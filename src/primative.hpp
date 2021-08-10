#include "mesh.hpp"
#include <glm/glm.hpp>

struct quad {
    Vertex vertices[4];
    GLuint indices[6] = {0, 1, 2, 0, 2, 3};
};