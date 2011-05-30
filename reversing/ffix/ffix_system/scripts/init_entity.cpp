// battle load
// black screen
a0=00000000 a1=00000000 a2=00000014 a3=00000010 ra=8004A364 // first run script

a0=00000004 a1=00000000 a2=000000AC a3=00000010 ra=8004A49C
a0=00000009 a1=00000000 a2=000000AC a3=00000010 ra=8004A49C
a0=0000000A a1=00000000 a2=000000AC a3=00000010 ra=8004A49C
a0=0000000B a1=00000000 a2=000000AC a3=00000010 ra=8004A49C

a0=00000001 a1=00000080 a2=000000AC a3=00000010 ra=80039DBC
a0=00000002 a1=00000081 a2=000000AC a3=00000010 ra=80039DBC
a0=00000003 a1=00000082 a2=000000AC a3=00000010 ra=80039DBC


////////////////////////////////
// func367d0

entity_scripts_settings = w[8007adf8];

entity_id = A0;
S0 = A1; // memory id
S1 = A2;
yielded_scripts_memory = A3;
if (S0 == 0)
{
    S0 = entity_id;
}



A0 = S0;
func4b040; // get pointer to already allocated memory
if (V0 != 0)
{
    A0 = V0;
    func36978; // move this script call at the end of script list or insert it to end
}



S1 = ceil(S1 / 4); // 14/4=4
S2 = ceil(bu[entity_scripts_settings + entity_id * 8 + 4] / 4); // some requested memory
A0 = S1 + S2 + yielded_scripts_memory; // memory amount (in bytes * 4) (4+0+10=14)
func36650; // insert new memory in memory list
allocated_memory = V0;



// clear allocated memory
A1 = allocated_memory;
while (allocated_memory < allocated_memory + S1 * 4 + S2 * 4)
{
    [A1] = w(0);
    A1 = A1 + 4;
}



// insert script into script list
A1 = w[8007aecc];
V1 = w[A1 + 16e0];
[A1 + 16e0] = w(w[V1 + 0]); // set new last element

A2 = w[A1 + 16dc];
if (A2 != 0)
{
    [A2 + 0] = w(V1); // set link to new element in list
}
else
{
    [A1 + 16d8] = w(V1); // set first element
}
[A1 + 16dc] = w(V1); // set current element

[V1 + 0] = w(0); // this is last element so link to next element == 0
[V1 + 4] = w(allocated_memory); // set link to allocated memory



// initialize memory
[allocated_memory + 5] = b(0);
[allocated_memory + 6] = b(entity_id);
[allocated_memory + 7] = b(S0);
[allocated_memory + 8] = b(S1);
[allocated_memory + 9] = b(S1 + S2);
[allocated_memory + c] = b(yielded_scripts_memory);
[allocated_memory + e] = b(0);
[allocated_memory + 10] = b(ff);



offset_to_data = entity_scripts_settings + hu[entity_scripts_settings + entity_id * 8 + 0];
offset_to_data = offset_to_data + 2;

number_of_scripts = bu[offset_to_data + 1];
if (number_of_scripts != 0)
{
    A1 = 0;
    loop368f8:	; 800368F8
        if (hu[offset_to_data + A1 * 4 + 0] == 0)
        {
            break;
        }

        A1 = A1 + 1;
        V0 = A1 < number_of_scripts;
    8003690C	bne    v0, zero, loop368f8 [$800368f8]

    if (A1 < number_of_scripts)
    {
        offset_to_data = offset_to_data + hu[offset_to_data + A1 * 4 + 2];
    }
    else
    {
        offset_to_data = 0;
    }
}
else
{
    offset_to_data = 0;
}

[allocated_memory + 0] = w(offset_to_data);

return allocated_memory;
////////////////////////////////



