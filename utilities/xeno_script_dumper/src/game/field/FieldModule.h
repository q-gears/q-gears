// $Id: FieldModule.h 103 2006-11-26 07:19:38Z crazy_otaku $

#ifndef FIELDSCREEN_H
#define FIELDSCREEN_H

#include "../../common/utilites/StdString.h"



class FieldModule
{
public:
                 FieldModule(void);
    virtual     ~FieldModule(void);

    void         LoadMap(const RString& name);
};



#endif // FIELDSCREEN_H
