# What is QGears?


Q-Gears is an RPG engine for games like Squaresoft's Final Fantasy 7, Final Fantasy IX or Xenogears. It is designed to be cross-platfrom and run on modern operating systems such as Win32 and Linux.

## QGears Travis-CI build status

![Alt text](https://travis-ci.org/q-gears/q-gears.svg?branch=master)

### How do I build QGears?


#### Ubuntu Linux 14.04

Ogre version must be 1.9, Boost version must be 55, gcc version must be 4.9, QtCreator is optional - install if you want to use this as the IDE (recommended).

**Install required packages:**
```
* sudo apt-get update
* sudo apt-get install git
* sudo apt-get install build-essential
* sudo apt-get install libvorbis-dev
* sudo apt-get install libalut-dev
* sudo apt-get install cmake
* sudo apt-get install zlib1g-dev
* sudo apt-get install libboost-all-dev
* sudo apt-get install qtcreator
* sudo apt-get install libogre-1.9-dev
* sudo apt-get install libois-dev
```

**Sync down the QGears source code:**
```
mkdir qgears
cd qgears
git clone https://github.com/q-gears/q-gears.git
cd q-gears
```

**Build the code:**
```
mkdir build
cd build
cmake ..
make
```

#### Ubuntu Linux 12.04

If you are using an older Ubuntu version then you will have to add PPA's to get the correct gcc/boost/ogre versions, its easier just to upgrade the Ubuntu version IMO.

Anyway here is what we need for Ubuntu 12.04 (Travis-CI) **WARNING** updating the compiler and boost via the PPA's may break your system.

**Install required packages:**
```
* sudo apt-get update
* sudo apt-get install build-essential
* sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
* sudo add-apt-repository ppa:boost-latest/ppa -y
* sudo apt-get update
* sudo apt-get install git
* sudo apt-get install gcc-4.9
* sudo apt-get install g++-4.9
* sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 20
* sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.9 20
* sudo apt-get install libvorbis-dev
* sudo apt-get install libalut-dev
* sudo apt-get install cmake
* sudo apt-get install zlib1g-dev
* sudo apt-get install libois-dev
* sudo apt-get install boost1.55
* sudo apt-get install mercurial
* sudo apt-get install libcppunit-dev
* sudo apt-get install doxygen
* sudo apt-get install libxt-dev
* sudo apt-get install libxaw7-dev
* sudo apt-get install libxxf86vm-dev
* sudo apt-get install libxrandr-dev
* sudo apt-get install libglu-dev
* sudo apt-get install libfreetype6-dev 
* sudo apt-get install checkinstall
```

**Sync down source for Ogre 1.9:**

```
mkdir ogre
cd ogre
hg clone https://bitbucket.org/sinbad/ogre/src
```

**Build Ogre 1.9:**

```
cd src
hg update v1-9-0
mkdir ogre_build
cd ogre_build
cmake ..
make
sudo checkinstall
cd ..
cd ..
cd ..
```

**Sync down the QGears source code:**
```
mkdir qgears
cd qgears
git clone https://github.com/q-gears/q-gears.git
cd q-gears
```

**Build the code:**
```
mkdir build
cd build
cmake ..
make
```

#### Windows

**Download and install Visual Studio 2013 "community" (free/express) edition. Install all patches/Windows updates.**
```
http://www.visualstudio.com/en-us/products/free-developer-offers-vs
```

**Download and install the Ogre SDK 1.9 (The VC2013 build is not offical):**
```
https://bitbucket.org/lezo/ogre_build/downloads/OgreSDK_vc12_v1-9-0.exe
```
Install/extract to "C:\OgreSDK\"

**Download and install Git for windows:**
```
http://git-scm.com/download/win
```

**Download and install cmake for windows:**
```
http://www.cmake.org/files/v3.1/cmake-3.1.0-rc2-win32-x86.exe
```

Select "Add CMake to the system PATH for all users" - this makes things easier later on.

**Download boost 55:**
```
http://sourceforge.net/projects/boost/files/boost/1.55.0/boost_1_55_0.zip/download
```

Extract to C:\boost_1_55_0. Now we need to compile boost.

**Build boost 55:**

Open the Visual Studio 2013 command prompt and cd to the boost dir by entering 
```
"C:\boost_1_55_0" 
Then run
bootstrap.bat
Finally run (this may take a while to complete, you may pass -j8 here, where 8 is the number of cpu cores/threads to use):
b2 --toolset=msvc-12.0 --build-type=complete stage 
```

**Download the zlib dll version:**
```
http://zlib.net/zlib128-dll.zip
```
Extract to the root of C drive.

Now sync down the QGears source code, first create a directory some where you want to sync the code to using Windows explorer. Then right in the newly created directory and select "GIT Bash here".

In the git bash enter:
```
git clone https://github.com/q-gears/q-gears.git
```

**Building the QGears code:**
First launch a "Visual studio developer command prompt" (Found under "tools" in the start menu in the Visual studio directory" (you've already done this if you've got this far).

Now cd to where you synced the qgears source code to. For me this was "cd C:\Users\paul\Desktop\qgears\src"
```
mkdir build
cd build
set OGRE_HOME=C:\OgreSDK\OgreSDK_vc12_v1-9-0
cmake .. -DZLIB_ROOT=C:\zlib128-dll -DBOOST_ROOT=C:\boost_1_55_0
```

Now you can open the newly created QGears.sln in Visual Studio and build Win32/Release or Debug. If files are added/deleted/or the depends change then repeat the set and cmake commands in the Visual Studio command prompt in order to update QGears.sln.

# What next?

Now that you've got everything built see the wiki for how to run QGears, coding style, how to start hacking etc.

https://github.com/q-gears/q-gears/wiki
