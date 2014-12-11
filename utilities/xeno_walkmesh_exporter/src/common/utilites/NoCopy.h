// $Id: NoCopy.h 76 2006-08-25 18:41:20Z crazy_otaku $
/**
 * @brief Class template for all classes that doesn't need copy constructor and assign operator.
 *
 * @warning If you want copy object you must not derive your class from this.
 */

#ifndef NO_COPY_h
#define NO_COPY_h



template <typename T>
class NoCopy
{
public:
// LIFECYCLE

    /**
     * @brief Default constructor.
     */
    NoCopy(void) {}

    /**
     * @brief Default virtual destructor.
     */
    virtual ~NoCopy(void) {}

private:
// LIFECYCLE
    /**
     * @brief A copy constructor.
     *
     * It is private so there are no derived class that can copy object by default copy constructor.
     */
    NoCopy(const NoCopy& copy);

    /**
     * @brief A assign operator.
     *
     * It is private so there are no derived class that can assign object by default assign operator.
     */
    NoCopy& operator=(const NoCopy& copy);
};



#endif // NO_COPY_h
