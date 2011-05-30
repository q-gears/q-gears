////////////////////////////////
// funcbded4
A2 = 00ffffff;

switch( A1 )
{
    case 46: // 7CE10B80
    {
        return (w[A0 + 68] >> 1) & f;
    }

    default:
    {
        return A2;
    }

08DF0B80 23
1CDF0B80 24
28DF0B80 25
3CDF0B80 26
48DF0B80 27
D0E10B80 28
5CDF0B80 29
D8DF0B80 2a
E4DF0B80 2b
F0DF0B80 2c
FCDF0B80 2d
08E00B80 2e
14E00B80 2f
30 28E00B8034E00B8040E00B804CE00B8058E00B806CE00B80D0E10B80D0E10B80D0E10B8080E00B808CE00B80D0E10B80D0E10B80D0E10B80D0E10B80D0E10B80
98E00B80 40
ACE00B80 41
B8E00B80 42
F4E00B80 43
28E10B80 44
68E10B80 45
D0E10B80 47
90E10B80 48
9CE10B80 49
A8E10B80 4a
B4E10B80 4b
C0E10B80 4c
CCE10B80 4d

800BDF08	lw     v0, $0024(a0)
800BDF0C	nop
800BDF10	lhu    a2, $0000(v0)
800BDF14	jr     ra 
800BDF18	addu   v0, a2, zero

800BDF1C	lhu    a2, $0028(a0)
800BDF20	jr     ra 
800BDF24	addu   v0, a2, zero

800BDF28	lw     v0, $0024(a0)
800BDF2C	nop
800BDF30	lh     a2, $0002(v0)
800BDF34	jr     ra 
800BDF38	addu   v0, a2, zero

800BDF3C	lh     a2, $002a(a0)
800BDF40	jr     ra 
800BDF44	addu   v0, a2, zero

800BDF48	lw     v0, $0024(a0)
800BDF4C	nop
800BDF50	lh     a2, $0004(v0)
800BDF54	jr     ra 
800BDF58	addu   v0, a2, zero

800BDF5C	lw     a1, $0068(a0)
800BDF60	nop
800BDF64	andi   v0, a1, $0001
800BDF68	beq    v0, zero, Lbdf9c [$800bdf9c]
800BDF6C	lui    a0, $8006
800BDF70	srl    v1, a1, $01
800BDF74	andi   v1, v1, $000f
800BDF78	sll    v0, v1, $03
800BDF7C	lw     a0, $794c(a0)
800BDF80	addu   v0, v0, v1
800BDF84	lw     v1, $001c(a0)
800BDF88	sll    v0, v0, $04
800BDF8C	addu   v0, v0, v1
800BDF90	lbu    a2, $0047(v0)
800BDF94	jr     ra 
800BDF98	addu   v0, a2, zero


Lbdf9c:	; 800BDF9C
800BDF9C	lui    v1, $8006
800BDFA0	srl    v0, a1, $01
800BDFA4	andi   v0, v0, $000f
800BDFA8	lw     a0, $794c(v1)
800BDFAC	sll    v1, v0, $01
800BDFB0	lw     a0, $001c(a0)
800BDFB4	addu   v1, v1, v0
800BDFB8	lw     v0, $08e4(a0)
800BDFBC	sll    v1, v1, $03
800BDFC0	addu   v0, v0, v1
800BDFC4	lw     v0, $0488(v0)
800BDFC8	nop
800BDFCC	lbu    a2, $0003(v0)
800BDFD0	jr     ra 
800BDFD4	addu   v0, a2, zero

800BDFD8	lbu    a2, $0037(a0)
800BDFDC	jr     ra 
800BDFE0	addu   v0, a2, zero

800BDFE4	lw     v0, $0034(a0)
800BDFE8	j      Lbe01c [$800be01c]
800BDFEC	lui    v1, $00ff
800BDFF0	lbu    a2, $003b(a0)
800BDFF4	jr     ra 
800BDFF8	addu   v0, a2, zero

800BDFFC	lw     v0, $0038(a0)
800BE000	j      Lbe01c [$800be01c]
800BE004	lui    v1, $00ff
800BE008	lbu    a2, $003f(a0)
800BE00C	jr     ra 
800BE010	addu   v0, a2, zero

800BE014	lui    v1, $00ff
800BE018	lw     v0, $003c(a0)

Lbe01c:	; 800BE01C
800BE01C	ori    v1, v1, $ffff
800BE020	j      Lbe1d0 [$800be1d0]
800BE024	and    a2, v0, v1
800BE028	lbu    a2, $0070(a0)
800BE02C	jr     ra 
800BE030	addu   v0, a2, zero

800BE034	lbu    a2, $0071(a0)
800BE038	jr     ra 
800BE03C	addu   v0, a2, zero

800BE040	lbu    a2, $0072(a0)
800BE044	jr     ra 
800BE048	addu   v0, a2, zero

800BE04C	lbu    a2, $0073(a0)
800BE050	jr     ra 
800BE054	addu   v0, a2, zero

800BE058	lw     v0, $0068(a0)
800BE05C	nop
800BE060	srl    a2, v0, $1c
800BE064	j      Lbe1d0 [$800be1d0]
800BE068	andi   a2, a2, $0001
800BE06C	lw     v0, $0068(a0)
800BE070	nop
800BE074	srl    a2, v0, $16
800BE078	j      Lbe1d0 [$800be1d0]
800BE07C	andi   a2, a2, $0001
800BE080	lh     a2, $0084(a0)
800BE084	jr     ra 
800BE088	addu   v0, a2, zero

800BE08C	lhu    a2, $00ac(a0)
800BE090	jr     ra 
800BE094	addu   v0, a2, zero

800BE098	lw     v0, $0068(a0)
800BE09C	nop
800BE0A0	srl    a2, v0, $08
800BE0A4	j      Lbe1d0 [$800be1d0]
800BE0A8	andi   a2, a2, $0003
800BE0AC	lbu    a2, $0068(a0)
800BE0B0	j      Lbe1d0 [$800be1d0]
800BE0B4	srl    a2, a2, $05
800BE0B8	lw     v1, $0068(a0)
800BE0BC	lui    a0, $8006
800BE0C0	lw     a0, $794c(a0)
800BE0C4	srl    v1, v1, $01
800BE0C8	andi   v1, v1, $000f
800BE0CC	sll    v0, v1, $03
800BE0D0	addu   v0, v0, v1
800BE0D4	lw     v1, $001c(a0)
800BE0D8	sll    v0, v0, $04
800BE0DC	addu   v0, v0, v1
800BE0E0	lw     v0, $0070(v0)
800BE0E4	nop
800BE0E8	srl    a2, v0, $04
800BE0EC	j      Lbe1d0 [$800be1d0]
800BE0F0	andi   a2, a2, $001f
800BE0F4	lw     v1, $0068(a0)
800BE0F8	lui    a0, $8006
800BE0FC	lw     a0, $794c(a0)
800BE100	srl    v1, v1, $01
800BE104	andi   v1, v1, $000f
800BE108	sll    v0, v1, $03
800BE10C	addu   v0, v0, v1
800BE110	lw     v1, $001c(a0)
800BE114	sll    v0, v0, $04
800BE118	addu   v0, v0, v1
800BE11C	lbu    a2, $0046(v0)
800BE120	jr     ra 
800BE124	addu   v0, a2, zero

800BE128	lui    v1, $8006
800BE12C	lw     v0, $0068(a0)
800BE130	lw     a0, $794c(v1)
800BE134	srl    v0, v0, $01
800BE138	andi   v0, v0, $000f
800BE13C	sll    v1, v0, $01
800BE140	lw     a0, $001c(a0)
800BE144	addu   v1, v1, v0
800BE148	lw     v0, $08e4(a0)
800BE14C	sll    v1, v1, $03
800BE150	addu   v0, v0, v1
800BE154	lw     v0, $0488(v0)
800BE158	nop
800BE15C	lbu    a2, $0002(v0)
800BE160	jr     ra 
800BE164	addu   v0, a2, zero

800BE168	lw     v0, $0068(a0)
800BE16C	nop
800BE170	srl    a2, v0, $12
800BE174	j      Lbe1d0 [$800be1d0]
800BE178	andi   a2, a2, $0001

800BE190	lbu    a2, $0031(a0)
800BE194	jr     ra 
800BE198	addu   v0, a2, zero

800BE19C	lbu    a2, $0032(a0)
800BE1A0	jr     ra 
800BE1A4	addu   v0, a2, zero

800BE1A8	lbu    a2, $006c(a0)
800BE1AC	jr     ra 
800BE1B0	addu   v0, a2, zero

800BE1B4	lbu    a2, $006d(a0)
800BE1B8	jr     ra 
800BE1BC	addu   v0, a2, zero

800BE1C0	lbu    a2, $006e(a0)
800BE1C4	jr     ra 
800BE1C8	addu   v0, a2, zero

800BE1CC	lbu    a2, $006f(a0)

Lbe1d0:	; 800BE1D0
return A2;
////////////////////////////////



////////////////////////////////
// battle_get_units_data_pointer_by_mask
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V1 = w[V0 + 6f8];

if (V1 != 0)
{
    loopbed3c:	; 800BED3C
        if (hu[V1 + b0] == A0)
        {
            return V1;
        }

        V1 = w[V1 + 0];
    800BED54	bne    v1, zero, loopbed3c [$800bed3c]
}

return 0;
////////////////////////////////



////////////////////////////////
// battle_get_units_mask
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V1 = w[V0 + 6f8];

A1 = 0;
if (V1 != 0)
{
    loopbec9c:	; 800BEC9C
        if (A0 == 0)
        {
            if ((w[V1 + 68] & 1) != 0)
            {
                A1 = A1 | hu[V1 + b0];
            }
        }
        else if (A0 == 1)
        {
            if ((w[V1 + 68] & 1) == 0)
            {
                A1 = A1 | hu[V1 + b0];
            }
        }
        else if (A0 == 2)
        {
            A1 = A1 | hu[V1 + b0];
        }

        V1 = w[V1 + 0];
    800BED00	bne    v1, zero, loopbec9c [$800bec9c]

}

return A1 & ffff;
////////////////////////////////
