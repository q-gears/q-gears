git rev-parse HEAD>current_version.txt
set /P CURRENT=<current_version.txt
echo %CURRENT%

mkdir build
::if %errorlevel% neq 0 exit /b %errorlevel%

cd build
if %errorlevel% neq 0 exit /b %errorlevel%

set QTDIR=C:\qt-everywhere-opensource-src-4.8.6_64
set OGRE_HOME=C:\Ogre64\Build\sdk
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\VsDevCmd.bat"

cmake .. -G"Visual Studio 12 2013 Win64" -T v120_xp -DZLIB_INCLUDE_DIR=C:/zlib-1.2.8 -DBOOST_ROOT=C:\boost_1_55_0_64 -DBOOST_LIBRARYDIR=C:\boost_1_55_0_64\lib64-msvc-12.0 -DOGRE_DIR=C:\Ogre64\Build\sdk -DOIS_HOME=C:\Ogre64\Dependencies\Build\ogredeps -DZLIB_LIBRARY=C:/zlib-1.2.8/contrib/vstudio/vc11/x64/ZlibDllReleaseWithoutAsm/zlibwapi.lib
if %errorlevel% neq 0 exit /b %errorlevel%
