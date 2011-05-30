#ifndef CONSOLE_H
#define CONSOLE_H

#include <OgreLog.h>
#include <OgrePanelOverlayElement.h>
#include <OgreSingleton.h>
#include <OgreStringVector.h>
#include <OIS.h>
#include <list>
#include <vector>

#include "Event.h"
#include "gui/TextArea.h"



class Console : public Ogre::Singleton<Console>, public Ogre::LogListener
{
public:
                    Console();
                    ~Console();

    void            Input(const Event& event);
    void            Update();

    void            SetToVisible();
    void            SetToHide();
    bool            IsVisible() const;

    void            AddTextToOutput(const Ogre::String& text);
    void            UpdateOutput();
    void            ExecuteCommand();
    void            ExecuteScript();
    void            CompleteInput();
    void            ResetAutoCompletion();
    void            AddInputToHistory();
    void            SetInputLineFromHistory();

    virtual void    messageLogged(const Ogre::String& message, Ogre::LogMessageLevel lml, bool maskDebug, const Ogre::String& logName);

private:
    Ogre::Overlay*                m_Overlay;

    int                           m_ConsoleWidth;
    int                           m_ConsoleHeight;

    Ogre::PanelOverlayElement*    m_Background;

    bool                          m_ToVisible;
    bool                          m_Visible;
    int                           m_Speed;
    float                         m_Height;

    int                           m_LineWidth;

    TextArea*                     m_OutputTextBox;
    Ogre::Real                    m_OutputTextBoxY;
    std::list<Ogre::String>       m_OutputLine;
    int                           m_MaxOutputLine;
    int                           m_DisplayLine; // bottom of console displays this line

    TextArea*                     m_InputTextBox;
    Ogre::String                  m_InputLine;

    Ogre::StringVector            m_AutoCompletition;
    int                           m_AutoCompletitionLine;

    TextArea*                     m_CursorTextBox;
    int                           m_CursorPosition;
    int                           m_CursorDrawPosition;
    Ogre::Real                    m_CursorTextBoxX;
    float                         m_CursorBlinkTime;

    std::list<Ogre::String>       m_History;
    int                           m_HistoryLine;
    int                           m_HistorySize;
};



#endif // CONSOLE_H
