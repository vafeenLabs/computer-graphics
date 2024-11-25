// #include <GLFW/glfw3.h>
// #include <iostream>

// using namespace std;

// // Указатели на функции OpenGL, которые будут загружены через glfwGetProcAddress
// PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
// PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
// PFNGLBUFFERDATAPROC glBufferData = nullptr;
// PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
// PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
// PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
// PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
// PFNGLCREATESHADERPROC glCreateShader = nullptr;
// PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
// PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
// PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
// PFNGLATTACHSHADERPROC glAttachShader = nullptr;
// PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
// PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
// PFNGLDRAWARRAYSEXTPROC glDrawArrays = nullptr;  // Заменено на PFNGLDRAWARRAYSEXTPROC

// // Функция для загрузки необходимых функций OpenGL
// void loadOpenGLFunctions() {
//     glGenBuffers = (PFNGLGENBUFFERSPROC)glfwGetProcAddress("glGenBuffers");
//     glBindBuffer = (PFNGLBINDBUFFERPROC)glfwGetProcAddress("glBindBuffer");
//     glBufferData = (PFNGLBUFFERDATAPROC)glfwGetProcAddress("glBufferData");
//     glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glfwGetProcAddress("glGenVertexArrays");
//     glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glfwGetProcAddress("glBindVertexArray");
//     glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glfwGetProcAddress("glEnableVertexAttribArray");
//     glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glfwGetProcAddress("glVertexAttribPointer");
//     glCreateShader = (PFNGLCREATESHADERPROC)glfwGetProcAddress("glCreateShader");
//     glShaderSource = (PFNGLSHADERSOURCEPROC)glfwGetProcAddress("glShaderSource");
//     glCompileShader = (PFNGLCOMPILESHADERPROC)glfwGetProcAddress("glCompileShader");
//     glCreateProgram = (PFNGLCREATEPROGRAMPROC)glfwGetProcAddress("glCreateProgram");
//     glAttachShader = (PFNGLATTACHSHADERPROC)glfwGetProcAddress("glAttachShader");
//     glLinkProgram = (PFNGLLINKPROGRAMPROC)glfwGetProcAddress("glLinkProgram");
//     glUseProgram = (PFNGLUSEPROGRAMPROC)glfwGetProcAddress("glUseProgram");
//     glDrawArrays = (PFNGLDRAWARRAYSEXTPROC)glfwGetProcAddress("glDrawArrays");  // Заменено на PFNGLDRAWARRAYSEXTPROC

//     if (!glGenBuffers || !glBindBuffer || !glBufferData || !glGenVertexArrays || !glBindVertexArray ||
//         !glEnableVertexAttribArray || !glVertexAttribPointer || !glCreateShader || !glShaderSource ||
//         !glCompileShader || !glCreateProgram || !glAttachShader || !glLinkProgram || !glUseProgram || !glDrawArrays) {
//         cerr << "Failed to load OpenGL functions" << endl;
//         exit(EXIT_FAILURE);
//     }
// }

// void triang() {
//     GLuint vbo = 0;
//     GLuint vao = 0;
//     float points[] = {
//         0.0f, 0.5f, 0.0f,
//         0.5f, -0.5f, 0.0f,
//         -0.5f, -0.5f, 0.0f
//     };
//     const char* vertex_shader =
//         "#version 330 core\n"
//         "layout (location = 0) in vec3 vp;\n"
//         "void main() {\n"
//         "    gl_Position = vec4(vp, 1.0);\n"
//         "}";
//     const char* fragment_shader =
//         "#version 330 core\n"
//         "out vec4 frag_colour;\n"
//         "void main() {\n"
//         "    frag_colour = vec4(0.2, 0.0, 0.5, 1.0);\n"
//         "}";
//     GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//     GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//     GLuint shader_program = glCreateProgram();
//     glGenBuffers(1, &vbo);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//     glGenVertexArrays(1, &vao);
//     glBindVertexArray(vao);
//     glEnableVertexAttribArray(0);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
//     glShaderSource(vs, 1, &vertex_shader, NULL);
//     glCompileShader(vs);
//     glShaderSource(fs, 1, &fragment_shader, NULL);
//     glCompileShader(fs);
//     glAttachShader(shader_program, fs);
//     glAttachShader(shader_program, vs);
//     glLinkProgram(shader_program);
//     glUseProgram(shader_program);
//     glBindVertexArray(vao);
//     glDrawArrays(GL_TRIANGLES, 0, 3);
// }

// void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
// }

// int main() {
//     if (!glfwInit()) {
//         cerr << "Failed to initialize GLFW" << endl;
//         return -1;
//     }

//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW without glad", NULL, NULL);
//     if (window == NULL) {
//         cerr << "Failed to create GLFW window" << endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);

//     // Загрузка OpenGL-функций
//     loadOpenGLFunctions();

//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     while (!glfwWindowShouldClose(window)) {
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         triang();

//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }
