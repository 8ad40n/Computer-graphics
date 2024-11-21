#include <windows.h>
#include <GL/glut.h>

void bench() {

    // upper
    glLineWidth(1);
    glColor3ub(196, 242, 143);
    glBegin(GL_POLYGON);
    glVertex2f(-60, 15);
    glVertex2f(-45, 15);
    glVertex2f(-45, 10);
    glVertex2f(-60,10);
    glEnd();

    // lower
    glLineWidth(1);
    glColor3ub(148, 82, 37);
    glBegin(GL_POLYGON);
    glVertex2f(-45, 10);
    glVertex2f(-60,10);
    glVertex2f(-65, 5);
    glVertex2f(-40, 5);
    glEnd();


    // bottom
    glLineWidth(1);
    glColor3ub(105, 94, 84);
    glBegin(GL_POLYGON);
    glVertex2f(-62.9, 5);
    glVertex2f(-59.1,5);
    glVertex2f(-59.1, 0);
    glVertex2f(-62.9, 0);
    glEnd();

    glLineWidth(1);
    glColor3ub(105, 94, 84);
    glBegin(GL_POLYGON);
    glVertex2f(-46.1, 5);
    glVertex2f(-41.97,5);
    glVertex2f(-41.97, 0);
    glVertex2f(-46.1, 0);
    glEnd();

    glLineWidth(1);
    glColor3ub(105, 94, 84);
    glBegin(GL_POLYGON);
    glVertex2f(-57.6, 5);
    glVertex2f(-55,5);
    glVertex2f(-55, 2.85);
    glVertex2f(-57.6, 2.85);
    glEnd();

    glLineWidth(1);
    glColor3ub(105, 94, 84);
    glBegin(GL_POLYGON);
    glVertex2f(-50, 5);
    glVertex2f(-47.5,5);
    glVertex2f(-47.5, 3);
    glVertex2f(-50, 3);
    glEnd();

}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    bench();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("tree");
    gluOrtho2D(-80, 20, -20, 40);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
