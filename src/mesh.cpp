#include "mesh.hpp"

Mesh::Mesh(std::vector<Vertex> verts)
{

    vertices = verts;

    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    // Generate vbos
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glEnableVertexAttribArray(1);


}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &VBO);
}

void Mesh::use () {
    glBindVertexArray(VAO);
}