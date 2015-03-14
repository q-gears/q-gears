#include <OgreStringConverter.h>

#include "core/Utilites.h"

bool
GetBool( TiXmlNode* node, const Ogre::String& tag, bool def )
{
    bool ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseBool( *string );
        }
    }

    return ret;
}



int
GetInt( TiXmlNode* node, const Ogre::String& tag, int def )
{
    int ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseInt( *string );
        }
    }

    return ret;
}



float
GetFloat( TiXmlNode* node, const Ogre::String& tag, float def )
{
    float ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseReal( *string );
        }
    }

    return ret;
}



const Ogre::String
GetString( TiXmlNode* node, const Ogre::String& tag, const Ogre::String& def )
{
    Ogre::String ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = *string;
        }
    }

    return ret;
}



const Ogre::UTFString
GetUTFString( TiXmlNode* node, const Ogre::String& tag, const Ogre::UTFString& def )
{
    Ogre::UTFString ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = ( *string ).c_str();
        }
    }

    return ret;
}



const Ogre::Vector2
GetVector2( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector2& def )
{
    Ogre::Vector2 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseVector2( *string );
        }
    }

    return ret;
}



const Ogre::Vector3
GetVector3( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector3& def )
{
    Ogre::Vector3 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseVector3( *string );
        }
    }

    return ret;
}



const Ogre::Vector4
GetVector4( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector4& def )
{
    Ogre::Vector4 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseVector4( *string );
        }
    }

    return ret;
}



const Ogre::Matrix4
GetMatrix4( TiXmlNode* node, const Ogre::String& tag, const Ogre::Matrix4& def )
{
    Ogre::Matrix4 ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseMatrix4( *string );
        }
    }

    return ret;
}



const Ogre::Quaternion
GetQuaternion( TiXmlNode* node, const Ogre::String& tag, const Ogre::Quaternion& def )
{
    Ogre::Quaternion ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseQuaternion( *string );
        }
    }

    return ret;
}



const Ogre::ColourValue
GetColourValue( TiXmlNode* node, const Ogre::String& tag, const Ogre::ColourValue& def )
{
    Ogre::ColourValue ret = def;

    if( node->Type() == TiXmlNode::TINYXML_ELEMENT )
    {
        const std::string* string = node->ToElement()->Attribute( tag );
        if( string != NULL )
        {
            ret = Ogre::StringConverter::parseColourValue( *string );
        }
    }

    return ret;
}



void
ParsePersent( float& value_percent, float& value, const Ogre::String& string )
{
    if( string.at( string.size() - 1 ) == '%' )
    {
        value_percent = Ogre::StringConverter::parseReal( string.substr( 0, string.size() - 1 ) );
        value = 0;
    }
    else
    {
        Ogre::StringVector param = Ogre::StringUtil::split( string, "%" );
        if( param.size() > 1 )
        {
            value_percent = Ogre::StringConverter::parseReal( param[ 0 ] );
            value = Ogre::StringConverter::parseReal( param[ 1 ] );
        }
        else
        {
            value_percent = 0;
            value = Ogre::StringConverter::parseReal( string );
        }
    }
}



