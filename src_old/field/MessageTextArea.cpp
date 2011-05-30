
#include <OgreOverlayManager.h>

#include "MessageManager.h"
#include "MessageTextArea.h"
#include "../game/GameState.h"

#define UNICODE_NEL 0x0085
#define UNICODE_CR 0x000D
#define UNICODE_LF 0x000A

Ogre::UTFString tag_new_window = "[new_window]";
Ogre::UTFString tag_pause_ok   = "[pause_ok]";
Ogre::UTFString tag_end        = "]";


MessageTextArea::MessageTextArea(const Ogre::String& name):
    TextArea(name),

    m_CaptionReal(""),
    m_CaptionRealReadPointer(0),
    m_CaptionRealSize(0),

    m_CurrentRowTop(0),
    m_CurrentRowHeight(0),
    m_MaxRowHeight(4)
{
    m_ClipPlanes.push_back(Ogre::Plane(Ogre::Vector3( 0.0, -1.0, 0.0), -1));
    m_ClipPlanes.push_back(Ogre::Plane(Ogre::Vector3(-1.0,  0.0, 0.0), -1));
    m_ClipPlanes.push_back(Ogre::Plane(Ogre::Vector3( 1.0,  0.0, 0.0), -1));
    m_ClipPlanes.push_back(Ogre::Plane(Ogre::Vector3( 0.0,  1.0, 0.0), -1));
}



MessageTextArea::~MessageTextArea()
{
}



void
MessageTextArea::setCaption(const Ogre::DisplayString& caption)
{
    m_CaptionReal = caption;
    m_CaptionRealReadPointer = 0;
    m_CaptionRealSize = caption.size();

    m_CurrentRowTop = 0;
    m_CurrentRowHeight = 0;

    TextArea::setCaption("");
}



void
MessageTextArea::ClearCurrentCaption()
{
    m_CurrentRowTop = 0;
    m_CurrentRowHeight = 0;

    TextArea::setCaption("");
}



const int
MessageTextArea::GetCaptionSize() const
{
    return m_CaptionRealReadPointer;
}



const int
MessageTextArea::GetCaptionRealSize() const
{
    return m_CaptionRealSize;
}



