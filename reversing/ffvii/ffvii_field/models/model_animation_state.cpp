////////////////////////////////////////////////////////
// handle_animation_state
V0 = w[8009C6DC];
V0 = bu[V0 + 2];

800BBBE0	blez   v0, Lbbf68 [$800bbf68]
800BBBE4	addu   t2, zero, zero
T0 = 8007EB98;

Lbbbf0:	; 800BBBF0
    800BBBF0	lbu    a0, $0000(t0)
    800BBBF4	ori    v0, zero, $00ff
    800BBBF8	beq    a0, v0, Lbbf48 [$800bbf48]
    800BBBFC	nop
    800BBC00	lui    v1, $800a
    800BBC04	lw     v1, $c6e0(v1)
    800BBC08	nop
    800BBC0C	lh     v0, $002a(v1)
    800BBC10	nop
    800BBC14	bne    v0, a0, Lbbc2c [$800bbc2c]
    800BBC18	nop
    800BBC1C	lbu    v0, $0032(v1)
    800BBC20	nop
    800BBC24	beq    v0, zero, Lbbf48 [$800bbf48]
    800BBC28	nop

    Lbbc2c:	; 800BBC2C
    V1 = bu[800756e8 + A0];

    model           = bu[8007EB98];
    offset_to_model = w[8009C544];

    if (V1 < 7)
    {
        case 0:
        {
            animation_id = bu[offset_to_model + model * 84 + 5E];
            default_animation = bu[8008325C + model];
            if (animation_id != default_animation)
            {
                [offset_to_model + model * 84 + 5E] = b(default_animation);
                default_animation_speed = hu[80082248 + model * 2];
                [offset_to_model + model * 84 + 60] = h(default_animation_speed);
                [offset_to_model + model * 84 + 62] = h(0);

                V1 = w[8008357C];
                A1 = bu[V1 + model * 8 + 4];
                V1 = w[8004A62C];
                V1 = w[V1 + 4];
                A1 = hu[V1 + A1 * 24 + 1A];
                A0 = w[V1 + A1 * 24 + 1C];
                number_of_frames = hu[A0 + A1 + default_animation * 10];
                [offset_to_model + model * 84 + 64] = h(number_of_frames - 1);
            }
            else
            {
                V1 = w[8008357C];
                A1 = bu[V1 + model * 8 + 4];
                V1 = w[8004A62C];
                V1 = w[V1 + 4];
                A0 = hu[V1 + model * 24 + 1A];
                V1 = w[V1 + model * 24 + 1C];
                animation_id = bu[offset_to_model + model * 84 + 5E];
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
                [800756E8 + A0] = b(4);
                [offset_to_model + model * 84 + 62] = h(number_of_frames * 10);
            }
        }
        break;

        case 3 4:
        {
            number_of_frames = hu[offset_to_model + model * 84 + 64];
            [offset_to_model + model * 84 + 62] = h(number_of_frames * 10);
        }
        break;

        case 5:
        {
            current_frame_value = hu[offset_to_model + model * 84 + 62];
            number_of_frames = h[offset_to_model + model * 84 + 64];

            if (current_frame_value / 10 >= number_of_frames)
            {
                [800756E8 + A0] = b(0);
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
                [800756E8 + A0] = b(3);
            }
        }
        break;
    }

    Lbbf48:	; 800BBF48
    V0 = w[8009C6DC];
    V0 = bu[V0 + 2];
    T2 = T2 + 1;
    T0 = T0 + 1;
    V0 = T2 < V0;
800BBF60	bne    v0, zero, Lbbbf0 [$800bbbf0]

Lbbf68:	; 800BBF68
return;
////////////////////////////////////////////////////