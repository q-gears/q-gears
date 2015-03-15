#include "ScriptFile.h"
#include "../../common/Logger.h"

Logger* export_script;

std::vector< StackItem > stack;

Ogre::String raw_script;
u32 script_offset;
u32 script_pointer;
u32 script_stored_pointer;
u32 script_pointer_end;
u8 control;


ScriptFile::ScriptFile(const Ogre::String &file):
    File(file)
{
}



ScriptFile::ScriptFile(File *file, const u32 offset, const u32 length):
    File(file, offset, length)
{
}



ScriptFile::ScriptFile(u8* buffer, const u32 offset, const u32 length):
    File(buffer, offset, length)
{
}



ScriptFile::ScriptFile(File *file):
    File(file)
{
}



ScriptFile::~ScriptFile()
{
}



void
ScriptFile::DumpScripts()
{
    export_script = new Logger("scripts.txt");

    u32 number_of_entity = GetU8( 0x03 );
    for (u32 entity = 0; entity < number_of_entity; ++entity)
    {
        if ( GetU16LE( 0x80 + entity * 0x8 + 0x2) == 0 )
        {
            continue;
        }

        export_script->Log( "ENTITY: entity_id = 0x" + HexToString( entity, 2, '0' ) + "\n" );

        script_offset = 0x80 + GetU16LE( 0x80 + entity * 0x8 );

        u32 number_of_scripts = GetU8(script_offset + 1);

        for (u32 i = 0; i < number_of_scripts; ++i)
        {
            raw_script = "";
            u16 script_type = GetU16LE( script_offset + 2 + i * 0x4 );
            script_pointer = script_offset + 2 + GetU16LE( script_offset + 2 + i * 0x4 + 2 );
            script_pointer_end = script_pointer;

            export_script->Log( "SCRIPT: script_id = 0x" + HexToString( script_type, 2, '0' ) + "\n" );
            //export_script->Log( "script = w[8007aecc];\n" );
            //export_script->Log( "mask = 8007ae10;\n" );

            for( ; script_pointer <= script_pointer_end; )
            {
                u8 opcode = GetU8( script_pointer );
                raw_script += " " + HexToString( opcode, 2, '0' );

                //export_script->Log( "0x" + HexToString( script_pointer, 4, '0' ) + " 0x" + HexToString( script_pointer_end, 4, '0' ) + "\n" );

                if( opcode != 0x02 && opcode != 0x03 && opcode != 0x06 && opcode != 0x0b )
                {
                    script_stored_pointer = script_pointer;
                }

                if( opcode != 0x05 )
                {
                    export_script->Log( "0x" + HexToString( script_stored_pointer, 4, '0' ) );
                }

                // Jump
                if( opcode == 0x01 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    s16 jump = GetU16LE( script_pointer + 1 ) + script_pointer + 3;
                    AdvanceScript( 0, jump );
                    script_pointer += 3;

                    export_script->Log( "    JumpTo( 0x" + HexToString( jump, 4, '0' ) + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                // Jump If False
                else if( opcode == 0x02 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    s16 jump = GetU16LE( script_pointer + 1 ) + script_pointer + 3;
                    AdvanceScript( 3, jump );

                    export_script->Log("    JumpIf( " + GetStringFromStack() + " == false )To( 0x" + HexToString( jump, 4, '0' ) + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                // Jump If True
                else if( opcode == 0x03 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    s16 jump = GetU16LE( script_pointer + 1 ) + script_pointer + 3;
                    AdvanceScript( 3, jump );

                    export_script->Log("    JumpIf( " + GetStringFromStack() + " == true )To( 0x" + HexToString( jump, 4, '0' ) + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                // Return
                else if( opcode == 0x04 )
                {
                    export_script->Log("    Return(); //" + raw_script + "\n" );
                    raw_script = "";
                    script_pointer += 1;
                }
                // StackSubRoutine
                else if( opcode == 0x05 )
                {
                    script_stored_pointer = script_pointer;
                    AdvanceScript( 1 );

                    StackOpcodeParse();

                    u8 advance_op = GetU8( script_pointer );
                    if ( advance_op != 0x02 && advance_op != 0x03 && advance_op != 0x06 && advance_op != 0x0b )
                    {
                        export_script->Log( "0x" + HexToString( script_stored_pointer, 4, '0' ) );
                        export_script->Log( "    " + GetStringFromStack() + "; //" + raw_script + "\n" );
                        raw_script = "";
                    }
                }
                else if (opcode == 0x06)
                {
                    AdvanceScript( 1 );
                    u8 case_option   = GetU8( script_pointer );
                    raw_script += " " + HexToString( case_option, 2, '0' );
                    u16 default_jump = GetU16LE( script_pointer + 1 ) + script_pointer + 3;
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    AdvanceScript( 0, default_jump );


                    export_script->Log("    JumpSwitch( " + GetStringFromStack() + " )" );
                    for ( int i = 0; i < case_option; ++i )
                    {
                        raw_script += " " + HexToString( GetU8( script_pointer + 3 + i * 4 + 0 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 3 + i * 4 + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 3 + i * 4 + 2 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 3 + i * 4 + 3 ), 2, '0' );

                        u16 value  = GetU16LE( script_pointer + 3 + i * 4 + 0);
                        u16 jump  = GetU16LE( script_pointer + 3 + i * 4 + 2) + script_pointer + 3;
                        AdvanceScript( 0, jump );
                        export_script->Log("( case " + HexToString( value, 4, '0' ) + ": jump_to:0x" + HexToString( jump, 4, '0' ) + ")" );
                    }

                    export_script->Log("( default: jump_to:0x" + HexToString( default_jump, 4, '0' ) + "); //" + raw_script + "\n" );
                    raw_script = "";
                    AdvanceScript( 3 + case_option * 4 );
                }
                else if( opcode == 0x07 )
                {
                    Ogre::String data1 = HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    Ogre::String data2 = HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    raw_script += " " + data1 + " " + data2;
                    AdvanceScript( 3 );

                    export_script->Log( "    InitScriptEntity( entity_id = 0x" + data1 + ", shared_id = 0x" + data2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x08 )
                {
                    Ogre::String data1 = HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    Ogre::String data2 = HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    raw_script += " " + data1 + " " + data2;
                    AdvanceScript( 3 );

                    export_script->Log( "    InitType3Entity( entity_id = 0x" + data1 + ", shared_id = 0x" + data2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x09 )
                {
                    Ogre::String data1 = HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    Ogre::String data2 = HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    raw_script += " " + data1 + " " + data2;
                    AdvanceScript( 3 );

                    export_script->Log( "    InitModelEntity( entity_id = 0x" + data1 + ", shared_id = 0x" + data2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x0b )
                {
                    AdvanceScript( 1 );
                    u8 case_option   = GetU8( script_pointer );
                    s16 range_start  = GetU16LE( script_pointer + 1 );
                    u16 default_jump = GetU16LE( script_pointer + 3 ) + script_pointer;
                    AdvanceScript( 0, default_jump );

                    raw_script += " " + HexToString( case_option, 2, '0' );
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    raw_script += " " + HexToString( GetU8( script_pointer + 3 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 4 ), 2, '0' );

                    export_script->Log("    JumpSwitch( " + GetStringFromStack() + " )" );
                    for ( int i = 0; i < case_option; ++i )
                    {
                        raw_script += " " + HexToString( GetU8( script_pointer + 5 + i * 2 + 0 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 5 + i * 2 + 1 ), 2, '0' );

                        u16 jump  = GetU16LE( script_pointer + 5 + i * 2) + script_pointer;
                        AdvanceScript( 0, jump );
                        export_script->Log("( case 0x" + HexToString( i + range_start, 4, '0' ) + ": jump_to:0x" + HexToString( jump, 4, '0' ) + ")" );
                    }

                    export_script->Log("( default: jump_to:0x" + HexToString( default_jump, 4, '0' ) + "); //" + raw_script + "\n" );
                    raw_script = "";

                    AdvanceScript( 5 + case_option * 2 );
                }/*
                // switch in row
                else if (opcode == 0x0d)
                {
                    u16 case_option = GetU16LE(script_offset + script_pointer);
                    s16 range_start = GetU16LE(script_offset + script_pointer + 2);
                    u16 default_jump = GetU16LE(script_offset + script_pointer + 4);
                    export_script->Log("\t0x0b_JumpSwitchInRow(range_start:0x%04x)(default:0x%04x)", range_start, script_offset + default_jump + script_pointer + 1);
                    for (int i = 0; i < case_option; ++i)
                    {
                        u16 jump  = GetU16LE(script_offset + script_pointer + 6 + i * 2);
                        export_script->Log("(jump:0x%04x)", script_offset + jump + script_pointer + 1);
                    }
                    script_pointer += 6 + case_option * 2;
                    export_script->Log("; // pop 1 value from stack\n");
                }*/
                else if( opcode == 0x10 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String priority = Get8Variable();
                    Ogre::String entity_id = Get8Variable();
                    raw_script += " " + HexToString( GetU8( script_pointer ), 2, '0' );
                    Ogre::String script_id = HexToString( GetU8( script_pointer ), 2, '0' );
                    AdvanceScript( 1 );
                    export_script->Log( "    RunScriptAsync( priority = " + priority + ", entity_id = " + entity_id + ", script_id = 0x" + script_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x14 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String priority = Get8Variable();
                    Ogre::String entity_id = Get8Variable();
                    raw_script += " " + HexToString( GetU8( script_pointer ), 2, '0' );
                    Ogre::String script_id = HexToString( GetU8( script_pointer ), 2, '0' );
                    AdvanceScript( 1 );
                    export_script->Log( "    RunScriptStartSync( priority = " + priority + ", entity_id = " + entity_id + ", script_id = 0x" + script_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x1c )
                {
                    Ogre::String data = HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    Ogre::String entity_id = HexToString( GetU8( script_pointer + 2 ), 2, '0' );
                    raw_script += " " + data + " " + entity_id;
                    AdvanceScript( 3 );

                    export_script->Log( "    MoveScriptToEnd( entity_id = 0x" + entity_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x1d )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String x = Get16Variable();
                    Ogre::String z = Get16Variable();
                    export_script->Log( "    SetEntityPositionByXZ( x = " + x + ", z = " + z + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x1f )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String window_id = Get8Variable();
                    Ogre::String style = Get8Variable();
                    Ogre::String text_id = Get16Variable();
                    export_script->Log( "    WindowSync( window_id = " + window_id + ", style = " + style + ", text_id = " + text_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x20 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String window_id = Get8Variable();
                    Ogre::String style = Get8Variable();
                    Ogre::String text_id = Get16Variable();
                    export_script->Log( "    WindowAsync( window_id = " + window_id + ", style = " + style + ", text_id = " + text_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x21 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    export_script->Log( "    0x21( " + Get8Variable() + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x22 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    export_script->Log( "    Wait( " + Get8Variable() + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x23 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String x = Get16Variable();
                    Ogre::String y = Get16Variable();
                    export_script->Log( "    MoveToPosition( x = " + x + ", y = " + y + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x25 )
                {
                    AdvanceScript( 1 );
                    export_script->Log( "    ResetEntityData30_50_63_78(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x26 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    SetEntityData5c( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x27 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    export_script->Log( "    Set800c9df1( " + Get8Variable() + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x29)
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    if( control & 0x01 )
                    {
                        export_script->Log( "ERROR uexpected situation in opcode 0x29" );
                        break;
                    }

                    raw_script += " " + HexToString( GetU8( script_pointer + 0 ), 2, '0' );
                    u8 number = GetU8( script_pointer + 0 );
                    AdvanceScript( 1 );

                    export_script->Log( "    SetDataForType3Entity( number = " + HexToString( number, 2, '0' ) );
                    for ( int i = 0; i < number; ++i )
                    {
                        Ogre::String value1 = Get16Variable();
                        Ogre::String value2 = Get16Variable();
                        export_script->Log(", " + value1 + ", " + value2 );
                    }

                    export_script->Log(" ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x2a )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get16Variable();
                    export_script->Log( "    0x2a( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x2b )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    0x2b( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x2c )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    [ script + 0x16ed ] = h( GetCurrentEntityId() ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x2d )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    0x2d(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x2e )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    0x2e(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x2f )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    Set32and34inEntityStruct( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x33 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    SetEntityData54( animation_id = " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x34 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    SetEntityData56( animation_id = " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x35 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    SetEntityData58( animation_id = " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x36 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String rot = Get8Variable();
                    export_script->Log( "    SetEntityRotation( rotation = " + rot + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x3a )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String entity_id = Get8Variable();
                    Ogre::String value = Get8Variable();
                    export_script->Log( "    0x3a( entity_id = " + entity_id + ", " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x3d )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    SetEntityData60and61( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x40 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String animation_id = Get16Variable();
                    export_script->Log( "    PlayEntityAnimation( animation_id = " + animation_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x41 )
                {
                    AdvanceScript( 1 );
                    export_script->Log( "    WaitUntilAnimationComplete(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x43 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String entity_id = Get8Variable();
                    export_script->Log( "    InitAdditionalScriptEntityForCurrentEntity( entity_id = " + entity_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x47 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String flags = Get8Variable();
                    export_script->Log( "    SetEntityCollisionFlags( flags = " + flags + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x48 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    0x48( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x4b )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    Ogre::String solid = Get8Variable();
                    Ogre::String talk = Get8Variable();
                    export_script->Log( "    SetEntityCollision( " + value + ", solid_radius = " + solid + ", talk_radius = " + talk + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x50 )
                {
                    AdvanceScript( 1 );
                    export_script->Log( "    WaitUntilRotationComplete(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x51 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String entity_id = Get8Variable();
                    Ogre::String steps = Get8Variable();
                    export_script->Log( "    SetEntityRotateToEntity( entity_id = " + entity_id + ", steps = " + steps + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x52 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    SetEntityData74( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x54 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    0x54( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x55 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    SetEntityData5f( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x56 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String rotation = Get8Variable();
                    Ogre::String steps = Get8Variable();
                    export_script->Log( "    SetEntityRotateToRotation( rotation = " + rotation + ", steps = " + steps + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x59 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    Ogre::String value4 = Get8Variable();
                    export_script->Log( "    CallFuncc1368( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x5b )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    CallFuncc142c( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x61 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get16Variable();
                    export_script->Log( "    CallFuncc17f0( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x62 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable(); // must be less than 9 or else we must not read next value
                    Ogre::String value1 = Get8Variable();
                    export_script->Log( "    CharacterSet34Flag00000200( character_id = " + character_id + ", " + value1 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x65 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    export_script->Log( "    CallFuncc18d4( " + value1 + ", " + value2 + ", " + value3 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x66 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get16Variable();
                    export_script->Log( "    Set8007bba8( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x67 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    Set16e8and16ea( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x68 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    Set8007bbf4( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x6a )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    Set16f8to1(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x6f )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get16Variable();
                    Ogre::String value3 = Get8Variable();
                    Ogre::String value4 = Get8Variable();
                    export_script->Log( "    CallFuncc0df4( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x75 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    0x75( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x7a )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    SetEntityData4c( animation_id = " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x7b )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    SetEntityData4e( animation_id = " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x7e )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    export_script->Log( "    CallFuncc0bcc( " + value1 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x7f )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    0x7f(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x80 )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    0x80(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x86 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    Ogre::String value4 = Get8Variable();
                    export_script->Log( "    SetEntityData7c_7d_7e_7f( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x88 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get16Variable();
                    Ogre::String value3 = Get16Variable();
                    Ogre::String value4 = Get16Variable();
                    export_script->Log( "    CallFuncaba98( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x8b )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    SetEntityData6a_6b( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x8e )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    0x8e(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x8f )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String entity_id = Get8Variable();
                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    export_script->Log( "    0x8f( entity_id = " + entity_id + ", " + value1 + ", " + value2 + ", " + value3 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x90 )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    [ script + 0x1700 ] = h( -1 ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x92 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get16Variable();
                    Ogre::String value3 = Get8Variable();
                    Ogre::String value4 = Get8Variable();
                    Ogre::String value5 = Get8Variable();
                    Ogre::String value6 = Get8Variable();
                    Ogre::String value7 = Get8Variable();
                    export_script->Log( "    CallFuncc02d0( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + ", " + value5 + ", " + value6 + ", " + value7 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x93 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String flags = Get8Variable();
                    export_script->Log( "    SetEntityFlagsTo0f( flags = " + flags + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x94 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    export_script->Log( "    SetEntityData76_90_91( " + value1 + ", " + value2 + ", " + value3 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x9a )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    CallFuncc778c( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x9c )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    Play76Animation(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x9d )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    PlaySomeAnimation(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0x9f )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String entity_id = Get8Variable();
                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    export_script->Log( "    0x9f( entity_id = " + entity_id + ", " + value1 + ", " + value2 + ", " + value3 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xa1 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String x = Get16Variable();
                    Ogre::String y = Get16Variable();
                    Ogre::String z = Get16Variable();
                    export_script->Log( "    SetEntityPositionByXYZ( x = " + x + ", y = " + y + ", z = " + z + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xa8 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    0xa8( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xa9 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    Set8007ae2cAnd8007ae30WithScreenXYForEntity( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xaa )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    [80073998] = w(w[80073998] & fffbffff); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xab )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    [80073998] = w(w[80073998] | 00040000); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xb3 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get16Variable();
                    Ogre::String value4 = Get16Variable();
                    Ogre::String value5 = Get16Variable();
                    export_script->Log( "    CallFuncafac0( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + ", " + value5 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xb4 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get16Variable();
                    export_script->Log( "    0xb4( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xc5 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get16Variable();
                    export_script->Log( "    CallDynamic8006794c_1c_83c( " + value1 + ", " + value2 + ", 0x00, 0x00, 0x00 ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xc6 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get16Variable();
                    Ogre::String value3 = Get24Variable();
                    export_script->Log( "    CallDynamic8006794c_1c_83c( " + value1 + ", " + value2 + ", " + value3 + ", 0x00, 0x00 ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xc7 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get16Variable();
                    Ogre::String value3 = Get24Variable();
                    Ogre::String value4 = Get8Variable();
                    export_script->Log( "    CallDynamic8006794c_1c_83c( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + ", 0x00 ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xc8 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get16Variable();
                    Ogre::String value2 = Get16Variable();
                    Ogre::String value3 = Get24Variable();
                    Ogre::String value4 = Get8Variable();
                    Ogre::String value5 = Get8Variable();
                    export_script->Log( "    CallDynamic8006794c_1c_83c( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + ", " + value5 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xca )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    CallFuncc196c( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xcb )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    CallFuncc47e4( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xce )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get24Variable();
                    export_script->Log( "    0xce( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xd7 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value = Get8Variable();
                    export_script->Log( "    Set8007bc14to0x2cIfValueEqual8007bc10( " + value + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xd9 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable();
                    Ogre::String status_mask = Get8Variable();
                    export_script->Log( "    CharacterRemoveStatuses( character_id = " + character_id + ", status_mask = " + status_mask + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xda )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    Ogre::String value4 = Get16Variable();
                    Ogre::String value5 = Get16Variable();
                    export_script->Log( "    CallFuncafac0( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + ", " + value5 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xdc )
                {
                    AdvanceScript( 1 );

                    export_script->Log( "    PerformJump(); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xdd )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable();
                    export_script->Log( "    PartyRemove( character_id = " + character_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xde )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable();
                    Ogre::String string_id = Get16Variable();
                    export_script->Log( "    CharacterSetName( character_id = " + character_id + ", string_id = " + string_id + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xe2 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String x = Get16Variable();
                    Ogre::String y = Get16Variable();
                    Ogre::String z = Get16Variable();
                    Ogre::String steps = Get8Variable();
                    export_script->Log( "    Jump( x = " + x + ", y = " + y + ", z = " + z + ", steps = " + steps + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xe3 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    export_script->Log( "    Set8007bbd8( " + Get8Variable() + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xec )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    Ogre::String value4 = Get8Variable();
                    Ogre::String value5 = Get8Variable();
                    Ogre::String value6 = Get8Variable();
                    export_script->Log( "    0xec( " + value1 + ", " + value2 + ", " + value3 + ", " + value4 + ", " + value5 + ", " + value6 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xef )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    export_script->Log( "    Set8007bbe0_8007bbe8( " + Get8Variable() + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xf1 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable();
                    Ogre::String hp = Get16Variable();
                    export_script->Log( "    CharacterSetHP( character_id = " + character_id + ", hp = " + hp + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xf2 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable();
                    Ogre::String mp = Get16Variable();
                    export_script->Log( "    CharacterSetMP( character_id = " + character_id + ", mp = " + mp + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xf7 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    export_script->Log( "    CallFunc54fe0( " + value1 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xf8 )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    Ogre::String value3 = Get8Variable();
                    export_script->Log( "    CallFunc54e88( " + value1 + ", " + value2 + ", " + value3 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xfd )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get16Variable();
                    export_script->Log( "    CallDynamic8006794c_1c_8bc( " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else if( opcode == 0xfe )
                {
                    raw_script += " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
                    control = GetU8( script_pointer + 1 );
                    AdvanceScript( 2 );

                    Ogre::String character_id = Get8Variable();
                    Ogre::String type = Get8Variable();
                    Ogre::String preset_id = Get8Variable();
                    Ogre::String value1 = Get8Variable();
                    Ogre::String value2 = Get8Variable();
                    export_script->Log( "    CharacterInit( character_id = " + character_id + ", type = " + type + ", preset_id = " + preset_id + ", " + value1 + ", " + value2 + " ); //" + raw_script + "\n" );
                    raw_script = "";
                }
                else
                {
                    export_script->Log( "    MISSING OPCODE 0x" + HexToString( opcode, 2, '0' ) + "\n" );
                    break;
                }
            }

            export_script->Log( "\n" );
        }
        export_script->Log( "\n\n\n" );
    }

    delete export_script;
}



void
ScriptFile::StackOpcodeParse()
{
    Ogre::String result;
    stack.clear();

    for ( ;; )
    {
        u8 stack_opcode = GetU8( script_pointer );
        //export_script->Log( "StackOpcodeParse: 0x" + HexToString( script_pointer, 4, '0' ) + " opcode: 0x" + HexToString( stack_opcode, 2, '0' ) + "\n" );
        raw_script += " " + HexToString( stack_opcode, 2, '0' );
        AdvanceScript( 1 );

        if( stack_opcode == 0x04 )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value + "++ )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x05 )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value + "-- )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x0e)
        {
            Ogre::String value1 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value1 + " == false )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x11 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value1 + " * " + value2 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x12 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value1 + " / " + value2 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x13 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value1 + " % " + value2 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x14 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value1 + " + " + value2 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x15)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value1 + " - " + value2 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x16)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " << " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x17)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " >> " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x18)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " < " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x19)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " > " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x1a)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " <= " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x1b)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " >= " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x20)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " == " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x21)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " != " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x22)
        {
            Ogre::String value = GetStringFromStack();
            Ogre::String parameter = GetStringFromStack();
            Ogre::String mask = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "MultipleEqual( mask = " + mask + ", parameter = " + parameter + ", value = " + value + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x24)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " & " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x25)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " XOR " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x27)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " && " + value1 + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x28)
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " || " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x29 )
        {
            raw_script += " " + HexToString( GetU8( script_pointer + 0 ), 2, '0' );

            u16 data = GetU8( script_pointer + 0 );
            AdvanceScript( 1 );
            StackItem item;
            item.value_int = 0x18000000 | data;
            item.value_string = "";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x2a )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "CountActiveBits( " + value + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x2b)
        {
            Ogre::String parameter = GetStringFromStack();
            Ogre::String mask = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "GetUnitParameter( mask = " + mask + ", parameter = " + parameter + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x2c )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = StoreVariableByStack( value );
            stack.push_back( item );
        }
        else if (stack_opcode == 0x2d)
        {
            Ogre::String value = GetStringFromStack();
            Ogre::String parameter = GetStringFromStack();
            Ogre::String mask = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "StoreUnitsParamsByMask( mask = " + mask + ", parameter = " + parameter + ", value = " + value + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x32 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " += " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x33 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " -= " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x35 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " >>= " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x3d )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " &= " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x3e )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " ^= " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x3f )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "( " + value2 + " |= " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x4d )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "PickRandomActiveBit( " + value + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x4f )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "IsButtonPressed( " + value + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x52 )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "GetCurrentHpForCharacter( " + value + " )";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x54)
        {
            Ogre::String value = GetStringFromStack();
            Ogre::String parameter = GetStringFromStack();
            Ogre::String mask = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "MultipleAnd( mask = " + mask + ", parameter = " + parameter + ", value = " + value + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x5d )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "GetCurrentEntityRotationTo( " + value2 + ", " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x62 )
        {
            Ogre::String value = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "GetSinByRotation( " + value + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x64 )
        {
            Ogre::String value = GetStringFromStack( 0 );

            StackItem item;
            item.value_int = 0;
            item.value_string = "0x64stack( " + value + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x66 )
        {
            Ogre::String value1 = GetStringFromStack();
            Ogre::String value2 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "GetRotationBy( " + value2 + ", " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x6b )
        {
            Ogre::String value1 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "CallFunc4b85c( " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x6d )
        {
            Ogre::String value1 = GetStringFromStack();

            StackItem item;
            item.value_int = 0;
            item.value_string = "CallFunc378c4( " + value1 + " )";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x78 )
        {
            raw_script += " " + HexToString( GetU8( script_pointer + 0 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );

            u16 data = ( GetU8( script_pointer + 0 ) << 8 ) | GetU8( script_pointer + 1 );
            AdvanceScript( 2 );
            StackItem item;
            item.value_int = 0x10000000 | data;
            item.value_string = "";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x79 )
        {
            raw_script += " " + HexToString( GetU8( script_pointer + 0 ), 2, '0' );

            u16 data = GetU8( script_pointer + 0 );
            AdvanceScript( 1 );
            StackItem item;
            item.value_int = 0x14000000 | data;
            item.value_string = "";
            stack.push_back( item );
        }
        else if (stack_opcode == 0x7a)
        {
            raw_script += " " + HexToString( GetU8( script_pointer ), 2, '0' );

            u8 type = GetU8( script_pointer );
            AdvanceScript( 1 );
            StackItem item;
            item.value_int = 0;
            switch (type)
            {
                case 0x00: item.value_string = "GetRandomByte()"; break;
                case 0x02: item.value_string = "bu[script + 16ec]"; break;
                case 0x03: item.value_string = "funcb0124( 0xc00, 0xffffffff, 0, 0, 0 )"; break;
                case 0x06: item.value_string = "w[w[w[8006794c] + 1c] + 560]"; break;
                case 0x09: item.value_string = "Func4ecc4()"; break;
                case 0x0c: item.value_string = "w[8007ae2c]"; break;
                case 0x0d: item.value_string = "w[8007ae30]"; break;
                case 0x13: item.value_string = "Count80083248()"; break;
                default: item.value_string = "Unimplemented type 0x" + HexToString( type , 2, '0' ) + " for stack opcode 0x7a.";
            }
            stack.push_back( item );
        }
        else if( stack_opcode == 0x7d )
        {
            raw_script += " " + HexToString( GetU8( script_pointer ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );

            u16 data = GetU16LE( script_pointer );
            AdvanceScript( 2 );
            StackItem item;
            item.value_int = 0x1c000000 | data;
            item.value_string = "";
            stack.push_back( item );
        }
        else if( stack_opcode == 0x7e )
        {
            raw_script += " " + HexToString( GetU8( script_pointer ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 3 ), 2, '0' );

            u32 data = GetU32LE( script_pointer ) & 0x03ffffff;
            AdvanceScript( 4 );
            StackItem item;
            item.value_int = 0x1c000000 | data;
            item.value_string = "";
            stack.push_back( item );
        }
        // FinishSubRoutine
        else if( stack_opcode == 0x7f )
        {
            return;
        }
        // AddCommand
        else if( stack_opcode >= 0x80 )
        {
            StackItem item;
            item.value_int = StackOpcode80Parse( stack_opcode );
            item.value_string = "";
            stack.push_back( item );
        }
        else
        {
            //export_script->Log( "0x" + HexToString( script_position, 4, '0' ) );
            export_script->Log( " MISSING STACK OPCODE 0x" + HexToString( stack_opcode, 2, '0' ) + "; //" + raw_script + "\n" );
            raw_script = "";
            return;
        }
    }
}



u32
ScriptFile::StackOpcode80Parse( u32 stack_opcode )
{
    u32 command = stack_opcode & 0x03;
    command <<= 0x1a;
    u32 A1 = stack_opcode & 0x1c;
    A1 <<= 0x1b;
    command |= A1;
    u8 data = GetU8( script_pointer );
    raw_script += " " + HexToString( data, 2, '0' );
    AdvanceScript( 1 );
    command |= data;
    if (stack_opcode & 0x20)
    {
        data = GetU8( script_pointer );
        raw_script += " " + HexToString( data, 2, '0' );
        AdvanceScript( 1 );
        data <<= 0x8;
        command |= data;
    }
    //export_script->Log( "StackOpcode80Parse command: " + HexToString( command, 2, '0') + "\n" );
    return command;
}



Ogre::String
ScriptFile::LoadVariable( const StackItem& item )
{
    if( item.value_string != "" )
    {
        return "ERROR: LoadVariable must hanble top calue of stack as int. But value is \"" + stack.back().value_string + "\".";
    }
    u32 command = item.value_int;
    //export_script->Log( "Load with command: " + HexToString( command, 2, '0') + "\n" );
    if( ( command >> 0x18 ) == 0x10 )
    {
        switch (command & 0xff)
        {
            case 0x0: return "GetXPositionFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x1: return "GetYPositionFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x2: return "GetZPositionFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x3: return "GetYRotationFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x4: return "GetFlagsFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x5: return "GetMainEntityIdFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x6: return "GetCurrentScriptPriorityFromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            case 0x7: return "Get[3a]FromEntity( 0x" + HexToString( ( command >> 0x8 ) & 0xff, 2, '0' ) + " )";
            default: return "Unimplemented 0x" + HexToString( ( command >> 0x18 ), 2, '0' ) + " with type 0x" + HexToString( ( command & 0xff ), 2, '0' ) + " load.";
        }
    }
    else if( ( command >> 0x18 ) == 0x14 )
    {
        Ogre::String ret = "Get";
        if( ( command & 0x7 ) == 2 )
        {
            ret += "Party";
        }
        else if( ( command & 0x7 ) == 3 )
        {
            ret += "Enemy";
        }
        else if( ( command & 0x7 ) == 4 )
        {
            ret += "Units";
        }
        else
        {
            ret += "Unknown" + HexToString( ( command & 0x7 ), 2, '0' );
        }
        ret += "Mask()";
        return ret;
    }
    else if( ( command >> 0x18 ) == 0x18 )
    {
        switch ( ( command << 6 ) >> 6 )
        {
            case 0x0: return "GetXPositionFromEntity()";
            case 0x1: return "GetYPositionFromEntity()";
            case 0x2: return "GetZPositionFromEntity()";
            case 0x3: return "GetYRotationFromEntity()";
            case 0x4: return "GetFlagsFromEntity()";
            case 0x5: return "GetMainEntityIdFromEntity()";
            case 0x6: return "GetCurrentScriptPriorityFromEntity()";
            case 0x7: return "Get[3a]FromEntity()";
            default: return "Unimplemented 0x" + HexToString( ( command >> 0x18 ), 2, '0' ) + " with type 0x" + HexToString( ( ( command << 6 ) >> 6 ), 2, '0' ) + " load.";
        }
    }
    else if( ( command >> 0x18 ) == 0x1c )
    {
        return "0x" + HexToString( ( command << 0x6 ) >> 0x6, 8, '0' );
    }
    else if( ( command >> 0x18 ) == 0x20 )
    {
        return "(bu[ 0x8007aef0 + 0x" + HexToString( ( command & 0xffff ) >> 0x3, 4, '0' ) + " ] >> 0x" + HexToString( command & 0x7, 2, '0' ) + ") & 1";
    }
    else if( ( command >> 0x18 ) == 0x24 )
    {
        return "(bu[ script + 0x" + HexToString( ( command & 0xffff ) >> 0x3, 4, '0' ) + " ] >> 0x" + HexToString( command & 0x7, 2, '0' ) + ") & 1";
    }
    else if( ( command >> 0x18 ) == 0x48 )
    {
        return "b3[ w[ 0x8007bcf8 ] + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0x80 )
    {
        return "b[ 0x8007aef0 + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0x88 )
    {
        return "b[ w[ 0x8007bcf8 ] + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xa0 )
    {
        return "bu[ 0x8007aef0 + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xa4 )
    {
        return "bu[ script + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xa8 )
    {
        return "bu[ w[ 0x8007bcf8 ] + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xc0 )
    {
        return "h[ 0x8007aef0 + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xc4 )
    {
        return "h[ script + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xe0 )
    {
        return "hu[ 0x8007aef0 + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xe4 )
    {
        return "hu[ script + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }
    else if( ( command >> 0x18 ) == 0xe8 )
    {
        return "hu[ w[ 0x8007bcf8 ] + 0x" + HexToString( ( command & 0xffff ), 4, '0' ) + " ]";
    }

    return "Unimplemented 0x" + HexToString( ( command >> 0x18 ), 2, '0' ) + " load.";
}



Ogre::String
ScriptFile::GetStringFromStack( int position )
{
    StackItem item;

    if( position >= 0 )
    {
        item = stack[ stack.size() - 1 - position ];
    }
    else
    {
        item = stack.back();
        stack.pop_back();
    }

    Ogre::String stack_result = "";
    if ( item.value_string != "" )
    {
        Ogre::String string = item.value_string;
        return string;
    }
    else
    {
        return LoadVariable( item );
    }
}



Ogre::String
ScriptFile::StoreVariableByStack( const Ogre::String& value )
{
    if ( stack.back().value_string != "" )
    {
        return "ERROR: StoreVariableByStack must hanble top calue of stack as int. But value is \"" + stack.back().value_string + "\".";
    }

    u32 command = stack.back().value_int;
    //export_script->Log( "Save with command: " + HexToString( command, 2, '0') + " value: " + value + "\n" );
    stack.pop_back();

    if ( ( command >> 0x18 ) == 0x14 )
    {
        return "[ masks + 0x" + HexToString( ( command & 0x7 ) * 2, 2, '0' ) + " ] = h( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0x20 )
    {
        if ( value == "0x00000000" )
        {
            return "[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] = b( b[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] & 0x" + HexToString( 0xff ^ (1 << (command & 0x7)), 2, '0' ) + " )";
        }
        else
        {
            return "[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] = b( b[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] | 0x" + HexToString( 1 << (command & 0x7), 2, '0' ) + " )";
        }
    }
    else if ( ( command >> 0x18 ) == 0x24 )
    {
        if ( value == "0x00000000" )
        {
            return "[ script + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] = b( b[ script + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] & 0x" + HexToString( 0xff ^ (1 << (command & 0x7)), 2, '0' ) + " )";
        }
        else
        {
            return "[ script + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] = b( b[ script + 0x" + HexToString( (command & 0xffff) >> 0x3, 4, '0' ) + " ] | 0x" + HexToString( 1 << (command & 0x7), 2, '0' ) + " )";
        }
    }
    else if ( ( command >> 0x18 ) == 0x48 )
    {
        return "[ w[ 0x8007bcf8 ] + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = b3( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0x88 )
    {
        return "[ w[ 0x8007bcf8 ] + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = b( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xa0 )
    {
        return "[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = b( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xa4 )
    {
        return "[ script + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = b( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xa8 )
    {
        return "[ w[ 0x8007bcf8 ] + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = b( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xc0 )
    {
        return "[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = h( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xc4 )
    {
        return "[ script + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = h( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xe0 )
    {
        return "[ 0x8007aef0 + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = h( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xe4 )
    {
        return "[ script + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = h( " + value + " )";
    }
    else if ( ( command >> 0x18 ) == 0xe8 )
    {
        return "[ w[ 0x8007bcf8 ] + 0x" + HexToString( (command & 0xffff), 4, '0' ) + " ] = h( " + value + " )";
    }

    return "Unimplemented 0x" + HexToString( ( command >> 0x18 ), 2, '0' ) + " store.";
}



Ogre::String
ScriptFile::Get8Variable()
{
    if( control & 1 )
    {
        control >>= 1;
        StackOpcodeParse();
        return GetStringFromStack();
    }
    else
    {
        control >>= 1;
        u8 data = GetU8( script_pointer );
        raw_script += " " + HexToString( data, 2, '0' );
        AdvanceScript( 1 );
        return "0x" + HexToString( data, 2, '0' );
    }
}



Ogre::String
ScriptFile::Get16Variable()
{
    if (control & 1)
    {
        control >>= 1;
        StackOpcodeParse();
        return GetStringFromStack();
    }
    else
    {
        control >>= 1;
        u16 data = GetU16LE( script_pointer );
        raw_script += " " + HexToString( GetU8( script_pointer + 0 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' );
        AdvanceScript( 2 );
        return "0x" + HexToString( data, 4, '0' );
    }
}



Ogre::String
ScriptFile::Get24Variable()
{
    if (control & 1)
    {
        control >>= 1;
        StackOpcodeParse();
        return GetStringFromStack();
    }
    else
    {
        control >>= 1;
        u32 data = GetU16LE( script_pointer ) | ( GetU8( script_pointer + 2 ) << 0x10 );
        raw_script += " " + HexToString( GetU8( script_pointer + 0 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 1 ), 2, '0' ) + " " + HexToString( GetU8( script_pointer + 2 ), 2, '0' );
        AdvanceScript( 3 );
        return "0x" + HexToString( data, 6, '0' );
    }
}



void
ScriptFile::AdvanceScript( u32 value, u32 jump )
{
    script_pointer += value;
    script_pointer_end = (script_pointer > script_pointer_end) ? script_pointer : script_pointer_end;
    script_pointer_end = ( jump > script_pointer_end ) ? jump : script_pointer_end;
}
