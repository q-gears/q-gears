brew update
# brew doctor
# brew outdated wget || brew upgrade wget
brew install qt
wget https://github.com/paulsapps/Ogre1.9/releases/download/1.9.0/OgreDependencies_OSX_libc._20130610.zip
wget https://github.com/paulsapps/Ogre1.9/releases/download/1.9.0/NVIDIA_Cg.tgz
wget https://github.com/paulsapps/Ogre1.9/releases/download/1.9.0/OgreSDK.zip
unzip OgreSDK.zip >> OgreSDK_extract.log
sudo tar xfzC NVIDIA_Cg.tgz /
unzip OgreDependencies_OSX_libc._20130610.zip >> extract.log
export OGRE_HOME=${PWD}/../OgreSDK
export OGRE_SDK=${PWD}/../OgreSDK
export OIS_HOME=${PWD}/../Dependencies

# Overwrite broken symlink with actual file
cp ${OGRE_SDK}/lib/macosx/Release/Ogre.framework/Versions/1.9.0/Ogre ${OGRE_SDK}/lib/macosx/Release/Ogre.framework/Ogre
cp ${OGRE_SDK}/lib/macosx/Release/OgreOverlay.framework/Versions/1.9.0/OgreOverlay ${OGRE_SDK}/lib/macosx/Release/OgreOverlay.framework/OgreOverlay