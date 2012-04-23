#ifndef BACKGROUND_2D_ANIMATION_H
#define BACKGROUND_2D_ANIMATION_H

#include <OgreString.h>
#include <OgreVector2.h>
#include <vector>



class Background2D;



class Background2DAnimation
{
public:
    Background2DAnimation( const Ogre::String& name, Background2D* background, const int tile_index );
    virtual ~Background2DAnimation();

    enum State
    {
        DEFAULT,
        ONCE
    };

    void  AddTime( const float time );

    const Ogre::String& GetName() const;

    void  SetTime( const float time );
    float GetTime() const;
    void  SetLength( const float time );
    float GetLength() const;

    void  AddUVKeyFrame( const float time, const float u1, const float v1, const float u2, const float v2 );

private:
    Background2DAnimation();

    Ogre::String  m_Name;
    Background2D* m_Background;
    int           m_TileIndex;

    float         m_Time;
    float         m_Length;

    struct Background2DKeyFrameUV
    {
        float time;
        float u1;
        float v1;
        float u2;
        float v2;
    };
    std::vector< Background2DKeyFrameUV > m_UV;
};



#endif // BACKGROUND_2D_ANIMATION_H
