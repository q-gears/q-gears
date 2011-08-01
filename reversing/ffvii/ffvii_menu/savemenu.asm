////////////////////////////////
// func1d0408
[8009a000] = h(30);
[8009a004] = w(A0 & ffff);
[8009a008] = w(A0 & ffff);
system_execute_AKAO;
////////////////////////////////



////////////////////////////////
// func1d0448
// looks like fade
S1 = A0;
packet = w[80062f24];

[packet + 3] = b(3);
[packet + 7] = b(60);

A0 = packet; // packet address
A1 = 1; // add semi transparency
system_change_semi_transparency_in_packet;

[packet + 8] = h(0);
[packet + a] = h(0);
[packet + c] = h(180);
[packet + e] = h(e8);

[packet + 4] = b(w[801d4ec4]); // 0xFF000000
[packet + 5] = b(w[801d4ec4])
[packet + 6] = b(w[801d4ec4])

A0 = w[80062fc4];
[80062f24] = w(packet + 10);
A1 = packet;
system_add_render_packet_to_queue;

A0 = 0;
A1 = 1;
A2 = 5f;
A3 = SP + 10;
[SP + 10] = h(0);
[SP + 12] = h(0);
[SP + 14] = h(ff);
[SP + 16] = h(ff);
func26a34;

[801d4ec4] = w(w[801d4ec4] + S1);

if (V0 < 0)
{
    [801d4ec4] = w(0);
}

if (w[801d4ec4] >= 100)
{
    [801d4ec4] = w(ff);
}

return w[801d4ec4]; // 0xFF000000
////////////////////////////////



func1d05c0:	; 801D05C0
801D05C0	addiu  sp, sp, $ffc0 (=-$40)
801D05C4	andi   v1, a0, $00ff
801D05C8	lui    a0, $801e
801D05CC	addiu  a0, a0, $379c
801D05D0	ori    v0, zero, $00f0
801D05D4	lui    at, $801e
801D05D8	sw     v0, $3860(at)
801D05DC	ori    v0, zero, $0002
801D05E0	lui    at, $801e
801D05E4	sw     v1, $36b8(at)
801D05E8	ori    v1, zero, $0001
801D05EC	addu   a1, zero, zero
801D05F0	addu   a2, zero, zero
801D05F4	ori    a3, zero, $0001
801D05F8	sw     ra, $0038(sp)
801D05FC	lui    at, $801e
801D0600	sw     zero, $3850(at)
801D0604	sw     v0, $0010(sp)
801D0608	sw     zero, $0014(sp)
801D060C	sw     zero, $0018(sp)
801D0610	sw     v1, $001c(sp)
801D0614	sw     v0, $0020(sp)
801D0618	sw     zero, $0024(sp)
801D061C	sw     zero, $0028(sp)
801D0620	sw     zero, $002c(sp)
801D0624	sw     v1, $0030(sp)
801D0628	jal    $80026448
801D062C	sw     zero, $0034(sp)
801D0630	lui    a0, $801f
801D0634	addiu  a0, a0, $8f44 (=-$70bc)
801D0638	jal    $80025b8c
801D063C	nop
801D0640	lui    a0, $801e
801D0644	addiu  a0, a0, $4538
801D0648	jal    $80025c14
801D064C	nop
801D0650	jal    $80025df8
801D0654	nop
801D0658	jal    func1d19c4 [$801d19c4]
801D065C	nop
801D0660	lw     ra, $0038(sp)
801D0664	addiu  sp, sp, $0040
801D0668	jr     ra 
801D066C	nop


func1d0670:	; 801D0670
801D0670	addiu  sp, sp, $ffe8 (=-$18)
801D0674	sw     ra, $0010(sp)
801D0678	lui    a0, $801f
801D067C	addiu  a0, a0, $8f44 (=-$70bc)
801D0680	jal    $80025bd0
801D0684	nop
801D0688	lui    a0, $801e
801D068C	addiu  a0, a0, $4538
801D0690	jal    $80025c54
801D0694	nop
801D0698	jal    func1d1ba4 [$801d1ba4]
801D069C	nop
801D06A0	lw     ra, $0010(sp)
801D06A4	addiu  sp, sp, $0018
801D06A8	jr     ra 
801D06AC	nop


func1d06b0:	; 801D06B0
801D06B0	lui    v0, $801e
801D06B4	lw     v0, $36b8(v0)
801D06B8	addiu  sp, sp, $ff98 (=-$68)
801D06BC	sw     s2, $0058(sp)
801D06C0	addu   s2, a0, zero
801D06C4	sw     ra, $0060(sp)
801D06C8	sw     s3, $005c(sp)
801D06CC	sw     s1, $0054(sp)
801D06D0	bne    v0, zero, L1d06f0 [$801d06f0]
801D06D4	sw     s0, $0050(sp)
801D06D8	lui    a0, $8006
801D06DC	lw     a0, $2f58(a0)
801D06E0	jal    $800230c4
801D06E4	nop
801D06E8	j      L1d0740 [$801d0740]
801D06EC	nop

L1d06f0:	; 801D06F0
801D06F0	lui    v1, $801e
801D06F4	lw     v1, $36b0(v1)
801D06F8	nop
801D06FC	bne    v1, zero, L1d071c [$801d071c]
801D0700	ori    v0, zero, $0002
A0 = -f;
func1d0448;

801D070C	bne    v0, zero, L1d0740 [$801d0740]
801D0710	ori    v0, zero, $0001
801D0714	j      L1d0738 [$801d0738]
801D0718	nop

L1d071c:	; 801D071C
801D071C	bne    v1, v0, L1d0740 [$801d0740]
801D0720	nop
A0 = f;
func1d0448;

801D072C	ori    v1, zero, $00ff
801D0730	bne    v0, v1, L1d0740 [$801d0740]
801D0734	addiu  v0, zero, $ffff (=-$1)

L1d0738:	; 801D0738
801D0738	lui    at, $801e
801D073C	sw     v0, $36b0(at)

L1d0740:	; 801D0740
801D0740	jal    $80023050
801D0744	nop
801D0748	beq    v0, zero, L1d0778 [$801d0778]
801D074C	nop
801D0750	lui    v0, $801e
801D0754	lw     v0, $36b8(v0)
801D0758	nop
801D075C	beq    v0, zero, L1d07c8 [$801d07c8]
801D0760	ori    v0, zero, $0001
801D0764	lui    v1, $801e
801D0768	lw     v1, $36b0(v1)
801D076C	nop
801D0770	bne    v1, v0, L1d07c8 [$801d07c8]
801D0774	nop

L1d0778:	; 801D0778
801D0778	jal    $8001f6b4
801D077C	nop
801D0780	andi   v0, v0, $00ff
801D0784	bne    v0, zero, L1d07c8 [$801d07c8]
801D0788	nop
801D078C	lui    v0, $801e
801D0790	lw     v0, $3850(v0)
801D0794	nop
801D0798	sltiu  v0, v0, $0002
801D079C	beq    v0, zero, L1d07ac [$801d07ac]
801D07A0	nop
801D07A4	jal    func1d3668 [$801d3668]
801D07A8	addu   a0, s2, zero

L1d07ac:	; 801D07AC
801D07AC	lui    v0, $801e
801D07B0	lw     v0, $3860(v0)
801D07B4	nop
801D07B8	beq    v0, zero, L1d07c8 [$801d07c8]
801D07BC	addiu  v0, v0, $ffff (=-$1)
801D07C0	lui    at, $801e
801D07C4	sw     v0, $3860(at)

L1d07c8:	; 801D07C8
801D07C8	jal    $80026b5c
801D07CC	ori    a0, zero, $0080
801D07D0	lui    v1, $801e
801D07D4	lw     v1, $3850(v1)
801D07D8	nop
801D07DC	sltiu  v0, v1, $0008
801D07E0	beq    v0, zero, L1d0fa4 [$801d0fa4]
801D07E4	sll    v0, v1, $02
801D07E8	lui    at, $801d
801D07EC	addiu  at, at, $0010
801D07F0	addu   at, at, v0
801D07F4	lw     v0, $0000(at)
801D07F8	nop
801D07FC	jr     v0 
801D0800	nop

801D0804	lui    s1, $801d
801D0808	addiu  s1, s1, $4ec8
801D080C	lh     a0, $0000(s1)
801D0810	lui    v0, $801e
801D0814	lb     v0, $37a7(v0)
801D0818	addiu  a0, a0, $ffee (=-$12)
801D081C	sll    a1, v0, $01
801D0820	addu   a1, a1, v0
801D0824	sll    a1, a1, $02
801D0828	lui    v0, $801d
801D082C	lh     v0, $4eca(v0)
801D0830	addiu  a1, a1, $0006
801D0838	addu   a1, v0, a1
func1eb2c; // cursor

801D083C	ori    a0, zero, $000a
801D0840	ori    a1, zero, $000b

S0 = 801e2d20;
A2 = 801e2d20; // text "Select a slot."
801D0854	ori    a3, zero, $0007
func26f44;

801D0858	addiu  a2, s0, $0048
801D085C	lh     a0, $0000(s1)
801D0860	lui    a1, $801d
801D0864	lh     a1, $4eca(a1)
801D0868	lui    a3, $801f
801D086C	lbu    a3, $8f38(a3)
801D0870	addiu  a0, a0, $000c
801D0874	addiu  a1, a1, $0005
801D0878	sltu   a3, zero, a3
801D087C	subu   a3, zero, a3
801D0884	andi   a3, a3, $0007
func26f44;

L1d0888:	; 801D0888
801D0888	addiu  a2, s0, $006c
801D088C	lh     a0, $0000(s1)
801D0890	lui    a1, $801d
801D0894	lh     a1, $4eca(a1)
801D0898	lui    a3, $801f
801D089C	lbu    a3, $8f3b(a3)
801D08A0	addiu  a0, a0, $000c
801D08A4	addiu  a1, a1, $0011
801D08A8	sltu   a3, zero, a3
801D08AC	subu   a3, zero, a3
801D08B4	andi   a3, a3, $0007
func26f44;

801D08B8	addu   a0, zero, zero
801D08BC	ori    a1, zero, $0001
801D08C0	ori    a2, zero, $007f
801D08C4	addiu  a3, sp, $0040
801D08C8	ori    v0, zero, $0100
801D08CC	sh     zero, $0040(sp)
801D08D0	sh     zero, $0042(sp)
801D08D4	sh     v0, $0044(sp)
801D08D8	jal    $80026a34
801D08DC	sh     v0, $0046(sp)
801D08E0	j      L1d0f9c [$801d0f9c]
801D08E4	addu   a0, s1, zero
801D08E8	lui    s1, $801d
801D08EC	addiu  s1, s1, $4ed0
801D08F0	lh     a0, $0000(s1)
801D08F4	lui    v0, $801e
801D08F8	lb     v0, $3825(v0)
801D08FC	addiu  a0, a0, $0016
801D0900	sll    a1, v0, $01
801D0904	addu   a1, a1, v0
801D0908	sll    a1, a1, $02
801D090C	lui    v0, $801d
801D0910	lh     v0, $4ed2(v0)
801D0914	addiu  a1, a1, $0015
801D091C	addu   a1, v0, a1
func1eb2c; // cursor

801D0920	addu   a0, zero, zero
801D0924	ori    a1, zero, $0001
801D0928	ori    a2, zero, $007f
801D092C	addiu  a3, sp, $0040
801D0930	ori    v0, zero, $0100
801D0934	sh     zero, $0040(sp)
801D0938	sh     zero, $0042(sp)
801D093C	sh     v0, $0044(sp)
801D0940	jal    $80026a34
801D0944	sh     v0, $0046(sp)
801D0948	lui    s0, $801e
801D094C	addiu  s0, s0, $31a0
801D0950	addu   a2, s0, zero
801D0954	ori    a3, zero, $0007
801D0958	lh     a0, $0000(s1)
801D095C	lui    a1, $801d
801D0960	lh     a1, $4ed2(a1)
801D0964	addiu  a0, a0, $000a
801D096C	addiu  a1, a1, $0006
func26f44;

801D0970	addiu  a2, s0, $0024
801D0974	ori    a3, zero, $0007
801D0978	lh     a0, $0000(s1)
801D097C	lui    a1, $801d
801D0980	lh     a1, $4ed2(a1)
801D0984	addiu  a0, a0, $0030
801D098C	addiu  a1, a1, $0013
func26f44;

801D0990	addiu  a2, s0, $0048
801D0994	ori    a3, zero, $0007
801D0998	lh     a0, $0000(s1)
801D099C	lui    a1, $801d
801D09A0	lh     a1, $4ed2(a1)
801D09A4	addiu  a0, a0, $0030
801D09AC	addiu  a1, a1, $001f
func26f44;

801D09B0	jal    $8001e040
801D09B4	addu   a0, s1, zero
801D09B8	lui    v0, $801e
801D09BC	lb     v0, $37a7(v0)
801D09C0	nop
801D09C4	sll    v1, v0, $01
801D09C8	addu   v1, v1, v0
801D09CC	lui    at, $801f
801D09D0	addiu  at, at, $8f38 (=-$70c8)
801D09D4	addu   at, at, v1
801D09D8	lbu    v0, $0000(at)
801D09DC	nop
801D09E0	bne    v0, zero, L1d09f8 [$801d09f8]
801D09E4	nop
801D09E8	lui    at, $801e
801D09EC	sw     zero, $3850(at)
801D09F0	j      L1d0fa4 [$801d0fa4]
801D09F4	nop

L1d09f8:	; 801D09F8
801D09F8	jal    $800269d0
801D09FC	nop
801D0A00	lui    v0, $801e
801D0A04	lw     v0, $36b8(v0)
801D0A08	nop
801D0A0C	bne    v0, zero, L1d0a24 [$801d0a24]
801D0A10	nop
801D0A14	lui    v0, $8006
801D0A18	lw     v0, $2f58(v0)
801D0A1C	j      L1d0a34 [$801d0a34]
801D0A20	sll    a0, v0, $02

L1d0a24:	; 801D0A24
801D0A24	lui    v0, $801e
801D0A28	lw     v0, $36b4(v0)
801D0A2C	nop
801D0A30	sll    a0, v0, $02

L1d0a34:	; 801D0A34
801D0A34	addu   a0, a0, v0
801D0A38	sll    a0, a0, $0c
801D0A3C	lui    v0, $801d
801D0A40	addiu  v0, v0, $4edc
801D0A44	jal    $800269c0
801D0A48	addu   a0, a0, v0
801D0A4C	lui    v1, $801e
801D0A50	lw     v1, $3850(v1)
801D0A54	ori    v0, zero, $0007
801D0A58	bne    v1, v0, L1d0a68 [$801d0a68]
801D0A5C	andi   v0, s2, $0002
801D0A60	beq    v0, zero, L1d0a80 [$801d0a80]
801D0A64	nop

L1d0a68:	; 801D0A68
801D0A68	lui    a1, $801e
801D0A6C	lb     a1, $37b9(a1)
801D0A70	ori    a0, zero, $0008
801D0A74	sll    a1, a1, $06
801D0A7C	ori    a1, a1, $0038
func1eb2c; // cursor


L1d0a80:	; 801D0A80
801D0A80	lui    v1, $801e
801D0A84	addiu  v1, v1, $37b6
801D0A88	lh     v0, $0000(v1)
801D0A8C	nop
801D0A90	bne    v0, zero, L1d0a9c [$801d0a9c]
801D0A94	ori    s3, zero, $0004
801D0A98	ori    s3, zero, $0003

L1d0a9c:	; 801D0A9C
801D0A9C	beq    s3, zero, L1d0b6c [$801d0b6c]
801D0AA0	addu   s0, zero, zero
801D0AA4	addiu  s2, v1, $fffa (=-$6)
801D0AA8	addu   s1, zero, zero

loop1d0aac:	; 801D0AAC
801D0AAC	lh     v1, $0000(s2)
801D0AB0	lui    v0, $8006
801D0AB4	lhu    v0, $2f3c(v0)
801D0AB8	addu   v1, s0, v1
801D0ABC	srav   v0, v1, v0
801D0AC0	andi   v0, v0, $0001
801D0AC4	beq    v0, zero, L1d0b04 [$801d0b04]
801D0AC8	ori    a0, zero, $0032
801D0ACC	jal    $8001de70
801D0AD0	nop
801D0AD4	addu   a0, zero, zero
801D0AD8	lb     a1, $000d(s2)
801D0ADC	lh     a2, $0000(s2)
801D0AE0	sll    a1, a1, $03
801D0AE4	addiu  a1, a1, $001d
801D0AE8	addu   a1, s1, a1
801D0AEC	jal    func1d370c [$801d370c]
801D0AF0	addu   a2, s0, a2
801D0AF4	jal    $8001deb0
801D0AF8	addiu  s1, s1, $0040
801D0AFC	j      L1d0b60 [$801d0b60]
801D0B00	addiu  s0, s0, $0001

L1d0b04:	; 801D0B04
A2 = 801e2e1c; // text "EMPTY"
801D0B0C	lb     a1, $000d(s2)
801D0B10	ori    a3, zero, $0006
801D0B14	sll    a1, a1, $03
801D0B18	addiu  a1, a1, $0037
801D0B20	addu   a1, s1, a1
func26f44;

801D0B24	lui    a1, $801e
801D0B28	addiu  a1, a1, $eef4 (=-$110c)
801D0B2C	jal    $8001de40
801D0B30	addiu  a0, sp, $0038
801D0B34	addiu  a0, sp, $0038
801D0B38	lb     a2, $000d(s2)
801D0B3C	addu   a1, zero, zero
801D0B40	sll    a2, a2, $03
801D0B44	addiu  a2, a2, $001d
801D0B48	jal    $8001de24
801D0B4C	addu   a2, s1, a2
801D0B50	jal    $8001e040
801D0B54	addiu  a0, sp, $0038
801D0B58	addiu  s1, s1, $0040
801D0B5C	addiu  s0, s0, $0001

L1d0b60:	; 801D0B60
801D0B60	slt    v0, s0, s3
801D0B64	bne    v0, zero, loop1d0aac [$801d0aac]
801D0B68	nop

L1d0b6c:	; 801D0B6C
801D0B6C	jal    $80026b5c
801D0B70	ori    a0, zero, $0080
801D0B74	lui    v1, $801e
801D0B78	lw     v1, $36b8(v1)
801D0B7C	ori    v0, zero, $001d
801D0B80	sh     v0, $0042(sp)
801D0B84	ori    v0, zero, $016c
801D0B88	sh     v0, $0044(sp)
801D0B8C	ori    v0, zero, $00c3
801D0B90	sh     zero, $0040(sp)
801D0B94	bne    v1, zero, L1d0bc8 [$801d0bc8]
801D0B98	sh     v0, $0046(sp)
801D0B9C	lui    v0, $8006
801D0BA0	lw     v0, $2f58(v0)
801D0BA4	addiu  a1, sp, $0040
801D0BA8	sll    a0, v0, $01
801D0BAC	addu   a0, a0, v0
801D0BB0	sll    a0, a0, $03
801D0BB4	subu   a0, a0, v0
801D0BB8	lui    v0, $8007
801D0BBC	addiu  v0, v0, $06a4
801D0BC0	j      L1d0bf0 [$801d0bf0]
801D0BC4	sll    a0, a0, $02

L1d0bc8:	; 801D0BC8
801D0BC8	lui    v0, $801e
801D0BCC	lw     v0, $36b4(v0)
801D0BD0	addiu  a1, sp, $0040
801D0BD4	sll    a0, v0, $01
801D0BD8	addu   a0, a0, v0
801D0BDC	sll    a0, a0, $03
801D0BE0	subu   a0, a0, v0
801D0BE4	sll    a0, a0, $02
801D0BE8	lui    v0, $801e
801D0BEC	addiu  v0, v0, $36bc

L1d0bf0:	; 801D0BF0
801D0BF0	jal    $80026a94
801D0BF4	addu   a0, a0, v0
801D0BF8	ori    a0, zero, $000a
801D0BFC	ori    a1, zero, $000b
S1 = 801e2d44;
A2 = S1; // text "Select a file."

801D0C10	ori    a3, zero, $0007
func26f44;

801D0C14	ori    a0, zero, $00ce
801D0C18	ori    a1, zero, $000b
801D0C1C	addiu  s0, s1, $00fc
801D0C20	addu   a2, s0, zero
801D0C28	ori    a3, zero, $0006
func26f44;

801D0C2C	jal    $80026b70
801D0C30	addu   a0, s0, zero
801D0C34	addiu  a0, v0, $00d0
801D0C38	ori    a1, zero, $000b
801D0C3C	ori    a3, zero, $0007
801D0C40	addiu  s1, s1, $ffb8 (=-$48)
801D0C44	lui    v0, $801e
801D0C48	lh     v0, $37b0(v0)
801D0C4C	lui    v1, $801e
801D0C50	lb     v1, $37b9(v1)
801D0C54	addiu  v0, v0, $000d
801D0C58	addu   v1, v1, v0
801D0C5C	sll    a2, v1, $03
801D0C60	addu   a2, a2, v1
801D0C64	sll    a2, a2, $02
801D0C6C	addu   a2, a2, s1
func26f44;

801D0C70	addiu  a0, sp, $0038
801D0C74	ori    a1, zero, $00c8
801D0C78	ori    a2, zero, $0005
801D0C7C	ori    a3, zero, $004e
801D0C80	ori    v0, zero, $0018
801D0C84	jal    $8001de0c
801D0C88	sw     v0, $0010(sp)
801D0C8C	jal    $8001e040
801D0C90	addiu  a0, sp, $0038
801D0C94	jal    $800269e8
801D0C98	nop
801D0C9C	j      L1d0fa4 [$801d0fa4]
801D0CA0	nop
801D0CA4	lui    v1, $801e
801D0CA8	lw     v1, $3850(v1)
801D0CAC	ori    v0, zero, $0002
801D0CB0	bne    v1, v0, L1d0cc8 [$801d0cc8]
801D0CB4	ori    s2, zero, $00e0
801D0CB8	ori    s2, zero, $0040
801D0CBC	ori    s1, zero, $0020
801D0CC0	j      L1d0cd0 [$801d0cd0]
801D0CC4	ori    s0, zero, $00a0

L1d0cc8:	; 801D0CC8
801D0CC8	ori    s1, zero, $0080
801D0CCC	addu   s0, zero, zero

L1d0cd0:	; 801D0CD0
801D0CD0	ori    a0, zero, $000a
801D0CD4	ori    a1, zero, $000b
A2 = 801e2eac; // text "Checking Memory card."
801D0CE4	ori    a3, zero, $0007
func26f44;

801D0CE8	lui    v0, $801e
801D0CEC	lw     v0, $36a8(v0)
801D0CF0	nop
801D0CF4	bne    v0, zero, L1d0d54 [$801d0d54]
801D0CF8	ori    v0, zero, $0018
801D0CFC	ori    a0, zero, $007a
801D0D00	ori    a1, zero, $0075
801D0D04	lui    a2, $801e
801D0D08	lw     a2, $36ac(a2)
801D0D0C	ori    a3, zero, $0008
801D0D10	sw     s2, $0010(sp)
801D0D14	sw     s1, $0014(sp)
801D0D18	sw     s0, $0018(sp)
801D0D1C	addiu  a2, a2, $0001
801D0D20	jal    $800285ac
801D0D24	sll    a2, a2, $03
801D0D28	addu   a0, zero, zero
801D0D2C	ori    a1, zero, $0001
801D0D30	ori    a2, zero, $003f
801D0D34	addiu  a3, sp, $0040
801D0D38	ori    v0, zero, $00ff
801D0D3C	sh     zero, $0040(sp)
801D0D40	sh     zero, $0042(sp)
801D0D44	sh     v0, $0044(sp)
801D0D48	jal    $80026a34
801D0D4C	sh     v0, $0046(sp)
801D0D50	ori    v0, zero, $0018

L1d0d54:	; 801D0D54
801D0D54	sw     v0, $0010(sp)
801D0D58	addiu  a0, sp, $0038
801D0D5C	ori    a1, zero, $0070
801D0D60	ori    a2, zero, $006d
801D0D64	j      L1d0f90 [$801d0f90]
801D0D68	ori    a3, zero, $008c
S2 = 801e2df8;
A0 = S2;
801D0D74	jal    $80026b70

801D0D7C	addiu  s1, v0, $0010
801D0D80	srl    s0, s1, $1f
801D0D84	addu   s0, s1, s0
801D0D88	sra    s0, s0, $01
801D0D8C	ori    a0, zero, $00be
801D0D90	subu   a0, a0, s0
801D0D94	ori    a1, zero, $0073
A2 = S2; // text "Saving. Do not remove memory card."

801D0DA0	ori    a3, zero, $0007
func26f44;

801D0DA4	ori    v0, zero, $0018
801D0DA8	sw     v0, $0010(sp)
801D0DAC	addiu  a0, sp, $0038
801D0DB0	ori    a1, zero, $00b6
801D0DB4	subu   a1, a1, s0
801D0DB8	ori    a2, zero, $006d
801D0DBC	j      L1d0f90 [$801d0f90]
801D0DC0	addu   a3, s1, zero
801D0DC4	andi   v0, s2, $0002
801D0DC8	beq    v0, zero, L1d0e04 [$801d0e04]
801D0DCC	nop
801D0DD0	lui    a0, $801d
801D0DD4	lh     a0, $4ec8(a0)
801D0DD8	lui    v0, $801e
801D0DDC	lb     v0, $37a7(v0)
801D0DE0	addiu  a0, a0, $ffee (=-$12)
801D0DE4	sll    a1, v0, $01
801D0DE8	addu   a1, a1, v0
801D0DEC	sll    a1, a1, $02
801D0DF0	lui    v0, $801d
801D0DF4	lh     v0, $4eca(v0)
801D0DF8	addiu  a1, a1, $0006
801D0E00	addu   a1, v0, a1
func1eb2c; // cursor

L1d0e04:	; 801D0E04
801D0E04	lui    s0, $801d
801D0E08	addiu  s0, s0, $4ec8
801D0E0C	lui    s3, $801e
801D0E10	addiu  s3, s3, $2d68
801D0E14	addu   a2, s3, zero
801D0E18	lh     a0, $0000(s0)
801D0E1C	lui    a1, $801d
801D0E20	lh     a1, $4eca(a1)
801D0E24	lui    a3, $801f
801D0E28	lbu    a3, $8f38(a3)
801D0E2C	addiu  a0, a0, $000c
801D0E30	addiu  a1, a1, $0005
801D0E34	sltu   a3, zero, a3
801D0E38	subu   a3, zero, a3
801D0E40	andi   a3, a3, $0007
func26f44;

