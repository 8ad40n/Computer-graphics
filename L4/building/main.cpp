#include <windows.h>
#include <GL/glut.h>

void building() {
    // 1st floor
    glLineWidth(1);
    glColor3ub(200, 200, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-6.0, 6);
    glVertex2f(6.0, 6.0);
    glVertex2f(6.0, 0);
    glVertex2f(-6.0, 0.0);
    glEnd();

    // Border for the 1st floor
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-6.0, 6);
    glVertex2f(6.0, 6.0);
    glVertex2f(6.0, 0);
    glVertex2f(-6.0, 0.0);
    glEnd();

    // Door for the 1st floor
    glLineWidth(1);
    glColor3ub(200, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.0, 0);
    glVertex2f(-2.0, 4.0);
    glVertex2f(2.0, 4);
    glVertex2f(2.0, 0.0);
    glEnd();

    // Loop to draw 2nd to 5th floors
    for (int floor = 2; floor <= 5; ++floor) {
        float floorBottom = (floor - 1) * 6;
        float floorTop = floorBottom + 6;

        // Floor rectangle
        glLineWidth(1);
        glColor3ub(0, 200, 200);
        glBegin(GL_POLYGON);
        glVertex2f(-6.0, floorTop);
        glVertex2f(6.0, floorTop);
        glVertex2f(6.0, floorBottom);
        glVertex2f(-6.0, floorBottom);
        glEnd();

        // Border for the floor
        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(-6.0, floorTop);
        glVertex2f(6.0, floorTop);
        glVertex2f(6.0, floorBottom);
        glVertex2f(-6.0, floorBottom);
        glEnd();

        // Left window
        glLineWidth(1);
        glColor3ub(0, 0, 200);
        glBegin(GL_POLYGON);
        glVertex2f(-4.0, floorTop - 2.0);
        glVertex2f(-2.0, floorTop - 2.0);
        glVertex2f(-2.0, floorTop - 4.0);
        glVertex2f(-4.0, floorTop - 4.0);
        glEnd();

        // Right window
        glLineWidth(1);
        glColor3ub(0, 0, 200);
        glBegin(GL_POLYGON);
        glVertex2f(2.0, floorTop - 2.0);
        glVertex2f(4.0, floorTop - 2.0);
        glVertex2f(4.0, floorTop - 4.0);
        glVertex2f(2.0, floorTop - 4.0);
        glEnd();
    }
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    building();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("Building with Borders");
    gluOrtho2D(-30, 30, -10, 40);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
