#pragma once

#include <glad/glad.h>
#include <string>



class Texture {
    public:
        Texture (std::string path);
        void bind();


    private:
        GLuint texture;
};