801D0E44	addiu  a2, s3, $0024
801D0E48	lh     a0, $0000(s0)
801D0E4C	lui    a1, $801d
801D0E50	lh     a1, $4eca(a1)
801D0E54	lui    a3, $801f
801D0E58	lbu    a3, $8f3b(a3)
801D0E5C	addiu  a0, a0, $000c
801D0E60	addiu  a1, a1, $0011
801D0E64	sltu   a3, zero, a3
801D0E68	subu   a3, zero, a3
801D0E70	andi   a3, a3, $0007
func26f44;

801D0E74	addu   a0, zero, zero
801D0E78	ori    a1, zero, $0001
801D0E7C	ori    a2, zero, $007f
801D0E80	addiu  a3, sp, $0040
801D0E84	ori    v0, zero, $0100
801D0E88	sh     zero, $0040(sp)
801D0E8C	sh     zero, $0042(sp)
801D0E90	sh     v0, $0044(sp)
801D0E94	jal    $80026a34
801D0E98	sh     v0, $0046(sp)
801D0E9C	jal    $8001e040
801D0EA0	addu   a0, s0, zero
801D0EA4	ori    a0, zero, $000a
801D0EA8	ori    a1, zero, $000b
801D0EAC	lui    s0, $801e
801D0EB0	addiu  s0, s0, $3320
801D0EB4	addu   a2, s0, zero
801D0EBC	ori    a3, zero, $0007
func26f44;

801D0EC0	addiu  s0, s0, $0030
801D0EC4	jal    $80026b70
801D0EC8	addu   a0, s0, zero
801D0ECC	addiu  s2, v0, $0010
801D0ED0	srl    s1, s2, $1f
801D0ED4	addu   s1, s2, s1
801D0ED8	sra    s1, s1, $01
801D0EDC	ori    a0, zero, $00be
801D0EE0	subu   a0, a0, s1
801D0EE4	addu   a2, s0, zero
801D0EE8	lui    a1, $801d
801D0EEC	lh     a1, $4ece(a1)
801D0EF0	ori    a3, zero, $0007
801D0EF8	addiu  a1, a1, $0063
func26f44;

801D0EFC	ori    s0, zero, $00e4
801D0F00	subu   s0, s0, s1
801D0F04	addu   a0, s0, zero
801D0F08	addiu  a2, s3, $045c
801D0F0C	lui    a1, $801d
801D0F10	lh     a1, $4ece(a1)
801D0F14	ori    a3, zero, $0007
801D0F1C	addiu  a1, a1, $0070
func26f44;

801D0F20	addu   a0, s0, zero
801D0F24	addiu  a2, s3, $0480
801D0F28	lui    a1, $801d
801D0F2C	lh     a1, $4ece(a1)
801D0F30	ori    a3, zero, $0007
801D0F38	addiu  a1, a1, $007c
func26f44;

801D0F3C	ori    a0, zero, $00c8
801D0F40	subu   a0, a0, s1
801D0F44	lui    v1, $801e
801D0F48	lb     v1, $3813(v1)
801D0F4C	lui    a1, $801d
801D0F50	lh     a1, $4ece(a1)
801D0F54	sll    v0, v1, $01
801D0F58	addu   v0, v0, v1
801D0F5C	sll    v0, v0, $02
801D0F60	addiu  a1, a1, $0073
801D0F68	addu   a1, v0, a1
func1eb2c; // cursor

801D0F6C	addiu  a0, sp, $0038
801D0F70	ori    a1, zero, $00b6
801D0F74	subu   a1, a1, s1
801D0F78	addu   a3, s2, zero
801D0F7C	lui    a2, $801d
801D0F80	lh     a2, $4ece(a2)
801D0F84	ori    v0, zero, $0030
801D0F88	sw     v0, $0010(sp)
801D0F8C	addiu  a2, a2, $005d

L1d0f90:	; 801D0F90
801D0F90	jal    $8001de0c
801D0F94	nop
801D0F98	addiu  a0, sp, $0038

L1d0f9c:	; 801D0F9C
801D0F9C	jal    $8001e040
801D0FA0	nop

L1d0fa4:	; 801D0FA4
801D0FA4	lui    v0, $801e
801D0FA8	lw     v0, $36b8(v0)
801D0FAC	nop
801D0FB0	beq    v0, zero, L1d0fe8 [$801d0fe8]
801D0FB4	nop
801D0FB8	jal    $80026b5c
801D0FBC	ori    a0, zero, $0080
801D0FC0	ori    a0, zero, $0126
801D0FC4	ori    a1, zero, $000b
801D0FC8	lui    a2, $801e
801D0FCC	addiu  a2, a2, $eedc (=-$1124)
801D0FD4	ori    a3, zero, $0007
func26f44;

801D0FD8	lui    a0, $801e
801D0FDC	addiu  a0, a0, $eefc (=-$1104)
801D0FE0	jal    $8001e040
801D0FE4	nop

L1d0fe8:	; 801D0FE8
801D0FE8	addiu  a0, sp, $0038
801D0FEC	addu   a1, zero, zero
801D0FF0	ori    a2, zero, $0005
801D0FF4	ori    a3, zero, $016c
801D0FF8	ori    v0, zero, $0018
801D0FFC	jal    $8001de0c
801D1000	sw     v0, $0010(sp)
801D1004	jal    $8001e040
801D1008	addiu  a0, sp, $0038
801D100C	lui    v0, $801e
801D1010	lw     v0, $36b8(v0)
801D1014	nop
801D1018	bne    v0, zero, L1d1044 [$801d1044]
801D101C	nop
801D1020	jal    $80023050
801D1024	nop
801D1028	beq    v0, zero, L1d1058 [$801d1058]
801D102C	nop
801D1030	lui    v0, $801e
801D1034	lw     v0, $36b8(v0)
801D1038	nop
801D103C	beq    v0, zero, L1d1754 [$801d1754]
801D1040	nop

L1d1044:	; 801D1044
801D1044	lui    v1, $801e
801D1048	lw     v1, $36b0(v1)
801D104C	ori    v0, zero, $0001
801D1050	bne    v1, v0, L1d1754 [$801d1754]
801D1054	nop

L1d1058:	; 801D1058
801D1058	jal    $8001f6b4
801D105C	nop
801D1060	andi   v0, v0, $00ff
801D1064	bne    v0, zero, L1d1754 [$801d1754]
801D1068	nop
801D106C	lui    v1, $801e
801D1070	lw     v1, $3850(v1)
801D1074	nop
801D1078	sltiu  v0, v1, $0008
801D107C	beq    v0, zero, L1d1754 [$801d1754]
801D1080	nop
801D1084	sll    v0, v1, $02
801D1088	lui    at, $801d
801D108C	addiu  at, at, $0030
801D1090	addu   at, at, v0
801D1094	lw     v0, $0000(at)
801D1098	nop
801D109C	jr     v0 
801D10A0	nop

801D10A4	lui    v0, $8006
801D10A8	lhu    v0, $2d7c(v0)
801D10AC	nop
801D10B0	andi   v0, v0, $0020
801D10B4	beq    v0, zero, L1d1224 [$801d1224]
801D10B8	nop
801D10BC	lui    s0, $801e
801D10C0	addiu  s0, s0, $37a7
801D10C4	lb     v0, $0000(s0)
801D10C8	nop
801D10CC	sll    v1, v0, $01
801D10D0	addu   v1, v1, v0
801D10D4	lui    at, $801f
801D10D8	addiu  at, at, $8f38 (=-$70c8)
801D10DC	addu   at, at, v1
801D10E0	lbu    v0, $0000(at)
801D10E4	nop
801D10E8	beq    v0, zero, L1d11f4 [$801d11f4]
801D10EC	nop
A0 = 1;
func1d0408; // play sound

801D10F8	lb     v0, $0000(s0)
801D10FC	nop
801D1100	sll    v1, v0, $01
801D1104	addu   v1, v1, v0
801D1108	lui    at, $801f
801D110C	addiu  at, at, $8f3a (=-$70c6)
801D1110	addu   at, at, v1
801D1114	lbu    v0, $0000(at)
801D1118	nop
801D111C	beq    v0, zero, L1d116c [$801d116c]
801D1120	addiu  a0, s0, $0061
801D1124	addu   a1, zero, zero
801D1128	ori    a2, zero, $0001
801D112C	ori    a3, zero, $0001
801D1130	ori    v0, zero, $0006
801D1134	lui    at, $801e
801D1138	sw     v0, $3850(at)
801D113C	ori    v0, zero, $0002
801D1140	ori    v1, zero, $0001
801D1144	sw     v0, $0010(sp)
801D1148	sw     zero, $0014(sp)
801D114C	sw     zero, $0018(sp)
801D1150	sw     v1, $001c(sp)
801D1154	sw     v0, $0020(sp)
801D1158	sw     zero, $0024(sp)
801D115C	sw     zero, $0028(sp)
801D1160	sw     zero, $002c(sp)
801D1164	j      L1d11e4 [$801d11e4]
801D1168	sw     v1, $0030(sp)

L1d116c:	; 801D116C
801D116C	addiu  a0, s0, $0007
801D1170	addu   a1, zero, zero
801D1174	addu   a2, zero, zero
801D1178	ori    a3, zero, $0001
801D117C	ori    v0, zero, $0002
801D1180	ori    v1, zero, $0001
801D1184	lui    at, $801e
801D1188	sw     v0, $3850(at)
801D118C	ori    v0, zero, $003c
801D1190	lui    at, $801e
801D1194	sw     v0, $36a4(at)
801D1198	ori    v0, zero, $0003
801D119C	sw     v0, $0010(sp)
801D11A0	ori    v0, zero, $000f
801D11A4	lui    at, $801e
801D11A8	sw     zero, $36ac(at)
801D11AC	lui    at, $801e
801D11B0	sw     zero, $36a0(at)
801D11B4	lui    at, $8006
801D11B8	sh     zero, $2f3c(at)
801D11BC	lui    at, $801e
801D11C0	sw     v1, $36a8(at)
801D11C4	sw     zero, $0014(sp)
801D11C8	sw     zero, $0018(sp)
801D11CC	sw     v1, $001c(sp)
801D11D0	sw     v0, $0020(sp)
801D11D4	sw     zero, $0024(sp)
801D11D8	sw     zero, $0028(sp)
801D11DC	sw     zero, $002c(sp)
801D11E0	sw     zero, $0030(sp)

L1d11e4:	; 801D11E4
801D11E4	jal    $80026448
801D11E8	sw     zero, $0034(sp)
801D11EC	j      L1d1754 [$801d1754]
801D11F0	nop

L1d11f4:	; 801D11F4
A0 = 3;
func1d0408; // play sound

801D11FC	lui    v0, $801e
801D1200	lw     v0, $3860(v0)
801D1204	lui    a0, $801e
801D1208	addiu  a0, a0, $3380
801D120C	bne    v0, zero, L1d158c [$801d158c]
801D1210	nop
801D1214	lui    a0, $801e
801D1218	addiu  a0, a0, $33b0
801D121C	j      L1d158c [$801d158c]
801D1220	nop

L1d1224:	; 801D1224
801D1224	lui    a0, $801e
801D1228	addiu  a0, a0, $379c
801D122C	jal    $800264a8
801D1230	nop
801D1234	lui    v0, $801e
801D1238	lw     v0, $36b8(v0)
801D123C	nop
801D1240	beq    v0, zero, L1d127c [$801d127c]
801D1244	nop
801D1248	lui    v0, $8006
801D124C	lhu    v0, $2d7c(v0)
801D1250	nop
801D1254	andi   v0, v0, $0040
801D1258	beq    v0, zero, L1d1754 [$801d1754]
801D125C	nop

A0 = 4;
func1d0408; // play sound

801D1268	ori    v0, zero, $0002
801D126C	lui    at, $801e
801D1270	sw     v0, $36b0(at)
801D1274	j      L1d1754 [$801d1754]
801D1278	nop

L1d127c:	; 801D127C
801D127C	lui    v0, $8006
801D1280	lhu    v0, $2d7c(v0)
801D1284	nop
801D1288	andi   v0, v0, $0040
801D128C	beq    v0, zero, L1d1754 [$801d1754]
801D1290	nop
A0 = 4;
func1d0408; // play sound

801D129C	jal    func1d0670 [$801d0670]
801D12A0	nop
801D12A4	ori    a0, zero, $0005
801D12A8	jal    $8002305c
801D12AC	addu   a1, zero, zero
801D12B0	jal    $8002120c
801D12B4	addu   a0, zero, zero
801D12B8	j      L1d1754 [$801d1754]
801D12BC	nop
801D12C0	lui    s1, $801e
801D12C4	addiu  s1, s1, $37bd
801D12C8	lb     s0, $0000(s1)
801D12CC	jal    func1d2da8 [$801d2da8]
801D12D0	addiu  a0, s1, $fff1 (=-$f)
801D12D4	lb     v0, $0000(s1)
801D12D8	nop
801D12DC	bne    v0, zero, L1d1754 [$801d1754]
801D12E0	nop
801D12E4	bne    s0, zero, L1d1754 [$801d1754]
801D12E8	nop
801D12EC	lui    v1, $8006
801D12F0	lhu    v1, $2d7c(v1)
801D12F4	nop
801D12F8	andi   v0, v1, $0020
801D12FC	beq    v0, zero, L1d1360 [$801d1360]
801D1300	addiu  a0, s1, $005d
801D1304	addu   a1, zero, zero
801D1308	addu   a2, zero, zero
801D130C	ori    a3, zero, $0001
801D1310	ori    v0, zero, $0007
801D1314	lui    at, $801e
801D1318	sw     v0, $3850(at)
801D131C	ori    v0, zero, $0002
801D1320	ori    v1, zero, $0001
801D1324	sw     v0, $0010(sp)
801D1328	sw     zero, $0014(sp)
801D132C	sw     zero, $0018(sp)
801D1330	sw     v1, $001c(sp)
801D1334	sw     v0, $0020(sp)
801D1338	sw     zero, $0024(sp)
801D133C	sw     zero, $0028(sp)
801D1340	sw     zero, $002c(sp)
801D1344	sw     v1, $0030(sp)
801D1348	jal    $80026448
801D134C	sw     zero, $0034(sp)

A0 = 1;
func1d0408; // play sound

801D1358	j      L1d1754 [$801d1754]
801D135C	nop

L1d1360:	; 801D1360
801D1360	andi   v0, v1, $0040
801D1364	beq    v0, zero, L1d1754 [$801d1754]
801D1368	nop
A0 = 4;
func1d0408; // play sound

801D1374	lui    at, $801e
801D1378	sw     zero, $3850(at)
801D137C	j      L1d1754 [$801d1754]
801D1380	nop
801D1384	lui    v0, $801e
801D1388	lw     v0, $36a4(v0)
801D138C	nop
801D1390	bne    v0, zero, L1d14e0 [$801d14e0]
801D1394	addiu  v0, v0, $ffff (=-$1)
801D1398	lui    v0, $801e
801D139C	lw     v0, $36a8(v0)
801D13A0	nop
801D13A4	beq    v0, zero, L1d13dc [$801d13dc]
801D13A8	nop
801D13AC	lui    a0, $801e
801D13B0	lb     a0, $37a7(a0)
801D13B4	lui    at, $801e
801D13B8	sw     zero, $36a4(at)
801D13BC	lui    at, $801e
801D13C0	sw     zero, $36a8(at)
801D13C4	jal    func1d1c2c [$801d1c2c]
801D13C8	nop
801D13CC	lui    at, $8006
801D13D0	sh     v0, $2f3c(at)
801D13D4	j      L1d1754 [$801d1754]
801D13D8	nop

L1d13dc:	; 801D13DC
801D13DC	lui    v0, $8006
801D13E0	lhu    v0, $2f3c(v0)
801D13E4	lui    a1, $801e
801D13E8	lw     a1, $36ac(a1)
801D13EC	nop
801D13F0	srav   v0, a1, v0
801D13F4	andi   v0, v0, $0001
801D13F8	beq    v0, zero, L1d1414 [$801d1414]
801D13FC	addu   s0, zero, zero
801D1400	lui    a0, $801e
801D1404	lb     a0, $37a7(a0)
801D1408	jal    func1d3698 [$801d3698]
801D140C	nop
801D1410	addu   s0, v0, zero

L1d1414:	; 801D1414
801D1414	lui    v0, $801e
801D1418	lw     v0, $36ac(v0)
801D141C	nop
801D1420	addiu  v0, v0, $0001
801D1424	lui    at, $801e
801D1428	sw     v0, $36ac(at)
801D142C	beq    s0, zero, L1d144c [$801d144c]
801D1430	nop
801D1434	lui    at, $801e
801D1438	sw     zero, $3850(at)
801D143C	lui    a0, $801e
801D1440	addiu  a0, a0, $3530
801D1444	jal    $8001f6c0
801D1448	ori    a1, zero, $0002

L1d144c:	; 801D144C
801D144C	lui    v1, $801e
801D1450	lw     v1, $36ac(v1)
801D1454	ori    v0, zero, $000f
801D1458	bne    v1, v0, L1d1754 [$801d1754]
801D145C	nop
801D1460	ori    v0, zero, $000e
801D1464	lui    at, $801e
801D1468	sw     v0, $36ac(at)
801D146C	ori    v0, zero, $0003
801D1470	lui    at, $801e
801D1474	sw     v0, $3850(at)
801D1478	ori    v0, zero, $000a
801D147C	lui    at, $801e
801D1480	sw     v0, $36a4(at)

A0 = 2;
func1d0408; // play sound

801D148C	j      L1d1754 [$801d1754]
801D1490	nop
801D1494	lui    v1, $801e
801D1498	lw     v1, $36a4(v1)
801D149C	nop
801D14A0	bne    v1, zero, L1d14b8 [$801d14b8]
801D14A4	addiu  v0, v1, $ffff (=-$1)
801D14A8	ori    v0, zero, $0001
801D14AC	lui    at, $801e
801D14B0	sw     v0, $3850(at)
801D14B4	addiu  v0, v1, $ffff (=-$1)

L1d14b8:	; 801D14B8
801D14B8	lui    at, $801e
801D14BC	sw     v0, $36a4(at)
801D14C0	j      L1d1754 [$801d1754]
801D14C4	nop
801D14C8	lui    v0, $801e
801D14CC	lw     v0, $36a4(v0)
801D14D0	nop
801D14D4	beq    v0, zero, L1d14f0 [$801d14f0]
801D14D8	ori    s1, zero, $0001
801D14DC	addiu  v0, v0, $ffff (=-$1)

L1d14e0:	; 801D14E0
801D14E0	lui    at, $801e
801D14E4	sw     v0, $36a4(at)
801D14E8	j      L1d1754 [$801d1754]
801D14EC	nop

L1d14f0:	; 801D14F0
801D14F0	lui    s0, $801e
801D14F4	addiu  s0, s0, $37b9
801D14F8	lui    at, $801e
801D14FC	sw     s1, $3850(at)
801D1500	lb     v0, $0000(s0)
801D1504	lh     v1, $fff7(s0)
801D1508	lui    a0, $801e
801D150C	lb     a0, $37a7(a0)
801D1510	nop
801D1514	beq    a0, zero, L1d1520 [$801d1520]
801D1518	addu   v0, v0, v1
801D151C	ori    v0, v0, $0010

L1d1520:	; 801D1520
801D1520	jal    func1d2a34 [$801d2a34]
801D1524	addu   a0, v0, zero
801D1528	sll    v0, v0, $10
801D152C	bne    v0, zero, L1d157c [$801d157c]
801D1530	nop
A0 = d0;
func1d0408; // play sound

801D153C	lui    a0, $801e
801D1540	addiu  a0, a0, $30ec
801D1544	jal    $8001f6c0
801D1548	ori    a1, zero, $0007
801D154C	lb     v0, $0000(s0)
801D1550	lh     v1, $fff7(s0)
801D1554	nop
801D1558	addu   v0, v0, v1
801D155C	lui    v1, $8006
801D1560	lhu    v1, $2f3c(v1)
801D1564	sllv   v0, v0, s1
801D1568	or     v1, v1, v0
801D156C	lui    at, $8006
801D1570	sh     v1, $2f3c(at)
801D1574	j      L1d1754 [$801d1754]
801D1578	nop

L1d157c:	; 801D157C
A0 = 3;
func1d0408; // play sound

801D1584	lui    a0, $801e
801D1588	addiu  a0, a0, $3440

L1d158c:	; 801D158C
801D158C	jal    $8001f6c0
801D1590	ori    a1, zero, $0007
801D1594	j      L1d1754 [$801d1754]
801D1598	nop
801D159C	lui    a0, $801e
801D15A0	addiu  a0, a0, $3808
801D15A4	jal    $800264a8
801D15A8	nop
801D15AC	lui    v1, $8006
801D15B0	lhu    v1, $2d7c(v1)
801D15B4	nop
801D15B8	andi   v0, v1, $0020
801D15BC	beq    v0, zero, L1d168c [$801d168c]
801D15C0	andi   v0, v1, $0040
801D15C4	lui    v0, $801e
801D15C8	lb     v0, $3813(v0)
801D15CC	nop
801D15D0	beq    v0, zero, L1d15e8 [$801d15e8]
801D15D4	nop
801D15D8	lui    at, $801e
801D15DC	sw     zero, $3850(at)
801D15E0	j      L1d1734 [$801d1734]
801D15E4	nop

L1d15e8:	; 801D15E8
801D15E8	lui    v0, $801e
801D15EC	lb     v0, $37a7(v0)
801D15F0	lui    a0, $801d
801D15F4	addiu  a0, a0, $0008
801D15F8	beq    v0, zero, L1d1608 [$801d1608]
801D15FC	nop
801D1600	lui    a0, $801d
801D1604	addiu  a0, a0, $0000

L1d1608:	; 801D1608
801D1608	jal    $80042b60
801D160C	nop
801D1610	addu   v1, v0, zero
801D1614	lui    at, $801e
801D1618	sw     zero, $3850(at)
801D161C	ori    v0, zero, $0001
801D1620	bne    v1, v0, L1d166c [$801d166c]
801D1624	nop
801D1628	lui    a0, $801e
801D162C	addiu  a0, a0, $32c0
801D1630	lui    v1, $801e
801D1634	lb     v1, $37a7(v1)
801D1638	nop
801D163C	sll    v0, v1, $01
801D1640	addu   v0, v0, v1
801D1644	lui    at, $801f
801D1648	addiu  at, at, $8f3a (=-$70c6)
801D164C	addu   at, at, v0
801D1650	sb     zero, $0000(at)
801D1654	jal    $8001f6c0
801D1658	ori    a1, zero, $0007

A0 = d0;
func1d0408; // play sound

801D1664	j      L1d1754 [$801d1754]
801D1668	nop

L1d166c:	; 801D166C
801D166C	lui    a0, $801e
801D1670	addiu  a0, a0, $32f0
801D1674	jal    $8001f6c0
801D1678	ori    a1, zero, $0007

A0 = 3;
func1d0408; // play sound

801D1684	j      L1d1754 [$801d1754]
801D1688	nop

L1d168c:	; 801D168C
801D168C	beq    v0, zero, L1d1754 [$801d1754]
801D1690	nop
801D1694	lui    at, $801e
801D1698	sw     zero, $3850(at)
801D169C	j      L1d1734 [$801d1734]
801D16A0	nop
801D16A4	lui    v1, $8006
801D16A8	lhu    v1, $2d7c(v1)
801D16AC	nop
801D16B0	andi   v0, v1, $0020
801D16B4	beq    v0, zero, L1d1720 [$801d1720]
801D16B8	nop
801D16BC	lui    s0, $801e
801D16C0	lb     s0, $3825(s0)
801D16C4	nop
801D16C8	beq    s0, zero, L1d16e0 [$801d16e0]
801D16CC	ori    v0, zero, $0001
801D16D0	beq    s0, v0, L1d1708 [$801d1708]
801D16D4	nop
801D16D8	j      L1d1754 [$801d1754]
801D16DC	nop

L1d16e0:	; 801D16E0
A0 = 1;
func1d0408; // play sound

801D16E8	ori    v0, zero, $0004
801D16EC	lui    at, $801e
801D16F0	sw     v0, $3850(at)
801D16F4	ori    v0, zero, $000a
801D16F8	lui    at, $801e
801D16FC	sw     v0, $36a4(at)
801D1700	j      L1d1754 [$801d1754]
801D1704	nop

L1d1708:	; 801D1708
A0 = 4;
func1d0408; // play sound

801D1710	lui    at, $801e
801D1714	sw     s0, $3850(at)
801D1718	j      L1d1754 [$801d1754]
801D171C	nop

L1d1720:	; 801D1720
801D1720	andi   v0, v1, $0040
801D1724	beq    v0, zero, L1d1744 [$801d1744]
801D1728	ori    v0, zero, $0001
801D172C	lui    at, $801e
801D1730	sw     v0, $3850(at)

L1d1734:	; 801D1734
A0 = 4;
func1d0408; // play sound

801D173C	j      L1d1754 [$801d1754]
801D1740	nop

L1d1744:	; 801D1744
801D1744	lui    a0, $801e
801D1748	addiu  a0, a0, $381a
801D174C	jal    $800264a8
801D1750	nop

L1d1754:	; 801D1754
801D1754	lw     ra, $0060(sp)
801D1758	lw     s3, $005c(sp)
801D175C	lw     s2, $0058(sp)
801D1760	lw     s1, $0054(sp)
801D1764	lw     s0, $0050(sp)
801D1768	addiu  sp, sp, $0068
801D176C	jr     ra 
801D1770	nop

