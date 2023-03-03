#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>	

typedef struct rect {
	float x;
	float y;
	float width;
	float height;
} rect;

rect rectangle;

void init(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_FLAT);
	rectangle.x = 0.1;
	rectangle.y = 0.1;
	rectangle.width = 0.1;
	rectangle.height = 0.15;
}

std::vector<glm::vec3> position = {
glm::vec3(0.0f, 0.0f, 0.0f),
glm::vec3(0.0f, 1.0f, 0.0f),
glm::vec3(1.0f, 1.0f, 0.0f),
glm::vec3(1.0f, 0.0f, 0.0f),
};

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(rectangle.x, rectangle.y);
		glVertex2f(rectangle.x, rectangle.y + rectangle.width);
		glVertex2f(rectangle.x + rectangle.height, rectangle.y + rectangle.width);
		glVertex2f(rectangle.x + rectangle.height, rectangle.y); 
	glEnd();
	//glFlush();
	glutSwapBuffers();
}
void main(int argc, char** argv) {
	// inspect array elements and print to console
	const float* probe = &position[0].x;
	for (size_t i = 0; i < position.size() * 3; i++) {
		std::cout << probe[i] << std::endl;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(display);

	glewInit();
	glutMainLoop();
}