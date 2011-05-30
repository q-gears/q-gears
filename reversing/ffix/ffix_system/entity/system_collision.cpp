////////////////////////////////
// system_check_entity_collisions
// A0 - entity data
// A1 = 0 - move update
// A1 = 2 - idle update
// A1 = 4 - talk update
// A2 - pointer for squared distance between entity collisions

entity_scripts_settings = w[8007adf8];
scripting_system        = w[8007aecc];

entity1_data = A0;

flags = A1;
pointer_for_squared_distance = A2;

[SP + 10] = w(w[entity1_data + 14]);
[SP + 14] = w(w[entity1_data + 18]);
[SP + 18] = w(w[entity1_data + 1c]);

stored_collision_square = 0;
stored_entity2_data = 0;

if (flags & 4)
{
    entity1_collision = bu[entity1_data + 3d] * 4; // talk radius
}
else
{
    entity1_collision = bu[entity1_data + 3c] * 4; // solid radius
}



S6 = w[scripting_system + 16d8];
if (S6 != 0)
{
    L386b0:	; 800386B0
        entity2_data = w[S6 + 4]; // pointer to allocated memory
        entity2_flags = bu[entity1_data + f];

        if (flags & 4)
        {
            A1 = 1;
        }
        else if ((bu[entity2_data + 7] == bu[scripting_system + 16ed]) && (entity2_flags & 2))
        {
            A1 = 1;
        }
        else if ((bu[entity2_data + 7] != bu[scripting_system + 16ed]) && (entity2_flags & 4))
        {
            A1 = 1;
        }
        else
        {
            A1 = 0;
        }

        if (flags & 4)
        {
            V0 = entity2_flags & 8;
        }
        else if (bu[entity1_data + 7] == bu[scripting_system + 16ed])
        {
            V0 = entity2_flags & 2;
        }
        else
        {
            V0 = entity2_flags & 4;
        }

        if (A1 != 0 && V0 != 0)
        {
            80038854	j      L3893c
        }

        if (entity2_data == entity1_data) // skip same entity
        {
            80038854	j      L3893c
        }

        if (flags & 6) // talk and ??? check
        {
            scriptable_entity_id = bu[entity2_data + 6];

            if (flags & 4)
            {
                T0 = 3;
            }
            else
            {
                T0 = 2;
            }

            V1 = entity_scripts_settings + hu[entity_scripts_settings + scriptable_entity_id * 8 + 0];
            number_of_scripts = hu[V1 + 0] >> 8;

            A2 = V1 + 2;
            if (number_of_scripts == 0)
            {
                V1 = 0
            }
            else
            {
                loop38790:	; 80038790
                    if (hu[A2 + 0] == T0)
                    {
                        break;
                    }

                    A2 = A2 + 4;
                    number_of_scripts = number_of_scripts - 1;
                800387A4	bne    number_of_scripts, zero, loop38790 [$80038790]

                if (number_of_scripts != 0)
                {
                    V1 = V1 + hu[A2] + 4;
                }
                else
                {
                    V1 = 0;
                }
            }

            if (V1 == 0)
            {
                80038854	j      L3893c
            }
        }

        if (bu[entity2_data + 5] != 4)
        {
            80038854	j      L3893c
        }

        if ((w[entity2_data + 18] - w[SP + 14] + 18f) >= 31f) // skip if we have difference in height greater than 18f
        {
            80038854	j      L3893c
        }

        distance_x = w[entity2_data + 14] - w[SP + 10];
        if (|distance_x| >= 800) // if we stands too far on X axis then skip
        {
            80038854	j      L3893c
        }

        distance_y = w[entity2_data + 1c] - w[SP + 18];
        if (|distance_y| >= 800) // if we stands too far on Z axis then skip
        {
            80038854	j      L3893c
        }

        if (flags & 4)
        {
            entity2_collision = bu[entity2_data + 3d] * 4; // talk radius
        }
        else
        {
            entity2_collision = bu[entity2_data + 3c] * 4; // solid radius
        }

        if (bu[entity2_data + 2d] != 0) // in case of long collisions
        {
            A0 = entity2_data;
            A1 = entity1_data;
            A2 = h[entity2_data + 22];
            system_get_how_much_we_need_rotate_to_face_entity;

            A0 = V0;
            system_get_cos_by_rotation;

            A0 = ((V0 * V0) >> 4) * bu[entity2_data + 2d] + 1000000;
            system_fully_calulated_square_root;

            entity2_collision = (entity2_collision * V0) >> c;
        }

        collision = entity2_collision + entity1_collision;

        if (flags & 6)
        {
            collision = collision + 3c + bu[entity2_data + 5c];
        }

        A0 = distance_x;
        A1 = distance_y;
        A2 = collision;
        func52dec; // get squared distance between collisions

        collision_square = V0;
        if (flags & 4)
        {
            A0 = entity1_data;
            A1 = entity2_data;
            A2 = h[entity1_data + 22];
            system_get_how_much_we_need_rotate_to_face_entity;
            V0 = |V0|;

            collision_square = collision_square + V0 - 280;

            if (V0 >= 280) // if facing totation greater than 280 than skip
            {
                80038854	j      L3893c
            }
        }

        if (collision_square < 0)
        {
            stored_collision_square = collision_square;
            stored_entity2_data     = entity2_data;
        }

        L3893c:	; 8003893C
        S6 = w[S6];
    80038944	bne    s6, zero, L386b0 [$800386b0]
}



if (pointer_for_squared_distance != 0)
{
    [pointer_for_squared_distance] = w(stored_collision_square);
}
return stored_entity2_data;
////////////////////////////////