801D1774	addiu  sp, sp, $ffe0 (=-$20)
801D1778	lui    a0, $801e
801D177C	addiu  a0, a0, $36bc
801D1780	lui    a1, $801e
801D1784	addiu  a1, a1, $3774
801D1788	sw     ra, $001c(sp)
801D178C	sw     s2, $0018(sp)
801D1790	sw     s1, $0014(sp)
801D1794	jal    $80021044
801D1798	sw     s0, $0010(sp)
801D179C	addu   s0, zero, zero
801D17A0	lui    at, $801e
801D17A4	sw     zero, $36b0(at)
801D17A8	jal    func1d05c0 [$801d05c0]
801D17AC	ori    a0, zero, $0001
801D17B0	lui    at, $801e
801D17B4	sw     zero, $36b4(at)

L1d17b8:	; 801D17B8
801D17B8	jal    $8001cb48
801D17BC	nop
801D17C0	lui    v0, $801e
801D17C4	lw     v0, $36b4(v0)
801D17C8	nop
801D17CC	sll    a0, v0, $01
801D17D0	addu   a0, a0, v0
801D17D4	sll    a0, a0, $02
801D17D8	addu   a0, a0, v0
801D17DC	sll    a0, a0, $0a
801D17E0	lui    v0, $8007
801D17E4	addiu  v0, v0, $7f64
801D17E8	jal    $800269c0
801D17EC	addu   a0, a0, v0
801D17F0	lui    a0, $801e
801D17F4	lw     a0, $36b4(a0)
801D17F8	lui    v0, $801e
801D17FC	addiu  v0, v0, $3858
801D1800	sll    a0, a0, $02
801D1804	addu   a0, a0, v0
801D1808	lui    at, $801e
801D180C	sw     a0, $3854(at)
801D1810	jal    $8004418c
801D1814	ori    a1, zero, $0001
801D1818	lui    a0, $801e
801D181C	lw     a0, $3854(a0)
801D1820	jal    $80026a00
801D1824	nop
801D1828	jal    $8001f710
801D182C	nop
801D1830	jal    func1d06b0 [$801d06b0]
801D1834	addu   a0, s0, zero
801D1838	addu   s2, v0, zero
801D183C	lui    v1, $801e
801D1840	lw     v1, $36b0(v1)
801D1844	addiu  v0, zero, $ffff (=-$1)
801D1848	beq    v1, v0, L1d18e8 [$801d18e8]
801D184C	nop
801D1850	jal    $80043dd8
801D1854	addu   a0, zero, zero
801D1858	jal    $8003cedc
801D185C	addu   a0, zero, zero
801D1860	lui    v0, $801e
801D1864	lw     v0, $36b4(v0)
801D1868	nop
801D186C	sll    a0, v0, $02
801D1870	addu   a0, a0, v0
801D1874	sll    a0, a0, $02
801D1878	lui    v0, $801e
801D187C	addiu  v0, v0, $3774
801D1880	jal    $800444ac
801D1884	addu   a0, a0, v0
801D1888	lui    v0, $801e
801D188C	lw     v0, $36b4(v0)
801D1890	nop
801D1894	sll    a0, v0, $01
801D1898	addu   a0, a0, v0
801D189C	sll    a0, a0, $03
801D18A0	subu   a0, a0, v0
801D18A4	sll    a0, a0, $02
801D18A8	lui    v0, $801e
801D18AC	addiu  v0, v0, $36bc
801D18B0	jal    $800443b0
801D18B4	addu   a0, a0, v0
801D18B8	lui    a0, $801e
801D18BC	lw     a0, $3854(a0)
801D18C0	jal    $8004433c
801D18C4	addiu  s0, s0, $0001
801D18C8	lui    v0, $801e
801D18CC	lw     v0, $36b4(v0)
801D18D0	nop
801D18D4	xori   v0, v0, $0001
801D18D8	lui    at, $801e
801D18DC	sw     v0, $36b4(at)
801D18E0	j      L1d17b8 [$801d17b8]
801D18E4	nop

L1d18e8:	; 801D18E8
801D18E8	jal    func1d0670 [$801d0670]
801D18EC	nop
801D18F0	jal    $8003cedc
801D18F4	addu   a0, zero, zero
801D18F8	lui    s1, $801e
801D18FC	addiu  s1, s1, $3774
801D1900	jal    $800444ac
801D1904	addu   a0, s1, zero
801D1908	lui    s0, $801e
801D190C	addiu  s0, s0, $36bc
801D1910	jal    $800443b0
801D1914	addu   a0, s0, zero
801D1918	jal    $8003cedc
801D191C	addu   a0, zero, zero
801D1920	jal    $800444ac
801D1924	addiu  a0, s1, $0014
801D1928	jal    $800443b0
801D192C	addiu  a0, s0, $005c
801D1930	addu   v0, s2, zero
801D1934	lw     ra, $001c(sp)
801D1938	lw     s2, $0018(sp)
801D193C	lw     s1, $0014(sp)
801D1940	lw     s0, $0010(sp)
801D1944	addiu  sp, sp, $0020
801D1948	jr     ra 
801D194C	nop


func1d1950:	; 801D1950
801D1950	ori    v1, zero, $ffff
801D1954	andi   a0, a0, $ffff
801D1958	beq    a0, zero, L1d19b8 [$801d19b8]
801D195C	addu   a3, zero, zero

loop1d1960:	; 801D1960
801D1960	andi   v0, a3, $ffff
801D1964	addu   v0, a1, v0
801D1968	lbu    v0, $0000(v0)
801D196C	addu   a2, zero, zero
801D1970	sll    v0, v0, $08
801D1974	xor    v1, v1, v0
801D1978	andi   v0, v1, $8000

loop1d197c:	; 801D197C
801D197C	beq    v0, zero, L1d198c [$801d198c]
801D1980	sll    v0, v1, $01
801D1984	j      L1d1990 [$801d1990]
801D1988	xori   v1, v0, $1021

L1d198c:	; 801D198C
801D198C	sll    v1, v1, $01

L1d1990:	; 801D1990
801D1990	addiu  a2, a2, $0001
801D1994	andi   v0, a2, $ffff
801D1998	sltiu  v0, v0, $0008
801D199C	bne    v0, zero, loop1d197c [$801d197c]
801D19A0	andi   v0, v1, $8000
801D19A4	addiu  a3, a3, $0001
801D19A8	andi   v0, a3, $ffff
801D19AC	sltu   v0, v0, a0
801D19B0	bne    v0, zero, loop1d1960 [$801d1960]
801D19B4	nop

L1d19b8:	; 801D19B8
801D19B8	nor    v0, zero, v1
801D19BC	jr     ra 
801D19C0	andi   v0, v0, $ffff


func1d19c4:	; 801D19C4
801D19C4	lui    v0, $8006
801D19C8	lw     v0, $2dcc(v0)
801D19CC	addiu  sp, sp, $ffe0 (=-$20)
801D19D0	sw     ra, $0018(sp)
801D19D4	sw     s1, $0014(sp)
801D19D8	bne    v0, zero, L1d1b44 [$801d1b44]
801D19DC	sw     s0, $0010(sp)
801D19E0	jal    $80042af0
801D19E4	addu   s1, zero, zero
801D19E8	lui    a0, $f400
801D19EC	ori    a0, a0, $0001
801D19F0	ori    a1, zero, $0004
801D19F4	ori    a2, zero, $2000
801D19F8	jal    $80042a00
801D19FC	addu   a3, zero, zero
801D1A00	lui    a0, $f400
801D1A04	ori    a0, a0, $0001
801D1A08	ori    a1, zero, $8000
801D1A0C	ori    a2, zero, $2000
801D1A10	addu   a3, zero, zero
801D1A14	lui    s0, $800a
801D1A18	addiu  s0, s0, $a024 (=-$5fdc)
801D1A1C	jal    $80042a00
801D1A20	sw     v0, $0000(s0)
801D1A24	lui    a0, $f400
801D1A28	ori    a0, a0, $0001
801D1A2C	ori    a1, zero, $0100
801D1A30	ori    a2, zero, $2000
801D1A34	lui    at, $800a
801D1A38	sw     v0, $a028(at)
801D1A3C	jal    $80042a00
801D1A40	addu   a3, zero, zero
801D1A44	lui    a0, $f400
801D1A48	ori    a0, a0, $0001
801D1A4C	ori    a1, zero, $2000
801D1A50	ori    a2, zero, $2000
801D1A54	lui    at, $800a
801D1A58	sw     v0, $a02c(at)
801D1A5C	jal    $80042a00
801D1A60	addu   a3, zero, zero
801D1A64	lui    a0, $f000
801D1A68	ori    a0, a0, $0011
801D1A6C	ori    a1, zero, $0004
801D1A70	ori    a2, zero, $2000
801D1A74	lui    at, $800a
801D1A78	sw     v0, $a030(at)
801D1A7C	jal    $80042a00
801D1A80	addu   a3, zero, zero
801D1A84	lui    a0, $f000
801D1A88	ori    a0, a0, $0011
801D1A8C	ori    a1, zero, $8000
801D1A90	ori    a2, zero, $2000
801D1A94	lui    at, $800a
801D1A98	sw     v0, $a034(at)
801D1A9C	jal    $80042a00
801D1AA0	addu   a3, zero, zero
801D1AA4	lui    a0, $f000
801D1AA8	ori    a0, a0, $0011
801D1AAC	ori    a1, zero, $0100
801D1AB0	ori    a2, zero, $2000
801D1AB4	lui    at, $800a
801D1AB8	sw     v0, $a038(at)
801D1ABC	jal    $80042a00
801D1AC0	addu   a3, zero, zero
801D1AC4	lui    a0, $f000
801D1AC8	ori    a0, a0, $0011
801D1ACC	ori    a1, zero, $2000
801D1AD0	ori    a2, zero, $2000
801D1AD4	lui    at, $800a
801D1AD8	sw     v0, $a03c(at)
801D1ADC	jal    $80042a00
801D1AE0	addu   a3, zero, zero
801D1AE4	lui    at, $800a
801D1AE8	sw     v0, $a040(at)
801D1AEC	jal    $800489f0
801D1AF0	ori    a0, zero, $0001
801D1AF4	jal    $80048a44
801D1AF8	nop
801D1AFC	jal    $80042ba0
801D1B00	addu   a0, zero, zero
801D1B04	jal    $800429b0
801D1B08	nop
801D1B0C	jal    $80048988
801D1B10	addu   a0, zero, zero

loop1d1b14:	; 801D1B14
801D1B14	lw     a0, $0000(s0)
801D1B18	addiu  s0, s0, $0004
801D1B1C	jal    $80042a40
801D1B20	addiu  s1, s1, $0001
801D1B24	slti   v0, s1, $0008
801D1B28	bne    v0, zero, loop1d1b14 [$801d1b14]
801D1B2C	nop
801D1B30	jal    $80042b00
801D1B34	nop
801D1B38	ori    v0, zero, $0001
801D1B3C	lui    at, $8006
801D1B40	sw     v0, $2dcc(at)

L1d1b44:	; 801D1B44
801D1B44	addu   s1, zero, zero
801D1B48	addu   v1, zero, zero

loop1d1b4c:	; 801D1B4C
801D1B4C	lui    at, $801f
801D1B50	addiu  at, at, $8f38 (=-$70c8)
801D1B54	addu   at, at, v1
801D1B58	sb     zero, $0000(at)
801D1B5C	lui    at, $801f
801D1B60	addiu  at, at, $8f39 (=-$70c7)
801D1B64	addu   at, at, v1
801D1B68	sb     zero, $0000(at)
801D1B6C	lui    at, $801f
801D1B70	addiu  at, at, $8f3a (=-$70c6)
801D1B74	addu   at, at, v1
801D1B78	sb     zero, $0000(at)
801D1B7C	addiu  s1, s1, $0001
801D1B80	slti   v0, s1, $0002
801D1B84	bne    v0, zero, loop1d1b4c [$801d1b4c]
801D1B88	addiu  v1, v1, $0003
801D1B8C	lw     ra, $0018(sp)
801D1B90	lw     s1, $0014(sp)
801D1B94	lw     s0, $0010(sp)
801D1B98	addiu  sp, sp, $0020
801D1B9C	jr     ra 
801D1BA0	nop


func1d1ba4:	; 801D1BA4
801D1BA4	jr     ra 
801D1BA8	nop

801D1BAC	addiu  sp, sp, $ffe8 (=-$18)
801D1BB0	sll    a1, a1, $02
801D1BB4	sw     ra, $0010(sp)
801D1BB8	lui    at, $800a
801D1BBC	addiu  at, at, $a024 (=-$5fdc)
801D1BC0	addu   at, at, a1
801D1BC4	lw     a0, $0000(at)
801D1BC8	jal    $80042a30
801D1BCC	nop
801D1BD0	lw     ra, $0010(sp)
801D1BD4	addiu  sp, sp, $0018
801D1BD8	jr     ra 
801D1BDC	nop


loop1d1be0:	; 801D1BE0
801D1BE0	lbu    v1, $0000(a1)
801D1BE4	addiu  a1, a1, $0001
801D1BE8	lbu    v0, $0000(a0)
801D1BEC	nop
801D1BF0	bne    v0, v1, L1d1c20 [$801d1c20]
801D1BF4	addiu  a0, a0, $0001
801D1BF8	lbu    v0, $0000(a0)
801D1BFC	nop
801D1C00	bne    v0, zero, loop1d1be0 [$801d1be0]
801D1C04	nop
801D1C08	lbu    v0, $0000(a1)
801D1C0C	nop
801D1C10	bne    v0, zero, loop1d1be0 [$801d1be0]
801D1C14	ori    v0, zero, $0001
801D1C18	j      L1d1c24 [$801d1c24]
801D1C1C	nop

L1d1c20:	; 801D1C20
801D1C20	addu   v0, zero, zero

L1d1c24:	; 801D1C24
801D1C24	jr     ra 
801D1C28	nop


func1d1c2c:	; 801D1C2C
801D1C2C	addiu  sp, sp, $ffa8 (=-$58)
801D1C30	sw     s1, $003c(sp)
801D1C34	addu   s1, a0, zero
801D1C38	sw     s3, $0044(sp)
801D1C3C	addu   s3, zero, zero
801D1C40	sw     s0, $0038(sp)
801D1C44	addu   s0, zero, zero
801D1C48	sw     ra, $0050(sp)
801D1C4C	sw     s5, $004c(sp)
801D1C50	sw     s4, $0048(sp)
801D1C54	sw     s2, $0040(sp)

loop1d1c58:	; 801D1C58
801D1C58	lui    a0, $801d
801D1C5C	addiu  a0, a0, $0184
801D1C60	beq    s1, zero, L1d1c70 [$801d1c70]
801D1C64	nop
801D1C68	lui    a0, $801d
801D1C6C	addiu  a0, a0, $017c

L1d1c70:	; 801D1C70
801D1C70	jal    $80042b70
801D1C74	addiu  a1, sp, $0010
801D1C78	addu   s2, v0, zero
801D1C7C	bne    s2, zero, L1d1c98 [$801d1c98]
801D1C80	addiu  s0, s0, $0001
801D1C84	slti   v0, s0, $0064
801D1C88	bne    v0, zero, loop1d1c58 [$801d1c58]
801D1C8C	nop
801D1C90	j      L1d1cf0 [$801d1cf0]
801D1C94	addu   s3, zero, zero

L1d1c98:	; 801D1C98
S5 = 801e2c78;
801D1CA0	ori    s4, zero, $0001
801D1CA4	addu   s0, zero, zero

loop1d1ca8:	; 801D1CA8
801D1CA8	addu   s1, s5, zero

loop1d1cac:	; 801D1CAC
801D1CAC	lw     a1, $0000(s1)
801D1CB0	jal    loop1d1be0 [$801d1be0]
801D1CB4	addu   a0, s2, zero
801D1CB8	beq    v0, zero, L1d1cc4 [$801d1cc4]
801D1CBC	sllv   v0, s0, s4

L1d1cc0:	; 801D1CC0
801D1CC0	or     s3, s3, v0

L1d1cc4:	; 801D1CC4
801D1CC4	addiu  s0, s0, $0001
801D1CC8	slti   v0, s0, $000f
801D1CCC	bne    v0, zero, loop1d1cac [$801d1cac]
801D1CD0	addiu  s1, s1, $0004
801D1CD4	jal    $80042b80
801D1CD8	addu   a0, s2, zero
801D1CDC	addu   s2, v0, zero
801D1CE0	bne    s2, zero, loop1d1ca8 [$801d1ca8]
801D1CE4	addu   s0, zero, zero
801D1CE8	j      L1d1cf4 [$801d1cf4]
801D1CEC	andi   v0, s3, $ffff

L1d1cf0:	; 801D1CF0
801D1CF0	andi   v0, s3, $ffff

L1d1cf4:	; 801D1CF4
801D1CF4	lw     ra, $0050(sp)
801D1CF8	lw     s5, $004c(sp)
801D1CFC	lw     s4, $0048(sp)
801D1D00	lw     s3, $0044(sp)
801D1D04	lw     s2, $0040(sp)
801D1D08	lw     s1, $003c(sp)
801D1D0C	lw     s0, $0038(sp)
801D1D10	addiu  sp, sp, $0058
801D1D14	jr     ra 
801D1D18	nop


func1d1d1c:	; 801D1D1C
801D1D1C	sll    v0, a0, $02
801D1D20	addu   v0, v0, a0
801D1D24	sll    v0, v0, $02
801D1D28	addu   v0, v0, a0
801D1D2C	sll    v0, v0, $02
801D1D30	lui    v1, $801e
801D1D34	addiu  v1, v1, $3864
801D1D38	jr     ra 
801D1D3C	addu   v0, v0, v1


func1d1d40:	; 801D1D40
801D1D40	addiu  sp, sp, $ff90 (=-$70)
801D1D44	sw     s2, $0060(sp)
801D1D48	addu   s2, a0, zero
801D1D4C	ori    v0, zero, $0280
801D1D50	lui    at, $801f
801D1D54	sw     v0, $8f40(at)
801D1D58	andi   v0, s2, $0010
801D1D5C	sw     ra, $0068(sp)
801D1D60	sw     s3, $0064(sp)
801D1D64	sw     s1, $005c(sp)
801D1D68	beq    v0, zero, L1d1d98 [$801d1d98]
801D1D6C	sw     s0, $0058(sp)
801D1D70	andi   v0, s2, $000f
A2 = w[801e2c78 + V0 * 4];
801D1D88	lui    a1, $801d
801D1D8C	addiu  a1, a1, $018c
801D1D90	j      L1d1dbc [$801d1dbc]
801D1D94	addiu  a0, sp, $0038

L1d1d98:	; 801D1D98
801D1D98	addiu  a0, sp, $0038
801D1D9C	andi   v0, s2, $000f
A2 = w[801e2c78 + V0 * 4];
801D1DB4	lui    a1, $801d
801D1DB8	addiu  a1, a1, $0194

L1d1dbc:	; 801D1DBC
801D1DBC	jal    $80042dd8
801D1DC0	nop
801D1DC4	addiu  a0, sp, $0038
801D1DC8	jal    $80042b20
801D1DCC	ori    a1, zero, $0001
801D1DD0	addu   s1, v0, zero
801D1DD4	addiu  v0, zero, $ffff (=-$1)
801D1DD8	bne    s1, v0, L1d1de8 [$801d1de8]
801D1DDC	ori    s0, zero, $001e
801D1DE0	j      L1d1f20 [$801d1f20]
801D1DE4	ori    v0, zero, $0001

L1d1de8:	; 801D1DE8
801D1DE8	addiu  s3, zero, $ffff (=-$1)

loop1d1dec:	; 801D1DEC
801D1DEC	lui    a2, $801f
801D1DF0	lw     a2, $8f40(a2)
801D1DF4	lui    a1, $801e
801D1DF8	addiu  a1, a1, $6f38
801D1DFC	jal    $80042b30
801D1E00	addu   a0, s1, zero
801D1E04	lui    v1, $801f
801D1E08	lw     v1, $8f40(v1)
801D1E0C	nop
801D1E10	beq    v0, v1, L1d1e44 [$801d1e44]
801D1E14	nop
801D1E18	beq    v0, s3, L1d1e2c [$801d1e2c]
801D1E1C	addiu  s0, s0, $ffff (=-$1)
801D1E20	subu   v0, v1, v0
801D1E24	lui    at, $801f
801D1E28	sw     v0, $8f40(at)

L1d1e2c:	; 801D1E2C
801D1E2C	bne    s0, zero, loop1d1dec [$801d1dec]
801D1E30	nop
801D1E34	jal    $80042b50
801D1E38	addu   a0, s1, zero
801D1E3C	j      L1d1f20 [$801d1f20]
801D1E40	ori    v0, zero, $0002

L1d1e44:	; 801D1E44
801D1E44	jal    $80042b50
801D1E48	addu   a0, s1, zero
801D1E4C	andi   v1, s2, $000f
801D1E50	lui    a0, $801e
801D1E54	addiu  a0, a0, $3864
801D1E58	sll    v0, v1, $02
801D1E5C	addu   v0, v0, v1
801D1E60	sll    v0, v0, $02
801D1E64	addu   v0, v0, v1
801D1E68	sll    v0, v0, $02
801D1E6C	addu   a3, v0, a0
801D1E70	lui    a2, $801e
801D1E74	addiu  a2, a2, $7138
801D1E78	or     v0, a3, a2
801D1E7C	andi   v0, v0, $0003
801D1E80	beq    v0, zero, L1d1edc [$801d1edc]
801D1E84	addiu  t0, a2, $0050

loop1d1e88:	; 801D1E88
801D1E88	lwl    v0, $0003(a2)
801D1E8C	lwr    v0, $0000(a2)
801D1E90	lwl    v1, $0007(a2)
801D1E94	lwr    v1, $0004(a2)
801D1E98	lwl    a0, $000b(a2)
801D1E9C	lwr    a0, $0008(a2)
801D1EA0	lwl    a1, $000f(a2)
801D1EA4	lwr    a1, $000c(a2)
801D1EA8	swl    v0, $0003(a3)
801D1EAC	swr    v0, $0000(a3)
801D1EB0	swl    v1, $0007(a3)
801D1EB4	swr    v1, $0004(a3)
801D1EB8	swl    a0, $000b(a3)
801D1EBC	swr    a0, $0008(a3)
801D1EC0	swl    a1, $000f(a3)
801D1EC4	swr    a1, $000c(a3)
801D1EC8	addiu  a2, a2, $0010
801D1ECC	bne    a2, t0, loop1d1e88 [$801d1e88]
801D1ED0	addiu  a3, a3, $0010
801D1ED4	j      L1d1f08 [$801d1f08]
801D1ED8	nop

L1d1edc:	; 801D1EDC
801D1EDC	lw     v0, $0000(a2)
801D1EE0	lw     v1, $0004(a2)
801D1EE4	lw     a0, $0008(a2)
801D1EE8	lw     a1, $000c(a2)
801D1EEC	sw     v0, $0000(a3)
801D1EF0	sw     v1, $0004(a3)
801D1EF4	sw     a0, $0008(a3)
801D1EF8	sw     a1, $000c(a3)
801D1EFC	addiu  a2, a2, $0010
801D1F00	bne    a2, t0, L1d1edc [$801d1edc]
801D1F04	addiu  a3, a3, $0010

L1d1f08:	; 801D1F08
801D1F08	lwl    v0, $0003(a2)
801D1F0C	lwr    v0, $0000(a2)
801D1F10	nop
801D1F14	swl    v0, $0003(a3)
801D1F18	swr    v0, $0000(a3)
801D1F1C	addu   v0, zero, zero

L1d1f20:	; 801D1F20
801D1F20	lw     ra, $0068(sp)
801D1F24	lw     s3, $0064(sp)
801D1F28	lw     s2, $0060(sp)
801D1F2C	lw     s1, $005c(sp)
801D1F30	lw     s0, $0058(sp)
801D1F34	addiu  sp, sp, $0070
801D1F38	jr     ra 
801D1F3C	nop


func1d1f40:	; 801D1F40
801D1F40	addiu  sp, sp, $ff98 (=-$68)
801D1F44	addu   v1, a0, zero
801D1F48	ori    v0, zero, $2000
801D1F4C	lui    at, $801f
801D1F50	sw     v0, $8f40(at)
801D1F54	andi   v0, v1, $0010
801D1F58	sw     ra, $0064(sp)
801D1F5C	sw     s2, $0060(sp)
801D1F60	sw     s1, $005c(sp)
801D1F64	beq    v0, zero, L1d1f94 [$801d1f94]
801D1F68	sw     s0, $0058(sp)
801D1F6C	andi   v0, v1, $000f
A2 = w[801e2c78 + V0 * 4];
801D1F84	lui    a1, $801d
801D1F88	addiu  a1, a1, $018c
801D1F8C	j      L1d1fb8 [$801d1fb8]
801D1F90	addiu  a0, sp, $0038

L1d1f94:	; 801D1F94
801D1F94	addiu  a0, sp, $0038
801D1F98	andi   v0, v1, $000f
A2 = w[801e2c78 + V0 * 4];
801D1FB0	lui    a1, $801d
801D1FB4	addiu  a1, a1, $0194

L1d1fb8:	; 801D1FB8
801D1FB8	jal    $80042dd8
801D1FBC	nop
801D1FC0	addiu  a0, sp, $0038
801D1FC4	jal    $80042b20
801D1FC8	ori    a1, zero, $0001
801D1FCC	addu   s0, v0, zero
801D1FD0	addiu  v0, zero, $ffff (=-$1)
801D1FD4	bne    s0, v0, L1d1fe4 [$801d1fe4]
801D1FD8	ori    s1, zero, $001e
801D1FDC	j      L1d2134 [$801d2134]
801D1FE0	ori    v0, zero, $0001

L1d1fe4:	; 801D1FE4
801D1FE4	addiu  s2, zero, $ffff (=-$1)

loop1d1fe8:	; 801D1FE8
801D1FE8	lui    a2, $801f
801D1FEC	lw     a2, $8f40(a2)
801D1FF0	lui    a1, $801e
801D1FF4	addiu  a1, a1, $6f38
801D1FF8	jal    $80042b30
801D1FFC	addu   a0, s0, zero
801D2000	lui    a0, $801f
801D2004	lw     a0, $8f40(a0)
801D2008	addu   v1, v0, zero
801D200C	beq    v1, a0, L1d2040 [$801d2040]
801D2010	nop
801D2014	beq    v1, s2, L1d2028 [$801d2028]
801D2018	addiu  s1, s1, $0001
801D201C	subu   v0, a0, v1
801D2020	lui    at, $801f
801D2024	sw     v0, $8f40(at)

