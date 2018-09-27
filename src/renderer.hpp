#ifndef __RENDERER_HPP_
#define __RENDERER_HPP_

#include <SDL.h>
#include "glutils.hpp"

#include <string>
#include <vector>

class Renderer {
private:
    std::vector<std::pair<GLenum, std::string>>* shaders_;
    int bufferCount_;
    GLuint program_;
    GLuint* vbo_;
    GLuint vao_;

public:
    Renderer(int bufferCount);
    ~Renderer();

    bool init();
    void setProgram(GLuint program);
    void setShaders(std::vector<std::pair<GLenum, std::string>>*);
    void render();
};

#endif // __RENDERER_HPP_
