#version 330 core
#extension GL_ARB_separate_shader_objects : enable
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;

out vec2 texCoords;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    texCoords = vec2(aTex.x, aTex.y);
}