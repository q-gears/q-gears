#ifndef MESH_EXTRACTOR_H
#define MESH_EXTRACTOR_H

#include <Ogre.h>

#include "../../common/File.h"
#include "../../common/OgreGenUtilites.h"



void MeshExtractor(const MeshData& mesh_data, const Ogre::String& material_name, File* file, int offset_to_data, VectorTexForGen& textures, const Ogre::MeshPtr& mesh, const Ogre::String& name, int bone_id = -1);



#endif // MESH_EXTRACTOR_H
