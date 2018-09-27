#ifndef __GLUTILS_HPP_
#define __GLUTILS_HPP_

#include <GL/glew.h>
#include <vector>

#include <iostream>

#define LOGE(...) (std::cout << __VA_ARGS__);

GLuint createProgram(std::vector<std::pair<GLenum, std::string>>* shaderSource);

GLuint createShader(GLenum shaderType, const char* src);

#endif // __GLUTILS_HPP_
