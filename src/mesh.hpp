#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

// std
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec2 uv;
};

class Mesh
{
private:
    GLuint VBO, VAO;
public:
    std::vector<Vertex> vertices;

    Mesh(std::vector<Vertex> verts);
    ~Mesh();

    void use();
};

