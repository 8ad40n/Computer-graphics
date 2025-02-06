#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<cstdio>
#include <GL/gl.h>
#include<math.h>
#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <MMSystem.h>
#define PI 3.141516
using namespace std;

int displayNo=1;




// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************

//positions of the car, bus, plane and train.
static float    cm=  -300.0; //for car
static float    bm=  400.0;  //for bus
static float    pm=  300.0; // for plane
static float    tm=  300.0; // for Train

//***************************Day View ***************************************//

void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y) // for sun, hill
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0; i<=360; i++)
    {
        rad = i*(3.1416/180);
        glVertex2f(x+rx*cos(rad),y+ry*sin(rad));
    }
    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslated(-210,260,0); // sun position
    glColor3f(1.0, 0.76, 0.3); // sun color
    circle(20,40,0,0); // sun shape
    glPopMatrix();
}

void hill()
{
    glColor3f(0.5, 0.87, 1.0);
    circle(70,120,-250,90);
    circle(70,120,-100,90);
    circle(70,120,50,100);
    circle(70,120,200,90);
}

void rectangle(int x, int y, int x1, int y1)
{
    // glVertex2d()-> avoid z coordinates.rendiring shapes in 2d

    glBegin(GL_QUADS);
    glVertex2d(x,y);  // One corner of the rectangle.
    glVertex2d(x,y1); // Corner directly above or below (x, y), aligned vertically.
    glVertex2d(x1,y1); // Opposite corner of (x, y).
    glVertex2d(x1,y); // Corner directly to the right or left of (x, y), aligned horizontally.
    glEnd();

    // soil, ground
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    // x,y
    // x1,y
    // x2, y1
    glBegin(GL_POLYGON);
    glVertex2d(x,y);
    glVertex2d(x1,y);

    glVertex2d(x1,y);
    glVertex2d(x2,y1);

    glVertex2d(x2,y1);
    glVertex2d(x,y);
    glEnd();
}

void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
    glVertex2d(x1,y1);
    glVertex2d(x3,y3);
    glVertex2d(x4,y4);
    glVertex2d(x2,y2);
    glEnd();
}

void soil()
{
    glColor3f(0.75, 0.75, 0.75);
    rectangle(-300,-10,300,130);
}

void ground()
{
    glColor3f(0.72, 0.56, 0.26);  //Bottom part
    rectangle(-300,-300,300,-10);  //(x,y,x1,y1)-->(x,y),(x,y1),(x1,y1),(x1,y)
}

void roadN()
{
    //roadN Area
    glColor3f(0.3, 0.3, 0.3);
    rectangle(-300,-200,300,-30);
    //roadN side broadNer up
    glColor3f(0.0, 0.0, 0.0);
    rectangle(-300,-30,300,-33);
    //roadN side broadNer down
    glColor3f(0.0, 0.0, 0.0);
    rectangle(-300,-205,300,-200);
    //divider 1st
    glColor3f(1.0, 1.0, 1.0);
    rectangle(-270,-120,-230,-110);
    //divider 2nd
    glColor3f(1.0, 1.0, 1.0);
    rectangle(-150,-120,0,-110);
    //divider  3rd
    glColor3f(1.0, 1.0, 1.0);
    rectangle(50,-120,150,-110);
    //divider  4th
    glColor3f(1.0, 1.0, 1.0);
    rectangle(200,-120,290,-110);
}

void treeN(int a,int b,int c,int d, int e,int f,int g, int h, int i)
{
    glColor3f(0.0, 0.0, 0.0);
    rectangle(a,b,c,d);
    glColor3f(0.0, 0.5, 0.0);
    triangle(e,f,g,h,i);

}

void treeN1()
{
    treeN(-270,110,-268,140,-275,140,-263,-269,170);
    treeN(-240,110,-238,140,-245,140,-233,-239,170);
    treeN(-200,110,-202,140,-195,140,-205,-200,170);
    treeN(-150,110,-148,140,-155,140,-143,-149,170);
    treeN(-120,110,-118,140,-125,140,-113,-119,170);
    treeN(-90,110,-88,140,-95,140,-83,-89,170);
    treeN(-60,110,-58,140,-65,140,-53,-59,170);
    treeN(-30,110,-28,140,-35,140,-23,-29,170);
    treeN(0,110,2,140,-5,140,7,1,170);
    treeN(30,110,32,140,25,140,37,31,170);
    treeN(60,110,62,140,55,140,67,61,170);
    treeN(90,110,92,140,85,140,97,91,170);
    treeN(120,110,122,140,115,140,127,121,170);
    treeN(150,110,152,140,145,140,157,151,170);
    treeN(180,110,182,140,175,140,187,181,170);
    treeN(210,110,212,140,205,140,217,211,170);
    treeN(240,110,242,140,235,140,247,241,170);
    treeN(270,110,272,140,265,140,277,271,170);
}

void make_treeN2()
{
    glColor3f(0.0, 0.8, 0.0);
    circle(20,30,0,0);
    circle(20,30,20,0);
    circle(20,30,40,0);
    circle(20,30,30,30);    //Bigger part of the treeN
    circle(20,30,10,30);
    circle(20,30,10,-30);
    circle(20,30,30,-30);


    circle(10,20,50,-70);
    circle(10,20,60,-60);   //Small part of treeN
    circle(10,20,60,-80);

    glColor3f(0.75, 0.25,0.12);
    rectangle1(10,-130,30,-130,10,-30,30,-30);
    rectangle1(10,-30,17,-30,5,0,5,0);
    rectangle1(17,-30,22,-30,19,0,19,0);
    rectangle1(22,-30,30,-30,35,0,35,0);
    rectangle1(30,-90,30,-100,55,-70,55,-75);

}

void treeN2()
{
    //1st big treeN
    glPushMatrix();
    glTranslated(-320,120,0);
    make_treeN2();
    glPopMatrix();

    // 2nd big treeN
    glPushMatrix();
    glTranslated(100,120,0);
    make_treeN2();
    glPopMatrix();

    //3rd big treeN
    glPushMatrix();
    glTranslated(270,120,0);
    make_treeN2();
    glPopMatrix();

}

void college()
{
    glColor3f(0.73, 0.94, 0.32); //Front Show
    rectangle(-100,-9,60,120);
    glColor3f(0.96, 0.96, 0.37); //Top
    rectangle1(-100,120,60,120,-90,140,70,140);
    glColor3f(0.4, 1.0, 1.0); //Side show
    rectangle1(60,-9,70,0,60,120,70,140);

    glColor3f(0, 0, 0); //Windows
    rectangle(-90,100,-70,80);
    rectangle(-60,100,-40,80);
    rectangle(-35,-9,-5,30); //door
    rectangle(-30,100,-10,80);
    rectangle(0,100,20,80);
    rectangle(30,100,50,80);

    rectangle(-90,70,-70,50);
    rectangle(-60,70,-40,50);
    rectangle(-30,70,-10,50);
    rectangle(0,70,20,50);
    rectangle(30,70,50,50);
}

void hospital()
{
    glColor3f(0.97, 0.28, 0.09);  //Front show
    rectangle(-210,-9,-120,150);
    glColor3f(0.92, 0.49, 0.06); //Top
    rectangle1(-210,150,-120,150,-190,170,-110,170);
    glColor3f(0.09, 0.47, 0.89); // Side
    rectangle1(-120,-9,-110,0,-120,150,-110,170);


    glColor3f(1, 0.31, 1);  //window
    rectangle(-170,-9,-155,10); // hospital gate...

    rectangle(-140,130,-125,110);  //Right top
    rectangle(-140,100,-125,80);
    rectangle(-140,70,-125,50);
    rectangle(-140,40,-125,20);

    rectangle(-160,130,-145,110);
    rectangle(-160,100,-145,80);
    rectangle(-160,70,-145,50);
    rectangle(-160,40,-145,20);

    rectangle(-180,130,-165,110);
    rectangle(-180,100,-165,80);
    rectangle(-180,70,-165,50);
    rectangle(-180,40,-165,20);

    rectangle(-200,130,-185,110); //Left top
    rectangle(-200,100,-185,80);
    rectangle(-200,70,-185,50);
    rectangle(-200,40,-185,20);
}

void house()
{
    glColor3f(0.77, 1.0, 0.77); //Front Show
    rectangle1(200,-9,350,-9,200,80,350,80);
    rectangle1(200,80,250,80,200,120,250,120);

    glColor3f(0.0f, 0.1f, 0.0f); //Top
    triangle(195,120,255,225,150);


    glColor3f(0.97, 0.65, 0.14); //Window small one
    rectangle1(215,95,235,95,215,115,235,115);

    glColor3f(0., 0.1, 0.1); //Door
    rectangle1(220,-9,250,-9,220,40,250,40);

}

void makePrivateCar()
{

    glColor3f(1.0, 0.0, 0.0);
    circle(5,15,0,0);        // back circle
    rectangle(0,-15,60,15);  //Middle part


    glColor3f(0.2, 0.47, 1.0);
    triangle(5,15,20,20,45);
    triangle(40,15,60,40,45);


    glColor3f(0, 0, 0);
    rectangle(20,15,40,45);  //sunroof

    glColor3f(1.0, 0.0, 0.0);
    circle(5,10,80,-5);        //front circle

    glColor3f(1.0, 0.0, 0.0);
    rectangle1(60,-15,80,-15,60,15,80,5);  //front part

    glColor3f(0, 0, 0);
    circle(7,14,10,-15);
    circle(7,14,60,-15);      //tire

    glColor3f(1.0, 1.0, 1.0);
    circle(6,12,10,-15);      //tire border
    circle(6,12,60,-15);


}

void privatecarMove()
{
// cm= -300 (-x to x)
    cm=cm+.5;
    if(cm>330)
        cm = -350;
    glutPostRedisplay();
}

void privatecar()
{

    glPushMatrix();
    glTranslatef(cm,-50,0);
    makePrivateCar();
    glPopMatrix();

    privatecarMove();
}

void busmake()
{
    glColor3f(0.9, 0.72, 0.0);
    rectangle(-60,-15,0,15);
    rectangle(-80,-15,-60,25);
    glColor3f(0, 0, 0);
    rectangle(-60,15,-2,50);
    rectangle(-70,25,-60,50);
    glColor3f(0.76, 0.84, 0.84);
    rectangle1(-2,50,-70,50,-7,55,-76,55);

    glColor3f(0.2, 0.8, 1.0);
    rectangle1(-70,25,-74,25,-70,50,-76,55);


    glColor3f(1, 1, 1.0);
    rectangle(-58,0,-50,35);     //door
    glColor3f(0.2, 0.8, 1.0);
    rectangle(-45,30,-40,40);    //four windows serially
    rectangle(-35,30,-30,40);
    rectangle(-25,30,-20,40);
    rectangle(-15,30,-10,40);


    glColor3f(0.9, 0.72, 0.0);
    circle(3,15,0,0);           //back part
    circle(3,20,-80,5);         // front part

    glColor3f(0, 0, 0);           //tire border
    circle(8,16,-10,-15);
    circle(8,16,-70,-15);

    glColor3f(1, 1, 1);             //tire
    circle(6,12,-10,-15);
    circle(6,12,-70,-15);

}

void busMove()
{
    //bm= 400 (x to -x)
    bm=bm-.4;
    if(bm<-350)
        bm = 350;

    glutPostRedisplay();
}

void bus()
{
    glPushMatrix();
    glTranslatef(bm,-165,0);
    busmake();
    glPopMatrix();
    // busMove();

}

void railLine()
{
    glColor3f(0,0,0);
    rectangle(-300,-230,300,-225);
    rectangle(-300,-260,300,-265);
    int i = 0;

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    for(i=-305; i<=300; i=i+30)
    {

        glVertex2d(i,-260);
        glVertex2d(i+5,-260);
        glVertex2d(i+20,-225);
        glVertex2d(i+25,-225);
    }
    glEnd();
}

void makerail()
{
    glColor3f(1, 0, 0);
    circle(8,15,-70,-2);
    circle(8,15,-53,-2);

    circle(8,15,-20,-2);
    circle(8,15,-3,-2);

    circle(8,15,30,-2);
    circle(8,15,47,-2);

    circle(8,15,75,-2);
    circle(8,15,93,-2);

    rectangle(-70,0,-70,2);


    glColor3f(1, 1, 1);
    rectangle(-70,0,100,60);
    glColor3f(0.4, 0.4, 0.4);
    rectangle1(-100,0,-70,0,-100,20,-70,60);
    glColor3f(0.75, 0.75, 0.75);
    rectangle1(-70,60,100,60,-75,70,105,70);
    glColor3f(1.0, 1.0, 0.7);
    rectangle1(100,0,104,10,100,60,105,70);
    glColor3f(0.6, 0.87, 1.0);
    rectangle1(-100,20,-70,60,-95,35,-75,70);
    glColor3f(0.4, 0.4, 0.4);
    circle(12,15,-97,15);      //Front part


    glColor3f(0, 1, 1);
    rectangle(-60,10,-50,50);
    rectangle(-45,30,-35,50);
    rectangle(-30,30,-20,50);
    rectangle(-15,30,-5,50);

    rectangle(0,10,10,50);
    rectangle(15,30,25,50);
    rectangle(30,30,40,50);
    rectangle(45,30,55,50);

    rectangle(60,10,70,50);
    rectangle(75,30,85,50);
    rectangle(90,30,99,50);
    rectangle(-70,0,-70,2);
}

void trainMove()
{
    // tm=300 (x to -x)
    tm=tm-1;
    if(tm<-350)
        tm = 350;
    glutPostRedisplay();
}

void train()
{
    trainMove();
    glPushMatrix();
    glTranslatef(tm,-245,0);
    makerail();
    glPopMatrix();
}

//***************************Night View ***************************************//
void make_plane()
{
    glColor3f(0.0, 1.0, 0.0);
    circle(20,15,0,0);
    rectangle(0,-15,70,15);     //main body
    glColor3f(0.0, 1.0, 0.0);
    rectangle1(70,-15,90,35,70,15,90,40);  //backpart
    glColor3f(0.0, 1.0, 0.0);
    rectangle1(30,15,50,15,60,35,55,30);   //middle wing


glColor3f(1.0, 1.0, 1.0);
circle(5,5,10,0);
circle(5,5,30,0);
circle(5,5,50,0);
circle(5,5,65,0);
rectangle(-5,-5,0,10);


}

void planeMove(){
pm=pm-.5;
    if(pm<-500)
        pm = 300;
        glutPostRedisplay();
}

void plane()
{
     planeMove();
     glPushMatrix();
     glTranslatef(pm,250,0);
     make_plane();
     glPopMatrix();


}
void moon(){
    glPushMatrix();
    // Move the moon to a position beside the sun
    glTranslated(-160, 260, 0);

    // Draw the larger outer circle (moon body)
    glColor3f(1.0, 1.0, 1.0);  // white for the moon
    circle(15, 30, 0, 0);  // Large circle

    // Draw a smaller inner circle (to create the crescent effect)
    glColor3f(0.0, 0.0, 0.5);  // Use a dark blue color to simulate the background
    circle(15, 30, 5, 5);  // Smaller circle slightly offset

    glPopMatrix();

}
void sky(){
    glColor3f(0.0, 0.0, 0.5);
    rectangle(-300,130,300,300);
    glutPostRedisplay();

}
void hill_n(){
    glColor3f(0.28, 0.59, 0.70);
    circle(70,120,-250,90);
    circle(70,120,-100,90);
    circle(70,120,50,100);
    circle(70,120,200,90);
}
void soil_n(){
    glColor3f(0.31, 0.47, 0.67);
    rectangle(-300,-10,300,130);
}
void ground_n(){
     glColor3f(0.58, 0.52, 0.05);  //Bottom part
     rectangle(-300,-300,300,-10);  //(x,y,x1,y1)-->(x,y),(x,y1),(x1,y1),(x1,y)
}
void make_treeN2_n(){
    //glColor3f(0.38, 0.61, 0.37);
    glColor3f(0.0, 0.5, 0.0);
    circle(20,30,0,0);
    circle(20,30,20,0);
    circle(20,30,40,0);
    circle(20,30,30,30);    //Bigger part of the treeN
    circle(20,30,10,30);
    circle(20,30,10,-30);
    circle(20,30,30,-30);


    circle(10,20,50,-70);
    circle(10,20,60,-60);   //Small part of treeN
    circle(10,20,60,-80);

    glColor3f(0.64, 0.49,0.34);
    rectangle1(10,-130,30,-130,10,-30,30,-30);
    rectangle1(10,-30,17,-30,5,0,5,0);
    rectangle1(17,-30,22,-30,19,0,19,0);
    rectangle1(22,-30,30,-30,35,0,35,0);
    rectangle1(30,-90,30,-100,55,-70,55,-75);

}
void treeN2_n(){

    glPushMatrix();
    glTranslated(-320,120,0);
    make_treeN2_n();
    glPopMatrix();


    glPushMatrix();
    glTranslated(100,120,0);
    make_treeN2_n();
    glPopMatrix();

    glPushMatrix();
    glTranslated(270,120,0);
    make_treeN2_n();
    glPopMatrix();

}
void college1_n(){
    glColor3f(0.65, 0.28, 0.09);  //Front show
    rectangle(-210,-9,-120,150);
    glColor3f(0.81, 0.55, 0.05); //Top
    rectangle1(-210,150,-120,150,-190,170,-110,170);
    glColor3f(0.03, 0.38, 0.62); // Side
    rectangle1(-120,-9,-110,0,-120,150,-110,170);


        glColor3f(0.77, 1.0, 0.77);
        rectangle(-170,-9,-155,10);

        rectangle(-140,130,-125,110);  //Right top
        rectangle(-140,100,-125,80);
        rectangle(-140,70,-125,50);
        rectangle(-140,40,-125,20);

        rectangle(-160,130,-145,110);
        rectangle(-160,100,-145,80);
        rectangle(-160,70,-145,50);
        rectangle(-160,40,-145,20);

        rectangle(-180,130,-165,110);
        rectangle(-180,100,-165,80);
        rectangle(-180,70,-165,50);
        rectangle(-180,40,-165,20);

        rectangle(-200,130,-185,110); //Left top
        rectangle(-200,100,-185,80);
        rectangle(-200,70,-185,50);
        rectangle(-200,40,-185,20);
}
void college_n(){
    glColor3f(0.61, 0.61, 0.61); //Front show
    rectangle(-100,-9,60,120);
    glColor3f(0.73, 0.73, 0.04); //Top
    rectangle1(-100,120,60,120,-90,140,70,140);//top
    glColor3f(0.04, 0.53, 0.54); //side
    rectangle1(60,-9,70,0,60,120,70,140);

        glColor3f(0.77, 1.0, 0.77); //windows
        rectangle(-90,100,-70,80);
        rectangle(-60,100,-40,80);
        rectangle(-35,-9,-5,30);
        rectangle(-30,100,-10,80);
        rectangle(0,100,20,80);
        rectangle(30,100,50,80);

        rectangle(-90,70,-70,50);
        rectangle(-60,70,-40,50);
        rectangle(-30,70,-10,50);
        rectangle(0,70,20,50);
        rectangle(30,70,50,50);
}
void house_n(){
    glColor3f(0.1f, 0.1f, 1.0f); //Front Show
    rectangle1(200,-9,350,-9,200,80,350,80);
    rectangle1(200,80,250,80,200,120,250,120);
    glColor3f(0.0f, 0.1f, 0.0f); //Top triangle
    triangle(195,120,255,225,150);


    glColor3f(0.77, 1.0, 0.77); //Window
    rectangle1(215,95,235,95,215,115,235,115);

    glColor3f(0.77, 1.0, 0.77); //Door
    rectangle1(220,-9,250,-9,220,40,250,40);

}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
    hill();
    soil();
    ground();
    roadN();
    treeN1(); // 18 small treeN
    treeN2(); // 3 big treeN
    college();
    hospital();
    house();
    privatecar();
    bus();
    railLine();
    train();
    glFlush();
}
void night()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    moon();
    hill_n();
    soil_n();
    ground_n();
    roadN();
    treeN1();
    treeN2_n();
    college_n();
    college1_n();
    house_n();
    bus();
    plane();
    railLine();
    glFlush();
}


