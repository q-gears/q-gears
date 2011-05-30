-- created by Tori

entity = {
};

temp0 = 0; // door open
temp1 = 0; // cycle

entity["door"] = {
    on_start = function(self)
--4da:	bgon(0,2,0)
        return 0;
    end;

    script1 = function(self)
--4e0:	bgoff(0,2,0)
        temp0 = 1;
        return 0;
    end;

    script2 = function(self)
--4e9:	bgon(0,2,0)
        temp0 = 0;
        return 0;
    end;
};



entity["wall"] = {
    on_start = function(self)
--4f2:	bgclr(0,8)
        return 0;
    end;

    script1 = function(self)
--4f7:	bgon(0,8,0)
        return 0;
    end;

    script2 = function(self)
--4fc:	bgoff(0,8,0)
        return 0;
    end;
};



entity["box"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--503:	bgon(0,8,1)
        return 0;
    end;

    script2 = function(self)
--508:	bgoff(0,8,1)
        return 0;
    end;
};



entity["box2"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--50f:	bgon(0,8,2)
        return 0;
    end;

    script2 = function(self)
--514:	bgoff(0,8,2)
        return 0;
    end;
};



entity["lg"] = {
    on_start = function(self)
--519:	bgclr(0,1)
        temp0 = 0;
        temp1 = 0;

        while true then
            if temp0 == 1 then
--52b:	bgon(0,1,0)
--52f:	wait(1,0)
--532:	bgoff(0,1,0)
            elseif temp0 == 1 then
--53c:	bgon(0,1,1)
--540:	wait(1,0)
--543:	bgoff(0,1,1)
            elseif temp0 == 1 then
--54d:	bgon(0,1,2)
--551:	wait(1,0)
--554:	bgoff(0,1,2)
            elseif temp0 == 1 then
--55e:	bgon(0,1,3)
--562:	wait(1,0)
--565:	bgoff(0,1,3)
--56f:	bgon(0,1,4)
--573:	wait(1,0)
--576:	bgoff(0,1,4)
            elseif temp0 == 1 then
                if temp1 < 1 then
                    temp1 = temp1 + 1;
                else
--58e:	wait(18,0)
                    temp1 = 0;
                end;
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["produce"] = {
    on_start = function(self)
        mpnam(0)

        local progress = game:variable_get("progress_game");
        if progress >= 48 then
--            music(0)
        else
--            akao(0,0,0,c0,0,0,0,0,0,0,0,0,0)
--            music(1)
        end;

--        idlck(28,0,1)

        return 0;
    end;
};



entity["direct"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            script:request_start_wait("cloud", "script9", 6);
        elseif progress < 48 then
--            uc(1)
--            menu2(1)
--            wait(3c,0)
            script:request_end_wait("avaf", "script3", 6);
--5de:	wait(1e,0)
            script:request_end_wait("aval", "script3", 6);
--5e4:	wait(a,0)
            script:request_end_wait("avaw", "script3", 6);
--5ea:	wait(3c,0)
--5ed:	akao(0,0,0,29,40,a8,0,0,0,0,0,0,0)
            script:request_start_wait("avaw", "script4", 6);
--5fe:	wait(4,0)
            script:request_start_wait("aval", "script4", 6);
--604:	wait(4,0)
            script:request_start_wait("ballet", "script4", 6);
--60a:	wait(6,0)
            script:request_start_wait("avaf", "script4", 6);
--610:	wait(1e,0)
--613:	akao(0,0,0,29,40,0,0,0,0,0,0,0,0)
--621:	wait(3c,0)
--624:	wait(1e,0)
            script:request_end_wait("aval", "script5", 6);
        end;

        return 0;
    end;
};



entity["ad"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["shake"] = {
    on_start = function(self)
--62d:	akao(0,0,0,a2,40,0,0,0,0,0,0,0,0)
--63b:	akao(0,0,0,2a,40,9a,0,0,0,0,0,0,0)
--64a:	scr2d(0,0,0,f8,ff)

        while true then
        script:request_end_wait("random", "script1", 6);
--653:	shake(0,0,2,0,0,5,2)
--65b:	wait(a,0)
--65e:	shake(0,0,0,0,1,0,1)
--666:	wait(f,0)
        end;

        return 0;
    end;
};



entity["random"] = {
    on_start = function(self)
--66d:	random(5,c)
--670:	jmpb(66d)
        return 0;
    end;

    script1 = function(self)
--673:	random(5,c)
        if tempc > 64 then
            temp13 = 10;
        elseif tempc > 128 then
            temp13 = 15;
        elseif tempc > 192 then
            temp13 = 20;
        end;

        return 0;
    end;
};



entity["border1"] = {
    on_start = function(self)
--699:	line(f1,ff,98,ff,0,0,35,0,98,ff,0,0)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--6a9:	uc(1)
--6ab:	menu2(1)
        script:request_end_wait("cloud", "script8", 6);
--6b0:	mapjump(8b,0,fe,ff,60,2,1d,0,fc)

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--6bf:	linon(1)

        return 0;
    end;

    script8 = function(self)
--6c2:	linon(0)

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
--6c5:	char(0)
--6c7:	pc(0)
        local progress = game:variable_get("progress_game");
        if progress == 48 then
--6d1:	tlkon(0)
--6d3:	solid(0)
--6d5:	visi(1)
        else
--6d9:	tlkon(1)
--6db:	solid(1)
--6dd:	visi(0)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--6e2:	akao(0,0,0,29,0,ac,0,0,0,0,0,0,0)
        script:request_start_wait("ballet", "script7", 6);
--6f3:	wait(4,0)
        script:request_start_wait("avaf", "script4", 6);
--6f9:	wait(6,0)
        script:request_start_wait("avaw", "script5", 6);
--6ff:	wait(4,0)
        script:request_start_wait("aval", "script4", 6);
--705:	wait(4,0)
--708:	wait(1e,0)
--70b:	wait(1e,0)
--70e:	akao(0,0,0,29,0,ac,0,0,0,0,0,0,0)
--71c:	wait(8,0)
--71f:	akao(0,0,0,29,0,ac,0,0,0,0,0,0,0)
--72d:	wait(8,0)
--730:	akao(0,0,0,29,0,ac,0,0,0,0,0,0,0)
        script:request_start_wait("ballet", "script7", 6);
--741:	wait(4,0)
        script:request_start_wait("avaf", "script4", 6);
--747:	wait(6,0)
        script:request_start_wait("avaw", "script5", 6);
--74d:	wait(4,0)
        script:request_start_wait("aval", "script4", 6);
--753:	wait(4,0)
--756:	wait(1e,0)
--759:	akao(0,0,0,29,0,a7,0,0,0,0,0,0,0)
        script:request_end_wait("wall", "script1", 4);
--76a:	akao(0,0,0,a2,7f,0,0,0,0,0,0,0,0)
        script:request_end_wait("door", "script1", 4);
--77b:	wait(1e,0)
--77e:	xyzi(0,0,e8,ff,10,0,0,0,14,0)
--789:	dir(0,40)
--78c:	anim!1(3,1)
--78f:	akao(0,0,0,a1,7f,0,0,0,0,0,0,0,0)
--79d:	akao(0,0,0,29,40,e9,0,0,0,0,0,0,0)
--7ab:	tlkon(0)
--7ad:	solid(0)
--7af:	visi(1)
--7b1:	wait(19,0)
        script:request_start_wait("ballet", "script8", 6);
        script:request_end_wait("wall", "script2", 4);
--7ba:	akao(0,0,0,29,40,ea,0,0,0,0,0,0,0)
--7c8:	animw
--7c9:	anime1(4,1)
        script:request_start_wait("avaf", "script6", 6);
        script:request_start_wait("aval", "script7", 6);
        script:request_end_wait("avaw", "script7", 6);
--7d5:	anime1(5,1)
--7d8:	canm!2(6,0,9,1)
--7dd:	window(0,8,0,8,0,89,0,39,0)
--7e7:	message(0,d)
--7ea:	canm!2(6,9,e,1)
        script:request_end_wait("ballet", "script9", 6);
--7f2:	canm!2(6,f,1d,1)
--7f7:	canm!2(7,0,1d,1)
--7fc:	asped(0,10,0)
--800:	window(0,8,0,8,0,ab,0,39,0)
--80a:	message(0,f)
        script:request_end_wait("ballet", "script10", 6);
--810:	canm!2(7,1e,2c,1)
--815:	anime1(8,1)
--818:	canm!1(9,0,e,1)
--81d:	window(0,8,0,8,0,cf,0,39,0)
--827:	message(0,11)
        script:request_start_wait("ballet", "script11", 6);

        return 0;
    end;

    script4 = function(self)
--82e:	tura(c,a,2)

        return 0;
    end;

    script5 = function(self)
--833:	anime2(a,1)
--836:	tura(f,a,2)
--83a:	canm!2(b,0,e,1)

        return 0;
    end;

    -- not used in real game
    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--88e:	anime2(a,1)
--891:	turngen(0,0,0,a,2)
--897:	uc(0)
--899:	menu2(0)

        return 0;
    end;

    script8 = function(self)
        script:request_end_wait("box2", "script1", 4);
--89f:	dfanm(d,1)
--8a2:	dir(0,0)
--8a5:	wait(f,0)
--8a8:	akao(0,0,0,29,40,e9,0,0,0,0,0,0,0)
--8b6:	jump(0,0,9,0,9,ff,0,0,c,0)
--8c1:	tlkon(1)
--8c3:	solid(1)
--8c5:	visi(0)

        return 0;
    end;

    -- not used in real game
    script9 = function(self)
        return 0;
    end;
};



entity["ballet"] = {
    on_start = function(self)
--92a:	char(1)
--92c:	pc(1)
        local progress = game:variable_get("progress_game");
        if progress == 48 then
--936:	tlkon(1)
--938:	solid(1)
--93a:	visi(0)
        else
--93e:	xyzi(0,0,60,0,16,0,0,0,12,0)
--949:	dir(0,c0)
--94c:	tlkon(0)
--94e:	solid(0)
--950:	visi(1)

--953:	anim!2(3,1)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--958:	asped(0,20,0)
--95c:	canm!2(4,0,e,1)
--961:	window(2,8,0,8,0,e1,0,39,0)
--96b:	message(2,3)
--96e:	canm!2(4,f,1d,1)

        return 0;
    end;

    script4 = function(self)
--974:	canm!2(5,0,e,1)
--979:	wait(1e,0)
--97c:	wait(a,0)
--97f:	canm!2(5,f,1d,1)

        return 0;
    end;

    script5 = function(self)
--985:	canm!2(6,0,e,1)
--98a:	window(2,8,0,8,0,ea,0,39,0)
--994:	message(2,6)
--997:	canm!2(6,f,1d,1)
--99c:	asped(0,20,0)
--9a0:	anim!1(7,1)
--9a3:	wait(8,0)
--9a6:	akao(0,0,0,29,7f,ac,0,0,0,0,0,0,0)
--9b4:	wait(a,0)
--9b7:	message(2,7)
        script:request_start_wait("avaf", "script5", 6);

        return 0;
    end;

    script6 = function(self)
--9be:	anim!1(7,1)
--9c1:	wait(8,0)
--9c4:	akao(0,0,0,29,7f,ac,0,0,0,0,0,0,0)
--9d2:	wait(a,0)
--9d5:	animw
--9d6:	asped(0,10,0)

        return 0;
    end;

    script7 = function(self)
--9db:	canm!2(6,0,e,1)
--9e0:	wait(1e,0)
--9e3:	canm!2(6,f,1d,1)

        return 0;
    end;

    script8 = function(self)
--9e9:	anime2(8,1)
--9ec:	jump(0,0,60,0,16,0,12,0,a,0)
--9f7:	animw
--9f8:	dfanm(9,1)

        return 0;
    end;

    script9 = function(self)
--9fc:	canm!1(a,0,e,1)
--a01:	tura(b,a,2)
--a05:	window(1,64,0,8,0,d5,0,39,0)
--a0f:	message(1,e)

        return 0;
    end;

    script10 = function(self)
--a13:	canm!2(a,e,12,1)
--a18:	window(1,64,0,8,0,dd,0,39,0)
--a22:	message(1,10)

        return 0;
    end;

    script11 = function(self)
--a26:	anime1(b,1)
--a29:	window(1,64,0,8,0,b6,0,39,0)
--a33:	message(1,12)
--a36:	solid(1)
--a38:	slidr(0,0)
        script:request_end_wait("box", "script1", 4);
--a3e:	move(0,ff,ff,ca,ff)
        script:request_start_wait("avaf", "script7", 6);
--a47:	tura(b,a,2)
--a4b:	window(1,8,0,8,0,8a,0,39,0)
--a55:	message(1,13)
--a58:	anime2(c,1)
--a5b:	turngen(0,0,1,a,2)
--a61:	move(0,f7,ff,b6,ff)
--a67:	dfanm(d,1)
--a6a:	dir(0,0)
--a6d:	wait(14,0)
        script:request_end_wait("box", "script2", 4);
--a73:	akao(0,0,0,29,40,e9,0,0,0,0,0,0,0)
--a81:	jump(0,0,9,0,49,ff,0,0,c,0)
--a8c:	akao(0,0,0,29,40,a7,0,0,0,0,0,0,0)
--a9a:	tlkon(1)
--a9c:	solid(1)
--a9e:	visi(0)
        script:request_start_wait("avaf", "script8", 6);
--aa3:	wait(a,0)

        return 0;
    end;
};



entity["aval"] = {
    on_start = function(self)
--aa7:	char(2)
        local progress = game:variable_get("progress_game");
        if progress == 48 then
--ab1:	tlkon(1)
--ab3:	solid(1)
--ab5:	visi(0)
        else
--ab9:	xyzi(0,0,a3,ff,c0,0,0,0,18,0)
--ac4:	solid(1)
--ac6:	slidr(0,0)

--aca:	canm!2(3,0,0,1)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--ad1:	canm!1(3,0,e,1)
--ad6:	turngen(0,8,0,a,2)
--adc:	window(1,27,0,8,0,b3,0,39,0)
--ae6:	message(1,2)
        script:request_end_wait("ballet", "script3", 6);
--aec:	canm!2(3,e,1d,1)

        return 0;
    end;

    script4 = function(self)
--af2:	canm!1(3,0,e,1)
--af7:	wait(1e,0)
--afa:	canm!2(3,e,1d,1)

        return 0;
    end;

    script5 = function(self)
--b00:	canm!1(3,0,e,1)
--b05:	turngen(0,10,0,a,2)
--b0b:	window(1,27,0,8,0,1e,1,39,0)
--b15:	message(1,5)
        script:request_start_wait("ballet", "script5", 6);

        return 0;
    end;

    script6 = function(self)
--b1c:	anim!2(3,1)
--b1f:	window(1,50,0,8,0,50,0,19,0)
--b29:	message(1,b)

        return 0;
    end;

    script7 = function(self)
--b2d:	canm!2(3,0,e,1)
--b32:	window(0,1c,0,8,0,a3,0,29,0)
--b3c:	message(0,c)

        return 0;
    end;

    script8 = function(self)
--b40:	msped(0,0,8)
--b44:	move(0,d2,ff,db,ff)
--b4a:	tura(b,a,2)
--b4e:	anime1(4,1)
--b51:	window(0,27,0,8,0,e1,0,39,0)
--b5b:	message(0,15)
--b5e:	move(0,ff,ff,ca,ff)
--b64:	move(0,f7,ff,b6,ff)
--b6a:	dfanm(5,1)
--b6d:	dir(0,0)
--b70:	wait(f,0)
--b73:	akao(0,0,0,29,40,e9,0,0,0,0,0,0,0)
--b81:	jump(0,0,9,0,9,ff,0,0,c,0)
--b8c:	tlkon(1)
--b8e:	solid(1)
--b90:	visi(0)
        script:request_start_wait("avaw", "script8", 6);

        return 0;
    end;
};



-- jessie
entity["avaf"] = {
    on_start = function(self)
--b96:	char(3)
        local progress = game:variable_get("progress_game");
        if progress == 48 then
--ba0:	tlkon(1)
--ba2:	solid(1)
--ba4:	visi(0)
        else
--ba8:	xyzi(0,0,bf,ff,ce,ff,0,0,10,0)
--bb3:	dir(0,80)
--bb6:	solid(1)
--bb8:	slidr(0,0)

--bbc:	canm!2(3,0,0,1)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--bc3:	canm!2(3,0,e,1)
--bc8:	window(0,8,0,8,0,e2,0,39,0)
--bd2:	message(0,1)
--bd5:	canm!2(3,f,1d,1)

        return 0;
    end;

    script4 = function(self)
--bdb:	canm!2(3,0,e,1)
--be0:	wait(1e,0)
--be3:	wait(a,0)
--be6:	canm!2(3,f,1d,1)

        return 0;
    end;

    script5 = function(self)
--bec:	canm!2(3,0,e,1)
--bf1:	window(0,8,0,8,0,bc,0,39,0)
--bfb:	message(0,8)
        script:request_end_wait("ballet", "script6", 6);
--c01:	canm!2(3,f,1d,1)
--c06:	window(0,8,0,8,0,95,0,39,0)
--c10:	message(0,9)
        script:request_start_wait("avaw", "script6", 6);
        script:request_end_wait("aval", "script6", 6);
--c19:	wait(3c,0)
        script:request_start_wait("cloud", "script3", 6);

        return 0;
    end;

    script6 = function(self)
--c20:	asped(0,20,0)
--c24:	anim!1(4,1)
--c27:	asped(0,10,0)
--c2b:	turngen(0,60,1,a,2)
--c31:	window(1,64,0,a0,0,a3,0,29,0)
--c3b:	message(1,a)

        return 0;
    end;

    script7 = function(self)
--c3f:	tura(c,a,2)

        return 0;
    end;

    script8 = function(self)
--c44:	move(0,eb,ff,cd,ff)
--c4a:	tura(b,a,2)
--c4e:	anim!1(5,1)
        script:request_start_wait("cloud", "script4", 6);
--c54:	window(1,8,0,8,0,c8,0,39,0)
--c5e:	message(1,14)
--c61:	msped(0,0,8)
        script:request_start_wait("aval", "script8", 6);
--c68:	move(0,ff,ff,ca,ff)
--c6e:	move(0,f7,ff,b6,ff)
--c74:	dfanm(6,1)
--c77:	dir(0,0)
--c7a:	wait(f,0)
--c7d:	akao(0,0,0,29,40,e9,0,0,0,0,0,0,0)
--c8b:	jump(0,0,9,0,9,ff,0,0,c,0)
--c96:	tlkon(1)
--c98:	solid(1)
--c9a:	visi(0)

        return 0;
    end;
};



-- wedge
entity["avaw"] = {
    on_start = function(self)
--c9d:	char(4)
        local progress = game:variable_get("progress_game");
        if progress == 48 then
--ca7:	tlkon(1)
--ca9:	solid(1)
--cab:	visi(0)
        else
--caf:	xyzi(0,0,3f,0,b,1,0,0,1b,0)
--cba:	dir(0,20)
--cbd:	solid(1)
--cbf:	slidr(0,0)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--cc5:	canm!2(3,0,e,1)
--cca:	window(0,be,0,8,0,a7,0,39,0)
--cd4:	message(0,4)

        return 0;
    end;

    script4 = function(self)
--cd8:	canm!2(3,f,1d,1)
--cdd:	canm!2(4,0,e,1)
--ce2:	wait(1e,0)
--ce5:	canm!2(4,f,1d,1)

        return 0;
    end;

    script5 = function(self)
--ceb:	canm!2(5,0,e,1)
--cf0:	wait(1e,0)
--cf3:	canm!2(5,f,1d,1)

        return 0;
    end;

    script6 = function(self)
--cf9:	anim!2(4,1)

        return 0;
    end;

    script7 = function(self)
--cfd:	canm!2(5,0,e,1)
--d02:	window(2,be,0,31,0,a7,0,29,0)
--d0c:	message(2,4)

        return 0;
    end;

    script8 = function(self)
--d10:	msped(0,0,6)
--d14:	move(0,7,0,1e,1)
--d1a:	move(0,2,0,bc,0)
--d20:	move(0,b9,ff,40,0)
--d26:	dir(0,c0)
        script:request_start_wait("cloud", "script5", 6);
--d2c:	window(2,8,0,8,0,73,0,39,0)
--d36:	message(2,16)
--d39:	akao(0,0,0,29,0,a7,0,0,0,0,0,0,0)
        script:request_end_wait("door", "script2", 4);
--d4a:	akao(0,0,0,a2,40,0,0,0,0,0,0,0,0)
--d58:	anime1(6,1)
--d5b:	turngen(0,20,0,4,2)
--d61:	wait(4,0)
--d64:	wait(a,0)
--d67:	canm!2(3,0,e,1)
--d6c:	wait(a,0)
--d6f:	canm!2(3,f,1d,1)
--d74:	anime2(7,1)
--d77:	tura(b,a,2)
--d7b:	window(2,8,0,8,0,bf,0,39,0)
--d85:	message(2,17)
--d88:	canm!2(8,0,19,1)
--d8d:	canm!2(8,13,19,1)
--d92:	canm!2(8,13,19,1)
--d97:	canm!2(8,13,19,1)
--d9c:	canm!1(8,13,1d,1)
--da1:	window(2,8,0,8,0,bf,0,39,0)
--dab:	message(2,18)
--dae:	animw
--daf:	canm!2(8,1d,2c,1)
--db4:	wait(1e,0)
--db7:	msped(0,0,4)
--dbb:	move(0,cf,ff,de,ff)
--dc1:	tura(b,a,2)
        script:request_start_wait("cloud", "script5", 6);
--dc8:	window(2,64,0,8,0,c1,0,39,0)
--dd2:	message(2,19)
--dd5:	anime2(9,1)
--dd8:	turngen(0,0,1,1e,2)
--dde:	move(0,e9,ff,bd,ff)
--de4:	move(0,f7,ff,b6,ff)
--dea:	dfanm(a,1)
--ded:	dir(0,0)
--df0:	wait(f,0)
--df3:	akao(0,0,0,29,40,e9,0,0,0,0,0,0,0)
--e01:	jump(0,0,9,0,9,ff,0,0,c,0)
--e0c:	tlkon(1)
--e0e:	solid(1)
--e10:	visi(0)
--e12:	akao(0,0,0,29,40,a7,0,0,0,0,0,0,0)
--e20:	wait(8,0)
        game:variable_set("progress_game", 48);

        script:request_start_wait("cloud", "script7", 6);

        return 0;
    end;
};
