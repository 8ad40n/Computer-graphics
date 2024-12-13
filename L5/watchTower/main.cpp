#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void bottom()
{
    // bottom
    glBegin(GL_LINE_STRIP);
    glVertex2f(-8.5894134263022f, 0.0193376408815f);
    glVertex2f(-5.0f, 0.0f);
    glVertex2f(-4.6320211091492f, 0.0799653935828f);
    glVertex2f(-2.4266988225096f, 1.1120479645287f);
    glVertex2f(-1.7533573065309f, 1.39798751241f);
    glVertex2f(-1.0338965086359f, 1.5916884964587f);
    glVertex2f(-0.2916769275181f, 1.696421884159f);
    glVertex2f(0.2488306168797f, 1.7093336551249f);
    glVertex2f(0.5897810387785f, 1.7068194863201f);
    glVertex2f(1.0813305732426f, 1.5801526274134f);
    glVertex2f(2.01430466227f, 1.2643767818964f);
    glVertex2f(2.9688089225827f, 0.8337733561915f);
    glVertex2f(3.8730761165631f, 0.2955190740603f);
    glVertex2f(4.3437543863358f, 0.0905672428591f);
    glVertex2f(4.7516959580216f, -0.0293421436497f);
    glVertex2f(8.846193748072f, -0.0293421436497f);
    glEnd();

}
void leftRightLines()
{
    //1st left line
    glBegin(GL_LINE_STRIP);
    glVertex2f(-4.3528358903013f, 6.8198384660712f);
    glVertex2f(-0.7960151377873, 6.1693284759359);
    glEnd();

    //2nd left line
    glBegin(GL_LINE_STRIP);
    glVertex2f(-5.1817115228931, 5.928010253789);
    glVertex2f(-0.7855230411722, 5.8545655774834);
    glEnd();

    //3rd left line
    glBegin(GL_LINE_STRIP);
    glVertex2f(-4.4577568564522, 4.7843717227446);
    glVertex2f(-0.8274914276326, 5.4873421959554);
    glEnd();

    //1st right line
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9876412867773, 6.1693284759359);
    glVertex2f(4.7018434885176, 6.8513147559165);
    glEnd();

    //2nd right line
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.0732257891513, 5.8608418557611);
    glVertex2f(5.4712499260168, 5.887983551315);
    glEnd();

    //3rd right line
    glBegin(GL_LINE_STRIP);
    glVertex2f(4.7344984842814, 4.8507150741349);
    glVertex2f(1, 5.5);
    glEnd();

}

void towerBottom()
{

    //tower bottom
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.2916769275181f, 1.696421884159f);
    glVertex2f(-0.1975971768535f, 5.2244334962648f);
    glVertex2f(0.4004822458781f, 5.234660626736f);
    glVertex2f(0.5897810387785f, 1.7068194863201f);
    glEnd();

}

void towerTop()
{

    //tower top
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1975971768535f, 5.2244334962648f);
    glVertex2f(-0.3212088999682f, 5.4531151840271f);
    glVertex2f(0.5045497066489f, 5.4555402152634f);
    glVertex2f(0.4004822458781f, 5.234660626736f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.3357095985643f, 5.6011650443103f);
    glVertex2f(0.5027292753221f, 5.6142146765887f);
    glVertex2f(0.5045497066489f, 5.4555402152634f);
    glVertex2f(-0.3212088999682f, 5.4531151840271f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.3357095985643f, 5.6011650443103f);
    glVertex2f(-0.3382307937726f, 5.7924531379281f);
    glVertex2f(0.5045907142313f, 5.7924531379281f);
    glVertex2f(0.5027292753221f, 5.6142146765887f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2f, 5.8f);
    glVertex2f(-0.2016110570689f, 6.2921154260682f);
    glVertex2f(0.3789258107243f, 6.2864462068867f);
    glVertex2f(0.3744402585914f, 5.794479472749f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.0884405851233f, 6.2955681735949f);
    glVertex2f(-0.0938864274399f, 5.7999965227858f);
    glVertex2f(0.2546474808215f, 5.7891048381526f);
    glVertex2f(0.2489276346826f, 6.2907794794215f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.2016110570689f, 6.2921154260682f);
    glVertex2f(-0.2951062967835f, 6.2981473770175f);
    glVertex2f(-0.0719241116585f, 6.4941857828705f);
    glVertex2f(0.0858263690074f, 6.8646586956779f);
    glVertex2f(0.2274182692386f, 6.4970643393085f);
    glVertex2f(0.4634246251515f, 6.2777796618173f);
    glVertex2f(0.3789258107243f, 6.2864462068867f);
    glEnd();
}

void windows()
{

    // 1st window
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.0284914850662f, 4.8038618792005f);
    glVertex2f(0.2f, 4.8f);
    glVertex2f(0.2004099451463f, 4.5131682732651f);
    glVertex2f(-0.0413205941759f, 4.5087923696794f);
    glEnd();

    // 2nd window
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.0307705754414f, 2.9916921299369f);
    glVertex2f(0.1951422613853f, 2.9869293312292f);
    glVertex2f(0.2300801671949f, 2.5727961070218f);
    glVertex2f(-0.0493316679128f, 2.5727961070218f);
    glEnd();


}

void tower()
{
    glLineWidth(4);
    glColor3f(0.0f, 0.0f, 0.0f);

    bottom();
    leftRightLines();
    towerBottom();
    towerTop();
    windows();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    tower();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Watch Tower");
    gluOrtho2D(-12, 12, -12, 12);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
