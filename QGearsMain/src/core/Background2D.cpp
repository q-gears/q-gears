#include <OgreHardwareBufferManager.h>
#include <OgreLogManager.h>
#include <OgreMaterialManager.h>
#include <OgreException.h>

#include "core/Background2D.h"
#include "core/CameraManager.h"
#include "core/ConfigVar.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "core/Timer.h"


ConfigVar cv_debug_background2d("debug_background2d", "Draw background debug info", "false");
ConfigVar cv_show_background2d("show_background2d", "Draw background", "true");
ConfigVar cv_background2d_manual("background2d_manual", "Manual scrolling for 2d background", "false");


Background2D::Background2D():
    m_AlphaMaxVertexCount(0),
    m_AddMaxVertexCount(0),
    m_SubtractMaxVertexCount(0),

    m_ScrollEntity(nullptr),
    m_ScrollPositionStart(Ogre::Vector2::ZERO),
    m_ScrollPositionEnd(Ogre::Vector2::ZERO),
    m_ScrollType(Background2D::NONE),
    m_ScrollSeconds(0),
    m_ScrollCurrentSeconds(0),
    m_Position(Ogre::Vector2::ZERO),
    m_PositionReal(Ogre::Vector2::ZERO),
    m_range(Ogre::AxisAlignedBox::BOX_INFINITE),
    // for ffvii
    m_virtual_screen_size(320, 240)
{
    m_SceneManager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_RenderSystem = Ogre::Root::getSingletonPtr()->getRenderSystem();

    CreateVertexBuffers();

    m_AlphaMaterial = Ogre::MaterialManager::getSingleton().create("Background2DAlpha", "General");
    Ogre::Pass* pass = m_AlphaMaterial->getTechnique(0)->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(true);
    pass->setDepthWriteEnabled(true);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
    pass->setAlphaRejectFunction(Ogre::CMPF_GREATER);
    pass->setAlphaRejectValue(0);
    Ogre::TextureUnitState* tex = pass->createTextureUnitState();
    tex->setTextureName("system/blank.png");
    tex->setNumMipmaps(-1);
    tex->setTextureFiltering(Ogre::TFO_NONE);

    m_AddMaterial = Ogre::MaterialManager::getSingleton().create("Background2DAdd", "General");
    pass = m_AddMaterial->getTechnique(0)->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(true);
    pass->setDepthWriteEnabled(true);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_ADD);
    pass->setAlphaRejectFunction(Ogre::CMPF_GREATER);
    pass->setAlphaRejectValue(0);
    tex = pass->createTextureUnitState();
    tex->setTextureName("system/blank.png");
    tex->setNumMipmaps(-1);
    tex->setTextureFiltering(Ogre::TFO_NONE);

    m_SubtractMaterial = Ogre::MaterialManager::getSingleton().create("Background2DSubtract", "General");
    pass = m_SubtractMaterial->getTechnique(0)->getPass(0);
    pass->setVertexColourTracking(Ogre::TVC_AMBIENT);
    pass->setCullingMode(Ogre::CULL_NONE);
    pass->setDepthCheckEnabled(true);
    pass->setDepthWriteEnabled(true);
    pass->setLightingEnabled(false);
    pass->setSceneBlending(Ogre::SBT_ADD);
    pass->setSceneBlendingOperation(Ogre::SBO_SUBTRACT);
    pass->setAlphaRejectFunction(Ogre::CMPF_LESS);
    pass->setAlphaRejectValue(0);
    tex = pass->createTextureUnitState();
    tex->setTextureName("system/blank.png");
    tex->setNumMipmaps(-1);
    tex->setTextureFiltering(Ogre::TFO_NONE);

    m_SceneManager->addRenderQueueListener(this);
}


Background2D::~Background2D()
{
    m_SceneManager->removeRenderQueueListener(this);

    for(unsigned int i = 0; i < m_Animations.size(); ++i)
    {
        delete m_Animations[i];
    }

    DestroyVertexBuffers();
}


