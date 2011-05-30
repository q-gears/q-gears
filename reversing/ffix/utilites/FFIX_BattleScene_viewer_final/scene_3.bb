Graphics3D(800,600,32,2);
SetBuffer BackBuffer()

WBuffer True

.Nach

Const vram%=1024*512*2

Global GpuBuffer%=CreateBank(vram)
For i=0 To (vram-1)
	PokeByte(GpuBuffer,i,0)
Next


cam=CreateCamera()
;dds=CreateLight(2)

Global sssr%

AmbientLight 255,255,255

Dialog(False,"","")



f=ReadFile(GetPathName())

AppTitle GetPathName()

Global param%

ReadByte(f)

Global db=ReadByte(f)
ReadShort(f)
Global tmpp%


For i= 1 To db
	gdds%=FilePos(f)
	tmpp=ReadInt(f)
	If ((tmpp Shr 24) And $FF)=$0c Then
		param=(tmpp And $FFFFFF)+gdds+$10
	EndIf
	If ((tmpp Shr 24) And $FF)=$04 Then
		LoadTims(f,(tmpp And $FFFFFF)+gdds)
	EndIf
Next


Dim ccols(1)
Dim ccord#(1,7)

SeekFile(f,4+param)
objs=ReadShort(f)

ReadShort(f)
Global imgs=ReadShort(f)

Dim TexS%(imgs)

blamp=ReadShort(f)
ReadShort(f)
vertOff=ReadShort(f)

SeekFile(f,blamp+param)
ToImages(f,imgs)


;For i=0 To (imgs-1)
;SaveBuffer (TextureBuffer(TexS(i)),"save "+i+".bmp")	
;Next



SeekFile(f,$18+param)


Dim obj(objs,1)


vertpos=vertoff+param

maxx=0


For i=1 To objs

m=CreateMesh()
s=CreateSurface(m)
;EntityFX m,2

timp=ReadShort(f)


;If tmp<>8 And tmp<>0 Then EntityParent obj(i,0),obj(tmp,0)

verts=ReadShort(f)
ReadShort(f)


	cpl=ReadShort(f)
	tmppl=ReadShort(f)
	cord=ReadShort(f)
;PositionEntity obj(i,0),x/50.0,y/50.0,z/50.0
pols=ReadShort(f)
tris=ReadShort(f)

tmp=FilePos(f)
SeekFile f,vertpos

	For j=1 To verts
	
	x=ReadSShort(f)
	y=ReadSShort(f)
	z=ReadSShort(f)
	AddVertex(s,x/50.0,-y/50.0,z/50.0)
;	VertexNormal(s,j-1,-x,-y,-z)
;	VertexColor(s,j-1,Rand(100,150),Rand(100,150),Rand(100,150))
;	If timp=0 Then
;	ttmp=CreateSphere(4,m)
;	;ScaleEntity ttmp,.1,.1,.1
;	PositionEntity(ttmp,x/50.0,-y/50.0,z/50.0)
;	EndIf
	Next
vertpos=FilePos(f)


SeekFile f,(cpl+$18+(i-1)*16+param)

Dim ccols(pols+tris)
Dim scols(pols+tris)

For j=1 To pols+tris
ppctmp%=ReadInt(f)
ccols(j-1)=((ppctmp Shr 22) And $7c )/ 4
scols(j-1)=ppctmp Shr 29
;DebugLog ccols(j-1)

;If ccols(j-1)>imgs Then ccols(j-1)=ccols(j-1) And $3F

Next

SeekFile f,(cord+$18+(i-1)*16+param)
Dim ccord(pols+tris,7)

For j=1 To pols

ccord(j-1,0)=ReadByte(f)/255.0
ccord(j-1,1)=ReadByte(f)/255.0
ccord(j-1,2)=ReadByte(f)/255.0
ccord(j-1,3)=ReadByte(f)/255.0
ccord(j-1,4)=ReadByte(f)/255.0
ccord(j-1,5)=ReadByte(f)/255.0
ccord(j-1,6)=ReadByte(f)/255.0
ccord(j-1,7)=ReadByte(f)/255.0
Next
For k=1 To tris
ccord(j+k-2,0)=ReadByte(f)/255.0
ccord(j+k-2,1)=ReadByte(f)/255.0
ccord(j+k-2,2)=ReadByte(f)/255.0
ccord(j+k-2,3)=ReadByte(f)/255.0
ccord(j+k-2,4)=ReadByte(f)/255.0
ccord(j+k-2,5)=ReadByte(f)/255.0
Next

cdsee=0

SeekFile f,(tmppl+$18+(i-1)*16+param)

For j=1 To pols
tm1=ReadShort(f)/4
tm2=ReadShort(f)/4
tm3=ReadShort(f)/4
tm4=ReadShort(f)/4

g=CreateMesh()
gf=CreateSurface(g)


DebugLog ccols(cdsee)

