to build you need to set 3 environment variables, you can do so directly via
CodeBlocks ( Settings -> Environment... -> Environment Variables )
BOOST_INCLUDE_DIR=$(BOOST_HOME)
BOOST_LIB_DIR=$(BOOST_HOME)\stage\lib
OGRE_HOME
MINGW_HOME // for codeblocks set it to the MinGW folder in Codeblocks root directory
SDL_HOME
ZLIB_INCLUDE_DIR=$(BOOST_HOME)
ZLIB_LIB_DIR=$(BOOST_HOME)\stage\lib

an exampel of folders and content that is expected
// b2 --layout=tagged toolset=gcc --build-type=complete --with-system  --with-atomic --with-chrono --with-date_time --with-filesystem --with-test --with-program_options --with-wave --with-thread
BOOST_INCLUDE_DIR/boost      // include files
// libaries with 'system' layout nameing see http://stackoverflow.com/questions/8940249/boost-how-bjam-constructs-a-library-name
BOOST_LIB_DIR/libboost_system-mt-d
...

OGRE_HOME/include
OGRE_HOME/lib
OGRE_HOME/lib/release/libOgreMain.dll.a
OGRE_HOME/lib/debug/libOgreMain_d.dll.a
// also posible, none the default variation compilation setting were set to install debug and
// release into the same folders for easier use
OGRE_HOME/lib/libOgreMain.dll.a
OGRE_HOME/lib/libOgreMain_d.dll.a
...

afterwards I did add the paths to the binaries (.dll files) to the PATH environment variable
for easier usage, so you don't have to copy the dlls to every sub folder where you want to use
em