void
Background2D::InputDebug(const QGears::Event& event)
{
    if(cv_background2d_manual.GetB() == true)
    {
        if (event.type == QGears::ET_KEY_IMPULSE && event.param1 == OIS::KC_W)
        {
            m_PositionReal.y += 2;
        }
        else if (event.type == QGears::ET_KEY_IMPULSE && event.param1 == OIS::KC_A)
        {
            m_PositionReal.x += 2;
        }
        else if (event.type == QGears::ET_KEY_IMPULSE && event.param1 == OIS::KC_S)
        {
            m_PositionReal.y -= 2;
        }
        else if (event.type == QGears::ET_KEY_IMPULSE && event.param1 == OIS::KC_D)
        {
            m_PositionReal.x -= 2;
        }

        CameraManager::getSingleton().Set2DScroll(m_PositionReal);
    }
}


void
Background2D::Update()
{
    for(unsigned int i = 0; i < m_AnimationPlayed.size(); ++i)
    {
        for( unsigned int j = 0; j < m_Animations.size(); ++j )
        {
            if( m_Animations[j]->GetName() == m_AnimationPlayed[i].name)
            {
                float delta_time = Timer::getSingleton().GetGameTimeDelta();
                float time = m_Animations[j]->GetTime();
                float end_time = m_Animations[j]->GetLength();

                // if animation ended
                if(time + delta_time >= end_time)
                {
                    // set to last frame of animation
                    if(time != end_time)
                    {
                        m_Animations[j]->SetTime(end_time);
                    }

                    if(m_AnimationPlayed[i].state == Background2DAnimation::ONCE)
                    {
                        for(unsigned int k = 0; k < m_AnimationPlayed[i].sync.size(); ++k)
                        {
                            ScriptManager::getSingleton().ContinueScriptExecution(m_AnimationPlayed[i].sync[k]);
                        }
                        m_AnimationPlayed[i].sync.clear();
                        m_AnimationPlayed[i].name = ""; // mark to erase this way
                    }
                    else // LOOPED
                    {
                        // in case of looped we need to sync with end
                        m_Animations[j]->SetTime(time + delta_time - end_time);
                    }
                }
                else
                {
                    m_Animations[j]->AddTime(delta_time);
                }
            }
        }
    }

    // remove stopped animations
    std::vector<AnimationPlayed>::iterator i = m_AnimationPlayed.begin();
    for(; i != m_AnimationPlayed.end();)
    {
        if((*i).name == "")
        {
            i = m_AnimationPlayed.erase(i);
        }
        else
        {
            ++i;
        }
    }
}


void
Background2D::UpdateDebug()
{
    // TODO: is this necessary? does it cost to apply camera 2d Scroll?
    // if so maybe move this check to applyScroll
    if(m_PositionReal != GetScreenScroll())
    {
        applyScroll();
    }

    if(cv_debug_background2d.GetB() == true)
    {
        DEBUG_DRAW.SetTextAlignment(DEBUG_DRAW.LEFT);
        DEBUG_DRAW.SetScreenSpace(true);
        DEBUG_DRAW.SetColour(Ogre::ColourValue(0.0f, 0.8f, 0.8f, 1.0f));
        for(unsigned int i = 0; i < m_AnimationPlayed.size(); ++i)
        {
            DEBUG_DRAW.Text(150.0f, static_cast<float>(34 + i * 12), "Background 2D animation: " + m_AnimationPlayed[i].name);
        }
    }
}


void
Background2D::calculateScreenScale()
{
    Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
    Ogre::Real scale_width = static_cast<Ogre::Real>(viewport->getActualWidth());
    Ogre::Real scale_height = static_cast<Ogre::Real>(viewport->getActualHeight());

    scale_width /= m_virtual_screen_size.x;
    scale_height /= m_virtual_screen_size.y;

    m_screen_scale = scale_height;
    m_screen_proportion.x = m_screen_scale / scale_width;
    m_screen_proportion.y = m_screen_scale / scale_height;
}


