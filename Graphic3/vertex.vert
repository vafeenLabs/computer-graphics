#version 400
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
in vec3 vp;
out vec3 color;
void main() {
gl_Position =projection*view*model*vec4(vp, 1.0);
color = vec3(0.7,0.7,0.7);
};