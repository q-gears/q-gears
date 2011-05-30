#ifndef PARTICLE_POOL_H
#define PARTICLE_POOL_H

#include <list>



template <typename T>
class ParticlePool
{
public:
    typedef std::list<T*> PoolList;
    typedef typename PoolList::iterator PoolIterator; // The 'typename' MUST be added, since T is not a fixed type

    ParticlePool() {};
    virtual ~ParticlePool() {};

    bool
    IsEmpty()
    {
        return m_Released.empty();
    };

    size_t
    GetSize()
    {
        return m_Released.size();
    };

    void
    ResetIterator()
    {
        m_PoolIterator = m_Released.begin();
    };

    T*
    GetFirst()
    {
        ResetIterator();
        if (End())
        {
            return NULL;
        }

        T* t = *m_PoolIterator;
        return t;
    };

    T*
    GetNext()
    {
        if (End())
        {
            return NULL;
        }

        ++m_PoolIterator;
        if (End())
        {
            return NULL;
        }

        T* t = *m_PoolIterator;
        return t;
    };

    bool
    End()
    {
        return m_PoolIterator == m_Released.end();
    };

    void
    Clear()
    {
        m_Locked.clear();
        m_Released.clear();
    };

    void
    AddElement(T* element)
    {
        m_Locked.push_back(element);
    };

    T*
    ReleaseElement()
    {
        // Return with 0 if no elements left
        if (m_Locked.empty())
        {
            return 0;
        }

        // Move element from locked elements to released elements and return it
        T* t = m_Locked.front();
        m_Released.splice(m_Released.end(), m_Locked, m_Locked.begin());
        return t;
    };

    void
    ReleaseAllElements()
    {
        // Move all elements from locked elements to released elements
        m_Released.splice(m_Released.end(), m_Locked);
        ResetIterator();
    };

    void
    LockLatestElement()
    {
        if (End() == false)
        {
            m_Locked.push_back(*m_PoolIterator);
            m_PoolIterator = m_Released.erase(m_PoolIterator);
        }
    };

    void LockAllElements()
    {
        // Move all elements from released elements to locked elements
        m_Locked.splice(m_Locked.end(), m_Released);
        ResetIterator();
    };

    std::list<T*>&
    GetActiveElementsList()
    {
        return m_Released;
    };

protected:
    PoolList        m_Released; // List with precreated 'released' elements
    PoolList        m_Locked; // List with precreated 'locked' elements
    PoolIterator    m_PoolIterator;
};



#endif // PARTICLE_POOL_H