void
Background2D::OnResize()
{
    calculateScreenScale();

    for(unsigned int i = 0; i < m_Tiles.size(); ++i)
    {
        Tile &tile(m_Tiles[ i ]);
        Ogre::Vector2   top_left(static_cast<Ogre::Real>(tile.x), static_cast<Ogre::Real>(- tile.y));
        Ogre::Vector2   top_right(static_cast<Ogre::Real>(tile.x + tile.width), static_cast<Ogre::Real>(top_left.y));
        Ogre::Vector2   bottom_right(static_cast<Ogre::Real>(top_right.x), static_cast<Ogre::Real>(-(tile.y + tile.height)));
        Ogre::Vector2   bottom_left(static_cast<Ogre::Real>(top_left.x), static_cast<Ogre::Real>(bottom_right.y));

        virtualScreenToWorldSpace(top_left);
        virtualScreenToWorldSpace(top_right);
        virtualScreenToWorldSpace(bottom_right);
        virtualScreenToWorldSpace(bottom_left);

        float new_x1 = top_left.x;
        float new_y1 = top_left.y;

        float new_x2 = top_right.x;
        float new_y2 = top_right.y;

        float new_x3 = bottom_right.x;
        float new_y3 = bottom_right.y;

        float new_x4 = bottom_left.x;
        float new_y4 = bottom_left.y;

        Ogre::HardwareVertexBufferSharedPtr vertex_buffer;

        if(m_Tiles[i].blending == QGears::B_ALPHA)
        {
            vertex_buffer = m_AlphaVertexBuffer;
        }
        else if(m_Tiles[i].blending == QGears::B_ADD)
        {
            vertex_buffer = m_AddVertexBuffer;
        }
        else if(m_Tiles[i].blending == QGears::B_SUBTRACT)
        {
            vertex_buffer = m_SubtractVertexBuffer;
        }

        float* writeIterator = (float*)vertex_buffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);

        writeIterator += m_Tiles[i].start_vertex_index * TILE_VERTEX_INDEX_SIZE;

        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        writeIterator += 7;

        *writeIterator++ = new_x2;
        *writeIterator++ = new_y2;
        writeIterator += 7;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        writeIterator += 7;

        ///*
        *writeIterator++ = new_x1;
        *writeIterator++ = new_y1;
        writeIterator += 7;

        *writeIterator++ = new_x3;
        *writeIterator++ = new_y3;
        writeIterator += 7;
        //*/

        *writeIterator++ = new_x4;
        *writeIterator++ = new_y4;

        vertex_buffer->unlock();
    }

    applyScroll();
}


void
Background2D::Clear()
{
    m_ScrollEntity = nullptr;
    m_ScrollPositionStart = Ogre::Vector2::ZERO;
    m_ScrollPositionEnd = Ogre::Vector2::ZERO;
    m_ScrollSeconds = 0;
    m_ScrollCurrentSeconds = 0;
    m_Position = Ogre::Vector2::ZERO;
    m_PositionReal = Ogre::Vector2::ZERO;
    m_range = Ogre::AxisAlignedBox::BOX_INFINITE;
    UnsetScroll();

    for(unsigned int i = 0; i < m_Animations.size(); ++i)
    {
        delete m_Animations[i];
    }
    m_Animations.clear();

    for(unsigned int i = 0; i < m_AnimationPlayed.size(); ++i)
    {
        for(unsigned int j = 0; j < m_AnimationPlayed[i].sync.size(); ++j)
        {
            ScriptManager::getSingleton().ContinueScriptExecution(m_AnimationPlayed[i].sync[j]);
        }
    }
    m_AnimationPlayed.clear();

    m_Tiles.clear();
    DestroyVertexBuffers();
    CreateVertexBuffers();
}


