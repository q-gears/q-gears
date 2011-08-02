////////////////////////////////
// func1e040
8001E048	addu   s5, a0, zero
8001E064	lh     v0, $0004(s5)
8001E068	nop
8001E06C	slti   v0, v0, $0009
8001E070	bne    v0, zero, L1e2a4 [$8001e2a4]
8001E074	ori    s2, zero, $0004
8001E078	lui    v0, $8006
8001E07C	lw     v0, $2f24(v0)
8001E080	nop
8001E084	sb     s2, $0003(v0)
8001E088	lui    v0, $8006
8001E08C	lw     v0, $2f24(v0)
8001E090	ori    s1, zero, $0064
8001E094	sb     s1, $0007(v0)
8001E098	lui    a0, $8006
8001E09C	lw     a0, $2f24(a0)
8001E0A0	jal    func46870 [$80046870]
8001E0A4	ori    a1, zero, $0001
8001E0A8	lhu    v0, $0000(s5)
8001E0AC	lui    v1, $8006
8001E0B0	lw     v1, $2f24(v1)
8001E0B4	addiu  v0, v0, $0004
8001E0B8	sh     v0, $0008(v1)
8001E0BC	lui    v1, $8006
8001E0C0	lw     v1, $2f24(v1)
8001E0C4	lhu    v0, $0002(s5)
8001E0C8	nop
8001E0CC	sh     v0, $000a(v1)
8001E0D0	lhu    v0, $0004(s5)
8001E0D4	lui    v1, $8006
8001E0D8	lw     v1, $2f24(v1)
8001E0DC	addiu  v0, v0, $fff8 (=-$8)
8001E0E0	sh     v0, $0010(v1)
8001E0E4	lui    v0, $8006
8001E0E8	lw     v0, $2f24(v0)
8001E0EC	ori    s3, zero, $0004
8001E0F0	sh     s3, $0012(v0)
8001E0F4	lui    v0, $8006
8001E0F8	lw     v0, $2f24(v0)
8001E0FC	ori    a0, zero, $0100
8001E100	sb     zero, $000c(v0)
8001E104	lui    v0, $8006
8001E108	lw     v0, $2f24(v0)
8001E10C	ori    a1, zero, $01e0
8001E110	jal    func46634 [$80046634]
8001E114	sb     zero, $000d(v0)
8001E118	lui    v1, $8006
8001E11C	lw     v1, $2f24(v1)
8001E120	nop
8001E124	sh     v0, $000e(v1)
8001E128	lui    a1, $8006
8001E12C	lw     a1, $2f24(a1)
8001E130	lui    a0, $8006
8001E134	lw     a0, $2fc4(a0)
8001E138	addiu  v0, a1, $0014
8001E13C	lui    at, $8006
8001E140	sw     v0, $2f24(at)
8001E144	jal    system_add_render_packet_to_queue [$80046794]
8001E148	ori    s0, zero, $0010
8001E14C	addu   a0, zero, zero
8001E150	ori    a1, zero, $0001
8001E154	ori    a2, zero, $03c0
8001E158	ori    a3, zero, $0100
8001E15C	ori    v0, zero, $00e0
8001E160	sh     zero, $0010(sp)
8001E164	sh     v0, $0012(sp)
8001E168	sh     s0, $0014(sp)
8001E16C	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001E170	sh     s0, $0016(sp)
8001E174	addu   a0, zero, zero
8001E178	ori    a1, zero, $0001
8001E17C	andi   a2, v0, $ffff
8001E180	jal    func26a34 [$80026a34]
8001E184	addiu  a3, sp, $0010
8001E188	lui    v0, $8006
8001E18C	lw     v0, $2f24(v0)
8001E190	nop
8001E194	sb     s2, $0003(v0)
8001E198	lui    v0, $8006
8001E19C	lw     v0, $2f24(v0)
8001E1A0	nop
8001E1A4	sb     s1, $0007(v0)
8001E1A8	lui    a0, $8006
8001E1AC	lw     a0, $2f24(a0)
8001E1B0	jal    func46870 [$80046870]
8001E1B4	ori    a1, zero, $0001
8001E1B8	lhu    v0, $0000(s5)
8001E1BC	lui    v1, $8006
8001E1C0	lw     v1, $2f24(v1)
8001E1C4	addiu  v0, v0, $0004
8001E1C8	sh     v0, $0008(v1)
8001E1CC	lhu    v0, $0002(s5)
8001E1D0	lhu    v1, $0006(s5)
8001E1D4	nop
8001E1D8	addu   v0, v0, v1
8001E1DC	lui    v1, $8006
8001E1E0	lw     v1, $2f24(v1)
8001E1E4	addiu  v0, v0, $fffc (=-$4)
8001E1E8	sh     v0, $000a(v1)
8001E1EC	lhu    v0, $0004(s5)
8001E1F0	lui    v1, $8006
8001E1F4	lw     v1, $2f24(v1)
8001E1F8	addiu  v0, v0, $fff8 (=-$8)
8001E1FC	sh     v0, $0010(v1)
8001E200	lui    v0, $8006
8001E204	lw     v0, $2f24(v0)
8001E208	ori    a0, zero, $0100
8001E20C	sh     s3, $0012(v0)
8001E210	lui    v0, $8006
8001E214	lw     v0, $2f24(v0)
8001E218	ori    a1, zero, $01e0
8001E21C	sb     zero, $000c(v0)
8001E220	lui    v1, $8006
8001E224	lw     v1, $2f24(v1)
8001E228	ori    v0, zero, $000c
8001E22C	jal    func46634 [$80046634]
8001E230	sb     v0, $000d(v1)
8001E234	lui    v1, $8006
8001E238	lw     v1, $2f24(v1)
8001E23C	nop
8001E240	sh     v0, $000e(v1)
8001E244	lui    a1, $8006
8001E248	lw     a1, $2f24(a1)
8001E24C	lui    a0, $8006
8001E250	lw     a0, $2fc4(a0)
8001E254	addiu  v0, a1, $0014
8001E258	lui    at, $8006
8001E25C	sw     v0, $2f24(at)
8001E260	jal    system_add_render_packet_to_queue [$80046794]
8001E264	nop
8001E268	addu   a0, zero, zero
8001E26C	ori    a1, zero, $0001
8001E270	ori    a2, zero, $03c0
8001E274	ori    a3, zero, $0100
8001E278	ori    v0, zero, $00e8
8001E27C	sh     s0, $0010(sp)
8001E280	sh     v0, $0012(sp)
8001E284	sh     s0, $0014(sp)
8001E288	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001E28C	sh     s0, $0016(sp)
8001E290	addu   a0, zero, zero
8001E294	ori    a1, zero, $0001
8001E298	andi   a2, v0, $ffff
8001E29C	jal    func26a34 [$80026a34]
8001E2A0	addiu  a3, sp, $0010

