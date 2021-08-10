#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <glm/glm.hpp>
#include "shader.hpp"



class Renderer {
    Shader vertexShader;
    Shader fragmentShader;
    std::vector<Vertex> vertices;

};
