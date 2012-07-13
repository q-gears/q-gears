////////////////////////////////
// func220e8
S1 = A0;
S2 = 0;

A0 = A0;
func21e5c;

S0 = V0;
if( S0 != 0 )
{
    if( ( hu[S0 + 0] & 0001 ) != 0 )
    {
        func22020;
    }

    A0 = S0;
    func21ae0;

    if( V0 != 0 )
    {
        S2 = 1;
    }
    else
    {
        A0 = S0;
        func21a8c;

        if( V0 != 0 )
        {
            S2 = 1;
        }
    }
}
else
{
    func21e20; // get element 0x28 indexed by +3[]

    if( V0 != 0 )
    {
        if( ( w[V0 + 4] NOR 0 ) != 0 )
        {
            if( bu[V0 + 6] == ( ( S1 >> 10 ) & ff ) )
            {
                if( ( w[V0 + 4] & ffff ) != ( S1 & ffff ) )
                {
                    A0 = V0;
                    func21c20;
                }
            }
        }
    }
}

return S2;
////////////////////////////////



////////////////////////////////
// func2177c
8002177C	beq    a0, zero, L217bc [$800217bc]
80021780	nop
80021784	sw     a1, $0000(a0)
80021788	sw     a2, $0004(a0)
8002178C	sw     a3, $0008(a0)
80021790	lw     v0, $0010(sp)
80021794	sw     a3, $0020(a0)
80021798	sw     v0, $000c(a0)
8002179C	lw     v0, $0014(sp)
800217A0	nop
800217A4	sw     v0, $0010(a0)
800217A8	lw     v0, $0018(sp)
800217AC	sw     a2, $0018(a0)
800217B0	sw     v0, $0014(a0)
800217B4	addiu  v0, zero, $0001
800217B8	sw     v0, $001c(a0)

L217bc:	; 800217BC
800217BC	jr     ra 
800217C0	addu   v0, a0, zero
////////////////////////////////



////////////////////////////////
// func21a8c
80021A8C	lhu    v1, $0000(a0)
80021A90	nop
80021A94	andi   v0, v1, $0082
80021A98	beq    v0, zero, L21ad4 [$80021ad4]
80021A9C	andi   v0, v1, $0001
80021AA0	bne    v0, zero, L21ad8 [$80021ad8]
80021AA4	addu   v0, zero, zero
80021AA8	lhu    v0, $0002(a0)
80021AAC	nop
80021AB0	bne    v0, zero, L21ad8 [$80021ad8]
80021AB4	addu   v0, zero, zero
80021AB8	andi   v0, v1, $0020
80021ABC	bne    v0, zero, L21ad8 [$80021ad8]
80021AC0	addu   v0, zero, zero
80021AC4	lw     v1, $0008(a0)
80021AC8	nop
80021ACC	bne    v1, zero, L21ad8 [$80021ad8]
80021AD0	addiu  v0, zero, $0001

L21ad4:	; 80021AD4
80021AD4	addu   v0, zero, zero

L21ad8:	; 80021AD8
80021AD8	jr     ra 
80021ADC	nop
////////////////////////////////



////////////////////////////////
// func21ae0
80021AE0	lhu    v1, $0000(a0)
80021AE4	nop
80021AE8	andi   v0, v1, $0082
80021AEC	beq    v0, zero, L21b28 [$80021b28]
80021AF0	andi   v0, v1, $0001
80021AF4	bne    v0, zero, L21b2c [$80021b2c]
80021AF8	addu   v0, zero, zero
80021AFC	andi   v0, v1, $0020
80021B00	beq    v0, zero, L21b2c [$80021b2c]
80021B04	addu   v0, zero, zero
80021B08	lh     v0, $0024(a0)
80021B0C	nop
80021B10	beq    v0, zero, L21b2c [$80021b2c]
80021B14	addu   v0, zero, zero
80021B18	lh     v1, $0026(a0)
80021B1C	nop
80021B20	bne    v1, zero, L21b2c [$80021b2c]
80021B24	addiu  v0, zero, $0001

L21b28:	; 80021B28
80021B28	addu   v0, zero, zero

L21b2c:	; 80021B2C
80021B2C	jr     ra 
80021B30	nop
////////////////////////////////



////////////////////////////////
// func22d3c
[SP + 10] = b(4);
V0 = 800231a0;
[SP + 28] = w(A0);
A0 = SP + 10;

80022D5C	sw     zero, $0014(sp)
80022D60	sw     zero, $0018(sp)
80022D64	sw     zero, $001c(sp)
80022D68	sw     v0, $0020(sp)
80022D6C	jal    func230b8 [$800230b8]
80022D70	sw     zero, $0024(sp)

return V0 & ff;
////////////////////////////////



