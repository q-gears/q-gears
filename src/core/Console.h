#ifndef CONSOLE_H
#define CONSOLE_H

#include <OgreLog.h>
#include <OgreSingleton.h>
#include <OgreStringVector.h>
#include <OIS.h>
#include <list>
#include <vector>

#include "Event.h"



class Console : public Ogre::Singleton< Console >, public Ogre::LogListener
{
public:
    Console();
    ~Console();

    void Input( const Event& event );
    void Update();
    void UpdateDraw();
    void OnResize();

    void SetToVisible();
    void SetToHide();
    bool IsVisible() const;

    void AddTextToOutput( const Ogre::String& text );
    void ExecuteCommand();
    void ExecuteScript();
    void CompleteInput();
    void ResetAutoCompletion();
    void AddInputToHistory();
    void SetInputLineFromHistory();

    virtual void messageLogged( const Ogre::String& message, Ogre::LogMessageLevel lml, bool maskDebug, const Ogre::String& logName );

private:
    int                           m_ConsoleWidth;
    int                           m_ConsoleHeight;

    bool                          m_ToVisible;
    bool                          m_Visible;
    int                           m_Speed;
    float                         m_Height;

    int                           m_LineWidth;

    int                           m_LetterWidth;

    Ogre::Real                    m_OutputTextBoxY;
    std::list< Ogre::String >     m_OutputLine;
    int                           m_MaxOutputLine;
    int                           m_DisplayLine; // bottom of console displays this line

    Ogre::String                  m_InputLine;

    Ogre::StringVector            m_AutoCompletition;
    int                           m_AutoCompletitionLine;

    int                           m_CursorPosition;
    int                           m_CursorDrawPosition;
    Ogre::Real                    m_CursorTextBoxX;
    float                         m_CursorBlinkTime;

    std::list< Ogre::String >     m_History;
    int                           m_HistoryLine;
    int                           m_HistorySize;
};



#endif // CONSOLE_H