MessageState
MessageTextArea::AddCharactersToDisplay(float& number_symbols_to_read, float& time)
{
    MessageState ret = MS_SHOW_TEXT;

    int i = 0;
    int iend = m_CaptionReal.size();

    // read symbols and parse special tag
    for (i = m_CaptionRealReadPointer; i < iend && (int)number_symbols_to_read > 0; ++i, --number_symbols_to_read)
    {
        ///////////////////////////
        // new row
        if (m_CaptionReal[i] == UNICODE_CR || m_CaptionReal[i] == UNICODE_NEL || m_CaptionReal[i] == UNICODE_LF)
        {
            mCaption.push_back(m_CaptionReal[i]);

            // consume CR/LF in one
            if (m_CaptionReal[i] == UNICODE_CR && (i + 1) < iend && m_CaptionReal[i + 1] == UNICODE_LF)
            {
                ++i; // skip both as one newline
                mCaption.push_back(m_CaptionReal[i]);
            }

            ++m_CurrentRowHeight;
            // if we overflowed by number of rows
            if (m_CurrentRowHeight >= m_MaxRowHeight + m_CurrentRowTop)
            {
                ++i;
                --number_symbols_to_read;

                ret = MS_OPENED_OVERFLOW;
                break;
            }

            continue;
        }



        ///////////////////////////
        // new window
        else if (CheckTag(i, tag_new_window) == true)
        {
            --number_symbols_to_read;
            ret = MS_OPENED_NEXT_WINDOW;
            break;
        }



        ///////////////////////////
        // pause output
        else if (CheckTag(i, tag_pause_ok) == true)
        {
            --number_symbols_to_read;
            ret = MS_PAUSE_OK;
            break;
        }
        else
        {



            ///////////////////////////
            // pass colour formatter to inner stream
            Ogre::ColourValue temp_colour;
            int scan_ret = swscanf(m_CaptionReal.asWStr_c_str() + m_CaptionRealReadPointer, L"[colour r=\"%f\" g=\"%f\" b=\"%f\"]", &temp_colour.r, &temp_colour.g, &temp_colour.b);
            if (scan_ret == 3)
            {
                for (;; ++i)
                {
                    mCaption.push_back(m_CaptionReal[i]);

                    if (m_CaptionReal[i] != tag_end[0])
                    {
                        continue;
                    }

                    break;
                }

                continue;
            }



            ///////////////////////////
            // pause output wait
            float digit_holder = 0;
            scan_ret = swscanf(m_CaptionReal.asWStr_c_str() + m_CaptionRealReadPointer, L"[pause wait=\"%f\"]", &digit_holder);
            if (scan_ret == 1)
            {
                SkipTag(i);

                time = digit_holder;

                ++i;
                --number_symbols_to_read;
                ret = MS_PAUSE_TIME;

                break;
            }



            ///////////////////////////
            // variable
            wchar_t variable_holder[30];
            scan_ret = swscanf(m_CaptionReal.asWStr_c_str() + m_CaptionRealReadPointer, L"[variable name=\"%[a-zA-Z0-9_]s\"]", variable_holder);
            if (scan_ret == 1)
            {
                SkipTag(i);

                mCaption = mCaption + Ogre::UTFString(Ogre::StringConverter::toString(g_GameState->GetVariable(Ogre::UTFString(variable_holder).asUTF8())));
                //Ogre::LogManager::getSingletonPtr()->logMessage("String name found '" + Ogre::UTFString(variable_holder).asUTF8() + "'");

                continue;
            }



            ///////////////////////////
            // character name
            int character_id = 0;
            scan_ret = swscanf(m_CaptionReal.asWStr_c_str() + m_CaptionRealReadPointer, L"[character id=\"%d\"]", &character_id);
            if (scan_ret == 1)
            {
                SkipTag(i);

                mCaption = mCaption + Ogre::UTFString(g_GameState->CharacterGet(character_id).name);

                continue;
            }



            ///////////////////////////
            // party name
            int party_character_id = 0;
            scan_ret = swscanf(m_CaptionReal.asWStr_c_str() + m_CaptionRealReadPointer, L"[party_character id=\"%d\"]", &party_character_id);
            if (scan_ret == 1)
            {
                SkipTag(i);

                int character = g_GameState->GetPartyCharacter(party_character_id);
                if (character != -1)
                {
                    mCaption = mCaption + Ogre::UTFString(g_GameState->CharacterGet(character).name);
                }

                continue;
            }
        }

        mCaption.push_back(m_CaptionReal[i]);
    }

    m_CaptionRealReadPointer = i;

    // if we can read
    TextArea::setCaption(mCaption);

    // if text block is ended - return to set state opened window.
    if (m_CaptionRealReadPointer >= iend)
    {
        ret = MS_OPENED;
    }

    return ret;
}



void
MessageTextArea::SetMaxRowHeight(const int number)
{
    m_MaxRowHeight = number;
}



void
MessageTextArea::SetTopRow(const int number)
{
    m_CurrentRowTop = number;
}



const int
MessageTextArea::GetTopRow() const
{
    return m_CurrentRowTop;
}



void
MessageTextArea::SetClipping(float left, float top, float right, float bottom)
{
    int width = Ogre::OverlayManager::getSingleton().getViewportWidth() / 2;
    int height = Ogre::OverlayManager::getSingleton().getViewportHeight() / 2;

    m_ClipPlanes[0].d = -(mPixelTop + top - height) / height;
    m_ClipPlanes[1].d =  (mPixelLeft + mPixelWidth - right - width) / width;
    m_ClipPlanes[2].d = -(mPixelLeft + left - width) / width;
    m_ClipPlanes[3].d =  (mPixelTop + mPixelHeight - bottom - height) / height;
}



const Ogre::PlaneList&
MessageTextArea::getClipPlanes() const
{
    return m_ClipPlanes;
}



bool
MessageTextArea::CheckTag(int& i, Ogre::DisplayString& tag)
{
    int j = 0;

    for (; (i + j) < m_CaptionReal.size() && j < tag.size(); ++j)
    {
        if (m_CaptionReal[i + j] != tag[j])
        {
            return false;
        }
    }

    m_CaptionRealReadPointer += j;
    i += j;
    return true;
}



void
MessageTextArea::SkipTag(int& i)
{
    for (; i < m_CaptionReal.size(); ++i, ++m_CaptionRealReadPointer)
    {
        if (m_CaptionReal[i] == tag_end[0])
        {
            return;
        }
    }
}
