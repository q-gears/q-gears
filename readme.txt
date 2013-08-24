to build you need to set 3 environment variables, you can do so directly via
CodeBlocks ( Settings -> Environment... -> Environment Variables )
BOOST_HOME
OGRE_HOME
MINGW_HOME // for codeblocks set it to the MinGW folder in Codeblocks root directory

an exampel of folders and content that is expected
// b2 --layout=tagged toolset=gcc --build-type=complete --with-system  --with-atomic --with-chrono --with-date_time --with-filesystem --with-test --with-program_options --with-wave --with-thread
BOOST_HOME/boost      // include files
BOOST_HOME/stage/lib  // libaries with 'system' layout nameing see http://stackoverflow.com/questions/8940249/boost-how-bjam-constructs-a-library-name
BOOST_HOME/stage/lib/libboost_system-mt-d
...

OGRE_HOME/include
OGRE_HOME/lib
// this is not the default compilation setting it's set to install debug and
// release into the same folders for easier use
OGRE_HOME/lib/libOgreMain.dll.a
OGRE_HOME/lib/libOgreMain_d.dll.a
...

afterwards I did add the paths to the binaries (.dll files) to the PATH environment variable
for easier usage, so you don't have to copy the dlls to every sub folder where you want to use
em
