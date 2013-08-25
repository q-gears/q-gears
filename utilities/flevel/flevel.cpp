/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-07-31 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#include <cstdio>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "common/FileSystem.h"
#include "common/Logger.h"
//#include "common/QGearsFLevelFile.h"

using std::cout;
using std::endl;

namespace bfs = boost::filesystem;
namespace bpo = boost::program_options;

void extractSections( const bfs::path &file_in, const bfs::path &path_out )
{
    FILESYSTEM = new FileSystem();
    /*
    File f( file_in.string() );
    // TODO alternative implementation adapted to FLevel Resource
    QGears::FLevelFile flevel( &f );
    File** sections( flevel.getSections() );

    bfs::path file_out;
    file_out = path_out / ( file_in.stem().string() + ".script" );
    sections[0]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".cam_matrix" );
    sections[1]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".model_loader" );
    sections[2]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".palette" );
    sections[3]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".walkmesh" );
    sections[4]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".tilemap" );
    sections[5]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".encounter" );
    sections[6]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".trigger" );
    sections[7]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".background.ppm" );
    sections[8]->WriteFile( file_out.string() );
    file_out = path_out / ( file_in.stem().string() + ".background" );
    sections[9]->WriteFile( file_out.string() );
    */
}

int
main(int ac, char *av[])
{
    const char* PO_HELP( "help" );
    const char* PO_INPUT_FILE( "input-file" );
    const char* PO_OUTPUT_PATH( "output-path" );

    try {
        bpo::options_description generic("Generic options");
        generic.add_options()
            ( PO_HELP, "produce help message" )
            ;

        // Hidden options, will be allowed both on command line and
        // in config file, but will not be shown to the user.
        bpo::options_description hidden("Hidden options");
        hidden.add_options()
            ( PO_INPUT_FILE , bpo::value< bfs::path >()->required(), "lzs compressed file" )
            ( PO_OUTPUT_PATH
              , bpo::value< bfs::path >()->default_value( "." )
              , "path to output section files"
            )
            ;

        bpo::positional_options_description p;
        p.add( PO_INPUT_FILE , 1 )
         .add( PO_OUTPUT_PATH, 1 );

        bpo::options_description cmdline_options;
        cmdline_options.add( generic ).add( hidden );
        bpo::variables_map vm;
        bpo::store( bpo::command_line_parser( ac, av ).options( cmdline_options ).positional( p ).run(), vm );

        bfs::path self( av[0] );
        if ( vm.count( PO_HELP ) )
        {
            cout << "Usage: " << self.stem().string()
                 << " [options]"
                 << " " << PO_INPUT_FILE
                 << " " << PO_OUTPUT_PATH
                 << endl
                 << generic << "\n";
            return 0;
        }

        bpo::notify( vm );
        // TODO implement compression?
        LOGGER = new Logger( self.stem().string() + ".log" );
        extractSections( vm[ PO_INPUT_FILE ].as< bfs::path >(), vm[ PO_OUTPUT_PATH ].as< bfs::path >() );
    }
    catch( std::exception& e )
    {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