void init()
{
    glClearColor(0.3, .65, 1, 1.0);  //light blue

}

// Mouse Functionality........
void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
        exit(0);
}
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************
// *****************************************************  NADIM  ************************************************



















// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************

bool isSnow=false;


int triangleAmount = 500;
float twicePi = 2.0f * PI;
float angle1=0.0;
float angle2=120.0;
float angle3=240.0;

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

void river()                              ///OID-9
{
    ///river
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.8f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(-1.0f, 0.4f);
    glEnd();

    ///bank river
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-1.0,0.4);
    glVertex2f(1.0, 0.4);
    glEnd();
}

void flow()                                  ///OID-10
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


void tree()                                 ///OID-18
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

void human(float red, float green, float blue, float x, float y)    ///OID-21
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
void Cloud()                          ///OID-3
{
    ///cloud
    glPushMatrix();
    glTranslatef(cloudPosition+0.48,0.9,0);
    cloud(-0.3,0.0);
    cloud(0.2,0.1);
    cloud(0.5,-0.05);
    glPopMatrix();
}
void update_cloud(int value)        ///AFID-1
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


void road19()                             ///OID-16
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.60f, -0.35f);
    glVertex2f(-0.40f, -0.35f);
    glVertex2f(-0.40f, -0.3f);
    glVertex2f(-0.60f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.20f, -0.35f);
    glVertex2f(0.00f, -0.35f);
    glVertex2f(0.00f, -0.3f);
    glVertex2f(-0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.20f, -0.35f);
    glVertex2f(0.40f, -0.35f);
    glVertex2f(0.40f, -0.3f);
    glVertex2f(0.20f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(0.60f, -0.35f);
    glVertex2f(0.80f, -0.35f);
    glVertex2f(0.80f, -0.3f);
    glVertex2f(0.60f, -0.3f);
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

void hills()                              ///OID-4
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

    ///left3
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(-0.35,0.40);
    glColor3ub(176,250,222);
    glVertex2f(-0.0,0.65);
    glColor3ub(34,240,34);
    glVertex2f(0.20,0.40);
    glEnd();

    ///left4
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.10,0.40);
    glColor3ub(176,220,222);
    glVertex2f(0.25,0.55);
    glColor3ub(34,200,34);
    glVertex2f(0.40,0.40);
    glEnd();

    ///left5
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.40,0.40);
    glColor3ub(176,210,222);
    glVertex2f(0.55,0.65);
    glColor3ub(34,200,34);
    glVertex2f(0.75,0.40);
    glEnd();

    ///left6
    glBegin(GL_TRIANGLES);
    glColor3ub(200,224,232);
    glVertex2f(0.70,0.40);
    glColor3ub(176,196,222);
    glVertex2f(0.95,0.82);
    glColor3ub(34,180,34);
    glVertex2f(1.1,0.40);
    glEnd();


}
void snowhills()                              ///OID-4
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

void weather_update(int value)          ///AFID-9
{

    icePosition-=iceSpeed;
    if(icePosition<-1.0)
    {
        icePosition=1;
    }

    glutPostRedisplay();
    glutTimerFunc(60, weather_update, 0);
}



void updateVehicals(int value)                  ///AFID-7
{

    if (suv_car_position>=3.5)
    {
        suv_car_position=-0.2;
    }
    suv_car_position+=suv_car_speed;

    if (car_position>=3.5)
    {
        car_position=-1.2;
    }
    car_position+=car_speed;

    glutPostRedisplay();
    glutTimerFunc(30, updateVehicals, 0);
}




void updateHuman(int value)                 ///AFID-6
{

    man2Position+=man2Speed;
    if(man2Position>1.0)
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


void updateFlow(int value)                      ///AFID-5
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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /// Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);       /// Clear the color buffer (background)

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
    if(isSnow)
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

void myInit (void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
    //glOrtho(-300,300,-300,300,-150,500);
}
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************
// *****************************************************  BADHON  ************************************************























// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************
GLfloat position = 0.0;
GLfloat speed = 0.8;
GLfloat position1 = 0.0;
GLfloat position2 = 0.0;
GLfloat position4 = 0.0;
GLfloat position5 = 0.0;
GLfloat position6 = 0.0;
GLfloat speed1 = 0.4;
GLfloat speed2 = 0.3;
GLfloat speed3 = 0.8;
GLfloat speed9 = 1.2;
GLfloat _rain = 0.0;
GLfloat _night_R = 0.0;
GLfloat _morning = 0.0;

GLfloat bird_y = 14.0f;



GLfloat rainday = false;
GLfloat night_R = false;
GLfloat day_rain = false;


void trainR(int value)
{
    if(position > 10.0)
        position = -20.0;
        position += speed;
        glutPostRedisplay();
        glutTimerFunc(100, trainR, 1);
}
void cloudR1(int value)
{
    if(position1 > 25.0)
        position1 = -20.0;
        position1 += speed1;
        glutPostRedisplay();
        glutTimerFunc(100, cloudR1, 1);
}
void cloudR2(int value){
    if(position2 > 32.0)
        position2 = -10.0;
        position2 += speed2;
        glutPostRedisplay();
        glutTimerFunc(100, cloudR2, 1);
}


void caru(int value)
{
    if(position4 > 10)
        position4 = -30.0;
        position4 += speed3;
        glutPostRedisplay();
        glutTimerFunc(100, caru, 1);
}

void card(int value)
{
    if(position5 > 30)
        position5 = -20.0;
        position5 += speed3;
        glutPostRedisplay();
        glutTimerFunc(100, card, 1);
}

void bird(int value) {
    if (position6 > 30) {
        position6 = -9.0;
    }
    position6 += speed9;
    glutPostRedisplay();
    glutTimerFunc(100, bird, 1);

    // compute the current time
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

    // update the bird's y position
    bird_y += 0.1f * sin(time);
}



void sunR(bool sunRny){

        ///Conditions for sunR

        if(!night_R && !rainday){
            glPushMatrix();
            glTranslatef(7.0f, 15.0f, 0.0f);
            GLfloat radius = 2.0f;
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f, 0.6f, 0.2f);
            glVertex2f(0.0f, 0.0f);
            int num_segments = 100;
                for (int i = 0; i <= num_segments; i++) {
                    GLfloat theta = i * twicePi / num_segments;
                    GLfloat x = radius * cos(theta);
                    GLfloat y = radius * sin(theta);
                    glColor3f(1.0f, 0.8f - 0.6f * y / radius, 0.2f - 0.2f * y / radius);
                    glVertex2f(x, y);
                }
            glEnd();

            glPopMatrix();
        }
}


void moon(bool moony){

///Condition for moon

    if(night_R && !rainday){
        glPushMatrix();
        glTranslatef(7.0f, 15.0f, 0.0f);
        GLfloat radius = 2.0f;
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(220,220,220);
        glVertex2f(0.0f, 0.0f);
        int num_segments = 100;
        for (int i = 0; i <= num_segments; i++) {
            GLfloat theta = i * twicePi / num_segments;
            GLfloat x = radius * cos(theta);
            GLfloat y = radius * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();
    }

}


void wheel(int x, int y)
{
    float theta;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.0);
    for(int i=0; i<360; i++)
    {
        theta = i*PI/180;
        glVertex2f(x+0.02*6*cos(theta),y+0.02*6*sin(theta));
    }
    glEnd();
}

void myCars(float l, float r,float b, float t, int rr1, int gg1, int bb1, int rr2, int gg2, int bb2)
{

    float car_left = l;
    float car_right = r;
    float car_bottom = b;
    float car_top = t;

    glBegin(GL_POLYGON);
    glColor3ub(255, 239, 213);
    glVertex2f(car_left, car_bottom);
    glVertex2f(car_right, car_bottom);
    glVertex2f(car_right, car_top);
    glVertex2f(car_left, car_top);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
    glVertex2f(car_left + 0.15, car_top);
    glVertex2f(car_right - 0.15, car_top);
    glVertex2f(car_right - 0.25, car_top + 0.25);
    glVertex2f(car_left + 0.25, car_top + 0.25);
    glEnd();

    //wheels
    wheel(car_left+1.2, car_bottom);
    wheel(car_right-0.4, car_bottom);
}



/// Drawing Birds
void bird2(float x, float y, bool bol, float time) {
    if(bol){

    glColor3f(0.0f, 0.0f, 0.0f);

    // compute the bird's y position based on a sine wave
    y = y - 2.5f * sin(time);

    // draw the body
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+0.5, y+0.5);
    glVertex2f(x, y+0.20);
    glVertex2f(x-0.5, y+0.5);
    glEnd();
    }


}




