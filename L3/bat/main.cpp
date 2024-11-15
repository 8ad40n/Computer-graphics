#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void drawLeftTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.64, 0.0);
    glVertex2f(0.58, 3.45);
    glVertex2f(0.33, 2.35);
    glEnd();
}

void drawRightTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.64, 1.81);
    glVertex2f(-0.33, 2.35);
    glVertex2f(-0.58, 3.45);
    glEnd();
}

void drawCenterRectangle() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.29, 0.96);
    glVertex2f(1.29, 0.96);
    glVertex2f(0.64, 1.81);
    glVertex2f(-0.64, 1.81);
    glEnd();
}

void drawInnerRectangle() {
    glBegin(GL_QUADS);
    glVertex2f(-0.64, 1.81);
    glVertex2f(0.64, 1.81);
    glVertex2f(0.33, 2.35);
    glVertex2f(-0.33, 2.35);
    glEnd();
}

void drawMainShape() {
    glBegin(GL_POLYGON);

    glVertex2f(-2.22, 0.85);
    glVertex2f(-2.95, 0.88);
    glVertex2f(-3.63, 0.99);
    glVertex2f(-4.42, 1.1);
    glVertex2f(-5.1, 1.33);
    glVertex2f(-5.69, 1.81);
    glVertex2f(-6.2, 2.4);
    glVertex2f(-6.46, 3.05);
    glVertex2f(-6.65, 3.67);
    glVertex2f(-19.98, 3.73);
    glVertex2f(-18.87, 3.23);
    glVertex2f(-18.07, 2.87);
    glVertex2f(-17.12, 2.29);
    glVertex2f(-16.35, 1.82);
    glVertex2f(-15.54, 1.14);
    glVertex2f(-14.76, 0.19);
    glVertex2f(-14.22, -0.76);
    glVertex2f(-14.0, -2.0);
    glVertex2f(-14.17, -3.41);
    glVertex2f(-12.99, -3.41);
    glVertex2f(-11.61, -3.34);
    glVertex2f(-10.2, -3.37);
    glVertex2f(-8.76, -3.44);
    glVertex2f(-7.68, -3.55);
    glVertex2f(-6.62, -3.87);
    glVertex2f(-5.45, -4.07);
    glVertex2f(-4.45, -4.42);
    glVertex2f(-3.53, -4.81);
    glVertex2f(-2.67, -5.25);
    glVertex2f(-1.91, -5.79);
    glVertex2f(-1.23, -6.44);
    glVertex2f(-0.69, -7.09);
    glVertex2f(-0.23, -7.77);
    glVertex2f(0.0, -8.77);  // Bottom center point
    glVertex2f(0.23, -7.77);
    glVertex2f(0.69, -7.09);
    glVertex2f(1.23, -6.44);
    glVertex2f(1.91, -5.79);
    glVertex2f(2.67, -5.25);
    glVertex2f(3.53, -4.81);
    glVertex2f(4.45, -4.42);
    glVertex2f(5.45, -4.07);
    glVertex2f(6.62, -3.87);
    glVertex2f(7.68, -3.55);
    glVertex2f(8.76, -3.44);
    glVertex2f(10.2, -3.37);
    glVertex2f(11.61, -3.34);
    glVertex2f(12.99, -3.41);
    glVertex2f(14.17, -3.41);
    glVertex2f(14.0, -2.0);
    glVertex2f(14.22, -0.76);
    glVertex2f(14.76, 0.19);
    glVertex2f(15.54, 1.14);
    glVertex2f(16.35, 1.82);
    glVertex2f(17.12, 2.29);
    glVertex2f(18.07, 2.87);
    glVertex2f(18.87, 3.23);
    glVertex2f(19.98, 3.73);
    glVertex2f(6.65, 3.67);
    glVertex2f(6.46, 3.05);
    glVertex2f(6.2, 2.4);
    glVertex2f(5.69, 1.81);
    glVertex2f(5.1, 1.33);
    glVertex2f(4.42, 1.1);
    glVertex2f(3.63, 0.99);
    glVertex2f(2.95, 0.88);
    glVertex2f(2.22, 0.85);

    glEnd();
}

void renderDisplay() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(0, 0, 0); // Set color to black
    drawLeftTriangle();
    drawRightTriangle();
    drawCenterRectangle();
    drawInnerRectangle();
    drawMainShape();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("BATMAN");

    glutDisplayFunc(renderDisplay);
    gluOrtho2D(-35, 35, -35, 35);
    glutMainLoop();
    return 0;
}