void
Background2D::ScriptAutoScrollToEntity(Entity* entity)
{
    m_ScrollEntity = entity;
}


Entity*
Background2D::GetAutoScrollEntity() const
{
    return m_ScrollEntity;
}


void
Background2D::ScriptScrollToPosition(const float x, const float y, const ScrollType type, const float seconds)
{
    LOG_TRIVIAL("[SCRIPT] Background2d set scroll to position \"" + Ogre::StringConverter::toString(Ogre::Vector2(x, y)) + "\".");

    Ogre::Vector2 position = Ogre::Vector2(x, y);

    m_ScrollEntity = nullptr;

    if(type == Background2D::NONE)
    {
        SetScroll(position);
        return;
    }

    m_ScrollPositionStart = m_Position;
    m_ScrollPositionEnd = position;
    m_ScrollType = type;
    m_ScrollSeconds = seconds;
    m_ScrollCurrentSeconds = 0;
}


int
Background2D::ScriptScrollSync()
{
    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();

    LOG_TRIVIAL("[SCRIPT] Wait Background2d scroll for function \"" + script.function + "\" in script entity \"" + script.entity + "\".");

    m_ScrollSync.push_back(script);
    return -1;
}


void
Background2D::UnsetScroll()
{
    m_ScrollType = Background2D::NONE;

    for(unsigned int i = 0; i < m_ScrollSync.size(); ++i)
    {
        ScriptManager::getSingleton().ContinueScriptExecution(m_ScrollSync[i]);
    }
    m_ScrollSync.clear();
}


const Ogre::Vector2&
Background2D::GetScrollPositionStart() const
{
    return m_ScrollPositionStart;
}


const Ogre::Vector2&
Background2D::GetScrollPositionEnd() const
{
    return m_ScrollPositionEnd;
}


Background2D::ScrollType
Background2D::GetScrollType() const
{
    return m_ScrollType;
}


float
Background2D::GetScrollSeconds() const
{
    return m_ScrollSeconds;
}


void
Background2D::SetScrollCurrentSeconds(const float seconds)
{
    m_ScrollCurrentSeconds = seconds;
}


float
Background2D::GetScrollCurrentSeconds() const
{
    return m_ScrollCurrentSeconds;
}


void
Background2D::SetScreenScroll(const Ogre::Vector2& position)
{
    SetScroll(position / m_screen_scale);
}


void
Background2D::SetScroll(const Ogre::Vector2& position)
{
    m_Position = position;
    Ogre::Vector3 pos_3d(m_Position.x, m_Position.y, 0);

    if( !m_range.contains(pos_3d))
    {
        Ogre::Vector3 max_3d(m_range.getMaximum());
        Ogre::Vector3 min_3d(m_range.getMinimum());
        Ogre::Vector2 max(max_3d.x, max_3d.y);
        Ogre::Vector2 min(min_3d.x, min_3d.y);
        m_Position.makeCeil(min);
        m_Position.makeFloor(max);
    }

    applyScroll();
}


void
Background2D::applyScroll()
{
    if(cv_background2d_manual.GetB() != true)
    {
        m_PositionReal = GetScreenScroll();
        CameraManager::getSingleton().Set2DScroll(m_PositionReal);
    }
}


const Ogre::Vector2&
Background2D::GetScroll() const
{
    return m_Position;
}


const Ogre::Vector2
Background2D::GetScreenScroll() const
{
    return GetScroll() * m_screen_scale;
}


void
Background2D::SetImage(const Ogre::String& image)
{
    Ogre::LogManager::getSingleton().stream()
        << "Background2D::SetImage " << image;
    Ogre::Pass* pass = m_AlphaMaterial->getTechnique(0)->getPass(0);
    Ogre::TextureUnitState* tex = pass->getTextureUnitState(0);
    tex->setTextureName(image);
    pass = m_AddMaterial->getTechnique(0)->getPass(0);
    tex = pass->getTextureUnitState(0);
    tex->setTextureName(image);
    pass = m_SubtractMaterial->getTechnique(0)->getPass(0);
    tex = pass->getTextureUnitState(0);
    tex->setTextureName(image);
}


