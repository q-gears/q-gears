#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include <Ogre.h>



class FieldModel
{
public:
    FieldModel();
    virtual ~FieldModel();

    void Export(const Ogre::String& model_file, const Ogre::String& texture_file);
};



#endif // FIELDMODEL_H
