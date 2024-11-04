
#include <windows.h>
#include <GL/glut.h>

void line1() {
    glLineWidth(2);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-4.5814705014768f, 2.541999274203f);
    glVertex2f(-0.9232923134012f, 2.5224368239994f);
    glEnd();
}

void line2() {
    glLineWidth(2);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-2.8730165170279f,3.8135585374379f);
    glVertex2f(-2.8664957002934f,1.2378359272955f);
    glEnd();
}

void quad()
{
    glBegin(GL_QUADS);
    glVertex2f(-4.1315341467937,3.6374964856053);
    glVertex2f(-3.1925365370203,3.6440173023399);
    glVertex2f(-3.1816566745943,2.8298147054694);
    glVertex2f(-4.1445757802628,2.8354360272572);
    glEnd();
}

/* Draw the green arrow */
void arrow()
{
    glBegin(GL_QUADS);
    glVertex2f(-2.4230801623448,3.4744760672419);
    glVertex2f(-1.4658215836269,3.4700471198787);
    glVertex2f(-1.3694918834183,3.029611144913);
    glVertex2f(-2.4361217958139,3.050622979497);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.4694918834183,3.6719136084046);
    glVertex2f(-1.4548106842527,2.8350852559698);
    glVertex2f(-1.0180450090784,3.2498291323958);
    glEnd();
}

/* Draw the purple triangle */
void triangle()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.9340189072545,2.2681249713525);
    glVertex2f(-2.4296009790794,1.6225641146332);
    glVertex2f(-1.4319160186951,1.6095224811642);
    glEnd();
}

/* Draw the yellow triangle */
void triangle2()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(-3.2707863378347,2.457228656654);
    glVertex2f(-4.1315341467937,1.9486049513601);
    glVertex2f(-3.2642655211002,1.4204187958626);
    glEnd();
}


void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    line1();
    line2();

    glColor3ub(255,0,0);
    quad();

    glColor3ub(0,255,0);
    arrow();

    glColor3ub(255,255,0);
    triangle();

    glColor3ub(128,0,128);
    triangle2();


    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("");
    glutDisplayFunc(display);
    gluOrtho2D(-5, 5, -5, 5);
    glViewport(0, 0, 800, 800);

    glutMainLoop();
    return 0;
}




