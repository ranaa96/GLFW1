#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;


float screenWidth = 700;
float screenHieght = 700;
float a;
float R = 0.0;
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void drawTriangle();
int main() {
	GLFWwindow *window;
	//initilize library
	if (!glfwInit()) {
		cout << " Can't initilize the GLFW";
		return -1;
	}
	//Create Window
	window = glfwCreateWindow(screenWidth, screenHieght, "GLFW", NULL, NULL);
	if (!window)
	{
		cout << "Can't render the window ";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glViewport(0.0f, 0.0f, screenWidth, screenHieght); //draw openGl in pixels 
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
		//glTranslatef(0.0, 0.0, -15.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		
		glColor3f(0.5f, 0.6f, 1.0f);
		glTranslatef(0.0, 1.0*cos(a), 1.0*sin(a));
		glRotatef(R, 0.0, 1.0, 0.0);
		glTranslatef(0.0, -1.0*cos(a), -1.0*sin(a));
		drawCircle();
		R += 0.1;
		glPopMatrix();
		
		
		
		glfwSetKeyCallback(window, keyCallback);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}


void drawCircle() {
	
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glColor3f(0.0f, 0.4f, 0.8f);
		a = i * 3.142 / 180;
		glVertex3f(0.125*cos(a), 0.125*sin(a), 0.0);
	}
	glEnd();
	
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}