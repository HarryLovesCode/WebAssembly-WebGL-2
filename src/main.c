#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <emscripten/emscripten.h>

GLFWwindow *window;

void errorCallback(int error, const char *description) {
    fputs(description, stderr);
}

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

int main(int argc, char **argv) {
	glfwSetErrorCallback(errorCallback);
	
	if (!glfwInit()) {
		fputs("Failed to initialize GLFW3!", stderr);
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(640, 480, "Emscripten", NULL, NULL);

	if (!window) {
		fputs("Failed to create GLFW3 window!", stderr);
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	/* Initialize main loop which is the same as:
	 * window.requestAnimationFrame(renderGame)
	 * in this case.
	 */
	emscripten_set_main_loop(renderGame, 0, 0);
}
