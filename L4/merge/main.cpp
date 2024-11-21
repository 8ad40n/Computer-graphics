#include <windows.h>
#include <GL/glut.h>
#include <math.h>

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


void lamppost() {
    // Bottom part of the lamppost
    glLineWidth(1);
    glColor3ub(148, 82, 37);
    glBegin(GL_POLYGON);
    glVertex2f(-25, 2.03);
    glVertex2f(-17.02, 2.03);
    glVertex2f(-17.02, 0);
    glVertex2f(-25, 0);
    glEnd();

    // Vertical pole
    glLineWidth(6);
    glColor3ub(170, 190, 215);
    glBegin(GL_LINES);
    glVertex2f(-20.95, 1.93);
    glVertex2f(-20.95, 24.97);
    glEnd();

    // Angled top part
    glLineWidth(6);
    glColor3ub(170, 190, 215);
    glBegin(GL_LINES);
    glVertex2f(-20.95, 24.97);
    glVertex2f(-32.3, 27.91);
    glEnd();

    // lamp
    glLineWidth(1);
    glColor3ub(251, 215, 5);
    glBegin(GL_POLYGON);
    glVertex2f(-31.81, 27.78);
    glVertex2f(-32.2501975237585,26.397744994307);
    glVertex2f(-28.3959714262513,25.4831828694748);
    glVertex2f(-27.99, 26.79);
    glEnd();
}

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

    // Background: light blue for above y=0
    glColor3ub(135, 206, 235);
    glBegin(GL_POLYGON);
    glVertex2f(-80, 40);
    glVertex2f(50, 40);
    glVertex2f(50, 0);
    glVertex2f(-80, 0);
    glEnd();

    // Background: green for below y=0
    glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON);
    glVertex2f(-80, 0);
    glVertex2f(50, 0);
    glVertex2f(50, -30);
    glVertex2f(-80, -30);
    glEnd();


    building();
    tree();
    lamppost();
    bench();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("All");
    gluOrtho2D(-80, 50, -30, 40);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
