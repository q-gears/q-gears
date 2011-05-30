////////////////////////////////
// 0x29_EntityTurnOff
A0 = 1;
get_entity_id_from_opcode;
entity_id = V0;

if (entity_id != ff)
{
    V0 = w[800aefe4];
    A1 = w[V0 + entity_id * 5c + 4c];

    [A1 + 0] = w(w[A1 + 0] | 00000001);
    [A1 + 4] = w(w[A1 + 4] | 00100000);
    [V1 + 58] = h(hu[V1 + 58] | 0020);

    // say to close dialog
    A0 = SP + 10;
    func9c2a8;
    if (V0 == 0)
    {
        V1 = w[SP + 10];
        [800c1b6c + V1 * 498 + 414] = h(0);
    }
}

A0 = w[800af54c];
[A0 + cc] = h([A0 + cc] + 2);
////////////////////////////////
