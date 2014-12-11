#include "AnimationScriptDumper.h"



void
AdvanceScript(u32 value, u32& current, u32& end)
{
    current += value;
    u32 temp_end = current;
    end = (temp_end > end) ? temp_end : end;
}



void
AnimationScriptDumper(File* file, int offset_to_anim_file, Logger* dump)
{
    int number_of_scripts = 0x20;

    for (u8 i = 0; i < number_of_scripts; ++i)
    {
        u32 script = offset_to_anim_file + file->GetU16LE(offset_to_anim_file + 0x68 + i * 0x04);
        u32 end = script;

        u8 opcode = file->GetU8(script);
        if (opcode == 0x00) // skip if script starts with 0x00
        {
            continue;
        }

        dump->Log("\nfunction action_script_" + IntToString(i) + "()\n");

        for (; script <= end;)
        {
            //dump->Log(HexToString(script, 4, '0') + " (end " + HexToString(end, 4, '0') + "): ");
            u8 opcode = file->GetU8(script);

            dump->Log("    ");

            if (opcode < 0x8E)
            {
                dump->Log("play_animation(" + IntToString(opcode) + ");\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xA9)
            {
                dump->Log("animation_reset(); -- A9 this increment pointer by 2 and execute animation on second pointer. This called if we back from other action using EE.\n");
                end = (script + 2 > end) ? script + 2 : end;
                script += 1;
            }
            else if (opcode == 0xAA)
            {
                dump->Log("unpause_camera(); -- AA\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xAD)
            {
                dump->Log("set_effect(\"machinegun_fire\", " +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    ", " +
                    HexToString(file->GetU16LE(script + 2), 4, '0') +
                    ", " +
                    HexToString(file->GetU8(script + 4), 2, '0') +
                    ", " +
                    HexToString(file->GetU8(script + 5), 2, '0') +
                    "); -- AD\n"
                );
                AdvanceScript(6, script, end);
            }
            else if (opcode == 0xB6)
            {
                dump->Log("pause_camera_finish_animation(" + IntToString(file->GetU8(script + 1)) + "); -- B6\n");
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xB9)
            {
                dump->Log("set_camera(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    "); -- B9\n"
                );
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xBE)
            {
                dump->Log("execute_hurt(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    "); -- BE\n"
                );
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xC1)
            {
                dump->Log("jump(); -- C1\n");
                script += 1;
            }
            else if (opcode == 0xC2)
            {
                dump->Log("execute_damage(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    "); -- C2\n"
                );
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xC5)
            {
                dump->Log("set_unit_fade_wait(); -- C9\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xC6)
            {
                dump->Log("set_unit_fade_time(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    "); -- C6\n"
                );
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xC9)
            {
                dump->Log("jump_label(); -- C9\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xCA)
            {
                dump->Log("jump_if_not_loaded(); -- CA\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xD1)
            {
                dump->Log("move_to_target(\"linear_movement\", " +
                    HexToString(file->GetU16LE(script + 1), 4, '0') +
                    ", " +
                    HexToString(file->GetU16LE(script + 3), 4, '0') +
                    ", " +
                    HexToString(file->GetU8(script + 5), 2, '0') +
                    "); -- D1\n"
                );
                AdvanceScript(6, script, end);
            }
            else if (opcode == 0xD8)
            {
                dump->Log("play_sound_for_attacker(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    ", " +
                    HexToString(file->GetU16LE(script + 2), 4, '0') +
                    "); -- D8\n"
                );
                AdvanceScript(4, script, end);
            }
            else if (opcode == 0xE5)
            {
                dump->Log("return_direction(); -- E5\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xE8)
            {
                dump->Log("load_additional_effect(); -- E8\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xEA)
            {
                dump->Log("show_action_name(); -- EA\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xEC)
            {
                dump->Log("execute_additional_effect(); -- EC\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xEE)
            {
                dump->Log("return_to_idle(); -- EE\n");
                script += 1;
            }
            else if (opcode == 0xF0)
            {
                dump->Log("set_effect(\"foot_dust\"); -- F0\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xF3)
            {
                dump->Log("wait(); -- F3\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xF4)
            {
                dump->Log("set_wait(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    "); -- F4\n"
                );
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xF6)
            {
                dump->Log("play_die_if_dead(); -- F6\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xF7)
            {
                dump->Log("execute_attack(" +
                    HexToString(file->GetU8(script + 1), 2, '0') +
                    "); -- F7\n"
                );
                AdvanceScript(2, script, end);
            }
            else if (opcode == 0xFA)
            {
                dump->Log("return_position(); -- FA\n");
                AdvanceScript(1, script, end);
            }
            else if (opcode == 0xFC)
            {
                dump->Log("set_direction(); -- FC\n");
                AdvanceScript(1, script, end);
            }
            else
            {
                dump->Log("[ACTION_OPCODE " + HexToString(opcode, 2, '0') + "]\n");
                script += 1;
            }
        }

        dump->Log("end;\n");
    }
}
