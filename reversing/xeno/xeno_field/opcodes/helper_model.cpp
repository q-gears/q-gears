////////////////////////////////////////////////////////
// set_position_by_x_z
x = A0;
z = A1;
offset_to_current_entity   = w[800af54c];
curently_initing_entity_id = w[800af1f0];
entity_data                = w[800aefe4];
S3 = w[entity_data + curently_initing_entity_id * 5c + 4];

V1 = h[800af028];
V1 = V1 - 1;
if (V1 <= 0)
{
    walkmesh_id = 0;
    S2 = SP + 18;
    S1 = SP + 58;

    loop9db74:	; 8009DB74
        A0 = x;
        A1 = z;
        A2 = walkmesh_id;
        A3 = S1;
        [SP + 10] = w(S2);
        func7a7d8;

        [offset_to_current_entity + 8 + walkmesh_id * 2] = h(V0);

        walkmesh_id = walkmesh_id + 1;
        S1 = S1 + 8;
        S2 = S2 + 10;
        V0 = walkmesh_id < h[800af028] - 1;
    8009DBB8	bne    v0, zero, loop9db74 [$8009db74]
}

A0 = offset_to_current_entity;
func7ff7c;
[offset_to_current_entity + 14] = w(V0);

V1 = h[offset_to_current_entity + 10];
[offset_to_current_entity + 50] = w(w[SP + 18 + V1 * 10 + 0]);
[offset_to_current_entity + 54] = w(w[SP + 18 + V1 * 10 + 4]);
[offset_to_current_entity + 58] = w(w[SP + 18 + V1 * 10 + 8]);

[entity_data + curently_initing_entity_id * 5c + 20] = w(x);
[entity_data + curently_initing_entity_id * 5c + 40] = w(x);
[entity_data + curently_initing_entity_id * 5c + 24] = w(h[SP + 58 + V1 * 8 + 2]);
[entity_data + curently_initing_entity_id * 5c + 44] = w(h[SP + 58 + V1 * 8 + 2]);
[entity_data + curently_initing_entity_id * 5c + 28] = w(z);
[entity_data + curently_initing_entity_id * 5c + 48] = w(z);

[S3 + 84] = h(hu[SP + 58 + V1 * 8 + 2]);

[offset_to_current_entity + 20] = w(x << 10);
[offset_to_current_entity + 24] = w(h[SP + 58 + V1 * 8 + 2] << 10);
[offset_to_current_entity + 28] = w(z << 10);

[offset_to_current_entity + 72] = h(hu[SP + 58 + V1 * 8 + 2]);

[S3 + 0] = w(w[offset_to_current_entity + 20]);
[S3 + 4] = w(w[offset_to_current_entity + 24]);
[S3 + 8] = w(w[offset_to_current_entity + 28]);

[offset_to_current_entity + 40] = w(0);
[offset_to_current_entity + 44] = w(0);
[offset_to_current_entity + 48] = w(0);

[offset_to_current_entity + 30] = w(0);
[offset_to_current_entity + 34] = w(0);
[offset_to_current_entity + 38] = w(0);

[offset_to_current_entity + d0] = w(0);
[offset_to_current_entity + d4] = w(0);
[offset_to_current_entity + d8] = w(0);

[offset_to_current_entity + 60] = h(0);
[offset_to_current_entity + 62] = h(0);
[offset_to_current_entity + 64] = h(0);

[S3 + 0c] = w(0);
[S3 + 10] = w(0);
[S3 + 14] = w(0);

[offset_to_current_entity + ec] = w(0);
[offset_to_current_entity + f0] = w(0);

[offset_to_current_entity + 72] = h(h[offset_to_current_entity + 26]);

V1 = w[offset_to_current_entity + 0];
V1 = V1 & fffbffff
V1 = V1 | 00400000;
[offset_to_current_entity] = w(V1);
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// func7a7d8
// A0 - x
// A1 - z
// A2 - walkmesh id
S0 = 0;
S1 = A3;
T2 = w[SP + 10];

