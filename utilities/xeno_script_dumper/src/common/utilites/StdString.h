// $Id: StdString.h 101 2006-11-25 00:47:51Z gigaherz $

/* StdString - std::string convenience wrapper. */

// =============================================================================
//  FILE:  StdString.h
//  AUTHOR: Joe O'Leary (with outside help noted in comments)
//  REMARKS:
//      This header file declares the CStdStr template.  This template derives
//      the Standard C++ Library basic_string<> template and add to it the
//      the following conveniences:
//          - The full MFC RString set of functions (including implicit cast)
//          - writing to/reading from COM IStream interfaces
//          - Functional objects for use in STL algorithms

#ifndef STDSTRING
#define STDSTRING



// Standard headers needed
#include <string>           // basic_string
#include <algorithm>        // for_each, etc.
#include <functional>       // for StdStringLessNoCase, et al


#include <cstdarg>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstdarg>

#ifdef _MSC_VER
#ifdef va_copy
#undef va_copy
#endif
#define va_copy(a,b) (a=b)
#define snprintf _snprintf
#endif

// =============================================================================
// INLINE FUNCTIONS ON WHICH CSTDSTRING RELIES
//
// Usually for generic text mapping, we rely on preprocessor macro definitions
// to map to string functions.  However the CStdStr<> template cannot use
// macro-based generic text mappings because its character types do not get
// resolved until template processing which comes AFTER macro processing.  In
// other words, UNICODE is of little help to us in the CStdStr template
//
// Therefore, to keep the CStdStr declaration simple, we have these inline
// functions.  The template calls them often.  Since they are inline (and NOT
// exported when this is built as a DLL), they will probably be resolved away
// to nothing. 
//
// Without these functions, the CStdStr<> template would probably have to broken
// out into two, almost identical classes.  Either that or it would be a huge,
// convoluted mess, with tons of "if" statements all over the place checking the
// size of template parameter CT.
// 
// In several cases, you will see two versions of each function.  One version is
// the more portable, standard way of doing things, while the other is the
// non-standard, but often significantly faster Visual C++ way.
// =============================================================================
namespace StdString
{



// -----------------------------------------------------------------------------
// sslen: strlen/wcslen wrappers
// -----------------------------------------------------------------------------
template<typename CT>
inline int
sslen(const CT* pT)
{
    return pT == NULL ? 0 : std::basic_string<CT>::traits_type::length(pT);
}

inline int
sslen(const std::string &s)
{
    return s.length();
}



// -----------------------------------------------------------------------------
// sstolower/sstoupper -- convert characters to upper/lower case
// -----------------------------------------------------------------------------
inline char
sstoupper(char ch)
{
    return (ch >= 'a' && ch <= 'z')? char(ch + 'A' - 'a'): ch;
}

inline char
sstolower(char ch)
{
    return (ch >= 'A' && ch <= 'Z')? char(ch + 'a' - 'A'): ch;
}



// -----------------------------------------------------------------------------
// ssasn: assignment functions -- assign "sSrc" to "sDst"
// -----------------------------------------------------------------------------
inline void
ssasn(std::string &sDst, const std::string &sSrc)
{
    if (sDst.c_str() != sSrc.c_str())
    {
        sDst.erase();
        sDst.assign(sSrc);
    }
}

inline void
ssasn(std::string &sDst, const char* pA)
{
    // Watch out for NULLs, as always.
    if (pA == NULL)
    {
        sDst.erase();
    }
    else
        sDst.assign(pA);
}

inline void
ssasn(std::string &sDst, const int nNull)
{
    sDst.erase();
}



// -----------------------------------------------------------------------------
// ssadd: string object concatenation -- add second argument to first
// -----------------------------------------------------------------------------
inline void
ssadd(std::string &sDst, const std::string &sSrc)
{
    if (&sDst == &sSrc)
    {
        sDst.reserve(2 * sDst.size());
    }

    sDst.append(sSrc.c_str());
}

inline void
ssadd(std::string &sDst, const char* pA)
{
    if (pA)
    {
        // If the string being added is our internal string or a part of our
        // internal string, then we must NOT do any reallocation without
        // first copying that string to another object (since we're using a
        // direct pointer)
        if (pA >= sDst.c_str() && pA <= sDst.c_str() + sDst.length())
        {
            if (sDst.capacity() <= sDst.size() + sslen(pA))
            {
                sDst.append(std::string(pA));
            }
            else
            {
                sDst.append(pA);
            }
        }
        else
        {
            sDst.append(pA);
        }
    }
}



// -----------------------------------------------------------------------------
// ssicmp: comparison (case insensitive )
// -----------------------------------------------------------------------------
template<typename CT>
inline int
ssicmp(const CT* pA1, const CT* pA2)
{
    CT f;
    CT l;

    do 
    {
        f = sstolower(*(pA1++));
        l = sstolower(*(pA2++));
    }
    while ((f) && (f == l));

    return (int)(f - l);
}



// -----------------------------------------------------------------------------
// ssupr/sslwr: Uppercase/Lowercase conversion functions
// -----------------------------------------------------------------------------
template<typename CT>
inline void
sslwr(CT* pT, size_t nLen)
{
    for (CT* p = pT; static_cast<size_t>(p - pT) < nLen; ++p)
    {
        *p = (CT)sstolower(*p);
    }
}

template<typename CT>
inline void
ssupr(CT* pT, size_t nLen)
{
    for (CT* p = pT; static_cast<size_t>(p - pT) < nLen; ++p)
    {
        *p = (CT)sstoupper(*p);
    }
}



// -----------------------------------------------------------------------------
//  vsprintf/vswprintf or _vsnprintf/_vsnwprintf equivalents.  In standard
//  builds we can't use _vsnprintf/_vsnwsprintf because they're MS extensions.
// -----------------------------------------------------------------------------
inline int
ssvsprintf(char* pA, size_t nCount, const char* pFmtA, va_list vl)
{
    return vsnprintf(pA, nCount, pFmtA, vl);
}



//          Now we can define the template (finally!)
// =============================================================================
// TEMPLATE: CStdStr
//      template<typename CT> class CStdStr : public std::basic_string<CT>
//
// REMARKS:
//      This template derives from basic_string<CT> and adds some MFC RString-
//      like functionality
//
//      Basically, this is my attempt to make Standard C++ library strings as
//      easy to use as the MFC RString class.
//
//      Note that although this is a template, it makes the assumption that the
//      template argument (CT, the character type) is either char or wchar_t.  
// =============================================================================

template<typename CT>
class CStdStr;



template<typename CT>
inline CStdStr<CT>
operator+(const CStdStr<CT> &str1, const CStdStr<CT> &str2)
{
    CStdStr<CT> strRet(str1);
    strRet.append(str2);
    return strRet;
}

template<typename CT>
inline CStdStr<CT>
operator+(const CStdStr<CT> &str, CT t)
{
    // this particular overload is needed for disabling reference counting
    // though it's only an issue from line 1 to line 2
    CStdStr<CT> strRet(str);    // 1
    strRet.append(1, t);                // 2
    return strRet;
}

template<typename CT>
inline CStdStr<CT>
operator+(const CStdStr<CT> &str, const char* pA)
{
    return CStdStr<CT>(str) + CStdStr<CT>(pA);
}

template<typename CT>
inline CStdStr<CT>
operator+(const char* pA, const CStdStr<CT> &str)
{
    CStdStr<CT> strRet(pA);
    strRet.append(str);
    return strRet;
}



template<typename CT>
class CStdStr : public std::basic_string<CT>
{
    // Typedefs for shorter names.  Using these names also appears to help
    // us avoid some ambiguities that otherwise arise on some platforms
    typedef typename std::basic_string<CT>      MYBASE;  // my base class
    typedef CStdStr<CT>                         MYTYPE;  // myself
    typedef typename MYBASE::const_pointer      PCMYSTR; // const char* 
    typedef typename MYBASE::pointer            PMYSTR;  // char*
    typedef typename MYBASE::iterator           MYITER;  // my iterator type
    typedef typename MYBASE::const_iterator     MYCITER; // you get the idea...
    typedef typename MYBASE::reverse_iterator   MYRITER;
    typedef typename MYBASE::size_type          MYSIZE;
    typedef typename MYBASE::value_type         MYVAL;
    typedef typename MYBASE::allocator_type     MYALLOC;

public:
    // CStdStr inline constructors
    CStdStr()
    {
    }