////////////////////////////////
// func21c20
V1 = 0;

if( hu[A0 + 0] & 0001 )
{
    loop21c3c:	; 80021C3C
        A0 = 0;
        func22d3c;
        V0 = V0 & ff;
    80021C48	beq    v0, zero, loop21c3c [$80021c3c]

    V1 = 1;
}

return V1;
////////////////////////////////



////////////////////////////////
// func21e20
V0 = w[8006794c];
V0 = w[V0 + 1c];
A0 = w[V0 + 8c8];
return A0 + 4 + b[A0 + 3] * 28;
////////////////////////////////



////////////////////////////////
// func22020
loop22028:	; 80022028
    func21fb4;
80022030	bgtz   v0, loop22028 [$80022028]

func22050;
////////////////////////////////



////////////////////////////////
// func21fb4
func21e20;
S0 = V0;
if( S0 == 0 )
{
    return 0;
}

A0 = S0;
func219fc;

if( V0 == 0 )
{
    return -1;
}

A0 = hu[S0 + 0];
if( ( A0 & 0001 ) == 0 )
{
    return 0;
}

if( ( A0 & 0080 ) == 0 )
{
    return ( A0 & 0002 ) < 1;
}

return -1;
////////////////////////////////



////////////////////////////////
// func219fc
if( A0 == 0 )
{
    return 0;
}

V0 = w[A0 + 4];
V0 = V0 NOR 0;
V0 = 0 < V0;
////////////////////////////////



////////////////////////////////
// func22050
func21e20;

if( V0 != 0 )
{
    [V0 + 0] = h(hu[V0 + 0] & ff7e);
}
////////////////////////////////



////////////////////////////////
// func21e5c
V0 = w[8006794c];
V0 = w[V0 + 1c];
A3 = w[V0 + 8c8];
A1 = b[A3 + 2] - 1;
if( A1 >= 0 )
{
    loop21ea4:	; 80021EA4
        if( ( w[A3 + 4 + A1 * 28 + 4] & 00ffffff ) == ( A0 & 00ffffff ) )
        {
            return A3 + A1 * 28 + 4;
        }
        A1 = A1 - 1;
    80021EC4	bgez   a1, loop21ea4 [$80021ea4]
}

return 0;
////////////////////////////////



////////////////////////////////
// func1c7fc
// A0 - type of return

S2 = A0;
S4 = A1;
S5 = A2; // XXXXYYYY where XXXX - type of db file, YYYY - 

V0 = h[80073c40 + 2];
S0 = V0 - 1;

if (S0 >= 0)
{
    S1 = 80073c40 + S0 * 4;

    loop1c84c:	; 8001C84C
        A0 = w[S1 + 4];
        A1 = S2;
        A2 = S4;
        A3 = S5;
        func1c8b0;

        if (V0 != -1)
        {
            return V0;
        }

        S0 = S0 - 1;
        S1 = S1 - 4;
    8001C86C	bgez   s0, loop1c84c [$8001c84c]
}

if (V0 == -1 && (S2 & 1) == 0)
{
    return 0;
}

return -1;
////////////////////////////////



////////////////////////////////
// func1c8b0
// get info from db structure
// A1 - type of return
// 0 - return address of founded resource.
// 1 - number of files of that type resource.
// 2 - return address of file with index A2 & ffff in given resource.
// 3 - return unique identificator of file???
// 4 - return address of file with identificator A2 & ffff in given resource.
// 5 - return size of file with identificator A2 & ffff in given resource.
// 8 - 

address = A0;
return_type = A1;
V1 = A2;
file_index = V1 & ffff;
resource_type = (V1 >> 10) & ff;

A2 = A3;

if (address == 0)
{
    return 0;
}

file_pointer_start = address + 4;
number_of_files = bu[address + 1];

