#include <iostream>
#include <string>
#include <fstream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Utils.h"

// clang-format off
// clang-format on

using namespace std;
#define numVAOs 1

// GLuint : unsigned int
GLuint renderingProgram;
GLuint vao[numVAOs];

using namespace std;

void init(GLFWwindow *window)
{
	renderingProgram = Utils::createShaderProgram("vertShader.vert", "fragShader.frag");
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

// location of triangle on x axis
float x = 0.0f;
// offset for moving the triangle
float inc = 0.01f;

void display(GLFWwindow *window, double currentTime)
{
	// clear the background to black, each time
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);

	x += inc;

	if (x > 1.0f)
	{
		inc = -0.01f;
	}

	else if (x < -1.0f)
	{
		inc = 0.01f;
	}

	GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");
	glProgramUniform1f(renderingProgram, offsetLoc, x);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(void)
{
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // I don't know what this does
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // and neither this
	GLFWwindow *window = glfwCreateWindow(600, 600, "Chapter2 - program2", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Load GLAD so it configures OpenGL
	gladLoadGL();
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window))
	{
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}