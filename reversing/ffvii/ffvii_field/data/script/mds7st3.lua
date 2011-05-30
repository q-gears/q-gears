-- created by Tori

entity = {
};



tempf  = 0; -- set when barret tell everyone gather

temp11 = 0; -- trainman talk progress
temp12 = 0; -- talk to pair once



entity["door"] = {
    on_start = function(self)
--6ca:	bgclr(0,1)

        return 0;
    end;

    script1 = function(self)
--6cf:	bgon(0,1,0)
--6d3:	wait(3,0)
--6d6:	bgoff(0,1,0)
--6da:	bgon(0,1,1)
--6de:	wait(3,0)
--6e1:	bgoff(0,1,1)
--6e5:	bgon(0,1,2)
--6e9:	wait(3,0)
--6ec:	bgoff(0,1,2)
--6f0:	bgon(0,1,3)

        return 0;
    end;

    script2 = function(self)
--6f5:	bgoff(0,1,3)
--6f9:	bgon(0,1,2)
--6fd:	wait(3,0)
--700:	bgoff(0,1,2)
--704:	bgon(0,1,1)
--708:	wait(3,0)
--70b:	bgoff(0,1,1)
--70f:	bgon(0,1,0)
--713:	wait(3,0)
--716:	bgoff(0,1,0)

        return 0;
    end;
};



entity["produce"] = {
    on_start = function(self)
        --MPNAM(0)

        local progress = game:variable_get("progress_game");
        if progress == 251 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --FADE(0,0,0,0,0,1,4,0)
            script:request_start_wait("BGanim", "script1", 2);
            --MUSIC(0)

            local flags = game:variable_get("bank3[217]")
            if bit.band(flags, hex.to_dec('0x08')) then
                script:request_start_wait("ad", "script1", 2);
                script:request_start_wait("stagedr", "script2", 6);
            else
                --SOUND(0,B8,0,40)
                script:request_start_wait("stagedr", "script1", 2);
            end;
        elseif progress >= 212 then
            script:request_start_wait("guard", "script10", 6);
            script:request_start_wait("man1", "script7", 6);
            script:request_start_wait("woman1", "script7", 6);
        elseif progress == 108 then
            --BGON(0,1,3)
            script:request_start_wait("stagedr", "script5", 6);

            local flags = game:variable_get("bank3[216]")
            if bit.band(flags, hex.to_dec('0x08')) == 0 then
                --Wait(1)
                script:request_start_wait("border3", "script7", 6);
            end;
        elseif progress >= 63 then
            --IDLCK(40,0,1)
            script:request_start_wait("stagedr", "script4", 2);
        else
            --CharMovable(Off)
            --MenuAccess(Off)
            --SOUND(0,90,1,40)
            script:request_start_wait("stagedr", "script3", 2);
            Wait(1)
            script:request_start_wait("border2", "script7", 6);
            script:request_start_wait("border4", "script7", 6);
        end;

        return 0;
    end;
};



entity["direct"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 251 then
            local flags = game:variable_get("bank3[217]")
            if bit.band(flags, hex.to_dec('0x08')) then
                return 0;
            elseif bit.band(flags, hex.to_dec('0x04')) then
                --ChangeField(93,0,0,0,0,0,0,0,0) -- mds7st32
            elseif bit.band(flags, hex.to_dec('0x02')) then
                return 0;
            else
                --Wait(3C)
                --PMJMP(93,0)
                script:request_start_wait("emother", "script3", 2);
            end;
        end;

        return 0;
    end;
};



