#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

const int NUM = 20;
uniform float freq[NUM];

void main(void){
    vec3 color;
    for (float i = 0.0; i < float(NUM); i = i + 1.0) {
        vec2 pos = ( gl_FragCoord.xy / resolution.xy );
        
        pos.y -= 0.5;
        pos.y += sin(pos.x * freq[int(i)] + time) * 0.25
        * sin(time * freq[int(i)] * 0.1);
        
        color += vec3(1.0 - pow(abs(pos.y),0.75/float(NUM)));
    }
    gl_FragColor = vec4(color.r * 0.2, color.g * 0.5, color.b * 1.0, 1.0);
}