L1d2028:	; 801D2028
801D2028	bne    s1, zero, loop1d1fe8 [$801d1fe8]
801D202C	nop
801D2030	jal    $80042b50
801D2034	addu   a0, s0, zero
801D2038	j      L1d2134 [$801d2134]
801D203C	ori    v0, zero, $0002

L1d2040:	; 801D2040
801D2040	jal    $80042b50
801D2044	addu   a0, s0, zero
801D2048	lui    a3, $800a
801D204C	addiu  a3, a3, $c6e4 (=-$391c)
801D2050	lui    a2, $801e
801D2054	addiu  a2, a2, $7138
801D2058	or     v0, a2, a3
801D205C	andi   v0, v0, $0003
801D2060	beq    v0, zero, L1d20bc [$801d20bc]
801D2064	addiu  t0, a2, $10f0

loop1d2068:	; 801D2068
801D2068	lwl    v0, $0003(a2)
801D206C	lwr    v0, $0000(a2)
801D2070	lwl    v1, $0007(a2)
801D2074	lwr    v1, $0004(a2)
801D2078	lwl    a0, $000b(a2)
801D207C	lwr    a0, $0008(a2)
801D2080	lwl    a1, $000f(a2)
801D2084	lwr    a1, $000c(a2)
801D2088	swl    v0, $0003(a3)
801D208C	swr    v0, $0000(a3)
801D2090	swl    v1, $0007(a3)
801D2094	swr    v1, $0004(a3)
801D2098	swl    a0, $000b(a3)
801D209C	swr    a0, $0008(a3)
801D20A0	swl    a1, $000f(a3)
801D20A4	swr    a1, $000c(a3)
801D20A8	addiu  a2, a2, $0010
801D20AC	bne    a2, t0, loop1d2068 [$801d2068]
801D20B0	addiu  a3, a3, $0010
801D20B4	j      L1d20e8 [$801d20e8]
801D20B8	nop

L1d20bc:	; 801D20BC
801D20BC	lw     v0, $0000(a2)
801D20C0	lw     v1, $0004(a2)
801D20C4	lw     a0, $0008(a2)
801D20C8	lw     a1, $000c(a2)
801D20CC	sw     v0, $0000(a3)
801D20D0	sw     v1, $0004(a3)
801D20D4	sw     a0, $0008(a3)
801D20D8	sw     a1, $000c(a3)
801D20DC	addiu  a2, a2, $0010
801D20E0	bne    a2, t0, L1d20bc [$801d20bc]
801D20E4	addiu  a3, a3, $0010

L1d20e8:	; 801D20E8
801D20E8	lwl    v0, $0003(a2)
801D20EC	lwr    v0, $0000(a2)
801D20F0	nop
801D20F4	swl    v0, $0003(a3)
801D20F8	swr    v0, $0000(a3)
801D20FC	addu   v1, zero, zero

loop1d2100:	; 801D2100
801D2100	lui    at, $800a
801D2104	addiu  at, at, $c72c (=-$38d4)
801D2108	addu   at, at, v1
801D210C	lbu    v0, $0000(at)
801D2110	nop
801D2114	lui    at, $8005
801D2118	addiu  at, at, $9208 (=-$6df8)
801D211C	addu   at, at, v1
801D2120	sb     v0, $0000(at)
801D2124	addiu  v1, v1, $0001
801D2128	slti   v0, v1, $000c
801D212C	bne    v0, zero, loop1d2100 [$801d2100]
801D2130	addu   v0, zero, zero

L1d2134:	; 801D2134
801D2134	lw     ra, $0064(sp)
801D2138	lw     s2, $0060(sp)
801D213C	lw     s1, $005c(sp)
801D2140	lw     s0, $0058(sp)
801D2144	addiu  sp, sp, $0068
801D2148	jr     ra 
801D214C	nop

801D2150	addiu  v0, a0, $0067
801D2154	andi   v0, v0, $00ff
801D2158	sltiu  v0, v0, $0007
801D215C	bne    v0, zero, L1d217c [$801d217c]
801D2160	ori    v0, zero, $0001
801D2164	addiu  v0, a0, $001f
801D2168	andi   v0, v0, $00ff
801D216C	sltiu  v0, v0, $001c
801D2170	bne    v0, zero, L1d217c [$801d217c]
801D2174	ori    v0, zero, $0001
801D2178	addu   v0, zero, zero

L1d217c:	; 801D217C
801D217C	jr     ra 
801D2180	nop

801D2184	addiu  v0, a0, $007f
801D2188	andi   v0, v0, $00ff
801D218C	sltiu  v0, v0, $001f
801D2190	bne    v0, zero, L1d21b0 [$801d21b0]
801D2194	ori    v0, zero, $0001
801D2198	addiu  v0, a0, $0020
801D219C	andi   v0, v0, $00ff
801D21A0	sltiu  v0, v0, $001d
801D21A4	bne    v0, zero, L1d21b0 [$801d21b0]
801D21A8	ori    v0, zero, $0001
801D21AC	addu   v0, zero, zero

L1d21b0:	; 801D21B0
801D21B0	jr     ra 
801D21B4	nop


func1d21b8:	; 801D21B8
801D21B8	addu   v1, zero, zero

loop1d21bc:	; 801D21BC
801D21BC	lbu    v0, $0000(a1)
801D21C0	addiu  a1, a1, $0001
801D21C4	addiu  v1, v1, $0001
801D21C8	sb     v0, $0000(a0)
801D21CC	slti   v0, v1, $0040
801D21D0	bne    v0, zero, loop1d21bc [$801d21bc]
801D21D4	addiu  a0, a0, $0001
801D21D8	jr     ra 
801D21DC	nop


func1d21e0:	; 801D21E0
801D21E0	lui    at, $801e
801D21E4	sw     a0, $2cb4(at)
801D21E8	jr     ra 
801D21EC	nop


func1d21f0:	; 801D21F0
801D21F0	addiu  sp, sp, $fff8 (=-$8)
801D21F4	lui    v0, $801e
801D21F8	lw     v0, $2cb4(v0)
801D21FC	nop
801D2200	blez   v0, L1d2240 [$801d2240]
801D2204	addu   v1, zero, zero
801D2208	ori    a2, zero, $00ff

loop1d220c:	; 801D220C
801D220C	lbu    v0, $0000(a1)
801D2210	nop
801D2214	sb     v0, $0000(a0)
801D2218	lbu    v0, $0000(a1)
801D221C	nop
801D2220	beq    v0, a2, L1d2240 [$801d2240]
801D2224	addiu  a0, a0, $0001
801D2228	lui    v0, $801e
801D222C	lw     v0, $2cb4(v0)
801D2230	addiu  v1, v1, $0001
801D2234	slt    v0, v1, v0
801D2238	bne    v0, zero, loop1d220c [$801d220c]
801D223C	addiu  a1, a1, $0001

L1d2240:	; 801D2240
801D2240	addiu  sp, sp, $0008
801D2244	jr     ra 
801D2248	nop


func1d224c:	; 801D224C
801D224C	addiu  sp, sp, $ffe0 (=-$20)
801D2250	addu   v1, zero, zero
801D2254	sw     ra, $0018(sp)
801D2258	sw     s1, $0014(sp)
801D225C	sw     s0, $0010(sp)

loop1d2260:	; 801D2260
801D2260	lui    at, $800a
801D2264	addiu  at, at, $cbdc (=-$3424)
801D2268	addu   at, at, v1
801D226C	lbu    v0, $0000(at)
801D2270	nop
801D2274	lui    at, $800a
801D2278	addiu  at, at, $c6e9 (=-$3917)
801D227C	addu   at, at, v1
801D2280	sb     v0, $0000(at)
801D2284	addiu  v1, v1, $0001
801D2288	slti   v0, v1, $0003
801D228C	bne    v0, zero, loop1d2260 [$801d2260]
801D2290	nop
801D2294	jal    func1d21e0 [$801d21e0]
801D2298	ori    a0, zero, $0010
801D229C	addu   v1, zero, zero
801D22A0	lui    a0, $800a
801D22A4	addiu  a0, a0, $c6ec (=-$3914)
801D22A8	addu   s1, zero, zero

loop1d22ac:	; 801D22AC
801D22AC	lui    at, $800a
801D22B0	addiu  at, at, $cbdc (=-$3424)
801D22B4	addu   at, at, v1
801D22B8	lbu    a1, $0000(at)
801D22BC	ori    v0, zero, $00ff
801D22C0	beq    a1, v0, L1d2370 [$801d2370]
801D22C4	sll    s0, a1, $05
801D22C8	addu   s0, s0, a1
801D22CC	sll    s0, s0, $02
801D22D0	addiu  a1, a0, $005c
801D22D4	jal    func1d21f0 [$801d21f0]
801D22D8	addu   a1, s0, a1
801D22DC	lui    at, $800a
801D22E0	addiu  at, at, $c739 (=-$38c7)
801D22E4	addu   at, at, s0
801D22E8	lbu    v0, $0000(at)
801D22EC	nop
801D22F0	lui    at, $800a
801D22F4	sb     v0, $c6e8(at)
801D22F8	lui    at, $800a
801D22FC	addiu  at, at, $d85c (=-$27a4)
801D2300	addu   at, at, s1
801D2304	lhu    v0, $0000(at)
801D2308	nop
801D230C	lui    at, $800a
801D2310	sh     v0, $c6fc(at)
801D2314	lui    at, $800a
801D2318	addiu  at, at, $d85e (=-$27a2)
801D231C	addu   at, at, s1
801D2320	lhu    v0, $0000(at)
801D2324	nop
801D2328	lui    at, $800a
801D232C	sh     v0, $c6fe(at)
801D2330	lui    at, $800a
801D2334	addiu  at, at, $d860 (=-$27a0)
801D2338	addu   at, at, s1
801D233C	lhu    v0, $0000(at)
801D2340	nop
801D2344	lui    at, $800a
801D2348	sh     v0, $c700(at)
801D234C	lui    at, $800a
801D2350	addiu  at, at, $d862 (=-$279e)
801D2354	addu   at, at, s1
801D2358	lhu    v0, $0000(at)
801D235C	nop
801D2360	lui    at, $800a
801D2364	sh     v0, $c702(at)
801D2368	j      L1d2384 [$801d2384]
801D236C	addu   v1, zero, zero

L1d2370:	; 801D2370
801D2370	addiu  v1, v1, $0001
801D2374	slti   v0, v1, $0003
801D2378	bne    v0, zero, loop1d22ac [$801d22ac]
801D237C	addiu  s1, s1, $0440
801D2380	addu   v1, zero, zero

L1d2384:	; 801D2384
801D2384	lui    at, $8005
801D2388	addiu  at, at, $9208 (=-$6df8)
801D238C	addu   at, at, v1
801D2390	lbu    v0, $0000(at)
801D2394	nop
801D2398	lui    at, $800a
801D239C	addiu  at, at, $c72c (=-$38d4)
801D23A0	addu   at, at, v1
801D23A4	sb     v0, $0000(at)
801D23A8	addiu  v1, v1, $0001
801D23AC	slti   v0, v1, $000c
801D23B0	bne    v0, zero, L1d2384 [$801d2384]
801D23B4	nop
801D23B8	lui    v0, $800a
801D23BC	lw     v0, $d260(v0)
801D23C0	lui    v1, $800a
801D23C4	lw     v1, $d264(v1)
801D23C8	lui    s0, $800a
801D23CC	addiu  s0, s0, $c704 (=-$38fc)
801D23D0	sw     v0, $0000(s0)
801D23D4	lui    at, $800a
801D23D8	sw     v1, $c708(at)
801D23DC	jal    func1d21e0 [$801d21e0]
801D23E0	ori    a0, zero, $0018
801D23E4	addiu  a0, s0, $0008
801D23E8	jal    func1d21f0 [$801d21f0]
801D23EC	addiu  a1, s0, $0eec
801D23F0	lw     ra, $0018(sp)
801D23F4	lw     s1, $0014(sp)
801D23F8	lw     s0, $0010(sp)
801D23FC	addiu  sp, sp, $0020
801D2400	jr     ra 
801D2404	nop


func1d2408:	; 801D2408
801D2408	addiu  sp, sp, $fdd8 (=-$228)
801D240C	sw     s3, $021c(sp)
801D2410	addu   s3, a0, zero
801D2414	sw     s1, $0214(sp)
801D2418	addu   s1, a1, zero
801D241C	sw     ra, $0220(sp)
801D2420	sw     s2, $0218(sp)
801D2424	jal    func1d224c [$801d224c]
801D2428	sw     s0, $0210(sp)
801D242C	lui    s0, $801e
801D2430	addiu  s0, s0, $6d38
801D2434	addiu  a0, s0, $0004
801D2438	ori    v0, zero, $2000
801D243C	lui    at, $801f
801D2440	sw     v0, $8f40(at)
801D2444	ori    v0, zero, $0053
801D2448	sb     v0, $0000(s0)
801D244C	ori    v0, zero, $0043
801D2450	lui    at, $801e
801D2454	sb     v0, $6d39(at)
801D2458	ori    v0, zero, $0011
801D245C	lui    at, $801e
801D2460	sb     v0, $6d3a(at)
801D2464	ori    v0, zero, $0001
801D2468	lui    at, $801e
801D246C	sb     v0, $6d3b(at)
801D2470	jal    func1d21b8 [$801d21b8]
801D2474	addu   a1, s1, zero
801D2478	ori    v0, zero, $001b
801D247C	addiu  s0, s0, $005f

loop1d2480:	; 801D2480
801D2480	sb     zero, $0000(s0)
801D2484	addiu  v0, v0, $ffff (=-$1)
801D2488	bgez   v0, loop1d2480 [$801d2480]
801D248C	addiu  s0, s0, $ffff (=-$1)
801D2490	lui    s0, $800a
801D2494	addiu  s0, s0, $c708 (=-$38f8)
801D2498	lw     a0, $0000(s0)
801D249C	jal    $80023788
801D24A0	nop
801D24A4	andi   v0, v0, $00ff
801D24A8	lui    s1, $cccc
801D24AC	ori    s1, s1, $cccd
801D24B0	multu  v0, s1
801D24B4	lw     a0, $0000(s0)
801D24B8	mfhi   t2
801D24BC	srl    a1, t2, $03
801D24C0	andi   v1, a1, $00ff
801D24C4	sll    v1, v1, $01
801D24C8	addiu  a2, v1, $0020
801D24CC	andi   a2, a2, $00ff
801D24D0	lui    at, $801e
801D24D4	addiu  at, at, $ef08 (=-$10f8)
801D24D8	addu   at, at, a2
801D24DC	lbu    v1, $0000(at)
801D24E0	lui    s0, $801e
801D24E4	addiu  s0, s0, $6d52
801D24E8	sb     v1, $0000(s0)
801D24EC	sll    v1, a1, $02
801D24F0	addu   v1, v1, a1
801D24F4	sll    v1, v1, $01
801D24F8	subu   v0, v0, v1
801D24FC	andi   v0, v0, $00ff
801D2500	sll    v0, v0, $01
801D2504	lui    at, $801e
801D2508	addiu  at, at, $ef09 (=-$10f7)
801D250C	addu   at, at, a2
801D2510	lbu    v1, $0000(at)
801D2514	addiu  a2, v0, $0020
801D2518	lui    at, $801e
801D251C	sb     v1, $6d53(at)
801D2520	andi   v1, a2, $00ff
801D2524	lui    at, $801e
801D2528	addiu  at, at, $ef08 (=-$10f8)
801D252C	addu   at, at, v1
801D2530	lbu    v0, $0000(at)
801D2534	nop
801D2538	lui    at, $801e
801D253C	sb     v0, $6d54(at)
801D2540	lui    at, $801e
801D2544	addiu  at, at, $ef09 (=-$10f7)
801D2548	addu   at, at, v1
801D254C	lbu    v0, $0000(at)
801D2550	nop
801D2554	lui    at, $801e
801D2558	sb     v0, $6d55(at)
801D255C	jal    $8002382c
801D2560	addiu  s0, s0, $0066
801D2564	andi   v0, v0, $00ff
801D2568	multu  v0, s1
801D256C	lui    t0, $801e
801D2570	addiu  t0, t0, $f120 (=-$ee0)
801D2574	lui    a0, $801e
801D2578	lw     a0, $3d50(a0)
801D257C	mfhi   t2
801D2580	srl    a1, t2, $03
801D2584	andi   v1, a1, $00ff
801D2588	sll    v1, v1, $01
801D258C	addiu  a2, v1, $0020
801D2590	andi   a3, a2, $00ff
801D2594	addiu  a2, t0, $002c
801D2598	sll    v1, a0, $07
801D259C	subu   v1, v1, a0
801D25A0	sll    v1, v1, $02
801D25A4	subu   v1, v1, a0
801D25A8	sll    v1, v1, $01
801D25AC	addu   t1, v1, a2
801D25B0	sll    v1, a1, $02
801D25B4	addu   v1, v1, a1
801D25B8	sll    v1, v1, $01
801D25BC	subu   v0, v0, v1
801D25C0	andi   v0, v0, $00ff
801D25C4	lui    at, $801e
801D25C8	addiu  at, at, $ef08 (=-$10f8)
801D25CC	addu   at, at, a3
801D25D0	lbu    a0, $0000(at)
801D25D4	sll    v0, v0, $01
801D25D8	lui    at, $801e
801D25DC	sb     a0, $6d58(at)
801D25E0	lui    at, $801e
801D25E4	addiu  at, at, $ef09 (=-$10f7)
801D25E8	addu   at, at, a3
801D25EC	lbu    v1, $0000(at)
801D25F0	addiu  a2, v0, $0020
801D25F4	lui    at, $801e
801D25F8	sb     v1, $6d59(at)
801D25FC	andi   v1, a2, $00ff
801D2600	lui    at, $801e
801D2604	addiu  at, at, $ef08 (=-$10f8)
801D2608	addu   at, at, v1
801D260C	lbu    v0, $0000(at)
801D2610	or     a0, t1, s0
801D2614	lui    at, $801e
801D2618	sb     v0, $6d5a(at)
801D261C	lui    at, $801e

L1d2620:	; 801D2620
801D2620	addiu  at, at, $ef09 (=-$10f7)
801D2624	addu   at, at, v1
801D2628	lbu    v0, $0000(at)
801D262C	lui    v1, $801e
801D2630	lw     v1, $3d50(v1)
801D2634	andi   a0, a0, $0003
801D2638	lui    at, $801e
801D263C	sb     v0, $6d5b(at)
801D2640	sll    v0, v1, $07
801D2644	subu   v0, v0, v1
801D2648	sll    v0, v0, $02
801D264C	subu   v0, v0, v1
801D2650	sll    v0, v0, $01
801D2654	addu   v0, v0, t0
801D2658	lui    a3, $801e
801D265C	addiu  a3, a3, $6d98
801D2660	lwl    v1, $0003(v0)
801D2664	lwr    v1, $0000(v0)
801D2668	lwl    a1, $0007(v0)
801D266C	lwr    a1, $0004(v0)
801D2670	lwl    a2, $000b(v0)
801D2674	lwr    a2, $0008(v0)
801D2678	swl    v1, $0003(a3)
801D267C	swr    v1, $0000(a3)
801D2680	swl    a1, $0007(a3)
801D2684	swr    a1, $0004(a3)
801D2688	swl    a2, $000b(a3)
801D268C	swr    a2, $0008(a3)
801D2690	lwl    v1, $000f(v0)
801D2694	lwr    v1, $000c(v0)
801D2698	lwl    a1, $0013(v0)
801D269C	lwr    a1, $0010(v0)
801D26A0	lwl    a2, $0017(v0)
801D26A4	lwr    a2, $0014(v0)
801D26A8	swl    v1, $000f(a3)
801D26AC	swr    v1, $000c(a3)
801D26B0	swl    a1, $0013(a3)
801D26B4	swr    a1, $0010(a3)
801D26B8	swl    a2, $0017(a3)
801D26BC	swr    a2, $0014(a3)
801D26C0	lwl    v1, $001b(v0)
801D26C4	lwr    v1, $0018(v0)
801D26C8	lwl    a1, $001f(v0)
801D26CC	lwr    a1, $001c(v0)
801D26D0	swl    v1, $001b(a3)
801D26D4	swr    v1, $0018(a3)
801D26D8	swl    a1, $001f(a3)
801D26DC	swr    a1, $001c(a3)
801D26E0	beq    a0, zero, L1d273c [$801d273c]
801D26E4	addiu  a2, t1, $0080

loop1d26e8:	; 801D26E8
801D26E8	lwl    v0, $0003(t1)
801D26EC	lwr    v0, $0000(t1)
801D26F0	lwl    v1, $0007(t1)
801D26F4	lwr    v1, $0004(t1)
801D26F8	lwl    a0, $000b(t1)
801D26FC	lwr    a0, $0008(t1)
801D2700	lwl    a1, $000f(t1)
801D2704	lwr    a1, $000c(t1)
801D2708	swl    v0, $0003(s0)
801D270C	swr    v0, $0000(s0)
801D2710	swl    v1, $0007(s0)
801D2714	swr    v1, $0004(s0)
801D2718	swl    a0, $000b(s0)
801D271C	swr    a0, $0008(s0)
801D2720	swl    a1, $000f(s0)
801D2724	swr    a1, $000c(s0)
801D2728	addiu  t1, t1, $0010
801D272C	bne    t1, a2, loop1d26e8 [$801d26e8]
801D2730	addiu  s0, s0, $0010
801D2734	j      L1d2768 [$801d2768]
801D2738	nop

L1d273c:	; 801D273C
801D273C	lw     v0, $0000(t1)
801D2740	lw     v1, $0004(t1)
801D2744	lw     a0, $0008(t1)
801D2748	lw     a1, $000c(t1)
801D274C	sw     v0, $0000(s0)
801D2750	sw     v1, $0004(s0)
801D2754	sw     a0, $0008(s0)
801D2758	sw     a1, $000c(s0)
801D275C	addiu  t1, t1, $0010
801D2760	bne    t1, a2, L1d273c [$801d273c]
801D2764	addiu  s0, s0, $0010

L1d2768:	; 801D2768
801D2768	lui    a3, $801e
801D276C	addiu  a3, a3, $6f38
801D2770	lui    a2, $801e
801D2774	addiu  a2, a2, $6d38
801D2778	or     v0, a2, a3
801D277C	andi   v0, v0, $0003
801D2780	beq    v0, zero, L1d27dc [$801d27dc]
801D2784	addiu  t0, a2, $0200

loop1d2788:	; 801D2788
801D2788	lwl    v0, $0003(a2)
801D278C	lwr    v0, $0000(a2)
801D2790	lwl    v1, $0007(a2)
801D2794	lwr    v1, $0004(a2)
801D2798	lwl    a0, $000b(a2)
801D279C	lwr    a0, $0008(a2)
801D27A0	lwl    a1, $000f(a2)
801D27A4	lwr    a1, $000c(a2)
801D27A8	swl    v0, $0003(a3)
801D27AC	swr    v0, $0000(a3)
801D27B0	swl    v1, $0007(a3)
801D27B4	swr    v1, $0004(a3)
801D27B8	swl    a0, $000b(a3)
801D27BC	swr    a0, $0008(a3)
801D27C0	swl    a1, $000f(a3)
801D27C4	swr    a1, $000c(a3)
801D27C8	addiu  a2, a2, $0010
801D27CC	bne    a2, t0, loop1d2788 [$801d2788]
801D27D0	addiu  a3, a3, $0010
801D27D4	j      L1d280c [$801d280c]
801D27D8	ori    a0, zero, $10f0

L1d27dc:	; 801D27DC
801D27DC	lw     v0, $0000(a2)
801D27E0	lw     v1, $0004(a2)
801D27E4	lw     a0, $0008(a2)
801D27E8	lw     a1, $000c(a2)
801D27EC	sw     v0, $0000(a3)
801D27F0	sw     v1, $0004(a3)
801D27F4	sw     a0, $0008(a3)
801D27F8	sw     a1, $000c(a3)
801D27FC	addiu  a2, a2, $0010
801D2800	bne    a2, t0, L1d27dc [$801d27dc]
801D2804	addiu  a3, a3, $0010
801D2808	ori    a0, zero, $10f0

L1d280c:	; 801D280C
801D280C	lui    s0, $800a
801D2810	addiu  s0, s0, $c6e8 (=-$3918)
801D2814	addu   a1, s0, zero
801D2818	ori    v0, zero, $0001
801D281C	lui    at, $8006
801D2820	sb     v0, $2d99(at)
801D2824	jal    func1d1950 [$801d1950]
801D2828	nop
801D282C	lui    a3, $801e
801D2830	addiu  a3, a3, $7138
801D2834	addiu  a2, s0, $fffc (=-$4)
801D2838	or     v1, a2, a3
801D283C	andi   v1, v1, $0003
801D2840	andi   v0, v0, $ffff
801D2844	beq    v1, zero, L1d28bc [$801d28bc]
801D2848	sw     v0, $fffc(s0)
801D284C	addiu  t0, s0, $10ec

loop1d2850:	; 801D2850
801D2850	lwl    v0, $0003(a2)
801D2854	lwr    v0, $0000(a2)
801D2858	lwl    v1, $0007(a2)
801D285C	lwr    v1, $0004(a2)
801D2860	lwl    a0, $000b(a2)
801D2864	lwr    a0, $0008(a2)
801D2868	lwl    a1, $000f(a2)
801D286C	lwr    a1, $000c(a2)
801D2870	swl    v0, $0003(a3)
801D2874	swr    v0, $0000(a3)
801D2878	swl    v1, $0007(a3)
801D287C	swr    v1, $0004(a3)
801D2880	swl    a0, $000b(a3)
801D2884	swr    a0, $0008(a3)
801D2888	swl    a1, $000f(a3)
801D288C	swr    a1, $000c(a3)
801D2890	addiu  a2, a2, $0010
801D2894	bne    a2, t0, loop1d2850 [$801d2850]
801D2898	addiu  a3, a3, $0010
801D289C	j      L1d28ec [$801d28ec]
801D28A0	nop

