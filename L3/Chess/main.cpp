#include <windows.h>
#include <GL/glut.h>

void box1() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(-2.0, 4.0);
    glVertex2f(0.0, 4.0);
    glVertex2f(0.0, 2.0);
    glVertex2f(-2.0, 2.0);
    glEnd();
}

void box2() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 4.0);
    glVertex2f(2.0, 4.0);
    glVertex2f(2.0, 2.0);
    glVertex2f(0.0, 2.0);
    glEnd();
}

void box3() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 4.0);
    glVertex2f(4.0, 4.0);
    glVertex2f(4.0, 2.0);
    glVertex2f(2.0, 2.0);
    glEnd();
}

void box4() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(4.0, 4.0);
    glVertex2f(6.0, 4.0);
    glVertex2f(6.0, 2.0);
    glVertex2f(4.0, 2.0);
    glEnd();
}

void box5() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(-2.0, 2.0);
    glVertex2f(0.0, 2.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-2.0, 0.0);
    glEnd();
}

void box6() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 2.0);
    glVertex2f(2.0, 2.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();
}

void box7() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 2.0);
    glVertex2f(4.0, 2.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(2.0, 0.0);
    glEnd();
}

void box8() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(4.0, 2.0);
    glVertex2f(6.0, 2.0);
    glVertex2f(6.0, 0.0);
    glVertex2f(4.0, 0.0);
    glEnd();
}

void box9() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(-2.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(-2.0, -2.0);
    glEnd();
}

void box10() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(2.0, 0.0);
    glVertex2f(2.0, -2.0);
    glVertex2f(0.0, -2.0);
    glEnd();
}

void box11() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 0.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(4.0, -2.0);
    glVertex2f(2.0, -2.0);
    glEnd();
}

void box12() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(4.0, 0.0);
    glVertex2f(6.0, 0.0);
    glVertex2f(6.0, -2.0);
    glVertex2f(4.0, -2.0);
    glEnd();
}

void box13() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(-2.0, -2.0);
    glVertex2f(0.0, -2.0);
    glVertex2f(0.0, -4.0);
    glVertex2f(-2.0, -4.0);
    glEnd();
}

void box14() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(0.0, -2.0);
    glVertex2f(2.0, -2.0);
    glVertex2f(2.0, -4.0);
    glVertex2f(0.0, -4.0);
    glEnd();
}

void box15() {
    glColor3f(1.0f, 1.0f, 1.0f);  // White
    glBegin(GL_POLYGON);
    glVertex2f(2.0, -2.0);
    glVertex2f(4.0, -2.0);
    glVertex2f(4.0, -4.0);
    glVertex2f(2.0, -4.0);
    glEnd();
}

void box16() {
    glColor3f(0.0f, 0.0f, 0.0f);  // Black
    glBegin(GL_POLYGON);
    glVertex2f(4.0, -2.0);
    glVertex2f(6.0, -2.0);
    glVertex2f(6.0, -4.0);
    glVertex2f(4.0, -4.0);
    glEnd();
}

void drawBorder() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-2.0f, 4.0f);
    glVertex2f(6.0f, 4.0f);
    glVertex2f(6.0f, -4.0f);
    glVertex2f(-2.0f, -4.0f);
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    box1();
    box2();
    box3();
    box4();
    box5();
    box6();
    box7();
    box8();
    box9();
    box10();
    box11();
    box12();
    box13();
    box14();
    box15();
    box16();

    drawBorder();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Chess");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

