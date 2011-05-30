// $Id$

#ifndef INPUT_FILTER_h
#define INPUT_FILTER_h

#include <Ogre.h>
#include <OIS/OIS.h>
#include <vector>



enum InputEventType
{
    IE_PRESSED,  // The device was just pressed.
    IE_REPEATED, // The device is auto-repeating.
    IE_RELEASED, // The device is no longer pressed.  Exactly one RELEASED event will be sent for each PRESSED.
    IE_MOVED     // Mouse moved
};



struct InputEvent
{
    InputEvent():
        name(""),
        type(IE_PRESSED),
        x(0),
        y(0)
    {
    };

    InputEvent(const Ogre::String& n, const InputEventType t, int c_x, int c_y):
        name(n),
        type(t),
        x(c_x),
        y(c_y)
    {
    };

    Ogre::String   name;
    InputEventType type;
    int            x;
    int            y;
};

typedef std::vector<InputEvent> InputEventArray;



class InputFilter
{
public:
                       InputFilter(void);
    virtual           ~InputFilter(void);

    void               ButtonPressed(const int button, const bool down);
    void               MouseMoved(int x, int y);
    void               Reset(void);
    void               Update(void);

    bool               IsButtonPressed(const int button) const;
    void               GetInputEvents(InputEventArray& input_events);

    void               ClearAllMappings(void);
    void               SetInputMap(const int button, const Ogre::String& name);
    void               InsertEventsForButton(const int button, const InputEventType type);

private:
    struct Mapping
    {
        int          key;
        Ogre::String name;
    };

    bool                                 m_ButtonState[256 + 8];
    std::vector<Mapping>                 m_InputMap;
    InputEventArray                      m_EventQueue;
};



#endif // INPUT_FILTER_h