loop1d28a4:	; 801D28A4
801D28A4	jal    $80042b90
801D28A8	addu   a0, s3, zero
801D28AC	jal    $80042b50
801D28B0	addu   a0, s0, zero
801D28B4	j      L1d2938 [$801d2938]
801D28B8	ori    s1, zero, $001e

L1d28bc:	; 801D28BC
801D28BC	addiu  t0, s0, $10ec

loop1d28c0:	; 801D28C0
801D28C0	lw     v0, $0000(a2)
801D28C4	lw     v1, $0004(a2)
801D28C8	lw     a0, $0008(a2)
801D28CC	lw     a1, $000c(a2)
801D28D0	sw     v0, $0000(a3)
801D28D4	sw     v1, $0004(a3)
801D28D8	sw     a0, $0008(a3)
801D28DC	sw     a1, $000c(a3)
801D28E0	addiu  a2, a2, $0010
801D28E4	bne    a2, t0, loop1d28c0 [$801d28c0]
801D28E8	addiu  a3, a3, $0010

L1d28ec:	; 801D28EC
801D28EC	lwl    v0, $0003(a2)
801D28F0	lwr    v0, $0000(a2)
801D28F4	nop
801D28F8	swl    v0, $0003(a3)
801D28FC	swr    v0, $0000(a3)
801D2900	lui    at, $8006
801D2904	sb     zero, $2d99(at)
801D2908	addu   s1, zero, zero
801D290C	addiu  s2, zero, $ffff (=-$1)
801D2910	addu   a0, s3, zero

loop1d2914:	; 801D2914
801D2914	jal    $80042b20
801D2918	ori    a1, zero, $0001
801D291C	addu   s0, v0, zero
801D2920	bne    s0, s2, loop1d28a4 [$801d28a4]
801D2924	addiu  s1, s1, $0001
801D2928	slti   v0, s1, $000a
801D292C	bne    v0, zero, loop1d2914 [$801d2914]
801D2930	addu   a0, s3, zero
801D2934	ori    s1, zero, $001e

L1d2938:	; 801D2938
801D2938	addiu  s2, zero, $ffff (=-$1)

loop1d293c:	; 801D293C
801D293C	lui    a1, $801e
801D2940	lbu    a1, $6d3b(a1)
801D2944	addu   a0, s3, zero
801D2948	sll    a1, a1, $10
801D294C	jal    $80042b20
801D2950	ori    a1, a1, $0200
801D2954	addu   s0, v0, zero
801D2958	bne    s0, s2, L1d2970 [$801d2970]
801D295C	addiu  s1, s1, $ffff (=-$1)
801D2960	bne    s1, zero, loop1d293c [$801d293c]
801D2964	ori    v0, zero, $0001
801D2968	j      L1d2a14 [$801d2a14]
801D296C	nop

L1d2970:	; 801D2970
801D2970	jal    $80042b50
801D2974	addu   a0, s0, zero
801D2978	ori    s1, zero, $001e
801D297C	addiu  s2, zero, $ffff (=-$1)
801D2980	addu   a0, s3, zero

loop1d2984:	; 801D2984
801D2984	jal    $80042b20
801D2988	ori    a1, zero, $0002
801D298C	addu   s0, v0, zero
801D2990	bne    s0, s2, L1d29a8 [$801d29a8]
801D2994	addiu  s1, s1, $ffff (=-$1)
801D2998	bne    s1, zero, loop1d2984 [$801d2984]
801D299C	addu   a0, s3, zero
801D29A0	j      L1d2a14 [$801d2a14]
801D29A4	ori    v0, zero, $0002

L1d29a8:	; 801D29A8
801D29A8	ori    s1, zero, $001e
801D29AC	addiu  s2, zero, $ffff (=-$1)

loop1d29b0:	; 801D29B0
801D29B0	lui    a2, $801f
801D29B4	lw     a2, $8f40(a2)
801D29B8	lui    a1, $801e
801D29BC	addiu  a1, a1, $6f38
801D29C0	jal    $80042b40
801D29C4	addu   a0, s0, zero
801D29C8	lui    v1, $801f
801D29CC	lw     v1, $8f40(v1)
801D29D0	nop
801D29D4	beq    v0, v1, L1d2a08 [$801d2a08]
801D29D8	nop
801D29DC	beq    v0, s2, L1d29f0 [$801d29f0]
801D29E0	addiu  s1, s1, $ffff (=-$1)
801D29E4	subu   v0, v1, v0
801D29E8	lui    at, $801f
801D29EC	sw     v0, $8f40(at)

L1d29f0:	; 801D29F0
801D29F0	bne    s1, zero, loop1d29b0 [$801d29b0]
801D29F4	nop
801D29F8	jal    $80042b50
801D29FC	addu   a0, s0, zero
801D2A00	j      L1d2a14 [$801d2a14]
801D2A04	ori    v0, zero, $0003

L1d2a08:	; 801D2A08
801D2A08	jal    $80042b50
801D2A0C	addu   a0, s0, zero
801D2A10	addu   v0, zero, zero

L1d2a14:	; 801D2A14
801D2A14	lw     ra, $0220(sp)
801D2A18	lw     s3, $021c(sp)
801D2A1C	lw     s2, $0218(sp)
801D2A20	lw     s1, $0214(sp)
801D2A24	lw     s0, $0210(sp)
801D2A28	addiu  sp, sp, $0228
801D2A2C	jr     ra 
801D2A30	nop


func1d2a34:	; 801D2A34
801D2A34	addiu  sp, sp, $ffa0 (=-$60)
801D2A38	sw     s0, $0050(sp)
801D2A3C	addu   s0, a0, zero
801D2A40	andi   v0, s0, $0010
801D2A44	sw     ra, $0058(sp)
801D2A48	beq    v0, zero, L1d2a78 [$801d2a78]
801D2A4C	sw     s1, $0054(sp)
801D2A50	andi   v0, s0, $000f
A2 = w[801e2c78 + V0 * 4];
801D2A68	lui    a1, $801d
801D2A6C	addiu  a1, a1, $018c
801D2A70	j      L1d2a9c [$801d2a9c]
801D2A74	addiu  a0, sp, $0010

L1d2a78:	; 801D2A78
801D2A78	addiu  a0, sp, $0010
801D2A7C	andi   v0, s0, $000f
A2 = w[801e2c78 + V0 * 4];
801D2A94	lui    a1, $801d
801D2A98	addiu  a1, a1, $0194

L1d2a9c:	; 801D2A9C
801D2A9C	jal    $80042dd8
801D2AA0	andi   s0, s0, $000f
801D2AA4	sll    s1, s0, $02
801D2AA8	lui    at, $801e
801D2AAC	addiu  at, at, $2cb8
801D2AB0	addu   at, at, s1
801D2AB4	lw     a1, $0000(at)
801D2AB8	lui    at, $801e
801D2ABC	sw     s0, $3d50(at)
801D2AC0	jal    func1d2408 [$801d2408]
801D2AC4	addiu  a0, sp, $0010
801D2AC8	addu   t1, v0, zero
801D2ACC	sll    v0, t1, $10
801D2AD0	bne    v0, zero, L1d2b40 [$801d2b40]
801D2AD4	sra    v0, v0, $10
801D2AD8	lui    v1, $801e
801D2ADC	addiu  v1, v1, $3864
801D2AE0	addu   v0, s1, s0
801D2AE4	sll    v0, v0, $02
801D2AE8	addu   v0, v0, s0
801D2AEC	sll    v0, v0, $02
801D2AF0	addu   a3, v0, v1
801D2AF4	lui    a2, $800a
801D2AF8	addiu  a2, a2, $c6e4 (=-$391c)
801D2AFC	addiu  t0, a2, $0050

loop1d2b00:	; 801D2B00
801D2B00	lw     v0, $0000(a2)
801D2B04	lw     v1, $0004(a2)
801D2B08	lw     a0, $0008(a2)
801D2B0C	lw     a1, $000c(a2)
801D2B10	sw     v0, $0000(a3)
801D2B14	sw     v1, $0004(a3)
801D2B18	sw     a0, $0008(a3)
801D2B1C	sw     a1, $000c(a3)
801D2B20	addiu  a2, a2, $0010
801D2B24	bne    a2, t0, loop1d2b00 [$801d2b00]
801D2B28	addiu  a3, a3, $0010
801D2B2C	lw     v0, $0000(a2)
801D2B30	nop
801D2B34	sw     v0, $0000(a3)
801D2B38	sll    v0, t1, $10
801D2B3C	sra    v0, v0, $10

L1d2b40:	; 801D2B40
801D2B40	lw     ra, $0058(sp)
801D2B44	lw     s1, $0054(sp)
801D2B48	lw     s0, $0050(sp)
801D2B4C	addiu  sp, sp, $0060
801D2B50	jr     ra 
801D2B54	nop



////////////////////////////////
// func1d2b58
[8009a000] = h(30);
[8009a004] = w(A0 & ffff);
[8009a008] = w(A0 & ffff);
system_execute_AKAO;
////////////////////////////////



func1d2b98:	; 801D2B98
801D2B98	addiu  sp, sp, $ffd8 (=-$28)
801D2B9C	sw     s1, $001c(sp)
801D2BA0	addu   s1, a0, zero
801D2BA4	lui    v1, $8006
801D2BA8	lw     v1, $2f24(v1)
801D2BAC	ori    v0, zero, $0003
801D2BB0	sw     s0, $0018(sp)
801D2BB4	lui    s0, $8006
801D2BB8	addiu  s0, s0, $2f24
801D2BBC	sw     ra, $0020(sp)
801D2BC0	sb     v0, $0003(v1)
801D2BC4	lui    v1, $8006
801D2BC8	lw     v1, $2f24(v1)
801D2BCC	ori    v0, zero, $0060
801D2BD0	sb     v0, $0007(v1)

A0 = w[S0]; // packets here
A1 = 1; // add semi transparency
system_change_semi_transparency_in_packet;

801D2BE0	lui    v0, $8006
801D2BE4	lw     v0, $2f24(v0)
801D2BE8	nop
801D2BEC	sh     zero, $0008(v0)
801D2BF0	lui    v0, $8006
801D2BF4	lw     v0, $2f24(v0)
801D2BF8	nop
801D2BFC	sh     zero, $000a(v0)
801D2C00	lui    v1, $8006
801D2C04	lw     v1, $2f24(v1)
801D2C08	ori    v0, zero, $0180
801D2C0C	sh     v0, $000c(v1)
801D2C10	lui    v1, $8006
801D2C14	lw     v1, $2f24(v1)
801D2C18	ori    v0, zero, $00e8
801D2C1C	sh     v0, $000e(v1)
801D2C20	lui    v1, $8006
801D2C24	lw     v1, $2f24(v1)
801D2C28	lui    v0, $801e
801D2C2C	lw     v0, $2cf4(v0)
801D2C30	nop
801D2C34	sb     v0, $0004(v1)
801D2C38	lui    v1, $8006
801D2C3C	lw     v1, $2f24(v1)
801D2C40	lui    v0, $801e
801D2C44	lw     v0, $2cf4(v0)
801D2C48	nop
801D2C4C	sb     v0, $0005(v1)
801D2C50	lui    v1, $8006
801D2C54	lw     v1, $2f24(v1)
801D2C58	lui    v0, $801e
801D2C5C	lw     v0, $2cf4(v0)
801D2C60	nop
801D2C64	sb     v0, $0006(v1)
801D2C68	lw     a1, $0000(s0)
801D2C6C	lui    a0, $8006
801D2C70	lw     a0, $2fc4(a0)
801D2C74	addiu  v0, a1, $0010
801D2C7C	sw     v0, $0000(s0)
system_add_render_packet_to_queue;

801D2C80	addu   a0, zero, zero
801D2C84	ori    a1, zero, $0001
801D2C88	ori    v0, zero, $00ff
801D2C8C	ori    a2, zero, $005f
801D2C90	addiu  a3, sp, $0010
801D2C94	sh     zero, $0010(sp)
801D2C98	sh     zero, $0012(sp)
801D2C9C	sh     v0, $0014(sp)
801D2CA0	jal    $80026a34
801D2CA4	sh     v0, $0016(sp)
801D2CA8	lui    v0, $801e
801D2CAC	lw     v0, $2cf4(v0)
801D2CB0	nop
801D2CB4	addu   v0, v0, s1
801D2CB8	lui    at, $801e
801D2CBC	sw     v0, $2cf4(at)
801D2CC0	bgez   v0, L1d2cd0 [$801d2cd0]
801D2CC4	nop
801D2CC8	lui    at, $801e
801D2CCC	sw     zero, $2cf4(at)

L1d2cd0:	; 801D2CD0
801D2CD0	lui    v0, $801e
801D2CD4	lw     v0, $2cf4(v0)
801D2CD8	nop
801D2CDC	slti   v0, v0, $0100
801D2CE0	bne    v0, zero, L1d2cf0 [$801d2cf0]
801D2CE4	ori    v0, zero, $00ff
801D2CE8	lui    at, $801e
801D2CEC	sw     v0, $2cf4(at)

L1d2cf0:	; 801D2CF0
801D2CF0	lui    v0, $801e
801D2CF4	lw     v0, $2cf4(v0)
801D2CF8	lw     ra, $0020(sp)
801D2CFC	lw     s1, $001c(sp)
801D2D00	lw     s0, $0018(sp)
801D2D04	addiu  sp, sp, $0028
801D2D08	jr     ra 
801D2D0C	nop



////////////////////////////////
// func1d2d10
if (A0 == 0)
{
    [8009a000] = h(81);
    [8009a004] = w(81);
    [8009a008] = w(81);
}
else if (A0 == 1)
{
    [8009a000] = h(80);
    [8009a004] = w(80);
    [8009a008] = w(80);
}
else if (A0 == 2)
{
    [8009a000] = h(82);
    [8009a004] = w(82);
    [8009a008] = w(82);
}

system_execute_AKAO;
////////////////////////////////



func1d2da8:	; 801D2DA8
801D2DA8	addiu  sp, sp, $ffb8 (=-$48)
801D2DAC	addu   a1, a0, zero
801D2DB0	sw     ra, $0040(sp)
801D2DB4	lh     v1, $0008(a1)
801D2DB8	nop
801D2DBC	bne    v1, zero, L1d323c [$801d323c]
801D2DC0	ori    v0, zero, $0001
801D2DC4	lui    v1, $8006
801D2DC8	lhu    v1, $2d7e(v1)
801D2DCC	nop
801D2DD0	andi   v0, v1, $1000
801D2DD4	beq    v0, zero, L1d2e64 [$801d2e64]
801D2DD8	andi   v0, v1, $4000
801D2DDC	lbu    v0, $000b(a1)
801D2DE0	lb     v1, $0011(a1)
801D2DE4	addiu  v0, v0, $ffff (=-$1)
801D2DE8	beq    v1, zero, L1d2e08 [$801d2e08]
801D2DEC	sb     v0, $000b(a1)
801D2DF0	bltz   v1, L1d32b0 [$801d32b0]
801D2DF4	slti   v0, v1, $0003
801D2DF8	beq    v0, zero, L1d32b0 [$801d32b0]
801D2DFC	nop
801D2E00	j      L1d2e40 [$801d2e40]
801D2E04	nop

L1d2e08:	; 801D2E08
801D2E08	sll    v0, v0, $18
801D2E0C	bgez   v0, L1d322c [$801d322c]
801D2E10	nop
801D2E14	lh     v0, $0002(a1)
801D2E18	sb     zero, $000b(a1)
801D2E1C	blez   v0, L1d32b0 [$801d32b0]
801D2E20	addu   v1, v0, zero
801D2E24	addiu  v0, v1, $ffff (=-$1)
801D2E28	ori    a0, zero, $0001
801D2E2C	sh     v0, $0002(a1)
801D2E30	addiu  v0, zero, $fff9 (=-$7)
801D2E34	sb     v0, $000f(a1)
801D2E38	j      L1d2ee0 [$801d2ee0]
801D2E3C	ori    v0, zero, $0001

L1d2e40:	; 801D2E40
801D2E40	lb     v0, $000b(a1)
801D2E44	nop
801D2E48	bgez   v0, L1d322c [$801d322c]
801D2E4C	nop
801D2E50	lbu    v0, $000d(a1)
801D2E54	nop
801D2E58	addiu  v0, v0, $ffff (=-$1)
801D2E5C	j      L1d322c [$801d322c]
801D2E60	sb     v0, $000b(a1)

L1d2e64:	; 801D2E64
801D2E64	beq    v0, zero, L1d2f10 [$801d2f10]
801D2E68	andi   v0, v1, $8000
801D2E6C	lbu    v0, $000b(a1)
801D2E70	lb     v1, $0011(a1)
801D2E74	addiu  v0, v0, $0001
801D2E78	beq    v1, zero, L1d2e98 [$801d2e98]
801D2E7C	sb     v0, $000b(a1)
801D2E80	bltz   v1, L1d32b0 [$801d32b0]
801D2E84	slti   v0, v1, $0003
801D2E88	beq    v0, zero, L1d32b0 [$801d32b0]
801D2E8C	nop
801D2E90	j      L1d2ef0 [$801d2ef0]
801D2E94	nop

L1d2e98:	; 801D2E98
801D2E98	sll    v0, v0, $18
801D2E9C	lb     v1, $000d(a1)
801D2EA0	sra    v0, v0, $18
801D2EA4	slt    v0, v0, v1
801D2EA8	bne    v0, zero, L1d322c [$801d322c]
801D2EAC	addu   a0, v1, zero
801D2EB0	addiu  v0, a0, $ffff (=-$1)
801D2EB4	lh     v1, $0006(a1)
801D2EB8	lb     a0, $000d(a1)
801D2EBC	sb     v0, $000b(a1)
801D2EC0	lh     v0, $0002(a1)
801D2EC4	subu   v1, v1, a0
801D2EC8	slt    v0, v0, v1
801D2ECC	beq    v0, zero, L1d32b0 [$801d32b0]
801D2ED0	ori    a0, zero, $0001
801D2ED4	addiu  v0, zero, $ffff (=-$1)
801D2ED8	sb     v0, $000f(a1)
801D2EDC	ori    v0, zero, $0002

L1d2ee0:	; 801D2EE0
A0 = 1;
func1d2b58; // play sound
801D2EE4	sh     v0, $0008(a1)
801D2EE8	j      L1d32b0 [$801d32b0]
801D2EEC	nop

L1d2ef0:	; 801D2EF0
801D2EF0	lb     v0, $000b(a1)
801D2EF4	lb     v1, $000d(a1)
801D2EF8	nop
801D2EFC	slt    v0, v0, v1
801D2F00	bne    v0, zero, L1d322c [$801d322c]
801D2F04	nop
801D2F08	j      L1d322c [$801d322c]
801D2F0C	sb     zero, $000b(a1)

L1d2f10:	; 801D2F10
801D2F10	beq    v0, zero, L1d3030 [$801d3030]
801D2F14	ori    v0, zero, $0001
801D2F18	lb     v1, $0010(a1)
801D2F1C	nop
801D2F20	beq    v1, v0, L1d2f78 [$801d2f78]
801D2F24	slti   v0, v1, $0002
801D2F28	beq    v0, zero, L1d2f40 [$801d2f40]
801D2F2C	nop
801D2F30	beq    v1, zero, L1d2f54 [$801d2f54]
801D2F34	nop
801D2F38	j      L1d32b0 [$801d32b0]
801D2F3C	nop

L1d2f40:	; 801D2F40
801D2F40	ori    v0, zero, $0002
801D2F44	beq    v1, v0, L1d2fa8 [$801d2fa8]
801D2F48	nop
801D2F4C	j      L1d32b0 [$801d32b0]
801D2F50	nop

L1d2f54:	; 801D2F54
801D2F54	lbu    v0, $000a(a1)
801D2F58	nop
801D2F5C	addiu  v0, v0, $ffff (=-$1)
801D2F60	sb     v0, $000a(a1)
801D2F64	sll    v0, v0, $18
801D2F68	bgez   v0, L1d322c [$801d322c]
801D2F6C	nop
801D2F70	j      L1d32b0 [$801d32b0]
801D2F74	sb     zero, $000a(a1)

L1d2f78:	; 801D2F78
801D2F78	lbu    v0, $000a(a1)
801D2F7C	nop
801D2F80	addiu  v0, v0, $ffff (=-$1)
801D2F84	sb     v0, $000a(a1)
801D2F88	sll    v0, v0, $18
801D2F8C	bgez   v0, L1d322c [$801d322c]
801D2F90	nop
801D2F94	lbu    v0, $000c(a1)
801D2F98	nop
801D2F9C	addiu  v0, v0, $ffff (=-$1)
801D2FA0	j      L1d322c [$801d322c]
801D2FA4	sb     v0, $000a(a1)

L1d2fa8:	; 801D2FA8
801D2FA8	lhu    v0, $000a(a1)
801D2FAC	nop
801D2FB0	bne    v0, zero, L1d2fc8 [$801d2fc8]
801D2FB4	nop
801D2FB8	lh     v0, $0002(a1)
801D2FBC	nop
801D2FC0	beq    v0, zero, L1d32b0 [$801d32b0]
801D2FC4	nop

L1d2fc8:	; 801D2FC8
801D2FC8	lbu    v0, $000a(a1)
801D2FCC	nop
801D2FD0	addiu  v0, v0, $ffff (=-$1)
801D2FD4	sb     v0, $000a(a1)
801D2FD8	sll    v0, v0, $18
801D2FDC	bgez   v0, L1d322c [$801d322c]
801D2FE0	nop
801D2FE4	lbu    v0, $000c(a1)
801D2FE8	lbu    v1, $000b(a1)
801D2FEC	addiu  v0, v0, $ffff (=-$1)
801D2FF0	addiu  v1, v1, $ffff (=-$1)
801D2FF4	sb     v1, $000b(a1)
801D2FF8	sll    v1, v1, $18
801D2FFC	bgez   v1, L1d322c [$801d322c]
801D3000	sb     v0, $000a(a1)
801D3004	lh     v0, $0002(a1)
801D3008	sb     zero, $000b(a1)
801D300C	blez   v0, L1d322c [$801d322c]
801D3010	addu   v1, v0, zero
801D3014	addiu  v0, v1, $ffff (=-$1)
801D3018	sh     v0, $0002(a1)
801D301C	addiu  v0, zero, $fff9 (=-$7)
801D3020	sb     v0, $000f(a1)
801D3024	ori    v0, zero, $0001
801D3028	j      L1d322c [$801d322c]
801D302C	sh     v0, $0008(a1)

L1d3030:	; 801D3030
801D3030	andi   v0, v1, $2000
801D3034	beq    v0, zero, L1d31a8 [$801d31a8]
801D3038	ori    v0, zero, $0001
801D303C	lb     v1, $0010(a1)
801D3040	nop
801D3044	beq    v1, v0, L1d30a8 [$801d30a8]
801D3048	slti   v0, v1, $0002
801D304C	beq    v0, zero, L1d3064 [$801d3064]
801D3050	nop
801D3054	beq    v1, zero, L1d3078 [$801d3078]
801D3058	nop
801D305C	j      L1d32b0 [$801d32b0]
801D3060	nop

L1d3064:	; 801D3064
801D3064	ori    v0, zero, $0002

L1d3068:	; 801D3068
801D3068	beq    v1, v0, L1d30d4 [$801d30d4]
801D306C	nop
801D3070	j      L1d32b0 [$801d32b0]
801D3074	nop

L1d3078:	; 801D3078
801D3078	lbu    v0, $000a(a1)
801D307C	lb     v1, $000c(a1)
801D3080	addiu  v0, v0, $0001
801D3084	sb     v0, $000a(a1)
801D3088	sll    v0, v0, $18
801D308C	sra    v0, v0, $18
801D3090	slt    v0, v0, v1
801D3094	bne    v0, zero, L1d322c [$801d322c]
801D3098	addu   a0, v1, zero
801D309C	addiu  v0, a0, $ffff (=-$1)
801D30A0	j      L1d32b0 [$801d32b0]
801D30A4	sb     v0, $000a(a1)

L1d30a8:	; 801D30A8
801D30A8	lbu    v0, $000a(a1)
801D30AC	lb     v1, $000c(a1)
801D30B0	addiu  v0, v0, $0001
801D30B4	sb     v0, $000a(a1)
801D30B8	sll    v0, v0, $18
801D30BC	sra    v0, v0, $18
801D30C0	slt    v0, v0, v1
801D30C4	bne    v0, zero, L1d322c [$801d322c]
801D30C8	nop
801D30CC	j      L1d322c [$801d322c]
801D30D0	sb     zero, $000a(a1)

L1d30d4:	; 801D30D4
801D30D4	lb     v0, $000c(a1)
801D30D8	lb     v1, $000a(a1)
801D30DC	addiu  v0, v0, $ffff (=-$1)
801D30E0	bne    v1, v0, L1d3110 [$801d3110]
801D30E4	nop
801D30E8	lb     a0, $000d(a1)
801D30EC	lb     v1, $000b(a1)
801D30F0	addiu  v0, a0, $ffff (=-$1)
801D30F4	bne    v1, v0, L1d3110 [$801d3110]
801D30F8	nop
801D30FC	lh     v0, $0006(a1)
801D3100	lh     v1, $0002(a1)
801D3104	subu   v0, v0, a0
801D3108	beq    v1, v0, L1d32b0 [$801d32b0]
801D310C	nop

L1d3110:	; 801D3110
801D3110	lbu    v0, $000a(a1)
801D3114	lb     v1, $000c(a1)
801D3118	addiu  v0, v0, $0001
801D311C	sb     v0, $000a(a1)
801D3120	sll    v0, v0, $18
801D3124	sra    v0, v0, $18
801D3128	slt    v0, v0, v1
801D312C	bne    v0, zero, L1d322c [$801d322c]
801D3130	nop
801D3134	lb     v0, $000b(a1)
801D3138	lb     v1, $000c(a1)
801D313C	nop
801D3140	slt    v0, v0, v1
801D3144	bne    v0, zero, L1d3150 [$801d3150]
801D3148	sb     zero, $000a(a1)
801D314C	sb     zero, $000a(a1)

