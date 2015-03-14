#ifndef CONSOLE_H
#define CONSOLE_H

#include <OgreColourValue.h>
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

    void Input(const QGears::Event& event);
    void Update();
    void UpdateDraw();
    void UpdateNotification();
    void OnResize();

    void SetToVisible();
    void SetToHide();
    bool IsVisible() const;

    void AddTextToOutput( const Ogre::String& text, const Ogre::ColourValue& colour = Ogre::ColourValue::White );
    void ExecuteCommand( const Ogre::String& command );
    void ExecuteScript();
    void CompleteInput();
    void ResetAutoCompletion();
    void AddInputToHistory();
    void SetInputLineFromHistory();

    virtual void messageLogged( const Ogre::String& message, Ogre::LogMessageLevel lml, bool maskDebug, const Ogre::String &logName, bool& skipThisMessage );

private:
    void LoadHistory();
    void SaveHistory();
    void AddToHistory(const Ogre::String& history);
    char TranslateNumpad(const QGears::Event& event);

    int                           m_ConsoleWidth;
    int                           m_ConsoleHeight;
    unsigned int                  m_LineWidth;
    int                           m_LetterWidth;

    bool                          m_ToVisible;
    bool                          m_Visible;
    float                         m_Height;

    struct OutputLine
    {
        Ogre::String text;
        Ogre::ColourValue colour;
        float time;
    };
    std::list< OutputLine >       m_OutputLine;
    unsigned int                  m_MaxOutputLine; // max number of lines in output list
    unsigned int                  m_DisplayLine;   // bottom of console displays this line
    Ogre::String                  m_InputLine;
    unsigned int                  m_CursorPosition;
    float                         m_CursorBlinkTime;

    std::list< Ogre::String >     m_History;
    int                           m_HistoryLineCycleIndex;
    unsigned int                  m_MaxHistorySize;

    Ogre::StringVector            m_AutoCompletition;
    unsigned int                  m_AutoCompletitionLine;
};



#endif // CONSOLE_H
