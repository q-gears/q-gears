/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-30 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef __QGearsTexPlugin_H__
#define __QGearsTexPlugin_H__

#include <OgrePlugin.h>

#include "data/QGearsBackgroundFileManager.h"
#include "data/QGearsPFileManager.h"
#include "data/QGearsHRCFileManager.h"
#include "data/QGearsRSDFileManager.h"
#include "data/QGearsTexCodec.h"

namespace QGears {

	/** Plugin instance for various FFVII Data Formats */
    class DataPlugin : public Ogre::Plugin
    {
    public:
        DataPlugin();

        /// @copydoc Ogre::Plugin::getName
        const Ogre::String& getName() const;

        /// @copydoc Ogre::Plugin::install
        void install();

        /// @copydoc Ogre::Plugin::initialise
        void initialise();

        /// @copydoc Ogre::Plugin::shutdown
        void shutdown();

        /// @copydoc Ogre::Plugin::uninstall
        void uninstall();

        static const Ogre::String ms_plugin_name;

    private:
        PFileManager           *p_manager;
        HRCFileManager         *hrc_manager;
        RSDFileManager         *rsd_manager;
        BackgroundFileManager  *background_manager;

    };
}
#endif // __QGearsTexPlugin_H__
