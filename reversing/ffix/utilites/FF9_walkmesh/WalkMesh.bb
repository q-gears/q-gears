Include "FastImage.bb"
Include "3DLib.bb"

Graphics3D 800,600,0,2
InitDraw

;ggrrr=LoadImage("C:\185_0.bmp")

;zdc#=600.0/ImageHeight(ggrrr)

;ScaleImage ggrrr,zdc,zdc

Type tochka
	Field x#,y#,z#,x2#,y2#,z2#
End Type

.scop

cam=CreateCamera()

msh=CreateMesh()
sur=CreateSurface(msh)
EntityFX(msh,16)

wire=True

Dialog(False,"","")

fil=ReadFile(GetPathName())
AppTitle GetPathName()

SeekFile(fil,$28)
skol=ReadShort(fil)

SeekFile(fil,$36)
skot=ReadShort(fil)+4

SeekFile(fil,$3e)
sko=ReadShort(fil)+4

Dim pivo%(5000)





SeekFile(fil,$40)

ppc=0

For i=0 To (skol-1)
ReadShort(fil)
ReadShort(fil)
tmp2=ReadShort(fil)
ReadShort(fil)

ReadShort(fil)
ReadShort(fil)
ds=ReadShort(fil)
tmp=FilePos(fil)
SeekFile(fil,sko+ds*6)
x#=ReadSShort(fil)/20.0
y#=-ReadsShort(fil)/20.0
z#=ReadSShort(fil)/20.0
SeekFile fil,(skot+tmp2*$20 + 4)
x#=x#+ReadSShort(fil)/20.0
y#=y#-ReadsShort(fil)/20.0
z#=z#+ReadSShort(fil)/20.0
AddVertex sur,x,y,z	
SeekFile(fil,tmp)

kopx#=x
kopy#=y
kopz#=z


ds=ReadShort(fil)
tmp=FilePos(fil)
SeekFile(fil,sko+ds*6)
x#=ReadSShort(fil)/20.0
y#=-ReadsShort(fil)/20.0
z#=ReadSShort(fil)/20.0
SeekFile fil,(skot+tmp2*$20 + 4)
x#=x#+ReadSShort(fil)/20.0
y#=y#-ReadSShort(fil)/20.0
z#=z#+ReadSShort(fil)/20.0
AddVertex sur,x,y,z	
SeekFile(fil,tmp)

kopx=kopx+x
kopy=kopy+y
kopz=kopz+z

ds=ReadShort(fil)
tmp=FilePos(fil)
SeekFile(fil,sko+ds*6)
x#=ReadSShort(fil)/20.0
y#=-ReadsShort(fil)/20.0
z#=ReadSShort(fil)/20.0
SeekFile fil,(skot+tmp2*$20 + 4)
x#=x#+ReadSShort(fil)/20.0
y#=y#-ReadSShort(fil)/20.0
z#=z#+ReadSShort(fil)/20.0
AddVertex sur,x,y,z	
SeekFile(fil,tmp)


kopx=kopx+x
kopy=kopy+y
kopz=kopz+z
;
pivo(i)=CreatePivot()
PositionEntity pivo(i),kopx/3.0,kopy/3.0,kopz/3.0

ReadShort(fil)
ReadShort(fil)
ReadShort(fil)


s1=ReadShort(fil)
s2=ReadShort(fil)
s3=ReadShort(fil)

If s1=$FFFF Then s1=-1
If s2=$FFFF Then s2=-1
If s3=$FFFF Then s3=-1

If s1=-1 Then 
cc.tochka=New tochka 
cc\x=VertexX(sur,ppc+2)
cc\y=VertexY(sur,ppc+2)
cc\z=VertexZ(sur,ppc+2)
cc\x2=VertexX(sur,ppc)
cc\y2=VertexY(sur,ppc)
cc\z2=VertexZ(sur,ppc)
EndIf

