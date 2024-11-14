#include <windows.h>
#include <GL/glut.h>

void rectangle1() {
    glBegin(GL_POLYGON);
    glVertex2f(-5.0, 0.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(5.0, 2.0);
    glVertex2f(-5.0, 2.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5.0, 0.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(5.0, 2.0);
    glVertex2f(-5.0, 2.0);
    glEnd();
}

void rectangle2() {
    glBegin(GL_POLYGON);
    glVertex2f(-5.0, 2.0);
    glVertex2f(5.0, 2.0);
    glVertex2f(5.0, 4.0);
    glVertex2f(-5.0, 4.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5.0, 2.0);
    glVertex2f(5.0, 2.0);
    glVertex2f(5.0, 4.0);
    glVertex2f(-5.0, 4.0);
    glEnd();
}

void rectangle3() {
    glBegin(GL_POLYGON);
    glVertex2f(5.0, 6.0);
    glVertex2f(-5.0, 6.0);
    glVertex2f(-5.0, 4.0);
    glVertex2f(5.0, 4.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.0, 6.0);
    glVertex2f(-5.0, 6.0);
    glVertex2f(-5.0, 4.0);
    glVertex2f(5.0, 4.0);
    glEnd();
}

void rectangle4() {
    glBegin(GL_POLYGON);
    glVertex2f(5.0, 8.0);
    glVertex2f(-5.0, 8.0);
    glVertex2f(-5.0, 6.0);
    glVertex2f(5.0, 6.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.0, 8.0);
    glVertex2f(-5.0, 8.0);
    glVertex2f(-5.0, 6.0);
    glVertex2f(5.0, 6.0);
    glEnd();
}

void rectangle5() {

    glBegin(GL_POLYGON);
    glVertex2f(-5.0, -2.0);
    glVertex2f(-5.0, -4.0);
    glVertex2f(5.0, -4.0);
    glVertex2f(5.0, -2.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5.0, -2.0);
    glVertex2f(-5.0, -4.0);
    glVertex2f(5.0, -4.0);
    glVertex2f(5.0, -2.0);
    glEnd();
}

void rectangle6() {
    glBegin(GL_POLYGON);
    glVertex2f(-5.0, -2.0);
    glVertex2f(5.0, -2.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(-5.0, 0.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5.0, -2.0);
    glVertex2f(5.0, -2.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(-5.0, 0.0);
    glEnd();

}

void rectangle7() {
    glBegin(GL_POLYGON);
    glVertex2f(-5.0, -4.0);
    glVertex2f(-5.0, -6.0);
    glVertex2f(5.0, -6.0);
    glVertex2f(5.0, -4.0);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5.0, -4.0);
    glVertex2f(-5.0, -6.0);
    glVertex2f(5.0, -6.0);
    glVertex2f(5.0, -4.0);
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(2);

    glColor3ub(0, 176, 80);
    rectangle1();
    glColor3ub(75, 172, 198);
    rectangle2();
    glColor3ub(79, 129, 189);
    rectangle3();
    glColor3ub(128, 100, 162);
    rectangle4();
    glColor3ub(255, 255, 0);
    rectangle5();
    glColor3ub(247, 150, 70);
    rectangle6();
    glColor3ub(255, 0, 0);
    rectangle7();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 500);
    glutCreateWindow("");
    glutDisplayFunc(display);
    gluOrtho2D(-10, 10, -10, 10);

    glutMainLoop();


    return 0;
}
