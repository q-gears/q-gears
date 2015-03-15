#include "ConfigCmdManager.h"
#include "Console.h"
#include "Logger.h"
#include "XmlTextsFile.h"



void
CmdSetLanguage( const Ogre::StringVector& params )
{
    if( params.size() < 2 )
    {
        Console::getSingleton().AddTextToOutput( "Usage: /set_language <language>" );
        return;
    }

    TextManager::getSingleton().SetLanguage( params[ 1 ] );
    LOG_TRIVIAL( "Set game language to \"" + params[ 1 ] + "\"." );
}



void
CmdSetLanguageCompletition( Ogre::StringVector& complete_params )
{
    XmlTextsFile texts( "./data/texts.xml" );
    texts.GetAvailableLanguages( complete_params );
}



void
TextManager::InitCmd()
{
    ConfigCmdManager::getSingleton().AddCommand( "set_language", "Change language of texts and dialogs", "", CmdSetLanguage, CmdSetLanguageCompletition );
}