EntityTexture(g,TexS(ccols(cdsee)))

If scols(cdsee)<>0 Then EntityBlend g,3

AddVertex gf,VertexX(s,tm1),VertexY(s,tm1),VertexZ(s,tm1),ccord(cdsee,0),ccord(cdsee,1)
AddVertex gf,VertexX(s,tm2),VertexY(s,tm2),VertexZ(s,tm2),ccord(cdsee,2),ccord(cdsee,3)
AddVertex gf,VertexX(s,tm3),VertexY(s,tm3),VertexZ(s,tm3),ccord(cdsee,4),ccord(cdsee,5)
AddVertex gf,VertexX(s,tm4),VertexY(s,tm4),VertexZ(s,tm4),ccord(cdsee,6),ccord(cdsee,7)

AddTriangle gf,0,1,2
AddTriangle gf,2,1,3

;AddTriangle s,tm1,tm2,tm3
;AddTriangle s,tm3,tm2,tm4
If tm1>maxx Then maxx=tm1
If tm2>maxx Then maxx=tm2
If tm3>maxx Then maxx=tm3
If tm4>maxx Then maxx=tm4
cdsee=cdsee+1
Next


For j=1 To tris
tm1=ReadShort(f)/4
tm2=ReadShort(f)/4
tm3=ReadShort(f)/4

g=CreateMesh()
gf=CreateSurface(g)

EntityTexture(g,TexS(ccols(cdsee)))
If scols(cdsee)<>0 Then EntityBlend g,3

AddVertex gf,VertexX(s,tm1),VertexY(s,tm1),VertexZ(s,tm1),ccord(cdsee,0),ccord(cdsee,1)
AddVertex gf,VertexX(s,tm2),VertexY(s,tm2),VertexZ(s,tm2),ccord(cdsee,2),ccord(cdsee,3)
AddVertex gf,VertexX(s,tm3),VertexY(s,tm3),VertexZ(s,tm3),ccord(cdsee,4),ccord(cdsee,5)

AddTriangle gf,0,1,2

;AddTriangle s,tm1,tm2,tm3
If tm1>maxx Then maxx=tm1
If tm2>maxx Then maxx=tm2
If tm3>maxx Then maxx=tm3
cdsee=cdsee+1
Next

SeekFile f,tmp



Next


;EntityTexture CreateCube(),TexS(8)


CloseFile(f)




MoveMouse GraphicsWidth()/2,GraphicsHeight()/2	
While Not KeyDown(1)
	
	;TurnEntity c,MouseYSpeed(),-MouseXSpeed(),0
	mouselook(cam)
	If KeyDown(200) Then MoveEntity cam,0,0,1
	If KeyDown(208) Then MoveEntity cam,0,0,-1

	RenderWorld()

;	Text 10,10,maxx
;	Text 10,20,sssr
	If KeyHit(57) ggg=Not ggg:WireFrame ggg 
		
	If KeyHit(28) ClearWorld(1,1,1) : Goto nach	
	
	Flip
Wend
End


Function mouselook(ent)

	mxspd#=MouseXSpeed()*0.25
	myspd#=MouseYSpeed()*0.25

	MoveMouse GraphicsWidth()/2,GraphicsHeight()/2	
	
	campitch#=EntityPitch(ent)+myspd#
	
	If campitch#<-85 Then campitch#=-85
	If campitch#>85 Then campitch#=85

	RotateEntity ent,campitch#,EntityYaw(ent)-mxspd#,0
End Function

Function ReadSShort%(fl%)
	Local qq%
	qq=ReadShort(fl)
	If qq>32767 Then qq=qq-65536
	Return qq
End Function

;Type TimS
;	Field X%,Y%,PageX%,PageY%
;	Field wi%,hi%
;	Field bytes%
;	Field BitmAp%
;End Type

Function LoadTim(fl%)
Local hasClut%=0
Local tmmp%,sizeof%

Local poloj%

;;	c.tims=New TimS 
	ReadInt(fl)
	tmmp=ReadInt(fl)
	If (tmmp And 8) = 8 Then hasClut=1
	If (tmmp And 7) = 1 Then cbytes=1
	If (tmmp And 7) = 2 Then cbytes=2
	If (tmmp And 7) = 3 Then cbytes=3
	tmmp=FilePos(fl)
	If hasClut=1 Then
		SeekFile(fl,tmmp+ReadInt(fl))
		tmmp=FilePos(fl)
	EndIf
	sizeof=(ReadInt(fl)-12)
;;	c\BitmAp=CreateBank(sizeof)
	cx=ReadShort(fl)
	cy=ReadShort(fl)
	cwi=ReadShort(fl)
	chi=ReadShort(fl)
	
	poloj=cx*2 + cy*1024*2
	
	For j=0 To (chi-1)
	For i=0 To ((cwi*cbytes)-1)
	PokeByte(GpuBuffer,poloj+i,ReadByte(fl))	
	Next
	poloj=poloj+1024*2
	Next
	
