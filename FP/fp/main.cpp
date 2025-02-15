#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <cmath>
#include<windows.h>
#include<cstdio>
#include <GL/gl.h>
#include <vector>
#include <cstdlib>
using namespace std;

#define PI 3.141516

bool isSnow=false;

float move_flow = 0.0f;

float man1Position=0.3f;
float man1Speed=0.008;
float man2Position=-0.4f;
float man2Speed=0.012;
float man3Position=0.8f;
float man3Speed=0.01;
float man4Position=0.9f;
float man4Speed=0.015;

float suv_car_position = 0;
float suv_car_speed=0.01;

float car_position = 0;
float car_speed=0.01;




void circle(float radius, float cX, float cY, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);
    }
}



void Wire()
{
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(-1, 0.7);
    glVertex2f(1, 0.7);
    glVertex2f(1 ,0.702);
    glVertex2f(-1, 0.702);
    glEnd();

}

void river()
{
    ///river
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.8f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();
}

void flow()
{
    float x=0.1,y=0.1;
    ///flow
    glPushMatrix();
    glTranslatef(move_flow, 0.0f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5,0.3);
    glVertex2f(0.6, 0.3);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.3-x);
    glVertex2f(0.6-x, 0.3-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x,0.3-x-x);
    glVertex2f(0.6-x-x, 0.3-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x,0.3-x-x-x+0.05);
    glVertex2f(0.6-x-x-x-2*x, 0.3-x-x-x+0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x+0.15);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.25);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.25);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x+0.35);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x+0.35);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12,0.3-x-x-x+0.15);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-0.12, 0.3-x-x-x+0.15);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x,0.3-x-x-x-0.05);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x-2*x, 0.3-x-x-x-0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x,0.3-x-x-x+0.1);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x, 0.3-x-x-x+0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x,0.3-x-x-x-0.08);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+x, 0.3-x-x-x-0.08);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x-2*x-2*x-2*x+x+2*x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x,0.3-x-x-x);
    glVertex2f(0.6-x-x-x-2*x-2*x, 0.3-x-x-x);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17,0.3);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17, 0.3);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.3+0.06);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.3+0.06);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x-x-x-2*x-2*x+0.17+2*x,0.2);
    glVertex2f(0.6-x-x-x-2*x-2*x+0.17+2*x, 0.2);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x,0.2);
    glVertex2f(0.6-x,0.2);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x,0.1);
    glVertex2f(0.6-x+2*x,0.1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x,0.1+y);
    glVertex2f(0.6-x+2*x+x,0.1+y);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.1+y+y);
    glVertex2f(0.6-x+2*x+x+x,0.1+y+y);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,0.9,0.9);
    glVertex2f(0.5-x+2*x+x+x,0.0);
    glVertex2f(0.6-x+2*x+x+x,0.0);
    glEnd();
    glPopMatrix();
}


void tree()
{
    ///tree1
    float t = 0.5;
    glScalef(1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree2
    glPushMatrix();
    glScalef(-1.5,1.50,0);
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.048f, 0.4f-t);
    glVertex2f(0.064f, 0.4f-t);
    glVertex2f(0.064f, 0.53f-t);
    glVertex2f(0.048f, 0.53f-t);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.47f-t);
    glVertex2f(0.081f,0.47f-t);
    glVertex2f(0.06f,0.68f-t);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(0.03f,0.48f-t);
    glVertex2f(0.082f,0.48f-t);
    glVertex2f(0.07f,0.64f-t);
    glEnd();

    glLoadIdentity();

    ///tree3
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(-0.6f,-0.15f);
    glVertex2f(-0.624f,-0.15f);
    glVertex2f(-0.624f,0.08f);
    glVertex2f(-0.6f,0.08f);
    glEnd();

    circle(0.04,-0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,-0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,-0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,-0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,-0.615,0.1,0.0, 0.6, 0.0);
    glEnd();

    ///tree4
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.6f,-0.15f);
    glVertex2f(0.624f,-0.15f);
    glVertex2f(0.624f,0.08f);
    glVertex2f(0.6f,0.08f);
    glEnd();

    circle(0.04,0.645,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.04,0.58,0.13,0.0,1.0,0.2);
    glEnd();
    circle(0.06,0.61,0.2,0.0,1.0,0.2);
    glEnd();

    circle(0.04,0.67,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.56,0.1,0.0, 0.6, 0.0);
    glEnd();
    circle(0.04,0.615,0.1,0.0, 0.6, 0.0);
    glEnd();


}

