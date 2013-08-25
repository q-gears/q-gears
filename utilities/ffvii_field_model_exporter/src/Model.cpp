// $Id: Model.cpp 94 2006-11-12 19:44:43Z crazy_otaku $

#include <OgreTagPoint.h>

#include "../../common/utilites/Logger.h"

#include "Model.h"

Uint32 g_ModelNumber = 0;



Model::Model(void):
    m_CurrentFrame(0),
    m_PlayedAnimation(0),
    m_AnimationWait(0),
    m_Scale(1.0f)
{
    ++g_ModelNumber;
}



Model::~Model(void)
{
}



void
Model::Update(const Uint32 delta_time)
{
    if (m_AnimationWait >= 4)
    {
        if (m_Animation.size() > m_PlayedAnimation)
        {
            if (m_CurrentFrame < m_Animation[m_PlayedAnimation].frame.size() - 1)
            {
                ++m_CurrentFrame;
            }
            else
            {
                m_CurrentFrame = 0;
            }
        }

        m_AnimationWait = 0;
    }

    ++m_AnimationWait;
}






void
Model::DrawHierarchy(const Sint8 level) const
{
}



void
Model::AddBone(const Sint16 length, const Sint8 parent_id)
{
    Bone bone;
    bone.length    = length;
    bone.parent_id = parent_id;
    m_Skeleton.push_back(bone);
}



void
Model::AddPart(const TotalGeometry& geometry, const int parent_bone)
{
    Part part;
    part.geometry    = geometry;
    part.parent_bone = parent_bone;
    m_Parts.push_back(part);
}



void
Model::AddAnimation(const Animation& animation)
{
    m_Animation.push_back(animation);
}



void
Model::SetAnimation(Uint32 animation_id)
{
    m_PlayedAnimation = animation_id;
    m_CurrentFrame = 0;
}



int
Model::GetNumberOfBones(void) const
{
    return m_Skeleton.size();
}