/// Function Day
void Morning(int _mor){

    glClearColor (0.77, 0.95, 1.00, 1.0);
    sunR(true);

    if(!night_R && !rainday){
        glPushMatrix();
        glTranslatef(position6, 0.0f, 0.0f);
        bird2(9.0, 14.0, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird2(8.8, 15.3, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird2(7.7, 15.9, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird2(7.5, 14.0, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird2(8.3, 15.6, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird2(7.2, 15.2, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird2(8.5, 14.2, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        glPopMatrix();
    }

}

void display1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    /// cloudRs

    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);

    float theta;

    //c1
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(10+1*cos(theta),15+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(12.5+1.2*cos(theta),16+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(11+1.5*cos(theta),16+1.5*sin(theta));
    }
    glEnd();

    //c
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(18+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(20.5+1.2*cos(theta),11+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(19+1.5*cos(theta),11+1.5*sin(theta));
    }
    glEnd();
    glPopMatrix();

    //c1c
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(-2+1*cos(theta),15+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(0.5+1.2*cos(theta),16+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(-1+1.5*cos(theta),16+1.5*sin(theta));
    }
    glEnd();

    //c
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(14+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(15.5+1.8*cos(theta),11+1.2*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(15+1.2*cos(theta),11+1.5*sin(theta));
    }
    glEnd();
    //c3
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(5+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6.5+.6*cos(theta),11+.5*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6+.7*cos(theta),11+.7*sin(theta));
    }
    glEnd();

    glPopMatrix();


    ///Buildings
	glBegin(GL_QUADS);

    glColor3f (0, 0, 0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f);
	glVertex3f(5.0, 3.0, 0.0);
	glVertex3f(6.0, 3.0, 0.0);
	glVertex3f(6.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(6.0, 0.0, 0.0);
	glVertex3f(6.0, 8.0, 0.0);
	glVertex3f(11.0, 8.0, 0.0);
    glVertex3f(11.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(11.0, 0.0, 0.0);
	glVertex3f(11.0, 4.5, 0.0);
	glVertex3f(12.0, 4.5, 0.0);
    glVertex3f(12.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(12.0, 0.0, 0.0);
	glVertex3f(12.0, 6.0, 0.0);
	glVertex3f(16.0, 6.0, 0.0);
    glVertex3f(16.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //greenish blue
	glVertex3f(16.0, 0.0, 0.0);
	glVertex3f(16.0, 3.5, 0.0);
	glVertex3f(17.0, 3.5, 0.0);
    glVertex3f(17.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(17.0, 0.0, 0.0);
	glVertex3f(17.0, 7.0, 0.0);
	glVertex3f(21.0, 7.0, 0.0);
    glVertex3f(21.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(21.0, 0.0, 0.0);
	glVertex3f(21.0, 5.75, 0.0);
	glVertex3f(24.0, 5.75, 0.0);
    glVertex3f(24.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(22.0, 0.0, 0.0);
	glVertex3f(22.0, 5.0, 0.0);
	glVertex3f(26.0, 5.0, 0.0);
    glVertex3f(26.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(26.0, 0.0, 0.0);
	glVertex3f(26.0, 3.25, 0.0);
	glVertex3f(27.0, 3.25, 0.0);
    glVertex3f(27.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(27.0, 0.0, 0.0);
	glVertex3f(27.0, 8.0, 0.0);
	glVertex3f(31.0, 8.0, 0.0);
    glVertex3f(31.0, 0.0, 0.0);

    // Back Building
    glColor3f(0.0f, 0.5f, 0.5f);
	glVertex3f(31.0, 0.0, 0.0);
	glVertex3f(31.0, 6, 0.0);
	glVertex3f(32.0, 6, 0.0);
    glVertex3f(32.0, 0.0, 0.0);


    // Metro Pillar
    glColor3f (0.329, 0.329, 0.329);
	glVertex3f(24.5, 5.0, 0.0);
	glVertex3f(24.5, 7.0, 0.0);
	glVertex3f(25.5, 7.0, 0.0);
    glVertex3f(25.5, 5.0, 0.0);

    glVertex3f(24, 7.0, 0.0);
	glVertex3f(24, 8.0, 0.0);
	glVertex3f(26, 8.0, 0.0);
    glVertex3f(26, 7.0, 0.0);

    glVertex3f(26, 7.0, 0.0);
	glVertex3f(26, 8.0, 0.0);
	glVertex3f(27, 9.0, 0.0);
    glVertex3f(28, 9.0, 0.0);

    glVertex3f(24, 7.0, 0.0);
	glVertex3f(24, 8.0, 0.0);
	glVertex3f(23, 9.0, 0.0);
    glVertex3f(22, 9.0, 0.0);

    glVertex3f(3.5, 5.0, 0.0);
	glVertex3f(3.5, 7.0, 0.0);
	glVertex3f(4.5, 7.0, 0.0);
    glVertex3f(4.5, 5.0, 0.0);

    glVertex3f(3, 7.0, 0.0);
	glVertex3f(3, 8.0, 0.0);
	glVertex3f(5, 8.0, 0.0);
    glVertex3f(5, 7.0, 0.0);

    glVertex3f(5, 7.0, 0.0);
	glVertex3f(5, 8.0, 0.0);
	glVertex3f(6, 9.0, 0.0);
    glVertex3f(7, 9.0, 0.0);

    glVertex3f(3, 7.0, 0.0);
	glVertex3f(3, 8.0, 0.0);
	glVertex3f(2, 9.0, 0.0);
    glVertex3f(1, 9.0, 0.0);

    glVertex3f(0, 9.0, 0.0);
	glVertex3f(0, 9.25, 0.0);
	glVertex3f(32, 9.25, 0.0);
    glVertex3f(32, 9.0, 0.0);

    glVertex3f(0, 11.75, 0.0);
	glVertex3f(0, 11.85, 0.0);
	glVertex3f(32, 11.85, 0.0);
    glVertex3f(32, 11.75, 0.0);



    glEnd();
    // buildings end


    /// Metro Rail
    glPushMatrix();
    glTranslatef(-position,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
	glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(20, 9.25, 0.0);
	glVertex3f(20, 11, 0.0);
    glVertex3f(11.75, 11, 0.0);

    glColor3f (1, 0, 0);
	glVertex3f(14, 9.25, 0.0);
	glVertex3f(16, 9.25, 0.0);
	glVertex3f(16, 11, 0.0);
    glVertex3f(14.75, 11, 0.0);

    glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(11, 9.5, 0.0);
	glVertex3f(11,10.25 , 0.0);
    glVertex3f(11.75, 11, 0.0);

    glVertex3f(20, 9.25, 0.0);
	glVertex3f(20.25, 9.5, 0.0);
	glVertex3f(20.25,10.75 , 0.0);
    glVertex3f(20, 11, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(11.25, 9.5, 0.0);
	glVertex3f(12.75, 9.5, 0.0);
	glVertex3f(12.75, 9.75, 0.0);
    glVertex3f(11.25, 9.75, 0.0);

    glVertex3f(11.25, 10, 0.0);
	glVertex3f(11.75, 10, 0.0);
	glVertex3f(11.75, 10.75, 0.0);
    glVertex3f(11.25, 10.25, 0.0);

    glVertex3f(12, 10, 0.0);
	glVertex3f(12.75, 10, 0.0);
	glVertex3f(12.75, 10.75, 0.0);
    glVertex3f(12, 10.75, 0.0);

    glVertex3f(13, 9.25, 0.0);
	glVertex3f(13.5, 9.25, 0.0);
	glVertex3f(13.5, 10.5, 0.0);
    glVertex3f(13, 10.5, 0.0);

    glVertex3f(13.75, 9.75, 0.0);
	glVertex3f(14, 9.75, 0.0);
	glVertex3f(14, 10.75, 0.0);
    glVertex3f(13.75, 10.75, 0.0);

    glVertex3f(14.25, 9.75, 0.0);
	glVertex3f(14.5, 9.75, 0.0);
	glVertex3f(14.5, 10.75, 0.0);
    glVertex3f(14.25, 10.75, 0.0);

    glVertex3f(14.75, 9.25, 0.0);
	glVertex3f(15.25, 9.25, 0.0);
	glVertex3f(15.25, 10.5, 0.0);
    glVertex3f(14.75, 10.5, 0.0);

    glVertex3f(15.5, 9.75, 0.0);
	glVertex3f(15.75, 9.75, 0.0);
	glVertex3f(15.75, 10.75, 0.0);
    glVertex3f(15.5, 10.75, 0.0);

    glVertex3f(16, 9.75, 0.0);
	glVertex3f(16.25, 9.75, 0.0);
	glVertex3f(16.25, 10.75, 0.0);
    glVertex3f(16, 10.75, 0.0);

    glVertex3f(16.5, 9.25, 0.0);
	glVertex3f(17, 9.25, 0.0);
	glVertex3f(17, 10.5, 0.0);
    glVertex3f(16.5, 10.5, 0.0);

    glVertex3f(17.25, 9.75, 0.0);
	glVertex3f(17.5, 9.75, 0.0);
	glVertex3f(17.5, 10.75, 0.0);
    glVertex3f(17.25, 10.75, 0.0);

    glVertex3f(17.75, 9.75, 0.0);
	glVertex3f(18, 9.75, 0.0);
	glVertex3f(18, 10.75, 0.0);
    glVertex3f(17.75, 10.75, 0.0);

    glVertex3f(18.25, 9.25, 0.0);
	glVertex3f(18.75, 9.25, 0.0);
	glVertex3f(18.75, 10.5, 0.0);
    glVertex3f(18.25, 10.5, 0.0);

    glVertex3f(19, 9.75, 0.0);
	glVertex3f(19.25, 9.75, 0.0);
	glVertex3f(19.25, 10.75, 0.0);
    glVertex3f(19, 10.75, 0.0);

    glVertex3f(19.5, 9.5, 0.0);
	glVertex3f(19.75, 9.5, 0.0);
	glVertex3f(19.75, 10.75, 0.0);
    glVertex3f(19.5, 10.75, 0.0);

    glVertex3f(19.75, 9.5, 0.0);
	glVertex3f(20, 9.5, 0.0);
	glVertex3f(20, 10.5, 0.0);
    glVertex3f(19.75, 10.75, 0.0);

    glEnd();


	/// Metro Rail border
	glBegin(GL_LINES);
    glColor3f (0, 0, 0);
    glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(11, 9.5, 0.0);

	glVertex3f(11, 9.5, 0.0);
	glVertex3f(11,10.25 , 0.0);

	glVertex3f(11,10.25 , 0.0);
    glVertex3f(11.75, 11, 0.0);

    glVertex3f(11.75, 11, 0.0);
    glVertex3f(20, 11, 0.0);

    glVertex3f(20, 9.25, 0.0);
	glVertex3f(20.25, 9.5, 0.0);

	glVertex3f(20.25, 9.5, 0.0);
	glVertex3f(20.25,10.75 , 0.0);

	glVertex3f(20.25,10.75 , 0.0);
    glVertex3f(20, 11, 0.0);

    glVertex3f(14.25,11 , 0.0);
    glVertex3f(15, 11.25, 0.0);

    glVertex3f(14.5, 11.25 , 0.0);
    glVertex3f(16.75,11.25, 0.0);

    glVertex3f(14.5,11.25 , 0.0);
    glVertex3f(14.25, 11.5, 0.0);

    glVertex3f(14.25,11.5 , 0.0);
    glVertex3f(14.25, 11.75, 0.0);

    glVertex3f(15.5,11 , 0.0);
    glVertex3f(15.75, 11.25, 0.0);

    glVertex3f(15.5,11 , 0.0);
    glVertex3f(15.5, 11.25, 0.0);

    glVertex3f(15.75,11 , 0.0);
    glVertex3f(15.75, 11.25, 0.0);

    glVertex3f(16.25,11.25 , 0.0);
    glVertex3f(17, 11, 0.0);

    glVertex3f(16.75,11.25 , 0.0);
    glVertex3f(17, 11.5, 0.0);

    glVertex3f(17,11.5 , 0.0);
    glVertex3f(17, 11.75, 0.0);

	glEnd();
	glPopMatrix();


    /// Metro Rail Railing
    glColor4f(0.41, 0.91, 1.00, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 9.2);
    glVertex2f(32.0, 9.2);
    glVertex2f(32.0, 10.5);
    glVertex2f(0.0, 10.5);
    glEnd();
    glColor4f(0.35, 0.18, 0.13, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(32.0, 10.5);
    glVertex2f(0.0, 10.5);
    glVertex2f(0.0, 10.6);
    glVertex2f(32.0, 10.6);
    glEnd();


	/// Road
	glBegin(GL_QUADS);
    glColor3f (0.29, 0.29, 0.29);
	glVertex2f(0.0, 0.0);
	glVertex2f(32.0, 0.0);
	glVertex2f(32.0, 1.8);
	glVertex2f(0.0, 1.8);
	glEnd();

	/// Road divider lines
    glBegin(GL_LINES);
    glColor3f(1.0, 0.93, 0.0);
    for (int i = 1; i < 32; i+=2) {
        glVertex2f(i, 0.9);
        glVertex2f(i+1, 0.9);
    }
    glEnd();

    /// Footpath
    glBegin(GL_QUADS);
    glColor3f (0.48, 0.34, 0.26);
    glVertex2f(0.0, 1.8);
    glVertex2f(32.0, 1.8);
    glVertex2f(32.0, 2.2);
    glVertex2f(0.0, 2.2);
    glEnd();


    /// Cars
    glPushMatrix();
    glTranslatef(-position4, 0.0f, 0.0f);

    myCars(4.8, 6.3, 1.0, 1.3, 13, 93, 88, 0, 111, 248);
    myCars(8.8, 10.3, 1.0, 1.3, 93, 13, 40, 55, 139, 90);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(position5, 0.0f, 0.0f);

    myCars(2.8, 4.6, 0.05, 0.3, 13, 93, 88, 0, 111, 248);
    myCars(6.8, 8.6, 0.05, 0.3, 93, 13, 40, 55, 139, 90);

    glPopMatrix();





    /// Birds

    Morning(_morning);


glFlush ();
}



/// Function Night_R
void Night_R(int _nt){
if(night_R){

    moon(true);

    glClearColor(0.00, 0.11, 0.36, 1.0);
    glutTimerFunc(8, Night_R, 0);
    glFlush();
}
}

/// Function for Rainy weather
void Rain(int rainy){

if(rainday){

    sunR(false);

    _rain += 0.001f;



    glBegin(GL_POINTS);
    for(int i=1;i<=70;i++)
    {
        if(day_rain == true){
            glClearColor (0.259, 0.569, 0.8, 0.82);
        }
        int x=rand(),y=rand();
        x%=32; y%=18;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2d(x,y);
        glVertex2d(x+.25,y+.55);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();
}
}

void initR (void)
{
    glClearColor (0.77, 0.95, 1.00, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 32.0, 0.0, 18.0, -10.0, 10.0);

}
void handleMouseR(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        speed += 1;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 1;
    }
    glutPostRedisplay();
}
// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************
// *****************************************************  REJUAN  ************************************************





















// *****************************************************  ESTHAB  ************************************************
// *****************************************************  ESTHAB  ************************************************
// *****************************************************  ESTHAB  ************************************************
// *****************************************************  ESTHAB  ************************************************
bool dayNight = true;
bool fountain = false;
bool keymap=true;
int i;
void setColor(string col){
    //day
    if(dayNight){
        if(col == "background") glColor3ub (133, 193, 233);
        else if(col == "darkBlue") glColor3ub (0, 84, 120);
        else if(col == "navyBlue") glColor3ub (0, 66, 101);
        else if(col == "lightGreen") glColor3ub (122, 250, 137);
        else if(col == "darkGreen") glColor3ub (30, 132, 73); //changed
        else if(col == "white") glColor3ub (255, 255, 255);
        else if(col == "black") glColor3ub (0, 0, 0);
        else if(col == "window") glColor3ub (202, 201, 201); //changed
        else if(col == "mediumGreen") glColor3ub (10, 176, 128);
        else if(col == "teal") glColor3ub (21, 177, 189);
        else if(col == "trainBody") glColor3ub (255, 255, 255); //changed
        else if(col == "trainFace") glColor3ub (255, 1, 1); //changed
        else if(col == "trainBodyStripe") glColor3ub (17, 255, 16); //changed
        else if(col == "darkerGreen") glColor3ub (20, 90, 50);
        else if(col == "blue") glColor3ub (0, 122, 171);
        else if(col == "sun") glColor3ub (246, 247, 193);
        else if(col == "grass") glColor3ub (97, 201, 85);
        else if(col == "gray") glColor3ub (84, 84, 84);
        else if(col == "ash") glColor3ub (156, 156, 156);
        else if(col == "yellow") glColor3ub (241, 106, 81);
        else if(col == "darkYellow") glColor3ub (241, 196, 15);
        else if(col == "jeepWindow") glColor3ub (52, 195, 227);
        else if(col == "fountainLight") glColor3ub (145, 178, 235);
        else if(col == "fountainMid") glColor3ub (92, 145, 214);
        else if(col == "fountainDark") glColor3ub (46, 78, 143);


        else{
            cout<<"INVALID COLOR CODE: "<<col<<"\n";
            glColor3ub (0,0,0);
        }

    }
    //night
    else{
        if(col == "background") glColor3ub (27, 115, 135);
        else if(col == "darkBlue") glColor3ub (30, 48, 88);
        else if(col == "navyBlue") glColor3ub (30, 48, 88);
        else if(col == "lightGreen") glColor3ub (51, 148, 129);
        else if(col == "darkGreen") glColor3ub (30, 132, 73);
        else if(col == "white") glColor3ub (83, 170, 179);
        else if(col == "black") glColor3ub (37, 0, 36);
        else if(col == "window") glColor3ub (247, 242, 171);
        else if(col == "mediumGreen") glColor3ub (83, 70, 53);
        else if(col == "teal") glColor3ub (28, 102, 127);
        else if(col == "trainBody") glColor3ub (255, 255, 255);
        else if(col == "trainFace") glColor3ub (255, 1, 1);
        else if(col == "trainBodyDark") glColor3ub (201, 93, 64);
        else if(col == "trainBodyStripe") glColor3ub (17, 255, 16);
        else if(col == "darkerGreen") glColor3ub (20, 90, 50);
        else if(col == "blue") glColor3ub (27, 71, 110);
        else if(col == "sun") glColor3ub (229, 229, 229);
        else if(col == "grass") glColor3ub (47, 118, 102);
        else if(col == "gray") glColor3ub (52, 56, 83);
        else if(col == "ash") glColor3ub (156, 156, 156);
        else if(col == "yellow") glColor3ub (241, 106, 81);
        else if(col == "darkYellow") glColor3ub (241, 196, 15);
        else if(col == "jeepWindow") glColor3ub (52, 195, 227);
        else if(col == "fountainLight") glColor3ub (59, 118, 150);
        else if(col == "fountainMid") glColor3ub (50, 93, 136);
        else if(col == "fountainDark") glColor3ub (42, 51, 98);
        else{
            cout<<"INVALID COLOR CODE: "<<col<<"\n";
            glColor3ub (0,0,0);
        }
    }
}

//animate train
float trainSpeed = 0;
float trainPosition = 1000;

//animate clouds
float cloud1Position = 250;
float cloud2Position = 210;
float cloud3Position = 1100;

float cloud1Speed = 1.0;
float cloud2Speed = 2.5;
float cloud3Speed = 2.0;


//animate jeep
float jeepSpeed = 1.0;
float jeepPosition = 0;


//animate fountain
float fountain1Position = 0;
float fountain1Speed = 2.5;

float fountain2Position = 0;
float fountain2Speed = 3;

void drawBackground(){
    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,620);
    glVertex2i(0,620);
    glEnd();
}

void drawStars(){

    glPushMatrix();
    glTranslatef(50,520,0);
    setColor("sun");
    //glColor3ub (1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,515,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,540,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,560,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,500,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(280,490,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,490,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,510,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(500,530,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(600,525,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650,510,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700,500,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(760,540,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800,520,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(850,540,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(760+100,530,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800+100,505,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(850+100,510,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(760+200,530,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800+200,505,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(850+200,550,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(760+300,560,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(800+300,545,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(850+300,510,0);
    setColor("sun");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(5,0);
    glVertex2i(5,5);
    glVertex2i(0,5);
    glEnd();
    glPopMatrix();

}


void drawTrain(){

    glPushMatrix();
    glTranslatef(trainPosition,260, 0);
    glScalef(0.7,0.7,1);
    //main body
    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(440,170);
    glVertex2i(440,210);
    glVertex2i(0,210);
    glEnd();

    //upperLine main body
    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(5,210);
    glVertex2i(435,210);
    glVertex2i(435,215);
    glVertex2i(5,215);
    glEnd();

    setColor("trainBody");
    glBegin(GL_QUADS);
    glVertex2i(5,210);
    glVertex2i(35,210);
    glVertex2i(35,215);
    glVertex2i(5,215);
    glEnd();



    //face
    setColor("trainFace");
    glBegin(GL_QUADS);
    glVertex2i(0,170);
    glVertex2i(40,170);
    glVertex2i(40,205);
    glVertex2i(0,205);
    glEnd();

    //face stripe
    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(0,175);
    glVertex2i(40,175);
    glVertex2i(40,180);
    glVertex2i(0,180);
    glEnd();


    //lights
    if (dayNight) setColor("navyBlue");
    else setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(5,175);
    glVertex2i(10,175);
    glVertex2i(10,185);
    glVertex2i(5,185);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(30,175);
    glVertex2i(35,175);
    glVertex2i(35,185);
    glVertex2i(30,185);
    glEnd();

    //frontWindow
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(5,190);
    glVertex2i(35,190);
    glVertex2i(35,205);
    glVertex2i(5,205);
    glEnd();

    //long stripes
    //up
    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(40,205);
    glVertex2i(440,205);
    glVertex2i(440,210);
    glVertex2i(40,210);
    glEnd();


    //down
    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(40,175);
    glVertex2i(65,175);
    glVertex2i(65,180);
    glVertex2i(40,180);
    glEnd();

    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(100,175);
    glVertex2i(200,175);
    glVertex2i(200,180);
    glVertex2i(100,180);
    glEnd();

    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(235,175);
    glVertex2i(335,175);
    glVertex2i(335,180);
    glVertex2i(235,180);
    glEnd();

    setColor("trainBodyStripe");
    glBegin(GL_QUADS);
    glVertex2i(370,175);
    glVertex2i(440,175);
    glVertex2i(440,180);
    glVertex2i(370,180);
    glEnd();



    //train windows and door component(1)
    //window
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(55,185);
    glVertex2i(65,185);
    glVertex2i(65,200);
    glVertex2i(55,200);
    glEnd();

    //doors
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(70,170);
    glVertex2i(80,170);
    glVertex2i(80,200);
    glVertex2i(70,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(85,170);
    glVertex2i(95,170);
    glVertex2i(95,200);
    glVertex2i(85,200);
    glEnd();
    //end doors

    //more windows
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(100,185);
    glVertex2i(110,185);
    glVertex2i(110,200);
    glVertex2i(100,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(115,185);
    glVertex2i(125,185);
    glVertex2i(125,200);
    glVertex2i(115,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(130,185);
    glVertex2i(140,185);
    glVertex2i(140,200);
    glVertex2i(130,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(145,185);
    glVertex2i(155,185);
    glVertex2i(155,200);
    glVertex2i(145,200);
    glEnd();
    //end of window + doors component(1)

    //train windows and door component(2)
    //window
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(185,185);
    glVertex2i(195,185);
    glVertex2i(195,200);
    glVertex2i(185,200);
    glEnd();

    //doors
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(200,170);
    glVertex2i(210,170);
    glVertex2i(210,200);
    glVertex2i(200,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(215,170);
    glVertex2i(225,170);
    glVertex2i(225,200);
    glVertex2i(215,200);
    glEnd();
    //end doors

    //more windows
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(230,185);
    glVertex2i(240,185);
    glVertex2i(240,200);
    glVertex2i(230,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(245,185);
    glVertex2i(255,185);
    glVertex2i(255,200);
    glVertex2i(245,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(260,185);
    glVertex2i(270,185);
    glVertex2i(270,200);
    glVertex2i(260,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(275,185);
    glVertex2i(285,185);
    glVertex2i(285,200);
    glVertex2i(275,200);
    glEnd();
    //end of window + doors component(2)

    //train windows and door component(3)
    //window
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(325,185);
    glVertex2i(335,185);
    glVertex2i(335,200);
    glVertex2i(325,200);
    glEnd();

    //doors
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(340,170);
    glVertex2i(350,170);
    glVertex2i(350,200);
    glVertex2i(340,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(355,170);
    glVertex2i(365,170);
    glVertex2i(365,200);
    glVertex2i(355,200);
    glEnd();
    //end doors

    //more windows
    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(370,185);
    glVertex2i(380,185);
    glVertex2i(380,200);
    glVertex2i(370,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(385,185);
    glVertex2i(395,185);
    glVertex2i(395,200);
    glVertex2i(385,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(400,185);
    glVertex2i(410,185);
    glVertex2i(410,200);
    glVertex2i(400,200);
    glEnd();

    setColor("navyBlue");
    glBegin(GL_QUADS);
    glVertex2i(415,185);
    glVertex2i(425,185);
    glVertex2i(425,200);
    glVertex2i(415,200);
    glEnd();
    //end of window + doors component(3)


    glPopMatrix();
}


void drawBridge(){

    glPushMatrix();
    glTranslatef(0,300,0);
    glScalef(0.7,0.7,1);

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(0,95);
    glVertex2i(2500,95);
    glVertex2i(2500,120);
    glVertex2i(0,120);
    glEnd();


    setColor("darkerGreen");
    glBegin(GL_QUADS);
    glVertex2i(0,80);
    glVertex2i(2500,80);
    glVertex2i(2500,95);
    glVertex2i(0,95);
    glEnd();

    setColor("glColor3ub (0,0,0)");
    glBegin(GL_QUADS);
    glVertex2i(0,60);
    glVertex2i(2500,60);
    glVertex2i(2500,80);
    glVertex2i(0,80);
    glEnd();



    //pillars
    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(285,0);
    glVertex2i(320,0);
    glVertex2i(320,80);
    glVertex2i(285,80);
    glEnd();

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(285+245,0);
    glVertex2i(320+245,0);
    glVertex2i(320+245,80);
    glVertex2i(285+245,80);
    glEnd();

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(285+490,0);
    glVertex2i(320+490,0);
    glVertex2i(320+490,80);
    glVertex2i(285+490,80);
    glEnd();

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(285+735,0);
    glVertex2i(320+735,0);
    glVertex2i(320+735,80);
    glVertex2i(285+735,80);
    glEnd();

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(285+1180,0);
    glVertex2i(320+1180,0);
    glVertex2i(320+1180,80);
    glVertex2i(285+1180,80);
    glEnd();

    glPopMatrix();

}


void drawTree1(string col){

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(200,550,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 150*sin(i);
            float y = 150*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,650,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 120*sin(i);
            float y = 120*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree2(string col){

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(550,470,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 150*sin(i);
            float y = 150*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(550,570,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 120*sin(i);
            float y = 120*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree3(string col){

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(900,390,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 150*sin(i);
            float y = 150*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900,490,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 120*sin(i);
            float y = 120*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree4(string col){

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(5900,400,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 150*sin(i);
            float y = 150*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5900,500,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 120*sin(i);
            float y = 120*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawTree5(string col){

    glPushMatrix();
    glScalef(0.2,0.2,1);
    glPushMatrix();
    glTranslatef(6240,470,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 150*sin(i);
            float y = 150*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6240,570,0);
    setColor(col);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 120*sin(i);
            float y = 120*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}


void drawBranches(){
    //1
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37,30);
    glVertex2i(39,30);
    glVertex2i(39,120);
    glVertex2i(37,120);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37,65);
    glVertex2i(39,65);
    glVertex2i(53,95);
    glVertex2i(50,95);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38,75);
    glVertex2i(36,75);
    glVertex2i(21,105);
    glVertex2i(23,105);
    glEnd();

    //2
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+70,30-15);
    glVertex2i(39+70,30-15);
    glVertex2i(39+70,120-15);
    glVertex2i(37+70,120-15);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+70,65-15);
    glVertex2i(39+70,65-15);
    glVertex2i(53+70,95-15);
    glVertex2i(50+70,95-15);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+70,75-15);
    glVertex2i(36+70,75-15);
    glVertex2i(21+70,105-15);
    glVertex2i(23+70,105-15);
    glEnd();

    //3
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140,30-20);
    glVertex2i(39+140,30-20);
    glVertex2i(39+140,120-20);
    glVertex2i(37+140,120-20);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140,65-20);
    glVertex2i(39+140,65-20);
    glVertex2i(53+140,95-20);
    glVertex2i(50+140,95-20);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+140,75-20);
    glVertex2i(36+140,75-20);
    glVertex2i(21+140,105-20);
    glVertex2i(23+140,105-20);
    glEnd();

    //4
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140+1000,30-20);
    glVertex2i(39+140+1000,30-20);
    glVertex2i(39+140+1000,120-20);
    glVertex2i(37+140+1000,120-20);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+140+1000,65-20);
    glVertex2i(39+140+1000,65-20);
    glVertex2i(53+140+1000,95-20);
    glVertex2i(50+140+1000,95-20);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+140+1000,75-20);
    glVertex2i(36+140+1000,75-20);
    glVertex2i(21+140+1000,105-20);
    glVertex2i(23+140+1000,105-20);
    glEnd();

    //5
    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+210+1000,30-20);
    glVertex2i(39+210+1000,30-20);
    glVertex2i(39+210+1000,120-20);
    glVertex2i(37+210+1000,120-20);
    glEnd();

    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(37+210+1000,65-20);
    glVertex2i(39+210+1000,65-20);
    glVertex2i(53+210+1000,95-20);
    glVertex2i(50+210+1000,95-20);
    glEnd();


    setColor("white");
    glBegin(GL_QUADS);
    glVertex2i(38+210+1000,75-20);
    glVertex2i(36+210+1000,75-20);
    glVertex2i(21+210+1000,105-20);
    glVertex2i(23+210+1000,105-20);
    glEnd();




}


void drawClouds1(){
    glPushMatrix();
    glTranslatef(cloud1Position,-90,0);
    glScalef(1,1,1);

    glPushMatrix();
    glTranslatef(200,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 30*sin(i);
            float y = 40*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 35*sin(i);
            float y = 45*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 35*sin(i);
            float y = 45*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(170,570-70);
    glVertex2i(340,570-70);
    glVertex2i(340,615-70+20);
    glVertex2i(170,615-70+20);

    glEnd();
    glPopMatrix();

}

void drawClouds2(){
    glPushMatrix();
    glTranslatef(cloud2Position,250,0);
    glScalef(0.5,0.4,1);

    glPushMatrix();
    glTranslatef(200,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 30*sin(i);
            float y = 40*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 35*sin(i);
            float y = 45*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 35*sin(i);
            float y = 45*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(170,570-70);
    glVertex2i(340,570-70);
    glVertex2i(340,615-70+20);
    glVertex2i(170,615-70+20);

    glEnd();
    glPopMatrix();

}

void drawClouds3(){
    glPushMatrix();
    glTranslatef(cloud3Position,250,0);
    glScalef(0.5,0.4,1);

    glPushMatrix();
    glTranslatef(200,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 30*sin(i);
            float y = 40*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 35*sin(i);
            float y = 45*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,550,0);
    setColor("white");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 35*sin(i);
            float y = 45*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

    setColor("background");
    glBegin(GL_QUADS);
    glVertex2i(170,570-70);
    glVertex2i(340,570-70);
    glVertex2i(340,615-70+20);
    glVertex2i(170,615-70+20);

    glEnd();
    glPopMatrix();

}


void drawMountain()
{

    setColor("darkerGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(300,300);
    glVertex2i(600,300);
    glVertex2i(450,500);
    glEnd();



    setColor("darkerGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(600,300);
    glVertex2i(900,300);
    glVertex2i(750,550);
    glEnd();

    setColor("darkGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(400,300);
    glVertex2i(800,300);
    glVertex2i(600,600);
    glEnd();


}
void drawRightMountain(){

    glPushMatrix();
    glTranslatef(+650,0,0);
    setColor("darkGreen");
   //glColor3ub (0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(400,300);
    glVertex2i(800,300);
    glVertex2i(600,600);
    glEnd();
    glPopMatrix();

}
void drawFountainMountain(){
     glPushMatrix();
    glTranslatef(-450,0,0);
    setColor("darkerGreen");
    glBegin(GL_TRIANGLES);
    glVertex2i(300,300);
    glVertex2i(600,300);
    glVertex2i(450,500);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-400,0,0);
    setColor("darkGreen");
    //glColor3ub (23, 201, 205);
    glBegin(GL_TRIANGLES);
    glVertex2i(300,300);
    glVertex2i(600,300);
    glVertex2i(450,500);
    glEnd();

    glPopMatrix();


}


void drawCave() {
    glPushMatrix();

    // Outer Cave (Gray Semicircle)
    setColor("gray");
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(610, 270);  // Center point
        for (float i = 0; i <= 3.14; i += 0.001) {
            float x = 75 * cos(i) + 610;
            float y = 75 * sin(i) + 299.699;
            glVertex2f(x, y);
        }
    glEnd();

    // Inner Cave (Black Semicircle)
    setColor("black");
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(610, 270);  // Center point
        for (float i = 0; i <= 3.14; i += 0.001) {
            float x = 70 * cos(i) + 610;
            float y = 70 * sin(i) + 299.699;
            glVertex2f(x, y);
        }
    glEnd();

    glPopMatrix();




    setColor("grass");
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1280,0);
    glVertex2i(1280,300);
    glVertex2i(0,300);
    glEnd();
    //background + circle half end

    //road
    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(540,300);
    glVertex2i(680,300);
    glVertex2i(670,0);
    glVertex2i(450,0);
    glEnd();

    setColor("gray");
    glBegin(GL_QUADS);
    glVertex2i(545,300);
    glVertex2i(675,300);
    glVertex2i(665,0);
    glVertex2i(455,0);
    glEnd();

    //lanes

    glPushMatrix();
    glTranslatef(480,0,0);

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(110,250);
    glVertex2i(120,250);
    glVertex2i(115,230);
    glVertex2i(105,230);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,-80,0);

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(110,250);
    glVertex2i(120,250);
    glVertex2i(115,230);
    glVertex2i(105,230);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(450,-160,0);

    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(110,250);
    glVertex2i(120,250);
    glVertex2i(115,230);
    glVertex2i(105,230);
    glEnd();

    glPopMatrix();

}


void drawJeep()
{

    glPushMatrix();
    glTranslatef(-10,jeepPosition,0);


    setColor("ash");
    glBegin(GL_QUADS);
    glVertex2i(575,300);
    glVertex2i(645,300);
    glVertex2i(645,305);
    glVertex2i(575,305);
    glEnd();
    setColor("yellow");
    glBegin(GL_QUADS);
    glVertex2i(580,305);
    glVertex2i(640,305);
    glVertex2i(640,310);
    glVertex2i(580,310);
    glEnd();
    //lights
    if (dayNight) setColor("navyBlue");
    else setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(590,305);
    glVertex2i(595,305);
    glVertex2i(595,310);
    glVertex2i(590,310);
    glEnd();
    //lights
    if (dayNight) setColor("navyBlue");
    else setColor("window");
    glBegin(GL_QUADS);
    glVertex2i(625,305);
    glVertex2i(630,305);
    glVertex2i(630,310);
    glVertex2i(625,310);
    glEnd();
    setColor("darkYellow");
    glBegin(GL_QUADS);
    glVertex2i(580,310);
    glVertex2i(640,310);
    glVertex2i(630,315);
    glVertex2i(590,315);
    glEnd();
    setColor("yellow");
    glBegin(GL_QUADS);
    glVertex2i(590,315);
    glVertex2i(630,315);
    glVertex2i(630,330);
    glVertex2i(590,330);
    glEnd();
    setColor("jeepWindow");
    glBegin(GL_QUADS);
    glVertex2i(592,317);
    glVertex2i(628,317);
    glVertex2i(628,328);
    glVertex2i(592,328);
    glEnd();
    setColor("black");
    glBegin(GL_QUADS);
    glVertex2i(580,290);
    glVertex2i(590,290);
    glVertex2i(590,300);
    glVertex2i(580,300);
    glEnd();
    setColor("black");
    glBegin(GL_QUADS);
    glVertex2i(630,290);
    glVertex2i(640,290);
    glVertex2i(640,300);
    glVertex2i(630,300);
    glEnd();


    glPopMatrix();
}


void drawSunMoon(){
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(200,550,0);
    setColor("sun");
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 30*sin(i);
            float y = 30*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}

void drawTreeBunch(){


    glPushMatrix();
    glTranslatef(320,250,0);
    glScalef(.7,.7,1);
    drawTree1("lightGreen");
    drawTree2("lightGreen");
    drawTree3("darkGreen");
    drawTree4("darkerGreen");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,150,0);
    glScalef(.7,.7,1);
    drawTree1("lightGreen");
    drawTree2("lightGreen");
    drawTree3("darkGreen");
    drawTree4("darkerGreen");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,200,0);
    glScalef(.7,.7,1);
    drawTree1("blue");
    drawTree2("lightGreen");
    drawTree3("darkGreen");
    drawTree4("darkerGreen");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700,200,0);
    glScalef(.8,.8,1);
    drawTree1("teal");
    drawTree2("blue");
    drawTree3("darkGreen");
    drawTree4("darkerGreen");
    drawTree5("teal");
    drawBranches();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(50,50,0);
    glScalef(.7,.7,1);
    drawTree1("teal");
    drawTree2("darkGreen");
    drawTree3("blue");
    drawTree4("darkGreen");
    drawTree5("blue");
    drawBranches();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(20,10,0);
    glScalef(.7,.7,1);
    drawTree1("darkerGreen");
    drawTree2("darkGreen");
    drawTree3("blue");
    drawTree4("teal");
    drawTree5("blue");
    drawBranches();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(80,100,0);
    glScalef(.7,.7,1);
    drawTree1("blue");
    drawTree2("darkGreen");
    drawTree3("blue");
    drawTree4("teal");
    drawTree5("darkerGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(70,10,0);
    glScalef(.7,.7,1);
    drawTree1("darkerGreen");
    drawTree2("lightGreen");
    drawTree3("blue");
    drawTree4("teal");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(220,50,0);
    glScalef(.7,.7,1);
    drawTree1("teal");
    drawTree2("darkGreen");
    drawTree3("blue");
    drawTree4("darkGreen");
    drawTree5("blue");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(210,100,0);
    glScalef(.7,.7,1);
    drawTree1("blue");
    drawTree2("darkGreen");
    drawTree3("blue");
    drawTree4("teal");
    drawTree5("darkerGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,10,0);
    glScalef(.7,.7,1);
    drawTree1("darkerGreen");
    drawTree2("lightGreen");
    drawTree3("blue");
    drawTree4("teal");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(650,120,0);
    glScalef(1,1,1);
    drawTree1("darkGreen");
    drawTree2("lightGreen");
    drawTree3("teal");
    drawTree4("teal");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(850,110,0);
    glScalef(1,1,1);
    drawTree1("darkerGreen");
    drawTree2("lightGreen");
    drawTree3("teal");
    drawTree4("teal");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(750,170,0);
    glScalef(1,1,1);
    drawTree1("teal");
    drawTree2("lightGreen");
    drawTree3("teal");
    drawTree4("teal");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650,60,0);
    glScalef(1,1,1);
    drawTree1("blue");
    drawTree2("darkGreen");
    drawTree3("lightGreen");
    drawTree4("blue");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(650,10,0);
    glScalef(1,1,1);
    drawTree1("blue");
    drawTree2("darkGreen");
    drawTree3("lightGreen");
    drawTree4("blue");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(350,170,0);
    glScalef(.7,.7,1);
    drawTree1("lightGreen");
    drawTree2("lightGreen");
    drawTree3("darkGreen");
    drawTree4("darkGreen");
    drawTree5("darkerGreen");
    drawBranches();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(330,110,0);
    glScalef(.7,.7,1);
    drawTree1("teal");
    drawTree2("teal");
    drawTree3("darkGreen");
    drawTree4("lightGreen");
    drawTree5("darkerGreen");
    drawBranches();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(330,50,0);
    glScalef(.7,.7,1);
    drawTree1("lightGreen");
    drawTree2("lightGreen");
    drawTree3("darkGreen");
    drawTree4("darkerGreen");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,0,0);
    glScalef(.7,.7,1);
    drawTree1("lightGreen");
    drawTree2("lightGreen");
    drawTree3("darkGreen");
    drawTree4("darkerGreen");
    drawTree5("lightGreen");
    drawBranches();
    glPopMatrix();

}


void drawWaterFall()
{
    setColor("fountainLight");
    //glColor3ub (23, 201, 205);
    glBegin(GL_QUADS);
    glVertex2i(20,475);
    glVertex2i(35,475);
    glVertex2i(35,445);
    glVertex2i(20,445);
    glEnd();
    setColor("fountainLight");
    glBegin(GL_QUADS);
    glVertex2i(15,470);
    glVertex2i(50,470);
    glVertex2i(50,445);
    glVertex2i(15,445);
    glEnd();
    setColor("fountainLight");
    glBegin(GL_QUADS);
    glVertex2i(10,460);
    glVertex2i(55,460);
    glVertex2i(55,440);
    glVertex2i(10,440);
    glEnd();
    setColor("fountainLight");
    glBegin(GL_QUADS);
    glVertex2i(5,450);
    glVertex2i(60,450);
    glVertex2i(60,300);
    glVertex2i(5,300);
    glEnd();

    //1
    glPushMatrix();
    glTranslatef(0,fountain1Position,0);
    setColor("fountainMid");

    // glColor3ub (23, 201, 205);
    glBegin(GL_QUADS);
    glVertex2i(20,450);
    glVertex2i(25,450);
    glVertex2i(25,400);
    glVertex2i(20,400);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(25,440);
    glVertex2i(30,440);
    glVertex2i(30,410);
    glVertex2i(25,410);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(15,430);
    glVertex2i(20,430);
    glVertex2i(20,420);
    glVertex2i(15,420);
    glEnd();
    glPopMatrix();
    //1

    //2
    glPushMatrix();
    glTranslatef(0,fountain1Position,0);
    glPushMatrix();
    glTranslatef(+20,-10,0);
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(20,450);
    glVertex2i(25,450);
    glVertex2i(25,400);
    glVertex2i(20,400);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(25,440);
    glVertex2i(30,440);
    glVertex2i(30,410);
    glVertex2i(25,410);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(15,430);
    glVertex2i(20,430);
    glVertex2i(20,420);
    glVertex2i(15,420);
    glEnd();
     glPopMatrix();

     glPopMatrix();
    //2

    //3
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
    glPopMatrix();
    //3


    //4
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);

    glPushMatrix();
    glTranslatef(+20,-10,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
     glPopMatrix();
     glPopMatrix();
     //4


    //5
    glPushMatrix();
    glTranslatef(0,fountain1Position,0);

    glPushMatrix();
    glTranslatef(+10,-30,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
     glPopMatrix();
    glPopMatrix();
    //5

    //6
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);

     glPushMatrix();
    glTranslatef(-10,-40,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
     glPopMatrix();

     glPopMatrix();
     //6


    //7
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);

     glPushMatrix();
    glTranslatef(+20,-80,0);
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(20,450);
    glVertex2i(25,450);
    glVertex2i(25,400);
    glVertex2i(20,400);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(25,440);
    glVertex2i(30,440);
    glVertex2i(30,410);
    glVertex2i(25,410);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(15,430);
    glVertex2i(20,430);
    glVertex2i(20,420);
    glVertex2i(15,420);
    glEnd();
     glPopMatrix();
    glPopMatrix();
    //7

    //8
    glPushMatrix();
    glTranslatef(0,fountain1Position,0);

     glPushMatrix();
    glTranslatef(-10,-100,0);
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(20,450);
    glVertex2i(25,450);
    glVertex2i(25,400);
    glVertex2i(20,400);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(25,440);
    glVertex2i(30,440);
    glVertex2i(30,410);
    glVertex2i(25,410);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(15,430);
    glVertex2i(20,430);
    glVertex2i(20,420);
    glVertex2i(15,420);
    glEnd();
     glPopMatrix();
     glPopMatrix();
     //8

    //9
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);
      glPushMatrix();
    glTranslatef(+20,-100,0);
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(20,450);
    glVertex2i(25,450);
    glVertex2i(25,400);
    glVertex2i(20,400);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(25,440);
    glVertex2i(30,440);
    glVertex2i(30,410);
    glVertex2i(25,410);
    glEnd();
    setColor("fountainMid");
    glBegin(GL_QUADS);
    glVertex2i(15,430);
    glVertex2i(20,430);
    glVertex2i(20,420);
    glVertex2i(15,420);
    glEnd();
     glPopMatrix();
     glPopMatrix();
     //9


    //10
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);

     glPushMatrix();
    glTranslatef(+5,-70,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
     glPopMatrix();
     glPopMatrix();
     //10

    //11
    glPushMatrix();
    glTranslatef(0,fountain2Position,0);

     glPushMatrix();
    glTranslatef(+5,+60,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
     glPopMatrix();
     glPopMatrix();
     //11

    //12
        glPushMatrix();
    glTranslatef(0,fountain2Position,0);
     glPushMatrix();
    glTranslatef(-15,+30,0);
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(25,415);
    glVertex2i(30,415);
    glVertex2i(30,385);
    glVertex2i(25,385);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(30,410);
    glVertex2i(35,410);
    glVertex2i(35,380);
    glVertex2i(30,380);
    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(20,405);
    glVertex2i(25,405);
    glVertex2i(25,360);
    glVertex2i(20,360);
    glEnd();
     glPopMatrix();
    glPopMatrix();
    //12



}

void drawPond(){

    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(0,300);
    glVertex2i(200,300);
    glVertex2i(200,220);
    glVertex2i(0,220);

    glEnd();
    setColor("fountainDark");
    glBegin(GL_QUADS);
    glVertex2i(180,300);
    glVertex2i(200,300);
    glVertex2i(213,260);
    glVertex2i(180,260);


    glEnd();


    glPushMatrix();
    glTranslatef(100,240,0);
    setColor("fountainDark");
    // glColor3ub (23, 201, 205);
    glBegin(GL_TRIANGLE_FAN);
        for(float i=0;i<=2*3.14;i+=0.001)
        {
            float x = 120*sin(i);
            float y = 60*cos(i);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();

}



void update(int val){
    //animate train
    if(trainPosition < -1050) trainPosition = 1000;
    trainPosition -= trainSpeed;

    //animate jeep
    if(jeepPosition < - 350) jeepPosition = 0;
    jeepPosition -= jeepSpeed;

    //animate clouds
    if(cloud1Position > 1280) cloud1Position = -500;
    cloud1Position += cloud1Speed;

    if(cloud2Position < -300) cloud2Position = 1300;
    cloud2Position -= cloud2Speed;

    if(cloud3Position < -300) cloud3Position = 1300;
    cloud3Position -= cloud3Speed;
    glutPostRedisplay();
    glutTimerFunc(10, update,0);


    if(fountain){
    //animate fountain
    if(fountain1Position <= -110)
        fountain1Speed = -2.5;

    else if (fountain1Position >= 0)
        fountain1Speed = 2.5;
    fountain1Position -= fountain1Speed;


    if(fountain2Position <= -110)
        fountain2Speed = -3;

    else if (fountain2Position >= 0)
        fountain2Speed = 3;
    fountain2Position -= fountain2Speed;

    }

}

void anyText(string text, float x, float y, int R, int G, int B){
    glColor3ub(R, G, B);
    glRasterPos2f(x, y);
    for (i = 0; i < text.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }}

void keymappings(bool keymap){
    if(keymap==true)
    anyText("n = day/night | f = fountain | w = train run | s = train Stop | j = jeep Speed | y = jeep Stop | k = keymap show | e = exit", 10, 10, 255, 255, 255);
}



void myDisplayE(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    drawBackground();
    drawSunMoon();
    // drawBackMountains();
    if(!dayNight) {drawStars(); drawTrain(); drawJeep();}
    drawClouds1();
    drawClouds2();
    drawClouds3();


    drawBridge();
    if(dayNight) drawTrain();
    drawMountain();
    drawFountainMountain();

    drawWaterFall();
    drawRightMountain();
    drawCave();
    if(dayNight) drawJeep();
    if(!dayNight){drawJeep();}
    drawPond();
    drawTreeBunch();
    keymappings(keymap);


    glFlush ();
}

void myInitE (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1280.0, 0.0, 620.0);
}
// *****************************************************  ESTHAB  ************************************************
// *****************************************************  ESTHAB  ************************************************
// *****************************************************  ESTHAB  ************************************************
// *****************************************************  ESTHAB  ************************************************




























// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************

float x,y;


GLfloat radiusN;
int triangleAmountN =40;
GLfloat twicePiN = 2.0 * PI;

float counter1=0.0;

GLfloat positionN = 0.0f;
GLfloat speedN = 0.001f;

GLfloat positionN2 = 0.0f;
GLfloat speedN2 = 0.0005f;

GLfloat positionN3 = 0.0f;
GLfloat speedN3 = 0.00003f;


void updateN(int value)
{

    if(positionN > 2.5)
        positionN = 0.0f;

    positionN += speedN;

    if(positionN < 0)
        positionN = 2.5f;

    positionN += speedN;

    if(positionN2 >1.0)
        positionN2 =-1.0f;

    positionN2 += speedN2;

    if(positionN2 <-1.0)
        positionN2 =1.0f;

    positionN2 += speedN2;

    if(positionN3 >1.0)
        positionN3 =-1.0f;

    positionN3 += speedN3;

    if(positionN3 <-1.0)
        positionN3 =1.0f;

    positionN3 += speedN3;

	glutPostRedisplay();


	glutTimerFunc(10, updateN, 0);
}
void initN(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void WeatherN()
{

//WeatherN//*******************************
    glBegin(GL_POLYGON);
    glColor3ub(255, 175, 129);
    glVertex2f(-1,1);
    glVertex2f(-0.5,1);
    glVertex2f(0,1);
    glVertex2f(0.5,1);
    glVertex2f(1,1);
    glVertex2f(1,0.5);
    glVertex2f(1,0);
    glVertex2f(1,-0.5);

    glColor3ub(255, 223, 130);
    glVertex2f(1,-1);
    glVertex2f(0.5,-1);
    glVertex2f(0,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-1,-1);
    glVertex2f(-1,-0.5);
    glVertex2f(-1,0);
    glVertex2f(-1,0.5);
    glEnd();
}


void StarsN()
{
//StarsN//*******************************
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glColor3ub(253, 254, 254);
    glVertex2f(-0.3645172959228,0.4309170099487);
    glVertex2f(-0.1821772156068,0.4481564358171);
    glVertex2f(-0.1225022802306,0.5191033038138);
    glVertex2f(0.3405137665184,0.4669291361126);
    glVertex2f(0.6715992413588,0.4674006182477);

    glVertex2f(0.133518308869,0.6199728400006);
    glVertex2f(0.5253637739596,0.7548184461239);
    glVertex2f(0.2,0.8);
    glVertex2f(0.8410338162627,0.7080052324405);
    glVertex2f(-0.2894974846897,0.7359195857011);
    glVertex2f(-0.0297675866571,0.907116918527);
    glVertex2f(0.388722593744,0.9116657248602);
    glVertex2f(0.7185110511253,0.8866472900273);
    glEnd();
}

void MoonN()
{


//MoonN//*******************************
    glPushMatrix();
    glTranslatef(positionN2,-positionN2,0);


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=0.5;
    y=0.7;
    radiusN =0.1;
    twicePiN = -1.5 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 175, 129);

    x=0.525;
    y=0.72;
    radiusN =0.1;
    twicePiN = 2.0 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glPopMatrix();
}


void MountainForest()
{


//Mountain Forests//*******************************
//4th Forest
    glBegin(GL_POLYGON);
    glColor3ub(67, 103, 126);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.0495381320471,-0.0605962800007);
    glVertex2f(0.2007153286505,-0.020341151271);
    glVertex2f(0.4427379444186,0.079029417574);
    glVertex2f(0.532644859892,0.0930773731167);
    glVertex2f(0.5878840146746,0.1278804610864);
    glVertex2f(0.7280410710124,0.135802381662);
    glVertex2f(0.8255416319431,0.1930839612088);
    glVertex2f(0.8881571014033,0.2715589807316);
    glVertex2f(0.95,0.3);
    glVertex2f(1,0.35);
    glVertex2f(1,-1);
    glEnd();
//3rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(76, 100, 115);
    glVertex2f(0.5205438541769,-0.0232772782295);
    glVertex2f(0.6879612259458,0.0486461694152);
    glVertex2f(0.7923235425046,0.0510180402461);
    glVertex2f(0.898267106284,0.0929210915917);
    glVertex2f(1,0.07);
    glVertex2f(1,-1);
    glVertex2f(0.68,-1);
    glEnd();
//2rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(36, 83, 115);
    glVertex2f(0.057107533847,-0.1203209192809);
    glVertex2f(0.057107533847,-0.1203209192809);
    glVertex2f(0.5205438541769,-0.0232772782295);
    glVertex2f(0.71856689755,-0.0435006178664);
    glVertex2f(0.8693954089044,-0.0490508612132);
    glVertex2f(1,-0.04);
    glVertex2f(1,-1);
    glVertex2f(0.42,-1);
    glVertex2f(-0.05,-1);
    glEnd();
//1st Forest
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-1,-1);
    glVertex2f(-1,0.3);
    glVertex2f(-0.9818789380332,0.3204266017963);
    glVertex2f(-0.8498381660267,0.2072781828038);
    glVertex2f(-0.8327052805765,0.1644459691783);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.8327052805765,0.1644459691783);
    glVertex2f(-0.6609836630438,0.1130680416116);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.5824784481087,0.0763478604323);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.0495381320471,-0.0605962800007);
    glVertex2f(-0.2036190238643,-0.0653130419951);
    glVertex2f(-0.5154958923208,0.0441953783772);
    glVertex2f(-0.5824784481087,0.0763478604323);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.05,-1);
    glVertex2f(0.42,-1);
    glVertex2f(0.4147327510621,-0.1913590727716);
    glVertex2f(0.2444733656041,-0.1329199639149);
    glVertex2f(0.0746699338056,-0.1140529159373);
    glVertex2f(-0.0495381320471,-0.0605962800007);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.42,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.2);
    glVertex2f(0.8256570560146,-0.2046760641358);
    glVertex2f(0.585951211459,-0.2122857734868);
    glVertex2f(0.4147327510621,-0.1913590727716);
    glEnd();
}


void BlueLake()
{
//Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(98, 167, 206);
    glVertex2f(1,-0.32);
    glVertex2f(-1,-0.32);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();
}


void Stone()
{

//Stone//*******************************
    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(-0.3544718150677,-0.9061478128671);
    glVertex2f(-0.32,-0.88);
    glVertex2f(-0.279812747796,-0.8882829353903);
    glVertex2f(-0.3147904587855,-0.9053345695897);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(-0.3147904587855,-0.9053345695897);
    glVertex2f(-0.279812747796,-0.8882829353903);
    glVertex2f(-0.2277834026991,-0.8782268434266);
    glVertex2f(-0.1700701795663,-0.9031484626411);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(0.7603149708665,-0.9561858394084);
    glVertex2f(0.7963944423714,-0.9323268339297);
    glVertex2f(0.8272365712384,-0.9375641765957);
    glVertex2f(0.8574967731458,-0.9567677663713);
    glEnd();
}


void TrainN()
{


//TrainN//*******************************
//TrainN Engine
    glPushMatrix();

    glTranslatef(-positionN,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0098910779337,-0.3415864917119);
    glVertex2f(1.0031891105663,-0.3415238565025);
    glVertex2f(1.0048176260014,-0.3360745932866);
    glVertex2f(1.0094508171327,-0.3360495004043);
    glVertex2f(1.0111437821145,-0.3383294608242);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0184721015724,-0.3382668256148);
    glVertex2f(1.0111437821145,-0.3383294608242);
    glVertex2f(1.0094508171327,-0.3360495004043);
    glVertex2f(1.0177427317828,-0.3359144585746);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0202885226345,-0.3416491269213);
    glVertex2f(1.0184721015724,-0.3382668256148);
    glVertex2f(1.0177427317828,-0.3359144585746);
    glVertex2f(1.0197248057532,-0.3358866876584);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0196943303373,-0.3330053522641);
    glVertex2f(1.0622827328597,-0.3328490531977);
    glVertex2f(1.0626752202786,-0.3347669566508);
    glVertex2f(1.057493836805,-0.334821889099);
    glVertex2f(1.0485370019121,-0.334821889099);
    glVertex2f(1.0430877387255,-0.334821889099);
    glVertex2f(1.0336298221603,-0.3347592538896);
    glVertex2f(1.0308112377535,-0.3415864917119);
    glVertex2f(1.0202885226345,-0.3416491269213);
    glVertex2f(1.0197248057532,-0.3358866876584);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0430877387255,-0.334821889099);
    glVertex2f(1.0485370019121,-0.334821889099);
    glVertex2f(1.0459689583414,-0.3402085171056);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 1, 1);
    glVertex2f(1.057493836805,-0.334821889099);
    glVertex2f(1.0603979681959,-0.3398418922259);
    glVertex2f(1.0626752202786,-0.3347669566508);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0622827328597,-0.3328490531977);
    glVertex2f(1.0898780710276,-0.3328586032972);
    glVertex2f(1.0898982419916,-0.3347914269528);
    glVertex2f(1.0885878493823,-0.3348093775366);
    glVertex2f(1.0709429795877,-0.3347669566508);
    glVertex2f(1.0626752202786,-0.3347669566508);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 1, 1);
    glVertex2f(1.0885878493823,-0.3348093775366);
    glVertex2f(1.0886019550463,-0.3415008736333);
    glVertex2f(1.0739704296049,-0.3415677393376);
    glVertex2f(1.0739564619528,-0.3373168263581);
    glVertex2f(1.0739564619528,-0.3373168263581);
    glVertex2f(1.0709429795877,-0.3347669566508);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0898780710276,-0.3328586032972);
    glVertex2f(1.0898020499935,-0.3174058403025);
    glVertex2f(1.0623273776143,-0.3174482449278);
    glVertex2f(1.0622827328597,-0.3328490531977);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0177427317828,-0.3359144585746);
    glVertex2f(1.0094508171327,-0.3360495004043);
    glVertex2f(1.0094645195481,-0.3331145612299);
    glVertex2f(1.0176863690847,-0.3330399609572);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.0104900243388,-0.3194340294909);
    glVertex2f(1.0104276841839,-0.3072509127323);
    glVertex2f(1.0156323508482,-0.3072698399406);
    glVertex2f(1.015710092674,-0.3194096837789);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(219, 162, 60);
    glVertex2f(1.0156323508482,-0.3072698399406);
    glVertex2f(1.0104276841839,-0.3072509127323);
    glVertex2f(1.0104217387347,-0.3060889954846);
    glVertex2f(1.015624788889,-0.3060889954846);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(219, 162, 60);
    glVertex2f(1.009221034853,-0.3036375583795);
    glVertex2f(1.0167254341139,-0.3036875877081);
    glVertex2f(1.015624788889,-0.3060889954846);
    glVertex2f(1.0104217387347,-0.3060889954846);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.0271249671621,-0.319466598631);
    glVertex2f(1.0246814218514,-0.3194301278053);
    glVertex2f(1.0247178926769,-0.3131206749541);
    glVertex2f(1.027052025511,-0.3130842041283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.0433929848875,-0.3194687783974);
    glVertex2f(1.0346439293974,-0.3193854393564);
    glVertex2f(1.0346818861351,-0.3102560320525);
    glVertex2f(1.0434096348236,-0.3102424374283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.0573784205303,-0.3194317364811);
    glVertex2f(1.0507993473203,-0.3193820830981);
    glVertex2f(1.0507993473203,-0.314888451938);
    glVertex2f(1.0573287671476,-0.314888451938);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0623186999797,-0.3194433057925);
    glVertex2f(1.0622827328597,-0.3328490531977);
    glVertex2f(1.0071535518213,-0.3330995902678);
    glVertex2f(1.0059222927478,-0.331589834331);

    glVertex2f(1.0058934754503,-0.3278217944749);
    glVertex2f(1.0059459470175,-0.3241837657988);
    glVertex2f(1.0059222927478,-0.3208465791155);
    glVertex2f(1.007162924654,-0.319418482296);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0058934754503,-0.3278217944749);
    glVertex2f(1.0049870767165,-0.3271883214221);
    glVertex2f(1.005,-0.325);
    glVertex2f(1.0059459470175,-0.3241837657988);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0281608356127,-0.3194486274053);
    glVertex2f(1.0285406858458,-0.3187617493781);
    glVertex2f(1.0325384655675,-0.3187192349283);
    glVertex2f(1.0328873016467,-0.3193854393564);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0450908459111,-0.3195146168997);
    glVertex2f(1.0454832507008,-0.3186941341532);
    glVertex2f(1.0493359522721,-0.3186941341532);
    glVertex2f(1.049942396038,-0.3193719242481);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(68, 66, 64);
    glVertex2f(1.0843158166231,-0.3173720661009);
    glVertex2f(1.0623273776143,-0.3174482449278);
    glVertex2f(1.0623755907957,-0.306480874804);
    glVertex2f(1.0842396834824,-0.3065071409486);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(68, 66, 64);
    glVertex2f(1.0856752219861,-0.3065071409486);
    glVertex2f(1.0608532588722,-0.3064718575209);
    glVertex2f(1.0608532588722,-0.3047419140986);
    glVertex2f(1.061796831841,-0.30395538117);
    glVertex2f(1.0847674754863,-0.3039967280852);
    glVertex2f(1.0856837923341,-0.3051128990856);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.0697812448398,-0.3154010738886);
    glVertex2f(1.0653218223721,-0.3154088201746);
    glVertex2f(1.0652573870146,-0.309021274357);
    glVertex2f(1.0697425793883,-0.309021274357);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(87, 87, 86);
    glVertex2f(1.0817678040379,-0.3314439588216);
    glVertex2f(1.0743106388263,-0.3313859659023);
    glVertex2f(1.0743399621193,-0.3103872488424);
    glVertex2f(1.075233073501,-0.3090599398088);
    glVertex2f(1.0809555603227,-0.3090599398088);
    glVertex2f(1.0819995275131,-0.3102972342634);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.0914265881104,-0.3305806976574);
    glVertex2f(1.0898547164848,-0.330620722504);
    glVertex2f(1.0898334455546,-0.3279716295793);
    glVertex2f(1.0914265881104,-0.32795869575);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 139, 150);
    glVertex2f(1.0916439904273,-0.3203255736099);
    glVertex2f(1.0898330385182,-0.3203777120259);
    glVertex2f(1.0898233922952,-0.3185095761605);
    glVertex2f(1.0916169141062,-0.3184780003505);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.0967420733951,-0.34141590784);
    glVertex2f(1.0886019550463,-0.3415008736333);
    glVertex2f(1.0885985286555,-0.3398754499156);
    glVertex2f(1.0967420733951,-0.3398628181353);
    glEnd();
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);
    x=1.0147045394483;
    y=-0.3431020496611;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0147045394483;
    y=-0.3431020496611;
    radiusN =0.00215;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    x=1.0147045394483;
    y=-0.3431020496611;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for( float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0384885885324;
    y=-0.3412683237308;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for( float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0384885885324;
    y=-0.3412683237308;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for( float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0531048883341;
    y=-0.3412683237308;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0531048883341;
    y=-0.3412683237308;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//4th Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0674691829668;
    y=-0.341394326316;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for( float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0674691829668;
    y=-0.341394326316;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//Coal Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1113223885496;
    y=-0.3422454148682;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1113223885496;
    y=-0.3422454148682;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1364549333457;
    y=-0.3422279668657;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1364549333457;
    y=-0.3422279668657;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1615249078393;
    y=-0.3422279668657;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1615249078393;
    y=-0.3422279668657;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1039526896977,-0.3413710805488);
    glVertex2f(1.0967420733951,-0.34141590784);
    glVertex2f(1.0967420733951,-0.3398628181353);
    glVertex2f(1.1023431179662,-0.3398852085333);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1039526896977,-0.3413710805488);
    glVertex2f(1.1023431179662,-0.3398852085333);
    glVertex2f(1.1023205367962,-0.3379964775326);
    glVertex2f(1.104,-0.338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1156560277489,-0.3403107511918);
    glVertex2f(1.1069333275813,-0.3402902185074);
    glVertex2f(1.1070332512372,-0.3374847992105);
    glVertex2f(1.1156560277489,-0.3374123389033);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1209762029526,-0.3418148735559);
    glVertex2f(1.1174454228592,-0.3417747510547);
    glVertex2f(1.117431305266,-0.3376659499785);
    glVertex2f(1.1209818603002,-0.3376297198249);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1405976554239,-0.34002257777);
    glVertex2f(1.132,-0.34);
    glVertex2f(1.1319628785559,-0.3368643325172);
    glVertex2f(1.1405897130209,-0.3367983244245);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1657662457085,-0.3400580746755);
    glVertex2f(1.1574163015897,-0.3400983654464);
    glVertex2f(1.1574648285564,-0.3371867474258);
    glVertex2f(1.1657493359854,-0.3371720829414);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 106, 107);
    glVertex2f(1.1732827396309,-0.3397104711472);
    glVertex2f(1.1715438648613,-0.3412076845117);
    glVertex2f(1.1715319266551,-0.3368160389016);
    glVertex2f(1.1732946828541,-0.336794800875);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(1.1187589056951,-0.3189047665993);
    glVertex2f(1.1367747195501,-0.3132981854938);
    glVertex2f(1.1577059555643,-0.3188300121845);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.0984064660773,-0.318406769825);
    glVertex2f(1.1766644732027,-0.3184063848784);
    glVertex2f(1.1765727487197,-0.3369581180438);
    glVertex2f(1.1758818540264,-0.3384062305431);
    glVertex2f(1.099217255021,-0.3386764935257);
    glVertex2f(1.0984064660773,-0.3371450032906);
    glEnd();
