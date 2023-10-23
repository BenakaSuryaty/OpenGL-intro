#version 330 core

out vec4 frag_out;

in vec2 TexCoord;

uniform sampler2D texture1;

void main() {

    frag_out = texture(texture1, TexCoord);
}