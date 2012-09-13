////////////////////////////////
// field_init_background_packets
tile_block_data = A0;
packets = A1;
end_of_packets = A2;

tileset_file = w[800c9da4 + 10];
S7 = bu[800ca108] + df;
[tile_block_data + 30] = w(packets);

xy_data = w(tileset_file + w[tile_block_data + 28]);
[SP + 14] = w(tileset_file + w[tile_block_data + 2c]);

// set global tile block position
[tile_block_data + 18] = h(hu[tile_block_data + c] + hu[tileset_file + 30]);
[tile_block_data + 1a] = h(hu[tile_block_data + e] + hu[tileset_file + 32]);

[tile_block_data + 24] = w(w[tile_block_data + 24] & fffffeff & ffff01ff);




S1 = w[SP + 14];
frame_buffer = 0;
number_of_tiles = hu[tile_block_data + 26];

loopbd1dc:	; 800BD1DC
    if( number_of_tiles != 0 )
    {
        tile_id = 0;
        loopbd1f0:	; 800BD1F0
            [packets + b] = b(03);
            [packets + c] = b(80); // R
            [packets + d] = b(80); // G
            [packets + e] = b(80); // B
            [packets + f] = b(7c); // 16x16 sprite

            [packets + 10] = h(hu[tile_block_data + 18] + (w[xy_data + tile_id * 4] >> 16)); // X
            [packets + 12] = h(hu[tile_block_data + 1a] + ((w[xy_data + tile_id * 4] >> c) & 3ff)); // Y
            [packets + 14] = b(bu[S1 + tile_id * 8 + 4]); // V
            [packets + 15] = b(bu[S1 + tile_id * 8 + 3]); // U

            if( ( w[S1 + tile_id * 8 + 4] >> 1c ) & 1 )
            {
                V0 = bu[packets + f] | 2;
            }
            else
            {
                V0 = bu[packets + f] & fd;
            }
            [packets + f] = b(V0);

            A1 = w[S1 + tile_id * 8 + 0];
            A0 = A1 >> 5;
            A0 = A0 & 3f0;
            A1 = A1 & 1ff;
            [packets + 16] = h((A1 << 6) | ((A0 >> 4) & 3f)); // clut

            A3 = w[S1 + tile_id * 8 + 0];

            if( ( (A3 >> 14) & 3 ) == 0 )
            {
                A0 = 0;
            }
            else
            {
                A0 = 1;
            }

            A1 = (A3 >> 16) & 0003;
            A2 = (A3 >> a) & 03c0;
            A3 = (A3 >> 7) & 0100;
            V0 = ((A0 & 0003) << 7) | ((A1 & 0003) << 5) | ((A3 & 0100) >> 4) | ((A2 & 03ff) >> 6) | ((A3 & 0200) << 2)

            A2 = V0;
            A0 = packets;
            A1 = packets + 8;
            [packets + 3] = b(1);
            [packets + 4] = w((A2 & 9ff) | e1000600);
            800BD300	jal    func62b4c [$80062b4c]

            V1 = w[S1 + tile_id * 8 + 0] & 000001ff;

            if( S7 < V1 )
            {
                S7 = V1;
            }

            packets = packets + 18;

            tile_id = tile_id + 1;
            V0 = tile_id < number_of_tiles;
        800BD334	bne    v0, zero, loopbd1f0 [$800bd1f0]

    }



    frame_buffer = frame_buffer + 1;
    V0 = frame_buffer < 2;
800BD354	bne    v0, zero, loopbd1dc [$800bd1dc]



[end_of_packets] = w(packets);
[800ca108] = b(S7 + 21);



return 1;
////////////////////////////////
