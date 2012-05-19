////////////////////////////////////////////////////////
// handle_animation_state
field_file = w[8009c6dc];
offset_to_model = w[8009c544];
V1 = w[8009c6e0];
manual_model = h[V1 + 2a];
pc = bu[V1 + 32];


number_of_entity = bu[field_file + 2];

if( number_of_entity > 0 )
{
    T2 = 0;
    Lbbbf0:	; 800BBBF0
        model = bu[8007eb98 + T2];
        if( model != ff )
        {
            if( model != manual_model || pc != 0 )
            {
                switch( bu[800756e8 + model] )
                {
                    case 0:
                    {
                        animation_id = bu[offset_to_model + model * 84 + 5e];
                        default_animation = bu[8008325c + model];
                        if( animation_id != default_animation )
                        {
                            [offset_to_model + model * 84 + 5e] = b(default_animation);
                            default_animation_speed = hu[80082248 + model * 2];
                            [offset_to_model + model * 84 + 60] = h(default_animation_speed);
                            [offset_to_model + model * 84 + 62] = h(0);

                            V1 = w[8008357c];
                            A1 = bu[V1 + model * 8 + 4];
                            V1 = w[8004a62c];
                            V1 = w[V1 + 4];
                            A1 = hu[V1 + A1 * 24 + 1A];
                            A0 = w[V1 + A1 * 24 + 1C];
                            number_of_frames = hu[A0 + A1 + default_animation * 10];
                            [offset_to_model + model * 84 + 64] = h(number_of_frames - 1);
                        }
                        else
                        {
                            V1 = w[8008357c];
                            A1 = bu[V1 + model * 8 + 4];
                            V1 = w[8004a62c];
                            V1 = w[V1 + 4];
                            A0 = hu[V1 + model * 24 + 1a];
                            V1 = w[V1 + model * 24 + 1c];
                            animation_id = bu[offset_to_model + model * 84 + 5e];
                            number_of_frames = hu[A0 + V1 + animation_id * 10];
                            [offset_to_model + model * 84 + 64] = h(number_of_frames - 1);

                            current_frame_value = hu[offset_to_model + model * 84 + 62];
                            number_of_frames = h[offset_to_model + model * 84 + 64];

                            if (current_frame_value / 10 >= number_of_frames)
                            {
                                [offset_to_model + model * 84 + 62] = h(0);
                            }
                        }
                    }
                    break;

                    case 1:
                    {
                        current_frame_value = hu[offset_to_model + model * 84 + 62];
                        number_of_frames = h[offset_to_model + model * 84 + 64];

                        if (current_frame_value / 10 >= number_of_frames)
                        {
                            [offset_to_model + model * 84 + 62] = h(0);
                        }
                    }
                    break;

                    case 2:
                    {
                        current_frame_value = hu[offset_to_model + model * 84 + 62];
                        number_of_frames = h[offset_to_model + model * 84 + 64];

                        if (current_frame_value / 10 >= number_of_frames)
                        {
                            [800756e8 + model] = b(4);
                            [offset_to_model + model * 84 + 62] = h(number_of_frames * 10);
                        }
                    }
                    break;

                    case 3:
                    case 4:
                    {
                        number_of_frames = hu[offset_to_model + model * 84 + 64];
                        [offset_to_model + model * 84 + 62] = h(number_of_frames * 10);
                    }
                    break;

                    case 5:
                    {
                        current_frame_value = hu[offset_to_model + model * 84 + 62];
                        number_of_frames = h[offset_to_model + model * 84 + 64];

                        if( current_frame_value / 10 >= number_of_frames )
                        {
                            [800756e8 + model] = b(0);
                        }
                    }
                    break;

                    case 6:
                    {
                        V0 = hu[offset_to_model + model * 84 + 62];
                        V0 = V0 / 10;
                        V1 = h[offset_to_model + model * 84 + 64];

                        if (V0 >= V1)
                        {
                            [800756e8 + model] = b(3);
                        }
                    }
                    break;
                }
            }
        }

        T2 = T2 + 1;
        V0 = T2 < number_of_entity;
    800BBF60	bne    v0, zero, Lbbbf0 [$800bbbf0]
}
////////////////////////////////////////////////////