L1e2a4:	; 8001E2A4
8001E2A4	lh     v0, $0006(s5)
8001E2A8	nop
8001E2AC	slti   v0, v0, $0009
8001E2B0	bne    v0, zero, L1e4e0 [$8001e4e0]
8001E2B4	ori    s4, zero, $0004
8001E2B8	lui    v0, $8006
8001E2BC	lw     v0, $2f24(v0)
8001E2C0	nop
8001E2C4	sb     s4, $0003(v0)
8001E2C8	lui    v0, $8006
8001E2CC	lw     v0, $2f24(v0)
8001E2D0	ori    s3, zero, $0064
8001E2D4	sb     s3, $0007(v0)
8001E2D8	lui    a0, $8006
8001E2DC	lw     a0, $2f24(a0)
8001E2E0	jal    func46870 [$80046870]
8001E2E4	ori    a1, zero, $0001
8001E2E8	lhu    v0, $0000(s5)
8001E2EC	lhu    v1, $0004(s5)
8001E2F0	ori    a0, zero, $0100
8001E2F4	addu   v0, v0, v1
8001E2F8	lui    v1, $8006
8001E2FC	lw     v1, $2f24(v1)
8001E300	addiu  v0, v0, $fffc (=-$4)
8001E304	sh     v0, $0008(v1)
8001E308	lhu    v0, $0002(s5)
8001E30C	lui    v1, $8006
8001E310	lw     v1, $2f24(v1)
8001E314	addiu  v0, v0, $0004
8001E318	sh     v0, $000a(v1)
8001E31C	lui    v0, $8006
8001E320	lw     v0, $2f24(v0)
8001E324	ori    s2, zero, $0004
8001E328	sh     s2, $0010(v0)
8001E32C	lhu    v0, $0006(s5)
8001E330	lui    v1, $8006
8001E334	lw     v1, $2f24(v1)
8001E338	addiu  v0, v0, $fff8 (=-$8)
8001E33C	sh     v0, $0012(v1)
8001E340	lui    v1, $8006
8001E344	lw     v1, $2f24(v1)
8001E348	ori    v0, zero, $000c
8001E34C	sb     v0, $000c(v1)
8001E350	lui    v0, $8006
8001E354	lw     v0, $2f24(v0)
8001E358	ori    a1, zero, $01e0
8001E35C	jal    func46634 [$80046634]
8001E360	sb     zero, $000d(v0)
8001E364	lui    v1, $8006
8001E368	lw     v1, $2f24(v1)
8001E36C	nop
8001E370	sh     v0, $000e(v1)
8001E374	lui    a1, $8006
8001E378	lw     a1, $2f24(a1)
8001E37C	lui    a0, $8006
8001E380	lw     a0, $2fc4(a0)
8001E384	addiu  v0, a1, $0014
8001E388	lui    at, $8006
8001E38C	sw     v0, $2f24(at)
8001E390	jal    system_add_render_packet_to_queue [$80046794]
8001E394	ori    s0, zero, $0010
8001E398	addu   a0, zero, zero
8001E39C	ori    a1, zero, $0001
8001E3A0	ori    a2, zero, $03c0
8001E3A4	ori    a3, zero, $0100
8001E3A8	ori    s1, zero, $00f0
8001E3AC	sh     s0, $0010(sp)
8001E3B0	sh     s1, $0012(sp)
8001E3B4	sh     s0, $0014(sp)
8001E3B8	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001E3BC	sh     s0, $0016(sp)
8001E3C0	addu   a0, zero, zero
8001E3C4	ori    a1, zero, $0001
8001E3C8	andi   a2, v0, $ffff
8001E3CC	jal    func26a34 [$80026a34]
8001E3D0	addiu  a3, sp, $0010
8001E3D4	lui    v0, $8006
8001E3D8	lw     v0, $2f24(v0)
8001E3DC	nop
8001E3E0	sb     s4, $0003(v0)
8001E3E4	lui    v0, $8006
8001E3E8	lw     v0, $2f24(v0)
8001E3EC	nop
8001E3F0	sb     s3, $0007(v0)
8001E3F4	lui    a0, $8006
8001E3F8	lw     a0, $2f24(a0)
8001E3FC	jal    func46870 [$80046870]
8001E400	ori    a1, zero, $0001
8001E404	lui    v1, $8006
8001E408	lw     v1, $2f24(v1)
8001E40C	lhu    v0, $0000(s5)
8001E410	nop
8001E414	sh     v0, $0008(v1)
8001E418	lhu    v0, $0002(s5)
8001E41C	lui    v1, $8006
8001E420	lw     v1, $2f24(v1)
8001E424	addiu  v0, v0, $0004
8001E428	sh     v0, $000a(v1)
8001E42C	lui    v0, $8006
8001E430	lw     v0, $2f24(v0)
8001E434	nop
8001E438	sh     s2, $0010(v0)
8001E43C	lhu    v0, $0006(s5)
8001E440	lui    v1, $8006
8001E444	lw     v1, $2f24(v1)
8001E448	addiu  v0, v0, $fff8 (=-$8)
8001E44C	sh     v0, $0012(v1)
8001E450	lui    v0, $8006
8001E454	lw     v0, $2f24(v0)
8001E458	ori    a0, zero, $0100
8001E45C	sb     zero, $000c(v0)
8001E460	lui    v0, $8006
8001E464	lw     v0, $2f24(v0)
8001E468	ori    a1, zero, $01e0
8001E46C	jal    func46634 [$80046634]
8001E470	sb     zero, $000d(v0)
8001E474	lui    v1, $8006
8001E478	lw     v1, $2f24(v1)
8001E47C	nop
8001E480	sh     v0, $000e(v1)
8001E484	lui    a1, $8006
8001E488	lw     a1, $2f24(a1)
8001E48C	lui    a0, $8006
8001E490	lw     a0, $2fc4(a0)
8001E494	addiu  v0, a1, $0014
8001E498	lui    at, $8006
8001E49C	sw     v0, $2f24(at)
8001E4A0	jal    system_add_render_packet_to_queue [$80046794]
8001E4A4	nop
8001E4A8	addu   a0, zero, zero
8001E4AC	ori    a1, zero, $0001
8001E4B0	ori    a2, zero, $03c0
8001E4B4	ori    a3, zero, $0100
8001E4B8	sh     zero, $0010(sp)
8001E4BC	sh     s1, $0012(sp)
8001E4C0	sh     s0, $0014(sp)
8001E4C4	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001E4C8	sh     s0, $0016(sp)
8001E4CC	addu   a0, zero, zero
8001E4D0	ori    a1, zero, $0001
8001E4D4	andi   a2, v0, $ffff
8001E4D8	jal    func26a34 [$80026a34]
8001E4DC	addiu  a3, sp, $0010

