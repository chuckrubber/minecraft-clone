#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "shader.hpp"
//#include "render.hpp"
#include "mesh.hpp"

int main()
{
    try
    {
        engine::io::Window window(800, 600, "OpenGL");
        Shader shader("assets/vert_shader.glsl", "assets/frag_shader.glsl");
        std::vector<Vertex> vertices = {
            {{0.f, 0.f, 0.f}, {0.f, 0.f}},
            {{0.f, 1.f, 0.f}, {0.f, 1.f}},
            {{1.f, 1.f, 0.f}, {1.f, 1.f}},
            {{0.f, 0.f, 0.f}, {0.f, 0.f}},
            {{1.f, 1.f, 0.f}, {1.f, 1.f}},
            {{1.f, 0.f, 0.f}, {1.f, 0.f}}};
        // std::vector<Vertex> vertices2 = {
        //     {{-.5f, -1.f, 0.f}, {0.f, 0.f}},
        //     {{0.f, 0.f, 0.f}, {0.f, 1.f}},
        //     {{.5f, -1.f, 0.f}, {1.f, 1.f}}};
        Mesh mesh(vertices);
       // Mesh mesh2(vertices2);

        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        while (!window.shouldClose())
        {

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shader.use();
            mesh.use();
            glDrawArrays(GL_TRIANGLES, 0, vertices.size());
           // mesh2.use();
          //  glDrawArrays(GL_TRIANGLES, 0, vertices.size());

            window.pollEvents();
            window.swapBuffers();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}