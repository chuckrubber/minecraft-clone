#include <stdexcept>
#include <iostream>

//#include "render.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "window.hpp"
#include "texture.hpp"
#include "camera.hpp"

int main()
{
    try
    {
        Window window(800, 800, "OpenGL");
        Shader shader("assets/vert_shader.glsl", "assets/frag_shader.glsl");
        std::vector<Vertex> vertices = {
            {{0.f, 0.f, 0.f}, {0.f, 0.f}},
            {{0.f, 1.f, 0.f}, {0.f, 1.f}},
            {{1.f, 1.f, 0.f}, {1.f, 1.f}},
            {{0.f, 0.f, 0.f}, {0.f, 0.f}},
            {{1.f, 1.f, 0.f}, {1.f, 1.f}},
            {{1.f, 0.f, 0.f}, {1.f, 0.f}}};

        Mesh mesh(vertices);

        Texture tex("assets/atlas.png");

        Transform camPos = {{3., 0., 0.}};

        Camera camera(camPos, &window, &shader);

        float deltaTime, lastFrame = 0.0f;

        while (!window.shouldClose())
        {
            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            camera.update(deltaTime);
            camera.activateShader();

            tex.bind();
            mesh.use();

            camera.render(vertices.size());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}