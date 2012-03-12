////////////////////////////////
// 800cf5bc
// movement callback

data_id   = h[801590d0];
stage     = h[801620ac + data_id * 20 + 2];
unit_id   = h[801620ac + data_id * 20 + 8];
target_id = h[801620ac + data_id * 20 + a];

if( stage == 0 )
{
    [801620ac + data_id * 20 + 2] = h(1);

    if (unit_id >= 4 && bu[801031f0] == 0)
    {
        V1 = h[801518e4 + target_id * b9c + 16a] * h[801518e4 + target_id * b9c + 6];
        V0 = h[801518e4 + unit_id * b9c   + 16a] * h[801518e4 + unit_id * b9c   + 6];

        [801620ac + data_id * 20 + 6] = h(((V1 >> c) - (V0 >> c)) / h[801620ac + data_id * 20 + 4]);
    }
    else
    {
        [801620ac + data_id * 20 + 6] = h(0);
    }
}

if( bu[801620ac + data_id * 20 + 18] == 0 )
{
    [80166f58] = b(0); // set frames to wait to 0

    if (h[801620ac + data_id * 20 + 4] == 0)
    {
        [801620ac + data_id * 20 + 0] = h(-1);
        return;
    }

    [801518e4 + unit_id * b9c + 168] = h(hu[801518e4 + unit_id * b9c + 168] + hu[801620ac + data_id * 20 + c]);
    [801518e4 + unit_id * b9c + 16a] = h(hu[801518e4 + unit_id * b9c + 16a] + hu[801620ac + data_id * 20 + 6]);
    [801518e4 + unit_id * b9c + 16c] = h(hu[801518e4 + unit_id * b9c + 16c] + hu[801620ac + data_id * 20 + e]);

    [801620ac + data_id * 20 + 4] = h(hu[801620ac + data_id * 20 + 4] - 1); // decrement steps number
}
else
{
    [801620ac + data_id * 20 + 18] = b(bu[801620ac + data_id * 20 + 18] - 1);
}
////////////////////////////////



////////////////////////////////
// funccfcb0
data_id   = h[801590d0];
unit_id   = h[801620ac + data_id * 20 + 8];
target_id = h[801620ac + data_id * 20 + a]

V0 = h[801620ac + data_id * 20 + 4];
if( V0 == 0 )
{
    [801620ac + data_id * 20 + 0] = h(-1);
}
else
{
    A1 = w[801620ac + data_id * 20 + 10];
    [80151a4c + unit_id * b9c] = h(hu[80151a4c + unit_id * b9c] + hu[801620ac + data_id * 20 + c]);

    [1f80000c] = w(unit_id);
    [1f800008] = w(target_id);
    [1f800010] = w(A1);

    [80151a50 + unit_id * b9c] = h(hu[80151a50 + unit_id * b9c] + hu[801620ac + data_id * 20 + e]);
    V1 = bu[801620ac + data_id * 20 + 18];
    [801620ac + data_id * 20 + 18] = b(V1 + 1);
    [80151a4e + unit_id * b9c] = h(hu[80151a4e + unit_id * b9c] + hu[800eeb28 + A1 * 10 + V1 * 2]);
    [801620ac + data_id * 20 + 4] = h(hu[801620ac + data_id * 20 + 4] - 1);
}
////////////////////////////////
