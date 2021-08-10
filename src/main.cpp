#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "shader.hpp"

int main()
{
    try
    {
        engine::io::Window window(800, 600, "OpenGL");
        Shader shader("assets/vert_shader.glsl", "assets/frag_shader.glsl");

        while (!window.shouldClose())
        {

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            
            

            glClear(GL_COLOR_BUFFER_BIT);
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