L1d3150:	; 801D3150
801D3150	lbu    v0, $000b(a1)
801D3154	lb     v1, $000d(a1)
801D3158	addiu  v0, v0, $0001
801D315C	sb     v0, $000b(a1)
801D3160	sll    v0, v0, $18
801D3164	sra    v0, v0, $18
801D3168	slt    v0, v0, v1
801D316C	bne    v0, zero, L1d322c [$801d322c]
801D3170	addu   a0, v1, zero
801D3174	addiu  v0, a0, $ffff (=-$1)
801D3178	lh     v1, $0006(a1)
801D317C	lb     a0, $000d(a1)
801D3180	sb     v0, $000b(a1)
801D3184	lh     v0, $0002(a1)
801D3188	subu   v1, v1, a0
801D318C	slt    v0, v0, v1
801D3190	beq    v0, zero, L1d322c [$801d322c]
801D3194	addiu  v0, zero, $ffff (=-$1)
801D3198	sb     v0, $000f(a1)
801D319C	ori    v0, zero, $0002
801D31A0	j      L1d322c [$801d322c]
801D31A4	sh     v0, $0008(a1)

L1d31a8:	; 801D31A8
801D31A8	andi   v0, v1, $0008
801D31AC	beq    v0, zero, L1d31f8 [$801d31f8]
801D31B0	andi   v0, v1, $0004
801D31B4	lbu    v0, $000d(a1)
801D31B8	lhu    v1, $0002(a1)
801D31BC	lb     a2, $000d(a1)
801D31C0	sll    v0, v0, $18
801D31C4	sra    v0, v0, $18
801D31C8	addu   v1, v1, v0
801D31CC	sh     v1, $0002(a1)
801D31D0	sll    v1, v1, $10
801D31D4	lh     v0, $0006(a1)
801D31D8	sra    v1, v1, $10
801D31DC	addu   a0, v0, zero
801D31E0	subu   v0, v0, a2
801D31E4	slt    v0, v0, v1
801D31E8	beq    v0, zero, L1d322c [$801d322c]
801D31EC	subu   v0, a0, a2
801D31F0	j      L1d32b0 [$801d32b0]
801D31F4	sh     v0, $0002(a1)

L1d31f8:	; 801D31F8
801D31F8	beq    v0, zero, L1d32b0 [$801d32b0]
801D31FC	nop
801D3200	lbu    v0, $000d(a1)
801D3204	lhu    v1, $0002(a1)
801D3208	sll    v0, v0, $18
801D320C	sra    v0, v0, $18
801D3210	subu   v1, v1, v0
801D3214	sh     v1, $0002(a1)
801D3218	sll    v1, v1, $10
801D321C	bgez   v1, L1d322c [$801d322c]
801D3220	nop
801D3224	j      L1d32b0 [$801d32b0]
801D3228	sh     zero, $0002(a1)

L1d322c:	; 801D322C
A0 = 1;
func1d2b58; // play sound

801D3234	j      L1d32b0 [$801d32b0]
801D3238	nop

L1d323c:	; 801D323C
801D323C	beq    v1, v0, L1d3254 [$801d3254]
801D3240	ori    v0, zero, $0002
801D3244	beq    v1, v0, L1d327c [$801d327c]
801D3248	addiu  v1, zero, $fff8 (=-$8)
801D324C	j      L1d32b0 [$801d32b0]
801D3250	nop

L1d3254:	; 801D3254
801D3254	lbu    v0, $000f(a1)
801D3258	nop
801D325C	addiu  v0, v0, $0001
801D3260	sb     v0, $000f(a1)
801D3264	sll    v0, v0, $18
801D3268	bne    v0, zero, L1d32b0 [$801d32b0]
801D326C	nop
801D3270	sh     zero, $0008(a1)
801D3274	j      L1d32b0 [$801d32b0]
801D3278	sb     zero, $000f(a1)

L1d327c:	; 801D327C
801D327C	lbu    v0, $000f(a1)
801D3280	nop
801D3284	addiu  v0, v0, $ffff (=-$1)
801D3288	sb     v0, $000f(a1)
801D328C	sll    v0, v0, $18
801D3290	sra    v0, v0, $18
801D3294	bne    v0, v1, L1d32b0 [$801d32b0]
801D3298	nop
801D329C	lhu    v0, $0002(a1)
801D32A0	sh     zero, $0008(a1)
801D32A4	sb     zero, $000f(a1)
801D32A8	addiu  v0, v0, $0001
801D32AC	sh     v0, $0002(a1)

L1d32b0:	; 801D32B0
801D32B0	lw     ra, $0040(sp)
801D32B4	addiu  sp, sp, $0048
801D32B8	jr     ra 
801D32BC	nop


func1d32c0:	; 801D32C0
801D32C0	lui    a0, $800a
801D32C4	lw     a0, $a024(a0)
801D32C8	addiu  sp, sp, $ffe8 (=-$18)
801D32CC	sw     ra, $0010(sp)
801D32D0	jal    $80042a30
801D32D4	nop
801D32D8	lui    a0, $800a
801D32DC	lw     a0, $a028(a0)
801D32E0	jal    $80042a30
801D32E4	nop
801D32E8	lui    a0, $800a
801D32EC	lw     a0, $a02c(a0)
801D32F0	jal    $80042a30
801D32F4	nop
801D32F8	lui    a0, $800a
801D32FC	lw     a0, $a030(a0)
801D3300	jal    $80042a30
801D3304	nop
801D3308	lw     ra, $0010(sp)
801D330C	addiu  sp, sp, $0018
801D3310	jr     ra 
801D3314	nop


func1d3318:	; 801D3318
801D3318	lui    a0, $800a
801D331C	lw     a0, $a034(a0)
801D3320	addiu  sp, sp, $ffe8 (=-$18)
801D3324	sw     ra, $0010(sp)
801D3328	jal    $80042a30
801D332C	nop
801D3330	lui    a0, $800a
801D3334	lw     a0, $a038(a0)
801D3338	jal    $80042a30
801D333C	nop
801D3340	lui    a0, $800a
801D3344	lw     a0, $a03c(a0)
801D3348	jal    $80042a30
801D334C	nop
801D3350	lui    a0, $800a
801D3354	lw     a0, $a040(a0)
801D3358	jal    $80042a30
801D335C	nop
801D3360	lw     ra, $0010(sp)
801D3364	addiu  sp, sp, $0018
801D3368	jr     ra 
801D336C	nop


func1d3370:	; 801D3370
801D3370	addiu  sp, sp, $ffe0 (=-$20)
801D3374	sw     s1, $0014(sp)
801D3378	lui    s1, $800a
801D337C	addiu  s1, s1, $a024 (=-$5fdc)
801D3380	sw     s0, $0010(sp)
801D3384	ori    s0, zero, $0001
801D3388	sw     ra, $0018(sp)

loop1d338c:	; 801D338C
801D338C	lw     a0, $0000(s1)
801D3390	jal    $80042a30
801D3394	nop
801D3398	beq    v0, s0, L1d33dc [$801d33dc]
801D339C	addu   v0, zero, zero
801D33A0	lw     a0, $0004(s1)
801D33A4	jal    $80042a30
801D33A8	nop
801D33AC	beq    v0, s0, L1d33dc [$801d33dc]
801D33B0	ori    v0, zero, $0001
801D33B4	lw     a0, $0008(s1)
801D33B8	jal    $80042a30
801D33BC	nop
801D33C0	beq    v0, s0, L1d33dc [$801d33dc]
801D33C4	ori    v0, zero, $0002
801D33C8	lw     a0, $000c(s1)
801D33CC	jal    $80042a30
801D33D0	nop
801D33D4	bne    v0, s0, loop1d338c [$801d338c]
801D33D8	ori    v0, zero, $0003

L1d33dc:	; 801D33DC
801D33DC	lw     ra, $0018(sp)
801D33E0	lw     s1, $0014(sp)
801D33E4	lw     s0, $0010(sp)
801D33E8	addiu  sp, sp, $0020
801D33EC	jr     ra 
801D33F0	nop


func1d33f4:	; 801D33F4
801D33F4	addiu  sp, sp, $ffe0 (=-$20)
801D33F8	sw     s1, $0014(sp)
801D33FC	lui    s1, $800a
801D3400	addiu  s1, s1, $a034 (=-$5fcc)
801D3404	sw     s0, $0010(sp)
801D3408	ori    s0, zero, $0001
801D340C	sw     ra, $0018(sp)

loop1d3410:	; 801D3410
801D3410	lw     a0, $0000(s1)
801D3414	jal    $80042a30
801D3418	nop
801D341C	beq    v0, s0, L1d3460 [$801d3460]
801D3420	addu   v0, zero, zero
801D3424	lw     a0, $0004(s1)
801D3428	jal    $80042a30
801D342C	nop
801D3430	beq    v0, s0, L1d3460 [$801d3460]
801D3434	ori    v0, zero, $0001
801D3438	lw     a0, $0008(s1)
801D343C	jal    $80042a30
801D3440	nop
801D3444	beq    v0, s0, L1d3460 [$801d3460]
801D3448	ori    v0, zero, $0002
801D344C	lw     a0, $000c(s1)
801D3450	jal    $80042a30
801D3454	nop
801D3458	bne    v0, s0, loop1d3410 [$801d3410]
801D345C	ori    v0, zero, $0003

L1d3460:	; 801D3460
801D3460	lw     ra, $0018(sp)
801D3464	lw     s1, $0014(sp)
801D3468	lw     s0, $0010(sp)
801D346C	addiu  sp, sp, $0020
801D3470	jr     ra 
801D3474	nop


func1d3478:	; 801D3478
801D3478	addiu  sp, sp, $ffe0 (=-$20)
801D347C	sw     s0, $0010(sp)
801D3480	addu   s0, a0, zero
801D3484	sltu   v0, zero, s0
801D3488	sw     s1, $0014(sp)
801D348C	sll    s1, v0, $04
801D3490	sw     ra, $0018(sp)
801D3494	jal    $80048968
801D3498	addu   a0, s1, zero
801D349C	jal    func1d3370 [$801d3370]
801D34A0	nop
801D34A4	addu   v1, v0, zero
801D34A8	ori    v0, zero, $0001
801D34AC	beq    v1, v0, L1d3634 [$801d3634]
801D34B0	slti   v0, v1, $0002
801D34B4	beq    v0, zero, L1d34cc [$801d34cc]
801D34B8	nop
801D34BC	beq    v1, zero, L1d34e8 [$801d34e8]
801D34C0	sll    v0, s0, $01
801D34C4	j      L1d363c [$801d363c]
801D34C8	addu   v0, v0, s0

L1d34cc:	; 801D34CC
801D34CC	ori    v0, zero, $0002
801D34D0	beq    v1, v0, L1d3524 [$801d3524]
801D34D4	ori    v0, zero, $0003
801D34D8	beq    v1, v0, L1d3564 [$801d3564]
801D34DC	sll    v0, s0, $01
801D34E0	j      L1d3638 [$801d3638]
801D34E4	nop

L1d34e8:	; 801D34E8
801D34E8	addu   v1, v0, s0
801D34EC	lui    at, $801f
801D34F0	addiu  at, at, $8f38 (=-$70c8)
801D34F4	addu   at, at, v1
801D34F8	lbu    v0, $0000(at)
801D34FC	nop
801D3500	bne    v0, zero, L1d3650 [$801d3650]
801D3504	nop
801D3508	ori    v0, zero, $0001
801D350C	lui    at, $801f
801D3510	addiu  at, at, $8f38 (=-$70c8)
801D3514	addu   at, at, v1
801D3518	sb     v0, $0000(at)
801D351C	j      L1d357c [$801d357c]
801D3520	nop

L1d3524:	; 801D3524
801D3524	sll    v0, s0, $01
801D3528	addu   v0, v0, s0
801D352C	lui    at, $801f
801D3530	addiu  at, at, $8f38 (=-$70c8)
801D3534	addu   at, at, v0
801D3538	sb     zero, $0000(at)
801D353C	lui    at, $801f
801D3540	addiu  at, at, $8f39 (=-$70c7)
801D3544	addu   at, at, v0
801D3548	sb     zero, $0000(at)
801D354C	lui    at, $801f
801D3550	addiu  at, at, $8f3a (=-$70c6)
801D3554	addu   at, at, v0
801D3558	sb     zero, $0000(at)
801D355C	j      L1d3650 [$801d3650]
801D3560	nop

L1d3564:	; 801D3564
801D3564	jal    func1d3318 [$801d3318]
801D3568	nop
801D356C	jal    $80048998
801D3570	addu   a0, s1, zero
801D3574	jal    func1d33f4 [$801d33f4]
801D3578	nop

L1d357c:	; 801D357C
801D357C	jal    func1d32c0 [$801d32c0]
801D3580	nop
801D3584	jal    $80048978
801D3588	addu   a0, s1, zero
801D358C	jal    func1d3370 [$801d3370]
801D3590	nop
801D3594	addu   v1, v0, zero
801D3598	ori    v0, zero, $0001
801D359C	beq    v1, v0, L1d3634 [$801d3634]
801D35A0	slti   v0, v1, $0002
801D35A4	beq    v0, zero, L1d35bc [$801d35bc]
801D35A8	nop
801D35AC	beq    v1, zero, L1d35d8 [$801d35d8]
801D35B0	sll    v0, s0, $01
801D35B4	j      L1d363c [$801d363c]
801D35B8	addu   v0, v0, s0

L1d35bc:	; 801D35BC
801D35BC	ori    v0, zero, $0002
801D35C0	beq    v1, v0, L1d35f4 [$801d35f4]
801D35C4	ori    v0, zero, $0003
801D35C8	beq    v1, v0, L1d3614 [$801d3614]
801D35CC	sll    v0, s0, $01
801D35D0	j      L1d363c [$801d363c]
801D35D4	addu   v0, v0, s0

L1d35d8:	; 801D35D8
801D35D8	addu   v0, v0, s0
801D35DC	lui    at, $801f
801D35E0	addiu  at, at, $8f3a (=-$70c6)
801D35E4	addu   at, at, v0
801D35E8	sb     zero, $0000(at)
801D35EC	j      L1d3650 [$801d3650]
801D35F0	nop

L1d35f4:	; 801D35F4
801D35F4	sll    v0, s0, $01
801D35F8	addu   v0, v0, s0
801D35FC	lui    at, $801f
801D3600	addiu  at, at, $8f38 (=-$70c8)
801D3604	addu   at, at, v0
801D3608	sb     zero, $0000(at)
801D360C	j      L1d3650 [$801d3650]
801D3610	nop

L1d3614:	; 801D3614
801D3614	addu   v0, v0, s0
801D3618	ori    v1, zero, $0001
801D361C	lui    at, $801f
801D3620	addiu  at, at, $8f3a (=-$70c6)
801D3624	addu   at, at, v0
801D3628	sb     v1, $0000(at)
801D362C	j      L1d3650 [$801d3650]
801D3630	nop

L1d3634:	; 801D3634
801D3634	sll    v0, s0, $01

L1d3638:	; 801D3638
801D3638	addu   v0, v0, s0

L1d363c:	; 801D363C
801D363C	ori    v1, zero, $0001
801D3640	lui    at, $801f
801D3644	addiu  at, at, $8f39 (=-$70c7)
801D3648	addu   at, at, v0
801D364C	sb     v1, $0000(at)

L1d3650:	; 801D3650
801D3650	lw     ra, $0018(sp)
801D3654	lw     s1, $0014(sp)
801D3658	lw     s0, $0010(sp)
801D365C	addiu  sp, sp, $0020
801D3660	jr     ra 
801D3664	nop


func1d3668:	; 801D3668
801D3668	addiu  sp, sp, $ffe8 (=-$18)
801D366C	andi   a0, a0, $003f
801D3670	bne    a0, zero, L1d3688 [$801d3688]
801D3674	sw     ra, $0010(sp)
801D3678	jal    func1d3478 [$801d3478]
801D367C	addu   a0, zero, zero
801D3680	jal    func1d3478 [$801d3478]
801D3684	ori    a0, zero, $0001

L1d3688:	; 801D3688
801D3688	lw     ra, $0010(sp)
801D368C	addiu  sp, sp, $0018
801D3690	jr     ra 
801D3694	nop


func1d3698:	; 801D3698
801D3698	addiu  sp, sp, $ffe0 (=-$20)
801D369C	sw     s1, $0014(sp)
801D36A0	addu   s1, a0, zero
801D36A4	sw     s2, $0018(sp)
801D36A8	addu   s2, a1, zero
801D36AC	sw     s0, $0010(sp)
801D36B0	addu   s0, zero, zero
801D36B4	sw     ra, $001c(sp)

loop1d36b8:	; 801D36B8
801D36B8	beq    s1, zero, L1d36c4 [$801d36c4]
801D36BC	addu   a0, s2, zero
801D36C0	ori    a0, a0, $0010

L1d36c4:	; 801D36C4
801D36C4	jal    func1d1d40 [$801d1d40]
801D36C8	nop
801D36CC	bne    v0, zero, L1d36dc [$801d36dc]
801D36D0	nop
801D36D4	j      L1d36ec [$801d36ec]
801D36D8	addu   v1, zero, zero

L1d36dc:	; 801D36DC
801D36DC	addiu  s0, s0, $0001
801D36E0	slti   v0, s0, $0014
801D36E4	bne    v0, zero, loop1d36b8 [$801d36b8]
801D36E8	ori    v1, zero, $0001

L1d36ec:	; 801D36EC
801D36EC	addu   v0, v1, zero
801D36F0	lw     ra, $001c(sp)
801D36F4	lw     s2, $0018(sp)
801D36F8	lw     s1, $0014(sp)
801D36FC	lw     s0, $0010(sp)
801D3700	addiu  sp, sp, $0020
801D3704	jr     ra 
801D3708	nop


func1d370c:	; 801D370C
801D370C	addiu  sp, sp, $ffa0 (=-$60)
801D3710	sw     s4, $0048(sp)
801D3714	addu   s4, a1, zero
801D3718	addu   a0, a2, zero
801D371C	sw     ra, $0058(sp)
801D3720	sw     s7, $0054(sp)
801D3724	sw     s6, $0050(sp)
801D3728	sw     s5, $004c(sp)
801D372C	sw     s3, $0044(sp)
801D3730	sw     s2, $0040(sp)
801D3734	sw     s1, $003c(sp)
801D3738	jal    func1d1d1c [$801d1d1c]
801D373C	sw     s0, $0038(sp)
801D3740	ori    a0, zero, $00c0
801D3744	addiu  a1, s4, $002e
801D3748	addu   s6, v0, zero
801D374C	addiu  a2, s6, $0028
801D3754	ori    a3, zero, $0007
func26f44;

801D3758	addu   s2, zero, zero
801D375C	addiu  s5, s4, $0006
801D3760	ori    s3, zero, $0030
801D3764	addu   s0, s6, zero
801D3768	ori    s1, zero, $0016

loop1d376c:	; 801D376C
801D376C	lbu    v1, $0005(s0)
801D3770	ori    v0, zero, $00ff
801D3774	beq    v1, v0, L1d37ec [$801d37ec]
801D3778	sltiu  v0, v1, $0005
801D377C	bne    v0, zero, L1d378c [$801d378c]
801D3780	addu   a0, s1, zero
801D3784	j      L1d3790 [$801d3790]
801D3788	sw     s3, $0010(sp)

L1d378c:	; 801D378C
801D378C	sw     zero, $0010(sp)

L1d3790:	; 801D3790
801D3790	lbu    a3, $0005(s0)
801D3794	lui    v0, $cccc
801D3798	ori    v0, v0, $cccd
801D379C	multu  a3, v0
801D37A0	addu   a1, s5, zero
801D37A4	ori    a2, zero, $0030
801D37A8	sw     s3, $0018(sp)
801D37AC	sw     s3, $001c(sp)
801D37B0	mfhi   t0
801D37B4	srl    v1, t0, $02
801D37B8	sll    v0, v1, $02
801D37BC	addu   v0, v0, v1
801D37C0	subu   a3, a3, v0
801D37C4	andi   a3, a3, $00ff
801D37C8	sll    v0, a3, $01
801D37CC	addu   v0, v0, a3
801D37D0	sll    v0, v0, $04
801D37D4	sw     v0, $0014(sp)
801D37D8	lbu    v0, $0005(s0)
801D37DC	ori    a3, zero, $0030
801D37E0	sw     zero, $0024(sp)
801D37E4	jal    $8001d180
801D37E8	sw     v0, $0020(sp)

L1d37ec:	; 801D37EC
801D37EC	addiu  s0, s0, $0001
801D37F0	addiu  s2, s2, $0001
801D37F4	slti   v0, s2, $0003
801D37F8	bne    v0, zero, loop1d376c [$801d376c]
801D37FC	addiu  s1, s1, $0034
801D3800	addu   a0, zero, zero
801D3804	ori    a1, zero, $0001
801D3808	ori    a2, zero, $007f
801D380C	addiu  s2, sp, $0030
801D3810	addu   a3, s2, zero
801D3814	ori    v0, zero, $00ff
801D3818	sh     zero, $0030(sp)
801D381C	sh     zero, $0032(sp)
801D3820	sh     v0, $0034(sp)
801D3824	jal    $80026a34
801D3828	sh     v0, $0036(sp)
S3 = 801e3684;
801D3834	jal    $80026b70
801D3838	addu   a0, s3, zero
801D383C	addiu  a0, v0, $00c2
801D3840	addiu  a1, s4, $001c
801D3844	ori    a3, zero, $0002
801D3848	lbu    a2, $0004(s6)
801D384C	ori    s0, zero, $0007
801D3850	jal    $80028e00
801D3854	sw     s0, $0010(sp)
801D3858	ori    a0, zero, $0152
801D385C	addiu  a1, s4, $000c
801D3860	ori    a2, zero, $00d5
801D3864	jal    $8002708c
801D3868	ori    a3, zero, $0007
801D386C	lw     a0, $0024(s6)
801D3870	jal    $80023788
801D3874	addu   s7, zero, zero
801D3878	ori    a0, zero, $0144
801D387C	addiu  s1, s4, $000b
801D3880	addu   a1, s1, zero
801D3884	addu   a2, v0, zero
801D3888	ori    a3, zero, $0002
801D388C	jal    $80029114
801D3890	sw     s0, $0010(sp)
801D3894	lw     a0, $0024(s6)
801D3898	lui    s5, $801e
801D389C	addiu  s5, s5, $3650
801D38A0	jal    $8002382c
801D38A4	nop
801D38A8	ori    a0, zero, $0159
801D38AC	addu   a1, s1, zero
801D38B0	addu   a2, v0, zero
801D38B4	ori    a3, zero, $0002
801D38B8	jal    $80029114
801D38BC	sw     s0, $0010(sp)
801D38C0	ori    a0, zero, $0135
801D38C4	addiu  a1, s4, $0019
801D38C8	sw     s0, $0010(sp)
801D38CC	lw     a2, $0020(s6)
801D38D0	jal    $80028e00
801D38D4	ori    a3, zero, $0007
801D38D8	addu   a0, zero, zero
801D38DC	ori    a1, zero, $0001
801D38E0	ori    a2, zero, $007f
801D38E4	addu   a3, s2, zero
801D38E8	ori    v0, zero, $0100
801D38EC	sh     zero, $0030(sp)
801D38F0	sh     zero, $0032(sp)
801D38F4	sh     v0, $0034(sp)
801D38F8	jal    $80026a34
801D38FC	sh     v0, $0036(sp)
801D3900	ori    a0, zero, $00bd
801D3904	addiu  a1, s4, $001a
A2 = S3; // text "Level"

801D3910	ori    a3, zero, $0005
func26f44;

801D3914	ori    a0, zero, $00b8
801D3918	addiu  a1, s4, $0008
801D391C	addiu  a2, s6, $0008
801D3924	ori    a3, zero, $0007
func26f44;

801D3928	ori    a0, zero, $011c
801D392C	addiu  a1, s4, $0009
801D3930	lui    s0, $8005
801D3934	addiu  s0, s0, $92f0 (=-$6d10)
801D3938	addu   a2, s0, zero
801D3940	ori    a3, zero, $0007
func26f44;

801D3944	ori    a0, zero, $011c
801D3948	addiu  a1, s4, $0017
801D394C	addiu  a2, s0, $000c
801D3954	ori    a3, zero, $0007
func26f44;

801D3958	jal    $8001def0
801D395C	addiu  a0, s6, $0048

loop1d3960:	; 801D3960
801D3960	addiu  a0, sp, $0028
801D3964	jal    $8001de40
801D3968	addu   a1, s5, zero
801D396C	addiu  a0, sp, $0028
801D3970	addu   a1, zero, zero
801D3974	jal    $8001de24
801D3978	addu   a2, s4, zero
801D397C	jal    $8001e040
801D3980	addiu  a0, sp, $0028
801D3984	addiu  s7, s7, $0001
801D3988	slti   v0, s7, $0003
801D398C	bne    v0, zero, loop1d3960 [$801d3960]
801D3990	addiu  s5, s5, $0008
801D3994	lw     ra, $0058(sp)
801D3998	lw     s7, $0054(sp)
801D399C	lw     s6, $0050(sp)
801D39A0	lw     s5, $004c(sp)
801D39A4	lw     s4, $0048(sp)
801D39A8	lw     s3, $0044(sp)
801D39AC	lw     s2, $0040(sp)
801D39B0	lw     s1, $003c(sp)
801D39B4	lw     s0, $0038(sp)
801D39B8	addiu  sp, sp, $0060
801D39BC	jr     ra 
801D39C0	nop


