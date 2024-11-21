#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void circle(float radius, float cX, float cY)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(57, 177, 73);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);
    }
}

void tree() {
    // bottom
    glLineWidth(1);
    glColor3ub(148, 82, 37);
    glBegin(GL_POLYGON);
    glVertex2f(19.5, 12);
    glVertex2f(22.8, 12);
    glVertex2f(22.8, 0);
    glVertex2f(19.5, 0);
    glEnd();

    // leafs
    circle(8.5,21.07,16.69);
    glEnd();
    circle(8.43,18,13.82);
    glEnd();
    circle(8.43,25,12);
    glEnd();



}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    tree();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("tree");
    gluOrtho2D(-40, 40, -40, 40);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
