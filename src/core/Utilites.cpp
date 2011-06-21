#include "Utilites.h"

#include <OgreStringConverter.h>



const Ogre::String
CreateAutoName(const Ogre::String prefix)
{
    static int enumerator = 0;
    return prefix + Ogre::StringConverter::toString( enumerator++ );
}



struct KeyName
{
    Ogre::String name;
    OIS::KeyCode key;
};

KeyName key_names[] =
{
    { "LShift", OIS::KC_LSHIFT },
    { "RShift", OIS::KC_RSHIFT },
    { "LCtrl", OIS::KC_LCONTROL },
    { "RCtrl", OIS::KC_RCONTROL },
    { "LAlt", OIS::KC_LMENU },
    { "RAlt", OIS::KC_RMENU },

    { "0", OIS::KC_0 },
    { "1", OIS::KC_1 },
    { "2", OIS::KC_2 },
    { "3", OIS::KC_3 },
    { "4", OIS::KC_4 },
    { "5", OIS::KC_5 },
    { "6", OIS::KC_6 },
    { "7", OIS::KC_7 },
    { "8", OIS::KC_8 },
    { "9", OIS::KC_9 },

    { "A", OIS::KC_A },
    { "B", OIS::KC_B },
    { "C", OIS::KC_C },
    { "D", OIS::KC_D },
    { "E", OIS::KC_E },
    { "F", OIS::KC_F },
    { "G", OIS::KC_G },
    { "H", OIS::KC_H },
    { "I", OIS::KC_I },
    { "J", OIS::KC_J },
    { "K", OIS::KC_K },
    { "L", OIS::KC_L },
    { "M", OIS::KC_M },
    { "N", OIS::KC_N },
    { "O", OIS::KC_O },
    { "P", OIS::KC_P },
    { "Q", OIS::KC_Q },
    { "R", OIS::KC_R },
    { "S", OIS::KC_S },
    { "T", OIS::KC_T },
    { "U", OIS::KC_U },
    { "V", OIS::KC_V },
    { "W", OIS::KC_W },
    { "X", OIS::KC_X },
    { "Y", OIS::KC_Y },
    { "Z", OIS::KC_Z },

    { "Left", OIS::KC_LEFT },
    { "Up", OIS::KC_UP },
    { "Down", OIS::KC_DOWN },
    { "Right", OIS::KC_RIGHT },

    { "Num0", OIS::KC_NUMPAD0 },
    { "Num1", OIS::KC_NUMPAD1 },
    { "Num2", OIS::KC_NUMPAD2 },
    { "Num3", OIS::KC_NUMPAD3 },
    { "Num4", OIS::KC_NUMPAD4 },
    { "Num5", OIS::KC_NUMPAD5 },
    { "Num6", OIS::KC_NUMPAD6 },
    { "Num7", OIS::KC_NUMPAD7 },
    { "Num8", OIS::KC_NUMPAD8 },
    { "Num9", OIS::KC_NUMPAD9 },
    { "NumLock", OIS::KC_NUMLOCK },
    { "NumDiv", OIS::KC_DIVIDE },
    { "NumMult", OIS::KC_MULTIPLY },
    { "NumSub", OIS::KC_SUBTRACT },
    { "NumAdd", OIS::KC_ADD },
    { "NumEnter", OIS::KC_NUMPADENTER },
    { "NumDec", OIS::KC_DECIMAL },

    { "F1", OIS::KC_F1 },
    { "F2", OIS::KC_F2 },
    { "F3", OIS::KC_F3 },
    { "F4", OIS::KC_F4 },
    { "F5", OIS::KC_F5 },
    { "F6", OIS::KC_F6 },
    { "F7", OIS::KC_F7 },
    { "F8", OIS::KC_F8 },
    { "F9", OIS::KC_F9 },
    { "F10", OIS::KC_F10 },
    { "F11", OIS::KC_F11 },
    { "F12", OIS::KC_F12 },

    { "UNASSIGNED", OIS::KC_UNASSIGNED },
};



Ogre::String
KeyToString( OIS::KeyCode key )
{
    // find string by key
    for( KeyName* kn = key_names; kn->name != "UNASSIGNED"; ++kn )
    {
        if( kn->key == key )
        {
            return kn->name;
        }
    }

    return "UNASSIGNED";
}



OIS::KeyCode
StringToKey(const Ogre::String& str)
{
    if (str == "")
    {
        return OIS::KC_UNASSIGNED;
    }

    // find key by string
    for (KeyName* kn = key_names; kn->name != "UNASSIGNED"; ++kn)
    {
        if (kn->name == str)
        {
            return kn->key;
        }
    }

    return OIS::KC_UNASSIGNED;
}



Ogre::StringVector
StringTokenise( const Ogre::String& str, const Ogre::String& singleDelims, const Ogre::String& doubleDelims, unsigned int maxSplits )
{
    Ogre::StringVector ret;
    // Pre-allocate some space for performance
    ret.reserve( maxSplits ? maxSplits + 1 : 10 );    // 10 is guessed capacity for most case

    unsigned int numSplits = 0;
    Ogre::String delims = singleDelims + doubleDelims;

    // Use STL methods
    size_t start, pos;
    char curDoubleDelim = 0;
    start = 0;
    do
    {
        if (curDoubleDelim != 0)
        {
            pos = str.find(curDoubleDelim, start);
        }
        else
        {
            pos = str.find_first_of(delims, start);
        }

        if (pos == start)
        {
            char curDelim = str.at(pos);
            if (doubleDelims.find_first_of(curDelim) != Ogre::String::npos)
            {
                curDoubleDelim = curDelim;
            }
            // Do nothing
            start = pos + 1;
        }
        else if (pos == Ogre::String::npos || (maxSplits && numSplits == maxSplits))
        {
            if (curDoubleDelim != 0)
            {
                //Missing closer. Warn or throw exception?
            }
            // Copy the rest of the string
            ret.push_back( str.substr(start) );
            break;
        }
        else
        {
            if (curDoubleDelim != 0)
            {
                curDoubleDelim = 0;
            }

            // Copy up to delimiter
            ret.push_back( str.substr(start, pos - start) );
            start = pos + 1;
        }
        if (curDoubleDelim == 0)
        {
            // parse up to next real data
            start = str.find_first_not_of(singleDelims, start);
        }

        ++numSplits;

    } while (pos != Ogre::String::npos && start != Ogre::String::npos);

    return ret;
}
