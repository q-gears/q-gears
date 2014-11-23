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
git clone https://github.com/paulsapps/q-gears.git
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

for CMake to find BOOST and OGRE SDK you should have 2 environment variables
BOOST_ROOT pointing to the folder of your boost version
and
OGRE_HOME set to the path of the Ogre SDK
after setting environment variables you might have to restart the applications depending on them
to have them recognize the newly set variables