////////////////////////////////
// func36650
A1 = w[8007aecc];
A3 = w[A1 + 15d0];
A2 = 0;
if (A3 != 0)
{
    // insert as first
    if (w[A3 + 0] >= A1 + 50 + A0 * 4)
    {
        A2 = w[A1 + 15d4];
        [A1 + 15d0] = w(A2);
        [A1 + 15d4] = w(w[A2 + 8]);
        [A2 + 0] = w(A1 + 50);
        [A2 + 4] = w(A1 + 50 + A0 * 4);
        [A2 + 8] = w(A3);
    }
    else
    {
        A1 = w[A3 + 8];
        if (A1 != 0)
        {
            loop366c4:	; 800366C4
                if (w[A1 + 0] >= w[A3 + 4] + A0 * 4)
                {
                    break;
                }

                A3 = A1;
                A1 = w[A3 + 8];
            800366E8	bne    a1, zero, loop366c4 [$800366c4]

            // insert in middle
            if (A1 != 0)
            {
                V1 = w[8007aecc];
                A2 = w[V1 + 15d4];
                [V1 + 15d4] = w(w[A2 + 8]);
                [A2 + 8] = w(w[A3 + 8]);
                [A3 + 8] = w(A2);
                [A2 + 0] = w(w[A3 + 4]);
                [A2 + 4] = w(w[A3 + 4] + A0 * 4);
            }
            // insert as last
            else
            {
                V1 = w[A3 + 4];
                A1 = w[8007aecc];
                if (A1 + 1450 >= V1 + A0 * 4)
                {
                    A2 = w[A1 + 15d4];
                    [A1 + 15d4] = w(w[A2 + 8]);
                    [A3 + 8] = w(A2);
                    [A2 + 0] = w(w[A3 + 4]);
                    [A2 + 4] = w(w[A3 + 4] + A0 * 4);
                    [A2 + 8] = w(0);
                }
            }
        }
        // insert as last
        else
        {
            V1 = w[A3 + 4];
            A1 = w[8007aecc];
            if (A1 + 1450 >= V1 + A0 * 4)
            {
                A2 = w[A1 + 15d4];
                [A1 + 15d4] = w(w[A2 + 8]);
                [A3 + 8] = w(A2);
                [A2 + 0] = w(w[A3 + 4]);
                [A2 + 4] = w(w[A3 + 4] + A0 * 4);
                [A2 + 8] = w(0);
            }
        }
    }
}
// if no script running
// insert as first
else
{
    if (A0 < 501)
    {
        A2 = w[A1 + 15d4];
        [A1 + 15d0] = w(A2); // set first element in list
        [A1 + 15d4] = w(w[A2 + 8]); // set last element in list

        [A2 + 0] = w(A1 + 50);
        [A2 + 4] = w(A1 + 50 + A0 * 4);
        [A2 + 8] = w(0); // link to next element
    }
}

if (A2 != 0)
{
    return w[A2 + 0];
}

return 0;
////////////////////////////////



////////////////////////////////
// func36978
// A0 - allocated memory
// if we cant find allocated memory in existing scripts - return 0.
// else - return pointer to next script in list
// move given script to end of all lists.
script_struct = w[8007aecc];
T0 = 0;
A1 = 0;
A2 = w[script_struct + 16d8];

if (A2 != 0)
{
    loop36994:	; 80036994
        if (w[A2 + 4] == A0)
        {
            break;
        }

        A1 = A2;
        A2 = w[A2 + 0];
    800369B0	bne    a2, zero, loop36994 [$80036994]

    if (A2 != 0)
    {
        T0 = w[A2 + 0];
        // remove link to that script from previous element or from beginning of list
        if (A1 != 0)
        {
            [A1 + 0] = w(T0);
        }
        else
        {
            [script_struct + 16d8] = w(T0);
        }

        // remove link to that element from current script
        if (w[script_struct + 16dc] == A2)
        {
            [script_struct + 16dc] = w(A1);
        }

        // insert it in the end of list
        [A2 + 0] = w(w[script_struct + 16e0]);
        [script_struct + 16e0] = w(A2);

        A3 = 0;
        A1 = w[script_struct + 15d0];
        if (A1 != 0)
        {
            loop36a24:	; 80036A24
                if (w[A1 + 0] == A0)
                {
                    break;
                }

                A3 = A1;
                A1 = w[A1 + 8];
            80036A40	bne    a1, zero, loop36a24 [$80036a24]
        }

        // remove link to that memory from previous element or from beginning of list
        if (A3 != 0)
        {
            [A3 + 8] = w(w[A1 + 8]);
        }
        else
        {
            [script_struct + 15d0] = w(w[A1 + 8]);
        }

        // insert it in the end of list
        [A1 + 8] = w(w[script_struct + 15d4]);
        [script_struct + 15d4] = w(A1);

        V0 = w[A2 + 4];
        if (bu[script_struct + 16ed] == bu[V0 + 7])
        {
            [script_struct + 16ed] = b(0);
        }
    }
}

return T0;
////////////////////////////////