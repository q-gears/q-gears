// $Id$

/**
 * @brief Abstract class for all instances that can be drawn, receive update and input.
 */

#ifndef ACTOR_h
#define ACTOR_h

#include "../../TypeDefine.h"
#include "../../utilites/NoCopy.h"



class Actor : public NoCopy<Actor>
{
public:
    /**
     * Constructor.
     */
    Actor(void);

    /**
     * Destructor.
     */
    virtual
    ~Actor(void);

    /**
     * Handles update.
     */
    virtual void
    Update(const Uint32 deltaTime) = 0;
};



#endif // ACTOR_h
