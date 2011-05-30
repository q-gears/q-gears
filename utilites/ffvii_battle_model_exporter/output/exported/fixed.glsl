
void main(void)
{
    gl_Position = ftransform();

    gl_FrontColor = gl_Color; // write vertex colour
    gl_TexCoord[0] = gl_MultiTexCoord0; // write tex coords 0
}
