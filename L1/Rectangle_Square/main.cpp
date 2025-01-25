#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
void rectangleBorder() {
    glLineWidth(3);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-3, 2);
    glVertex2f(3, 2);
    glVertex2f(3, -1);
    glVertex2f(-3, -1);
    glEnd();
}
void rectangle() {
    glBegin(GL_POLYGON);
    glEnd();
}
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle();
    rectangleBorder();
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL Rectangle with Border");
    glutDisplayFunc(display);
    gluOrtho2D(-20, 20, -20, 20);
    glutMainLoop();
    return 0;
}
