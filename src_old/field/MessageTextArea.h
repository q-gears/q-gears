#ifndef MESSAGE_TEXT_AREA_h
#define MESSAGE_TEXT_AREA_h

#include "../core/ui/TextArea.h"



class MessageTextArea : public TextArea
{
public:
                                MessageTextArea(const Ogre::String& name);
    virtual                    ~MessageTextArea();

    virtual void                setCaption(const Ogre::DisplayString& caption);
    void                        ClearCurrentCaption();
    const int                   GetCaptionSize() const;
    const int                   GetCaptionRealSize() const;
    MessageState                AddCharactersToDisplay(float& number_symbols_to_read, float& time);
    void                        SetMaxRowHeight(const int number);
    void                        SetTopRow(const int number);
    const int                   GetTopRow() const;

    void                        SetClipping(float left, float top, float right, float bottom);

    const Ogre::PlaneList&      getClipPlanes() const;

private:
    bool                        CheckTag(int& i, Ogre::DisplayString& tag);
    void                        SkipTag(int& i);

private:
    Ogre::DisplayString m_CaptionReal;
    int                 m_CaptionRealReadPointer;
    int                 m_CaptionRealSize;

    int                 m_CurrentRowTop;
    int                 m_CurrentRowHeight;
    int                 m_MaxRowHeight;

    Ogre::PlaneList     m_ClipPlanes;
};



#endif // MESSAGE_TEXT_AREA_h
