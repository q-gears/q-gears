KAWAI_0 face texture
+ 00 []       eye1 id for this face.
+ 01 []       eye2 id for this face.
+ 02 []       mouth id for this face.
+ 03 []       model id (will be overwriten).
set new face textures to vram for this model.



KAWAI_1 transparency
+ 00 []       transparency 1-on/0-off
set ABE and TGE to 0 or 1 in packet drafts to turn on or off model transparency



KAWAI_2 ambient
+ 00 [][]     R.
+ 02 [][]     G.
+ 04 [][]     B.
+ 06 []       flags.
              0x01 - if not 1 then we will apply this only for polygons in which packet draft first 3 bytes not 0 (???).
set ambient color for this model.



KAWAI_3 lighting
+ 00 []       R.
+ 01 []       G.
+ 02 []       B.
+ 03 []       colour matrix.
+ 04 []       colour matrix.
+ 05 []       colour matrix.
+ 06 []       colour matrix.
+ 07 []       colour matrix.
+ 08 []       colour matrix.
+ 09 []       colour matrix.
+ 0a []       colour matrix.
+ 0b []       colour matrix.
+ 0c [][]     light matrix.
+ 0e [][]     light matrix.
+ 10 [][]     light matrix.
+ 12 [][]     light matrix.
+ 14 [][]     light matrix.
+ 16 [][]     light matrix.
+ 18 [][]     light matrix.
+ 1a [][]     light matrix.
+ 1c [][]     light matrix.
set lighting for this model. Uses data like in BSX file.



KAWAI_4
+ 00 [][]     R.
+ 02 [][]     G.
+ 04 [][]     B.
+ 06 [][]     height.
+ 08 []       flags.
              0x01 - use per vertex height check, otherwise use average height for all vertexes on polygon.
              0x02 - if not set then we will apply this only for polygons in which packet draft first 3 bytes not 0 (???).
              0x04 - flag that switch axises. One of them - Z. Other - Y.
add color to vertexes lower than given height.



KAWAI_5
+ 00 [][]     world light position X.
+ 02 [][]     world light position Y.
+ 04 [][]     world light position Z.
+ 06 [][]     light radius.
+ 08 [][]     light R/intensivity.
+ 0a [][]     light G.
+ 0c [][]     light B.
+ 0e [][]     ambient R.
+ 10 [][]     ambient G.
+ 12 [][]     ambient B.
calculate light source for object.



KAWAI_6 (dynamic for KAWAI_2)
+ 00 []       state. If 0 - init. If 1 then we miss all arguments, just execute.
+ 02 [][]     R start.
+ 04 [][]     G start.
+ 06 [][]     B start.
+ 08 [][]     R end.
+ 0a [][]     G end.
+ 0c [][]     B end.
+ 0e [][]     R addition.
+ 10 [][]     G adition.
+ 12 [][]     B addition.
+ 14 []       flags.
              0x01 - if not 1 then we will apply this only for polygons in which packet draft first 3 bytes not 0 (???).
set ambient color for this model. Ambient change over time.



KAWAI_7  (dynamic for KAWAI_3)
+ 00 []       state. If 0 - init. If 1 then we miss all arguments, just execute.
+ 02 []       R.
+ 03 []       G.
+ 04 []       B.
+ 05 []       colour matrix.
+ 06 []       colour matrix.
+ 07 []       colour matrix.
+ 08 []       colour matrix.
+ 09 []       colour matrix.
+ 0a []       colour matrix.
+ 0b []       colour matrix.
+ 0c []       colour matrix.
+ 0d []       colour matrix.
+ 0e [][]     light matrix.
+ 10 [][]     light matrix.
+ 12 [][]     light matrix.
+ 14 [][]     light matrix.
+ 16 [][]     light matrix.
+ 18 [][]     light matrix.
+ 1a [][]     light matrix.
+ 1c [][]     light matrix.
+ 1e [][]     light matrix.
set lighting for this model. Uses data like in BSX file. Doesn't do anything specific (mostly like KAWAI_3).