[SP + 60] = h(A0);
[SP + 62] = h(0);
[SP + 64] = h(A1);
V0 = w[800aeff8 + A2 * 4];
T1 = w[800af018 + A2 * 4];
A3 = w[800af008 + A2 * 4];
if (T1 > 0)
{
    A0 = A0 << 10;
    T0 = A0 + A1;
    A2 = V0;

    L7a838:	; 8007A838
        8007A838	lh     v0, $0000(a2)
        8007A83C	lh     v1, $0002(a2)
        8007A840	sll    v0, v0, $03
        8007A844	addu   v0, v0, a3
        8007A848	sll    v1, v1, $03
        8007A84C	addu   v1, v1, a3
        8007A850	lh     a1, $0000(v0)
        8007A854	lh     v0, $0004(v0)
        8007A858	lh     a0, $0000(v1)
        8007A85C	lh     v1, $0004(v1)
        8007A860	sll    a1, a1, $10
        8007A864	addu   a1, a1, v0
        8007A868	sll    a0, a0, $10
        8007A86C	lh     v0, $0004(a2)
        8007A870	addu   a0, a0, v1
        8007A874	sll    v0, v0, $03
        8007A878	addu   v0, v0, a3
        8007A87C	lh     v1, $0000(v0)
        8007A880	lh     v0, $0004(v0)
        8007A884	sll    v1, v1, $10
        8007A888	addu   v1, v1, v0

        8007A88C	mtc2   a1,l33
        8007A890	mtc2   t0,gbk
        8007A894	mtc2   a0,rbk
        8007A8A0	gte_func26zero,r11r12
        8007A8A4	addiu  v0, sp, $0068
        8007A8A8	swc2   t8, $0000(v0)
        V0 = w[SP + 68];
        if (V0 >= 0)
        {
            8007A8BC	mtc2   a0,l33
            8007A8C0	mtc2   t0,gbk
            8007A8C4	mtc2   v1,rbk
            8007A8D0	gte_func26zero,r11r12
            8007A8D4	addiu  v0, sp, $006c
            8007A8D8	swc2   t8, $0000(v0)
            V0 = w[SP + 6c];
            if (V0 >= 0)
            {
                8007A8EC	mtc2   v1,l33
                8007A8F0	mtc2   t0,gbk
                8007A8F4	mtc2   a1,rbk
                8007A900	gte_func26zero,r11r12
                8007A904	addiu  v0, sp, $0070
                8007A908	swc2   t8, $0000(v0)

                V0 = w[SP + 70];
                if (V0 >= 0)
                {
                    V0 = h[A2 + 0];
                    [SP + 48] = h(hu[A3 + V0 * 8 + 0]);
                    [SP + 4a] = h(hu[A3 + V0 * 8 + 2]);
                    [SP + 4c] = h(hu[A3 + V0 * 8 + 4]);

                    V0 = h[A2 + 2];
                    [SP + 50] = h(hu[A3 + V0 * 8 + 0]);
                    [SP + 52] = h(hu[A3 + V0 * 8 + 2]);
                    [SP + 54] = h(hu[A3 + V0 * 8 + 4]);

                    V0 = h[A2 + 4];
                    [SP + 58] = h(hu[A3 + V0 * 8 + 0]);
                    [SP + 5a] = h(hu[A3 + V0 * 8 + 2]);
                    [SP + 5c] = h(hu[A3 + V0 * 8 + 4]);

                    A0 = SP + 48;
                    A1 = SP + 50;
                    A2 = SP + 58;
                    A3 = SP + 60;
                    [SP + 10] = w(T2);
                    field_calculate_walkmesh_height; // calculate height

                    [S1 + 0] = h(hu[SP + 60]);
                    [S1 + 2] = h(hu[SP + 62]);
                    [S1 + 4] = h(hu[SP + 64]);
                    return S0;
                }
            }
        }

        S0 = S0 + 1;
        V0 = S0 < T1;
        A2 = A2 + e;
    8007AA50	bne    v0, zero, L7a838 [$8007a838]
}

[S1 + 0] = h(0);
[S1 + 2] = h(0);
[S1 + 4] = h(0);
[T2 + 0] = w(0);
[T2 + 4] = w(0);
[T2 + 8] = w(0);
return 0;
////////////////////////////////////////////////////////