    CStdStr(const MYTYPE& str) : MYBASE(str)
    {
    }

    CStdStr(const std::string& str)
    {
        ssasn(*this, str);
    }

    CStdStr(PCMYSTR pT, MYSIZE n)
        : MYBASE(pT, n)
    {
    }

    CStdStr(const char* pA)
    {
        *this = pA;
    }

    CStdStr(MYCITER first, MYCITER last)
        : MYBASE(first, last)
    {
    }

    CStdStr(MYSIZE nSize, MYVAL ch, const MYALLOC& al=MYALLOC())
        : MYBASE(nSize, ch, al)
    {
    }



    MYTYPE& operator=(const MYTYPE& str)
    { 
        ssasn(*this, str); 
        return *this;
    }

    MYTYPE& operator=(const std::string& str)
    {
        ssasn(*this, str);
        return *this;
    }

    MYTYPE& operator=(const char* pA)
    {
        ssasn(*this, pA);
        return *this;
    }

    MYTYPE& operator=(CT t)
    {
        this->assign(1, t);
        return *this;
    }



    // -------------------------------------------------------------------------
    // CStdStr inline concatenation.
    // -------------------------------------------------------------------------
    MYTYPE& operator+=(const MYTYPE& str)
    {
        ssadd(*this, str);
        return *this;
    }