void human(float red, float green, float blue, float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(65, 0,1,0);
    ///shirt
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex2f(0.0f, -0.13f);
    glVertex2f(0.07f, -0.13f);

    glVertex2f(0.07f, -0.06f);
    glVertex2f(0.0f, -0.06f);
    glEnd();

    ///left hand
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.7f);

    glVertex2f(0.0f,-0.145f);
    glVertex2f(-0.015f,-0.145f);
    glVertex2f(-0.012f,-0.06f);
    glVertex2f(0.0f,-0.06f);
    glEnd();

    ///left hand sleave
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex2f(0.0f,-0.1f);
    glVertex2f(-0.015f,-0.1f);
    glVertex2f(-0.012f,-0.06f);
    glVertex2f(0.0f,-0.06f);
    glEnd();

    ///right hand
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.7f);

    glVertex2f(0.07f,-0.145f);
    glVertex2f(0.085f,-0.145f);
    glVertex2f(0.082f,-0.06f);
    glVertex2f(0.07f,-0.06f);
    glEnd();

    ///right hand sleave
    glBegin(GL_QUADS);
    glColor3f(red, green, blue);

    glVertex2f(0.07f,-0.1f);
    glVertex2f(0.085f,-0.1f);
    glVertex2f(0.082f,-0.06f);
    glVertex2f(0.07f,-0.06f);
    glEnd();

    ///leg
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f);

    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.02f, -0.2f);

    glVertex2f(0.07f, -0.13f);
    glVertex2f(0.0f, -0.13f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.6f);

    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.07f, -0.2f);

    glVertex2f(0.07f, -0.13f);
    glVertex2f(0.03f, -0.16f);
    glEnd();
    ///shoe
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.0f, -0.22f);
    glVertex2f(0.02f, -0.22f);

    glVertex2f(0.02f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.05f, -0.22f);
    glVertex2f(0.07f, -0.22f);

    glVertex2f(0.07f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glEnd();

    ///neck
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.025f, -0.06f);
    glVertex2f(0.045f, -0.06f);

    glVertex2f(0.045f, -0.04f);
    glVertex2f(0.025f, -0.04f);
    glEnd();

    ///face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.01f, -0.04f);
    glVertex2f(0.06f, -0.04f);

    glVertex2f(0.06f, 0.0f);
    glVertex2f(0.01f, 0.0f);
    glEnd();

    ///hat
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.01f, 0.0f);
    glVertex2f(0.06f, 0.0f);

    glVertex2f(0.05f, 0.03f);
    glVertex2f(0.02f, 0.03f);
    glEnd();
    glPopMatrix();
}


void suv()                                  ///OID-24
{
    float cx = 5.5;
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(suv_car_position-2.0,0,0);
    glScalef(0.14,0.14,0);
    ///car Body
    glColor3d(1,0,0);
    glBegin(GL_POLYGON);
    glColor3f(0.90,0.3,0.0);
    glVertex2f(-3.0f, 0.0-cx);
    glVertex2f(-3.0f, 0.8-cx);
    glVertex2f(-0.7f, 0.8-cx);
    glVertex2f(-0.5f, 0.55-cx);
    glVertex2f(-0.5f, 0.0-cx);
    glEnd();

    ///car UP
    glBegin(GL_QUADS);
    glColor3f(1.,1.0,1.0);
    glVertex2f(-3.0f, 0.8f-cx);
    glVertex2f(-2.7f, 1.3f-cx);
    glVertex2f(-1.7f, 1.3f-cx);
    glVertex2f(-1.35f, 0.8f-cx);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-2.9f, 0.8f-cx);
    glVertex2f(-2.6f, 1.23f-cx);
    glVertex2f(-2.15f, 1.23f-cx);
    glVertex2f(-2.15f, 0.8f-cx);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-2.05f, 0.8f-cx);
    glVertex2f(-2.05f, 1.23f-cx);
    glVertex2f(-1.75f, 1.23f-cx);
    glVertex2f(-1.45f, 0.8f-cx);
    glEnd();

    ///Wheel
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.05-cx,y-5.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.05-cx,y-5.45);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.38;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.45-cx,y-5.45);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+4.45-cx,y-5.45);
    }
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}

