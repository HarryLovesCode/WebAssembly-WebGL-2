#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <emscripten/emscripten.h>

GLFWwindow *window;

void renderGame() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	float ratio;
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

	glfwSwapBuffers(window);
	glfwPollEvents();
}

int main(void)
{
	if (!glfwInit())
	{
		printf("Failed to initialize GLFW3!\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(640, 480, "Emscripten", NULL, NULL);

	if (!window)
	{
		printf("Failed to create window!\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	emscripten_set_main_loop(renderGame, 0, 0);
}