    MYTYPE& operator+=(const std::string& str)
    {
        ssadd(*this, str);
        return *this; 
    }

    MYTYPE& operator+=(const char* pA)
    {
        ssadd(*this, pA);
        return *this;
    }

    MYTYPE& operator+=(CT t)
    {
        this->append(1, t);
        return *this;
    }



    // addition operators -- global friend functions.
    friend MYTYPE operator+ <>(const MYTYPE& str1, const MYTYPE& str2);
    friend MYTYPE operator+ <>(const MYTYPE& str,  CT t);
    friend MYTYPE operator+ <>(const MYTYPE& str,  const char* sz);
    friend MYTYPE operator+ <>(const char* pA,     const MYTYPE& str);



    // -------------------------------------------------------------------------
    // Case changing functions
    // -------------------------------------------------------------------------
    MYTYPE& MakeUpper()
    {
        //  Strictly speaking, this would be about the most portable way

        //  std::transform(begin(),
        //                 end(),
        //                 begin(),
        //                 std::bind2nd(SSToUpper<CT>(), std::locale()));

        // But practically speaking, this works faster

        if ( !this->empty() )
            ssupr(GetBuf(), this->size());

        return *this;
    }

    MYTYPE& MakeLower()
    {
        //  Strictly speaking, this would be about the most portable way

        //  std::transform(begin(),
        //                 end(),
        //                 begin(),
        //                 std::bind2nd(SSToLower<CT>(), std::locale()));

        // But practically speaking, this works faster

        if ( !this->empty() )
            sslwr(GetBuf(), this->size());

        return *this;
    }



    // -------------------------------------------------------------------------
    // CStdStr -- Direct access to character buffer.  In the MS' implementation,
    // the at() function that we use here also calls _Freeze() providing us some
    // protection from multithreading problems associated with ref-counting.
    // -------------------------------------------------------------------------
    CT* GetBuf(int nMinLen=-1)
    {
        if ( static_cast<int>(this->size()) < nMinLen )
            this->resize(static_cast<MYSIZE>(nMinLen));

        return this->empty() ? const_cast<CT*>(this->data()) : &(this->at(0));
    }

    void RelBuf(int nNewLen=-1)
    {
        this->resize(static_cast<MYSIZE>(nNewLen > -1 ? nNewLen : sslen(this->c_str())));
    }