void
Background2D::SetRange(const Ogre::Vector4& range)
{
    SetRange((int)range.x, (int)range.y, (int)range.z, (int)range.w);
}


void
Background2D::SetRange(const int min_x, const int min_y, const int max_x, const int max_y)
{
    Ogre::LogManager::getSingleton().stream()
        << "Background2D::SetRange " << min_x << " " << min_y << " " << max_x << " " << max_y;

    Ogre::Vector2 half_virtual_screen_size(m_virtual_screen_size / 2);
    half_virtual_screen_size /= m_screen_proportion;
    m_range.setMaximum(max_x - half_virtual_screen_size.x , max_y - half_virtual_screen_size.y, 1);
    m_range.setMinimum(min_x + half_virtual_screen_size.x , min_y + half_virtual_screen_size.y, 0);

    Ogre::LogManager::getSingleton().stream()
        << "Background2D::SetRange " << m_range;

    calculateScreenScale();
}


void
Background2D::AddTile(const QGears::Tile& tile)
{
    // TODO: move depth calculation to flevelBackgroundLoader maybe? and let Backgorund2D only handle 0 <= depth <= 1 or so?
    // maybe just move the < 4095 part to flevel background loader?
    Ogre::Real depth(0.0001f);
    if(tile.depth >= 1)
    {
        if(tile.depth < 4095)
        {
            const Ogre::Matrix4 &cam_projection(CameraManager::getSingleton().GetCurrentCamera()->getProjectionMatrixWithRSDepth());
            Ogre::Vector4 res(0, 0, -tile.depth, 1);
            res = cam_projection * res;
            res /= res.w;
            depth = res.z;
        }
        else
        {
            depth = 0.9999f;
        }
    }
    AddTile(tile.destination, tile.width, tile.height, depth, tile.uv, tile.blending);
}


void
Background2D::AddTile(const Ogre::Vector2& destination, const int width, const int height, const float depth, const Ogre::Vector4& uv, const Blending blending)
{
    AddTile(static_cast<int>(destination.x), static_cast<int>(destination.y), width, height, depth, uv.x, uv.y, uv.z, uv.w, blending);
}


void
Background2D::virtualScreenToWorldSpace(Ogre::Vector2& pos) const
{
    pos.x /= m_virtual_screen_size.x / 2;
    pos.y /= m_virtual_screen_size.y / 2;

    pos.x *= m_screen_proportion.x;
    pos.y *= m_screen_proportion.y;
}


