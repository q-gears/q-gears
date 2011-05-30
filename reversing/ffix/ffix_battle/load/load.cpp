////////////////////////////////
// funca99ac
//a0=8010AEAC a1=00000150 a2=00000000 a3=00000007 ra=800A92EC // start of battle
// A1 - unique file identificator of file type 11.

S1 = A0;
S0 = 110000 | (A1 & ffff);

A0 = 4;
A1 = S0;
A2 = 0;
func1c7fc;
[S1 + 24] = w(V0); // get pointer to 11 file

A0 = 9;
A1 = S0;
A2 = 100000;
func1c7fc;
A0 = 4;
A1 = V0;
A2 = 0;
func1c7fc;
[S1 + 20] = w(V0); // get pointer to formation file

A0 = 9; // return unique file id
A1 = S0;
A2 = 50000;
func1c7fc;
A0 = 4; // return address
A1 = V0; // unique file id
A2 = 0;
func1c7fc;
[S1 + 10] = w(V0); // get pointer to script file

A0 = 9;
A1 = S0;
A2 = 60000;
func1c7fc;
A0 = 4;
A1 = V0;
A2 = 0;
func1c7fc;
[S1 + 14] = w(V0); // get pointer to text file

funcc94b8;

A0 = w[S1 + 10];
system_init_script_system;

func4bfb0;

return 0;
////////////////////////////////



////////////////////////////////
// funcc94b8
A1 = w[8006794c];
V0 = w[A1 + 1c];
S0 = w[V0 + 8e4];
A0 = w[S0 + 11c0];
V1 = w[A0 + 24]; // pointer to file 11
[S0 + 1338] = w(V1 + hu[V1 + 0]);
[S0 + 133c] = w(V1 + hu[V1 + 2]);

formation_data = w[A0 + 20];

// get offset to formation data to load
A0 = formation_data; // pointer to loaded formation data
funcc9600;
[S0 + 1330] = w(V0);

// store pointer to enemy data
A0 = bu[formation_data + 1]; // number of formation
[S0 + 1334] = w(formation_data + 8 + A0 * 38); // pointer to enemy data

A0 = w[S0 + 1330];
A0 = bu[A0 + 2]; // +2 in loaded formation data
if (A0 >= 3)
{
    // get random 0-2
    V1 = w[8007b720];
    if (V1 >= 8007b92d)
    {
        system_reset_random;
    }
    V0 = w[8007b720];
    A0 = bu[V0];
    [8007b720] = w(V0 + 1);
    V1 = A0 % 3;
}
else
{
    V1 = A0;
}

[S0 + 131c] = b(V1);

return formation_data;
////////////////////////////////



////////////////////////////////
// funcc9600
// function to get correct formation data offset
// calculates random from all formations and pick one or give offset to requested formation
S1 = A0; // offset to formation file

// get random 1-100
V1 = w[8007b720];
if (V1 >= 8007b92d)
{
    system_reset_random;
}
V0 = w[8007b720];
V1 = bu[V0];
[8007b720] = w(V0 + 1);
random = V1 * 64 / 100; // random 0-100

formation_id = 0;

formation_offset = S1 + 8;
V1 = bu[formation_offset]; // read data from first formation
if (random >= V1)
{
    loopc967c:	; 800C967C
        formation_offset = S1 + 8 + formation_id * 38;
        V1 = V1 + bu[formation_offset];

        formation_id = formation_id + 1;
        V0 = random < V1;
    800C9694	beq    v0, zero, loopc967c [$800c967c]
}

V0 = w[8006794c];
V0 = w[V0 + 1c];
V1 = b[V0 + 848];
if (V1 != -1)
{
    formation_id = V1;
    number_of_formations = bu[S1 + 1];
    if (formation_id >= number_of_formations)
    {
        formation_id = 0;
    }

    formation_offset = S1 + 8 + formation_id * 38;
}

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
[V0 + 1340] = b(formation_id);

return formation_offset;
////////////////////////////////