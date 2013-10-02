Linux
-----
CMake should find your boost and ogre files automagically

Windows
-------
for CMake to find BOOST and OGRE SDK you should have 2 environment variables
BOOST_ROOT pointing to the folder of your boost version
and
OGRE_HOME set to the path of the Ogre SDK
after setting environment variables you might have to restart the applications depending on them
to have them recognize the newly set variables

Requirements
------------
OgreSDK 1.8 (Ogre::Singleton was changed from 1.7 to 1.8 so we're incompatible with 1.7)
Boost 1.51 (should be what ever the Ogre SDK needs)

mostly you can follow instructions here http://www.ogre3d.org/tikiwiki/tiki-index.php?page=Prerequisites
