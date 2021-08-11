#version 330 core
#extension GL_ARB_separate_shader_objects : enable
out vec4 FragColor;
in vec2 texCoords;

uniform sampler2D atlas;

void main()
{
    FragColor = texture(atlas, vec2(texCoords.x, -texCoords.y)/8.);
}