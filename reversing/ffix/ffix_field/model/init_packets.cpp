////////////////////////////////
// funcb6584
model_data = A0;

[model_data + 18] = w(A1); // first data from 0x12 file

packet_data = w[model_data + 10];
model_file = w[model_data + 8];



number_of_parts = bu[model_file + 3];
if( number_of_parts != 0 )
{
    part_id = 0;
    Lb65bc:	; 800B65BC
        part_data = w[model_file + 10] + part_id * 28;
        colour_data = w[part_data + 24];



        // init parts struct
        T9 = w[model_data + 44];
        [T9 + part_id * c + 0] = h(0);
        [T9 + part_id * c + 4] = w(packet_data);
        [T9 + part_id * c + 8] = w(0);



        buffer_id = 0;
        Lb65e4:	; 800B65E4
            mesh_data = w[part_data + 1c];



            // monochrome textured quads
            number_of_monochrome_textured_quads = hu[part_data + 2];
            if( number_of_monochrome_textured_quads != 0 )
            {
                quad_id = 0;
                Lb65fc:	; 800B65FC
                    [packet_data + 3] = b(09);
                    [packet_data + 4] = b(bu[mesh_data + 10]); // r
                    [packet_data + 5] = b(bu[mesh_data + 11]); // g
                    [packet_data + 6] = b(bu[mesh_data + 12]); // b
                    [packet_data + 7] = b(2c);

                    // set uv
                    uv_data = w[part_data + 20];
                    vertex1 = hu[mesh_data + 8];
                    [packet_data + c] = h(hu[uv_data + vertex1 * 2]);
                    vertex2 = hu[mesh_data + a];
                    [packet_data + 14] = h(hu[uv_data + vertex2 * 2]);
                    vertex3 = hu[mesh_data + c];
                    [packet_data + 1c] = h(hu[uv_data + vertex3 * 2]);
                    vertex4 = hu[mesh_data + e];
                    [packet_data + 24] = h(hu[uv_data + vertex4 * 2]);

                    // set clut and blending
                    image_id = bu[mesh_data + 13];
                    V0 = w[model_data + 18];
                    [packet_data + e] = h(hu[V0 + image_id * 4 + 2]); // CLUT
                    [packet_data + 16] = h(hu[V0 + image_id * 4 + 0] & ffdf); // reset blending by default

                    if( bu[mesh_data + 15] & 1 )
                    {
                        [packet_data + 16] = h(hu[packet_data + 16] | (bu[mesh_data + 15] & e0));
                        [packet_data + 7] = b(bu[packet_data + 7] | 02); // semi transparency on
                    }

                    A3 = h[A2 + image_id * 4 + 0];
                    T0 = h[A2 + image_id * 4 + 2];

                    [packet_data + c] = b(bu[packet_data + c] + A3);
                    [packet_data + d] = b(bu[packet_data + d] + T0);
                    [packet_data + 14] = b(bu[packet_data + 14] + A3);
                    [packet_data + 15] = b(bu[packet_data + 15] + T0);
                    [packet_data + 1d] = b(bu[packet_data + 1d] + A3);
                    [packet_data + 1c] = b(bu[packet_data + 1c] + T0);
                    [packet_data + 24] = b(bu[packet_data + 24] + A3);
                    [packet_data + 25] = b(bu[packet_data + 25] + T0);



                    mesh_data = mesh_data + 18;
                    packet_data = packet_data + 28;
                    quad_id = quad_id + 1;
                    V0 = quad_id < number_of_monochrome_textured_quads;
                800B6804	bne    v0, zero, Lb65fc [$800b65fc]
            }



            // monochrome textured triangles
            number_of_monochrome_textured_triangles = hu[part_data + 4];
            if( number_of_monochrome_textured_triangles != 0 )
            {
                triangle_id = 0;
                Lb6824:	; 800B6824
                    [packet_data + 3] = b(7);
                    [packet_data + 4] = b(bu[mesh_data + 8]); // r
                    [packet_data + 5] = b(bu[mesh_data + 9]); // g
                    [packet_data + 6] = b(bu[mesh_data + a]); // b
                    [packet_data + 7] = b(24);

                    // set uv
                    uv_data = w[part_data + 20];
                    vertex1 = hu[mesh_data + c];
                    [packet_data + c] = h(hu[uv_data + vertex1 * 2]);
                    vertex2 = hu[mesh_data + e];
                    [packet_data + 14] = h(hu[uv_data + vertex2 * 2]);
                    vertex3 = hu[mesh_data + 10];
                    [packet_data + 1c] = b(bu[uv_data + vertex3 * 2]);

                    // set clut and blending
                    image_id = bu[mesh_data + 6];
                    V1 = w[model_data + 18];
                    [packet_data + e] = h(hu[V1 + image_id * 4 + 2]); // CLUT
                    [packet_data + 16] = h(hu[V1 + image_id * 4 + 0] & ffdf); // reset blending by default

                    if( bu[mesh_data + 12] & 01 )
                    {
                        [packet_data + 16] = h(hu[packet_data + 16] | (bu[mesh_data + 12] & e0));
                        [packet_data + 7] = b(bu[packet_data + 7] | 02);
                    }

                    A3 = h[A2 + image_id * 4 + 0];
                    T0 = h[A2 + image_id * 4 + 2];

                    [packet_data + c] = b(bu[packet_data + c] + A3);
                    [packet_data + d] = b(bu[packet_data + d] + T0);
                    [packet_data + 14] = b(bu[packet_data + 14] + A3);
                    [packet_data + 15] = b(bu[packet_data + 15] + T0);
                    [packet_data + 1c] = b(bu[packet_data + 1c] + A3);
                    [packet_data + 1d] = b(bu[packet_data + 1d] + T0);



                    mesh_data = mesh_data + 14;
                    packet_data = packet_data + 20;
                    triangle_id = triangle_id + 1;
                    V0 = triangle_id < number_of_monochrome_textured_triangles;
                800B69DC	bne    v0, zero, Lb6824 [$800b6824]
            }



            // shaded textured quads
            number_of_shaded_textured_quads = hu[part_data + 6];
            if( number_of_shaded_textured_quads != 0 )
            {
                quad_id = 0;
                Lb69fc:	; 800B69FC
                    [packet_data + 3] = b(0c);
                    [packet_data + 7] = b(3c);

                    vertex1 = hu[mesh_data + 10];
                    [packet_data + 4] = b(bu[colour_data + vertex1 * 4 + 0]);
                    [packet_data + 5] = b(bu[colour_data + vertex1 * 4 + 1]);
                    [packet_data + 6] = b(bu[colour_data + vertex1 * 4 + 2]);
                    vertex2 = hu[mesh_data + 12];
                    [packet_data + 10] = b(bu[colour_data + vertex2 * 4 + 0]);
                    [packet_data + 11] = b(bu[colour_data + vertex2 * 4 + 1]);
                    [packet_data + 12] = b(bu[colour_data + vertex2 * 4 + 2]);
                    vertex3 = hu[mesh_data + 14];
                    [packet_data + 1c] = b(bu[colour_data + vertex3 * 4 + 0]);
                    [packet_data + 1d] = b(bu[colour_data + vertex3 * 4 + 1]);
                    [packet_data + 1e] = b(bu[colour_data + vertex3 * 4 + 2]);
                    vertex4 = hu[mesh_data + 16];
                    [packet_data + 28] = b(bu[colour_data + vertex4 * 4 + 0]);
                    [packet_data + 29] = b(bu[colour_data + vertex4 * 4 + 1]);
                    [packet_data + 2a] = b(bu[colour_data + vertex4 * 4 + 2]);

                    // set uv
                    uv_data = w[part_data + 20];
                    vertex1 = hu[mesh_data + 8];
                    [packet_data + c] = h(hu[uv_data + vertex1 * 2]);
                    vertex2 = hu[mesh_data + a];
                    [packet_data + 18] = h(hu[uv_data + vertex2 * 2]);
                    vertex3 = hu[mesh_data + c];
                    [packet_data + 24] = h(hu[uv_data + vertex3 * 2]);
                    vertex4 = hu[mesh_data + e];
                    [packet_data + 30] = h(hu[uv_data + vertex4 * 2]);

                    image_id = bu[mesh_data + 1d];
                    V1 = w[model_data + 18];
                    [packet_data + e] = h(hu[V1 + image_id * 4 + 2]);
                    [packet_data + 1a] = h(hu[V1 + image_id * 4 + 0] & ffdf);

                    if( bu[mesh_data + 1c] & 01 )
                    {
                        [packet_data + 1a] = h(hu[packet_data + 1a] | (bu[mesh_data + 1c] & e0));
                        [packet_data + 7] = b(bu[packet_data + 7] | 02);
                    }

                    A3 = h[A2 + image_id * 4 + 0];
                    T0 = h[A2 + image_id * 4 + 2];

                    [packet_data + c] = b(bu[packet_data + c] + A3);
                    [packet_data + d] = b(bu[packet_data + d] + T0);
                    [packet_data + 18] = b(bu[packet_data + 18] + A3);
                    [packet_data + 19] = b(bu[packet_data + 19] + T0);
                    [packet_data + 24] = b(bu[packet_data + 24] + A3);
                    [packet_data + 25] = b(bu[packet_data + 25] + T0);
                    [packet_data + 30] = b(bu[packet_data + 30] + A3);
                    [packet_data + 31] = b(bu[packet_data + 31] + T0);



                    mesh_data = mesh_data + 20;
                    packet_data = packet_data + 34;
                    quad_id = quad_id + 1;
                    V0 = quad_id < number_of_shaded_textured_quads;
                800B6CB0	bne    v0, zero, Lb69fc [$800b69fc]
            }



            // shaded textured triangles
            number_of_shaded_textured_triangles = hu[part_data + 8];
            if( number_of_shaded_textured_triangles != 0 )
            {
                triangle_id = 0;
                Lb6cd0:	; 800B6CD0
                    [packet_data + 3] = b(09);
                    [packet_data + 7] = b(34);

                    vertex1 = hu[mesh_data + 10];
                    [packet_data + 4] = b(bu[colour_data + vertex1 * 4 + 0]);
                    [packet_data + 5] = b(bu[colour_data + vertex1 * 4 + 1]);
                    [packet_data + 6] = b(bu[colour_data + vertex1 * 4 + 2]);
                    vertex2 = hu[mesh_data + 12];
                    [packet_data + 10] = b(bu[colour_data + vertex2 * 4 + 0]);
                    [packet_data + 11] = b(bu[colour_data + vertex2 * 4 + 1]);
                    [packet_data + 12] = b(bu[colour_data + vertex2 * 4 + 2]);
                    vertex3 = hu[mesh_data + 14];
                    [packet_data + 1c] = b(bu[colour_data + vertex3 * 4 + 0]);
                    [packet_data + 1d] = b(bu[colour_data + vertex3 * 4 + 1]);
                    [packet_data + 1e] = b(bu[colour_data + vertex3 * 4 + 2]);

                    // set uv
                    uv_data = w[part_data + 20];
                    vertex1 = hu[mesh_data + 6];
                    [packet_data + c] = h(hu[uv_data + vertex1 * 2]);
                    vertex2 = hu[mesh_data + 8];
                    [packet_data + 18] = h(hu[uv_data + vertex2 * 2]);
                    vertex3 = hu[mesh_data + a];
                    [packet_data + 24] = h(hu[uv_data + vertex3 * 2]);

                    image_id = bu[mesh_data + 16];
                    V1 = w[model_data + 18];
                    [packet_data + e] = h(hu[V1 + image_id * 4 + 2]);
                    [packet_data + 1a] = h(hu[V1 + image_id * 4 + 0] & ffdf);

                    if( bu[mesh_data + f] & 01 )
                    {
                        [packet_data + 1a] = h(hu[packet_data + 1a] | (bu[mesh_data + f] & e0));
                        [packet_data + 7] = b(bu[packet_data + 7] | 02);
                    }

                    A3 = h[A2 + image_id * 4 + 0];
                    T0 = h[A2 + image_id * 4 + 2];

                    [packet_data + c] = b(bu[packet_data + c] + A3);
                    [packet_data + d] = b(bu[packet_data + d] + T0);
                    [packet_data + 18] = b(bu[packet_data + 18] + A3);
                    [packet_data + 19] = b(bu[packet_data + 19] + T0);
                    [packet_data + 24] = b(bu[packet_data + 24] + A3);
                    [packet_data + 25] = b(bu[packet_data + 25] + T0);



                    mesh_data = mesh_data + 18;
                    packet_data = packet_data + 28;
                    triangle_id = triangle_id + 1;
                    V0 = triangle_id < number_of_shaded_textured_triangles;
                800B6F00	bne    v0, zero, Lb6cd0 [$800b6cd0]
            }



            // gradated quads
            number_of_gradated_quads = hu[part_data + a];
            if( number_of_gradated_quads != 0 )
            {
                quad_id = 0;
                loopb6f20:	; 800B6F20
                    [packet_data + 3] = b(08);
                    [packet_data + 7] = b(38);

                    V0 = hu[mesh_data + 8];
                    [packet_data + 4] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + 5] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + 6] = b(bu[colour_data + V0 * 4 + 2]);
                    V0 = hu[mesh_data + a];
                    [packet_data + c] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + d] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + e] = b(bu[colour_data + V0 * 4 + 2]);
                    V0 = hu[mesh_data + c];
                    [packet_data + 14] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + 15] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + 16] = b(bu[colour_data + V0 * 4 + 2]);
                    V0 = hu[mesh_data + e];
                    [packet_data + 1c] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + 1d] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + 1e] = b(bu[colour_data + V0 * 4 + 2]);



                    mesh_data = mesh_data + 18;
                    packet_data = packet_data + 24;
                    quad_id = quad_id + 1;
                    V0 = quad_id < number_of_gradated_quads;
                800B7004	bne    v0, zero, loopb6f20 [$800b6f20]
            }



            // gradated triangles
            number_of_gradated_triangles = hu[part_data + c];
            if( number_of_gradated_triangles != 0 )
            {
                triangle_id = 0;
                loopb702c:	; 800B702C
                    [packet_data + 3] = b(06);
                    [packet_data + 7] = b(30);

                    V0 = hu[mesh_data + 8];
                    [packet_data + 4] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + 5] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + 6] = b(bu[colour_data + V0 * 4 + 2]);
                    V0 = hu[mesh_data + a];
                    [packet_data + c] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + d] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + e] = b(bu[colour_data + V0 * 4 + 2]);
                    V0 = hu[mesh_data + c];
                    [packet_data + 14] = b(bu[colour_data + V0 * 4 + 0]);
                    [packet_data + 15] = b(bu[colour_data + V0 * 4 + 1]);
                    [packet_data + 16] = b(bu[colour_data + V0 * 4 + 2]);



                    mesh_data = mesh_data + 14;
                    packet_data = packet_data + 1c;
                    triangle_id = triangle_id + 1;
                    V0 = triangle_id < number_of_gradated_triangles;
                800B70DC	bne    v0, zero, loopb702c [$800b702c]
            }



            // monochrome quads
            number_of_monochrome_quads = hu[part_data + e];
            if( number_of_monochrome_quads != 0 )
            {
                quad_id = 0;
                loopb7104:	; 800B7104
                    [packet_data + 3] = b(05);
                    [packet_data + 4] = b(bu[mesh_data + 8]);
                    [packet_data + 5] = b(bu[mesh_data + 9]);
                    [packet_data + 6] = b(bu[mesh_data + a]);
                    [packet_data + 7] = b(28);



                    mesh_data = mesh_data + 10;
                    packet_data = packet_data + 18;
                    quad_id = quad_id + 1;
                    V0 = quad_id < number_of_monochrome_quads;
                800B7140	bne    v0, zero, loopb7104 [$800b7104]
            }



            // monochrome triangles
            number_of_monochrome_triangles = hu[part_data + 10];
            if( number_of_monochrome_triangles != 0 )
            {
                triangle_id = 0;
                loopb7168:	; 800B7168
                    [packet_data + 3] = b(04);
                    [packet_data + 4] = b(bu[mesh_data + 8]);
                    [packet_data + 5] = b(bu[mesh_data + 9]);
                    [packet_data + 6] = b(bu[mesh_data + a]);
                    [packet_data + 7] = b(20);



                    mesh_data = mesh_data + c;
                    packet_data = packet_data + 14;
                    triangle_id = triangle_id + 1;
                    V0 = triangle_id < number_of_monochrome_triangles;
                800B71A0	bne    v0, zero, loopb7168 [$800b7168]
            }



            buffer_id = buffer_id + 1;
            V0 = buffer_id < 2;
        800B71B0	bne    v0, zero, Lb65e4 [$800b65e4]

        part_id = part_id + 1;
        V0 = part_id < number_of_parts;
    800B71C4	bne    v0, zero, Lb65bc [$800b65bc]
}
////////////////////////////////