if (number_of_files != 0)
{
    // loop through all files in database
    T7 = 0;
    loop1c94c:	; 8001C94C
        T0 = w[file_pointer_start + 0]
        T4 = (T0 >> 18) & 7f; // type of part
        if (T4 == resource_type)
        {
            resource_address = file_pointer_start + T0 & 00ffffff; // address of part
            number_of_resource = bu[resource_address + 1]; // number of files of that type

            if (return_type == 0)
            {
                return resource_address;
            }
            if (return_type == 1)
            {
                return number_of_resource;
            }

            identifiers_address = resource_address + 4;
            pointers_address = identifiers_address + number_of_resource * 2;
            V0 = pointers_address & 3;
            if (V0 != 0) // align address to 4 bytes
            {
                V0 = V0 - 4;
                pointers_address = pointers_address - V0;
            }

            if (return_type == 2)
            {
                V0 = w[pointers_address + file_index * 4];
                return pointers_address + file_index * 4 + V0 & 00ffffff;
            }

            if (return_type == 3)
            {
                return (T4 << 10) | hu[identifiers_address + file_index * 2];
            }

            if (number_of_resource != 0)
            {
                T0 = 0;
                loop1c9b8:	; 8001C9B8
                    if (hu[identifiers_address] == file_index)
                    {
                        switch (return_type)
                        {
                            case 4:
                            {
                                return pointers_address + w[pointers_address] & 00ffffff;
                            }
                            break;

                            case 5:
                            {
                                return (w[pointers_address + 4] & 00ffffff) - w[pointers_address + 0] & 00ffffff + 4;
                            }
                            break;

                            case 9:
                            {
                                A0 = address
                                A1 = 3;
                                A2 = A2;
                                A3 = 0;
                                func1c8b0;
                                return V0;
                            }
                            break;

                            case 8:
                            {
                                A0 = address
                                A1 = 2;
                                A2 = A2;
                                A3 = 0;
                                func1c8b0;
                                return V0;
                            }
                            break;

                            case b:
                            {
                                A0 = address
                                A1 = 1;
                                A2 = A2;
                                A3 = 0;
                                func1c8b0;
                                return V0;
                            }
                            break;

                            default:
                            {
                                return -1;
                            }
                        }
                    }

                    identifiers_address = identifiers_address + 2;
                    T0 = T0 + 1;
                    V0 = T0 < number_of_resource;
                    pointers_address = pointers_address + 4;
                8001CA40	bne    v0, zero, loop1c9b8 [$8001c9b8]
            }
        }

        T7 = T7 + 1;
        file_pointer_start = file_pointer_start + 4;
        V0 = T7 < number_of_files;
    8001CA50	bne    v0, zero, loop1c94c [$8001c94c]
}

return -1;
////////////////////////////////



////////////////////////////////
// func1daa4
S6 = A0; // offset to previous file
S7 = A1; // offset to file
S4 = A2;
S2 = A3; // some address
S1 = 0;
if (S4 != 0 && S1 < S4)
{
    loop1daf8:	; 8001DAF8
        V0 = bu[80068234];
        A1 = S4 - S1;
        V1 = V0 + 1;
        [80068234] = b(V1);
        V1 = V0 * 8;
        S0 = 80073ce8 + V1;
        if (V0 >= 5)
        {
            [80068234] = b(0);
        }

        if (S2 != 0)
        {
            [S0 + 0] = h(hu[S2 + 0]);
            [S0 + 2] = h(hu[S2 + 2]);
            [S0 + 4] = h(hu[S2 + 4]);
            [S0 + 6] = h(hu[S2 + 6]);
        }
        else
        {
            A0 = w[8006794c];
            V0 = w[A0 + 1c];
            V1 = w[A0 + 10] + bu[V0 + 8] * 5c;
            [S0 + 0] = h(hu[V1 + 0]);
            [S0 + 2] = h(hu[V1 + 2]);
            [S0 + 4] = h(140);
            [S0 + 6] = h(da);
        }

        V1 = A1 / 2;
        A0 = V1 / h[S0 + 6];
        if (A0 == 0 && A1 != 0)
        {
            V0 = V1 << 10;
            A0 = 1;
            [S0 + 6] = h(V1);
            if (V0 == 0)
            {
                [S0 + 6] = h(V1 + A0);
            }
        }
        else if (h[S0 + 4] < A0)
        {
            A0 = V1;
        }

        [S0 + 4] = h(A0);

        A0 = S0;
        A1 = S7 + S1;
        func13350;

        loop1dc48:	; 8001DC48
            8001DC48	jal    func22b18 [$80022b18]
        8001DC50	bne    v0, zero, loop1dc48 [$8001dc48]

        A0 = S0;
        A1 = S6 + S1;
        func133b0;

        T0 = h[S0 + 4] + h[S0 + 6];
        S1 = S1 + T0 * 2;
        V0 = S1 < S4;
    8001DC80	bne    v0, zero, loop1daf8 [$8001daf8]
}

return S1;
////////////////////////////////



////////////////////////////////
// func13350
S0 = A0;
S1 = A1;
A0 = 8001018c;
A1 = S0;
func1310c;

A1 = S0;
A2 = 8;
A3 = S1;
V0 = w[80066654];
A0 = w[V0 + 20];
V0 = w[V0 + 8];
80013394	jalr   v0 ra
////////////////////////////////



////////////////////////////////
// func133b0
S0 = A0;
S1 = A1;
A0 = 80010198;
A1 = S0;
func1310c;


V0 = w[80066654];
A0 = w[V0 + 1c];
A1 = S0;
A2 = 8;
A3 = S1;
V0 = w[V0 + 8];
800133F4	jalr   v0 ra
////////////////////////////////