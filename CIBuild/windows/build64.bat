msbuild /m QGears.sln /p:Configuration=Release
if %errorlevel% neq 0 exit /b %errorlevel%

cpack -C "Release"
if %errorlevel% neq 0 exit /b %errorlevel%

set path=%path%;C:\boost_1_55_0_64\lib64-msvc-12.0;C:\qt-everywhere-opensource-src-4.8.6_64\bin\release;C:\Ogre64\Build\bin\relwithdebinfo
ctest -C "Release" --verbose
if %errorlevel% neq 0 exit /b %errorlevel%

cd ..
cd ..
mkdir %CURRENT%
cd %CURRENT%
mkdir windows
cd .. 
dir
move q-gears\build\*.msi %CURRENT%\windows
upload %CURRENT%


