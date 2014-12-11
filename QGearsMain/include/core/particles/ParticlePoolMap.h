#ifndef PARTICLE_POOL_MAP_H
#define PARTICLE_POOL_MAP_H



template <typename T>
class ParticlePoolMap
{
public:
    typedef std::multimap<Ogre::String, T*> PoolMapMap;
    typedef typename PoolMapMap::iterator PoolMapIterator; // The 'typename' MUST be added, since T is not a fixed type

    ParticlePoolMap () {};
    virtual ~ParticlePoolMap() {};

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
        m_PoolMapIterator = m_Released.begin();
    };

    T*
    GetFirst()
    {
        ResetIterator();
        if (End())
        {
            return NULL;
        }

        T* t = m_PoolMapIterator->second;
        return t;
    };

    T*
    GetNext()
    {
        if (End())
        {
            return NULL;
        }

        ++m_PoolMapIterator;
        if (End())
        {
            return NULL;
        }

        T* t = m_PoolMapIterator->second;
        return t;
    };

    bool
    End()
    {
        return m_PoolMapIterator == m_Released.end();
    };

    void
    Clear()
    {
        m_Locked.clear();
        m_Released.clear();
    };

    void
    AddElement(const Ogre::String& key, T* element)
    {
        m_Locked.insert(make_pair(key, element));
    };

    T*
    ReleaseElement(const Ogre::String& key)
    {
        // Return with 0 if no elements left
        if (m_Locked.empty())
        {
            return NULL;
        }

        // Return the first element that is encountered
        T* t = 0;
        PoolMapIterator it;
        it = m_Locked.find(key);
        if (it != m_Locked.end())
        {
            // Get the element and move it to the released elements list
            t = it->second;
            m_Released.insert(make_pair(key, t));
            m_Locked.erase(it);
        }

        return t;
    };

    void
    ReleaseAllElements()
    {
        // Move all elements from locked elements to released elements
        PoolMapIterator it;
        for (it = m_Locked.begin(); it != m_Locked.end(); ++it)
        {
            m_Released.insert(make_pair(it->first, it->second));
        }
        m_Locked.clear();
        ResetIterator();
    };

    void
    LockLatestElement()
    {
        // Move element pointed by iterator from released elements to locked elements
        m_Locked.insert(make_pair(m_PoolMapIterator->first, m_PoolMapIterator->second));
        m_Released.erase(m_PoolMapIterator++); // Watch the ++ at the end to set mPoolMapIterator to the next element
    };

    void
    LockAllElements()
    {
        // Move all elements from release elements to locked elements
        PoolMapIterator it;
        for (it = m_Released.begin(); it != m_Released.end(); ++it)
        {
            m_Locked.insert(make_pair(it->first, it->second));
        }
        m_Released.clear();
        ResetIterator();
    };

protected:
    PoolMapMap m_Released;
    PoolMapMap m_Locked;
    PoolMapIterator m_PoolMapIterator;
};



#endif // PARTICLE_POOL_MAP_H
