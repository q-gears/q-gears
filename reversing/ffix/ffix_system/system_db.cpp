////////////////////////////////
// func1c7fc
// A0 - type of return

S2 = A0;
S4 = A1;
S5 = A2;

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