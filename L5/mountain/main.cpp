#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void circle(float radius, float cX, float cY)
{
    glLineWidth(4);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+cX,y+cY);
    }
}

void halfCircle(float radius, float cX, float cY)
{
    glLineWidth(4);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 100; i++)
    {
        float pi = 3.1416;
        float angle = (i * pi) / 100;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x + cX, y + cY);
    }
    glEnd();
}

void TextMountain()
{
    // M
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.7562619498324, 0.1882044599452);
    glVertex2f(0.7719864177985, 0.6075236057062);
    glVertex2f(0.8977821615267, 0.1855837152842);
    glVertex2f(1.0628890751701, 0.6101443503672);
    glVertex2f(1.0681305644921, 0.1960666939283);
    glEnd();

    // O
    circle(0.2,1.4, 0.4);
    glEnd();

    // U
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.6947056858873f, 0.6023869461706f);
    glVertex2f(1.6947056858873f, 0.2834647844519f);
    glVertex2f(1.7f, 0.25f);
    glVertex2f(1.714018504563f, 0.2232984146937f);
    glVertex2f(1.7336093550002f, 0.2043197783326f);
    glVertex2f(1.7605467743514f, 0.1902388545809f);
    glVertex2f(1.8070750441397f, 0.1853411419716f);
    glVertex2f(1.8395223901764f, 0.1859533560477f);
    glVertex2f(1.879316305127f, 0.1877899982762f);
    glVertex2f(1.9111514370875f, 0.2092174909419f);
    glVertex2f(1.9301300734485f, 0.2477869777402f);
    glVertex2f(1.9338973071763f, 0.2834647844519f);
    glVertex2f(1.9322708933493f, 0.6078413883927f);
    glEnd();


    // N
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.132236485787f, 0.1907008676117f);
    glVertex2f(2.1321528968605f, 0.5891783930791f);
    glVertex2f(2.4f, 0.2f);
    glVertex2f(2.4f, 0.6f);
    glEnd();

    // T
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.5121608727063f, 0.5970406270621f);
    glVertex2f(2.8f, 0.6f);
    glVertex2f(2.6589225737226f, 0.5996613717231f);
    glVertex2f(2.6611028982753f, 0.1998067330673f);
    glEnd();

    // A
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.8843066145691f, 0.1882044599452f);
    glVertex2f(3.0336890602464f, 0.6075236057062f);
    glVertex2f(3.2f, 0.2f);
    glVertex2f(3.146359442055f, 0.3288952141909f);
    glVertex2f(3.146359442055f, 0.3288952141909f);
    glVertex2f(2.9314800184672f, 0.3271039269785f);
    glEnd();

    // I
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(3.3699297311171, 0.6031453904821);
    glVertex2f(3.3691443768552, 0.2065496725723);
    glEnd();

    // N
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(3.5604587371086f, 0.1960666939283f);
    glVertex2f(3.5604587371086f, 0.6153858396892f);
    glVertex2f(3.8f, 0.2f);
    glVertex2f(3.8f, 0.6f);
    glEnd();
}

void leftInnerLine()
{
    // left inner lines

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.0526337554626, 1.3886885079766);
    glVertex2f(2.2418728554955, 1.3979196835879);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.9233972969035, 1.2594520494175);
    glVertex2f(2.2972599091637, 1.2594520494175);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.7710828993161, 1.1440623542755);
    glVertex2f(2.2972599091637, 1.1532935298868);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.6649243797854, 0.9963635444937);
    glVertex2f(2.1726390384103, 1.0148258957164);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.6947056858873, 0.6023869461706);
    glVertex2f(1.6947056858873, 0.2834647844519);
    glVertex2f(1.6947056858873, 0.2834647844519);
    glVertex2f(1.6947056858873, 0.2834647844519);
    glVertex2f(1.6947056858873, 0.2834647844519);
    glVertex2f(1.6947056858873, 0.2834647844519);
    glEnd();

}

void tree()
{

    // first tree
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.0834506601145,0.7993881613418);
    glVertex2f(1.0845025034758, 1.3144537034304);
    glVertex2f(0.9203046643105, 1.1547544352012);
    glVertex2f(1.0845025034758, 1.3144537034304);
    glVertex2f(1.2576974845131, 1.1547544352012);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9315510916506, 1.0040523088441);
    glVertex2f(1.0850397165315, 1.134679065338);
    glVertex2f(1.2576974845131, 1.0018030233761);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.9158060933745, 0.855599467955);
    glVertex2f(1.0834506601145, 0.9908694595956);
    glVertex2f(1.2352046298329, 0.8668458952951);
    glEnd();


    // second tree
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glVertex2f(3.4948033049898, 0.7971808316264);
    glVertex2f(3.4948901711105, 1.3102742544035);
    glVertex2f(3.3285784069733, 1.1631523092052);
    glVertex2f(3.4948901711105, 1.3102742544035);
    glVertex2f(3.6867883604996, 1.1695489155181);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glVertex2f(3.3381733164427, 1.0096337576939);
    glVertex2f(3.4951466448885, 1.1303327274563);
    glVertex2f(3.6516070257783, 1.0224269703198);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glVertex2f(3.3349750132862, 0.865710115652);
    glVertex2f(3.4955011412297, 0.9786983518675);
    glVertex2f(3.6516070257783, 0.8401236904001);
    glEnd();

}

void LeftRightLine()
{
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.3258431161921, 1.4607465006533);
    glVertex2f(1.7418695073305, 1.4588770139633);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.3127807707644, 1.7568263303487);
    glVertex2f(2.06502243058, 1.7561695520155);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.7743906684665, 1.3605416652837);
    glVertex2f(3.167732063185, 1.3694812424364);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.6647077267095, 1.7558699698494);
    glVertex2f(3.2394771098702, 1.7615479272658);
    glEnd();
}

void mountain()
{
    halfCircle(0.8, 2.3437874655997, 1.28366547372);

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(0.8, 0.8);
    glVertex2f(3.7465544801474, 0.8);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(1.0835641435689,0.7957474740175);
    glVertex2f(1.5864593870888,1.0379038347448);
    glVertex2f(2.0434025798512,1.4763846762845);
    glVertex2f(2.20494815305,1.4763846762845);
    glVertex2f(2.2508087169322,1.5487928090895);
    glVertex2f(2.3437874655997,1.577366547372);
    glVertex2f(2.4126496043057,1.527156142147);
    glVertex2f(2.4957301848079,1.4948470275072);
    glVertex2f(2.754203101926,1.2225273469721);
    glVertex2f(3.4948033049898,0.7971808316264);
    glEnd();



    LeftRightLine();
    tree();


    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.3434157872205, 1.6102367226492);
    glVertex2f(2.3233394158905, 1.3912892950179);
    glVertex2f(2.3765043451345, 1.3749308552505);
    glVertex2f(2.4378484942622, 1.3381243657738);
    glVertex2f(2.3765043451345, 1.2461081420822);
    glVertex2f(2.3765043451345, 1.0886581593211);
    glVertex2f(2.2988017562394, 0.9905075207167);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.1986063126641, 0.8800880522868);
    glVertex2f(2.0434025798512, 0.7932776810438);
    glEnd();


    leftInnerLine();
    TextMountain();


}


void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    mountain();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mountain");
    gluOrtho2D(-2, 5, -2, 4);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
