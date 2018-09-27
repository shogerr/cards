#include "renderer.hpp"

Renderer::Renderer(int bufferCount) {
    vbo_ = new GLuint[bufferCount];
    bufferCount_ = bufferCount;
}

Renderer::~Renderer() {
    delete[] vbo_;
}

bool Renderer::init() {
    program_ = createProgram(shaders_);

    glGenBuffers(bufferCount_, vbo_);
    glClearColor(0.f, 0.5f, 0.f, 1.f);

    return true;
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::setProgram(GLuint program) {
    program_ = program;
}

void Renderer::setShaders(std::vector<std::pair<GLenum, std::string>>* shaders) {
    shaders_ = shaders;
}
