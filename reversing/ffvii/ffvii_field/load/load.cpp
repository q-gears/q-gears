////////////////////////////////
// funca2d5c

// 1st part of mim - palette settings
[800e4d94] = w(w[A1 + 0]);
[800e4d98] = h(hu[A1 + 4]);
[800e4d9a] = h(hu[A1 + 6]);
[800e4d9c] = h(hu[A1 + 8]);
[800e4d9e] = h(hu[A1 + a]);
[800e4d90] = w(A1 + c);

// 2nd part 1st image
A1 = A1 + ((w[A1 + 0] >> 2) << 2);
[800e4da4] = w(A1 + c);
[800e4da8] = w(w[A1 + 0]);
[800e4dac] = h(hu[A1 + 4]);
[800e4dae] = h(hu[A1 + 6]);
[800e4db0] = h(hu[A1 + 8] * 2);
[800e4db2] = h(hu[A1 + a]);

// 3rd part 2nd image
A1 = A1 + ((w[A1 + 0] >> 2) << 2);
[800e4dd4] = w(A1 + c);
[800e4dd8] = w(w[A1 + 0]);
[800e4ddc] = h(hu[A1 + 4]);
[800e4dde] = h(hu[A1 + 6]);
[800e4de0] = h(hu[A1 + 8] << 1);
[800e4de2] = h(hu[A1 + a]);

[SP + 20] = h(0);
[SP + 22] = h(1e0);
[SP + 24] = h(100);
[SP + 26] = h(10);

A0 = 0;
func43dd8;

A0 = SP + 20;
A1 = w[800e4d90];
func44000; // load to vram

A0 = 0;
func43dd8;

A0 = w[800e4da4]; // address
A1 = 1; // 8 bit clut
A2 = 0;
A3 = h[800e4dac];
A4 = h[800e4dae];
A5 = hu[800e4db0];
A6 = hu[800e4db2];
func436c0; // load texture to vram and return texpage settings

[800e4db4] = h(V0);

if (w[800e4dd8] != 0)
{
    A0 = 0;
    func43dd8;

    A0 = w[800e4dd4];
    A1 = 1;
    A2 = 0;
    A3 = h[800e4ddc];
    A4 = h[800e4dde];
    A5 = hu[800e4de0];
    A6 = hu[800e4de2];
    func436c0; // load texture to vram and return texpage settings
    [800e4de4] = h(V0);
}

A0 = 0;
func43dd8;
////////////////////////////////



////////////////////////////////
// funca1368
if (h[800965e8] == 0) // if background start load earlier
{
    // load field mim
    V1 = h[8009a05c]; // field id to load
    A1 = w[800da5b8 + V1 * 18 + 8];
    A0 = w[800da5b8 + V1 * 18 + c]; 
    A2 = 80128000;
    A3 = 0;
    load_lzs_file;

    loopa13b8:	; 800A13B8
        800A13B8	jal    func34b44 [$80034b44]
    800A13C0	bne    v0, zero, loopa13b8 [$800a13b8]
}
else
{
    La13d0:	; 800A13D0
        800A13D0	jal    func34b44 [$80034b44]
    800A13D8	bne    v0, zero, La13d0 [$800a13d0]

    A0 = 801b0000;
    A1 = 80128000;
    func34bb0; // copy loaded mim
}

// load field dat
V1 = h[8009a05c]; // field id to load
A1 = w[800da5b8 + V1 * 18 + 0];
A0 = w[800da5b8 + V1 * 18 + 4]; 
A2 = 80114fe4;
A3 = 0;
load_lzs_file;


loopa1428:	; 800A1428
    800A1428	jal    func34b44 [$80034b44]
800A1430	bne    v0, zero, loopa1428 [$800a1428]

V0 = w[8009ad28];
[800716c4] = w(w[V0]); // offset to sector 5 triggers
// we read address of encounter section from extracted dat.
V1 = w[8009c55c];
[80071a54] = w(w[V1]);
// we read address of section 7 from extracted dat. Don't know what it is.
V1 = w[80070784];
[8007e770] = w(w[V1] + 0);
[8008357c] = w(w[V1] + 4);
////////////////////////////////