void car()
{
    float cy=0.3;
    glPushMatrix();
    glRotatef(-1,0,1,0);
    glTranslatef(car_position+0.5,0,0);
    glScalef(-1,1,0);
    ///police car
    glBegin(GL_QUADS);/// white car down body
    glColor3f(0.6f, 0.0f, 1.0f);
    glVertex2f(0.37f, -0.77f+cy);
    glVertex2f(0.35f, -0.89f+cy);
    glVertex2f(0.7f, -0.89f+cy);
    glVertex2f(0.69f, -0.77f+cy);
    glEnd();

    glBegin(GL_QUADS);/// black car down start line
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.34f, -0.87f+cy);
    glVertex2f(0.34f, -0.89f+cy);
    glVertex2f(0.37f, -0.89f+cy);
    glVertex2f(0.37f, -0.87f+cy);
    glEnd();

    glBegin(GL_QUADS);/// black car down end line
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.68f, -0.87f+cy);
    glVertex2f(0.68f, -0.89f+cy);
    glVertex2f(0.72f, -0.89f+cy);
    glVertex2f(0.72f, -0.87f+cy);
    glEnd();

    glBegin(GL_QUADS);   ///car middle line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.366f, -0.79f+cy);
    glVertex2f(0.363f, -0.81f+cy);
    glVertex2f(0.39f, -0.81f+cy);
    glVertex2f(0.39f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);/// blue car middle line
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, -0.79f+cy);
    glVertex2f(0.4f, -0.81f+cy);
    glVertex2f(0.66f, -0.81f+cy);
    glVertex2f(0.66f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);///red car middle line
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.67f, -0.79f+cy);
    glVertex2f(0.67f, -0.81f+cy);
    glVertex2f(0.695f, -0.81f+cy);
    glVertex2f(0.693f, -0.79f+cy);
    glEnd();

    glBegin(GL_QUADS);/// white car up body
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.46f, -0.7f+cy);
    glVertex2f(0.41f, -0.77f+cy);
    glVertex2f(0.65f, -0.77f+cy);
    glVertex2f(0.62f, -0.7f+cy);
    glEnd();

    glBegin(GL_QUADS);/// cyan car up body
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.465f, -0.715f+cy);
    glVertex2f(0.42f, -0.77f+cy);
    glVertex2f(0.52f, -0.77f+cy);
    glVertex2f(0.52f, -0.715f+cy);
    glEnd();

    glBegin(GL_QUADS);/// cyan car up body
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0.53f, -0.715f+cy);
    glVertex2f(0.53f, -0.77f+cy);
    glVertex2f(0.64f, -0.77f+cy);
    glVertex2f(0.615f, -0.715f+cy);
    glEnd();

    ///Wheel
    glScalef(0.2,0.2,0);
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-2.95);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+3.03,y-2.95);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.1,0.1,0.1);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.28;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-2.95);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3f(0.5,0.5,0.5);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=0.20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+2.23,y-2.95);
    }
    glEnd();
    glLoadIdentity();
}

float icePosition=1;
float iceSpeed=0.02;

void snow_fall()
{
    glPushMatrix();
    glTranslatef(0,icePosition, 0);
    for(float x=-0.95; x<=1; x+=0.1)
    {
        glPointSize(4.0);
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
        for(float y=-1; y<=1; y+=0.1)
        {
            glVertex2f(0.0+x, -1.0+y);
            glVertex2f(0.0+x, 0.0+y);
            glVertex2f(0.0+x, 1.0+y);
        }
        glEnd();
    }
    glPopMatrix();
}

float _move = 0.0f;
float _move2 = 0.0f;

float cloudPosition=-1.0;
float cloudSpeed=0.005;

void circle2()
{
    glBegin(GL_POLYGON);
    float xOffa = 0.744;
    float yOffa = -0.229;
    for (int i = 0; i < 500; i++)
    {
        glColor3ub(255,255,255);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = -0.054;
        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);
    }
    glEnd();
}

