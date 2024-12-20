#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "GLModel.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Affine.h"
#include "parse.h"
using namespace std;
static void glfwError(int id, const char* description)
{
	std::cout << description << std::endl;
}

// ÏÎ×ÅÌÓ ÌÛ ÓÏÐÀÂËßÅÌ ÀÒÐÈÁÓÒÀÌÈ Â ØÅÉÄÅÐÅ À ÍÅ ÁÓÔÔÅÐÅ??????????????????????
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
glm::vec3 points[]  {
	glm::vec3(-0.5f, 0.5f, 0.0f),		glm::vec3(1.0f, 1.0f, 1.0f),
glm::vec3(  0.5f, 0.5f, 0.0f),		glm::vec3(0.0f, 0.5f, 0.0f),
glm::vec3(0.5f, -0.5f, 0.0f),		glm::vec3(1.0f, 0.0f, 0.7f),
glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.3f, 0.0f, 1.0f ) };
vector<glm::vec3> pvec;
GLModel* model;
void init()
{
	std::vector<glm::vec3> vertices;
	std::vector<int>indices;
	readModelInfoFile("model.txt", vertices, indices);
	string vertPath = "vertex.vert";
	string fragPath = "fragment.frag";
	model = new GLModel(vertices,indices,vertPath,fragPath);

}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glfwSetKeyCallback(window, key_callback);
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main(int argc, char** argv)
{
	glfwSetErrorCallback(&glfwError);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW + GLAD", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	init();

	std::vector<glm::vec3> vertices;
	std::vector<int> indices;
	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 projection = glm::perspective(glm::radians(45.0f),
		4.f / 3.f,
		0.1f,
		100.0f);
	model->viewMatrix = view;
	model->projectionMatrix = projection;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		model->modelMatrix *= affine::rotationY(0.5f);
		model->modelMatrix *= affine::rotationX(0.5f);
		model->draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}