func1d39c4:	; 801D39C4
801D39C4	addiu  sp, sp, $ffc0 (=-$40)
801D39C8	lui    a0, $801e
801D39CC	addiu  a0, a0, $368c
801D39D0	ori    v0, zero, $0007
801D39D4	sw     ra, $0038(sp)
801D39D8	lui    at, $801e
801D39DC	sw     zero, $3698(at)
801D39E0	lui    at, $801e
801D39E4	sw     v0, $2cf8(at)
801D39E8	jal    $8001def0
801D39EC	nop
801D39F0	lui    a0, $801d
801D39F4	addiu  a0, a0, $4edc
801D39F8	ori    a1, zero, $0380
801D39FC	addu   a2, zero, zero
801D3A00	addu   a3, zero, zero
801D3A04	ori    v0, zero, $01e0
801D3A08	jal    $80025d14
801D3A0C	sw     v0, $0010(sp)
801D3A10	jal    $80043dd8
801D3A14	addu   a0, zero, zero
801D3A18	lui    a0, $801e
801D3A1C	addiu  a0, a0, $3dfe
801D3A20	addu   a1, zero, zero
801D3A24	ori    a2, zero, $0001
801D3A28	ori    a3, zero, $0001
801D3A2C	ori    v0, zero, $0002
801D3A30	ori    v1, zero, $0001
801D3A34	sw     v0, $0010(sp)
801D3A38	sw     zero, $0014(sp)
801D3A3C	sw     zero, $0018(sp)
801D3A40	sw     v1, $001c(sp)
801D3A44	sw     v0, $0020(sp)
801D3A48	sw     zero, $0024(sp)
801D3A4C	sw     zero, $0028(sp)
801D3A50	sw     zero, $002c(sp)
801D3A54	sw     v1, $0030(sp)
801D3A58	jal    $80026448
801D3A5C	sw     zero, $0034(sp)
801D3A60	lui    a0, $801e
801D3A64	addiu  a0, a0, $3f2c
801D3A68	jal    $80025cd4
801D3A6C	nop
801D3A70	lui    a0, $801f
801D3A74	addiu  a0, a0, $8f44 (=-$70bc)
801D3A78	jal    $80025b8c
801D3A7C	nop
801D3A80	lui    a0, $801e
801D3A84	addiu  a0, a0, $4538
801D3A88	jal    $80025c14
801D3A8C	nop
801D3A90	jal    $80025df8
801D3A94	nop
801D3A98	jal    func1d19c4 [$801d19c4]
801D3A9C	nop
801D3AA0	lw     ra, $0038(sp)
801D3AA4	addiu  sp, sp, $0040
801D3AA8	jr     ra 
801D3AAC	nop



////////////////////////////////
// func1d3ab0
801D3AB0	lui    v1, $801e
801D3AB4	lw     v1, $2cf8(v1)
801D3AB8	addiu  sp, sp, $ff98 (=-$68)
801D3ABC	sw     s0, $0050(sp)
801D3AC0	addu   s0, a0, zero
801D3AC4	sw     ra, $0060(sp)
801D3AC8	sw     s3, $005c(sp)
801D3ACC	sw     s2, $0058(sp)
801D3AD0	sltiu  v0, v1, $0002
801D3AD4	bne    v0, zero, L1d3ae8 [$801d3ae8]
801D3AD8	sw     s1, $0054(sp)
801D3ADC	ori    v0, zero, $0007
801D3AE0	bne    v1, v0, L1d3b0c [$801d3b0c]
801D3AE4	nop

L1d3ae8:	; 801D3AE8
V1 = w[801e3d54];
801D3AF0	ori    v0, zero, $0002
801D3AF4	beq    v1, v0, L1d3b0c [$801d3b0c]
801D3AF8	nop
801D3AFC	beq    v1, zero, L1d3b0c [$801d3b0c]
801D3B00	nop
801D3B04	jal    func1d3668 [$801d3668]
801D3B08	addu   a0, s0, zero

L1d3b0c:	; 801D3B0C
801D3B0C	jal    $80026b5c
801D3B10	ori    a0, zero, $0080
V1 = w[801e3d54];
if (V1 == 0)
{
    801D3B2C	addiu  a0, zero, $fff1 (=-$f)
    801D3B28	jal    func1d2b98 [$801d2b98]

    if (V0 == 0)
    {
        [801e3d54] = w(1);
    }
}
else if (V1 == 2)
{
    801D3B4C	ori    a0, zero, $000f
    801D3B48	jal    func1d2b98 [$801d2b98]

    if (V0 == ff)
    {
        [801e3d54] = w(-1);
    }
}

801D3B64	jal    $8001f6b4


V1 = w[801e2cf8];
switch (V1)
{
    A03B1D80 0
    8C3C1D80 1
    003F1D80 2
    003F1D80 3
    C83F1D80 4
    80441D80 5
    34401D80 6



    801D3BA0	lui    s1, $801e
    801D3BA4	addiu  s1, s1, $3668
    801D3BA8	lh     a0, $0000(s1)
    801D3BAC	lui    v0, $801e
    801D3BB0	lb     v0, $3d8b(v0)
    801D3BB4	addiu  a0, a0, $ffee (=-$12)
    801D3BB8	sll    a1, v0, $01
    801D3BBC	addu   a1, a1, v0
    801D3BC0	sll    a1, a1, $02
    801D3BC4	lui    v0, $801e
    801D3BC8	lh     v0, $366a(v0)
    801D3BCC	addiu  a1, a1, $0006
    801D3BD4	addu   a1, v0, a1
    func1eb2c; // cursor

    801D3BD8	ori    a0, zero, $000a
    801D3BDC	ori    a1, zero, $000b
    S0 = 801e2d20;
    A2 = S0; // text "Select a slot."
    801D3BF0	ori    a3, zero, $0007
    func26f44;

    A2 = S0 + 48; // text "SLOT 1"

    801D3BF8	lh     a0, $0000(s1)
    801D3BFC	lui    a1, $801e
    801D3C00	lh     a1, $366a(a1)
    801D3C04	lui    a3, $801f
    801D3C08	lbu    a3, $8f38(a3)
    801D3C0C	addiu  a0, a0, $000c
    801D3C10	addiu  a1, a1, $0005
    801D3C14	sltu   a3, zero, a3
    801D3C18	subu   a3, zero, a3
    801D3C20	andi   a3, a3, $0007
    func26f44;

    801D3C24	addiu  a2, s0, $006c
    801D3C28	lh     a0, $0000(s1)
    801D3C2C	lui    a1, $801e
    801D3C30	lh     a1, $366a(a1)
    801D3C34	lui    a3, $801f
    801D3C38	lbu    a3, $8f3b(a3)
    801D3C3C	addiu  a0, a0, $000c
    801D3C40	addiu  a1, a1, $0011
    801D3C44	sltu   a3, zero, a3
    801D3C48	subu   a3, zero, a3
    801D3C50	andi   a3, a3, $0007
    func26f44;

    801D3C54	addu   a0, zero, zero
    801D3C58	ori    a1, zero, $0001
    801D3C5C	ori    a2, zero, $007f
    801D3C60	addiu  a3, sp, $0040
    801D3C64	ori    v0, zero, $0100
    801D3C68	sh     zero, $0040(sp)
    801D3C6C	sh     zero, $0042(sp)
    801D3C70	sh     v0, $0044(sp)
    801D3C74	jal    $80026a34
    801D3C78	sh     v0, $0046(sp)
    801D3C7C	jal    $8001e040
    801D3C80	addu   a0, s1, zero
    801D3C84	j      L1d4480 [$801d4480]
    801D3C88	nop
    801D3C8C	lui    s1, $801e
    801D3C90	addiu  s1, s1, $3d8b
    801D3C94	lb     v0, $0000(s1)
    801D3C98	nop
    801D3C9C	sll    v1, v0, $01
    801D3CA0	addu   v1, v1, v0
    801D3CA4	lui    at, $801f
    801D3CA8	addiu  at, at, $8f38 (=-$70c8)
    801D3CAC	addu   at, at, v1
    801D3CB0	lbu    v0, $0000(at)
    801D3CB4	nop
    801D3CB8	bne    v0, zero, L1d3cd0 [$801d3cd0]
    801D3CBC	nop
    [801e2cf8] = w(0);
    801D3CC8	j      L1d4480 [$801d4480]
    801D3CCC	nop

    L1d3cd0:	; 801D3CD0
    801D3CD0	jal    $800269d0
    801D3CD4	ori    s3, zero, $0004
    801D3CD8	lui    v0, $801e
    801D3CDC	lw     v0, $3d58(v0)
    801D3CE0	nop
    801D3CE4	sll    a0, v0, $02
    801D3CE8	addu   a0, a0, v0
    801D3CEC	sll    a0, a0, $0c
    801D3CF0	lui    v0, $801d
    801D3CF4	addiu  v0, v0, $4edc
    801D3CF8	jal    $800269c0
    801D3CFC	addu   a0, a0, v0
    801D3D00	lui    a1, $801e
    801D3D04	lb     a1, $3d9d(a1)
    801D3D08	ori    a0, zero, $0008
    801D3D0C	sll    a1, a1, $06
    801D3D14	ori    a1, a1, $0038
    func1eb2c; // cursor

    801D3D18	lui    v0, $801e
    801D3D1C	lh     v0, $3d9a(v0)
    801D3D20	nop
    801D3D24	bne    v0, zero, L1d3d30 [$801d3d30]
    801D3D28	nop
    801D3D2C	ori    s3, zero, $0003

    L1d3d30:	; 801D3D30
    801D3D30	beq    s3, zero, L1d3e00 [$801d3e00]
    801D3D34	addu   s0, zero, zero
    801D3D38	addiu  s2, s1, $0009
    801D3D3C	addu   s1, zero, zero

    loop1d3d40:	; 801D3D40
    801D3D40	lh     v1, $0000(s2)
    801D3D44	lui    v0, $8006
    801D3D48	lhu    v0, $2f3c(v0)
    801D3D4C	addu   v1, s0, v1
    801D3D50	srav   v0, v1, v0
    801D3D54	andi   v0, v0, $0001
    801D3D58	beq    v0, zero, L1d3d98 [$801d3d98]
    801D3D5C	ori    a0, zero, $0032
    801D3D60	jal    $8001de70
    801D3D64	nop
    801D3D68	addu   a0, zero, zero
    801D3D6C	lb     a1, $000d(s2)
    801D3D70	lh     a2, $0000(s2)
    801D3D74	sll    a1, a1, $03
    801D3D78	addiu  a1, a1, $001d
    801D3D7C	addu   a1, s1, a1
    801D3D80	jal    func1d370c [$801d370c]
    801D3D84	addu   a2, s0, a2
    801D3D88	jal    $8001deb0
    801D3D8C	addiu  s1, s1, $0040
    801D3D90	j      L1d3df4 [$801d3df4]
    801D3D94	addiu  s0, s0, $0001

    L1d3d98:	; 801D3D98
    801D3D98	lui    a2, $801e
    801D3D9C	addiu  a2, a2, $2e1c
    801D3DA0	lb     a1, $000d(s2)
    801D3DA4	ori    a3, zero, $0006
    801D3DA8	sll    a1, a1, $03
    801D3DAC	addiu  a1, a1, $0037
    801D3DB4	addu   a1, s1, a1
    func26f44;

    801D3DB8	lui    a1, $801e
    801D3DBC	addiu  a1, a1, $3660
    801D3DC0	jal    $8001de40
    801D3DC4	addiu  a0, sp, $0038
    801D3DC8	addiu  a0, sp, $0038
    801D3DCC	lb     a2, $000d(s2)
    801D3DD0	addu   a1, zero, zero
    801D3DD4	sll    a2, a2, $03
    801D3DD8	addiu  a2, a2, $001d
    801D3DDC	jal    $8001de24
    801D3DE0	addu   a2, s1, a2
    801D3DE4	jal    $8001e040
    801D3DE8	addiu  a0, sp, $0038
    801D3DEC	addiu  s1, s1, $0040
    801D3DF0	addiu  s0, s0, $0001

    L1d3df4:	; 801D3DF4
    801D3DF4	slt    v0, s0, s3
    801D3DF8	bne    v0, zero, loop1d3d40 [$801d3d40]
    801D3DFC	nop

    L1d3e00:	; 801D3E00
    801D3E00	jal    $80026b5c
    801D3E04	ori    a0, zero, $0080
    801D3E08	addiu  a1, sp, $0040
    801D3E0C	lui    v1, $801e
    801D3E10	lw     v1, $3d58(v1)
    801D3E14	ori    v0, zero, $001d
    801D3E18	sh     v0, $0042(sp)
    801D3E1C	ori    v0, zero, $016c
    801D3E20	sh     v0, $0044(sp)
    801D3E24	ori    v0, zero, $00c3
    801D3E28	sh     v0, $0046(sp)
    801D3E2C	lui    v0, $801e
    801D3E30	addiu  v0, v0, $3e34
    801D3E34	sh     zero, $0040(sp)
    801D3E38	sll    a0, v1, $01
    801D3E3C	addu   a0, a0, v1
    801D3E40	sll    a0, a0, $03
    801D3E44	subu   a0, a0, v1
    801D3E48	sll    a0, a0, $02
    801D3E4C	jal    $80026a94
    801D3E50	addu   a0, a0, v0
    801D3E54	ori    a0, zero, $000a
    801D3E58	ori    a1, zero, $000b
    801D3E5C	lui    s1, $801e
    801D3E60	addiu  s1, s1, $2d44
    801D3E64	addu   a2, s1, zero
    801D3E6C	ori    a3, zero, $0007
    func26f44;

    801D3E70	ori    a0, zero, $00ce
    801D3E74	ori    a1, zero, $000b
    801D3E78	addiu  s0, s1, $00fc
    801D3E7C	addu   a2, s0, zero
    801D3E84	ori    a3, zero, $0006
    func26f44;

    801D3E88	jal    $80026b70
    801D3E8C	addu   a0, s0, zero
    801D3E90	addiu  a0, v0, $00d0
    801D3E94	ori    a1, zero, $000b
    801D3E98	ori    a3, zero, $0007
    801D3E9C	addiu  s1, s1, $ffb8 (=-$48)
    801D3EA0	lui    v0, $801e
    801D3EA4	lh     v0, $3d94(v0)
    801D3EA8	lui    v1, $801e
    801D3EAC	lb     v1, $3d9d(v1)
    801D3EB0	addiu  v0, v0, $000d
    801D3EB4	addu   v1, v1, v0
    801D3EB8	sll    a2, v1, $03
    801D3EBC	addu   a2, a2, v1
    801D3EC0	sll    a2, a2, $02
    801D3EC8	addu   a2, a2, s1
    func26f44;

    801D3ECC	addiu  a0, sp, $0038
    801D3ED0	ori    a1, zero, $00c8
    801D3ED4	ori    a2, zero, $0005
    801D3ED8	ori    a3, zero, $004e
    801D3EDC	ori    v0, zero, $0018
    801D3EE0	jal    $8001de0c
    801D3EE4	sw     v0, $0010(sp)
    801D3EE8	jal    $8001e040
    801D3EEC	addiu  a0, sp, $0038
    801D3EF0	jal    $800269e8
    801D3EF4	nop
    801D3EF8	j      L1d4480 [$801d4480]
    801D3EFC	nop
    801D3F00	lui    v1, $801e
    801D3F04	lw     v1, $2cf8(v1)
    801D3F08	ori    v0, zero, $0002
    801D3F0C	bne    v1, v0, L1d3f24 [$801d3f24]
    801D3F10	ori    s2, zero, $00e0
    801D3F14	ori    s2, zero, $0040
    801D3F18	ori    s1, zero, $0020
    801D3F1C	j      L1d3f2c [$801d3f2c]
    801D3F20	ori    s0, zero, $00a0

    L1d3f24:	; 801D3F24
    801D3F24	ori    s1, zero, $0080
    801D3F28	addu   s0, zero, zero

    L1d3f2c:	; 801D3F2C
    801D3F2C	ori    a0, zero, $000a
    801D3F30	ori    a1, zero, $000b
    801D3F34	lui    a2, $801e
    801D3F38	addiu  a2, a2, $2eac
    801D3F40	ori    a3, zero, $0007
    func26f44;

    801D3F44	lui    v0, $801e
    801D3F48	lw     v0, $3f1c(v0)
    801D3F4C	nop
    801D3F50	bne    v0, zero, L1d3fb0 [$801d3fb0]
    801D3F54	ori    v0, zero, $0018
    801D3F58	ori    a0, zero, $007a
    801D3F5C	ori    a1, zero, $0075
    801D3F60	lui    a2, $801e
    801D3F64	lw     a2, $3f20(a2)
    801D3F68	ori    a3, zero, $0008
    801D3F6C	sw     s2, $0010(sp)
    801D3F70	sw     s1, $0014(sp)
    801D3F74	sw     s0, $0018(sp)
    801D3F78	addiu  a2, a2, $0001
    801D3F7C	jal    $800285ac
    801D3F80	sll    a2, a2, $03
    801D3F84	addu   a0, zero, zero
    801D3F88	ori    a1, zero, $0001
    801D3F8C	ori    a2, zero, $003f
    801D3F90	addiu  a3, sp, $0040
    801D3F94	ori    v0, zero, $00ff
    801D3F98	sh     zero, $0040(sp)
    801D3F9C	sh     zero, $0042(sp)
    801D3FA0	sh     v0, $0044(sp)
    801D3FA4	jal    $80026a34
    801D3FA8	sh     v0, $0046(sp)
    801D3FAC	ori    v0, zero, $0018

    L1d3fb0:	; 801D3FB0
    801D3FB0	sw     v0, $0010(sp)
    801D3FB4	addiu  a0, sp, $0038
    801D3FB8	ori    a1, zero, $0070
    801D3FBC	ori    a2, zero, $006d
    801D3FC0	j      L1d4200 [$801d4200]
    801D3FC4	ori    a3, zero, $008c
    V1 = w[801e3d54];
    801D3FD0	ori    v0, zero, $0002
    801D3FD4	beq    v1, v0, L1d4480 [$801d4480]
    801D3FD8	nop
    801D3FDC	lui    s2, $801e
    801D3FE0	addiu  s2, s2, $2dd4
    801D3FE4	jal    $80026b70
    801D3FE8	addu   a0, s2, zero
    801D3FEC	addiu  s1, v0, $0010
    801D3FF0	srl    s0, s1, $1f
    801D3FF4	addu   s0, s1, s0
    801D3FF8	sra    s0, s0, $01
    801D3FFC	ori    a0, zero, $00be
    801D4000	subu   a0, a0, s0
    801D4004	ori    a1, zero, $0073
    801D4008	addu   a2, s2, zero
    801D4010	ori    a3, zero, $0007
    func26f44;

    801D4014	ori    v0, zero, $0018
    801D4018	sw     v0, $0010(sp)
    801D401C	addiu  a0, sp, $0038
    801D4020	ori    a1, zero, $00b6
    801D4024	subu   a1, a1, s0
    801D4028	ori    a2, zero, $006d
    801D402C	j      L1d4200 [$801d4200]
    801D4030	addu   a3, s1, zero
    801D4034	andi   v0, s0, $0002
    801D4038	beq    v0, zero, L1d4074 [$801d4074]
    801D403C	nop
    801D4040	lui    a0, $801e
    801D4044	lh     a0, $3668(a0)
    801D4048	lui    v0, $801e
    801D404C	lb     v0, $3d8b(v0)
    801D4050	addiu  a0, a0, $ffee (=-$12)
    801D4054	sll    a1, v0, $01
    801D4058	addu   a1, a1, v0
    801D405C	sll    a1, a1, $02
    801D4060	lui    v0, $801e
    801D4064	lh     v0, $366a(v0)
    801D4068	addiu  a1, a1, $0006
    801D4070	addu   a1, v0, a1
    func1eb2c; // cursor

    L1d4074:	; 801D4074
    801D4074	lui    s0, $801e
    801D4078	addiu  s0, s0, $3668
    801D407C	lui    s3, $801e
    801D4080	addiu  s3, s3, $2d68
    801D4084	addu   a2, s3, zero
    801D4088	lh     a0, $0000(s0)
    801D408C	lui    a1, $801e
    801D4090	lh     a1, $366a(a1)
    801D4094	lui    a3, $801f
    801D4098	lbu    a3, $8f38(a3)
    801D409C	addiu  a0, a0, $000c
    801D40A0	addiu  a1, a1, $0005
    801D40A4	sltu   a3, zero, a3
    801D40A8	subu   a3, zero, a3
    801D40B0	andi   a3, a3, $0007
    func26f44;

    801D40B4	addiu  a2, s3, $0024
    801D40B8	lh     a0, $0000(s0)
    801D40BC	lui    a1, $801e
    801D40C0	lh     a1, $366a(a1)
    801D40C4	lui    a3, $801f
    801D40C8	lbu    a3, $8f3b(a3)
    801D40CC	addiu  a0, a0, $000c
    801D40D0	addiu  a1, a1, $0011
    801D40D4	sltu   a3, zero, a3
    801D40D8	subu   a3, zero, a3
    801D40E0	andi   a3, a3, $0007
    func26f44;

    801D40E4	addu   a0, zero, zero
    801D40E8	ori    a1, zero, $0001
    801D40EC	ori    a2, zero, $007f
    801D40F0	addiu  a3, sp, $0040
    801D40F4	ori    v0, zero, $0100
    801D40F8	sh     zero, $0040(sp)
    801D40FC	sh     zero, $0042(sp)
    801D4100	sh     v0, $0044(sp)
    801D4104	jal    $80026a34
    801D4108	sh     v0, $0046(sp)
    801D410C	jal    $8001e040
    801D4110	addu   a0, s0, zero
    801D4114	ori    a0, zero, $000a
    801D4118	ori    a1, zero, $000b
    801D411C	lui    s0, $801e
    801D4120	addiu  s0, s0, $3320
    801D4124	addu   a2, s0, zero
    801D412C	ori    a3, zero, $0007
    func26f44;

    801D4130	addiu  s0, s0, $0030
    801D4134	jal    $80026b70
    801D4138	addu   a0, s0, zero
    801D413C	addiu  s2, v0, $0010
    801D4140	srl    s1, s2, $1f
    801D4144	addu   s1, s2, s1
    801D4148	sra    s1, s1, $01
    801D414C	ori    a0, zero, $00be
    801D4150	subu   a0, a0, s1
    801D4154	addu   a2, s0, zero
    801D4158	lui    a1, $801e
    801D415C	lh     a1, $366e(a1)
    801D4160	ori    a3, zero, $0007
    801D4168	addiu  a1, a1, $0063
    func26f44;

    801D416C	ori    s0, zero, $00e4
    801D4170	subu   s0, s0, s1
    801D4174	addu   a0, s0, zero
    801D4178	addiu  a2, s3, $045c
    801D417C	lui    a1, $801e
    801D4180	lh     a1, $366e(a1)
    801D4184	ori    a3, zero, $0007
    801D418C	addiu  a1, a1, $0070
    func26f44;

    801D4190	addu   a0, s0, zero
    801D4194	addiu  a2, s3, $0480
    801D4198	lui    a1, $801e
    801D419C	lh     a1, $366e(a1)
    801D41A0	ori    a3, zero, $0007
    801D41A8	addiu  a1, a1, $007c
    func26f44;

    801D41AC	ori    a0, zero, $00c8
    801D41B0	subu   a0, a0, s1
    801D41B4	lui    v1, $801e
    801D41B8	lb     v1, $3df7(v1)
    801D41BC	lui    a1, $801e
    801D41C0	lh     a1, $366e(a1)
    801D41C4	sll    v0, v1, $01
    801D41C8	addu   v0, v0, v1
    801D41CC	sll    v0, v0, $02
    801D41D0	addiu  a1, a1, $0073
    801D41D8	addu   a1, v0, a1
    func1eb2c; // cursor

    801D41DC	addiu  a0, sp, $0038
    801D41E0	ori    a1, zero, $00b6
    801D41E4	subu   a1, a1, s1
    801D41E8	addu   a3, s2, zero
    801D41EC	lui    a2, $801e
    801D41F0	lh     a2, $366e(a2)
    801D41F4	ori    v0, zero, $0030
    801D41F8	sw     v0, $0010(sp)
    801D41FC	addiu  a2, a2, $005d

    L1d4200:	; 801D4200
    801D4200	jal    $8001de0c
    801D4204	nop
    801D4208	jal    $8001e040
    801D420C	addiu  a0, sp, $0038
    801D4210	j      L1d4480 [$801d4480]
    801D4214	nop

    case 7: // 18421D80
    {
        A0 = h[801e3668] - 12;
        A1 = h[801e366a] + b[801e3e09] * c + 6;
        func1eb2c; // cursor



        S1 = 801e317c;
        A2 = S1; // text "NEW GAME"
        A3 = 7;
        A0 = h[801e3668] + 8; // 0x96 + 8
        A1 = h[801e366a] + 6; // 0x5D + 6
        func26f44;

        A0 = h[801e3668] + 8;
        A1 = h[801e366a] + 12;
        A2 = S1 - 318; // text "Continue?"

        if ((bu[801e8f38] == 0) && (bu[801e8f3b] == 0))
        {
            A3 = 7; // white
        }
        else
        {
            A3 = 0; // gray
        }
        func26f44;



        A0 = 0;
        A1 = 1;
        A2 = 7f;
        A3 = SP + 40;
        [SP + 40] = h(0);
        [SP + 42] = h(0);
        [SP + 44] = h(100)
        [SP + 46] = h(100)
        801D42E0	jal    $80026a34

        packet = w[80062f24];

        A0 = packet;
        801D42F4	jal    $800468fc

        [packet + 4] = b(60);
        [packet + 5] = b(60);
        [packet + 6] = b(60);
        [packet + 8] = h(6f);
        [packet + a] = h(54);
        [packet + c] = b(0);
        [packet + d] = b(0);
        [packet + 10] = h(119);
        [packet + 12] = h(54);
        [packet + 14] = b(96);
        [packet + 15] = b(0);
        [packet + 18] = h(6f);
        [packet + 1a] = h(ea);
        [packet + 1c] = b(0);
        [packet + 1d] = b(96);
        [packet + 20] = h(119);
        [packet + 22] = h(ea);
        [packet + 24] = b(96);
        [packet + 25] = b(96);

        A0 = 0;
        A1 = 1e0;
        801D4428	jal    $80046634

        [packet + e] = h(V0);

        A0 = 1;
        A1 = 0;
        A2 = 380;
        A3 = 0;
        801D4448	jal    $8004656c

        [packet + 16] = h(V0);

        A0 = w[80062fc4];
        A1 = packet;
        system_add_render_packet_to_queue;

        [80062f24] = w(packet + 28);
    }
    break;
}
L1d4480:	; 801D4480
L1d4488:	; 801D4488
if (w[801e2cf8] != 7)
{
    A0 = 126;
    A1 = b;
    A2 = 801e2cfc; // text "Load"
    A3 = 7;
    func26f44;

    801D44A8	addiu  a0, sp, $0038
    801D44AC	ori    a1, zero, $0116
    801D44B0	ori    a2, zero, $0005
    801D44B4	ori    a3, zero, $0056
    801D44B8	ori    s0, zero, $0018
    801D44BC	jal    $8001de0c
    801D44C0	sw     s0, $0010(sp)
    801D44C4	jal    $8001e040
    801D44C8	addiu  a0, sp, $0038
    801D44CC	addiu  a0, sp, $0038
    801D44D0	addu   a1, zero, zero
    801D44D4	ori    a2, zero, $0005
    801D44D8	ori    a3, zero, $016c
    801D44DC	jal    $8001de0c
    801D44E0	sw     s0, $0010(sp)
    801D44E4	jal    $8001e040
    801D44E8	addiu  a0, sp, $0038
}

