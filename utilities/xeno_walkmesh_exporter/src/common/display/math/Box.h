// $Id$

#ifndef BOX_H
#define BOX_H

#include <limits>

#include "Vector.h"

class Box3
{
public:
  Box3():
    mLow(std::numeric_limits<float>::max(),
	 std::numeric_limits<float>::max(),
	 std::numeric_limits<float>::max()),
    mHigh(-std::numeric_limits<float>::max(),
	  -std::numeric_limits<float>::max(),
	  -std::numeric_limits<float>::max())
  {}

public:
  inline const Vector3 &GetLow() const { return mLow; }
  inline const Vector3 &GetHigh() const { return mHigh; }

public:
  inline void Insert(const Vector3 &p)
  {
    if (p.x < mLow.x) mLow.x = p.x;
    if (p.y < mLow.y) mLow.y = p.y;
    if (p.z < mLow.z) mLow.z = p.z;

    if (mHigh.x < p.x) mHigh.x = p.x;
    if (mHigh.y < p.y) mHigh.y = p.y;
    if (mHigh.z < p.z) mHigh.z = p.z;
  }

protected:
  Vector3 mLow;
  Vector3 mHigh;
};

#endif // !BOX_H