    // -------------------------------------------------------------------------
    // FUNCTION:  CStdStr::Format
    //      void _cdecl Formst(CStdStringA& const char* szFormat, ...)
    //      void _cdecl Format(const char* szFormat);
    //           
    // DESCRIPTION:
    //      This function does sprintf/wsprintf style formatting on CStdStringA
    //      objects.  It looks a lot like MFC's RString::Format.  Some people
    //      might even call this identical.  Fortunately, these people are now
    //      dead.
    //
    // PARAMETERS: 
    //      nId - ID of string resource holding the format string
    //      szFormat - a const char* holding the format specifiers
    //      argList - a va_list holding the arguments for the format specifiers.
    //
    // RETURN VALUE:  None.
    // -------------------------------------------------------------------------
    // formatting (using wsprintf style formatting)

    // If they want a Format() function that safely handles string objects
    // without casting
 

    void Format(const CT* szFmt, ...)
    {
        va_list argList;
        va_start(argList, szFmt);
        FormatV(szFmt, argList);
        va_end(argList);
    }

    #define MAX_FMT_TRIES       5    // #of times we try 
    #define FMT_BLOCK_SIZE      2048 // # of bytes to increment per try
    #define BUFSIZE_1ST 256
    #define BUFSIZE_2ND 512
    #define STD_BUF_SIZE        1024

    // -------------------------------------------------------------------------
    // FUNCTION:  FormatV
    //      void FormatV(const char* szFormat, va_list, argList);
    //           
    // DESCRIPTION:
    //      This function formats the string with sprintf style format-specs. 
    //      It makes a general guess at required buffer size and then tries
    //      successively larger buffers until it finds one big enough or a
    //      threshold (MAX_FMT_TRIES) is exceeded.
    //
    // PARAMETERS: 
    //      szFormat - a const char* holding the format of the output
    //      argList - a Microsoft specific va_list for variable argument lists
    //
    // RETURN VALUE: 
    // -------------------------------------------------------------------------

    void FormatV(const CT* szFormat, va_list argList)
    {
        static bool bExactSizeSupported;
        static bool bInitialized = false;
        if( !bInitialized )
        {
            /* Some systems return the actual size required when snprintf
             * doesn't have enough space.  This lets us avoid wasting time
             * iterating, and wasting memory. */
            bInitialized = true;
            char ignore;
            bExactSizeSupported = ( snprintf( &ignore, 0, "Hello World" ) == 11 );
        }

        if( bExactSizeSupported )
        {
            va_list tmp;
            va_copy( tmp, argList );
            char ignore;
            int iNeeded = ssvsprintf( &ignore, 0, szFormat, tmp );
            va_end(tmp);

            char *buf = GetBuffer( iNeeded+1 );
            ssvsprintf( buf, iNeeded+1, szFormat, argList );
            ReleaseBuffer( iNeeded );
            return;
        }

        int nChars          = FMT_BLOCK_SIZE;
        int nTry            = 1;
        do  
        {
            // Grow more than linearly (e.g. 512, 1536, 3072, etc)
            char *buf = GetBuffer(nChars);
            int nUsed = ssvsprintf(buf, nChars-1, szFormat, argList);

            if(nUsed == -1)
            {
                nChars += ((nTry+1) * FMT_BLOCK_SIZE);
                ReleaseBuffer();
                continue;
            }

            /* OK */
            ReleaseBuffer(nUsed);
            break;
        } while ( nTry++ < MAX_FMT_TRIES );
    }
    

    // -------------------------------------------------------------------------
    // RString Facade Functions:
    //
    // The following methods are intended to allow you to use this class as a
    // drop-in replacement for CString.
    // -------------------------------------------------------------------------
    int CompareNoCase(PCMYSTR szThat)   const
    {
        return ssicmp(this->c_str(), szThat);
    }

    bool EqualsNoCase(PCMYSTR szThat)   const
    {
        return CompareNoCase(szThat) == 0;
    }

    // -------------------------------------------------------------------------
    // GetXXXX -- Direct access to character buffer
    // -------------------------------------------------------------------------
    CT* GetBuffer(int nMinLen=-1)
    {
        return GetBuf(nMinLen);
    }

    MYTYPE Left(int nCount) const
    {
        // Range check the count.

        nCount = std::max(0, std::min(nCount, static_cast<int>(this->size())));
        return this->substr(0, static_cast<MYSIZE>(nCount)); 
    }

    void MakeReverse()
    {
        std::reverse(this->begin(), this->end());
    }

    void ReleaseBuffer(int nNewLen=-1)
    {
        RelBuf(nNewLen);
    }