A0 = 126;
801D44EC	jal    $8001f6b4
801D44F0	nop
801D44F4	andi   v0, v0, $00ff
801D44F8	bne    v0, zero, L1d4c10 [$801d4c10]
801D44FC	ori    v0, zero, $0001
V1 = w[801e3d54];

801D450C	bne    v1, v0, L1d4c10 [$801d4c10]

switch(w[801e2cf8])
{
    FC461D80 1
    B4471D80 2
    C8481D80 3
    FC481D80 4
    104A1D80 6

    case 0: // 48451D80
    {
        V1 = hu[80062d7c];
        if ((V1 & 0020) == 0) // circle not pressed
        {
            if (V1 & 0040) // cross was pressed
            {
                A0 = 4;
                func1d2b58; // play sound

                [801e2cf8] = w(7); // set start screen with newgame
                return w[801e3698];
            }
            A0 = 801e3d80;
            801D4C08	jal    $800264a8
        }
        else
        {
            801D4560	lui    s0, $801e
            801D4564	addiu  s0, s0, $3d8b
            801D4568	lb     v1, $0000(s0)
            801D456C	nop
            801D4570	slti   v0, v1, $0002
            801D4574	beq    v0, zero, L1d4c10 [$801d4c10]
            801D4578	nop
            801D457C	bltz   v1, L1d4c10 [$801d4c10]
            801D4580	sll    v0, v1, $01
            801D4584	addu   v0, v0, v1
            801D4588	lui    at, $801f
            801D458C	addiu  at, at, $8f38 (=-$70c8)
            801D4590	addu   at, at, v0
            801D4594	lbu    v0, $0000(at)
            801D4598	nop
            801D459C	beq    v0, zero, L1d46a8 [$801d46a8]
            801D45A0	nop
            A0 = 1;
            func1d2b58; // play sound

            801D45AC	lb     v0, $0000(s0)
            801D45B0	nop
            801D45B4	sll    v1, v0, $01
            801D45B8	addu   v1, v1, v0
            801D45BC	lui    at, $801f
            801D45C0	addiu  at, at, $8f3a (=-$70c6)
            801D45C4	addu   at, at, v1
            801D45C8	lbu    v0, $0000(at)
            801D45CC	nop
            801D45D0	beq    v0, zero, L1d4620 [$801d4620]
            801D45D4	addiu  a0, s0, $0061
            801D45D8	addu   a1, zero, zero
            801D45DC	ori    a2, zero, $0001
            801D45E0	ori    a3, zero, $0001
            [801e2cf8] = w(6);
            801D45F0	ori    v0, zero, $0002
            801D45F4	ori    v1, zero, $0001
            801D45F8	sw     v0, $0010(sp)
            801D45FC	sw     zero, $0014(sp)
            801D4600	sw     zero, $0018(sp)
            801D4604	sw     v1, $001c(sp)
            801D4608	sw     v0, $0020(sp)
            801D460C	sw     zero, $0024(sp)
            801D4610	sw     zero, $0028(sp)
            801D4614	sw     zero, $002c(sp)
            801D4618	j      L1d4698 [$801d4698]
            801D461C	sw     v1, $0030(sp)

            L1d4620:	; 801D4620
            801D4620	addiu  a0, s0, $0007
            801D4624	addu   a1, zero, zero
            801D4628	addu   a2, zero, zero
            801D462C	ori    a3, zero, $0001
            801D4630	ori    v0, zero, $000a
            801D4634	lui    at, $801e
            801D4638	sw     v0, $3f18(at)
            801D4640	ori    v1, zero, $0001
            [801e2cf8] = w(2);
            801D464C	ori    v0, zero, $0003
            801D4650	sw     v0, $0010(sp)
            801D4654	ori    v0, zero, $000f
            801D4658	lui    at, $801e
            801D465C	sw     zero, $3f20(at)
            801D4660	lui    at, $801e
            801D4664	sw     zero, $3f14(at)
            801D4668	lui    at, $8006
            801D466C	sh     zero, $2f3c(at)
            801D4670	lui    at, $801e
            801D4674	sw     v1, $3f1c(at)
            801D4678	sw     zero, $0014(sp)
            801D467C	sw     zero, $0018(sp)
            801D4680	sw     v1, $001c(sp)
            801D4684	sw     v0, $0020(sp)
            801D4688	sw     zero, $0024(sp)
            801D468C	sw     zero, $0028(sp)
            801D4690	sw     zero, $002c(sp)
            801D4694	sw     zero, $0030(sp)

            L1d4698:	; 801D4698
            801D4698	jal    $80026448
            801D469C	sw     zero, $0034(sp)
            801D46A0	j      L1d4c10 [$801d4c10]
            801D46A4	nop

            L1d46a8:	; 801D46A8
            A0 = 3;
            func1d2b58; // play sound

            801D46B0	lui    a0, $801e
            801D46B4	addiu  a0, a0, $33b0
            801D46B8	jal    $8001f6c0
            801D46BC	ori    a1, zero, $0007
            801D46C0	j      L1d4c10 [$801d4c10]
            801D46C4	nop
        }
    }
    break;

    801D46FC	lui    s0, $801e
    801D4700	addiu  s0, s0, $3da1
    801D4704	lb     s1, $0000(s0)
    801D4708	jal    func1d2da8 [$801d2da8]
    801D470C	addiu  a0, s0, $fff1 (=-$f)
    801D4710	lb     v0, $0000(s0)
    801D4714	nop
    801D4718	bne    v0, zero, L1d4c10 [$801d4c10]
    801D471C	nop
    801D4720	bne    s1, zero, L1d4c10 [$801d4c10]
    801D4724	nop
    801D4728	lui    v1, $8006
    801D472C	lhu    v1, $2d7c(v1)
    801D4730	nop
    801D4734	andi   v0, v1, $0020
    801D4738	beq    v0, zero, L1d4794 [$801d4794]
    801D473C	andi   v0, v1, $0040
    801D4740	lui    v0, $801e
    801D4744	lb     v0, $3d9d(v0)
    801D4748	lui    a0, $801e
    801D474C	lh     a0, $3d94(a0)
    801D4750	lui    v1, $8006
    801D4754	lhu    v1, $2f3c(v1)
    801D4758	addu   v0, v0, a0
    801D475C	srav   v1, v0, v1
    801D4760	andi   v1, v1, $0001
    if (V1 == 0)
    {
        A0 = 3;
        func1d2b58; // play sound

        801D4BF8	j      L1d4c10 [$801d4c10]
        801D4BFC	nop
    }

    A0 = 1;
    func1d2b58; // play sound

    801D4774	ori    v0, zero, $0004
    801D4778	lui    at, $801e
    801D477C	sw     v0, $2cf8(at)
    801D4780	ori    v0, zero, $000a
    801D4784	lui    at, $801e
    801D4788	sw     v0, $3f18(at)
    801D478C	j      L1d4c10 [$801d4c10]
    801D4790	nop

    L1d4794:	; 801D4794
    801D4794	beq    v0, zero, L1d4c10 [$801d4c10]
    801D4798	nop
    A0 = 4;
    func1d2b58; // play sound

    801D47A4	lui    at, $801e
    801D47A8	sw     zero, $2cf8(at)
    801D47AC	j      L1d4c10 [$801d4c10]
    801D47B0	nop
    801D47B4	lui    v0, $801e
    801D47B8	lw     v0, $3f18(v0)
    801D47BC	nop
    801D47C0	bne    v0, zero, L1d4910 [$801d4910]
    801D47C4	addiu  v0, v0, $ffff (=-$1)
    801D47C8	lui    v0, $801e
    801D47CC	lw     v0, $3f1c(v0)
    801D47D0	nop
    801D47D4	beq    v0, zero, L1d480c [$801d480c]
    801D47D8	nop
    801D47DC	lui    a0, $801e
    801D47E0	lb     a0, $3d8b(a0)
    801D47E4	lui    at, $801e
    801D47E8	sw     zero, $3f18(at)
    801D47EC	lui    at, $801e
    801D47F0	sw     zero, $3f1c(at)
    801D47F4	jal    func1d1c2c [$801d1c2c]
    801D47F8	nop
    801D47FC	lui    at, $8006
    801D4800	sh     v0, $2f3c(at)
    801D4804	j      L1d4c10 [$801d4c10]
    801D4808	nop

    L1d480c:	; 801D480C
    801D480C	lui    v0, $8006
    801D4810	lhu    v0, $2f3c(v0)
    801D4814	lui    a1, $801e
    801D4818	lw     a1, $3f20(a1)
    801D481C	nop
    801D4820	srav   v0, a1, v0
    801D4824	andi   v0, v0, $0001
    801D4828	beq    v0, zero, L1d4844 [$801d4844]
    801D482C	addu   s1, zero, zero
    801D4830	lui    a0, $801e
    801D4834	lb     a0, $3d8b(a0)
    801D4838	jal    func1d3698 [$801d3698]
    801D483C	nop
    801D4840	addu   s1, v0, zero

    L1d4844:	; 801D4844
    801D4844	lui    v0, $801e
    801D4848	lw     v0, $3f20(v0)
    801D484C	nop
    801D4850	addiu  v0, v0, $0001
    801D4854	lui    at, $801e
    801D4858	sw     v0, $3f20(at)
    801D485C	beq    s1, zero, L1d4884 [$801d4884]
    801D4860	nop
    801D4864	lui    at, $801e
    801D4868	sw     zero, $2cf8(at)
    801D486C	lui    a0, $801e
    801D4870	addiu  a0, a0, $3530
    801D4874	jal    $8001f6c0
    801D4878	ori    a1, zero, $0002

    A0 = 3;
    func1d2b58; // play sound


    L1d4884:	; 801D4884
    801D4884	lui    v1, $801e
    801D4888	lw     v1, $3f20(v1)
    801D488C	ori    v0, zero, $000f
    801D4890	bne    v1, v0, L1d4c10 [$801d4c10]
    801D4894	ori    v0, zero, $000e
    801D4898	lui    at, $801e
    801D489C	sw     v0, $3f20(at)
    801D48A0	ori    v0, zero, $0003
    801D48A4	lui    at, $801e
    801D48A8	sw     v0, $2cf8(at)
    801D48AC	ori    v0, zero, $000a
    801D48B0	lui    at, $801e
    801D48B4	sw     v0, $3f18(at)

    A0 = 2;
    func1d2b58; // play sound

    801D48C0	j      L1d4c10 [$801d4c10]
    801D48C4	nop
    801D48C8	lui    v1, $801e
    801D48CC	lw     v1, $3f18(v1)
    801D48D0	nop
    801D48D4	bne    v1, zero, L1d48ec [$801d48ec]
    801D48D8	addiu  v0, v1, $ffff (=-$1)
    801D48DC	ori    v0, zero, $0001
    801D48E0	lui    at, $801e
    801D48E4	sw     v0, $2cf8(at)
    801D48E8	addiu  v0, v1, $ffff (=-$1)

    L1d48ec:	; 801D48EC
    801D48EC	lui    at, $801e
    801D48F0	sw     v0, $3f18(at)
    801D48F4	j      L1d4c10 [$801d4c10]
    801D48F8	nop
    801D48FC	lui    v0, $801e
    801D4900	lw     v0, $3f18(v0)
    801D4904	nop
    801D4908	beq    v0, zero, L1d4920 [$801d4920]
    801D490C	addiu  v0, v0, $ffff (=-$1)

    L1d4910:	; 801D4910
    801D4910	lui    at, $801e
    801D4914	sw     v0, $3f18(at)
    801D4918	j      L1d4c10 [$801d4c10]
    801D491C	nop

    L1d4920:	; 801D4920
    801D4920	lui    a0, $801e
    801D4924	lb     a0, $3d9d(a0)
    801D4928	ori    v0, zero, $0001
    801D492C	lui    at, $8006
    801D4930	sb     v0, $2d99(at)
    801D4934	lui    v0, $801e
    801D4938	lh     v0, $3d94(v0)
    801D493C	lui    v1, $801e
    801D4940	lb     v1, $3d8b(v1)
    801D4944	nop
    801D4948	beq    v1, zero, L1d4954 [$801d4954]
    801D494C	addu   a0, a0, v0
    801D4950	ori    a0, a0, $0010

    L1d4954:	; 801D4954
    801D4954	jal    func1d1f40 [$801d1f40]
    801D4958	nop
    801D495C	sll    v0, v0, $10
    801D4960	sra    s1, v0, $10
    801D4964	bne    s1, zero, L1d49dc [$801d49dc]
    801D4968	ori    v0, zero, $0001
    801D496C	ori    a0, zero, $10f0
    801D4970	lui    s0, $800a
    801D4974	addiu  s0, s0, $c6e4 (=-$391c)
    801D4978	jal    func1d1950 [$801d1950]
    801D497C	addiu  a1, s0, $0004
    801D4980	lw     v1, $0000(s0)
    801D4984	andi   v0, v0, $ffff
    801D4988	beq    v1, v0, L1d49b0 [$801d49b0]
    801D498C	ori    v0, zero, $0001
    801D4990	lui    at, $801e
    801D4994	sw     v0, $2cf8(at)

    A0 = 3;
    func1d2b58; // play sound

    801D49A0	lui    a0, $801e
    801D49A4	addiu  a0, a0, $3158
    801D49A8	j      L1d49f8 [$801d49f8]
    801D49AC	addu   a1, zero, zero

    L1d49b0:	; 801D49B0
    A0 = d0;
    func1d2b58; // play sound

    801D49B8	lui    a0, $800a
    801D49BC	lhu    a0, $d7be(a0)
    [801e3d54] = w(2);

    A0 = A0 & 3;
    func1d2d10; // play sound by selection

    801D49D4	j      L1d4a00 [$801d4a00]
    801D49D8	nop

    L1d49dc:	; 801D49DC
    801D49DC	lui    at, $801e
    801D49E0	sw     v0, $2cf8(at)

    A0 = 3;
    func1d2b58; // play sound

    801D49EC	lui    a0, $801e
    801D49F0	addiu  a0, a0, $2e88
    801D49F4	addu   a1, s1, zero

    L1d49f8:	; 801D49F8
    801D49F8	jal    $8001f6c0
    801D49FC	nop

    L1d4a00:	; 801D4A00
    801D4A00	lui    at, $8006
    801D4A04	sb     zero, $2d99(at)
    801D4A08	j      L1d4c10 [$801d4c10]
    801D4A0C	nop
    801D4A10	lui    a0, $801e
    801D4A14	addiu  a0, a0, $3dec
    801D4A18	jal    $800264a8
    801D4A1C	nop
    801D4A20	lui    v1, $8006
    801D4A24	lhu    v1, $2d7c(v1)
    801D4A28	nop
    801D4A2C	andi   v0, v1, $0020
    801D4A30	beq    v0, zero, L1d4ae8 [$801d4ae8]
    801D4A34	andi   v0, v1, $0040
    801D4A38	lui    v0, $801e
    801D4A3C	lb     v0, $3df7(v0)
    801D4A40	nop
    801D4A44	bne    v0, zero, L1d4af0 [$801d4af0]
    801D4A48	nop
    801D4A4C	lui    v0, $801e
    801D4A50	lb     v0, $3d8b(v0)
    801D4A54	lui    a0, $801d
    801D4A58	addiu  a0, a0, $03c0
    801D4A5C	beq    v0, zero, L1d4a6c [$801d4a6c]
    801D4A60	nop
    801D4A64	lui    a0, $801d
    801D4A68	addiu  a0, a0, $03b8

    L1d4a6c:	; 801D4A6C
    801D4A6C	jal    $80042b60
    801D4A70	nop
    801D4A74	addu   v1, v0, zero
    801D4A78	lui    at, $801e
    801D4A7C	sw     zero, $2cf8(at)
    801D4A80	ori    v0, zero, $0001
    801D4A84	bne    v1, v0, L1d4ad0 [$801d4ad0]
    801D4A88	nop
    801D4A8C	lui    a0, $801e
    801D4A90	addiu  a0, a0, $32c0
    801D4A94	lui    v1, $801e
    801D4A98	lb     v1, $3d8b(v1)
    801D4A9C	nop
    801D4AA0	sll    v0, v1, $01
    801D4AA4	addu   v0, v0, v1
    801D4AA8	lui    at, $801f
    801D4AAC	addiu  at, at, $8f3a (=-$70c6)
    801D4AB0	addu   at, at, v0
    801D4AB4	sb     zero, $0000(at)
    801D4AB8	jal    $8001f6c0
    801D4ABC	ori    a1, zero, $0007

    A0 = d0;
    func1d2b58; // play sound

    801D4AC8	j      L1d4c10 [$801d4c10]
    801D4ACC	nop

    L1d4ad0:	; 801D4AD0
    801D4AD0	lui    a0, $801e
    801D4AD4	addiu  a0, a0, $32f0
    801D4AD8	jal    $8001f6c0
    801D4ADC	ori    a1, zero, $0007
    A0 = 3;
    func1d2b58; // play sound

    801D4BF8	j      L1d4c10 [$801d4c10]
    801D4BFC	nop

    L1d4ae8:	; 801D4AE8
    801D4AE8	beq    v0, zero, L1d4c10 [$801d4c10]
    801D4AEC	nop

    L1d4af0:	; 801D4AF0
    801D4AF0	lui    at, $801e
    801D4AF4	sw     zero, $2cf8(at)

    A0 = 4;
    func1d2b58; // play sound

    801D4B00	j      L1d4c10 [$801d4c10]
    801D4B04	nop

    case 7: // 084B1D80
    {
        if (hu[80062d7c] & 0020) // circle pressed
        {
            S0 = b[801e3e09];
            if (S0 == 0)
            {
                A0 = d0; // new game
                func1d2b58; // play sound

                [801e3698] = w(1);
                [801e3d54] = w(2);
            }
            else if (S0 == 1)
            {
                if ((bu[801e8f38] == 0) && (bu[801e8f3b] == 0))
                {
                    A0 = 3; // forbid sound
                    func1d2b58; // play sound
                }
                else
                {
                    A0 = 1;
                    func1d2b58; // play sound

                    A0 = 801e3d80;
                    A1 = 0;
                    A2 = 0;
                    A3 = 1;
                    [SP + 10] = w(2);
                    [SP + 10] = w(0);
                    [SP + 18] = w(0);
                    [SP + 1c] = w(S0);
                    [SP + 20] = w(2);
                    [SP + 24] = w(0);
                    [SP + 28] = w(0);
                    [SP + 2c] = w(0);
                    [SP + 30] = w(S0);
                    [SP + 34] = w(0)
                    801D4BD8	jal    $80026448

                    [801e2cf8] = w(0);
                }
            }
        }
        else
        {
            A0 = 801e3dfe;
            801D4C08	jal    $800264a8
        }
    }
    break;
}

L1d4c10:	; 801D4C10
return w[801e3698];
////////////////////////////////


func1d4c38:	; 801D4C38
801D4C38	addiu  sp, sp, $ffe8 (=-$18)
801D4C3C	sw     ra, $0010(sp)
801D4C40	jal    $80025ed4
801D4C44	nop
801D4C48	lui    a0, $8007
801D4C4C	addiu  a0, a0, $56f8
801D4C50	jal    $80025cd4
801D4C54	nop
801D4C58	lui    a0, $801e
801D4C5C	addiu  a0, a0, $3f2c
801D4C60	jal    $80025c94
801D4C64	nop
801D4C68	lui    a0, $801f
801D4C6C	addiu  a0, a0, $8f44 (=-$70bc)
801D4C70	jal    $80025bd0
801D4C74	nop
801D4C78	lui    a0, $801e
801D4C7C	addiu  a0, a0, $4538
801D4C80	jal    $80025c54
801D4C84	nop
801D4C88	jal    func1d1ba4 [$801d1ba4]
801D4C8C	nop
801D4C90	lui    a0, $801e
801D4C94	addiu  a0, a0, $3eec
801D4C98	jal    $800444ac
801D4C9C	nop
801D4CA0	lui    a0, $801e
801D4CA4	addiu  a0, a0, $3e34
801D4CA8	jal    $800443b0
801D4CAC	nop
801D4CB0	lw     ra, $0010(sp)
801D4CB4	addiu  sp, sp, $0018
801D4CB8	jr     ra 
801D4CBC	nop

801D4CC0	addiu  sp, sp, $ffe0 (=-$20)
801D4CC4	lui    a0, $801e
801D4CC8	addiu  a0, a0, $3e34
801D4CCC	lui    a1, $801e
801D4CD0	addiu  a1, a1, $3eec
801D4CD4	sw     ra, $001c(sp)
801D4CD8	sw     s2, $0018(sp)
801D4CDC	sw     s1, $0014(sp)
801D4CE0	jal    $80021044
801D4CE4	sw     s0, $0010(sp)
[801e3d54] = w(0);
801D4CF0	jal    func1d39c4 [$801d39c4]
801D4CF4	addu   s0, zero, zero
801D4CF8	lui    at, $801e
801D4CFC	sw     zero, $3d58(at)

while (true)
{
    801D4D00	jal    $8001cb48
    801D4D04	nop
    801D4D08	lui    v0, $801e
    801D4D0C	lw     v0, $3d58(v0)
    801D4D10	nop
    801D4D14	sll    a0, v0, $01
    801D4D18	addu   a0, a0, v0
    801D4D1C	sll    a0, a0, $02
    801D4D20	addu   a0, a0, v0
    801D4D24	sll    a0, a0, $0a
    801D4D28	lui    v0, $8007
    801D4D2C	addiu  v0, v0, $7f64
    801D4D30	jal    $800269c0
    801D4D34	addu   a0, a0, v0
    801D4D38	lui    a0, $801e
    801D4D3C	lw     a0, $3d58(a0)
    801D4D40	lui    v0, $801e
    801D4D44	addiu  v0, v0, $3d60
    801D4D48	sll    a0, a0, $04
    801D4D4C	addu   a0, a0, v0
    801D4D50	lui    at, $801e
    801D4D54	sw     a0, $3d5c(at)
    801D4D58	jal    $8004418c
    801D4D5C	ori    a1, zero, $0001
    801D4D60	lui    a0, $801e
    801D4D64	lw     a0, $3d5c(a0)
    801D4D68	jal    $80026a00
    801D4D6C	nop
    801D4D70	jal    $8001f710
    801D4D74	nop

    A0 = S0;
    func1d3ab0
    S2 = V0;

    if (w[801e3d54] == -1)
    {
        break;
    }

    801D4D98	jal    $80043dd8
    801D4D9C	addu   a0, zero, zero
    801D4DA0	jal    $8003cedc
    801D4DA4	addu   a0, zero, zero
    801D4DA8	lui    v0, $801e
    801D4DAC	lw     v0, $3d58(v0)
    801D4DB0	nop
    801D4DB4	sll    a0, v0, $02
    801D4DB8	addu   a0, a0, v0
    801D4DBC	sll    a0, a0, $02
    801D4DC0	lui    v0, $801e
    801D4DC4	addiu  v0, v0, $3eec
    801D4DC8	jal    $800444ac
    801D4DCC	addu   a0, a0, v0
    801D4DD0	lui    v0, $801e
    801D4DD4	lw     v0, $3d58(v0)
    801D4DD8	nop
    801D4DDC	sll    a0, v0, $01
    801D4DE0	addu   a0, a0, v0
    801D4DE4	sll    a0, a0, $03
    801D4DE8	subu   a0, a0, v0
    801D4DEC	sll    a0, a0, $02
    801D4DF0	lui    v0, $801e
    801D4DF4	addiu  v0, v0, $3e34
    801D4DF8	jal    $800443b0
    801D4DFC	addu   a0, a0, v0
    801D4E00	lui    a0, $801e
    801D4E04	lw     a0, $3d5c(a0)
    801D4E08	jal    $8004433c
    801D4E0C	addiu  s0, s0, $0001
    801D4E10	lui    v0, $801e
    801D4E14	lw     v0, $3d58(v0)
    801D4E18	nop
    801D4E1C	xori   v0, v0, $0001
    801D4E20	lui    at, $801e
    801D4E24	sw     v0, $3d58(at)
}

801D4E30	jal    func1d4c38 [$801d4c38]
801D4E34	addu   s0, zero, zero
801D4E38	jal    $8003cedc
801D4E3C	addu   a0, zero, zero
801D4E40	lui    a0, $801e
801D4E44	addiu  a0, a0, $3f00
801D4E48	jal    $800444ac
801D4E4C	ori    s1, zero, $00ff
801D4E50	lui    a0, $801e
801D4E54	addiu  a0, a0, $3e90
801D4E58	jal    $800443b0
801D4E5C	nop

loop1d4e60:	; 801D4E60
801D4E60	lui    at, $800a
801D4E64	addiu  at, at, $cbdc (=-$3424)
801D4E68	addu   at, at, s0
801D4E6C	lbu    v0, $0000(at)
801D4E70	nop
801D4E74	beq    v0, s1, L1d4e8c [$801d4e8c]
801D4E78	nop
801D4E7C	jal    $80020058
801D4E80	addu   a0, s0, zero
801D4E84	jal    $8001786c
801D4E88	andi   a0, s0, $00ff

L1d4e8c:	; 801D4E8C
801D4E8C	addiu  s0, s0, $0001
801D4E90	slti   v0, s0, $0003
801D4E94	bne    v0, zero, loop1d4e60 [$801d4e60]
801D4E98	nop
801D4E9C	jal    $80017678
801D4EA0	nop
801D4EA4	addu   v0, s2, zero
801D4EA8	lw     ra, $001c(sp)
801D4EAC	lw     s2, $0018(sp)
801D4EB0	lw     s1, $0014(sp)
801D4EB4	lw     s0, $0010(sp)
801D4EB8	addiu  sp, sp, $0020
801D4EBC	jr     ra 
801D4EC0	nop
