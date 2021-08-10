#include "shader.hpp"

Shader::Shader(std::string vertShaderPath, std::string fragShaderPath)
{
    vertPath = vertShaderPath;
    fragPath = fragShaderPath;
    initShader();
}

Shader::~Shader()
{
    glDeleteShader(shaderProgram);
}

// Simple file to c string
std::string Shader::readFile(std::string path)
{
    std::ifstream file(path, std::ios::binary);
    std::string fileStr;

    std::istreambuf_iterator<char> inputIt(file), emptyInputIt;
    std::back_insert_iterator<std::string> stringInsert(fileStr);

    copy(inputIt, emptyInputIt, stringInsert);


    return fileStr;
}

void Shader::use()
{
    glUseProgram(shaderProgram);
}

void Shader::initShader()
{
    // Get source
    auto vss = readFile(vertPath);
    auto fss = readFile(fragPath);
    auto vertexShaderSource = vss.c_str();
    auto fragmentShaderSource = fss.c_str();

    std::cout << vss;
    std::cout << fss;



    // Create OpenGL objects
    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Bind the sources
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

    // Compile shaders and check for errors
    if (!compileShader(vertexShader))
    {
        char errorlog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, errorlog);
        std::cout << "Vertex shader [" << vertPath << "] failed to compile.\n";
        std::cout << errorlog;
        throw std::runtime_error("Failed vertex shader!");
    }
    if (!compileShader(fragmentShader))
    {
        char errorlog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, errorlog);
        std::cout << "Fragment shader [" << fragPath << "] failed to compile.\n";
        std::cout << errorlog;
        throw std::runtime_error("Failed fragment shader!");
    }

    // Create shader program
    shaderProgram = glCreateProgram();

    // Attach shaders
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Link
    if (!linkProgram(shaderProgram))
    {
        char errorlog[512];
        glGetShaderInfoLog(shaderProgram, 512, NULL, errorlog);
        std::cerr << "Shader program failed to link!\n";
        std::cout << errorlog;
        throw std::runtime_error("Failed linking shader!");
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

bool Shader::compileShader(GLuint shader)
{
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    return success;
}

bool Shader::linkProgram(GLuint program)
{
    glLinkProgram(shaderProgram);
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    return success;
}