L1e4e0:	; 8001E4E0
8001E4E0	lui    v0, $8006
8001E4E4	lw     v0, $2f24(v0)
8001E4E8	ori    s2, zero, $0004
8001E4EC	sb     s2, $0003(v0)
8001E4F0	lui    v0, $8006
8001E4F4	lw     v0, $2f24(v0)
8001E4F8	ori    s1, zero, $0064
8001E4FC	sb     s1, $0007(v0)
8001E500	lui    a0, $8006
8001E504	lw     a0, $2f24(a0)
8001E508	jal    func46870 [$80046870]
8001E50C	ori    a1, zero, $0001
8001E510	lui    v1, $8006
8001E514	lw     v1, $2f24(v1)
8001E518	lhu    v0, $0000(s5)
8001E51C	nop
8001E520	sh     v0, $0008(v1)
8001E524	lui    v1, $8006
8001E528	lw     v1, $2f24(v1)
8001E52C	lhu    v0, $0002(s5)
8001E530	nop
8001E534	sh     v0, $000a(v1)
8001E538	lui    v0, $8006
8001E53C	lw     v0, $2f24(v0)
8001E540	ori    a0, zero, $0100
8001E544	sb     zero, $000c(v0)
8001E548	lui    v0, $8006
8001E54C	lw     v0, $2f24(v0)
8001E550	ori    s3, zero, $00e8
8001E554	sb     s3, $000d(v0)
8001E558	lui    v0, $8006
8001E55C	lw     v0, $2f24(v0)
8001E560	ori    s0, zero, $0004
8001E564	sh     s0, $0010(v0)
8001E568	lui    v0, $8006
8001E56C	lw     v0, $2f24(v0)
8001E570	ori    a1, zero, $01e0
8001E574	jal    func46634 [$80046634]
8001E578	sh     s0, $0012(v0)
8001E57C	lui    v1, $8006
8001E580	lw     v1, $2f24(v1)
8001E584	lui    a0, $8006
8001E588	lw     a0, $2fc4(a0)
8001E58C	sh     v0, $000e(v1)
8001E590	lui    a1, $8006
8001E594	lw     a1, $2f24(a1)
8001E598	jal    system_add_render_packet_to_queue [$80046794]
8001E59C	nop
8001E5A0	lui    v1, $8006
8001E5A4	lw     v1, $2f24(v1)
8001E5A8	nop
8001E5AC	addiu  v0, v1, $0014
8001E5B0	lui    at, $8006
8001E5B4	sw     v0, $2f24(at)
8001E5B8	sb     s2, $0017(v1)
8001E5BC	lui    v0, $8006
8001E5C0	lw     v0, $2f24(v0)
8001E5C4	nop
8001E5C8	sb     s1, $0007(v0)
8001E5CC	lui    a0, $8006
8001E5D0	lw     a0, $2f24(a0)
8001E5D4	jal    func46870 [$80046870]
8001E5D8	ori    a1, zero, $0001
8001E5DC	lhu    v0, $0000(s5)
8001E5E0	lhu    v1, $0004(s5)
8001E5E4	nop
8001E5E8	addu   v0, v0, v1
8001E5EC	lui    v1, $8006
8001E5F0	lw     v1, $2f24(v1)
8001E5F4	addiu  v0, v0, $fffc (=-$4)
8001E5F8	sh     v0, $0008(v1)
8001E5FC	lui    v1, $8006
8001E600	lw     v1, $2f24(v1)
8001E604	lhu    v0, $0002(s5)
8001E608	nop
8001E60C	sh     v0, $000a(v1)
8001E610	lui    v1, $8006
8001E614	lw     v1, $2f24(v1)
8001E618	ori    v0, zero, $000c
8001E61C	sb     v0, $000c(v1)
8001E620	lui    v0, $8006
8001E624	lw     v0, $2f24(v0)
8001E628	nop
8001E62C	sb     s3, $000d(v0)
8001E630	lui    v0, $8006
8001E634	lw     v0, $2f24(v0)
8001E638	ori    a0, zero, $0100
8001E63C	sh     s0, $0010(v0)
8001E640	lui    v0, $8006
8001E644	lw     v0, $2f24(v0)
8001E648	ori    a1, zero, $01e0
8001E64C	jal    func46634 [$80046634]
8001E650	sh     s0, $0012(v0)
8001E654	lui    v1, $8006
8001E658	lw     v1, $2f24(v1)
8001E65C	lui    a0, $8006
8001E660	lw     a0, $2fc4(a0)
8001E664	sh     v0, $000e(v1)
8001E668	lui    a1, $8006
8001E66C	lw     a1, $2f24(a1)
8001E670	jal    system_add_render_packet_to_queue [$80046794]
8001E674	ori    s3, zero, $00e4
8001E678	lui    v1, $8006
8001E67C	lw     v1, $2f24(v1)
8001E680	nop
8001E684	addiu  v0, v1, $0014
8001E688	lui    at, $8006
8001E68C	sw     v0, $2f24(at)
8001E690	sb     s2, $0017(v1)
8001E694	lui    v0, $8006
8001E698	lw     v0, $2f24(v0)
8001E69C	nop
8001E6A0	sb     s1, $0007(v0)
8001E6A4	lui    a0, $8006
8001E6A8	lw     a0, $2f24(a0)
8001E6AC	jal    func46870 [$80046870]
8001E6B0	ori    a1, zero, $0001
8001E6B4	lui    v1, $8006
8001E6B8	lw     v1, $2f24(v1)
8001E6BC	lhu    v0, $0000(s5)
8001E6C0	nop
8001E6C4	sh     v0, $0008(v1)
8001E6C8	lhu    v0, $0002(s5)
8001E6CC	lhu    v1, $0006(s5)
8001E6D0	nop
8001E6D4	addu   v0, v0, v1
8001E6D8	lui    v1, $8006
8001E6DC	lw     v1, $2f24(v1)
8001E6E0	addiu  v0, v0, $fffc (=-$4)
8001E6E4	sh     v0, $000a(v1)
8001E6E8	lui    v1, $8006
8001E6EC	lw     v1, $2f24(v1)
8001E6F0	ori    v0, zero, $0010
8001E6F4	sb     v0, $000c(v1)
8001E6F8	lui    v0, $8006
8001E6FC	lw     v0, $2f24(v0)
8001E700	nop
8001E704	sb     s3, $000d(v0)
8001E708	lui    v0, $8006
8001E70C	lw     v0, $2f24(v0)
8001E710	ori    a0, zero, $0100
8001E714	sh     s0, $0010(v0)
8001E718	lui    v0, $8006
8001E71C	lw     v0, $2f24(v0)
8001E720	ori    a1, zero, $01e0
8001E724	jal    func46634 [$80046634]
8001E728	sh     s0, $0012(v0)
8001E72C	lui    v1, $8006
8001E730	lw     v1, $2f24(v1)
8001E734	lui    a0, $8006
8001E738	lw     a0, $2fc4(a0)
8001E73C	sh     v0, $000e(v1)
8001E740	lui    a1, $8006
8001E744	lw     a1, $2f24(a1)
8001E748	jal    system_add_render_packet_to_queue [$80046794]
8001E74C	nop
8001E750	lui    v1, $8006
8001E754	lw     v1, $2f24(v1)
8001E758	nop
8001E75C	addiu  v0, v1, $0014
8001E760	lui    at, $8006
8001E764	sw     v0, $2f24(at)
8001E768	sb     s2, $0017(v1)
8001E76C	lui    v0, $8006
8001E770	lw     v0, $2f24(v0)
8001E774	nop
8001E778	sb     s1, $0007(v0)
8001E77C	lui    a0, $8006
8001E780	lw     a0, $2f24(a0)
8001E784	jal    func46870 [$80046870]
8001E788	ori    a1, zero, $0001
8001E78C	lhu    v0, $0000(s5)
8001E790	lhu    v1, $0004(s5)
8001E794	nop
8001E798	addu   v0, v0, v1
8001E79C	lui    v1, $8006
8001E7A0	lw     v1, $2f24(v1)
8001E7A4	addiu  v0, v0, $fffc (=-$4)
8001E7A8	sh     v0, $0008(v1)
8001E7AC	lhu    v0, $0002(s5)
8001E7B0	lhu    v1, $0006(s5)
8001E7B4	nop
8001E7B8	addu   v0, v0, v1
8001E7BC	lui    v1, $8006
8001E7C0	lw     v1, $2f24(v1)
8001E7C4	addiu  v0, v0, $fffc (=-$4)
8001E7C8	sh     v0, $000a(v1)
8001E7CC	lui    v1, $8006
8001E7D0	lw     v1, $2f24(v1)
8001E7D4	ori    v0, zero, $001c
8001E7D8	sb     v0, $000c(v1)
8001E7DC	lui    v0, $8006
8001E7E0	lw     v0, $2f24(v0)
8001E7E4	nop
8001E7E8	sb     s3, $000d(v0)
8001E7EC	lui    v0, $8006
8001E7F0	lw     v0, $2f24(v0)
8001E7F4	ori    a0, zero, $0100
8001E7F8	sh     s0, $0010(v0)
8001E7FC	lui    v0, $8006
8001E800	lw     v0, $2f24(v0)
8001E804	ori    a1, zero, $01e0
8001E808	jal    func46634 [$80046634]
8001E80C	sh     s0, $0012(v0)
8001E810	lui    v1, $8006
8001E814	lw     v1, $2f24(v1)
8001E818	lui    a0, $8006
8001E81C	lw     a0, $2fc4(a0)
8001E820	sh     v0, $000e(v1)
8001E824	lui    a1, $8006
8001E828	lw     a1, $2f24(a1)
8001E82C	jal    system_add_render_packet_to_queue [$80046794]
8001E830	nop
8001E834	addu   a0, zero, zero
8001E838	ori    a1, zero, $0001
8001E83C	ori    a2, zero, $03c0
8001E840	lui    v0, $8006
8001E844	lw     v0, $2f24(v0)
8001E848	ori    v1, zero, $0100
8001E84C	sh     zero, $0010(sp)
8001E850	sh     zero, $0012(sp)
8001E854	sh     v1, $0014(sp)
8001E858	sh     v1, $0016(sp)
8001E85C	addiu  v0, v0, $0014
8001E860	lui    at, $8006
8001E864	sw     v0, $2f24(at)
8001E868	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001E86C	ori    a3, zero, $0100
8001E870	addu   a0, zero, zero
8001E874	ori    a1, zero, $0001
8001E878	andi   a2, v0, $ffff
8001E87C	jal    func26a34 [$80026a34]
8001E880	addiu  a3, sp, $0010
8001E884	lh     a3, $0004(s5)
8001E888	nop
8001E88C	slti   v0, a3, $0007
8001E890	bne    v0, zero, L1eb04 [$8001eb04]
8001E894	nop
8001E898	lh     a2, $0006(s5)
8001E89C	nop
8001E8A0	slti   v0, a2, $0007
8001E8A4	bne    v0, zero, L1eb04 [$8001eb04]
8001E8A8	ori    v0, zero, $0008
8001E8AC	addiu  s2, a3, $fffa (=-$6)
8001E8B0	lh     a0, $0000(s5)
8001E8B4	lh     a1, $0002(s5)
8001E8B8	lui    v1, $8006
8001E8BC	lw     v1, $2f24(v1)
8001E8C0	addiu  s3, a2, $fffa (=-$6)
8001E8C4	sb     v0, $0003(v1)
8001E8C8	ori    v0, zero, $0038
8001E8CC	lui    v1, $8006
8001E8D0	lw     v1, $2f24(v1)
8001E8D4	addiu  s0, a0, $0003
8001E8D8	sb     v0, $0007(v1)
8001E8DC	lw     v0, $0084(gp)
8001E8E0	nop
8001E8E4	beq    v0, zero, L1e8fc [$8001e8fc]
8001E8E8	addiu  s1, a1, $0003
8001E8EC	lui    a0, $8006
8001E8F0	lw     a0, $2f24(a0)
8001E8F4	jal    system_change_semi_transparency_in_packet [$80046848]
8001E8F8	ori    a1, zero, $0001