entity["ad"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--812:	pmjmp(93,0)
--815:	wmode(1,1,0)
--819:	window(1,8,0,64,0,32,1,19,0)
--823:	message(1,14)
--826:	message(1,15)
--829:	wait(a,0)
        local flags = game:variable_get("bank3[217]")
        game:variable_set("bank3[217]", bit.bor(flags, hex.to_dec('0x04')));
--830:	fade(0,0,ff,ff,ff,8,6,0)
--839:	fadew
--83a:	mapjump(93,0,0,0,0,0,0,0,0) -- MDS7ST32

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["stagedr"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        script:request_start_wait("avaw", "script3", 6);
        script:request_start_wait("aval", "script3", 6);
        script:request_start_wait("guard", "script5", 6);
        script:request_start_wait("obasan1", "script3", 6);
        script:request_start_wait("woman1", "script3", 6);
        script:request_start_wait("cloud", "script6", 6);

        return 0;
    end;

    script2 = function(self)
        script:request_start_wait("guard", "script6", 6);
        script:request_start_wait("emother", "script4", 6);

        return 0;
    end;

    script3 = function(self)
        script:request_start_wait("guard", "script3", 1);

        return 0;
    end;

    script4 = function(self)
        script:request_start_wait("guard", "script6", 6);
        script:request_start_wait("man1", "script5", 6);
        script:request_start_wait("woman1", "script5", 6);

        return 0;
    end;

    script5 = function(self)
        script:request_start_wait("guard", "script7", 6);
        script:request_start_wait("man1", "script5", 6);
        script:request_start_wait("woman1", "script5", 6);

        local flags = game:variable_get("bank3[216]")
        if bit.band(flags, hex.to_dec('0x08')) == 0 then
            script:request_start_wait("avaw", "script8", 6);
            script:request_start_wait("aval", "script10", 6);
            script:request_end_wait("avaf", "script6", 6);
        end;

        return 0;
    end;
};



entity["timekp"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;
};



entity["BGanim"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--8a3:	fade(0,0,ff,ff,ff,2,5,ff)
--8ac:	fadew
--8ad:	fade(0,0,14,14,28,4,6,0)
--8b6:	fadew

        return 0;
    end;
};



entity["border1"] = {
    on_start = function(self)
--8b8:	line(9c,f4,17,d,65,0,e3,f4,3d,d,65,0)
--8c6:	linon(1)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--8ca:	uc(1)
--8cc:	menu2(1)
--8ce:	pmjmp(8b,0)
        script:request_start_wait("cloud", "script6", 6);
        script:request_end_wait("guard", "script8", 1);

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
};



entity["border2"] = {
    on_start = function(self)
--8dc:	line(a,f7,3f,b,0,0,81,f5,4c,a,0,0)
--8ea:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--8ee:	linon(0)
--8f0:	idlck(5,0,0)
--8f4:	uc(1)
--8f6:	menu2(1)
        script:request_end_wait("cloud", "script5", 6);
        script:request_start_wait("ballet", "script5", 6);
        script:request_start_wait("border4", "script8", 6);

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
--906:	linon(1)

        return 0;
    end;
};



entity["border3"] = {
    on_start = function(self)
--909:	line(64,f5,6c,a,0,0,7a,f5,47,7,0,0)
--917:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--91b:	linon(0)
        local flags = game:variable_get("bank3[216]");
        game:variable_set("bank3[216]", bit.bor(flags, hex.to_dec('0x08')));

        script:request_end_wait("avaw", "script13", 5);

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
--929:	linon(1)

        return 0;
    end;
};


entity["border4"] = {
    on_start = function(self)
--92c:	line(18,f7,bd,d,65,0,f6,f6,16,c,65,0)
--93a:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--93e:	uc(1)
--940:	menu2(1)
        script:request_start_wait("ballet", "script4", 6);
        script:request_end_wait("cloud", "script4", 6);
--948:	uc(0)
--94a:	menu2(0)

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
--951:	linon(1)

        return 0;
    end;

    script8 = function(self)
--954:	linon(0)

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
--957:	char(0)
--959:	pc(0)
--95b:	slidr(0,22)

        local progress = game:variable_get("progress_game");
        if progress < 63 then
--969:	tlkon(1)
--96b:	solid(1)
--96d:	visi(0)
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
--971:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--97c:	tlkon(0)
--97e:	solid(0)
--980:	visi(1)
--982:	msped(0,0,8)
--986:	move(0,e9,f4,dd,c)
--98c:	dfanm(3,1)
--98f:	wait(f,0)
--992:	jump(0,0,21,f5,1e,c,34,0,11,0)
--99d:	dir(0,10)
--9a0:	wait(14,0)
--9a3:	dfanm(0,1)
--9a6:	move(0,4e,f5,c9,b)
        script:request_start_wait("guard", "script4", 1);
        game:variable_set("progress_game", 63);
--9b4:	idlck(40,0,1)
--9b8:	uc(0)
--9ba:	menu2(0)

        return 0;
    end;

    script4 = function(self)
--9bd:	msped(0,0,8)
--9c1:	dfanm(2,1)
--9c4:	fmove(0,6c,f6,11,c)
--9ca:	dir(0,10)
--9cd:	dfanm(4,1)
--9d0:	anime1(5,1)

        return 0;
    end;

    script5 = function(self)
--9d4:	move(0,75,f6,9e,a)
--9da:	dfanm(4,1)
--9dd:	dir(0,10)

        return 0;
    end;

    script6 = function(self)
--9e1:	tlkon(1)
--9e3:	solid(1)
--9e5:	visi(0)

        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
        return 0;
    end;
};



entity["ballet"] = {
    on_start = function(self)
--a44:	char(1)
--a46:	pc(1)
--a48:	tlkon(0)
--a4a:	solid(0)
--a4c:	visi(1)
--a4e:	slidr(0,30)
--a51:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--a57:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--a62:	slidr(0,0)
--a65:	solid(1)
--a67:	msped(0,0,8)
--a6b:	move(0,e9,f4,dd,c)
--a71:	dfanm(3,1)
--a74:	wait(f,0)
--a77:	jump(0,0,21,f5,1e,c,34,0,8,0)
--a82:	dfanm(0,1)
--a85:	dir(0,10)
--a88:	dfanm(4,1)
--a8b:	wait(3c,0)
--a8e:	dfanm(2,1)
--a91:	msped(0,0,8)
--a95:	fmove(0,99,f5,3c,b)
        script:request_start_wait("cloud", "script3", 6);
--a9e:	dfanm(3,1)
--aa1:	wait(f,0)
--aa4:	jump(0,0,16,f6,3a,a,10,0,11,0)
--aaf:	wait(14,0)
--ab2:	dir(0,18)
--ab5:	dfanm(5,1)
--ab8:	wait(3c,0)
--abb:	anime1(6,1)
--abe:	window(0,3a,0,46,0,b1,0,39,0)
--ac8:	message(0,1)
        script:request_start_wait("avaf", "script4", 6);
        script:request_start_wait("aval", "script8", 6);
        script:request_start_wait("avaw", "script6", 6);
--ad4:	slidr(0,64)
        tempf = 1;

        return 0;
    end;

    script4 = function(self)
--adc:	anim!2(7,1)
--adf:	window(0,8,0,3b,0,b2,0,39,0)
--ae9:	message(0,5)
--aec:	dfanm(5,1)

        return 0;
    end;

    script5 = function(self)
--af0:	anime1(6,1)
--af3:	anime1(8,1)
--af6:	window(0,8,0,32,0,e,1,39,0)
--b00:	message(0,2)
--b03:	anime1(6,1)
--b06:	window(0,8,0,32,0,c3,0,39,0)
--b10:	message(0,3)
--b13:	wait(a,0)
--b16:	dfanm(2,1)
--b19:	msped(0,0,8)
--b1d:	fmove(0,a4,f4,96,9)
--b23:	anim!2(7,1)
--b26:	window(0,8,0,32,0,ba,0,39,0)
--b30:	message(0,4)
        script:request_start_wait("avaf", "script5", 6);
        script:request_start_wait("aval", "script9", 6);
        script:request_start_wait("avaw", "script7", 6);

        local flags = game:variable_get("bank3[216]")
        game:variable_set("bank3[216]", bit.bor(flags, hex.to_dec('0x01')));

--b40:	uc(0)
--b42:	menu2(0)
--b44:	slidr(0,0)
--b47:	solid(1)
--b49:	dfanm(2,1)
--b4c:	msped(0,0,d)
--b50:	fmove(0,a4,f4,96,9)
--b56:	fmove(0,9,f4,7a,8)
--b5c:	fmove(0,a4,ef,88,6)
--b62:	tlkon(1)
--b64:	solid(1)
--b66:	visi(0)

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
        return 0;
    end;
};



entity["tifa"] = {
    on_start = function(self)
--bbc:	char(2)
--bbe:	pc(2)
--bc0:	slidr(0,1e)
--bc3:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        return 0;
    end;
};



entity["aval"] = {
    on_start = function(self)
--bde:	char(3)
--be0:	slidr(0,22)
--be3:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--be9:	solid(1)
--beb:	xyzi(0,0,cc,f2,84,8,0,0,1c,0)
--bf6:	dfanm(3,1)
--bf9:	dir(0,50)

        return 0;
    end;

    script4 = function(self)
--bfd:	msped(0,0,2)
--c01:	move(0,a4,ef,88,6)

        return 0;
    end;

    script5 = function(self)
--c08:	dfanm(4,1)
--c0b:	anime1(5,1)

        return 0;
    end;

    script6 = function(self)
--c0f:	dfanm(6,1)
--c12:	wait(f,0)
--c15:	jump(0,0,c9,f2,2,9,1b,0,11,0)
--c20:	dfanm(7,1)
--c23:	canm!2(7,0,0,1)
--c28:	turn(0,10,fe,80,1)
--c2e:	dfanm(6,1)
--c31:	jump(0,0,cc,f2,84,8,1c,0,11,0)

        return 0;
    end;

    script7 = function(self)
--c3d:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--c48:	msped(0,0,8)
--c4c:	move(0,e9,f4,dd,c)
--c52:	dfanm(8,1)
--c55:	jump(0,0,21,f5,1e,c,34,0,a,0)
--c60:	dir(0,10)
--c63:	dfanm(9,1)
--c66:	wait(1e,0)
        script:request_start_wait("avaw", "script5", 6);
--c6c:	dfanm(2,1)
--c6f:	msped(0,0,8)
--c73:	fmove(0,49,f7,fc,c)
--c79:	dir(0,50)
--c7c:	dfanm(9,1)
--c7f:	wait(1e,0)
--c82:	dfanm(2,1)
--c85:	msped(0,0,8)
--c89:	fmove(0,7a,f6,a3,b)
--c8f:	dir(0,d0)
--c92:	dfanm(9,1)
--c95:	wait(1e,0)
--c98:	dir(0,30)
--c9b:	dfanm(6,1)
--c9e:	wait(f,0)
--ca1:	jump(0,0,76,f7,85,b,13,0,11,0)
--cac:	wait(14,0)
--caf:	dfanm(9,1)
--cb2:	wait(1e,0)

        return 0;
    end;

    script8 = function(self)
--cb6:	dfanm(2,1)
--cb9:	msped(0,0,8)
--cbd:	fmove(0,eb,f6,49,a)
--cc3:	dir(0,d0)
--cc6:	dfanm(0,1)
--cc9:	slidr(0,64)

        return 0;
    end;

    script9 = function(self)
--ccd:	wait(32,0)
--cd0:	solid(1)
--cd2:	slidr(0,0)
--cd5:	dfanm(2,1)
--cd8:	msped(0,0,c)
--cdc:	fmove(0,f5,f3,39,8)
--ce2:	dir(0,b0)
--ce5:	dfanm(9,1)
--ce8:	wait(1e,0)
--ceb:	msped(0,0,10)
--cef:	move(0,a4,ef,88,6)
--cf5:	tlkon(1)
--cf7:	solid(1)
--cf9:	visi(0)

        return 0;
    end;

    script10 = function(self)
--cfc:	xyzi(0,0,0,f6,df,b,65,0,8,0)
--d07:	dir(0,f0)
--d0a:	dfanm(a,1)
--d0d:	msped(0,0,10)
--d11:	tlkon(0)
--d13:	solid(0)
--d15:	visi(1)
--d17:	solid(1)

        return 0;
    end;

    script11 = function(self)
        return 0;
    end;

    script12 = function(self)
        return 0;
    end;

    script13 = function(self)
        return 0;
    end;

    script14 = function(self)
--d5d:	asped(0,20,0)
--d61:	anime2(d,1)
--d64:	turngen(0,10,2,a,1)
--d6a:	msped(0,0,10)
--d6e:	move(0,10,f5,3b,c)
--d74:	move(0,a4,f4,4f,d)
--d7a:	tlkon(1)
--d7c:	solid(1)
--d7e:	visi(0)

        return 0;
    end;
};



entity["avaf"] = {
    on_start = function(self)
--d81:	char(4)
--d83:	slidr(0,22)
--d86:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--d8c:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--d97:	msped(0,0,8)
--d9b:	move(0,e9,f4,dd,c)
--da1:	dir(0,f0)
--da4:	dfanm(3,1)
--da7:	wait(f,0)
--daa:	jump(0,0,b3,f4,b9,b,3a,0,a,0)
--db5:	wait(14,0)
--db8:	dir(0,d0)
--dbb:	dfanm(4,1)
        script:request_start_wait("aval", "script7", 6);
--dc1:	dfanm(2,1)
--dc4:	msped(0,0,8)
--dc8:	fmove(0,a3,f5,41,b)
--dce:	dfanm(4,1)
--dd1:	wait(1e,0)
--dd4:	dfanm(2,1)
--dd7:	msped(0,0,8)
--ddb:	fmove(0,47,f6,b,a)
--de1:	dir(0,90)
--de4:	dfanm(4,1)
--de7:	wait(1e,0)
--dea:	dfanm(2,1)
--ded:	msped(0,0,8)
--df1:	fmove(0,e6,f3,b3,8)
--df7:	dir(0,d0)
--dfa:	dfanm(4,1)
--dfd:	ret

        return 0;
    end;

    script4 = function(self)
--dfe:	dfanm(2,1)
--e01:	msped(0,0,8)
--e05:	fmove(0,ba,f5,86,9)
--e0b:	dir(0,50)
--e0e:	dfanm(0,1)
--e11:	slidr(0,0)
--e14:	solid(1)

        return 0;
    end;

    script5 = function(self)
--e17:	wait(a,0)
--e1a:	solid(1)
--e1c:	slidr(0,0)
--e1f:	dfanm(2,1)
--e22:	msped(0,0,c)
--e26:	fmove(0,eb,f3,c8,8)
--e2c:	dir(0,d0)
--e2f:	dfanm(4,1)
--e32:	wait(1e,0)
--e35:	dfanm(2,1)
--e38:	slidr(0,46)
--e3b:	solid(0)
--e3d:	msped(0,0,10)
--e41:	fmove(0,1e,f3,7f,7)
--e47:	fmove(0,a4,ef,88,6)
--e4d:	tlkon(1)
--e4f:	solid(1)
--e51:	visi(0)

        return 0;
    end;

    script6 = function(self)
--e54:	xyzi(0,0,59,f5,4c,c,65,0,9,0)
--e5f:	dir(0,10)
--e62:	tlkon(0)
--e64:	solid(0)
--e66:	visi(1)
--e68:	canm!2(5,0,e,1)
--e6d:	solid(1)
--e6f:	msped(0,0,10)

        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
--eb7:	asped(0,20,0)
--ebb:	anime2(8,1)
--ebe:	turngen(0,10,2,a,1)
--ec4:	msped(0,0,10)
--ec8:	move(0,10,f5,3b,c)
--ece:	move(0,a4,f4,4f,d)
--ed4:	tlkon(1)
--ed6:	solid(1)
--ed8:	visi(0)

        return 0;
    end;
};



entity["avaw"] = {
    on_start = function(self)
--edb:	char(5)
--edd:	slidr(0,22)
--ee0:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--ee6:	solid(1)
--ee8:	xyzi(0,0,10,f3,b4,8,0,0,19,0)
--ef3:	dir(0,d0)

        return 0;
    end;

    script4 = function(self)
--ef7:	anime1(3,1)
--efa:	move(0,cc,f2,84,8)
--f00:	dfanm(4,1)
        script:request_start_wait("aval", "script5", 6);
--f06:	anime1(5,1)
--f09:	dfanm(6,1)
--f0c:	dir(0,90)
--f0f:	dfanm(7,1)
        script:request_end_wait("aval", "script6", 6);
--f15:	dfanm(6,1)
--f18:	move(0,f7,f2,7e,8)
        script:request_start_wait("aval", "script4", 5);
--f21:	msped(0,0,2)
--f25:	move(0,a4,ef,88,6)

        return 0;
    end;

    script5 = function(self)
--f2c:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--f37:	msped(0,0,8)
--f3b:	move(0,e9,f4,dd,c)
--f41:	dfanm(8,1)
--f44:	wait(f,0)
--f47:	jump(0,0,21,f5,1e,c,34,0,a,0)
--f52:	wait(a,0)
--f55:	dir(0,10)
--f58:	dfanm(9,1)
--f5b:	wait(1e,0)
--f5e:	dfanm(2,1)
--f61:	msped(0,0,8)
--f65:	fmove(0,e7,f5,66,b)
--f6b:	dfanm(8,1)
--f6e:	wait(f,0)
        script:request_start_wait("ballet", "script3", 6);
--f74:	jump(0,0,62,f6,89,a,10,0,11,0)
--f7f:	wait(14,0)
--f82:	dfanm(9,1)
--f85:	wait(1e,0)
--f88:	dfanm(2,1)
--f8b:	msped(0,0,8)
--f8f:	fmove(0,9a,f7,b5,9)
--f95:	dfanm(9,1)

        return 0;
    end;

    script6 = function(self)
--f99:	dfanm(2,1)
--f9c:	msped(0,0,8)
--fa0:	fmove(0,72,f6,b0,9)
--fa6:	dir(0,90)
--fa9:	dfanm(0,1)

        return 0;
    end;

    script7 = function(self)
--fad:	wait(1e,0)
--fb0:	solid(1)
--fb2:	slidr(0,0)
--fb5:	dfanm(2,1)
--fb8:	msped(0,0,d)
--fbc:	fmove(0,35,f4,31,8)
--fc2:	dir(0,d0)
--fc5:	dfanm(9,1)
--fc8:	wait(14,0)
--fcb:	dfanm(2,1)
--fce:	msped(0,0,10)
--fd2:	fmove(0,1e,f3,7f,7)
--fd8:	fmove(0,a4,ef,88,6)
--fde:	tlkon(1)
--fe0:	solid(1)
--fe2:	visi(0)

        return 0;
    end;

    script8 = function(self)
--fe5:	xyzi(0,0,39,f5,55,b,65,0,9,0)
--ff0:	dir(0,70)
--ff3:	tlkon(0)
--ff5:	solid(0)
--ff7:	visi(1)
--ff9:	dfanm(a,1)
--ffc:	msped(0,0,10)
--1000:	solid(1)

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
        return 0;
    end;

    script12 = function(self)
        return 0;
    end;

    script13 = function(self)
--10c8:	asped(0,20,0)
--10cc:	anime2(d,1)
--10cf:	turngen(0,10,2,a,1)
        script:request_start_wait("avaf", "script10", 5);
        script:request_start_wait("aval", "script14", 5);
--10db:	wait(a,0)
--10de:	msped(0,0,10)
--10e2:	move(0,10,f5,3b,c)
--10e8:	move(0,a4,f4,4f,d)
--10ee:	tlkon(1)
--10f0:	solid(1)
--10f2:	visi(0)

        return 0;
    end;
};



entity["guard"] = {
    on_start = function(self)
--10f5:	char(6)
--10f7:	slidr(0,22)
--10fa:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local progress = game:variable_get("progress_game");
        if progress >= 212 then
            --TURA(B,A,2)
            --CreateWindow(0,8,8,EB,29)
            --Dialog(0,32)
            --TURNGEN(0,B0,2,A,1)
        elseif progress >= 108 then
            --TURA(B,A,2)
            if temp11 == 1 then
                --CreateWindow(0,8,8,CC,39)
                --Dialog(0,31)
            else
                --CreateWindow(0,8,8,105,39)
                --Dialog(0,30)
                temp11 = 1;
            end;
            --TURNGEN(0,50,2,A,1)
        else
            --TURA(B,A,2)
            local flags = game:variable_get("bank3[216]")
            if bit.band(flags, hex.to_dec('0x02')) then
                --CreateWindow(3,8,8,100,19)
                --Dialog(3,2F)
            else
                if temp11 == 2 then
                    --CreateWindow(3,8,A0,116,39)
                    --Dialog(3,2D)
                    --Dialog(3,2E)
                    game:variable_set("bank3[216]", bit.bor(flags, hex.to_dec('0x02')));
                elseif temp11 == 1 then
                    --CreateWindow(3,8,A0,F9,39)
                    --Dialog(3,2C)
                    temp11 = 2;
                else
                    --CreateWindow(3,8,A0,133,39)
                    --Dialog(3,2B)
                    temp11 = 1;
                end;
            end;
            --TURNGEN(0,10,2,A,1)
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--11c9:	xyzi(0,0,16,f2,6b,a,65,0,f,0)
--11d4:	dir(0,50)
--11d7:	anime1(3,1)
--11da:	dfanm(2,1)
--11dd:	msped(0,0,c)
--11e1:	fmove(0,10,f4,aa,b)
--11e7:	dfanm(0,1)
--11ea:	anime1(4,1)
--11ed:	anime1(5,1)
--11f0:	akao(0,0,0,29,40,35,0,0,0,0,0,0,0)
--11fe:	akao(0,0,0,2a,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("door", "script1", 2);
        script:request_end_wait("man1", "script3", 6);
        script:request_start_wait("woman1", "script4", 6);
--1215:	wait(1e,0)
        script:request_start_wait("child", "script3", 6);
--121b:	wait(3c,0)

        return 0;
    end;

    script4 = function(self)
--121f:	move(0,f5,f4,29,c)
--1225:	dir(0,90)
--1228:	anime1(3,1)
--122b:	anime1(5,1)
--122e:	akao(0,0,0,29,40,35,0,0,0,0,0,0,0)
--123c:	wait(a,0)
--123f:	dir(0,50)
--1242:	anime1(5,1)
--1245:	akao(0,0,0,2a,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("door", "script2", 2);
--1256:	move(0,27,f5,58,c)
--125c:	dir(0,10)

        return 0;
    end;

    script5 = function(self)
--1260:	solid(1)
--1262:	xyzi(0,0,25,f4,a5,b,65,0,39,0)
--126d:	dir(0,50)

        return 0;
    end;

    script6 = function(self)
--1271:	xyzi(0,0,27,f5,58,c,65,0,9,0)
--127c:	dir(0,10)

        return 0;
    end;

    script7 = function(self)
--1280:	xyzi(0,0,25,f4,a5,b,65,0,39,0)
--128b:	dir(0,50)

        return 0;
    end;

    script8 = function(self)
--128f:	wait(1e,0)
--1292:	akao(0,0,0,29,40,90,1,0,0,0,0,0,0)
--12a0:	msped(0,0,8)
--12a4:	anime1(3,1)
--12a7:	move(0,f5,f4,29,c)
--12ad:	dir(0,90)
--12b0:	anime1(3,1)
--12b3:	anime1(5,1)
--12b6:	akao(0,0,0,29,40,35,0,0,0,0,0,0,0)
--12c4:	wait(a,0)
--12c7:	dir(0,50)
--12ca:	anime1(5,1)
--12cd:	akao(0,0,0,2a,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("door", "script2", 2);
--12de:	wait(1e,0)
--12e1:	mapjump(8b,0,a3,ff,34,2,1f,0,40) -- tin_1

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
--12f3:	xyzi(0,0,2e,f5,75,c,65,0,9,0)
--12fe:	dir(0,b0)

        return 0;
    end;
};



entity["man1"] = {
    on_start = function(self)
--1304:	char(7)
--1306:	slidr(0,22)
--1309:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            local flags = game:variable_get("bank3[216]")
            if bit.band(flags, hex.to_dec('0x04')) then
                --CreateWindow(1,8,4B,65,29)
                --Dialog(1,29)
                --CreateWindow(2,64,4B,72,29)
                --Dialog(2,2A)
            else
                --CharMovable(Off)
                --MenuAccess(Off)
                --CreateWindow(1,8,4B,63,29)
                --Dialog(1,24)
                --CreateWindow(2,64,4B,50,29)
                --Dialog(2,25)
                --CreateWindow(1,8,4B,ED,29)
                --Dialog(1,26)
                --CreateWindow(2,64,4B,48,29)
                --Dialog(2,27)
                --CreateWindow(1,8,4B,AC,29)
                --Dialog(1,28)
                --CreateWindow(2,64,4B,48,29)
                --Dialog(2,27)
                script:request_start_wait("woman1", "script6", 6);
                --ANIM!2(3,1)
                game:variable_set("bank3[216]", bit.bor(flags, hex.to_dec('0x04')));
                --CharMovable(On)
                --MenuAccess(On)
            end
        elseif progress >= 72 then
            --CreateWindow(1,8,4B,A2,29)
            --Dialog(1,1E)
            --CreateWindow(2,64,4B,7D,29)
            --Dialog(2,1F)
            --CreateWindow(1,8,4B,64,29)
            --Dialog(1,20)
            --CreateWindow(2,64,4B,D0,29)
            --Dialog(2,21)
            --CreateWindow(1,8,4B,4B,29)
            --Dialog(1,22)
            --TURA(B,4,2)
            --CreateWindow(1,8,4B,ED,29)
            --Dialog(1,23)
            --TURNGEN(0,50,2,A,1)
        else
            if temp12 == 1 then
                --CreateWindow(1,8,4B,B6,29)
                --Dialog(1,1A)
                --CreateWindow(2,64,4B,44,29)
                --Dialog(2,19)
                --CreateWindow(2,64,4B,126,29)
                --Dialog(2,1B)
                --CreateWindow(1,8,4B,60,29)
                --Dialog(1,1C)
                --CreateWindow(2,64,4B,40,29)
                --Dialog(2,1D)
                temp12 = 0;
            else
                --CreateWindow(1,8,4B,D4,29)
                --Dialog(1,18)
                --CreateWindow(2,64,4B,44,29)
                --Dialog(2,19)
                temp12 = 1;
            end;
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1471:	solid(1)
--1473:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--147e:	msped(0,0,2)
--1482:	move(0,e9,f4,dd,c)
--1488:	dfanm(4,1)
--148b:	jump(0,0,f6,f4,38,c,34,0,8,0)
--1496:	dfanm(5,1)
--1499:	dir(0,90)

        return 0;
    end;

    script4 = function(self)
--149d:	msped(0,0,5)
--14a1:	move(0,8a,f5,1d,b)
--14a7:	move(0,a,f6,37,a)
--14ad:	wait(f,0)
--14b0:	move(0,cc,f2,84,8)
--14b6:	dir(0,50)
--14b9:	dfanm(6,1)
--14bc:	slidr(0,46)
--14bf:	solid(0)

        return 0;
    end;

    script5 = function(self)
        --XYZI(0,-D34,884,0,1C)
        --DIR(0,50)
        --DFANM(6,1)
        local flags = game:variable_get("bank3[216]")
        if bit.band(flags, hex.to_dec('0x04')) then
            --CANM!2(3,3B,3B,1)
        end;

        return 0;
    end;

    script6 = function(self)
--14df:	anim!2(3,1)

        return 0;
    end;

    script7 = function(self)
--14e3:	tlkon(1)
--14e5:	solid(1)
--14e7:	visi(0)

        return 0;
    end;
};



entity["obasan1"] = {
    on_start = function(self)
--14ea:	char(8)
--14ec:	slidr(0,22)
--14ef:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        --SolidObject(Off)
        --XYZI(0,-A6B,C89,65,9)
        --DIR(0,90)
        --Wait(3C)
        --Wait(3C)

        while true do
            --Wait(3C)
            --Wait(3C)
            --MSPED(0,0,8)
            --DFANM(2,1)
            --FMOVE(0,91,F7,9E,D)
            --DIR(0,90)
            --DFANM(0,1)
            --Wait(3C)
            --Wait(3C)
            --MSPED(0,0,2)
            --MOVE(0,95,F5,89,C)
            --DIR(0,90)
            --DFANM(0,1)
            --Wait(3C)
            --Wait(3C)
        end;

        return 0;
    end;

    script4 = function(self)
--1543:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--154e:	msped(0,0,4)
--1552:	move(0,e9,f4,dd,c)
--1558:	dfanm(3,1)
--155b:	jump(0,0,6,f5,2d,c,34,0,8,0)
--1566:	dfanm(0,1)
--1569:	msped(0,0,8)
--156d:	move(0,93,f5,3d,b)
        script:request_start_wait("avaf", "script3", 6);
--1576:	dir(0,50)
--1579:	anime1(4,1)
        script:request_start_wait("child", "script4", 6);
--157f:	msped(0,0,8)
--1583:	move(0,4d,f6,c3,a)
--1589:	wait(a,0)
        script:request_start_wait("child", "script5", 6);
--158f:	move(0,bc,f4,3,9)
        script:request_start_wait("child", "script6", 6);
--1598:	move(0,a4,ef,88,6)
--159e:	tlkon(1)
--15a0:	solid(1)
--15a2:	visi(0)

        return 0;
    end;
};



entity["woman1"] = {
    on_start = function(self)
--15a5:	char(9)
--15a7:	slidr(0,22)
--15aa:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            local flags = game:variable_get("bank3[216]")
            if bit.band(flags, hex.to_dec('0x04')) then
                --CreateWindow(1,8,4B,65,29)
                --Dialog(1,29)
                --CreateWindow(2,64,4B,72,29)
                --Dialog(2,2A)
            else
                --CharMovable(Off)
                --MenuAccess(Off)
                --CreateWindow(1,8,4B,63,29)
                --Dialog(1,24)
                --CreateWindow(2,64,4B,50,29)
                --Dialog(2,25)
                --CreateWindow(1,8,4B,ED,29)
                --Dialog(1,26)
                --CreateWindow(2,64,4B,48,29)
                --Dialog(2,27)
                --CreateWindow(1,8,4B,AC,29)
                --Dialog(1,28)
                --CreateWindow(2,64,4B,48,29)
                --Dialog(2,27)
                script:request_start_wait("man1", "script6", 6);
                --ANIM!2(3,1)
                game:variable_set("bank3[216]", bit.bor(flags, hex.to_dec('0x04')));
                CharMovable(On)
                MenuAccess(On)
            end;
        else
            script:request_end_wait("man1", "script1", 1);
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1648:	slidr(0,0)
--164b:	solid(1)
--164d:	xyzi(0,0,49,f6,f5,b,63,0,8,0)
--1658:	dir(0,b0)

        return 0;
    end;

    script4 = function(self)
--165c:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--1667:	slidr(0,0)
--166a:	solid(1)
--166c:	msped(0,0,4)
--1670:	move(0,e9,f4,dd,c)
--1676:	dfanm(4,1)
--1679:	jump(0,0,d,f5,52,c,34,0,8,0)
--1684:	dfanm(5,1)
--1687:	msped(0,0,5)
        script:request_start_wait("man1", "script4", 6);
--168e:	move(0,a7,f5,40,b)
--1694:	move(0,5a,f6,21,a)
--169a:	move(0,10,f3,b4,8)
--16a0:	dir(0,d0)
--16a3:	dfanm(6,1)
--16a6:	slidr(0,1e)
--16a9:	solid(0)

        return 0;
    end;

    script5 = function(self)
        --XYZI(0,-CF0,8B4,0,19)
        --DIR(0,D0)
        --DFANM(6,1)
        local flags = game:variable_get("bank3[216]")
        if bit.band(flags, hex.to_dec('0x04')) then
            CANM!2(3,3B,3B,1)
        end;

        return 0;
    end;

    script6 = function(self)
--16c9:	anim!2(3,1)

        return 0;
    end;

    script7 = function(self)
--16cd:	tlkon(1)
--16cf:	solid(1)
--16d1:	visi(0)

        return 0;
    end;
};



entity["emother"] = {
    on_start = function(self)
--16d4:	char(10)
--16d6:	solid(1)
--16d8:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        script:request_start_wait("avaw", "script4", 5);
--16e1:	xyzi(0,0,ba,f0,a1,6,0,0,1e,0)
--16ec:	msped(0,0,4)
--16f0:	move(0,27,f3,df,7)
--16f6:	anim!1(3,1)
--16f9:	wait(1e,0)
--16fc:	turngen(0,50,2,a,1)
--1702:	anim!2(4,1)
--1705:	anim!2(5,1)
--1708:	move(0,5e,f4,82,8)
--170e:	move(0,7f,f5,48,9)
--1714:	akao(0,0,0,29,40,35,0,0,0,0,0,0,0)
--1722:	turngen(0,90,2,a,1)
--1728:	akao(0,0,0,2a,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("door", "script1", 2);
--1739:	fade(0,0,ff,ff,ff,8,6,0)
--1742:	fadew
--1743:	mapjump(93,0,7f,f5,48,9,16,0,90) -- mds7st32

        return 0;
    end;

    script4 = function(self)
--174e:	xyzi(0,0,1e,f6,21,b,31,0,b,0)
--1759:	dir(0,10)
--175c:	canm!2(6,27,27,1)
--1761:	tlkon(0)
--1763:	solid(0)
--1765:	visi(1)

        return 0;
    end;
};



entity["child"] = {
    on_start = function(self)
--1768:	char(11)
--176a:	solid(1)
--176c:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1772:	xyzi(0,0,b5,f4,40,d,65,0,1a,0)
--177d:	msped(0,0,2)
--1781:	move(0,e9,f4,dd,c)
--1787:	dfanm(3,1)
--178a:	jump(0,0,f6,f4,38,c,34,0,8,0)
        script:request_start_wait("obasan1", "script4", 6);
--1798:	dfanm(4,1)
--179b:	msped(0,0,8)
--179f:	dfanm(2,1)
--17a2:	fmove(0,e6,f5,56,b)
--17a8:	dir(0,90)
--17ab:	dfanm(5,1)

        return 0;
    end;

    script4 = function(self)
--17af:	msped(0,0,8)
--17b3:	dfanm(2,1)
--17b6:	fmove(0,71,f6,73,a)
--17bc:	dir(0,90)
--17bf:	dfanm(5,1)

        return 0;
    end;

    script5 = function(self)
--17c3:	msped(0,0,c)
--17c7:	dfanm(2,1)
--17ca:	fmove(0,b5,f4,d6,8)
--17d0:	dir(0,50)
--17d3:	anime1(5,1)
--17d6:	dfanm(0,1)

        return 0;
    end;

    script6 = function(self)
--17da:	msped(0,0,8)
--17de:	move(0,a4,ef,88,6)
--17e4:	tlkon(1)
--17e6:	solid(1)
--17e8:	visi(0)

        return 0;
    end;
};