;	For i=0 To (sizeof-1)
;		PokeByte(c\bitmap,i,ReadByte(fl))
;	Next
;;;	c\pagex=Floor(c\x/64)
;;	;c\pagey=Floor(c\y/256)
;;;	;	c\x=c\x-c\pagex*64
;;;	c\y=c\y-c\pagey*256
End Function

Function LoadTims(fl%,addr%)
Local endg%=FilePos(fl)
Local hows%,fif%,fuf%,tmmp%
SeekFile(fl,addr)
If ReadByte(fl)<>4 Then RuntimeError("FUCKED TIMS") : End

hows=ReadByte(fl)
ReadShort(fl)
 
For i=1 To hows
	ReadShort(fl)
Next
If (hows And 1) = 1 Then ReadShort(fl)

For i=1 To hows
	fif=FilePos(fl)
	tmmp=ReadInt(fl)
	fuf=FilePos(fl)
	SeekFile(fl,tmmp+fif)
	LoadTim(fl)
	SeekFile(fl,fuf)
Next

SeekFile(fl,endg)
End Function

Function GetTim%(Px%,py%,X%,Y%)
Local offx%,offy%
	Return PeekByte( gpubuffer, px*128 + py*256*1024*2+x+y*1024*2)
;	For c.tims=Each tims
;		If Px>=c\pagex And py>=c\pagey And X<=(c\x+c\wi*c\bytes) And Y<=(c\y+c\hi*c\bytes) And X>= c\x And Y>=c\y Then
;			offx=x-c\x
;			offy=y-c\y
;			Return PeekByte(c\bitmap,offy*c\bytes*c\wi+((px-c\pagex)*64*c\bytes)+offx)
;			Exit
;		EndIf
;	Next
End Function

Function ToImages(fl%,kol%)
Local tmmp%,ktmp%,pipka%
Local mass%[256]
Local ppc#=8.22580;

;pdd=WriteFile("debug.txt")
For i=0 To (kol-1)
	tmmp=ReadInt(fl)
	
	For j=0 To 255
		mass[j]=0
		ktmp=0
		ktmp=GetTim(0,0,((tmmp Shr 16) And $3F)+j*2,(tmmp Shr 16) Shr 6)
		ktmp=ktmp Or (GetTim(0,0,((tmmp Shr 16) And $3F)+j*2+1,(tmmp Shr 16) Shr 6 ) Shl 8)
		
;		If i=11 Then 	WriteLine(pdd, (tmmp Shr 16) Shr 6 +" " +((tmmp Shr 16) And $3F) )
		
		pipka=ktmp Shr 15
		If pipka Then
		mass[j]=($FF Shl 24) Or (((((ktmp) And $1f)*ppc) And $FF) Shl 16) Or ((((((ktmp) Shr 5) And $1f)*ppc) And $FF) Shl 8) Or ((((((ktmp) Shr 10 ) And $1f )*ppc) And $FF))
		Else
		mass[j]=($00 Shl 24) Or (((((ktmp) And $1f)*ppc) And $FF) Shl 16)  Or  ((((((ktmp) Shr 5) And $1f) *ppc) And $FF) Shl 8) Or ((((((ktmp) Shr 10 ) And $1f )*ppc) And $FF))
		EndIf
		
	Next
	
	
;;;;	If (tmmp And 15)<=12 Then
		TexS(i)=CreateTexture(256,256,1+2+4+512)
		LockBuffer TextureBuffer(TexS(i))
		For yj=0 To 255
			For xj=0 To 255
				ktmp=GetTim((tmmp And 15),(tmmp And 16) Shr 4,xj,yj)
				WritePixelFast(xj,yj,mass[ktmp],TextureBuffer(TexS(i)))
			Next
		Next
		UnlockBuffer TextureBuffer(TexS(i))
;;;;	Else
;;;;		;TexS(i)=CreateTexture(256-(((tmmp And 15)-12)*64),256,4)
;;;;		TexS(i)=CreateTexture(256,256,1+2+4+512)
;;;;	;	ScaleTexture(TexS(i),4.0/Float(((tmmp And 15)-12)),1)
;;;;		LockBuffer TextureBuffer(TexS(i))
;;;;		For yj=0 To 255
;;;;			;For xj=0 To (256-(((tmmp And 15)-12)*64)-1)
;;;;			For xj=0 To (255)
;;;;				ktmp=GetTim((tmmp And 15),(tmmp And 16) Shr 4,xj,yj)
;;;;				
;;;;				WriteLine(pdd,i+" "+xj+" "+yj+" "+ktmp)
;;;;				
;;;;				WritePixelFast(xj,yj,mass[ktmp],TextureBuffer(TexS(i)))
;;;;			Next
;;;;		Next
;;;;		UnlockBuffer TextureBuffer(TexS(i))
;;;;	EndIf
Next
;	CloseFile(pdd)
End Function