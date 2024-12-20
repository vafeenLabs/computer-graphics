//#include <glad/glad.h>
//#include <GLFW/glfw3.h> 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream> 
//using namespace std;
//static void key_callback(GLFWwindow* window, int key, int scancode, int action,
//	int mods)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GLFW_TRUE);
//	switch (key)
//	{
//	case GLFW_KEY_ESCAPE:
//		glfwSetWindowShouldClose(window, GLFW_TRUE);
//		break;
//	}
//}
//static GLuint CompileShader(unsigned int type, const string& source)
//{
//	GLuint id = glCreateShader(type);
//	const char* src = source.c_str();
//	glShaderSource(id, 1, &src, nullptr);
//	glCompileShader(id);
//
//	int result;
//	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//	if (result == GL_FALSE)
//	{
//		int length;
//		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//		char* message = new char[length];
//		glGetShaderInfoLog(id, length, &length, message);
//		cout << "Failed to compile shader'\n";
//		cout << message << '\n';
//		return 0;
//	}
//
//	return id;
//}
//static GLuint CreateShader(const string& vertex_shader, const string& fragment_shader)
//{
//	GLuint program = glCreateProgram();
//	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertex_shader);
//	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragment_shader);
//
//	glAttachShader(program, vs);
//	glAttachShader(program, fs);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	//glDeleteShader(vs);
//	//glDeleteShader(fs);
//	return program;
//
//
//}
//float points[] = {
//			-0.5f, 0.5f, 0.0f,		1.0f, 1.0f, 1.0f,
//		0.5f, 0.5f, 0.0f,		0.0f, 0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.7f,
//		-0.5f, -0.5f, 0.0f,		0.3f, 0.0f, 1.0f
//
//};
//
//void init()
//{
//	const string vertex_shader =
//		"#version 400\n"
//		"in vec3 vp;"
//		"in vec3 in_color;"
//		"out vec3 color;"
//		"void main() {"
//		"gl_Position = vec4(vp, 1.0);"
//		"color = in_color;"
//		"}";
//	const string fragment_shader =
//		"#version 400\n"
//		"in vec3 color;"
//		"out vec4 frag_color;"
//		"void main() {"
//		"  frag_color = vec4(color, 1.0);"
//		"}";
//
//	GLuint shader = CreateShader(vertex_shader, fragment_shader);
//	glUseProgram(shader);
//
//	GLuint vbo;
//	GLuint vao;
//	glGenBuffers(1, &vbo);//vertex buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//
//	glGenVertexArrays(1, &vao);//vertex attrib buffer
//	glBindVertexArray(vao);
//	glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(sizeof(float) * 3));
//
//}
//void triang()
//{
//	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//
//
//}
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glfwSetKeyCallback(window, key_callback);
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//}
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//}
//int main(int argc, char** argv)
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW + GLAD", NULL, NULL);
//	if (window == NULL) {
//		cout << "Failed to create GLFW window" << endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		cout << "Failed to initialize GLAD" << endl;
//		return -1;
//	}
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	init();
//	while (!glfwWindowShouldClose(window)) {
//		processInput(window);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		triang();
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glfwTerminate();
//	return 0;
//}
//
//
//