float
ParseKeyFrameTime( const float length, const Ogre::String& string )
{
    float res = 0;

    if( string.at( string.size() - 1 ) == '%' )
    {
        res = length * Ogre::StringConverter::parseReal( string.substr( 0, string.size() - 1 ) ) / 100;
    }
    else
    {
        res = Ogre::StringConverter::parseReal( string );
    }

    return res;
}



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
    {"Enter", OIS::KC_RETURN},
    {"Escape", OIS::KC_ESCAPE},
    {"Space", OIS::KC_SPACE},
    {"LShift", OIS::KC_LSHIFT},
    {"RShift", OIS::KC_RSHIFT},
    {"LCtrl", OIS::KC_LCONTROL},
    {"RCtrl", OIS::KC_RCONTROL},
    {"LAlt", OIS::KC_LMENU},
    {"RAlt", OIS::KC_RMENU},

    {"0", OIS::KC_0},
    {"1", OIS::KC_1},
    {"2", OIS::KC_2},
    {"3", OIS::KC_3},
    {"4", OIS::KC_4},
    {"5", OIS::KC_5},
    {"6", OIS::KC_6},
    {"7", OIS::KC_7},
    {"8", OIS::KC_8},
    {"9", OIS::KC_9},

    {"A", OIS::KC_A},
    {"B", OIS::KC_B},
    {"C", OIS::KC_C},
    {"D", OIS::KC_D},
    {"E", OIS::KC_E},
    {"F", OIS::KC_F},
    {"G", OIS::KC_G},
    {"H", OIS::KC_H},
    {"I", OIS::KC_I},
    {"J", OIS::KC_J},
    {"K", OIS::KC_K},
    {"L", OIS::KC_L},
    {"M", OIS::KC_M},
    {"N", OIS::KC_N},
    {"O", OIS::KC_O},
    {"P", OIS::KC_P},
    {"Q", OIS::KC_Q},
    {"R", OIS::KC_R},
    {"S", OIS::KC_S},
    {"T", OIS::KC_T},
    {"U", OIS::KC_U},
    {"V", OIS::KC_V},
    {"W", OIS::KC_W},
    {"X", OIS::KC_X},
    {"Y", OIS::KC_Y},
    {"Z", OIS::KC_Z},

    {"Left", OIS::KC_LEFT},
    {"Up", OIS::KC_UP},
    {"Down", OIS::KC_DOWN},
    {"Right", OIS::KC_RIGHT},

    {"Num0", OIS::KC_NUMPAD0},
    {"Num1", OIS::KC_NUMPAD1},
    {"Num2", OIS::KC_NUMPAD2},
    {"Num3", OIS::KC_NUMPAD3},
    {"Num4", OIS::KC_NUMPAD4},
    {"Num5", OIS::KC_NUMPAD5},
    {"Num6", OIS::KC_NUMPAD6},
    {"Num7", OIS::KC_NUMPAD7},
    {"Num8", OIS::KC_NUMPAD8},
    {"Num9", OIS::KC_NUMPAD9},
    {"NumLock", OIS::KC_NUMLOCK},
    {"NumDiv", OIS::KC_DIVIDE},
    {"NumMult", OIS::KC_MULTIPLY},
    {"NumSub", OIS::KC_SUBTRACT},
    {"NumAdd", OIS::KC_ADD},
    {"NumEnter", OIS::KC_NUMPADENTER},
    {"NumDec", OIS::KC_DECIMAL},

    {"F1", OIS::KC_F1},
    {"F2", OIS::KC_F2},
    {"F3", OIS::KC_F3},
    {"F4", OIS::KC_F4},
    {"F5", OIS::KC_F5},
    {"F6", OIS::KC_F6},
    {"F7", OIS::KC_F7},
    {"F8", OIS::KC_F8},
    {"F9", OIS::KC_F9},
    {"F10", OIS::KC_F10},
    {"F11", OIS::KC_F11},
    {"F12", OIS::KC_F12},

    {"UNASSIGNED", OIS::KC_UNASSIGNED},
};


Ogre::String
KeyToString(OIS::KeyCode key)
{
    // find string by key
    for(KeyName* kn = key_names; kn->name != "UNASSIGNED"; ++kn)
    {
        if(kn->key == key)
        {
            return kn->name;
        }
    }

    return "UNASSIGNED";
}


OIS::KeyCode
StringToKey(const Ogre::String& str)
{
    if(str == "")
    {
        return OIS::KC_UNASSIGNED;
    }

    // find key by string
    for(KeyName* kn = key_names; kn->name != "UNASSIGNED"; ++kn)
    {
        if(kn->name == str)
        {
            return kn->key;
        }
    }

    return OIS::KC_UNASSIGNED;
}


Ogre::StringVector
StringTokenise(const Ogre::String& str, const Ogre::String& delimiters, const Ogre::String& delimiters_preserve, const Ogre::String& quote, const Ogre::String& esc)
{
    Ogre::StringVector ret;

    Ogre::String::size_type pos = 0; // the current position (char) in the string
    char ch = 0; // buffer for the current character
    char delimiter = 0;	// the buffer for the delimiter char which
                            // will be added to the tokens if the delimiter
                            // is preserved
    char current_quote = 0; // the char of the current open quote
    bool quoted = false; // indicator if there is an open quote
    Ogre::String token;  // string buffer for the token
    bool token_complete = false; // indicates if the current token is
                                 // read to be added to the result vector
    Ogre::String::size_type len = str.length();  // length of the input-string

    // for every char in the input-string
    while(len > pos)
    {
        // get the character of the string and reset the delimiter buffer
        ch = str.at(pos);
        delimiter = 0;

        // assume ch isn't a delimiter
        bool add_char = true;

        // check ...

        // ... if the delimiter is an escaped character
        bool escaped = false; // indicates if the next char is protected
        if(esc.empty() == false) // check if esc-chars are provided
        {
            if(esc.find_first_of(ch) != std::string::npos)
            {
                // get the escaped char
                ++pos;
                if(pos < len) // if there are more chars left
                {
                    // get the next one
                    ch = str.at(pos);

                    // add the escaped character to the token
                    add_char = true;
                }
                else // cannot get any more characters
                {
                    // don't add the esc-char
                    add_char = false;
                }

                // ignore the remaining delimiter checks
                escaped = true;
            }
        }

        // ... if the delimiter is a quote
        if(quote.empty() == false && escaped == false)
        {
            // if quote chars are provided and the char isn't protected
            if(quote.find_first_of(ch) != std::string::npos)
            {
                // if not quoted, set state to open quote and set
                // the quote character
                if(quoted == false)
                {
                    quoted = true;
                    current_quote = ch;

                    // don't add the quote-char to the token
                    add_char = false;
                }
                else // if quote is open already
                {
                    // check if it is the matching character to close it
                    if(current_quote == ch)
                    {
                        // close quote and reset the quote character
                        quoted = false;
                        current_quote = 0;

                        // don't add the quote-char to the token
                        add_char = false;
                    }
                }
            }
        }

        // if the delimiter isn't preserved
        if(delimiters.empty() == false && escaped == false && quoted == false)
        {
            // if a delimiter is provided and the char isn't protected by
            // quote or escape char
            if(delimiters.find_first_of(ch) != std::string::npos)
            {
                // if ch is a delimiter and the token string isn't empty
                // the token is complete
                if(token.empty() == false)
                {
                    token_complete = true;
                }

                // don't add the delimiter to the token
                add_char = false;
            }
        }

        // if the delimiter is preserved - add it as a token
        bool add_delimiter = false;
        if(delimiters_preserve.empty() == false && escaped == false && quoted == false)
        {
            // if a delimiter which will be preserved is provided and the
            // char isn't protected by quote or escape char
            if(delimiters_preserve.find_first_of(ch) != std::string::npos)
            {
                // if ch is a delimiter and the token string isn't empty the token is complete
                if(token.empty() == false)
                {
                    token_complete = true;
                }

                // don't add the delimiter to the token
                add_char = false;

                // add the delimiter
                delimiter = ch;
                add_delimiter = true;
            }
        }

        // add the character to the token
        if(add_char == true)
        {
            // add the current char
            token.push_back(ch);
        }

        // add the token if it is complete
        if(token_complete == true && token.empty() == false)
        {
            // add the token string
            ret.push_back(token);

            // clear the contents
            token.clear();

            // build the next token
            token_complete = false;
        }

        // add the delimiter
        if(add_delimiter == true)
        {
            // the next token is the delimiter
            Ogre::String delim_token;
            delim_token.push_back(delimiter);
            ret.push_back(delim_token);
        }

        // repeat for the next character
        ++pos;
    }

    // add the final token
    if(token.empty() == false)
    {
        ret.push_back(token);
    }

    return ret;
}
