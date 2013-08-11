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
#include "QGearsTexPlugin.h"

#include "QGearsTexCodec.h"

using Ogre::String;

namespace QGears {
    const String TexPlugin::ms_plugin_name( "Codec for TEX Image Files" );

    //---------------------------------------------------------------------
    TexPlugin::TexPlugin()
    {
    }

    //---------------------------------------------------------------------
    const String& TexPlugin::getName() const
    {
        return ms_plugin_name;
    }

    //---------------------------------------------------------------------
    void TexPlugin::install()
    {
        //install called - create stuff here
        TexCodec::install();
    }

    //---------------------------------------------------------------------
    void TexPlugin::initialise()
    {
        //intialise called - register stuff here
        TexCodec::initialise();
    }

    //---------------------------------------------------------------------
    void TexPlugin::shutdown()
    {
        //shutdown called - unregister stuff here
        TexCodec::shutdown();
    }

    //---------------------------------------------------------------------
    void TexPlugin::uninstall()
    {
        //uninstall called - delete stuff here
        TexCodec::uninstall();
    }
}