void circle3()
{
    glBegin(GL_POLYGON);
    float xOffa = 0.745;
    float yOffa = -0.335;
    for (int i = 0; i < 500; i++)
    {
        glColor3ub(255,255,255);
        float pi = 3.1416;
        float a = (i * 2 * pi) / 300;
        float r = -0.075;
        float x = r * cos(a) + xOffa;
        float y = r * sin(a) + yOffa;
        glVertex2f(x, y);
    }
    glEnd();
}

void sky19()                             ///OID-1
{
    ///sky
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glColor3ub(200,224,232);
    glVertex2f(1.0f, 1.0f);
    glColor3ub(255,255,255);
    glVertex2f(-1.0f, 1.0f);

    glEnd();
}

void snowsky19()                             ///OID-1
{
    ///snow sky
    glBegin(GL_QUADS);
    glColor3ub(132, 199, 227);
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    //glColor3ub(200,224,232);
    glVertex2f(1.0f, 1.0f);
    //glColor3ub(255,255,255);
    glVertex2f(-1.0f, 1.0f);

    glEnd();
}
void circle1(float p1, float q1, float r1)
{
    int i;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glVertex2f (p1,q1);
    for(i= 0; i<=tringle2; i++)
    {
        glVertex2f (
            p1+(r1*cos(i*tp2/tringle2)),
            q1+(r1*sin(i*tp2/tringle2))
        );
    }
    glEnd();
}
void cloud(float xc, float yc)
{
    glColor3f(1, 1, 1);
    circle1(xc-0.12, yc-0.05, 0.05f);
    circle1(xc-0.16, yc-0.1, 0.05f);
    circle1(xc-0.09, yc-0.1, 0.05f);
}
void Cloud()

{
    ///cloud
    glPushMatrix();
    glTranslatef(cloudPosition+0.48,0.9,0);
    cloud(-0.3,0.0);
    cloud(0.2,0.1);
    cloud(0.5,-0.05);
    glPopMatrix();
}
void update_cloud(int value)
{
    cloudPosition+=cloudSpeed;
    if(cloudPosition>1.0)
    {
        cloudPosition=-1.7;
    }

    glutPostRedisplay();
    glutTimerFunc(80, update_cloud, 0);
}


void skatingroad()                             ///OID-17
{
    glBegin(GL_QUADS);
    glColor3ub(69, 158, 20);
    glVertex2f(-1.0f, -0.5f);
    glColor3ub(40, 200, 10);
    glVertex2f(1.0f, -0.5f);
    glColor3ub(80, 160, 40);
    glVertex2f(1.0f, -0.1f);
    glColor3ub(50, 180, 30);
    glVertex2f(-1.0f, -0.1f);
    glEnd();


}
void snowSkatingroad()                             ///OID-17
{
    glBegin(GL_QUADS);
    glColor3f(209.0f / 255.0f, 227.0f / 255.0f, 255.0f / 255.0f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();


}


void road19()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-1.0f, -0.67f);
    glVertex2f(-0.80f, -0.67f);
    glVertex2f(-0.80f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.60f, -0.67f);
    glVertex2f(-0.40f, -0.67f);
    glVertex2f(-0.40f, -0.7f);
    glVertex2f(-0.60f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(-0.20f, -0.67f);
    glVertex2f(0.00f, -0.67f);
    glVertex2f(0.00f, -0.7f);
    glVertex2f(-0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);

    glVertex2f(0.20f, -0.67f);
    glVertex2f(0.40f, -0.67f);
    glVertex2f(0.40f, -0.7f);
    glVertex2f(0.20f, -0.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 1.0f, 0.3f);
    glVertex2f(0.60f, -0.67f);
    glVertex2f(0.80f, -0.67f);
    glVertex2f(0.80f, -0.7f);
    glVertex2f(0.60f, -0.7f);
    glEnd();

}

