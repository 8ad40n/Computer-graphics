#include<cstdio>
#include<iostream>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;

float x,y,i;
float PI=3.1416;

GLfloat radius;
int triangleAmount =40;
GLfloat twicePi = 2.0 * PI;

float counter1=0.0;

GLfloat position = 0.0f;
GLfloat speed = 0.001f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.0005f;

GLfloat position3 = 0.0f;
GLfloat speed3 = 0.00003f;


void update(int value)
{

    if(position > 2.5)
        position = 0.0f;

    position += speed;

    if(position < 0)
        position = 2.5f;

    position += speed;

    if(position2 >1.0)
        position2 =-1.0f;

    position2 += speed2;

    if(position2 <-1.0)
        position2 =1.0f;

    position2 += speed2;

    if(position3 >1.0)
        position3 =-1.0f;

    position3 += speed3;

    if(position3 <-1.0)
        position3 =1.0f;

    position3 += speed3;

	glutPostRedisplay();


	glutTimerFunc(10, update, 0);
}
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void Weather()
{

//Weather//*******************************
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


void Stars()
{
//Stars//*******************************
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

void Moon()
{


//Moon//*******************************
    glPushMatrix();
    glTranslatef(position2,-position2,0);


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=0.5;
    y=0.7;
    radius =0.1;
    twicePi = -1.5 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 175, 129);

    x=0.525;
    y=0.72;
    radius =0.1;
    twicePi = 2.0 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
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


void Train()
{


//Train//*******************************
//Train Engine
    glPushMatrix();

    glTranslatef(-position,0.0f, 0.0f);
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
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0147045394483;
    y=-0.3431020496611;
    radius =0.00215;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    x=1.0147045394483;
    y=-0.3431020496611;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0384885885324;
    y=-0.3412683237308;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0384885885324;
    y=-0.3412683237308;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0531048883341;
    y=-0.3412683237308;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0531048883341;
    y=-0.3412683237308;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//4th Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 1, 1);

    x=1.0674691829668;
    y=-0.341394326316;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.0674691829668;
    y=-0.341394326316;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//Coal Cart
//1st Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1113223885496;
    y=-0.3422454148682;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1113223885496;
    y=-0.3422454148682;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1364549333457;
    y=-0.3422279668657;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1364549333457;
    y=-0.3422279668657;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1615249078393;
    y=-0.3422279668657;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1615249078393;
    y=-0.3422279668657;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
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
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.1983735010497;
    y=-0.3424054537282;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.2248014730928;
    y=-0.3424054537282;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.2248014730928;
    y=-0.3424054537282;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.1615249078393;
    y=-0.3422279668657;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.2512294451359;
    y=-0.3422726498479;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
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
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.289344158585;
    y=-0.3424054537282;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//2nd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.3157721306281;
    y=-0.3424054537282;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.3157721306281;
    y=-0.3424054537282;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
//3rd Wheel
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(97, 106, 107);

    x=1.3419344949119;
    y=-0.3425382576085;
    radius =0.00415;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=1.3419344949119;
    y=-0.3425382576085;
    radius =0.00315;
    twicePi = 2 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
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


void TrainBridge()
{

//Train Bridge//*******************************
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
    glTranslatef(-position3, 0,0);
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

    Weather();
    Stars();
    Moon();
    MountainForest();
    BlueLake();
    Stone();
    Train();
    TrainBridge();
    SideOfBlueLake();
    CoverBridge();
    FishingBoat();

    glPopMatrix();
    glFlush();
}

void WeatherN()
{


//Weather//*******************************
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

void MoonN()
{


//Moon//*******************************
    glPushMatrix();
    glTranslatef(position2,-position2,0);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);

    x=0.5;
    y=0.7;
    radius =0.1;
    twicePi = -1.5 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 24, 111);

    x=0.525;
    y=0.72;
    radius =0.1;
    twicePi = 2.0 * PI;

    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
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
    glTranslatef(-position3, 0,0);
}


void night()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    WeatherN();
    Stars();
    MoonN();
    MountainForestN();
    BlueLakeN();
    Stone();
    Train();
    TrainBridge();
    SideOfBlueLake();
    CoverBridgeN();
    FishingBoat();


    glPopMatrix();

    glFlush();
}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.01f;

		}
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed -= 0.01f;

		}
	}
    glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{
        case 'w':
	    glLoadIdentity();
        glutDisplayFunc(night);
        glutPostRedisplay();
        break;

        case 's':
	    glLoadIdentity();
        glutDisplayFunc(sunset);
        glutPostRedisplay();
        break;

        case 'a':
            speed2 += 0.01f;
            break;

        case 'd':
            speed2 -= 0.01f;
            break;

        case 'e':
            speed = 0.0f;
            break;


        case 27:     // ESC key
            exit(0);
            break;

        glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
    cout<<"\n            *************INSTRUCTIONS*************             \n";
    cout<<"\nIncrease Train Speed and For Going Forward: Mouse Left Button \n";
    cout<<"Decrease Train Speed and For Going Backward: Mouse Right Button \n";
    cout<<"Stop Train: E \n";
    cout<<"After Stopping Train, Start Train Forward: Mouse Left Button \n";
    cout<<"After Stopping Train, Start Train Backward: Mouse Right Button \n";
    cout<<"Train Sound: M \n";
    cout<<"Increase Moon Speed: A \n";
    cout<<"Decrease Moon Speed: D \n";
    cout<<"Select Night: W \n";
    cout<<"Select Sunset: S \n";
    cout<<"Exit Program: Esc ";

    glutInit(&argc, argv);
    glutInitWindowSize(900,900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Sunset & Midnight Scenery");
    glutDisplayFunc(sunset);
    init();
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
    return 0;
}
