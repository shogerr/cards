#include "renderer.hpp"
#include <iostream>

const std::string vShaderSrc = 
    "#version 150\n"
    "void main() {\n"
    "   gl_Position = vec4(0.f, 0.f, 0.f, 1.f);\n"
    "}\n";

const std::string fShaderSrc =
    "#version 150\n"
    "out vec4 color;\n"
    "void main() {\n"
    "   color = vec4(1.f, .5f, .5f, 1.f);\n"
    "}\n";

struct Vertex {
    GLfloat pos[4];
};

Vertex rectangle[4] = {{-0.5, 0.5, 0.0, 1.0},
                       {0.5, 0.5, 0.0, 1.0},
                       {0.5, -0.5, 0.0, 1.0},
                       {-0.5, -0.5, 0.0, 1.0}};

void printSdlErrorExit() {
    std::cout << SDL_GetError();
    exit(-1);
}

void test_renderer() {
    SDL_Window* window = NULL;
    SDL_GLContext context;

    bool quit = false;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        printSdlErrorExit();

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    window = SDL_CreateWindow("Cards", 0, 0, 320, 240, SDL_WINDOW_OPENGL);
    if (window == NULL) 
        printSdlErrorExit();

    context = SDL_GL_CreateContext(window);
    if (context == NULL)
        printSdlErrorExit();

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();

    if(glewError != GLEW_OK)
        std::cout << "Error initializing GLEW. " << glewGetErrorString(glewError);

    std::cout << "GL_VERSION" << glGetString(GL_VERSION) << std::endl;


    std::vector<std::pair<GLenum, std::string>> shaders = {
        {GL_VERTEX_SHADER, vShaderSrc},
        {GL_FRAGMENT_SHADER, fShaderSrc}};
    
    Renderer* renderer = new Renderer(1);

    renderer->setShaders(&shaders);
    renderer->init();

    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;
        }

        renderer->render();

        SDL_GL_SwapWindow(window);
    }
}

int main(void) {
    test_renderer();
    return 0;
}
