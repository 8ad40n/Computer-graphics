
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

void tra() {
    glColor3ub(255, 0, 0);

    glBegin(GL_POLYGON);
    glVertex2f(-2, 2);
    glVertex2f(2, 2);
    glVertex2f(4, -2);
    glVertex2f(-4, -2);
    glEnd();
}


void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    tra();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("");
    glutDisplayFunc(display);
    gluOrtho2D(-20, 20, -20, 20);

    glutMainLoop();
    return 0;
}


