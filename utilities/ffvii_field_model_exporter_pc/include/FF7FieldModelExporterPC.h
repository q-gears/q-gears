/*
-----------------------------------------------------------------------------
Copyright (c) 26.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#ifndef __FF7FieldModelExporterPC_H__
#define __FF7FieldModelExporterPC_H__

#include "QGearsUtility.h"

namespace QGears
{
    namespace FF7
    {
        class FieldModelExporterPC : public Utility
        {
        public:
            FieldModelExporterPC( int argc, char *argv[] );
            virtual ~FieldModelExporterPC();

        protected:
            virtual String getWindowTitle( void ) const;

        private:
            FieldModelExporterPC();
        };
    }
}

#endif // __FF7FieldModelExporterPC_H__