If s2=-1 Then 
cc.tochka=New tochka 
cc\x=VertexX(sur,ppc+1)
cc\y=VertexY(sur,ppc+1)
cc\z=VertexZ(sur,ppc+1)
cc\x2=VertexX(sur,ppc)
cc\y2=VertexY(sur,ppc)
cc\z2=VertexZ(sur,ppc)
EndIf

If s3=-1 Then 
cc.tochka=New tochka 
cc\x=VertexX(sur,ppc+2)
cc\y=VertexY(sur,ppc+2)
cc\z=VertexZ(sur,ppc+2)
cc\x2=VertexX(sur,ppc+1)
cc\y2=VertexY(sur,ppc+1)
cc\z2=VertexZ(sur,ppc+1)
EndIf

NameEntity pivo(i),i+" :"+s1+" "+s2+" "+s3


ReadShort(fil)

ReadShort(fil)
ReadShort(fil)
ReadShort(fil)
ReadShort(fil)

AddTriangle sur,ppc+2,ppc+1,ppc
;AddTriangle sur,ppc+2,ppc,ppc+1
ppc=ppc+3
Next



CloseFile fil

WireFrame wire


Local mat.matrix_t=New matrix_t
mat\aa=-readmatr($0F9F)
mat\ab=readmatr($0000)
mat\ac=readmatr($0374)
mat\ba=-readmatr($0167)
mat\bb=readmatr($0D71)
mat\bc=readmatr($F9A6)
mat\ca=-readmatr($FCE4)
mat\cb=readmatr($06F8)
mat\cc=readmatr($0E10)

camy# = ATan2(-mat\ca,mat\aa)
camz# = ATan2(-mat\bc,mat\bb)
camx#= ASin(mat\ba)

;AlignToVector cam,$0F9F,$0000,$0374,1

CameraClsMode cam,False,True

RotateEntity cam,camx,camy+90,camz

PositionEntity cam,$017A/20.0,$0C39/20.0,$CA/20.0

;CameraZoom cam,

MoveMouse GraphicsWidth()/2,GraphicsHeight()/2	
While Not KeyDown(1)
Cls
;DrawImage ggrrr,400-ImageWidth(ggrrr)/2,0
	
	If KeyDown(200) Then MoveEntity cam,0,0,1
	If KeyDown(208) Then MoveEntity cam,0,0,-1
	If KeyDown(203) Then MoveEntity cam,-1,0,0
	If KeyDown(205) Then MoveEntity cam,1,0,0
	mouselook(cam)
	
	If KeyHit(57) Then wire=Not wire : WireFrame wire
	
	If KeyHit(28) Then 
		For cc.tochka = Each tochka
			Delete cc
		Next
		ClearWorld 1,1,1
		Goto scop
	EndIf
	
	RenderWorld
	
	For i=0 To skol-1
	If EntityInView(pivo(i),cam) Then
			CameraProject(cam,EntityX(pivo(i)),EntityY(pivo(i)),EntityZ(pivo(i)))
			Text ProjectedX(),ProjectedY(),EntityName(pivo(i))
		EndIf
	Next
	StartDraw
	For cc.tochka = Each tochka
		CameraProject(cam,cc\x,cc\y,cc\z)
		dx#=ProjectedX()
		dy#=ProjectedY()
		CameraProject(cam,cc\x2,cc\y2,cc\z2)
		
		SetColor 255,0,0
		If dx<>0 And dy<>0 And ProjectedX()<>0 And ProjectedY()<>0 Then  DrawLineSimple dx,dy,ProjectedX(),ProjectedY()
		
	Next
	EndDraw
	If KeyHit(2) Then 
	sr$=""
		For i=0 To Rand(0,10) 
			sr=sr+Chr(Rand(65,90))
		Next
		SaveBuffer(BackBuffer(),sr+".bmp")
	EndIf
	
	Text 10,10,EntityPitch(cam)+" "+EntityYaw(cam)+" "+EntityRoll(cam)
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


Function readmatr#(ppr%)
	Local brr%,pcpv#
	pcpv#=(Float(ppr And $7fff))/4096.0
	If ppr>32767 Then pcpv=-pcpv
	Return pcpv#
End Function