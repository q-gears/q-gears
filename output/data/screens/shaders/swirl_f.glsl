
// Scene buffer
uniform sampler2D tex0; 
uniform float rt_w = 1280;
uniform float rt_h = 720; 

// Swirl effect parameters
uniform float radius = 400.0;
uniform float angle = 0.3;
uniform vec2 center = vec2(800.0, 300.0);

vec4 PostFX(sampler2D tex, vec2 uv)
{
  vec2 texSize = vec2(rt_w, rt_h);
  vec2 tc = uv * texSize;
  tc -= center;
  float dist = length(tc);
  if (dist < radius)
  {
    float percent = (radius - dist) / radius;
    float theta = percent * percent * angle * 8.0;
    float s = sin(theta);
    float c = cos(theta);
    tc = vec2(dot(tc, vec2(c, -s)), dot(tc, vec2(s, c)));
  }
  tc += center;
  vec3 color = texture2D(tex0, tc / texSize).rgb;
  return vec4(color, 1.0);
}

void main (void)
{
  vec2 uv = gl_TexCoord[0].st;
  gl_FragColor = PostFX(tex0, uv);
}