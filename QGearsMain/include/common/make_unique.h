#ifndef _MAKE_UNIQUE_
#define _MAKE_UNIQUE_

#include <memory>

#ifndef _MSC_VER
namespace std
{
    template<typename T, typename ...Args>
    std::unique_ptr<T> make_unique( Args&& ...args )
    {
        return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
    }
}
#endif

#endif // _MAKE_UNIQUE_