//1st Passenger Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1983735010497;
    y=-0.3424054537282;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1983735010497;
    y=-0.3424054537282;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.2248014730928;
    y=-0.3424054537282;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.2248014730928;
    y=-0.3424054537282;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1615249078393;
    y=-0.3422279668657;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.2512294451359;
    y=-0.3422726498479;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.185,-0.317);
    glVertex2f(1.1848818731574,-0.337158680073);
    glVertex2f(1.1856813186551,-0.3382940036579);
    glVertex2f(1.2659833441513,-0.3378991482825);
    glVertex2f(1.2666756069893,-0.3369218765052);
    glVertex2f(1.2668087575179,-0.3169893303632);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107);
    glVertex2f(1.183,-0.317);
    glVertex2f(1.183,-0.3135);
    glVertex2f(1.1842794650564,-0.3124096202959);
    glVertex2f(1.2666250580063,-0.3123102098959);
    glVertex2f(1.268,-0.3135);
    glVertex2f(1.268,-0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.1875,-0.3195);
    glVertex2f(1.197,-0.3195);
    glVertex2f(1.197,-0.329);
    glVertex2f(1.1875,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2015,-0.3195);
    glVertex2f(1.2105,-0.3195);
    glVertex2f(1.2105,-0.329);
    glVertex2f(1.2015,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2155,-0.3195);
    glVertex2f(1.2245,-0.3195);
    glVertex2f(1.2245,-0.329);
    glVertex2f(1.2155,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.229,-0.3195);
    glVertex2f(1.2385,-0.3195);
    glVertex2f(1.2385,-0.329);
    glVertex2f(1.229,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.243,-0.3195);
    glVertex2f(1.2525,-0.3195);
    glVertex2f(1.2525,-0.329);
    glVertex2f(1.243,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(1.258,-0.32);
    glVertex2f(1.2635,-0.32);
    glVertex2f(1.2635005300548,-0.3379113565984);
    glVertex2f(1.257999697129,-0.3379384049005);
    glEnd();
//2nd Passenger Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.289344158585;
    y=-0.3424054537282;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.289344158585;
    y=-0.3424054537282;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.3157721306281;
    y=-0.3424054537282;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.3157721306281;
    y=-0.3424054537282;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.3419344949119;
    y=-0.3425382576085;
    radiusN =0.00415;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.3419344949119;
    y=-0.3425382576085;
    radiusN =0.00315;
    twicePiN = 2 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(44, 62, 80);
    glVertex2f(1.2768,-0.338);
    glVertex2f(1.2757,-0.337);
    glVertex2f(1.2756,-0.317);
    glVertex2f(1.3575,-0.317);
    glVertex2f(1.3575,-0.337);
    glVertex2f(1.3565,-0.338);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(97, 106, 107);
    glVertex2f(1.2735,-0.317);
    glVertex2f(1.2735,-0.314);
    glVertex2f(1.275,-0.3125);
    glVertex2f(1.3578,-0.3124);
    glVertex2f(1.3592,-0.3138);
    glVertex2f(1.3592,-0.317);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2785,-0.32);
    glVertex2f(1.2875,-0.32);
    glVertex2f(1.2875,-0.329);
    glVertex2f(1.2785,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.2925,-0.32);
    glVertex2f(1.3015,-0.32);
    glVertex2f(1.3015,-0.329);
    glVertex2f(1.2925,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.3065,-0.32);
    glVertex2f(1.315,-0.32);
    glVertex2f(1.315,-0.329);
    glVertex2f(1.3065,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.32,-0.32);
    glVertex2f(1.329,-0.32);
    glVertex2f(1.329,-0.329);
    glVertex2f(1.32,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(208, 211, 212);
    glVertex2f(1.334,-0.32);
    glVertex2f(1.343,-0.32);
    glVertex2f(1.343,-0.329);
    glVertex2f(1.334,-0.329);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 86);
    glVertex2f(1.348,-0.32);
    glVertex2f(1.355,-0.32);
    glVertex2f(1.355,-0.338);
    glVertex2f(1.348,-0.338);
    glEnd();

    glPopMatrix();
}