void
Background2D::AddTile(const int x, const int y, const int width, const int height, const float depth, const float u1, const float v1, const float u2, const float v2, const Blending blending)
{
    Ogre::RenderOperation render_op;
    Ogre::HardwareVertexBufferSharedPtr vertex_buffer;
    unsigned int max_vertex_count;

    if(blending == QGears::B_ALPHA)
    {
        render_op = m_AlphaRenderOp;
        vertex_buffer = m_AlphaVertexBuffer;
        max_vertex_count = m_AlphaMaxVertexCount;
    }
    else if(blending == QGears::B_ADD)
    {
        render_op = m_AddRenderOp;
        vertex_buffer = m_AddVertexBuffer;
        max_vertex_count = m_AddMaxVertexCount;
    }
    else if(blending == QGears::B_SUBTRACT)
    {
        render_op = m_SubtractRenderOp;
        vertex_buffer = m_SubtractVertexBuffer;
        max_vertex_count = m_SubtractMaxVertexCount;
    }
    else
    {
        LOG_ERROR("Unknown blending type.");
        return;
    }

    if(render_op.vertexData->vertexCount + TILE_VERTEX_COUNT > max_vertex_count)
    {
        LOG_ERROR("Max number of tiles reached. Can't create more than " + Ogre::StringConverter::toString( max_vertex_count / TILE_VERTEX_COUNT ) + " tiles.");
        return;
    }

    Tile tile;
    tile.x = x;
    tile.y = y;
    tile.width = width;
    tile.height = height;
    tile.start_vertex_index = render_op.vertexData->vertexCount;
    tile.blending = blending;
    size_t index(m_Tiles.size());
    m_Tiles.push_back(tile);

    Ogre::Vector2   top_left(static_cast<Ogre::Real>(x), static_cast<Ogre::Real>(-y));
    Ogre::Vector2   top_right(static_cast<Ogre::Real>(x + width), static_cast<Ogre::Real>(top_left.y));
    Ogre::Vector2   bottom_right(static_cast<Ogre::Real>(top_right.x), static_cast<Ogre::Real>(-(y + height)));
    Ogre::Vector2   bottom_left(top_left.x, bottom_right.y);

    virtualScreenToWorldSpace(top_left);
    virtualScreenToWorldSpace(top_right);
    virtualScreenToWorldSpace(bottom_right);
    virtualScreenToWorldSpace(bottom_left);

    float new_x1 = top_left.x;
    float new_y1 = top_left.y;

    float new_x2 = top_right.x;
    float new_y2 = top_right.y;

    float new_x3 = bottom_right.x;
    float new_y3 = bottom_right.y;

    float new_x4 = bottom_left.x;
    float new_y4 = bottom_left.y;

    float* writeIterator = (float*)vertex_buffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
    writeIterator += render_op.vertexData->vertexCount * TILE_VERTEX_INDEX_SIZE;

    // TODO: Can use WriteGlyph

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u1;
    *writeIterator++ = v1;

    *writeIterator++ = new_x2;
    *writeIterator++ = new_y2;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u2;
    *writeIterator++ = v1;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u2;
    *writeIterator++ = v2;

    *writeIterator++ = new_x1;
    *writeIterator++ = new_y1;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u1;
    *writeIterator++ = v1;

    *writeIterator++ = new_x3;
    *writeIterator++ = new_y3;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u2;
    *writeIterator++ = v2;

    *writeIterator++ = new_x4;
    *writeIterator++ = new_y4;
    *writeIterator++ = depth;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = 1;
    *writeIterator++ = u1;
    *writeIterator++ = v2;

    render_op.vertexData->vertexCount += TILE_VERTEX_COUNT;

    vertex_buffer->unlock();
}


void
Background2D::UpdateTileUV(const unsigned int tile_id, const float u1, const float v1, const float u2, const float v2)
{
    if(tile_id >= m_Tiles.size())
    {
        LOG_ERROR("Tile with id " + Ogre::StringConverter::toString( tile_id ) + " doesn't exist.");
        return;
    }

    Ogre::HardwareVertexBufferSharedPtr vertex_buffer;

    if(m_Tiles[tile_id].blending == QGears::B_ALPHA)
    {
        vertex_buffer = m_AlphaVertexBuffer;
    }
    else if(m_Tiles[tile_id].blending == QGears::B_ADD)
    {
        vertex_buffer = m_AddVertexBuffer;
    }
    else if(m_Tiles[tile_id].blending == QGears::B_SUBTRACT)
    {
        vertex_buffer = m_SubtractVertexBuffer;
    }

    float* writeIterator = (float*)vertex_buffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);

    writeIterator += m_Tiles[tile_id].start_vertex_index * TILE_VERTEX_INDEX_SIZE;

    writeIterator += 7;
    *writeIterator++ = u1;
    *writeIterator++ = v1;
    writeIterator += 7;
    *writeIterator++ = u2;
    *writeIterator++ = v1;
    writeIterator += 7;
    *writeIterator++ = u2;
    *writeIterator++ = v2;
    writeIterator += 7;
    *writeIterator++ = u1;
    *writeIterator++ = v1;
    writeIterator += 7;
    *writeIterator++ = u2;
    *writeIterator++ = v2;
    writeIterator += 7;
    *writeIterator++ = u1;
    *writeIterator++ = v2;

    vertex_buffer->unlock();
}


