#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// clang-format off
// clang-format on

using namespace std;

void init(GLFWwindow *window) {}

void display(GLFWwindow *window, double currentTime)
{
	glClearColor(1.0, 0.0, 0.0, 1.0);

	// void glClear(GLbitfield mask)
	// GL_COLOR_BUFFERE_BIT : references the color buffer
	// glClear() : clears all of color buffers that OpenGL has
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(void)
{
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	// OpenGL version 2.0
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// monitor, share: for full screen moce and resource sharing
	GLFWwindow *window = glfwCreateWindow(600, 600, "Chapter2 - program1", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL
	gladLoadGL();

	// vertical synchronization (VSyc)
	glfwSwapInterval(1);

	// includes a reference to the GLFW window object
	init(window);

	// rendering loop
	// glfwWindowShouldClose : makes the loop terminate when GLFW detects an sould-close event
	while (!glfwWindowShouldClose(window))
	{

		// includes a reference to the GLFW windows object and the current time
		display(window, glfwGetTime());

		// vertical synchronization (VSyc)
		// paints the screen
		glfwSwapBuffers(window);

		// handles other window-related events
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}