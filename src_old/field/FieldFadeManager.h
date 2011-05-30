#ifndef FIELD_FADE_MANAGER_h
#define FIELD_FADE_MANAGER_h

#include <OgreOverlay.h>
#include <vector>

#include "FieldScriptManager.h"
#include "../core/Actor.h"
#include "../core/ui/Fade.h"
#include "../core/ui/TextArea.h"



class FieldModule;



enum FieldFadeType
{
    FF_ADD,
    FF_SUBTRACT
};



class FieldFadeManager : public Actor
{
public:
                   FieldFadeManager(FieldModule* field, FieldScriptManager* script);
    virtual       ~FieldFadeManager(void);

    virtual void   Input(const Event& input);
    virtual void   Update(const float delta_time);

    void           ShowFade(const bool show);
    void           ShowDebug(const bool show);

    void           FadeIn(const int r, const int g, const int b, const FieldFadeType type, const float time);
    void           FadeIn(const int r, const int g, const int b, const FieldFadeType type, const float speed, const int start_alpha);
    void           Clear();
    void           Black();
    const int      Wait();

private:
    void           UnsetWait();

private:
    FieldModule*                  m_FieldModule;
    FieldScriptManager*           m_FieldScriptManager;

    TextArea*                     m_DebugInfoText;
    Ogre::Overlay*                m_DebugInfoOverlay;

    Fade*                         m_Fade;
    Ogre::Overlay*                m_FadeOverlay;

    FieldFadeType                 m_Type;
    float                         m_Current;
    float                         m_Speed;
    float                         m_Time;
    Ogre::ColourValue             m_ColourStart;
    Ogre::ColourValue             m_ColourEnd;
    std::vector<ScriptInfo>       m_ScriptInfo;
};



#endif // FIELD_FADE_MANAGER_h