void
Background2D::AddAnimation(Background2DAnimation* animation)
{
    m_Animations.push_back(animation);
}


void
Background2D::PlayAnimation(const Ogre::String& animation, const Background2DAnimation::State state)
{
    bool found = false;

    for(unsigned int i = 0; i < m_Animations.size(); ++i)
    {
        if(m_Animations[i]->GetName() == animation)
        {
            found = true;
            m_Animations[i]->SetTime(0);
            m_Animations[i]->AddTime(0);
        }
    }

    for(unsigned int i = 0; i < m_AnimationPlayed.size(); ++i)
    {
        if(m_AnimationPlayed[i].name == animation)
        {
            m_AnimationPlayed.erase(m_AnimationPlayed.begin() + i);
        }
    }

    if(found == true)
    {
        AnimationPlayed anim;
        anim.name = animation;
        anim.state = state;
        m_AnimationPlayed.push_back(anim);
    }
    else
    {
        LOG_ERROR("Background2D doesn't has animation \"" + animation + "\".");
    }
}


void
Background2D::ScriptPlayAnimationLooped(const char* name)
{
    PlayAnimation(Ogre::String(name), Background2DAnimation::LOOPED);
}


void
Background2D::ScriptPlayAnimationOnce(const char* name)
{
    PlayAnimation(Ogre::String(name), Background2DAnimation::ONCE);
}


int
Background2D::ScriptAnimationSync(const char* animation)
{
    for(unsigned int i = 0; i < m_AnimationPlayed.size(); ++i)
    {
        if(m_AnimationPlayed[i].name == animation)
        {
            ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();
            m_AnimationPlayed[i].sync.push_back(script);
            return -1;
        }
    }

    return 1;
}


void
Background2D::renderQueueEnded(Ogre::uint8 queueGroupId, const Ogre::String& invocation, bool& repeatThisInvocation)
{
    if(cv_show_background2d.GetB() == false)
    {
        return;
    }

    if(queueGroupId == Ogre::RENDER_QUEUE_MAIN)
    {
        m_RenderSystem->_setWorldMatrix(Ogre::Matrix4::IDENTITY);
        m_RenderSystem->_setProjectionMatrix(Ogre::Matrix4::IDENTITY);

        Ogre::Viewport *viewport(CameraManager::getSingleton().getViewport());
        float width = static_cast<float>(viewport->getActualWidth());
        float height = static_cast<float>(viewport->getActualHeight());

        Ogre::Matrix4 view;
        view.makeTrans(Ogre::Vector3(m_PositionReal.x * 2 / width, -m_PositionReal.y * 2 / height, 0));
        m_RenderSystem->_setViewMatrix(view);

        if(m_AlphaRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_AlphaMaterial->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_AlphaRenderOp);
        }

        if(m_AddRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_AddMaterial->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_AddRenderOp);
        }

        if(m_SubtractRenderOp.vertexData->vertexCount != 0)
        {
            m_SceneManager->_setPass(m_SubtractMaterial->getTechnique(0)->getPass(0), true, false);
            m_RenderSystem->_render(m_SubtractRenderOp);
        }
    }
}


