
uniform sampler2D my_color_texture;

void main(void)
{
    vec4 add_color = vec4(0.5, 0.0, 0.0, 1.0);
    vec4 tex_color = texture2D(my_color_texture, gl_TexCoord[0].xy) * (gl_Color + add_color);
    gl_FragColor = vec4(tex_color.xyz, 0.5);
}