L1e8fc:	; 8001E8FC
8001E8FC	lui    v0, $8006
8001E900	lw     v0, $2f24(v0)
8001E904	nop
8001E908	sh     s0, $0008(v0)
8001E90C	lui    v0, $8006
8001E910	lw     v0, $2f24(v0)
8001E914	nop
8001E918	sh     s1, $000a(v0)
8001E91C	lui    v0, $8006
8001E920	lw     v0, $2f24(v0)
8001E924	addu   a0, s0, s2
8001E928	sh     a0, $0010(v0)
8001E92C	lui    v0, $8006
8001E930	lw     v0, $2f24(v0)
8001E934	nop
8001E938	sh     s1, $0012(v0)
8001E93C	lui    v0, $8006
8001E940	lw     v0, $2f24(v0)
8001E944	nop
8001E948	sh     s0, $0018(v0)
8001E94C	lui    v0, $8006
8001E950	lw     v0, $2f24(v0)
8001E954	addu   v1, s1, s3
8001E958	sh     v1, $001a(v0)
8001E95C	lui    v0, $8006
8001E960	lw     v0, $2f24(v0)
8001E964	nop
8001E968	sh     a0, $0020(v0)
8001E96C	lui    v0, $8006
8001E970	lw     v0, $2f24(v0)
8001E974	nop
8001E978	sh     v1, $0022(v0)
8001E97C	lui    v1, $8006
8001E980	lw     v1, $2f24(v1)
8001E984	lui    v0, $8005
8001E988	lbu    v0, $9208(v0)
8001E98C	nop
8001E990	sb     v0, $0004(v1)
8001E994	lui    v1, $8006
8001E998	lw     v1, $2f24(v1)
8001E99C	lui    v0, $8005
8001E9A0	lbu    v0, $9209(v0)
8001E9A4	nop
8001E9A8	sb     v0, $0005(v1)
8001E9AC	lui    v1, $8006
8001E9B0	lw     v1, $2f24(v1)
8001E9B4	lui    v0, $8005
8001E9B8	lbu    v0, $920a(v0)
8001E9BC	nop
8001E9C0	sb     v0, $0006(v1)
8001E9C4	lui    v1, $8006
8001E9C8	lw     v1, $2f24(v1)
8001E9CC	lui    v0, $8005
8001E9D0	lbu    v0, $920b(v0)
8001E9D4	nop
8001E9D8	sb     v0, $000c(v1)
8001E9DC	lui    v1, $8006
8001E9E0	lw     v1, $2f24(v1)
8001E9E4	lui    v0, $8005
8001E9E8	lbu    v0, $920c(v0)
8001E9EC	nop
8001E9F0	sb     v0, $000d(v1)
8001E9F4	lui    v1, $8006
8001E9F8	lw     v1, $2f24(v1)
8001E9FC	lui    v0, $8005
8001EA00	lbu    v0, $920d(v0)
8001EA04	nop
8001EA08	sb     v0, $000e(v1)
8001EA0C	lui    v1, $8006
8001EA10	lw     v1, $2f24(v1)
8001EA14	lui    v0, $8005
8001EA18	lbu    v0, $920e(v0)
8001EA1C	nop
8001EA20	sb     v0, $0014(v1)
8001EA24	lui    v1, $8006
8001EA28	lw     v1, $2f24(v1)
8001EA2C	lui    v0, $8005
8001EA30	lbu    v0, $920f(v0)
8001EA34	nop
8001EA38	sb     v0, $0015(v1)
8001EA3C	lui    v1, $8006
8001EA40	lw     v1, $2f24(v1)
8001EA44	lui    v0, $8005
8001EA48	lbu    v0, $9210(v0)
8001EA4C	nop
8001EA50	sb     v0, $0016(v1)
8001EA54	lui    v1, $8006
8001EA58	lw     v1, $2f24(v1)
8001EA5C	lui    v0, $8005
8001EA60	lbu    v0, $9211(v0)
8001EA64	nop
8001EA68	sb     v0, $001c(v1)
8001EA6C	lui    v1, $8006
8001EA70	lw     v1, $2f24(v1)
8001EA74	lui    v0, $8005
8001EA78	lbu    v0, $9212(v0)
8001EA7C	nop
8001EA80	sb     v0, $001d(v1)
8001EA84	lui    v1, $8006
8001EA88	lw     v1, $2f24(v1)
8001EA8C	lui    v0, $8005
8001EA90	lbu    v0, $9213(v0)
8001EA94	nop
8001EA98	sb     v0, $001e(v1)
8001EA9C	lui    a1, $8006
8001EAA0	lw     a1, $2f24(a1)
8001EAA4	lui    a0, $8006
8001EAA8	lw     a0, $2fc4(a0)
8001EAAC	addiu  v0, a1, $0024
8001EAB0	lui    at, $8006
8001EAB4	sw     v0, $2f24(at)
8001EAB8	jal    system_add_render_packet_to_queue [$80046794]
8001EABC	nop
8001EAC0	addu   a0, zero, zero
8001EAC4	addu   a1, zero, zero
8001EAC8	ori    a2, zero, $03c0
8001EACC	ori    a3, zero, $0100
8001EAD0	ori    v0, zero, $0060
8001EAD4	sh     v0, $0010(sp)
8001EAD8	ori    v0, zero, $00e0
8001EADC	sh     v0, $0012(sp)
8001EAE0	ori    v0, zero, $0020
8001EAE4	sh     v0, $0014(sp)
8001EAE8	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001EAEC	sh     v0, $0016(sp)
8001EAF0	addu   a0, zero, zero
8001EAF4	ori    a1, zero, $0001
8001EAF8	andi   a2, v0, $ffff
8001EAFC	jal    func26a34 [$80026a34]
8001EB00	addiu  a3, sp, $0010

L1eb04:	; 8001EB04
////////////////////////////////
