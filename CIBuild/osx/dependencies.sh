brew update
# brew doctor
# brew outdated wget || brew upgrade wget
echo "Download deps"
brew install qt
wget https://github.com/paulsapps/Ogre1.9/releases/download/1.9.0/OgreDependencies_OSX_libc._20130610.zip
wget https://github.com/paulsapps/Ogre1.9/releases/download/1.9.0/NVIDIA_Cg.tgz
wget https://github.com/paulsapps/Ogre1.9/releases/download/1.9.0/OgreSDK.zip
echo "Install deps"
unzip OgreSDK.zip >> OgreSDK_extract.log
sudo tar xfzC NVIDIA_Cg.tgz /
unzip OgreDependencies_OSX_libc._20130610.zip >> extract.log
echo "Setup env vars"
#export OGRE_HOME="${PWD}/../OgreSDK"
#export OGRE_SDK="${PWD}/../OgreSDK"
export OGRE_HOME="/Users/travis/build/q-gears/q-gears/OgreSDK"
export OGRE_SDK="/Users/travis/build/q-gears/q-gears/OgreSDK"
export OIS_HOME="/Users/travis/build/q-gears/q-gears/Dependencies"

# /Users/travis/build/q-gears/q-gears/Dependencies;
# /Users/travis/build/q-gears/q-gears/../Dependencies

echo "Env vars are $OGRE_SDK and $OIS_HOME"
# Overwrite broken symlink with actual file
ls
ls ./Dependencies

cp ${PWD}/OgreSDK/lib/macosx/Release/Ogre.framework/Versions/1.9.0/Ogre ${PWD}/OgreSDK/lib/macosx/Release/Ogre.framework/Ogre
cp ${PWD}/OgreSDK/lib/macosx/Release/OgreOverlay.framework/Versions/1.9.0/OgreOverlay ${PWD}/OgreSDK/lib/macosx/Release/OgreOverlay.framework/OgreOverlay