void hills()
{
    ///left1
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-1.1,0.40);
    glColor3ub(176,196,222);
    glVertex2f(-0.85,0.9);
    glColor3ub(34,139,34);
    glVertex2f(-0.70,0.40);
    glEnd();

    ///left2
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.8,0.40);
    glColor3ub(176,196,222);
    glVertex2f(-0.65,0.7);
    glColor3ub(34,139,34);
    glVertex2f(-0.50,0.40);
    glEnd();

    ///left3
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.6,0.40);
    glColor3ub(176,220,222);
    glVertex2f(-0.35,0.8);
    glColor3ub(34,200,34);
    glVertex2f(-0.20,0.40);
    glEnd();

    ///left4
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.35,0.40);
    glColor3ub(176,250,222);
    glVertex2f(-0.0,0.65);
    glColor3ub(34,240,34);
    glVertex2f(0.20,0.40);
    glEnd();

    ///left5
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.10,0.40);
    glColor3ub(176,220,222);
    glVertex2f(0.25,0.55);
    glColor3ub(34,200,34);
    glVertex2f(0.40,0.40);
    glEnd();

    ///left6
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.40,0.40);
    glColor3ub(176,210,222);
    glVertex2f(0.55,0.65);
    glColor3ub(34,200,34);
    glVertex2f(0.75,0.40);
    glEnd();

    ///left7
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.70,0.40);
    glColor3ub(176,196,222);
    glVertex2f(0.95,0.82);
    glColor3ub(34,180,34);
    glVertex2f(1.1,0.40);
    glEnd();


}
void snowhills()
{
    ///left1
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-1.1,0.40);
    glColor3ub(176,196,222);
    glVertex2f(-0.85,0.9);
    glColor3ub(34,139,34);
    glVertex2f(-0.70,0.40);
    glEnd();

    ///left2
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.8,0.40);
    glVertex2f(-0.65,0.7);
    glVertex2f(-0.50,0.40);
    glEnd();

    ///left3
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.6,0.40);
    glVertex2f(-0.35,0.8);
    glVertex2f(-0.20,0.40);
    glEnd();

    ///left3
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.35,0.40);
    glVertex2f(-0.0,0.65);
    glVertex2f(0.20,0.40);
    glEnd();

    ///left4
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.10,0.40);
    glVertex2f(0.25,0.55);
    glVertex2f(0.40,0.40);
    glEnd();

    ///left5
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.40,0.40);
    glVertex2f(0.55,0.65);
    glVertex2f(0.75,0.40);
    glEnd();

    ///left6
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.70,0.40);
    glColor3ub(176,196,222);
    glVertex2f(0.95,0.82);
    glColor3ub(34,139,34);
    glVertex2f(1.1,0.40);
    glEnd();


}


void cable()
{
     glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(-0.9696, 0.702);
    glVertex2f(-0.9596, 0.702);
    glVertex2f(-0.9584950286975, 0.644888102843);
    glVertex2f(-0.96982461821, 0.644888102843);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub		(255,255,255);
    glVertex2f(-1.0127577995204, 0.6454843970279);
    glVertex2f(-0.9233611918577, 0.6451961499495);
    glVertex2f(-0.9059953634307, 0.5929886490722);
    glVertex2f(-1.0280481778946, 0.5937889953966);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(-1.0280481778946, 0.5937889953966);
    glVertex2f(-0.9059953634307, 0.5929886490722);
    glVertex2f(-0.9208017704313, 0.5541718523411);
    glVertex2f(-1.015242636705, 0.5549721986654);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,0,0);

    glVertex2f(-0.99,0.59);
    glVertex2f (-0.997,0.64);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,0,0);
    glVertex2f(-0.935,0.59);
    glVertex2f (-0.93,0.64);

    glEnd();
}
void cable2()
{

    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(0.96, 0.702);
    glVertex2f(0.9681, 0.702);
    glVertex2f(0.9677206393564, 0.6422895175778);
    glVertex2f(0.9598433631957, 0.6430772451939);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.9117919786159, 0.6422895175778);
    glVertex2f(1.0047438373113, 0.6418956537698);
    glVertex2f(1.0189229344005, 0.5906933587257);
    glVertex2f(0.8980067453348, 0.5899056311096);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(128,0,0);
    glVertex2f(0.8980067453348, 0.5899056311096);
    glVertex2f(1.0189229344005, 0.5906933587257);
    glVertex2f(1.007105317983, 0.5492227572163);
    glVertex2f(0.9099011999664, 0.5507415715603);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,0,0);
    glVertex2f(0.9269333376212, 0.6434318867888);
    glVertex2f (0.92,0.59);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(128,0,0);
    glVertex2f(0.98,0.64);
    glVertex2f(0.99,0.590);
    glEnd();

}
void drawcable()
{
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    cable();
    glPopMatrix();
}

