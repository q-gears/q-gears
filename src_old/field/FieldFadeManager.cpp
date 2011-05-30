// $Id$

#include "FieldFadeManager.h"
#include "FieldModule.h"
#include "../Main.h"

Ogre::String fade_type_string[2] = {"ADD", "SUBTRACT"};



FieldFadeManager::FieldFadeManager(FieldModule* field, FieldScriptManager* script):
    m_FieldModule(field),
    m_FieldScriptManager(script),

    m_Type(FF_ADD),
    m_Current(0),
    m_Speed(0),
    m_Time(0),
    m_ColourStart(Ogre::ColourValue::Black)
{
    // debug info
    m_DebugInfoText = new TextArea("DebugFadeText");
    m_DebugInfoText->setCaption("");
    m_DebugInfoText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugInfoText->setPosition(5, 5);
    m_DebugInfoText->setTextAlignment(TextArea::LEFT);
    m_DebugInfoText->setFontName("DebugText");
    m_DebugInfoText->setCharHeight(18);

    m_DebugInfoOverlay = Ogre::OverlayManager::getSingleton().create("DebugFadeOverlay");
    m_DebugInfoOverlay->setZOrder(QGOO_FIELD_DEBUG);
    m_DebugInfoOverlay->add2D((Ogre::OverlayContainer*)m_DebugInfoText);



    m_FadeOverlay = Ogre::OverlayManager::getSingleton().create("FadeOverlay");
    m_FadeOverlay->setZOrder(QGOO_FIELD_FADE);
    m_FadeOverlay->show();

    m_Fade = new Fade("FieldFade");
    m_Fade->SetBackgroundUV(0, 0.75f, 0.125f, 0.8125f);
    m_Fade->SetColour(m_ColourStart);
    m_Fade->setMaterialName("fade_colour_blend");
    m_FadeOverlay->add2D(m_Fade);

    Ogre::LogManager::getSingletonPtr()->logMessage("FadeManager created.");
}



FieldFadeManager::~FieldFadeManager(void)
{
    // delete debug
    m_DebugInfoOverlay->remove2D((Ogre::OverlayContainer*)m_DebugInfoText);
    delete m_DebugInfoText;
    Ogre::OverlayManager::getSingleton().destroy(m_DebugInfoOverlay);

    Ogre::OverlayManager::getSingleton().destroy(m_FadeOverlay);

    Ogre::LogManager::getSingletonPtr()->logMessage("FadeManager destroyed.");
}



void
FieldFadeManager::Input(const Event& input)
{
}



void
FieldFadeManager::Update(const float delta_time)
{
    if (m_Time > 0)
    {
        m_Current += delta_time;
        m_Current = (m_Current > m_Time) ? m_Time : m_Current;

        m_Fade->SetColour(m_ColourStart + (m_ColourEnd - m_ColourStart) * m_Current / m_Time);

        if (m_Current == m_Time)
        {
            this->UnsetWait();
            m_ColourStart = m_ColourEnd;
            m_Time = 0;
        }
    }
    else if (m_Speed != 0)
    {
        m_Current += m_Speed * delta_time;
        m_Current = (m_Current > 255) ? 255 : m_Current;
        m_Current = (m_Current < 0) ? 0 : m_Current;

        if (m_Type == FF_ADD)
        {
            m_Fade->SetColour(m_ColourEnd * m_Current / 255.0f);
        }
        else
        {
            m_Fade->SetColour(Ogre::ColourValue::White - ((Ogre::ColourValue::White - m_ColourEnd) * m_Current / 255.0f));
        }

        if (m_Current == 255 || m_Current == 0)
        {
            this->UnsetWait();
            m_ColourStart = m_ColourEnd;
            m_Speed = 0;
        }
    }



    if (m_DebugInfoOverlay->isVisible() == true)
    {
        Ogre::String caption;

        caption += fade_type_string[m_Type] + " (" + Ogre::StringConverter::toString(m_ColourEnd) + ")";

        if (m_Time > 0)
        {
            caption += ":" + Ogre::StringConverter::toString(m_Time) + "/" + Ogre::StringConverter::toString(m_Current);
        }
        else if (m_Speed != 0)
        {
            caption += "speed:" + Ogre::StringConverter::toString(m_Speed) + " cur:" + Ogre::StringConverter::toString(m_Current);
        }

        m_DebugInfoText->setCaption(caption);
    }
}



void
FieldFadeManager::ShowFade(const bool show)
{
    if (show == true)
    {
        m_FadeOverlay->show();
    }
    else
    {
        m_FadeOverlay->hide();
    }
}



void
FieldFadeManager::ShowDebug(const bool show)
{
    if (show == true)
    {
        m_DebugInfoOverlay->show();
    }
    else
    {
        m_DebugInfoOverlay->hide();
    }
}



void
FieldFadeManager::FadeIn(const int r, const int g, const int b, const FieldFadeType type, const float time)
{
    m_Type = type;
    m_Current = 0;
    m_Time = time;
    m_ColourEnd = Ogre::ColourValue(r / 255.0f, g / 255.0f, b / 255.0f);

    switch (type)
    {
        case FF_ADD:      m_Fade->setMaterialName("fade_colour_blend"); break;
        case FF_SUBTRACT: m_Fade->setMaterialName("fade_modulate");     break;
    }

    if (m_Current == m_Time)
    {
        m_Fade->SetColour(m_ColourEnd);
        m_ColourStart = m_ColourEnd;
    }
}



void
FieldFadeManager::FadeIn(const int r, const int g, const int b, const FieldFadeType type, const float speed, const int start_alpha)
{
    m_Type = type;
    m_Current = start_alpha;
    m_Speed = speed;
    m_ColourEnd = Ogre::ColourValue(r / 255.0f, g / 255.0f, b / 255.0f);

    switch (type)
    {
        case FF_ADD:      m_Fade->setMaterialName("fade_colour_blend"); break;
        case FF_SUBTRACT: m_Fade->setMaterialName("fade_modulate");     break;
    }
}



void
FieldFadeManager::Clear()
{
    m_Fade->SetColour(Ogre::ColourValue::Black);
    m_Fade->setMaterialName("fade_colour_blend");

    m_Type = FF_ADD;
    m_Current = 0;
    m_Speed = 0;
    m_Time = 0;
    m_ColourStart = Ogre::ColourValue::Black;
}



void
FieldFadeManager::Black()
{
    m_Fade->SetColour(Ogre::ColourValue::Black);
    m_Fade->setMaterialName("fade_modulate");

    m_Type = FF_SUBTRACT;
    m_Current = 0;
    m_Speed = 0;
    m_Time = 0;
    m_ColourStart = Ogre::ColourValue::Black;
}



const int
FieldFadeManager::Wait()
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] fade:wait: Wait for fade.");

    if (m_Time == 0 && m_Speed == 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] fade:wait: There is no fading now.");
        return 1;
    }

    m_ScriptInfo.push_back(m_FieldScriptManager->GetCurrentScriptInfo());

    return -1;
}



void
FieldFadeManager::UnsetWait()
{
    for (int i = 0; i < m_ScriptInfo.size(); ++i)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_ScriptInfo[i]);
    }

    m_ScriptInfo.clear();
}
