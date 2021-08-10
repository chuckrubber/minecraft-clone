#version 330 core
#extension GL_ARB_separate_shader_objects : enable
out vec4 FragColor;
in vec2 texCoords;

void main()
{
    FragColor = vec4(texCoords, 0.f, 1.0f);
}