void drawcable2()
{
    glPushMatrix();
    glTranslatef(_move2, 0.0f, 0.0f);
    cable2();
    glPopMatrix();


}

/// cable car
void update2(int value)
{
    _move += 0.002;

    if (_move > 1.96)
    {
        _move = -1.0f;
    }
    _move2 -= 0.002;
    if(_move2 <-1.96)
    {
        _move2= +1.0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update2, 0); // Update every 20 milliseconds
}

void snowman(){



    circle2();
    circle3();
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(0.72,-0.18);
    glVertex2f(0.74,-0.15);
    glVertex2f(0.79,-0.15);
    glVertex2f(0.84,-0.18);
    glVertex2f(0.80,-0.18);
    glVertex2f(0.78,-0.19);

    glEnd();


}

void weather_update(int value)
{

    icePosition-=iceSpeed;
    if(icePosition<-1.0)
    {
        icePosition=1;
    }

    glutPostRedisplay();
    glutTimerFunc(60, weather_update, 0);
}



void updateVehicals(int value)
{

    suv_car_position+=suv_car_speed;
    if (suv_car_position>=3.5)
    {
        suv_car_position=-0.2;
    }


    car_position+=car_speed;
    if (car_position>=3.5)
    {
        car_position=-1.2;
    }


    glutPostRedisplay();
    glutTimerFunc(30, updateVehicals, 0);
}




void updateHuman(int value)
{

    man2Position+=man2Speed;
    if(man2Position>=1.0)
    {
        man2Position=-1.0;
    }
    man3Position-=man3Speed;
    if(man1Position<-1.0)
    {
        man3Position=+1.0;
    }
    man4Position-=man4Speed;
    if(man4Position<-1.0)
    {
        man4Position=+1.0;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateHuman, 0);
}


void updateFlow(int value)
{
    move_flow -=0.001;
    if (move_flow < -0.1)
    {
        move_flow = 0.001;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateFlow, 0);
}



void Display3(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    if(isSnow)
    {
        snowsky19();
        snowhills();
    }
    else{
        sky19();
        Cloud();
        hills();
    }

    river();
    flow();
    Wire();
    drawcable();
    drawcable2();

    road19();

    if(isSnow)
    {
        snowSkatingroad();
    }
    else
    {

        skatingroad();
    }
    tree();

    human(1,0,1,man1Position,0);
    human(0.5,0.2,0.6, man4Position,0);
    human(0,1,1,man2Position,0);
    human(1,0.5,0.5,man3Position,0);
    if (isSnow)
    {
        snowman();
    }

    car();
    suv();

    if(isSnow)
    {
        snow_fall();
    }

    glFlush();  /// Render now
}

void handleMouse(int button, int state, int x, int y)       ///AFID-10
{
    if (button == GLUT_LEFT_BUTTON)
    {
        suv_car_speed+=0.001;
        car_speed+=0.001;

    }
    if (button == GLUT_RIGHT_BUTTON)
    {

        suv_car_speed-=0.001;
        car_speed-=0.001;

    }
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)    ///AFID-11
{

    switch (key)
    {
    case '4':
        glutDisplayFunc(Display3);
        break;
    case 's':
        if(isSnow)
        {
            isSnow=false;
        }
        else
        {
            isSnow=true;
        }
        break;

    }
    glutPostRedisplay();
}

void myInit (void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
    //glOrtho(-300,300,-300,300,-150,500);
}


void display()
{

    Display3();

}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);

    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Snow");

    glMatrixMode(GL_PROJECTION);
    glutDisplayFunc(display);

    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(80, update_cloud, 0);
    glutTimerFunc(30, updateFlow, 0);
    glutTimerFunc(150, updateHuman, 0);
    glutTimerFunc(60, updateVehicals, 0);
    glutTimerFunc(60, weather_update, 0);
    glutTimerFunc(10, update2, 0);
    glutMainLoop();

    myInit ();

    return 0;

}