void TrainNBridge()
{

//TrainN Bridge//*******************************
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.0440668723581,-0.3441688569231);
    glVertex2f(0.6450787052674,-0.3441688569231);
    glVertex2f(0.6450787052674,-0.3616768441801);
    glVertex2f(-0.0440668723581,-0.3616768441801);
    glEnd();
//1st Pillar
    glBegin(GL_POLYGON);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.0440668723581,-0.3612137790339);
    glVertex2f(-0.0378932498522,-0.3621862352261);
    glVertex2f(-0.0314310662387,-0.3649361006084);
    glVertex2f(-0.0088403016837,-0.3645815473344);
    glVertex2f(-0.0015143448965,-0.3612423718204);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.0314310662387,-0.3649361006084);
    glVertex2f(-0.0282687210661,-0.3696108717583);
    glVertex2f(-0.0126559641036,-0.3696182217559);
    glVertex2f(-0.0088403016837,-0.3645815473344);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.0282687210661,-0.3696108717583);
    glVertex2f(-0.0126559641036,-0.3696108717583);
    glVertex2f(-0.0126559641036,-0.4795384214053);
    glVertex2f(-0.0282687210661,-0.4795384214053);
    glEnd();
//2nd Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(-0.0015143448965,-0.361242371820);
    glVertex2f(0.0059644685056,-0.3644289208368);
    glVertex2f(0.0295999067492,-0.3639798131217);
    glVertex2f(0.036696117031,-0.3612382706053);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.0059644685056,-0.3644289208368);
    glVertex2f(0.0295999067492,-0.3639798131217);
    glVertex2f(0.025967631411,-0.369883706095);
    glVertex2f(0.01,-0.37);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.01,-0.37);
    glVertex2f(0.025967631411,-0.37);
    glVertex2f(0.0264373758514,-0.4798039057445);
    glVertex2f(0.01,-0.4798039057445);
    glEnd();
