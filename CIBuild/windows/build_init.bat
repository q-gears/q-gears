git rev-parse HEAD>current_version.txt
set /P CURRENT=<current_version.txt
echo %CURRENT%

mkdir build
::if %errorlevel% neq 0 exit /b %errorlevel%

cd build
if %errorlevel% neq 0 exit /b %errorlevel%

set QTDIR=C:\qt-everywhere-opensource-src-4.8.6_32
set OGRE_HOME=C:\Ogre\Build\sdk
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat"

cmake .. -T v120_xp -DZLIB_INCLUDE_DIR=C:/zlib-1.2.8 -DBOOST_ROOT=C:\boost_1_55_0_32 -DBOOST_LIBRARYDIR=C:\boost_1_55_0_32\lib32-msvc-12.0 -DOGRE_DIR=C:\Ogre\Build\sdk -DOIS_HOME=C:\Ogre\Dependencies\Build\ogredeps -DZLIB_LIBRARY=C:/zlib-1.2.8/contrib/vstudio/vc11/x86/ZlibDllReleaseWithoutAsm/zlibwapi.lib
if %errorlevel% neq 0 exit /b %errorlevel%