KAWAI_8 (dynamic for KAWAI_4)
+ 00 []       state. If 0 - init. If 1 then we miss all arguments, just execute.
+ 02 [][]     R start.
+ 04 [][]     G start.
+ 06 [][]     B start.
+ 08 [][]     height start.
+ 0a [][]     R end.
+ 0c [][]     G end.
+ 0e [][]     B end.
+ 10 [][]     height end.
+ 12 [][]     R addition.
+ 14 [][]     G adition.
+ 16 [][]     B addition.
+ 18 [][]     height addition.
+ 1a []       flags.
              0x01 - use per vertex height check, otherwise use average height for all vertexes on polygon.
              0x02 - if not set then we will apply this only for polygons in which packet draft first 3 bytes not 0 (???).
              0x04 - flag that switch axises. One of them - Z. Other - Y.
add color to vertexes lower than given height. height and rgb change over time.



KAWAI_9 (dynamic for KAWAI_4)
+ 00 []       state. If 0 - init. If 1 then we miss all arguments, just execute.
+ 02 [][]     height.
+ 04 [][]     R.
+ 06 [][]     G.
+ 08 [][]     B.
+ 0a []       flags.
              0x01 - use per vertex height check, otherwise use average height for all vertexes on polygon.
              0x02 - if not set then we will apply this only for polygons in which packet draft first 3 bytes not 0 (???).
              0x04 - flag that switch axises. One of them - Z. Other - Y.
add color to vertexes lower than given height. And add effect of splashing water if we below height.



KAWAI_A
+00 []       number of 2bytes records.
    +00 []       id of part.
    +01 []       lighting calculation on/off.
enable or disable lighting calculation for given parts of model.



KAWAI_B



KAWAI_C



KAWAI_D (dynamic for KAWAI_5)
+00 []       state. If 0 - init. If 1 then we execute. If 2 then we stop.



////////////////////////////////////////////////////////
// 0x28 KAWAI
// S0 - more opcodes to read
A0 = bu[800722c4];
V1 = hu[800831fc + A0 * 2];
V0 = w[8009c6dc];
script = V0 + V1;
size = bu[script + 1];

unit_id = bu[8007eb98 + A0];
if (unit_id != ff)
{
    V0 = w[8008357c] + unit_id * 8; // 7 block in dat
    V1 = w[8004a62c];
    V0 = w[V1 + 4] + bu[V0 + 4] * 24;
    [V0 + 1] = b(bu[script + 2]); // write kawai to new structure

    A1 = w[8009c544];
    [A1 + unit_id * 84 + 0] = h(1);
    [A1 + unit_id * 84 + 2] = h(0);
    [A1 + unit_id * 84 + 4] = w(script + 3);

    if (bu[script + 2] == 0)
    {
        V0 = w[8009c544];
        V1 = w[V0 + unit_id * 84 + 4];

        if (bu[V1 + 0] == 1 && bu[V1 + 1] == 1 && bu[V1 + 2] == 0)
        {
            [V0 + unit_id * 84 + 8] = b(0);
            [V0 + unit_id * 84 + 9] = b(0);
        }
        else
        {
            [V0 + unit_id * 84 + 8] = b(1);
        }
    }
}

V0 = bu[800722c4];
[800831fc + V0 * 2] = h(hu[800831fc + V0 * 2] + size);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x29 KAWIW
A0 = bu[800722C4];
V1 = bu[8007EB98 + A0];
if (V1 != FF)
{
    V0 = w[8009C544];
    kawai_executed = h[V0 + V1 * 84 + 0];

    if (kawai_executed == 1)
    {
        return 1;
    }

    [V0 + V1 * 84 + 0] = h(0);
}

V1 = hu[800831FC + A0 * 2];
V1 = V1 + 1;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////////