//3rd Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.036696117031,-0.3612382706053);
    glVertex2f(0.0448622950273,-0.364218828234);
    glVertex2f(0.068296424165,-0.3649559974619);
    glVertex2f(0.0756225977328,-0.3612942032922);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.0448622950273,-0.364218828234);
    glVertex2f(0.068296424165,-0.3649559974619);
    glVertex2f(0.0644807617451,-0.3699926718834);
    glVertex2f(0.0486644380211,-0.369521817175);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.0486644380211,-0.369521817175);
    glVertex2f(0.0644807617451,-0.369521817175);
    glVertex2f(0.0644807617451,-0.4790086781139);
    glVertex2f(0.0486644380211,-0.4790086781139);
    glEnd();
//4th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.0756225977328,-0.3612942032922);
    glVertex2f(0.0831011943543,-0.3648033709643);
    glVertex2f(0.1059048466009,-0.3653211277788);
    glVertex2f(0.1132312485342,-0.3613194740854);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.0831011943543,-0.3648033709643);
    glVertex2f(0.1059048466009,-0.3653211277788);
    glVertex2f(0.1020891841809,-0.3703578022002);
    glVertex2f(0.0871367258487,-0.3703744501275);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.0871367258487,-0.3703744501275);
    glVertex2f(0.1020891841809,-0.3703744501275);
    glVertex2f(0.1020891841809,-0.4790086781139);
    glVertex2f(0.0871367258487,-0.4790086781139);
    glEnd();
//5th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1132312485342,-0.3613194740854);
    glVertex2f(0.1207096167901,-0.3651685012812);
    glVertex2f(0.1434604989179,-0.3651987518491);
    glVertex2f(0.1507868016653,-0.3613447092002);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1207096167901,-0.3651685012812);
    glVertex2f(0.1434604989179,-0.3651987518491);
    glVertex2f(0.139644836498,-0.3707395804444);
    glVertex2f(0.1247451482845,-0.3707395804444);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1247451482845,-0.3707395804444);
    glVertex2f(0.139644836498,-0.3707395804444);
    glVertex2f(0.139644836498,-0.48015562592);
    glVertex2f(0.1247451482845,-0.48015562592);
    glEnd();
//6th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1507868016653,-0.3613447092002);
    glVertex2f(0.1582652691071,-0.3650461253515);
    glVertex2f(0.1809136342031,-0.3654427462171);
    glVertex2f(0.18824008399,-0.3613698755949);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1582652691071,-0.3650461253515);
    glVertex2f(0.1809136342031,-0.3654427462171);
    glVertex2f(0.1770979717832,-0.3706172045147);
    glVertex2f(0.1623008006016,-0.3706172045147);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1623008006016,-0.3706172045147);
    glVertex2f(0.1770979717832,-0.3706172045147);
    glVertex2f(0.1770979717832,-0.480399620288);
    glVertex2f(0.1623008006016,-0.480399620288);
    glEnd();
