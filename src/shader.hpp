#include <glad/glad.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Shader
{
public:
    Shader(std::string vertShaderPath, std::string fragShaderPath);
    ~Shader();

    void use();

private:
    GLuint shaderProgram;
    std::string vertPath, fragPath;
    void initShader();
    std::string readFile(std::string path);
    bool compileShader(GLuint shader);
    bool linkProgram(GLuint program);
};