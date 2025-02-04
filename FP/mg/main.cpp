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


int displayNo=1;


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
        snowman();
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













void my_keyboard(unsigned char key, int x, int y);
void handleKeypress(unsigned char key, int x, int y);
void handleKeypressR(unsigned char key, int x, int y);


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
    glutInitWindowPosition (600, 100);
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







int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create the initial window and set up the first scene
    if (displayNo == 1) {
        displayNadim();
    }
    else if (displayNo == 2) {
        displayBNJ();
    }
    else if (displayNo == 3) {
        displayRejuan();
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
            displayNadim(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the Snow scene
            break;
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
void handleKeypress(unsigned char key, int x, int y)    ///AFID-11
{

    switch (key)
    {
        case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the Snow scene
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



void handleKeypressR(unsigned char key, int x, int y)
{
	switch (key)
	{
	    case '1':
            displayNo = 1;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayNadim(); // Reinitialize the City View scene
            break;
        case '2':
            displayNo = 2;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayBNJ(); // Reinitialize the Snow scene
            break;
        case '3':
            displayNo = 3;
            glutDestroyWindow(glutGetWindow()); // Destroy the current window
            displayRejuan(); // Reinitialize the Snow scene
            break;
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