//7th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.18824008399,-0.3613698755949);
    glVertex2f(0.1957184043924,-0.3652901197195);
    glVertex2f(0.219425340818,-0.3656397370448);
    glVertex2f(0.2267519055829,-0.3613957532656);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1957184043924,-0.3652901197195);
    glVertex2f(0.219425340818,-0.3656397370448);
    glVertex2f(0.2156096783981,-0.3708611988827);
    glVertex2f(0.1997539358868,-0.3708611988827);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.1997539358868,-0.3708611988827);
    glVertex2f(0.2156096783981,-0.3708611988827);
    glVertex2f(0.2156096783981,-0.4805966111158);
    glVertex2f(0.1997539358868,-0.4805966111158);
    glEnd();
//8th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.2267519055829,-0.3613957532656);
    glVertex2f(0.2342301110073,-0.3654871105472);
    glVertex2f(0.2575815511521,-0.3653652689414);
    glVertex2f(0.264907914263,-0.361421391851);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.2342301110073,-0.3654871105472);
    glVertex2f(0.2575815511521,-0.3653652689414);
    glVertex2f(0.2537658887322,-0.3710581897104);
    glVertex2f(0.2382656425017,-0.3710581897104);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.2382656425017,-0.3710581897104);
    glVertex2f(0.2537658887322,-0.3710581897104);
    glVertex2f(0.2537658887322,-0.4803221430124);
    glVertex2f(0.2382656425017,-0.4803221430124);
    glEnd();
//9th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.264907914263,-0.361421391851);
    glVertex2f(0.2723863213414,-0.3652126424438);
    glVertex2f(0.2962449768968,-0.3653658173618);
    glVertex2f(0.3035713229195,-0.3614473713792);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.2723863213414,-0.3652126424438);
    glVertex2f(0.2962449768968,-0.3653658173618);
    glVertex2f(0.2924293144769,-0.370783721607);
    glVertex2f(0.2764218528358,-0.370783721607);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.2764218528358,-0.370783721607);
    glVertex2f(0.2924293144769,-0.370783721607);
    glVertex2f(0.2924293144769,-0.4803226914328);
    glVertex2f(0.2764218528358,-0.4803226914328);
    glEnd();
//10th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3035713229195,-0.3614473713792);
    glVertex2f(0.3110497470861,-0.3652131908642);
    glVertex2f(0.333100872547,-0.3657179437553);
    glVertex2f(0.3404274385371,-0.3614721365132);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3110497470861,-0.3652131908642);
    glVertex2f(0.333100872547,-0.3657179437553);
    glVertex2f(0.3292852101271,-0.3707842700274);
    glVertex2f(0.3150852785805,-0.3707842700274);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3150852785805,-0.3707842700274);
    glVertex2f(0.3292852101271,-0.3707842700274);
    glVertex2f(0.3292852101271,-0.4806748178262);
    glVertex2f(0.3150852785805,-0.4806748178262);
    glEnd();
//11th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3404274385371,-0.3614721365132);
    glVertex2f(0.3479056427362,-0.3655653172577);
    glVertex2f(0.3715067314129,-0.3654779071361);
    glVertex2f(0.3788331187723,-0.3614979428631);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3479056427362,-0.3655653172577);
    glVertex2f(0.3715067314129,-0.3654779071361);
    glVertex2f(0.367691068993,-0.3711363964209);
    glVertex2f(0.3519411742306,-0.3711363964209);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3519411742306,-0.3711363964209);
    glVertex2f(0.367691068993,-0.3711363964209);
    glVertex2f(0.367691068993,-0.480434781207);
    glVertex2f(0.3519411742306,-0.480434781207);
    glEnd();
//12th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3788331187723,-0.3614979428631);
    glVertex2f(0.3863115016022,-0.3653252806384);
    glVertex2f(0.4088500538522,-0.3658917177252);
    glVertex2f(0.4165344998342,-0.3615232759656);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.3863115016022,-0.3653252806384);
    glVertex2f(0.4088500538522,-0.3658917177252);
    glVertex2f(0.4053913104301,-0.3722359339798);
    glVertex2f(0.3903470330966,-0.3708963598017);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.390816777537,-0.3708963598017);
    glVertex2f(0.4058610548705,-0.3708963598017);
    glVertex2f(0.4058610548705,-0.4821561336293);
    glVertex2f(0.390816777537,-0.4821561336293);
    glEnd();
//13th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4165344998342,-0.3615232759656);
    glVertex2f(0.4250972405587,-0.3657540297015);
    glVertex2f(0.4472650122516,-0.3657540297015);
    glVertex2f(0.4560475696049,-0.3615498264159);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4250972405587,-0.3657540297015);
    glVertex2f(0.4472650122516,-0.3657540297015);
    glVertex2f(0.4449043805309,-0.372617712224);
    glVertex2f(0.4280472745336,-0.372617712224);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4280472745336,-0.372617712224);
    glVertex2f(0.4449043805309,-0.372617712224);
    glVertex2f(0.4449043805309,-0.4821821927591);
    glVertex2f(0.4280472745336,-0.4821821927591);
    glEnd();
//14th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4560475696049,-0.3615498264159);
    glVertex2f(0.4642006390728,-0.3660294057488);
    glVertex2f(0.4823754581004,-0.3661670937725);
    glVertex2f(0.4904927966213,-0.3615729715751);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4642006390728,-0.3660294057488);
    glVertex2f(0.4823754581004,-0.3661670937725);
    glVertex2f(0.4793495098078,-0.3726437713537);
    glVertex2f(0.4675603446345,-0.3726437713537);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4675603446345,-0.3726437713537);
    glVertex2f(0.4793495098078,-0.3726437713537);
    glVertex2f(0.4793495098078,-0.4823507963921);
    glVertex2f(0.4675603446345,-0.4823507963921);
    glEnd();
//15th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.4904927966213,-0.3615729715751);
    glVertex2f(0.502,-0.3658917177252);
    glVertex2f(0.5203113860517,-0.3665933872299);
    glVertex2f(0.5280573351609,-0.3615982127274);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.502,-0.3658917177252);
    glVertex2f(0.5203113860517,-0.3665933872299);
    glVertex2f(0.5169138317764,-0.3727781444667);
    glVertex2f(0.5020054739114,-0.3727781444667);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.502,-0.3727781444667);
    glVertex2f(0.5169138317764,-0.3727781444667);
    glVertex2f(0.5169138317764,-0.4826983441162);
    glVertex2f(0.502,-0.4827325746362);
    glEnd();

//16th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.5280573351609,-0.3615982127274);
    glVertex2f(0.5371520152124,-0.3664764384157);
    glVertex2f(0.5586705969177,-0.3664764384157);
    glVertex2f(0.5674603309078,-0.3616246892145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.5371520152124,-0.3664764384157);
    glVertex2f(0.5586705969177,-0.3664764384157);
    glVertex2f(0.5563167265713,-0.3731599227108);
    glVertex2f(0.53956979588,-0.3731599227108);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.53956979588,-0.3731599227108);
    glVertex2f(0.5563167265713,-0.3731599227108);
    glVertex2f(0.5563167265713,-0.4828750600282);
    glVertex2f(0.53956979588,-0.4828750600282);
    glEnd();
//17th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.5674603309078,-0.3616246892145);
    glVertex2f(0.57621291896,-0.3663594896014);
    glVertex2f(0.5973806542245,-0.3663594896014);
    glVertex2f(0.6057339686366,-0.3616504068397);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.57621291896,-0.3663594896014);
    glVertex2f(0.5973806542245,-0.3663594896014);
    glVertex2f(0.5945903815808,-0.3733366386228);
    glVertex2f(0.5789726906748,-0.3733366386228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.5789726906748,-0.3733366386228);
    glVertex2f(0.5945903815808,-0.3733366386228);
    glVertex2f(0.5945903815808,-0.4828750600282);
    glVertex2f(0.5789726906748,-0.4828750600282);
    glEnd();

//18th Pillar
    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.6057339686366,-0.3616504068397);
    glVertex2f(0.614572129826,-0.3664764384157);
    glVertex2f(0.6353320612778,-0.3675380496472);
    glVertex2f(0.6450787052674,-0.3616768441801);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.614572129826,-0.3664764384157);
    glVertex2f(0.6353320612778,-0.3675380496472);
    glVertex2f(0.6335151352462,-0.3733366386228);
    glVertex2f(0.6172463456844,-0.3733366386228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 70, 89);
    glVertex2f(0.6172463456844,-0.3733366386228);
    glVertex2f(0.6335151352462,-0.3733366386228);
    glVertex2f(0.6335151352462,-0.4823033854072);
    glVertex2f(0.6172463456844,-0.4823033854072);
    glEnd();
}


void SideOfBlueLake()
{

//Sides of Blue Lake//*******************************
//Land
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-1,-1);
    glVertex2f(-0.8995326838053,-0.8862946528133);
    glVertex2f(-0.4362938071669,-0.9407676558111);
    glVertex2f(-0.1420660594122,-0.9861603438344);
    glVertex2f(0.06,-1);
    glEnd();
//Fence
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.4531309070236,-0.9404753650012);
    glVertex2f(-0.4536818778689,-0.9145797351297);
    glVertex2f(-0.4497282134211,-0.9124077362292);
    glVertex2f(-0.4419908653743,-0.9124077362292);
    glVertex2f(-0.4432134318071,-0.9407508504254);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.3479972047922,-0.9610623275462);
    glVertex2f(-0.3485933474059,-0.9143610101306);
    glVertex2f(-0.3444319968592,-0.9120106178223);
    glVertex2f(-0.3366744887868,-0.9123859811182);
    glVertex2f(-0.3364125631161,-0.9627034851258);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.215859374447,-0.982412890742);
    glVertex2f(-0.2161002194582,-0.9225615532161);
    glVertex2f(-0.212098889515,-0.9195836996522);
    glVertex2f(-0.2048130896326,-0.9198113808997);
    glVertex2f(-0.2054527222909,-0.982412890742);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.1021750530674,-0.9904614794253);
    glVertex2f(-0.102474503832,-0.9227856062677);
    glVertex2f(-0.0979158025979,-0.9202329488075);
    glVertex2f(-0.0910953747784,-0.9203900001382);
    glVertex2f(-0.0910953747784,-0.9913598317238);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.0209220219971,-0.9975833227217);
    glVertex2f(0.021602706167,-0.9399058605652);
    glVertex2f(0.0251999982919,-0.9369957032194);
    glVertex2f(0.0324605585193,-0.9369957032194);
    glVertex2f(0.0327255323846,-0.9981964920958);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.135,-1);
    glVertex2f(0.1350948708408,-0.9471993450333);
    glVertex2f(0.1386462564159,-0.9450907098367);
    glVertex2f(0.1464149123615,-0.9452016906366);
    glVertex2f(0.1465,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.259,-1);
    glVertex2f(0.2590692604552,-0.9545380836445);
    glVertex2f(0.2628517458507,-0.9521363786927);
    glVertex2f(0.2705642021141,-0.9523518104331);
    glVertex2f(0.2706,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.383,-1);
    glVertex2f(0.3828991373824,-0.9688705455124);
    glVertex2f(0.3865754050403,-0.9668356281355);
    glVertex2f(0.3937492004937,-0.9670377068818);
    glVertex2f(0.394,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.512,-1);
    glVertex2f(0.5122971841648,-0.9559659477345);
    glVertex2f(0.5160561385148,-0.953398856945);
    glVertex2f(0.5237574108414,-0.9533071751311);
    glVertex2f(0.5237,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.632,-1);
    glVertex2f(0.6321289026866,-0.9562050628171);
    glVertex2f(0.6359748185605,-0.9534080330755);
    glVertex2f(0.6434918359504,-0.9534954402549);
    glVertex2f(0.6435,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.7768,-1);
    glVertex2f(0.7767659672957,-0.976674443077);
    glVertex2f(0.78,-0.975);
    glVertex2f(0.7876172270879,-0.9749347091225);
    glVertex2f(0.788,-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.4698521271451,-0.9258365384557);
    glVertex2f(-0.4699186614649,-0.9193418854794);
    glVertex2f(-0.3428929959411,-0.9223168793538);
    glVertex2f(-0.3423901875007,-0.9318702397732);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.3423901875007,-0.9318702397732);
    glVertex2f(-0.3428929959411,-0.9223168793538);
    glVertex2f(-0.2106543761129,-0.9338814735457);
    glVertex2f(-0.2101515676724,-0.9424292170789);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.2101515676724,-0.9424292170789);
    glVertex2f(-0.2106543761129,-0.9338814735457);
    glVertex2f(-0.0967682643596,-0.9353898988751);
    glVertex2f(-0.0967682643596,-0.9451946635161);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.0967682643596,-0.9451946635161);
    glVertex2f(-0.0967682643596,-0.9353898988751);
    glVertex2f(0.0271740162019,-0.9497199395042);
    glVertex2f(0.0276768246423,-0.9587704914804);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.0276768246423,-0.9587704914804);
    glVertex2f(0.0271740162019,-0.9497199395042);
    glVertex2f(0.141175315667,-0.9579907204262);
    glVertex2f(0.141175315667,-0.9661397002348);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.141175315667,-0.9661397002348);
    glVertex2f(0.141175315667,-0.9579907204262);
    glVertex2f(0.2651903072916,-0.970849508359);
    glVertex2f(0.2652869628246,-0.9809901655811);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.2652869628246,-0.9809901655811);
    glVertex2f(0.2651903072916,-0.970849508359);
    glVertex2f(0.3877528167803,-0.9798046790301);
    glVertex2f(0.3882845258769,-0.9917681337673);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.3882845258769,-0.9917681337673);
    glVertex2f(0.3877528167803,-0.9798046790301);
    glVertex2f(0.5177124830437,-0.9752768088617);
    glVertex2f(0.5179821775134,-0.9866039766509);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.5179821775134,-0.9866039766509);
    glVertex2f(0.5177124830437,-0.9752768088617);
    glVertex2f(0.6380697699206,-0.9735963395397);
    glVertex2f(0.6380697699206,-0.9820818768043);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.6380697699206,-0.9820818768043);
    glVertex2f(0.6380697699206,-0.9735963395397);
    glVertex2f(0.7822915445925,-0.9882859733205);
    glVertex2f(0.782622460508,-0.9978825349236);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(0.782622460508,-0.9978825349236);
    glVertex2f(0.7822915445925,-0.9882859733205);
    glVertex2f(0.88,-1);
    glVertex2f(0.793,-1);
    glEnd();
//Dark Rock
    glBegin(GL_POLYGON);
    glColor3ub(41, 54, 62);
    glVertex2f(-1,-1);
    glVertex2f(-0.8995326838053,-0.8862946528133);
    glVertex2f(-0.7632128497935,-0.8615092283138);
    glVertex2f(-0.4699186614649,-0.9193418854794);
    glVertex2f(-0.365,-1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.2101515676724,-0.9424292170789);
    glVertex2f(-0.2106543761129,-0.9338814735457);
    glVertex2f(-0.3428929959411,-0.9223168793538);
    glVertex2f(-0.3423901875007,-0.9318702397732);
    glEnd();

//1st Side Forest of Blue Lake
    glBegin(GL_POLYGON);
    glColor3ub(20, 77, 110);
    glVertex2f(-1,-0.4482623769432);
    glVertex2f(0.08032289841543,-0.4482623769432);
    glVertex2f(-0.1320390596915,-0.2541253303839);
    glVertex2f(-0.4734288362521,-0.2041253303839);
    glVertex2f(-0.6594300061514,-0.1800843628459);
    glVertex2f(-0.8707374576695,-0.1408596263365);
    glVertex2f(-1,-0.11);
    glEnd();

//2st Side Forest of Blue Lake
    glBegin(GL_POLYGON);
    glColor3ub(20, 77, 110);
    glVertex2f(0.5422429702315,-0.4482623769432);
    glVertex2f(0.607145421979,-0.3349593212472);
    glVertex2f(0.8327249542509,-0.2174623167401);
    glVertex2f(0.8369149833822,-0.4482623769432);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(20, 77, 110);
    glVertex2f(0.8327249542509,-0.2174623167401);
    glVertex2f(0.8359102149068,-0.2072473867747);
    glVertex2f(0.9996368118879,-0.1695879140117);
    glVertex2f(1.0000691863567,-0.4482623769432);
    glVertex2f(0.8369149833822,-0.4482623769432);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(20, 77, 110);
    glVertex2f(0.8359102149068,-0.2072473867747);
    glVertex2f(0.8188751805996,-0.1846506759137);
    glVertex2f(0.8157897474026,-0.1630526435341);
    glVertex2f(0.8260745247262,-0.1385748735038);
    glVertex2f(0.8532263368606,-0.1385748735038);

    glVertex2f(0.8914857085046,-0.1389862645967);
    glVertex2f(0.9188432161855,-0.1315812249237);
    glVertex2f(1,-0.11);
    glVertex2f(0.9996368118879,-0.1695879140117);
    glEnd();
}


void CoverBridge()
{

//Cover Bridge Using Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(98, 167, 206);
    glVertex2f(-0.08032289841543,-0.4482623769432);
    glVertex2f(0.8422429702315,-0.4482623769432);
    glVertex2f(0.8422429702315,-0.8482623769432);
    glVertex2f(-0.08032289841543,-0.8482623769432);
    glEnd();

    glPushMatrix();
    glTranslatef(-positionN3, 0,0);
}

