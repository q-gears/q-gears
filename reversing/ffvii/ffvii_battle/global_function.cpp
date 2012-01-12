////////////////////////////////
// funcb6d6c
A0 = bu[801590e0];
V0 = A0 * c;
V1 = b[80163798 + V0];
if( V1 != -1 )
{
    S4 = 1f800004;
    S3 = 1f800008;
    S1 = -1;
    S5 = 80163798;
    S2 = 1;

    Lb6ddc:	; 800B6DDC
        V1 = b[80163798 + A0 * c + 1];
        switch( V1 )
        {
            case 5:
            {
                index = bu[801590e0];
                unit_id = b[80163798 + index * c + 0];

                [801518e4 + unit_id * b9c + 3e] = b(bu[801518e4 + unit_id * b9c + 3e] | 20);

                [80151200 + unit_id * 74] = w(w[801636b8 + unit_id * 10 + 8]); // unit status

                V1 = w[80151200 + unit_id * 74];
                if( V1 != 00000010 && V1 != 00000020 ) // sadness and fury
                {
                    [801518e4 + unit_id * b9c + 162] = h(hu[801518e4 + unit_id * b9c + 18]); // store rotation
                }

                funcb7fdc;
                [801590e0] = b(bu[801590e0] + 1);
            }
            break;



            case 0:
            {
                A0 = 800c494c;
                800B6F8C	jal    funcbc04c [$800bc04c]

                funcb7fdc;
                [801590e0] = b(bu[801590e0] + 1);
            }
            break;



            case 2: // A46F0B80
            {
                index = bu[801590e0];
                A0 = h[80163798 + index * c + 6]; // string index in buffer + 0x100
                A1 = bu[80163798 + index * c + 5]; // string argument
                A2 = bu[80163798 + index * c + 3]; // 0
                A3 = bu[80163798 + index * c + 2]; // 0
                funcc5c18;

                funcb7fdc;
                [801590e0] = b(bu[801590e0] + 1);
            }
            break;



            case 4: // 14700B80
            {
                if( bu[800f7de4] != 0 )
                {
                    index = bu[801590e0];
                    unit_id = b[80163798 + index * c + 0];

                    [800f7de4] = b(0);

                    [1f800004] = w(b[80163798 + index * c + 5] << 8); // animation action id
                    [1f800008] = w(h[801518ea + unit_id * b9c]);

                    A0 = 800c5694;
                    funcbbeac;
                    data_id = V0;

                    if( w[1f800004] < w[1f800008] )
                    {
                        V0 = w[1f800008] - w[1f800004];
                    }
                    else
                    {
                        V0 = w[1f800004] - w[1f800008];
                    }

                    [8015190a + unit_id * b9c] = b(0);

                    [80162978 + data_id * 20 + 2] = h(V0 / h[80163798 + index * c + 6]);
                    [80162978 + data_id * 20 + 4] = h(hu[80163798 + index * c + 6]);
                    [80162978 + data_id * 20 + 6] = h(unit_id);

                    [80163798 + index * c + 8] = h(-1);
                }

                funcb7fdc;
                if( bu[800f7de4] != 0 )
                {
                    [801590e0] = b(bu[801590e0] + 1);
                }
            }
            break;



            case 3: // 3C720B80
            {
                if( bu[800f7de4] != 0 )
                {
                    [800f7de4] = b(0);

                    800B7258	jal    funcbb684 [$800bb684]
                    800B725C	nop
                    800B7260	lui    v1, $8016
                    800B7264	lbu    v1, $90e0(v1)
                    800B7268	nop
                    800B726C	sll    v0, v1, $01
                    800B7270	addu   v0, v0, v1
                    800B7274	sll    v0, v0, $02
                    800B7278	lui    at, $8016
                    800B727C	addiu  at, at, $37a2
                    800B7280	addu   at, at, v0
                    800B7284	lh     v1, $0000(at)
                    800B7288	nop
                    800B728C	sll    v0, v1, $01
                    800B7290	addu   v0, v0, v1
                    800B7294	sll    v0, v0, $02
                    800B7298	lui    at, $8010
                    800B729C	addiu  at, at, $a9d1 (=-$562f)
                    800B72A0	addu   at, at, v0
                    800B72A4	lbu    v0, $0000(at)
                    800B72A8	nop
                    800B72AC	lui    at, $8016
                    800B72B0	sb     v0, $90cc(at)
                    800B72B4	lui    a0, $8016
                    800B72B8	lbu    a0, $90cc(a0)
                    800B72BC	nop
                    800B72C0	sll    v1, a0, $01
                    800B72C4	addu   v1, v1, a0
                    800B72C8	sll    v0, v1, $05
                    800B72CC	subu   v0, v0, v1
                    800B72D0	sll    v0, v0, $03
                    800B72D4	subu   v0, v0, a0
                    800B72D8	sll    v0, v0, $02
                    [801518e4 + V0 + 26] = b(S2);
                    800B72EC	jal    funcb7764 [$800b7764]
                    800B72F0	nop
                    800B72F4	lui    v1, $8016
                    800B72F8	lbu    v1, $90e0(v1)
                    800B72FC	nop
                    800B7300	sll    v0, v1, $01
                    800B7304	addu   v0, v0, v1
                    800B7308	sll    v0, v0, $02
                    800B730C	lui    at, $8016
                    800B7310	addiu  at, at, $37a2
                    800B7314	addu   at, at, v0
                    800B7318	lh     v1, $0000(at)
                    [800f9774] = b(0);
                    800B7324	sll    v0, v1, $01
                    800B7328	addu   v0, v0, v1
                    800B732C	sll    v0, v0, $02
                    800B7330	lui    at, $8010
                    800B7334	addiu  at, at, $a9d0 (=-$5630)
                    800B7338	addu   at, at, v0
                    800B733C	lb     v0, $0000(at)
                    800B7340	nop
                    800B7344	beq    v0, s1, Lb73c4 [$800b73c4]
                    800B7348	addiu  s0, zero, $ffff (=-$1)

                    loopb734c:	; 800B734C
                    800B734C	jal    funcb79f0 [$800b79f0]
                    800B7350	nop
                    800B7354	lui    v1, $8016
                    800B7358	lbu    v1, $90e0(v1)
                    800B735C	nop
                    800B7360	sll    v0, v1, $01
                    800B7364	addu   v0, v0, v1
                    800B7368	sll    v0, v0, $02
                    800B736C	lui    at, $8016
                    800B7370	addiu  at, at, $37a2
                    800B7374	addu   at, at, v0
                    800B7378	lhu    v1, $0000(at)
                    800B737C	addu   a0, v0, s5
                    