    int Replace(CT chOld, CT chNew)
    {
        int nReplaced   = 0;
        for ( MYITER iter=this->begin(); iter != this->end(); iter++ )
        {
            if ( *iter == chOld )
            {
                *iter = chNew;
                nReplaced++;
            }
        }
        return nReplaced;
    }

    int Replace(PCMYSTR szOld, PCMYSTR szNew)
    {
        int nReplaced       = 0;
        MYSIZE nIdx         = 0;
        MYSIZE nOldLen      = sslen(szOld);
        if ( 0 == nOldLen )
            return 0;

        static const CT ch  = CT(0);
        MYSIZE nNewLen      = sslen(szNew);
        PCMYSTR szRealNew   = szNew == 0 ? &ch : szNew;

        while ( (nIdx=this->find(szOld, nIdx)) != MYBASE::npos )
        {
            replace(this->begin()+nIdx, this->begin()+nIdx+nOldLen, szRealNew);
            nReplaced++;
            nIdx += nNewLen;
        }
        return nReplaced;
    }

    MYTYPE Right(int nCount) const
    {
        // Range check the count.

        nCount = std::max(0, std::min(nCount, static_cast<int>(this->size())));
        return this->substr(this->size()-static_cast<MYSIZE>(nCount));
    }

    // Array-indexing operators.  Required because we defined an implicit cast
    // to operator const CT* (Thanks to Julian Selman for pointing this out)
    CT& operator[](int nIdx)
    {
        return MYBASE::operator[](static_cast<MYSIZE>(nIdx));
    }

    const CT& operator[](int nIdx) const
    {
        return MYBASE::operator[](static_cast<MYSIZE>(nIdx));
    }

    CT& operator[](unsigned int nIdx)
    {
        return MYBASE::operator[](static_cast<MYSIZE>(nIdx));
    }

    const CT& operator[](unsigned int nIdx) const
    {
        return MYBASE::operator[](static_cast<MYSIZE>(nIdx));
    }

    CT& operator[](long unsigned int nIdx){
      return MYBASE::operator[](static_cast<MYSIZE>(nIdx));
    }
       
    const CT& operator[](long unsigned int nIdx) const {
      return MYBASE::operator[](static_cast<MYSIZE>(nIdx));
    }

    operator const CT*() const
    {
        return this->c_str();
    }

};



// =============================================================================
//                      END OF CStdStr INLINE FUNCTION DEFINITIONS
// =============================================================================
//  Now typedef our class names based upon this humongous template

typedef CStdStr<char> CStdString;    // a better std::string



// -----------------------------------------------------------------------------
// FUNCTIONAL COMPARATORS:
// REMARKS:
//      These structs are derived from the std::binary_function template.  They
//      give us functional classes (which may be used in Standard C++ Library
//      collections and algorithms) that perform case-insensitive comparisons of
//      CStdString objects.  This is useful for maps in which the key may be the
//       proper string but in the wrong case.
// -----------------------------------------------------------------------------

struct StdStringLessNoCase
    : std::binary_function<CStdString, CStdString, bool>
{
    inline bool
    operator()(const CStdString& sLeft, const CStdString& sRight) const
    { return ssicmp(sLeft.c_str(), sRight.c_str()) < 0; }
};

struct StdStringEqualsNoCase
    : std::binary_function<CStdString, CStdString, bool>
{
    inline bool
    operator()(const CStdString& sLeft, const CStdString& sRight) const
    { return ssicmp(sLeft.c_str(), sRight.c_str()) == 0; }
};


}   // namespace StdString

typedef StdString::CStdString RString;



#endif  // #ifndef STDSTRING_H

/*
 * COPYRIGHT:
 *  1999 Joseph M. O'Leary.  This code is free.  Use it anywhere you want.
 *  Rewrite it, restructure it, whatever.  Please don't blame me if it makes
 *  your $30 billion dollar satellite explode in orbit.  If you redistribute
 *  it in any form, I'd appreciate it if you would leave this notice here.
 *
 *  If you find any bugs, please let me know:
 *
 *          jmoleary@earthlink.net
 *          http://home.earthlink.net/~jmoleary
 */
