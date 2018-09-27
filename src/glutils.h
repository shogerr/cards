#include <iostream>
#define LOGE(...) (std::cout << __VA_ARGS__);

GLuint createProgram(*std::vector<GLchar*> shaderSource);

GLuint createShader(GLenum shaderType, const char* src);