void FishingBoat()
{


//Fishing Boat//*******************************
//Boat
    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.4960047335224,-0.8907374682157);
    glVertex2f(0.4965047335224,-0.8887374682157);
    glVertex2f(0.4940047335224,-0.8862374682157);
    glVertex2f(0.4922047335224,-0.8882374682157);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5140047335224,-0.9112374682157);
    glVertex2f(0.5150047335224,-0.8962374682157);
    glVertex2f(0.5050047335224,-0.8947374682157);
    glVertex2f(0.4980047335224,-0.8922374682157);
    glVertex2f(0.4922047335224,-0.8882374682157);
    glVertex2f(0.4920047335224,-0.8902374682157);
    glVertex2f(0.4930047335224,-0.8932374682157);
    glVertex2f(0.4969286807635,-0.9001604360224);
    glVertex2f(0.5000047335224,-0.9042374682157);
    glVertex2f(0.5050047335224,-0.9102374682157);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5140047335224,-0.9112374682157);
    glVertex2f(0.5150047335224,-0.8962374682157);
    glVertex2f(0.5350047335224,-0.8987374682157);
    glVertex2f(0.5540047335224,-0.8992374682157);
    glVertex2f(0.5750047335224,-0.8987374682157);
    glVertex2f(0.5690047335224,-0.9127374682157);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5690047335224,-0.9127374682157);
    glVertex2f(0.5750047335224,-0.8987374682157);
    glVertex2f(0.5850047335224,-0.8977374682157);
    glVertex2f(0.5950928110227,-0.8957331036198);
    glVertex2f(0.6050047335224,-0.8922374682157);
    glVertex2f(0.5770047335224,-0.9127374682157);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5770047335224,-0.9127374682157);
    glVertex2f(0.6075047335224,-0.8902374682157);
    glVertex2f(0.6110047335224,-0.8902374682157);
    glVertex2f(0.6110047335224,-0.8942374682157);
    glVertex2f(0.6090047335224,-0.9002374682157);
    glVertex2f(0.6050047335224,-0.9052374682157);
    glVertex2f(0.6000047335224,-0.9102374682157);
    glVertex2f(0.5950047335224,-0.9122374682157);
    glVertex2f(0.5850047335224,-0.9127374682157);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.6075047335224,-0.8902374682157);
    glVertex2f(0.6080047335224,-0.8892374682157);
    glVertex2f(0.6080047335224,-0.8877374682157);
    glVertex2f(0.6090047335224,-0.8877374682157);
    glVertex2f(0.6100047335224,-0.8882374682157);
    glVertex2f(0.6110047335224,-0.8902374682157);
    glEnd();
//Human
    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5429740159476,-0.89964980459);
    glVertex2f(0.5387818595593,-0.899615996877);
    glVertex2f(0.5385432695613,-0.8948256967017);
    glVertex2f(0.5375821555006,-0.8931170494735);
    glVertex2f(0.5425492865391,-0.8895447300209);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5438536468766,-0.8799885452611);
    glVertex2f(0.5442665811533,-0.8827471054697);
    glVertex2f(0.5430501641349,-0.884893723749);
    glVertex2f(0.5425492865391,-0.8895447300209);
    glVertex2f(0.5375821555006,-0.8931170494735);
    glVertex2f(0.5372083889214,-0.8871901794005);
    glVertex2f(0.5359802987327,-0.8843602324288);
    glVertex2f(0.5359715825779,-0.8806581315829);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5438536468766,-0.8799885452611);
    glVertex2f(0.5359715825779,-0.8806581315829);
    glVertex2f(0.535385498484,-0.8791358726558);
    glVertex2f(0.5353442624265,-0.8756531661676);
    glVertex2f(0.5357939622044,-0.8727130333831);
    glVertex2f(0.5370249615208,-0.8707199868601);
    glVertex2f(0.5388718373115,-0.8667842466625);
    glVertex2f(0.5427267902418,-0.8659364878528);
    glVertex2f(0.5452365522725,-0.873017127075);
    glVertex2f(0.5462741181636,-0.8795479612597);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5388718373115,-0.8667842466625);
    glVertex2f(0.537930397303,-0.864139248529);
    glVertex2f(0.5418843707017,-0.8631005100947);
    glVertex2f(0.5427267902418,-0.8659364878528);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5418843707017,-0.8631005100947);
    glVertex2f(0.537930397303,-0.864139248529);
    glVertex2f(0.5364958220518,-0.8641840790058);
    glVertex2f(0.535986398889,-0.8619990044059);
    glVertex2f(0.5362849011686,-0.8608476384643);
    glVertex2f(0.5348427165007,-0.8592813077956);
    glVertex2f(0.537349067996,-0.8583861822567);
    glVertex2f(0.538840943886,-0.8573120316101);

    glVertex2f(0.5402731447405,-0.8569539813946);
    glVertex2f(0.5426601461646,-0.8585055323286);
    glVertex2f(0.5430778714138,-0.8601167582985);
    glVertex2f(0.5424214460221,-0.8616683092325);
    glEnd();
//Fishing Pol
    glBegin(GL_QUADS);
    glColor3ub(36, 74, 100);
    glVertex2f(0.5356103175801,-0.8790514367252);
    glVertex2f(0.4905603186981,-0.8462026032679);
    glVertex2f(0.4901422709834,-0.8438589215045);
    glVertex2f(0.5355518880458,-0.8775417279859);
    glEnd();

}



void sunset()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    WeatherN();
    StarsN();
    MoonN();
    MountainForest();
    BlueLake();
    Stone();
    TrainN();
    TrainNBridge();
    SideOfBlueLake();
    CoverBridge();
    FishingBoat();

    glPopMatrix();
    glFlush();
}

void WeatherNN()
{


//WeatherN//*******************************
    glBegin(GL_POLYGON);
    glColor3ub(0, 24, 111);
    glVertex2f(-1,1);
    glVertex2f(-0.5,1);
    glVertex2f(0,1);
    glVertex2f(0.5,1);
    glVertex2f(1,1);
    glVertex2f(1,0.5);
    glVertex2f(1,0);
    glVertex2f(1,-0.5);

    glColor3ub(23, 91, 191);
    glVertex2f(1,-1);
    glVertex2f(0.5,-1);
    glVertex2f(0,-1);
    glVertex2f(-0.5,-1);
    glVertex2f(-1,-1);
    glVertex2f(-1,-0.5);
    glVertex2f(-1,0);
    glVertex2f(-1,0.5);
    glEnd();
}

void MoonNN()
{


//MoonN//*******************************
    glPushMatrix();
    glTranslatef(positionN2,-positionN2,0);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=0.5;
    y=0.7;
    radiusN =0.1;
    twicePiN = -1.5 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 24, 111);

    x=0.525;
    y=0.72;
    radiusN =0.1;
    twicePiN = 2.0 * PI;

    glVertex2f(x, y);
    for(float i = 0; i <= triangleAmountN;i++)
    {
        glVertex2f(x + (radiusN * cos(i *  twicePiN / triangleAmountN)), y + (radiusN * sin(i * twicePiN / triangleAmountN)));
    }
    glEnd();

    glPopMatrix();
}

void MountainForestN()
{


//Mountain Forests//*******************************
//4th Forest
    glBegin(GL_POLYGON);
    glColor3ub(67, 103, 126);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.0495381320471,-0.0605962800007);
    glVertex2f(0.2007153286505,-0.020341151271);
    glVertex2f(0.4427379444186,0.079029417574);
    glVertex2f(0.532644859892,0.0930773731167);
    glVertex2f(0.5878840146746,0.1278804610864);
    glVertex2f(0.7280410710124,0.135802381662);
    glVertex2f(0.8255416319431,0.1930839612088);
    glVertex2f(0.8881571014033,0.2715589807316);
    glVertex2f(0.95,0.3);
    glVertex2f(1,0.35);
    glVertex2f(1,-1);
    glEnd();
//3rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(76, 100, 115);
    glVertex2f(0.5205438541769,-0.0232772782295);
    glVertex2f(0.6879612259458,0.0486461694152);
    glVertex2f(0.7923235425046,0.0510180402461);
    glVertex2f(0.898267106284,0.0929210915917);
    glVertex2f(1,0.07);
    glVertex2f(1,-1);
    glVertex2f(0.68,-1);
    glEnd();
//2rd Forest
    glBegin(GL_POLYGON);
    glColor3ub(36, 83, 115);
    glVertex2f(0.057107533847,-0.1203209192809);
    glVertex2f(0.057107533847,-0.1203209192809);
    glVertex2f(0.5205438541769,-0.0232772782295);
    glVertex2f(0.71856689755,-0.0435006178664);
    glVertex2f(0.8693954089044,-0.0490508612132);
    glVertex2f(1,-0.04);
    glVertex2f(1,-1);
    glVertex2f(0.42,-1);
    glVertex2f(-0.05,-1);
    glEnd();
//1st Forest
    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-1,-1);
    glVertex2f(-1,0.3);
    glVertex2f(-0.9818789380332,0.3204266017963);
    glVertex2f(-0.8498381660267,0.2072781828038);
    glVertex2f(-0.8327052805765,0.1644459691783);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.8327052805765,0.1644459691783);
    glVertex2f(-0.6609836630438,0.1130680416116);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.5824784481087,0.0763478604323);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.835,-1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.585,-1);
    glVertex2f(-0.05,-1);
    glVertex2f(-0.0495381320471,-0.0605962800007);
    glVertex2f(-0.2036190238643,-0.0653130419951);
    glVertex2f(-0.5154958923208,0.0441953783772);
    glVertex2f(-0.5824784481087,0.0763478604323);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(-0.05,-1);
    glVertex2f(0.42,-1);
    glVertex2f(0.4147327510621,-0.1913590727716);
    glVertex2f(0.2444733656041,-0.1329199639149);
    glVertex2f(0.0746699338056,-0.1140529159373);
    glVertex2f(-0.0495381320471,-0.0605962800007);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(27, 64, 89);
    glVertex2f(0.42,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.2);
    glVertex2f(0.8256570560146,-0.2046760641358);
    glVertex2f(0.585951211459,-0.2122857734868);
    glVertex2f(0.4147327510621,-0.1913590727716);
    glEnd();
}

void BlueLakeN()
{


//Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(64, 154, 202);
    glVertex2f(1,-0.32);
    glVertex2f(-1,-0.32);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glEnd();
}

void CoverBridgeN()
{


//Cover Bridge Using Blue Lake//*******************************
    glBegin(GL_QUADS);
    glColor3ub(64, 154, 202);
    glVertex2f(-0.08032289841543,-0.4482623769432);
    glVertex2f(0.8422429702315,-0.4482623769432);
    glVertex2f(0.8422429702315,-0.8482623769432);
    glVertex2f(-0.08032289841543,-0.8482623769432);
    glEnd();

    glPushMatrix();
    glTranslatef(-positionN3, 0,0);
}


void nightN()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    WeatherNN();
    StarsN();
    MoonNN();
    MountainForestN();
    BlueLakeN();
    Stone();
    TrainN();
    TrainNBridge();
    SideOfBlueLake();
    CoverBridgeN();
    FishingBoat();


    glPopMatrix();

    glFlush();
}

void handleMouseN(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speedN += 0.01f;

		}
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speedN -= 0.01f;

		}
	}
    glutPostRedisplay();
}
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************
// *****************************************************  NAZMUS  ************************************************























void my_keyboard(unsigned char key, int x, int y);
void handleKeypress(unsigned char key, int x, int y);
void handleKeypressR(unsigned char key, int x, int y);
void handleKeypressE(unsigned char key, int x, int y);
void handleKeypressN(unsigned char key, int x, int y);


// Scene 1: City View Initialization
void displayNadim() {
    glutInitWindowSize(1200, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("City View");
    glOrtho(-300, 300, -300, 300, -150, 500);

    init(); // Set background color light blue
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);
    glutKeyboardFunc(my_keyboard);
}

// Scene 2: Snow Scene Initialization
void displayBNJ() {
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Snow");

    myInit();
    glutDisplayFunc(Display3);
    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(80, update_cloud, 0);
    glutTimerFunc(30, updateFlow, 0);
    glutTimerFunc(150, updateHuman, 0);
    glutTimerFunc(60, updateVehicals, 0);
    glutTimerFunc(60, weather_update, 0);
    glutTimerFunc(10, update2, 0);
}

//Scene 3:
void displayRejuan()
{

    glutInitWindowSize (1200, 720);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Mass rapid transit system Dhaka Metro Rail");

    // Enable alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    initR ();
    glutDisplayFunc(display1);
    glutKeyboardFunc(handleKeypressR);
    glutMouseFunc(handleMouseR);
    glutTimerFunc(100, trainR, 0);
    glutTimerFunc(100, cloudR1, 0);
    glutTimerFunc(100, cloudR2, 0);
    glutTimerFunc(100, caru, 0);
    glutTimerFunc(100, card, 0);
    glutTimerFunc(100, bird, 0);
}
//Scene 4:
void displayEshtab()
{

    glutInitWindowSize (1280, 620);
    glutInitWindowPosition (120, 60);
    glutCreateWindow ("Mountain View");
    glutDisplayFunc(myDisplayE);
    myInitE ();
    glutKeyboardFunc(handleKeypressE);
    glutTimerFunc(0, update, 0);
}
// Scene 5:
void displayNazmus()
{

    glutInitWindowSize(900,900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Sunset & MidnightN Scenery");
    glutDisplayFunc(sunset);
    initN();
    glutKeyboardFunc(handleKeypressN);
    glutMouseFunc(handleMouseN);
    glutTimerFunc(1000, updateN, 0);
    glutMainLoop();
}








int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create the initial window and set up the first scene


    if (displayNo == 1) {
        displayRejuan();
    }
    else if (displayNo == 2) {
        displayNadim();
    }

    else if (displayNo == 3)
    {

        displayEshtab();
    }
    else if (displayNo == 4)
    {

        displayNazmus();
    }
    else if (displayNo == 5) {
        displayBNJ();
    }

    glutMainLoop();
    return 0;
}






// Keybord Functionality........
void my_keyboard(unsigned char key, int x, int y)
{

    switch (key) {
        case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayEshtab(); // Reinitialize the Snow scene
            break;
        case '4':
            displayNo = 4;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNazmus();
        case '5':
            displayNo = 5;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ();
        case 'b':
            glutIdleFunc(busMove);
            break;

        case 's':
             glutIdleFunc(NULL);
             break;

        case 'n':
             glutDisplayFunc(night);
             glutPostRedisplay();
            break;

        case 'd':
             glutDisplayFunc(myDisplay);
             glutPostRedisplay();
             break;

      default:
            break;
    }

}
void handleKeypress(unsigned char key, int x, int y)
{

    switch (key)
    {
                case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayEshtab(); // Reinitialize the Snow scene
            break;
        case '4':
            displayNo = 4;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNazmus();
        case '5':
            displayNo = 5;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ();
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



void handleKeypressR(unsigned char key, int x, int y)
{
	switch (key)
	{
	            case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayEshtab(); // Reinitialize the Snow scene
            break;
        case '4':
            displayNo = 4;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNazmus();
        case '5':
            displayNo = 5;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ();
        case 's':
        speed = 0.0f;
        break;

        case 'a':
        speed += 0.1f;
        break;

        case 'r':
        rainday = true;
        Rain(_rain);
        break;

        case 't':
        rainday = false;
        Rain(false);
        break;

        case 'n':
        day_rain=false;
        night_R = true;
        Night_R(_night_R);
        break;

        case 'd':
        day_rain = true;
        night_R = false;
        sunR(true);
        glClearColor (0.77, 0.95, 1.00, 1.0);
        break;


	}
}
void handleKeypressE(unsigned char key, int x, int y) {

    switch (key) {
                case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayEshtab(); // Reinitialize the Snow scene
            break;
        case '4':
            displayNo = 4;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNazmus();
        case '5':
            displayNo = 5;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ();
        case 'w':
            trainSpeed += 1;
            break;

        case 'n':
            dayNight = !dayNight;
            break;

        case 's':
            trainSpeed = 0;
            break;

        case 'x':
            trainSpeed = 5;
            break;

        case 'j':
            jeepSpeed += 1;
            break;

        case 'y':
            jeepSpeed = 0;
            break;
        case 'f':
            fountain = !fountain;
            break;
        case 'k':
          keymap = !keymap;
          break;
        case 'e':
           exit(0);
           break;

    glutPostRedisplay();

    }

}

void handleKeypressN(unsigned char key, int x, int y)
{

	switch (key)
	{
            case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayEshtab(); // Reinitialize the Snow scene
            break;
        case '4':
            displayNo = 4;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNazmus();
        case '5':
            displayNo = 5;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ();

        case 'w':
	    glLoadIdentity();
        glutDisplayFunc(nightN);
        glutPostRedisplay();
        break;

        case 's':
	    glLoadIdentity();
        glutDisplayFunc(sunset);
        glutPostRedisplay();
        break;

        case 'a':
            speedN2 += 0.01f;
            break;

        case 'd':
            speedN2 -= 0.01f;
            break;

        case 'e':
            speedN = 0.0f;
            break;


        case 27:     // ESC key
            exit(0);
            break;

        glutPostRedisplay();
	}
}