void
Background2D::CreateVertexBuffers()
{
    m_AlphaMaxVertexCount = 2048 * TILE_VERTEX_COUNT;
    m_AlphaRenderOp.vertexData = new Ogre::VertexData;
    m_AlphaRenderOp.vertexData->vertexStart = 0;

    Ogre::VertexDeclaration* vDecl = m_AlphaRenderOp.vertexData->vertexDeclaration;

    size_t offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT4);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);

    m_AlphaVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_AlphaMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_AlphaRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_AlphaVertexBuffer);
    m_AlphaRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_AlphaRenderOp.useIndexes = false;

    m_AddMaxVertexCount = 256 * TILE_VERTEX_COUNT;
    m_AddRenderOp.vertexData = new Ogre::VertexData;
    m_AddRenderOp.vertexData->vertexStart = 0;

    vDecl = m_AddRenderOp.vertexData->vertexDeclaration;

    offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT4);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);

    m_AddVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_AddMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_AddRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_AddVertexBuffer);
    m_AddRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_AddRenderOp.useIndexes = false;



    m_SubtractMaxVertexCount = 256 * TILE_VERTEX_COUNT; // FIXME: 256?
    m_SubtractRenderOp.vertexData = new Ogre::VertexData;
    m_SubtractRenderOp.vertexData->vertexStart = 0;

    vDecl = m_SubtractRenderOp.vertexData->vertexDeclaration;

    offset = 0;
    vDecl->addElement(0, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT4, Ogre::VES_DIFFUSE);
    offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT4);
    vDecl->addElement(0, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);

    m_SubtractVertexBuffer = Ogre::HardwareBufferManager::getSingletonPtr()->createVertexBuffer(vDecl->getVertexSize(0), m_SubtractMaxVertexCount, Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, false);

    m_SubtractRenderOp.vertexData->vertexBufferBinding->setBinding(0, m_SubtractVertexBuffer);
    m_SubtractRenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
    m_SubtractRenderOp.useIndexes = false;
}


void
Background2D::DestroyVertexBuffers()
{
    delete m_AlphaRenderOp.vertexData;
    m_AlphaRenderOp.vertexData = 0;
    m_AlphaVertexBuffer.setNull();
    m_AlphaMaxVertexCount = 0;

    delete m_AddRenderOp.vertexData;
    m_AddRenderOp.vertexData = 0;
    m_AddVertexBuffer.setNull();
    m_AddMaxVertexCount = 0;

    delete m_SubtractRenderOp.vertexData;
    m_SubtractRenderOp.vertexData = 0;
    m_SubtractVertexBuffer.setNull();
    m_SubtractMaxVertexCount = 0;
}


void
Background2D::load(const QGears::Background2DFilePtr& background)
{
    assert(!background.isNull());
    background->load();
    SetImage(background->getTextureName());
    m_virtual_screen_size = background->getClip();
    SetRange(background->getRange());

    const Ogre::Vector3& position(background->getPosition());
    const Ogre::Quaternion& orientation(background->getOrientation());
    const Ogre::Radian& fov(background->getFov());
    CameraManager::getSingleton().Set2DCamera(position, orientation, fov);
    load(background->getTiles());
}


void
Background2D::load(const QGears::Background2DFile::TileList& tiles)
{
    QGears::Background2DFile::TileList::const_iterator it(tiles.begin());
    QGears::Background2DFile::TileList::const_iterator it_end(tiles.end());
    size_t tile_index(0);
    while(it != it_end)
    {
        AddTile(*it);
        load(tile_index++, it->animations);
        ++it;
    }
}


void
Background2D::load(const size_t tile_index, const QGears::AnimationMap& animations)
{
    QGears::AnimationMap::const_iterator it(animations.begin());
    QGears::AnimationMap::const_iterator it_end(animations.end());

    while(it != it_end)
    {
        const QGears::String& name(it->first);
        const QGears::Animation& animation(it->second);
        Background2DAnimation* anim(new Background2DAnimation(name, this, tile_index));
        anim->SetLength(animation.length);
        QGears::KeyFrameList::const_iterator itk(animation.key_frames.begin());
        QGears::KeyFrameList::const_iterator itk_end(animation.key_frames.end());
        while(itk != itk_end)
        {
            anim->AddUVKeyFrame(*(itk++));
        }
        AddAnimation(anim);
        ++it;
    }
}
