#include <windows.h>  // for MS Windows

#include <GL/glut.h>  // GLUT, include glu.h and gl.h



/* Handler for window-repaint event. Call back when the window first appears and

whenever the window needs to be re-painted. */



void rectangle()

{
    glBegin(GL_POLYGON);

    glVertex2f(-2, 2);

    glVertex2f(2, 2);

    glVertex2f(2, 0);

    glVertex2f(-2, 0);

    glEnd();

}




void square()

{
    glBegin(GL_POLYGON);

    glVertex2f(6, 2);

    glVertex2f(10, 2);

    glVertex2f(10, -2);

    glVertex2f(6, -2);

    glEnd();

}



void display()
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(2);

    glColor3ub(255,255,255);


    glColor3ub(100,0,0);

    rectangle();

    square();

    glFlush();

}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);                 // Initialize GLUT

    glutInitWindowSize(1080, 1080);   // Set the window's initial width & height

    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title



    glutDisplayFunc(display); // Register display callback handler for window re-paint

    gluOrtho2D(-20,20,-20,20);

    glutMainLoop();           // Enter the event-processing loop

    return 0;

}

