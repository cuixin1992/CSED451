#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include <vector>	

GLfloat jump = 0.0f; // jump height
GLfloat jumpSpeed = 0.05f; // jump speed
bool jumping = false; // jumping flag
int windowWidth = 500; // window width
int windowHeight = 500; // window height

GLfloat fireball = 1.5f;
GLfloat fireballSpeed = 0.001f; // fireball speed

void drawRectangle() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(-0.1f, -0.1f);
    glEnd();
}

void drawFireBall() {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, 0.05f);
        glVertex2f(0.05f, 0.05f);
        glVertex2f(0.05f, -0.05f);
        glVertex2f(-0.05f, -0.05f);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        glTranslatef(0.0f, jump, 0.0f);
        drawRectangle();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(fireball, 0.0f, 0.0f);
        drawFireBall();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    if (jumping) {
        if (jump < 1.0f) {
            jump += jumpSpeed;
        }
        else {
            jumping = false;
        }
    }
    else {
        if (jump > 0.0f) {
            jump -= jumpSpeed;
        }
    }

    fireball -= fireballSpeed;
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        jumping = true;
    }
}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glViewport(0, 0, windowWidth, windowHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (windowWidth <= windowHeight) {
        GLfloat aspect = (GLfloat)windowHeight / (GLfloat)windowWidth;
        glOrtho(-1.0, 1.0, -1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else {
        GLfloat aspect = (GLfloat)windowWidth / (GLfloat)windowHeight;
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, -1.0, 1.0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Jumping Rectangle");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(10, update, 0);
    glutMainLoop();
}