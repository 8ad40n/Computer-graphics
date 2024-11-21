#include <windows.h>
#include <GL/glut.h>

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

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    lamppost();

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
