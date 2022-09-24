/*
This project is made by:

NAZMUL HASAN MAMUN
ZANNATUL FERDUS
TIHAM INKIAD
NUSRAT SULTANA NETU
WAHID SADIK
*/

#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/gl.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <math.h>
#include<mmsystem.h>
#include<math.h>>
# define PI           3.14159265358979323846

using namespace std;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * PI;


GLfloat position = 0.0f;
GLfloat speed = 0.02f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.008f;

GLfloat position3 = 0.0f;
GLfloat speed3 = 0.008f;

GLfloat position4 = 0.0f;
GLfloat speed4 = 0.01f;


GLfloat position5 = 0.0f;
GLfloat speed5 = 0.01f;

GLfloat position6 = 0.0f;
GLfloat speed6 = 0.02f;

GLfloat position7 = 0.0f;
GLfloat speed7 = 0.01f;

GLfloat position8 = 0.0f;
GLfloat speed8 = 0.02f;

GLfloat position9 = 0.0f;
GLfloat speed9 = 0.01f;

GLfloat position10 = 0.0f;
GLfloat speed10 = 0.01f;

GLfloat position11 = 3.5f;
GLfloat speed11 = 0.05f;

GLfloat position12 = 2.0f;
GLfloat speed12 = 0.05f;

GLfloat position13 = 0.0f;
GLfloat speed13 = 0.001f;

GLfloat position14 = 0.0f;
GLfloat speed14 = 0.006f;


float windMillFanPosition=0;

bool night = false;
bool rain = false;
bool cover = false;
bool isWindMill=false;

//////////////////////////////////////////////////////////spin
static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.9;


float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;


/// private car 01
void update(int value){
    if(position <-1.7)
        position = 1.0f;
    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

	///cloud 2
	void update2(int value){
    if(position2 >1.1)
        position2 = -1.9f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}

///cloud 3
	void update3(int value){
    if(position3 <-1.1)
        position3 = 1.0f;
    position3 -= speed3;
	glutPostRedisplay();
	glutTimerFunc(100, update3, 0);
}


///THELAGARI
	void update4(int value){
    if(position4 >2.0)
        position4 = -1.0f;
    position4 += speed4;
	glutPostRedisplay();
	glutTimerFunc(100, update4, 0);
}

///bus 01
	void update5(int value){
    if(position5 >1.8)
        position5 = -1.0f;
    position5 += speed5;
	glutPostRedisplay();
	glutTimerFunc(100, update5, 0);
}

///plane
void update6(int value){
    if(position6 <-1.8)
        position6 = 1.0f;
    position6 -= speed6;
	glutPostRedisplay();
	glutTimerFunc(100, update6, 0);
}

///bus 02
	void update7(int value){
    if(position7 <-1.2)
        position7 = 1.7f;
    position7 -= speed7;
	glutPostRedisplay();
	glutTimerFunc(100, update7, 0);
	}

	/// private car 02
void update8(int value){
    if(position8 > 1.8)
        position8 = -2.7f;
    position8 += speed8;
	glutPostRedisplay();
	glutTimerFunc(100, update8, 0);
}

	/// boat 01
void update9(int value){
    if(position9 > 1.8)
        position9 = -1.7f;
    position9 += speed9;
	glutPostRedisplay();
	glutTimerFunc(100, update9, 0);
}

	/// boat 02
void update10(int value){
    if(position10 < -1.8)
        position10 = 1.7f;
    position10 -= speed10;
	glutPostRedisplay();
	glutTimerFunc(100, update10, 0);
}
	/// rain 01
void update11(int value){
    if(position11 < -1.0)
        position11 = 2.0f;
    position11 -= speed11;
	glutPostRedisplay();
	glutTimerFunc(100, update11, 0);
}

      /// rain 02
void update12(int value){
    if(position12 < -1.0)
        position12 = 2.0f;
    position12 -= speed12;
	glutPostRedisplay();
	glutTimerFunc(100, update12, 0);

}
    ///sun
void update13(int value)
{
    if(position13 >0.35)
        position13 = -0.2f;
    position13 += speed13;
    glutPostRedisplay();
    glutTimerFunc(100, update13, 0);
}

/// ship
void update14(int value){
    if(position14 > 1.3)
        position14 = -1.0f;
    position14 += speed14;
	glutPostRedisplay();
	glutTimerFunc(100, update14, 0);
}


float _run1 = 0;




void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void circle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 100; //# of lines used to draw circle

    GLfloat twicePi = 2.0f * PI;

    //glColor3ub(255,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
}


///---------------------windmill start

void windMill()
{


    glPushMatrix();
    glTranslatef(0,0,0);
    glColor3ub(192, 192, 192);
    ///stand
    glBegin(GL_QUADS);
    glVertex2f(-0.01,0);
    glVertex2f(-0.01,0.5);
    glVertex2f( 0.01,0.5);
    glVertex2f( 0.01,0);
    glEnd();

    glColor3ub(245,255,250);
    glTranslatef(0,0.5,0);
        ///middle circle
        circle(0,0,0.015);


        ///wind mill fan 1
         glPushMatrix();

         spin=spin+spin_speed;
    if(spin>360.0)
    {
        spin=spin-360.0;
    }
    glutPostRedisplay();

         glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin,0.0f,0.0f,1.0f);

        glPushMatrix();


        glColor3ub(245,255,250);
        glRotatef(windMillFanPosition,0,0,1);
        glBegin(GL_QUADS);///fan 1
        glVertex2f(0,0);
        glVertex2f(0.01,0.1);
        glVertex2f(0,0.2);
        glVertex2f(-0.01,0.1);
        glEnd();

        ///wind mill fan 1's middle line
        glLineWidth(1);
        glColor3ub(255,228,196);
        glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(0,0.2);
        glEnd();
        glPopMatrix();



        ///wind mill fan 2

         glPushMatrix();

        glColor3ub(245,255,250);
        glRotatef(windMillFanPosition+120,0,0,1);
        glBegin(GL_QUADS);///fan 2
        glVertex2f(0,0);
        glVertex2f(0.01,0.1);
        glVertex2f(0,0.2);
        glVertex2f(-0.01,0.1);
        glEnd();

        ///wind mill fan 1's middle line
        glLineWidth(1);
        glColor3ub(255,228,196);
        glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(0,0.2);
        glEnd();
        glPopMatrix();



        ///fan 3
         glPushMatrix();

        glColor3ub(245,255,250);
        glRotatef(windMillFanPosition+240,0,0,1);
        glBegin(GL_QUADS);///fan 2
        glVertex2f(0,0);
        glVertex2f(0.01,0.1);
        glVertex2f(0,0.2);
        glVertex2f(-0.01,0.1);
        glEnd();

        glLineWidth(1);
        glColor3ub(255,228,196);
        glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(0,0.2);
        glEnd();

        glPopMatrix();
        glPopMatrix();
        glPopMatrix();

}

void reshape(int w,int h)
{
    glViewport(0,0, (GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


///---------------------windmill end


///-----------------ship start
void ship()
{


        glPushMatrix();
        glTranslatef(-0.5, 0.0f, 0.0f);
        glPushMatrix();
        glScalef(0.0015f, 0.0015f, 1.00f);

    glColor3ub(20,20,20);
    glBegin(GL_POLYGON);
    glVertex2f(100,50);
    glVertex2f(0,100);
    glVertex2f(400,100);
    glVertex2f(300,50);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(50,100);
    glVertex2f(50,120);
    glVertex2f(350,120);
    glVertex2f(350,100);
    glEnd();

    glColor3ub(0,0,128);
    glBegin(GL_POLYGON);
    glVertex2f(70,120);
    glVertex2f(70,140);
    glVertex2f(330,140);
    glVertex2f(330,120);
    glEnd();

    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();

    glPushMatrix();
    glTranslatef(50,0,0);
    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,0,0);
    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,0,0);
    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,65);
    glVertex2f(110,85);
    glVertex2f(140,85);
    glVertex2f(140,65);
    glEnd();
    glPopMatrix();

    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();

    glPushMatrix();
    glTranslatef(75,0,0);

    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150,0,0);

    glColor3ub(255,255,255);
    if(night)
    {
        glColor3ub(229,228,2);
    }
    glBegin(GL_POLYGON);
    glVertex2f(110,140);
    glVertex2f(110,180);
    glVertex2f(140,180);
    glVertex2f(140,140);

    glEnd();
    glPopMatrix();

        glPopMatrix();
        glPopMatrix();

}

///------------------ship end

 ///------------------grass start


 void grass()
 {


    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1.2,1.2,1.2);

    glColor3ub(0,102,51);

    glBegin(GL_QUADS);

    glVertex2f(0.150,0.150);

    glVertex2f(0.150,0.170);

    glVertex2f(0.230,0.170);

    glVertex2f(0.230,0.150);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.190,0.150);
    glVertex2f(0.210,0.150);
    glVertex2f(0.200,0.300);
    glEnd();




    glBegin(GL_POLYGON);

    glVertex2f(0.195,0.150);

    glVertex2f(0.215,0.150);

    glVertex2f(0.210,0.295);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.200,0.150);

    glVertex2f(0.215,0.150);

    glVertex2f(0.220,0.280);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.210, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.230, 0.270);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.230, 0.260);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.245, 0.250);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.255, 0.240);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.265, 0.230);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.270, 0.220);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.275, 0.210);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.280, 0.205);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.285, 0.200);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.215, 0.150);

    glVertex2f(0.225, 0.150);

    glVertex2f(0.290, 0.190);

    glEnd();



     glBegin(GL_POLYGON);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.200, 0.150);

    glVertex2f(0.190, 0.295);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.175, 0.150);

    glVertex2f(0.195, 0.150);

    glVertex2f(0.185, 0.285);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.185, 0.150);

    glVertex2f(0.180, 0.275);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.170, 0.265);

    glEnd();







    glBegin(GL_POLYGON);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.160, 0.255);

    glEnd();

     glBegin(GL_POLYGON);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.180, 0.150);

    glVertex2f(0.150, 0.245);

    glEnd();



      glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.145, 0.235);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.140, 0.225);

    glEnd();





       glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.135, 0.220);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.124, 0.210);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.125, 0.210);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.120, 0.200);

    glEnd();



    glBegin(GL_POLYGON);

    glVertex2f(0.170, 0.150);

    glVertex2f(0.160, 0.150);

    glVertex2f(0.110, 0.195);

    glEnd();





    glBegin(GL_POLYGON);

    glVertex2f(0.165, 0.150);

    glVertex2f(0.155, 0.150);

    glVertex2f(0.100, 0.185);

    glEnd();






    glPopMatrix();
 }

    ///------------------grass end



void display()
{

glClearColor(1.0f, 1.0f, 1.0f, 1.0f);





glBegin(GL_QUADS); //SKY
glColor3ub(67,162,255);
if(night)
{
    glColor3b(29,29,62);
}
glVertex2f(-1.0f, 0.5f);
glVertex2f(1.0f, 0.5f);
glVertex2f(1.0f, 1.0f);
glVertex2f(-1.0f, 1.0f);
glEnd();

 ///----------------------------------sun start

 if(!night)
 {
    glPushMatrix();
    glTranslatef(position13,-position13,  -0.0f);
    glColor3ub(255,255,0);
    circle(0.4f,0.95f,0.07f);

    glPopMatrix();

 }

    ///----------------------------sun end


    ///-----------------windmill start

    ///-----------------windmill end

glBegin(GL_QUADS); //river
glColor3ub(67,162,255);
if(night)
{
   glColor3ub(1,17,78);
}
glVertex2f(-1.0f, -0.15f);
glVertex2f(1.0f, -0.15f);
glVertex2f(1.0f, -0.62f);
glVertex2f(-1.0f, -0.62f);
glEnd();

glBegin(GL_QUADS); //road
glColor3ub(74,75,74);
if(night)
{
    glColor3b(14,14,14);
}
glVertex2f(-1.0f, -0.15f);
glVertex2f(1.0f, -0.15f);
glVertex2f(1.0f, 0.15f);
glVertex2f(-1.0f, 0.15f);
glEnd();

glLineWidth(5.0);
glBegin(GL_LINES); //rode border white

glColor3ub(255,255,255);
glVertex2f(-1.0f, -0.15f);
glVertex2f(-0.8f, -0.15f);
glVertex2f(-0.6f, -0.15f);
glVertex2f(-0.4f, -0.15f);
glVertex2f(-0.2f, -0.15f);
glVertex2f( 0.0f, -0.15f);
glVertex2f( 0.2f, -0.15f);
glVertex2f( 0.4f, -0.15f);
glVertex2f( 0.6f, -0.15f);
glVertex2f(0.8f, -0.15f);
glVertex2f( 1.0f, -0.15f);


glEnd();

glLineWidth(5.0);
glBegin(GL_LINES); //rode border black

glColor3ub(0,0,0);

glVertex2f(-0.8f, -0.15f);
glVertex2f(-0.6f, -0.15f);
glVertex2f(-0.4f, -0.15f);
glVertex2f(-0.2f, -0.15f);
glVertex2f( 0.0f, -0.15f);
glVertex2f( 0.2f, -0.15f);
glVertex2f( 0.4f, -0.15f);
glVertex2f( 0.6f, -0.15f);
glVertex2f(0.8f, -0.15f);
glVertex2f(1.0f, -0.15f);



glEnd();


glLineWidth(4.0);
glBegin(GL_LINES); //rode border white up

glColor3ub(255,255,255);
glVertex2f(-1.0f, 0.15f);
glVertex2f(-0.8f, 0.15f);
glVertex2f(-0.6f, 0.15f);
glVertex2f(-0.4f, 0.15f);
glVertex2f(-0.2f, 0.15f);
glVertex2f( 0.0f, 0.15f);
glVertex2f( 0.2f, 0.15f);
glVertex2f( 0.4f, 0.15f);
glVertex2f( 0.6f, 0.15f);
glVertex2f(0.8f, 0.15f);
glVertex2f( 1.0f, 0.15f);


glEnd();

glLineWidth(4.0);
glBegin(GL_LINES); //rode border black up

glColor3ub(0,0,0);

glVertex2f(-0.8f, 0.15f);
glVertex2f(-0.6f, 0.15f);
glVertex2f(-0.4f, 0.15f);
glVertex2f(-0.2f, 0.15f);
glVertex2f( 0.0f, 0.15f);
glVertex2f( 0.2f, 0.15f);
glVertex2f( 0.4f, 0.15f);
glVertex2f( 0.6f, 0.15f);
glVertex2f(0.8f, 0.15f);
glVertex2f(1.0f, 0.15f);



glEnd();

glBegin(GL_QUADS); //down village
glColor3ub(61,231,131);
if(night)
{
    glColor3b(17,74,37);
}

glVertex2f(-1.0f, -0.62f);
glVertex2f(1.0f, -0.62f);
glVertex2f(1.0f, -1.0f);
glVertex2f(-1.0f, -1.0f);
glEnd();

//up
glBegin(GL_QUADS); //town
glColor3ub(61,231,131);
if(night)
{
    glColor3b(17,74,37);
}
glVertex2f(-1.0f, 0.15f);
glVertex2f(1.0f, 0.15f);
glVertex2f(1.0f, 0.5f);
glVertex2f(-1.0f, 0.5f);
glEnd();



glLineWidth(2);
 glBegin(GL_LINES);  //road border
 glColor3ub(252, 250, 250);
 glVertex2f(-1.0,0.0);
 glVertex2f(-0.8,0.0);
glVertex2f(-0.6,0.0);
 glVertex2f(-0.4,0.0);
 glVertex2f(-0.2,0.0);
 glVertex2f(0.0,0.0);
  glVertex2f(0.2,0.0);
 glVertex2f(0.4,0.0);
 glVertex2f(0.6,0.0);
 glVertex2f(0.8,0.0);
 glEnd();


 ///------------------------------star


 if(night)
    {
        glBegin(GL_POINTS);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.9f, 0.9f);

        glVertex2f(-0.7f, 0.9f);

        glVertex2f(-0.5f, 0.9f);

        glVertex2f(-0.3f, 0.9f);

        glVertex2f(-0.1f, 0.9f);

        glVertex2f(0.1f, 0.9f);

        glVertex2f(0.3f, 0.9f);

        glVertex2f(0.5f, 0.9f);

        glVertex2f(0.7f, 0.9f);

        glVertex2f(0.9f, 0.9f);

        glVertex2f(-0.98f, 0.93f);

        glVertex2f(-0.88f, 0.94f);

        glVertex2f(-0.68f, 0.91f);

        glVertex2f(-0.55f, 0.92f);

        glVertex2f(-0.45f, 0.93f);

        glVertex2f(-0.25f, 0.94f);

        glVertex2f(0.0f, 0.9f);

        glVertex2f(0.13f, 0.91f);

        glVertex2f(0.25f, 0.92f);

        glVertex2f(0.37f, 0.93f);

        glVertex2f(0.49f, 0.92f);

        glVertex2f(-0.8f, 0.85f);

        glVertex2f(-0.6f, 0.85f);

        glVertex2f(-0.4f, 0.85f);

        glVertex2f(-0.2f, 0.85f);

        glVertex2f(0.0f, 0.85f);

        glVertex2f(0.2f, 0.85f);

        glVertex2f(0.4f, 0.85f);

        glVertex2f(0.6f, 0.85f);

        glVertex2f(0.8f, 0.85f);

        glVertex2f(1.0f, 0.85f);

        glEnd();
    }

    ///---------------------------------------start end






    ///-------------------------moon start
    // moon
    if(night)
    {
        GLfloat xsm1=0.78f;
        GLfloat ysm1=0.9f;
        GLfloat radiussm1 =0.05f;
        glColor3f(1.0f,1.0f,1.0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xsm1, ysm1);
        //GLfloat twicePi = 2.0f * PI;
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( xsm1 + (radiussm1 * cos(i *  twicePi / triangleAmount)),
                        ysm1 + (radiussm1 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();



        GLfloat xsm2=0.8f;
        GLfloat ysm2=0.9f;
        glColor3b(29,29,62);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xsm2, ysm2);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( xsm2 + (radiussm1 * cos(i *  twicePi / triangleAmount)),
                        ysm2 + (radiussm1 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

    }

    ///---------------------------moon end



///--------------------plane

    glPushMatrix();
    glTranslatef(position6,0.0f, 0.0f);

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(128,128,0);
	if(night)
    {
        glColor3ub(245,214,70);
    }

	glVertex2f(0.4f, 0.91f);    // x, y
	glVertex2f(0.23f, 0.91f);
	glVertex2f(0.23f, 0.84f);    // x, y
	glVertex2f(0.4f, 0.84f);

	glEnd();
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red //plane body

	glVertex2f(0.23f, 0.91f);    // x, y
	glVertex2f(0.23f, 0.91f);
	glVertex2f(0.23f, 0.84f);    // x, y
	glVertex2f(0.20f, 0.84f);

	glEnd();

 glBegin(GL_QUADS);  //backside            // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Red

	glVertex2f(0.4f, 0.91f);    // x, y
	glVertex2f(0.45f, 0.93f);
	glVertex2f(0.45f, 0.90f);    // x, y
	glVertex2f(0.4f, 0.84f);

	glEnd();


glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(128,128,0);
	if(night)
    {
        glColor3ub(245,214,70);
    }

	glVertex2f(0.280f, 0.90f);    // x, y
	glVertex2f(0.25f, 0.90f);
	glVertex2f(0.270f, 0.75f);    // x, y
	glVertex2f(0.280f, 0.75f);

	glEnd();
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
		glColor3f(128,128,0);

		if(night)
    {
        glColor3ub(245,214,70);
    }

	glVertex2f(0.280f, 0.99f);    // x, y
	glVertex2f(0.27f, 0.99f);
	glVertex2f(0.25f, 0.90f);    // x, y
	glVertex2f(0.280f, 0.90f);

	glEnd();
	glPopMatrix();
	///-------------------plane end





///------------------------cloud


//glLoadIdentity();
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    //glScalef(1.7,1.7,1.7);

GLfloat p2=0.75f; GLfloat q2= 0.81f; GLfloat r2 = 0.05f;
    int tringle3=40;
    GLfloat tp3 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }
    glVertex2f (p2,q2);
    for(int j= 0;j<=tringle3; j++)
    {
        glVertex2f (
                    p2+(r2*cos(j*tp3/tringle3)),
                    q2+(r2*sin(j*tp3/tringle3))
                    );

    }
    glEnd ();

     GLfloat p3=0.80f; GLfloat q3= 0.78f; GLfloat r3 = 0.05f;
    int tringle4=40;
    GLfloat tp4 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p3,q3);
    for(int k= 0;k<=tringle4; k++)
    {
        glVertex2f (
                    p3+(r3*cos(k*tp4/tringle4)),
                    q3+(r3*sin(k*tp4/tringle4))
                    );

    }
    glEnd ();

    GLfloat p4=0.85f; GLfloat q4= 0.75f; GLfloat r4 = 0.05f;
    int tringle5=40;
    GLfloat tp5 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p4,q4);
    for(int m= 0;m<=tringle5; m++)
    {
        glVertex2f (
                    p4+(r4*cos(m*tp5/tringle5)),
                    q4+(r4*sin(m*tp5/tringle5))
                    );

    }
     GLfloat p5=0.79f; GLfloat q5= 0.77f; GLfloat r5 = 0.05f;
    int tringle6=40;
    GLfloat tp6 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p5,q5);
    for(int m= 0;m<=tringle6; m++)
    {
        glVertex2f (
                    p5+(r5*cos(m*tp6/tringle6)),
                    q4+(r5*sin(m*tp6/tringle6))
                    );

    }
    glEnd ();

    GLfloat p111=0.83f; GLfloat q111= 0.82f; GLfloat r111 = 0.05f;
    int tringle111=40;
    GLfloat tp111 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p111,q111);
    for(int c= 0;c<=tringle111; c++)
    {
        glVertex2f (
                    p111+(r111*cos(c*tp111/tringle111)),
                    q111+(r111*sin(c*tp111/tringle111))
                    );

    }
    glEnd ();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(position3,0.0f, 0.0f);


	GLfloat p7=0.2f; GLfloat q7= 0.83f; GLfloat r7 = 0.05f;
    int tringle7=40;
    GLfloat tp7 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }


    glVertex2f (p7,q7);
    for(int b= 0;b<=tringle7; b++)
    {
        glVertex2f (
                    p7+(r7*cos(b*tp7/tringle7)),
                    q7+(r7*sin(b*tp7/tringle7))
                    );

    }
    glEnd ();



  GLfloat p8=0.27f; GLfloat q8= 0.85f; GLfloat r8 = 0.05f;
    int tringle8=40;
    GLfloat tp8 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p8,q8);
    for(int c= 0;c<=tringle8; c++)
    {
        glVertex2f (
                    p8+(r8*cos(c*tp8/tringle8)),
                    q8+(r8*sin(c*tp8/tringle8))
                    );

    }
    glEnd ();


     GLfloat p9=0.15f; GLfloat q9= 0.85f; GLfloat r9 = 0.05f;
    int tringle9=40;
    GLfloat tp9 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p9,q9);
    for(int c= 0;c<=tringle9; c++)
    {
        glVertex2f (
                    p9+(r9*cos(c*tp9/tringle9)),
                    q9+(r9*sin(c*tp9/tringle9))
                    );

    }
    glEnd ();

     GLfloat p10=0.22f; GLfloat q10= 0.87f; GLfloat r10 = 0.05f;
    int tringle10=40;
    GLfloat tp10 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub ( 255,255,255);
    if(night)
    {
        glColor3ub (129,128,129);
    }

    glVertex2f (p10,q10);
    for(int c= 0;c<=tringle10; c++)
    {
        glVertex2f (
                    p10+(r10*cos(c*tp10/tringle10)),
                    q10+(r10*sin(c*tp10/tringle10))
                    );

    }
    glEnd ();


    glPopMatrix();



///-------------------------end cloud

glBegin(GL_POLYGON); ///hill 01
    glColor3f(0.0f,0.2f,0.0f);

    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, 0.65f);


    glVertex2f(-1.0f, 0.65f);
    glVertex2f(-0.97f, 0.68f);

    glVertex2f(-0.97f, 0.68f);
    glVertex2f(-0.95f, 0.66f);

    glVertex2f(-0.95f, 0.66f);
    glVertex2f(-0.9f, 0.75f);

    glVertex2f(-0.9f, 0.75f);
    glVertex2f(-0.87f, 0.73f);

    glVertex2f(-0.87f, 0.73f);
    glVertex2f(-0.84f, 0.66f);

    glVertex2f(-0.84f, 0.66f);
    glVertex2f(-0.8f, 0.7f);

    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.78f, 0.68f);

    glVertex2f(-0.78f, 0.68f);
    glVertex2f(-0.73f, 0.73f);

    glVertex2f(-0.73f, 0.73f);
    glVertex2f(-0.68f, 0.64f);

    glVertex2f(-0.68f, 0.64f);
    glVertex2f(-0.65f, 0.67f);

    glVertex2f(-0.65f, 0.67f);
    glVertex2f(-0.58f, 0.58f);

    glVertex2f(-0.58f, 0.58f);
    glVertex2f(-0.55f, 0.6f);

    glVertex2f(-0.55f, 0.6f);
    glVertex2f(-0.5f, 0.5f);



    glEnd();


     //windmill
    glPushMatrix();
    glTranslatef(-0.6,0.45,0);
    glScalef(0.7,0.7,0);
    windMill();
    glPopMatrix();



    glBegin(GL_POLYGON); ///hill 03

    glColor3f(0.0f,0.2f,0.0f);


    glVertex2f(-0.22f, 0.5f);
    glVertex2f(-0.18f, 0.65f);


    glVertex2f(-0.18f, 0.65f);
    glVertex2f(-0.15f, 0.68f);

    glVertex2f(-0.15f, 0.68f);
    glVertex2f(-0.13f, 0.66f);

    glVertex2f(-0.13f, 0.66f);
    glVertex2f(-0.08f, 0.75f);

    glVertex2f(-0.08f, 0.75f);
    glVertex2f(-0.05f, 0.73f);

    glVertex2f(-0.05f, 0.73f);
    glVertex2f(-0.02f, 0.66f);

    glVertex2f(-0.02f, 0.66f);
    glVertex2f(0.02f, 0.7f);

    glVertex2f(0.02f, 0.7f);
    glVertex2f(0.04f, 0.68f);

    glVertex2f(0.04f, 0.68f);
    glVertex2f(0.09f, 0.73f);

    glVertex2f(0.09f, 0.73f);
    glVertex2f(0.14f, 0.64f);

    glVertex2f(0.14f, 0.64f);
    glVertex2f(0.17f, 0.67f);

    glVertex2f(0.17f, 0.67f);
    glVertex2f(0.24f, 0.58f);

    glVertex2f(0.24f, 0.58f);
    glVertex2f(0.27f, 0.6f);

    glVertex2f(0.27f, 0.6f);
    glVertex2f(0.32f, 0.5f);



    glEnd();

    glBegin(GL_POLYGON); ///hill 02
    glColor3f(0.0f,0.4f,0.0f);


    glVertex2f(-0.65f, 0.5f);
    glVertex2f(-0.63f, 0.55f);

    glVertex2f(-0.63f, 0.55f);
    glVertex2f(-0.61f, 0.53f);

    glVertex2f(-0.61f, 0.53f);
    glVertex2f(-0.55f, 0.65f);

    glVertex2f(-0.55f, 0.65f);
    glVertex2f(-0.52f, 0.63f);

    glVertex2f(-0.52f, 0.63f);
    glVertex2f(-0.5f, 0.68f);

    glVertex2f(-0.5f, 0.68f);
    glVertex2f(-0.47f, 0.66f);

    glVertex2f(-0.47f, 0.66f);
    glVertex2f(-0.44f, 0.73f);

    glVertex2f(-0.44f, 0.73f);
    glVertex2f(-0.4f, 0.7f);

    glVertex2f(-0.4f, 0.7f);
    glVertex2f(-0.35f, 0.62f);

    glVertex2f(-0.35f, 0.62f);
    glVertex2f(-0.3f, 0.66f);

    glVertex2f(-0.3f, 0.66f);
    glVertex2f(-0.28f, 0.63f);

    glVertex2f(-0.28f, 0.63f);
    glVertex2f(-0.24f, 0.69f);

    glVertex2f(-0.24f, 0.69f);
    glVertex2f(-0.18f, 0.58f);

    glVertex2f(-0.18f, 0.58f);
    glVertex2f(-0.15f, 0.6f);

    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.11f, 0.55f);

    glVertex2f(-0.11f, 0.55f);
    glVertex2f(-0.1f, 0.5f);

    glEnd();



    glBegin(GL_POLYGON); ///hill 05
    glColor3ub(2,76,1);


    glVertex2f(0.65f, 0.5f);
    glVertex2f(0.63f, 0.55f);

    glVertex2f(0.63f, 0.55f);
    glVertex2f(0.61f, 0.53f);

    glVertex2f(0.61f, 0.53f);
    glVertex2f(0.55f, 0.65f);

    glVertex2f(0.55f, 0.65f);
    glVertex2f(0.52f, 0.63f);

    glVertex2f(0.52f, 0.63f);
    glVertex2f(0.5f, 0.68f);

    glVertex2f(0.5f, 0.68f);
    glVertex2f(0.47f, 0.66f);

    glVertex2f(0.47f, 0.66f);
    glVertex2f(0.44f, 0.73f);

    glVertex2f(0.44f, 0.73f);
    glVertex2f(0.4f, 0.7f);

    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.35f, 0.62f);

    glVertex2f(0.35f, 0.62f);
    glVertex2f(0.3f, 0.66f);

    glVertex2f(0.3f, 0.66f);
    glVertex2f(0.28f, 0.63f);

    glVertex2f(0.28f, 0.63f);
    glVertex2f(0.24f, 0.69f);

    glVertex2f(0.24f, 0.69f);
    glVertex2f(0.18f, 0.58f);

    glVertex2f(0.18f, 0.58f);
    glVertex2f(0.15f, 0.6f);

    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.11f, 0.55f);

    glVertex2f(0.11f, 0.55f);
    glVertex2f(0.1f, 0.5f);

    glEnd();

    glBegin(GL_POLYGON); ///hill 04
    glColor3ub(1,128,2);

    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.0f, 0.65f);


    glVertex2f(1.0f, 0.65f);
    glVertex2f(0.97f, 0.68f);

    glVertex2f(0.97f, 0.68f);
    glVertex2f(0.95f, 0.66f);

    glVertex2f(0.95f, 0.66f);
    glVertex2f(0.9f, 0.75f);

    glVertex2f(0.9f, 0.75f);
    glVertex2f(0.87f, 0.73f);

    glVertex2f(0.87f, 0.73f);
    glVertex2f(0.84f, 0.66f);

    glVertex2f(0.84f, 0.66f);
    glVertex2f(0.8f, 0.7f);

    glVertex2f(0.8f, 0.7f);
    glVertex2f(0.78f, 0.68f);

    glVertex2f(0.78f, 0.68f);
    glVertex2f(0.73f, 0.73f);

    glVertex2f(0.73f, 0.73f);
    glVertex2f(0.68f, 0.64f);

    glVertex2f(0.68f, 0.64f);
    glVertex2f(0.65f, 0.67f);

    glVertex2f(0.65f, 0.67f);
    glVertex2f(0.58f, 0.58f);

    glVertex2f(0.58f, 0.58f);
    glVertex2f(0.55f, 0.6f);

    glVertex2f(0.55f, 0.6f);
    glVertex2f(0.5f, 0.5f);

    glEnd();








///-------------------------------------------------------boat 01 start


    glPushMatrix();
    glTranslated(position9,0,0);
    glScalef(3,3,0);
        glBegin(GL_QUADS);
        glColor3ub(139,69,19);
        glVertex2f(0.01f, -0.14f);
        glVertex2f(0.015f, -0.13f);
        glVertex2f(-0.02f, -0.13f);
        glVertex2f(-0.03f, -0.14f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(0.02f, -0.145f);
        glVertex2f(0.02f, -0.14f);
        glVertex2f(-0.03f, -0.14f);
        glVertex2f(-0.03f, -0.145f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(-0.03f, -0.145f);
        glVertex2f(-0.03f, -0.14f);
        glVertex2f(-0.045f, -0.137f);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.02f, -0.145f);
        glVertex2f(0.035f, -0.137f);
        glVertex2f(0.02f, -0.14f);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.02f, -0.14f);
        glVertex2f(0.015f, -0.13f);
        glVertex2f(0.01f, -0.14f);

        glEnd();
        glPopMatrix();




        ///-------------------------------------------------------boat 01 end


        ///-------------------------------------------------------boat 02 start


    glPushMatrix();
    glTranslated(position10,-0.1,0);
    glScalef(3,3,0);
        glBegin(GL_QUADS);
        glColor3ub(139,69,19);
        glVertex2f(0.01f, -0.14f);
        glVertex2f(0.015f, -0.13f);
        glVertex2f(-0.02f, -0.13f);
        glVertex2f(-0.03f, -0.14f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(0.02f, -0.145f);
        glVertex2f(0.02f, -0.14f);
        glVertex2f(-0.03f, -0.14f);
        glVertex2f(-0.03f, -0.145f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(-0.03f, -0.145f);
        glVertex2f(-0.03f, -0.14f);
        glVertex2f(-0.045f, -0.137f);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.02f, -0.145f);
        glVertex2f(0.035f, -0.137f);
        glVertex2f(0.02f, -0.14f);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(0,0,0);
        glVertex2f(0.02f, -0.14f);
        glVertex2f(0.015f, -0.13f);
        glVertex2f(0.01f, -0.14f);

        glEnd();
        glPopMatrix();

        ///-------------------------------------------------------boat 02 end


        ///----------------ship start

        glPushMatrix();
        glTranslatef(position14,-0.5,0);
        glScalef(0.7,0.7,0.0);
        ship();
        glPopMatrix();

        ///-----------------ship end


    /// -----------------------------village






    ///Beraaaaaaa

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(229, 111, 128);
    glVertex2f(-1.0f,-0.67f);
    glVertex2f(-0.60f,-0.67f);

    glVertex2f(-1.0f,-0.63f);
    glVertex2f(-0.60f,-0.63f);

    glVertex2f(-1.0f,-0.59f);
    glVertex2f(-0.60f,-0.59f);

    glVertex2f(-1.0f,-0.55f);
    glVertex2f(-0.60f,-0.55f);


    ///*****
    glVertex2f(-1.0f,-0.69f);
    glVertex2f(-0.98f,-0.52f);

    glVertex2f(-0.97f,-0.69f);
    glVertex2f(-0.95f,-0.52f);

    glVertex2f(-0.94f,-0.69f);
    glVertex2f(-0.92f,-0.52f);

    glVertex2f(-0.91f,-0.69f);
    glVertex2f(-0.89f,-0.52f);

    glVertex2f(-0.88f,-0.69f);
    glVertex2f(-0.86f,-0.52f);

    glVertex2f(-0.85f,-0.69f);
    glVertex2f(-0.83f,-0.52f);

    glVertex2f(-0.82f,-0.69f);
    glVertex2f(-0.80f,-0.52f);

    glVertex2f(-0.79f,-0.69f);
    glVertex2f(-0.77f,-0.52f);

    glVertex2f(-0.76f,-0.69f);
    glVertex2f(-0.74f,-0.52f);
    ///******
    glEnd();

///tree.................................

	glLineWidth(1);  //right
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(46, 139, 87);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.079;
            float r2=-0.140;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.77+x,-0.40+y );
        }

	glEnd();

glLineWidth(1);      //middle
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 100, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.060;
            float r2=-0.160;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.85+x,-0.37+y );
        }

	glEnd();

glLineWidth(1);  //left
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(46, 139, 87);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.064;
            float r2=-0.140;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.93+x,-0.42+y );
        }

	glEnd();



 glBegin(GL_QUADS);  ///tree base
    glColor3ub(97, 106, 91);
      glVertex2f(-0.9,-0.75);
    glVertex2f(-0.8,-0.75);
    glVertex2f(-0.82,-0.68);
       glVertex2f(-0.88,-0.68);


       glVertex2f(-0.88,-0.68);
          glVertex2f(-0.82,-0.68);
        glVertex2f(-0.82,-0.62);
        glVertex2f(-0.88,-0.62);


       glVertex2f(-0.82,-0.62);
        glVertex2f(-0.8,-0.52);
       glVertex2f(-0.9,-0.52);
        glVertex2f(-0.88,-0.62);

     glEnd();



      glBegin(GL_TRIANGLES);  ///tree base

    glColor3ub(97, 106, 91);

       glVertex2f(-0.83,-0.52);       //right
          glVertex2f(-0.8,-0.52);
        glVertex2f(-0.75,-0.45);

      glVertex2f(-0.87,-0.52);      //middle
    glVertex2f(-0.83,-0.52);
    glVertex2f(-0.85,-0.42);

       glVertex2f(-0.9,-0.52);       //left
        glVertex2f(-0.87,-0.52);
       glVertex2f(-0.95,-0.45);

     glEnd();

     ///-----------------------------------second tree

    glPushMatrix();
    glTranslated(0.75,-0.01,0.0);

	glLineWidth(1);  //right
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(46, 139, 87);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.079;
            float r2=-0.140;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.77+x,-0.40+y );
        }

	glEnd();

glLineWidth(1);      //middle
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 100, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.060;
            float r2=-0.160;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.85+x,-0.37+y );
        }

	glEnd();

glLineWidth(1);  //left
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(46, 139, 87);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.064;
            float r2=-0.140;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.93+x,-0.42+y );
        }

	glEnd();



 glBegin(GL_QUADS);  ///tree base
    glColor3ub(97, 106, 91);
      glVertex2f(-0.9,-0.75);
    glVertex2f(-0.8,-0.75);
    glVertex2f(-0.82,-0.68);
       glVertex2f(-0.88,-0.68);


       glVertex2f(-0.88,-0.68);
          glVertex2f(-0.82,-0.68);
        glVertex2f(-0.82,-0.62);
        glVertex2f(-0.88,-0.62);


       glVertex2f(-0.82,-0.62);
        glVertex2f(-0.8,-0.52);
       glVertex2f(-0.9,-0.52);
        glVertex2f(-0.88,-0.62);

     glEnd();



      glBegin(GL_TRIANGLES);  ///tree base

    glColor3ub(97, 106, 91);

       glVertex2f(-0.83,-0.52);       //right
          glVertex2f(-0.8,-0.52);
        glVertex2f(-0.75,-0.45);

      glVertex2f(-0.87,-0.52);      //middle
    glVertex2f(-0.83,-0.52);
    glVertex2f(-0.85,-0.42);

       glVertex2f(-0.9,-0.52);       //left
        glVertex2f(-0.87,-0.52);
       glVertex2f(-0.95,-0.45);

     glEnd();
     glPopMatrix();



///>>>>>>>>>>>>>...................................

    /// house 1

    glPushMatrix();
    glTranslated(-0.25,-0.26,0.0);
    glScalef(0.7,0.7,0.7);
    glBegin(GL_QUADS);  ///middle

    glColor3ub(139, 180, 142);
    glVertex2f(-.6,- .75);
    glVertex2f(-.35,-.75);
    glVertex2f(-.35,-.50);
    glVertex2f(-.6,-.50);
    glEnd();

    glBegin(GL_POLYGON);  ///left side
    glColor3ub(97, 106, 91);
      glVertex2f(-0.76,-0.68);
    glVertex2f(-0.6,-0.75);
    glVertex2f(-0.6,-0.5);
     glVertex2f(-0.68,-0.35);
       glVertex2f(-0.76,-0.5);
       glVertex2f(-0.76,-0.68);

     glEnd();

      glBegin(GL_QUADS);  /// chal

    glColor3ub(133, 65, 22);
    glVertex2f(-.7,- .33);
    glVertex2f(-.6,-.5);
    glVertex2f(-.33,-.50);
    glVertex2f(-.43,-.33);
    glEnd();

     glBegin(GL_QUADS);  /// chal er side

    glColor3ub(133, 65, 22);
    glVertex2f(-.7,- .33);
    glVertex2f(-.79,-.5);
    glVertex2f(-.76,-.50);
     glVertex2f(-0.68,-0.35);
    glEnd();

     glBegin(GL_QUADS);  /// door

    glColor3ub(255, 205, 4);
    glVertex2f(-.52,- .75);
    glVertex2f(-.43,-.75);
    glVertex2f(-.43,-.55);
     glVertex2f(-0.52,-.55);
    glEnd();

     glBegin(GL_QUADS);  /// window

    glColor3ub(255, 205, 4);
    glVertex2f(-.72,- .62);
    glVertex2f(-.64,-.65);
    glVertex2f(-.64,-.55);
     glVertex2f(-0.72,-.53);
    glEnd();

     glBegin(GL_QUADS);  /// ghor er nich
    glColor3ub(90, 100, 91);
      glVertex2f(-0.76,-0.68);
    glVertex2f(-0.79,-0.71);
    glVertex2f(-0.6,-0.78);
     glVertex2f(-0.6,-0.75);

    glVertex2f(-0.6,-0.75);
     glVertex2f(-0.6,-0.78);
     glVertex2f(-0.32,-0.78);
       glVertex2f(-0.35,-0.75);


     glEnd();
     glPopMatrix();


      /// house 2



      glPushMatrix();
    glTranslated(-0.7,-0.26,0.0);
    glScalef(0.7,0.7,0.7);
    glBegin(GL_QUADS);  ///middle

    glColor3ub(139, 180, 142);
    glVertex2f(.6,- .75);
    glVertex2f(.35,-.75);
    glVertex2f(.35,-.50);
    glVertex2f(.6,-.50);
    glEnd();

    glBegin(GL_POLYGON);  ///left side
    glColor3ub(97, 106, 91);
      glVertex2f(0.76,-0.68);
    glVertex2f(0.6,-0.75);
    glVertex2f(0.6,-0.5);
     glVertex2f(0.68,-0.35);
       glVertex2f(0.76,-0.5);
       glVertex2f(0.76,-0.68);

     glEnd();

      glBegin(GL_QUADS);  /// chal

    glColor3ub(48,78,83);
    glVertex2f(.7,- .33);
    glVertex2f(.6,-.5);
    glVertex2f(.33,-.50);
    glVertex2f(.43,-.33);
    glEnd();

     glBegin(GL_QUADS);  /// chal er side

    glColor3ub(48,78,83);
    glVertex2f(.7,- .33);
    glVertex2f(.79,-.5);
    glVertex2f(.76,-.50);
     glVertex2f(0.68,-0.35);
    glEnd();

     glBegin(GL_QUADS);  /// door

    glColor3ub(255, 205, 4);
    glVertex2f(.52,- .75);
    glVertex2f(.43,-.75);
    glVertex2f(.43,-.55);
     glVertex2f(0.52,-.55);
    glEnd();

     glBegin(GL_QUADS);  /// window

    glColor3ub(255, 205, 4);
    glVertex2f(.72,- .62);
    glVertex2f(.64,-.65);
    glVertex2f(.64,-.55);
     glVertex2f(0.72,-.53);
    glEnd();

     glBegin(GL_QUADS);  /// ghor er nich
    glColor3ub(90, 100, 91);
      glVertex2f(0.76,-0.68);
    glVertex2f(0.79,-0.71);
    glVertex2f(0.6,-0.78);
     glVertex2f(0.6,-0.75);

    glVertex2f(0.6,-0.75);
     glVertex2f(0.6,-0.78);
     glVertex2f(0.32,-0.78);
       glVertex2f(0.35,-0.75);


     glEnd();
     glPopMatrix();





///---------------------playground start

     glBegin(GL_QUADS);  /// Green Ground
    glColor3ub(1, 118, 0);
      glVertex2f(0.4,-0.64);
    glVertex2f(0.3,-0.74);
    glVertex2f(0.8,-0.74);
     glVertex2f(0.9,-0.64);

    glEnd();



    glLineWidth(3);
    glBegin(GL_LINES);      /// line
    glColor3ub(255, 255, 255);
    glVertex2f(0.4f,-0.64f);
    glVertex2f(0.9f,-0.64f);

   glVertex2f(0.3f,-0.74f);
    glVertex2f(0.8f,-0.74f);

   glVertex2f(0.4f,-0.64f);
     glVertex2f(0.3f,-0.74f);

    glVertex2f(0.9f,-0.64f);
     glVertex2f(0.8f,-0.74f);

    glVertex2f(0.65f,-0.64f);
     glVertex2f(0.55f,-0.74f);

      glVertex2f(0.38f,-0.66f);
     glVertex2f(0.5f,-0.66f);

     glVertex2f(0.32f,-0.72f);
     glVertex2f(0.45f,-0.72f);

    glVertex2f(0.5f,-0.66f);
     glVertex2f(0.45f,-0.72f);

    glVertex2f(0.88f,-0.66f);
     glVertex2f(0.76f,-0.66f);

     glVertex2f(0.70f,-0.72f);
     glVertex2f(0.82f,-0.72f);

    glVertex2f(0.76f,-0.66f);
    glVertex2f(0.70f,-0.72f);
    glEnd();



    ///------------------Playground

    //grass
     glPushMatrix();
     glTranslatef(0.23,-0.85,0.0);
     glScalef(0.4,0.4,0);
     grass();
     glPopMatrix();

     //grass
     glPushMatrix();
     glTranslatef(0.38,-0.85,0.0);
     glScalef(0.4,0.4,0);
     grass();
     glPopMatrix();

     //grass
     glPushMatrix();
     glTranslatef(0.53,-0.86,0.0);
     glScalef(0.4,0.4,0);
     grass();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.68,-0.86,0.0);
     glScalef(0.4,0.4,0);
     grass();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.77,-0.79,0.0);
     glScalef(0.3,0.3,0);
     grass();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.82,-0.73,0.0);
     glScalef(0.3,0.3,0);
     grass();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(0.25,-0.75,0.0);
     glScalef(0.3,0.3,0);
     grass();
     glPopMatrix();




     ///---------------------------------------------------------------playground start



///---------------------------------- Thelagari

	glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);
	glLineWidth(1);  //left  outer wheel
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.030;
            float r2=-0.040;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.89+x,-0.90+y );
        }

	glEnd();

	glLineWidth(1);  //left    middle wheel
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(40, 170, 87);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.020;
            float r2=-0.030;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.89+x,-0.90+y );
        }

	glEnd();

 glLineWidth(3);
    glBegin(GL_LINES);      ///left line
    glColor3ub(0, 0, 0);
    glVertex2f(-0.89f,-0.90f);
    glVertex2f(-0.89f,-0.93f);

    glVertex2f(-0.89f,-0.90f);
    glVertex2f(-0.91f,-0.92f);

    glVertex2f(-0.89f,-0.90f);
    glVertex2f(-0.87f,-0.92f);


glEnd();

	glLineWidth(1);  //right  outer wheel  black
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.030;
            float r2=-0.040;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.76+x,-0.90+y );
        }

	glEnd();


	glLineWidth(1);  //right middle wheel
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=1;i<200;i++)
        {
            glColor3ub(46, 139, 87);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r1=-0.020;
            float r2=-0.030;
            float x = r1 * cos(A);
            float y = r2 * sin(A);
            glVertex2f(-0.76+x,-0.90+y );
        }

	glEnd();


	 glLineWidth(3);
    glBegin(GL_LINES);      ///right
    glColor3ub(0, 0, 0);
    glVertex2f(-0.76f,-0.90f);
    glVertex2f(-0.76f,-0.93f);

    glVertex2f(-0.76f,-0.90f);
    glVertex2f(-0.78f,-0.92f);

    glVertex2f(-0.76f,-0.90f);
    glVertex2f(-0.74f,-0.92f);


glEnd();


 glBegin(GL_QUADS);  /// chala
    glColor3ub(1, 0, 0);
      glVertex2f(-.9,-0.65);
    glVertex2f(-.75,-0.65);
    glVertex2f(-.70,-0.7);
     glVertex2f(-.95,-0.7);

glColor3ub(58, 95, 205);
         glVertex2f(-.93,-0.7);    ///main body
         glVertex2f(-.93,-0.9);
         glVertex2f(-.72,-0.9);
         glVertex2f(-.72,-0.7);


        glColor3ub(255, 255, 255);      ///peter moddher body
        if(night)
    {
        glColor3ub(229,228,2);
    }
         glVertex2f(-.9,-0.73);
         glVertex2f(-.9,-0.85);
         glVertex2f(-.75,-0.85);
         glVertex2f(-.75,-0.73);
     glEnd();

 ///1st bottle   head and body

         glBegin(GL_POLYGON);
    glColor3ub(255, 182, 193);      /// light pink
      glVertex2f(-0.89,-0.85);
    glVertex2f(-0.87,-0.85);
    glVertex2f(-0.87,-0.80);
     glVertex2f(-0.88,-0.78);
       glVertex2f(-0.89,-0.80);
     glVertex2f(-0.89,-0.85);

     glEnd();

 	glLineWidth(1);
	glBegin(GL_POLYGON);
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=-0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-0.88+x,-0.777+y );
        }

	glEnd();

///2nd bottle   head and body

         glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0);      /// orange
      glVertex2f(-0.86,-0.85);
    glVertex2f(-0.84,-0.85);
    glVertex2f(-0.84,-0.80);
     glVertex2f(-0.85,-0.78);
       glVertex2f(-0.86,-0.80);
     glVertex2f(-0.86,-0.85);

     glEnd();

 	glLineWidth(1);
	glBegin(GL_POLYGON);
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=-0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-0.85+x,-0.777+y );
        }

	glEnd();

	///3rd bottle   head and body

         glBegin(GL_POLYGON);
    glColor3ub(255, 236, 139);      /// light golden
      glVertex2f(-0.83,-0.85);
    glVertex2f(-0.81,-0.85);
    glVertex2f(-0.81,-0.80);
     glVertex2f(-0.82,-0.78);
       glVertex2f(-0.83,-0.80);
     glVertex2f(-0.83,-0.85);

     glEnd();

 	glLineWidth(1);
	glBegin(GL_POLYGON);
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=-0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-0.82+x,-0.777+y );
        }

	glEnd();


	///4th bottle   head and body

         glBegin(GL_POLYGON);
    glColor3ub(65, 105, 225);      /// blue
      glVertex2f(-0.80,-0.85);
    glVertex2f(-0.78,-0.85);
    glVertex2f(-0.78,-0.80);
     glVertex2f(-0.79,-0.78);
       glVertex2f(-0.80,-0.80);
     glVertex2f(-0.80,-0.85);

     glEnd();

 	glLineWidth(1);
	glBegin(GL_POLYGON);
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=-0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-0.79+x,-0.777+y );
        }

	glEnd();


	///5th bottle   head and body

         glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);      /// red
      glVertex2f(-0.77,-0.85);
    glVertex2f(-0.75,-0.85);
    glVertex2f(-0.75,-0.80);
     glVertex2f(-0.76,-0.78);
       glVertex2f(-0.77,-0.80);
     glVertex2f(-0.77,-0.85);

     glEnd();

 	glLineWidth(1);
	glBegin(GL_POLYGON);
	for(int i=1;i<200;i++)
        {
            glColor3ub(0, 0, 0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=-0.010;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-0.76+x,-0.777+y );
        }

	glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);      ///blueeeeeeeeeeee
    glColor3ub(0, 0, 139);
    glVertex2f(-0.93f,-0.71f);
    glVertex2f(-0.72f,-0.71f);

    glVertex2f(-0.93f,-0.86f);
    glVertex2f(-0.72f,-0.86f);

    glVertex2f(-0.93f,-0.88f);
    glVertex2f(-0.72f,-0.88f);

    glColor3ub(198, 226, 255);    ///sky blue
    glVertex2f(-0.93f,-0.87f);
    glVertex2f(-0.72f,-0.87f);

    glVertex2f(-0.93f,-0.89f);
    glVertex2f(-0.72f,-0.89f);

///left
    glLineWidth(5);    ///green
    glColor3ub(0, 205, 0);
    glVertex2f(-0.93f,-0.78f);
    glVertex2f(-0.90f,-0.78f);

    glVertex2f(-0.93f,-0.8f);
    glVertex2f(-0.90f,-0.8f);

    glVertex2f(-0.93f,-0.84f);
    glVertex2f(-0.90f,-0.84f);



    glLineWidth(5);                     ///orange
    glColor3ub(255, 69, 0);
    glVertex2f(-0.93f,-0.79f);
    glVertex2f(-0.90f,-0.79f);

    glVertex2f(-0.93f,-0.81f);
    glVertex2f(-0.90f,-0.81f);

    glVertex2f(-0.93f,-0.83f);
    glVertex2f(-0.90f,-0.83f);


    glColor3ub(255, 255, 0);            ///yellow
    glVertex2f(-0.93f,-0.82f);
    glVertex2f(-0.90f,-0.82f);

///Right

    glLineWidth(5);
    glColor3ub(0, 205, 0);
    glVertex2f(-0.72f,-0.78f);
    glVertex2f(-0.75f,-0.78f);

    glVertex2f(-0.72f,-0.8f);
    glVertex2f(-0.75f,-0.8f);

    glVertex2f(-0.72f,-0.84f);
    glVertex2f(-0.75f,-0.84f);



    glLineWidth(5);
    glColor3ub(255, 69, 0);
    glVertex2f(-0.72f,-0.79f);
    glVertex2f(-0.75f,-0.79f);

    glVertex2f(-0.72f,-0.81f);
    glVertex2f(-0.75f,-0.81f);

    glVertex2f(-0.72f,-0.83f);
    glVertex2f(-0.75f,-0.83f);


    glColor3ub(255, 255, 0);
    glVertex2f(-0.72f,-0.82f);
    glVertex2f(-0.75f,-0.82f);
    glEnd();
    glPopMatrix();


    /// grass
     //grass 1
    glPushMatrix();
    glTranslatef(-1.1,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 2
    glPushMatrix();
    glTranslatef(-0.8,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 3
    glPushMatrix();
    glTranslatef(-0.5,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 4
    glPushMatrix();
    glTranslatef(-0.2,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 5
    glPushMatrix();
    glTranslatef(0.1,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 6
    glPushMatrix();
    glTranslatef(0.4,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 7
    glPushMatrix();
    glTranslatef(0.7,-1.2,0.0);
    grass();
    glPopMatrix();

    //grass 8
    glPushMatrix();
    glTranslatef(0.7,-1.2,0.0);
    glScalef(0.5,0.5,0);
    grass();
    glPopMatrix();



///...............................................................................................................


///--------------------------------- town building starts

//house-1
   glBegin(GL_QUADS);
   glColor3ub(0,255,255);
   if(night)
   {
       glColor3ub(0,128,128);
   }

    glVertex2f(-0.89f, 0.25f);
    glVertex2f(-0.67f, 0.25f);
    glVertex2f(-0.67f, 0.38);
    glVertex2f(-0.89f, 0.38f);
    glEnd();

glBegin(GL_QUADS);
   glColor3ub(255,127,80);

    glVertex2f(-0.91f, 0.38f);
    glVertex2f(-0.65f, 0.38f);
    glVertex2f(-0.65f, 0.41);
    glVertex2f(-0.91f, 0.46f);
    glEnd();
glBegin(GL_QUADS);
   glColor3ub(175,238,238);
   if(night)
   {
       glColor3ub(0,128,128);
   }


    glVertex2f(-0.97f, 0.25f);
    glVertex2f(-0.89f, 0.25f);
    glVertex2f(-0.89f, 0.33f);
    glVertex2f(-0.97f, 0.33f);
    glEnd();
glBegin(GL_QUADS);
   glColor3ub(255,127,80);

    glVertex2f(-0.98f, 0.33f);
    glVertex2f(-0.89f, 0.33f);
    glVertex2f(-0.89f, 0.37f);
    glVertex2f(-0.96f, 0.37f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(112,128,144);
   if(night)
    {
        glColor3ub(229,228,2);
    }

    glVertex2f(-0.96f, 0.29f);
    glVertex2f(-0.96f, 0.25f);
    glVertex2f(-0.9f, 0.25f);
    glVertex2f(-0.9f, 0.29f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    if(night)
    {
        glColor3ub(229,228,2);
    }

    glVertex2f(-0.78f, 0.36f);
    glVertex2f(-0.78f, 0.25f);
    glVertex2f(-0.74f, 0.25f);
    glVertex2f(-0.74f, 0.36f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    if(night)
    {
        glColor3ub(229,228,2);
    }

    glVertex2f(-0.87f, 0.27f);
    glVertex2f(-0.87f, 0.33f);
    glVertex2f(-0.84f, 0.33f);
    glVertex2f(-0.84f, 0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    if(night)
    {
        glColor3ub(229,228,2);
    }

    glVertex2f(-0.83f, 0.27f);
    glVertex2f(-0.83f, 0.33f);
    glVertex2f(-0.8f, 0.33f);
    glVertex2f(-0.8f, 0.27f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(105,105,105);
    if(night)
    {
        glColor3ub(229,228,2);
    }

    glVertex2f(-0.73f, 0.27f);
    glVertex2f(-0.73f, 0.33f);
    glVertex2f(-0.69f, 0.33f);
    glVertex2f(-0.69, 0.27f);
    glEnd();



//house-2
glBegin(GL_QUADS);
   glColor3ub(94,42,94);
   if(night)
   {
       glColor3ub(94,42,94);
   }

    glVertex2f(-0.65f, 0.24f);
    glVertex2f(-0.65f, 0.49f);
    glVertex2f(-0.27f, 0.49f);
    glVertex2f(-0.27f, 0.24f);
    glEnd();
glBegin(GL_QUADS);
   glColor3ub(255,250,240);


    glVertex2f(-0.67f, 0.51f);
    glVertex2f(-0.67f, 0.49f);
    glVertex2f(-0.25f, 0.49f);
    glVertex2f(-0.25f, 0.51f);
    glEnd();

glBegin(GL_QUADS);
   glColor3ub(255,250,240);


    glVertex2f(-0.51f, 0.52f);
    glVertex2f(-0.51f, 0.48f);
    glVertex2f(-0.42f, 0.48f);
    glVertex2f(-0.42f, 0.52f);
    glEnd();
//upper windows
    glBegin(GL_QUADS);
   glColor3ub(245,245,245);
   if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.63f, 0.43f);
    glVertex2f(-0.63f, 0.38f);
    glVertex2f(-0.59f, 0.38f);
    glVertex2f(-0.59f, 0.43f);
    glEnd();
 glBegin(GL_QUADS);
   glColor3ub(245,245,245);
   if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.57f, 0.43f);
    glVertex2f(-0.57f, 0.38f);
    glVertex2f(-0.53f, 0.38f);
    glVertex2f(-0.53f, 0.43f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(245,245,245);
   if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.51f, 0.43f);
    glVertex2f(-0.51f, 0.38f);
    glVertex2f(-0.47f, 0.38f);
    glVertex2f(-0.47f, 0.43f);
    glEnd();
     glBegin(GL_QUADS);
   glColor3ub(245,245,245);
   if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.45f, 0.43f);
    glVertex2f(-0.45f, 0.38f);
    glVertex2f(-0.41f, 0.38f);
    glVertex2f(-0.41f, 0.43f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(245,245,245);
   if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.39f, 0.43f);
    glVertex2f(-0.39f, 0.38f);
    glVertex2f(-0.35f, 0.38f);
    glVertex2f(-0.35f, 0.43f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(245,245,245);
   if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.33f, 0.43f);
    glVertex2f(-0.33f, 0.38f);
    glVertex2f(-0.29f, 0.38f);
    glVertex2f(-0.29f, 0.43f);
    glEnd();
    //lower windows
glBegin(GL_QUADS);
     glColor3ub(245,245,245);
     if(night)
   {
       glColor3ub(229,228,2);
   }

    glVertex2f(-0.33f, 0.32f);
    glVertex2f(-0.33f, 0.27f);
    glVertex2f(-0.29f, 0.27f);
    glVertex2f(-0.29f, 0.32f);

    glVertex2f(-0.39f, 0.32f);
    glVertex2f(-0.39f, 0.27f);
    glVertex2f(-0.35f, 0.27f);
    glVertex2f(-0.35f, 0.32f);



    glVertex2f(-0.63f, 0.32f);
    glVertex2f(-0.63f, 0.27f);
    glVertex2f(-0.59f, 0.27f);
    glVertex2f(-0.59f, 0.32f);


    glVertex2f(-0.57f, 0.32f);
    glVertex2f(-0.57f, 0.27f);
    glVertex2f(-0.53f, 0.27f);
    glVertex2f(-0.53f, 0.32f);

    glEnd();
glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-0.51f, 0.32f);
    glVertex2f(-0.51f, 0.24f);
    glVertex2f(-0.41f, 0.24f);
    glVertex2f(-0.41f, 0.32f);
glEnd();



//house-4 moshjid
glBegin(GL_QUADS);
   glColor3ub(128,128,128);
   if(night)
   {
       glColor3ub(87,94,26);
   }

    glVertex2f(-0.24f, 0.53f);
    glVertex2f(-0.19f, 0.34f);
    glVertex2f(-0.01f, 0.34f);
    glVertex2f(0.04f, 0.53f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(169,169,169);

    glVertex2f(-0.26f, 0.56f);
    glVertex2f(-0.26f, 0.53f);
    glVertex2f(0.06f, 0.53f);
    glVertex2f(0.06f, 0.56f);
    glEnd();
  glBegin(GL_QUADS);
    glColor3ub(160,82,45);

    glVertex2f(-0.21f, 0.34f);
    glVertex2f(-0.21f, 0.32f);
    glVertex2f(0.01f, 0.32f);
    glVertex2f(0.01f, 0.34f);
    glEnd();

  glBegin(GL_QUADS);
   glColor3ub(128,128,128);

    glVertex2f(-0.21f, 0.71f);
    glVertex2f(-0.21f, 0.56f);
    glVertex2f(-0.18f, 0.56f);
    glVertex2f(-0.18f, 0.71f);
    glEnd();
glBegin(GL_QUADS);
   glColor3ub(160,82,45);

    glVertex2f(-0.16f, 0.47f);
    glVertex2f(-0.16f, 0.33f);
    glVertex2f(-0.04f, 0.33f);
    glVertex2f(-0.04f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(255,228,196);

    glVertex2f(-0.14f, 0.45f);
    glVertex2f(-0.14f, 0.34f);
    glVertex2f(-0.06f, 0.34f);
    glVertex2f(-0.06f, 0.45f);
    glEnd();
 glBegin(GL_QUADS);
   glColor3ub(0,100,0);

    glVertex2f(-0.115f, 0.42f);
    glVertex2f(-0.115f, 0.34f);
    glVertex2f(-0.09f, 0.34f);
    glVertex2f(-0.09f, 0.42f);
    glEnd();
    glBegin(GL_TRIANGLES);
   glColor3ub(0,100,0);
   glVertex2f(-0.115f, 0.42f);
   glVertex2f(-0.09f, 0.42f);
   glVertex2f(-0.102f, 0.44f);
   glEnd();
    glBegin(GL_TRIANGLES);
   glColor3ub(160,82,45);
   glVertex2f(-0.21f, 0.71f);
   glVertex2f(-0.18f, 0.71f);
   glVertex2f(-0.195f, 0.73f);
   glEnd();

//house-7 AIUB

    //body
    glBegin(GL_QUADS);
   glColor3ub(0,128,128);

    glVertex2f(0.51f, 0.61f);
    glVertex2f(0.51f, 0.38f);
    glVertex2f(0.67f, 0.38f);
    glVertex2f(0.67f, 0.61f);
    glEnd();
     glBegin(GL_QUADS);
   glColor3ub(32,178,170);

    glVertex2f(0.54f, 0.63f);
    glVertex2f(0.54f, 0.61f);
    glVertex2f(0.65f, 0.61f);
    glVertex2f(0.65f, 0.63f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(0,0,128);

    glVertex2f(0.47f, 0.66f);
    glVertex2f(0.47f, 0.38f);
    glVertex2f(0.51f, 0.38f);
    glVertex2f(0.51f, 0.66f);
    glEnd();
    //windows
    glBegin(GL_QUADS);
    glColor3ub(0,250,154);
//1st row
    glVertex2f(0.52f, 0.58f);
    glVertex2f(0.52f, 0.54f);
    glVertex2f(0.54f, 0.54f);
    glVertex2f(0.54f, 0.58f);

    glVertex2f(0.56f, 0.58f);
    glVertex2f(0.56f, 0.54f);
    glVertex2f(0.58f, 0.54f);
    glVertex2f(0.58f, 0.58f);

    glVertex2f(0.60f, 0.58f);
    glVertex2f(0.60f, 0.54f);
    glVertex2f(0.62f, 0.54f);
    glVertex2f(0.62f, 0.58f);

    glVertex2f(0.64f, 0.58f);
    glVertex2f(0.64f, 0.54f);
    glVertex2f(0.66f, 0.54f);
    glVertex2f(0.66f, 0.58f);
    //2nd row
    glVertex2f(0.52f, 0.52f);
    glVertex2f(0.52f, 0.48f);
    glVertex2f(0.54f, 0.48f);
    glVertex2f(0.54f, 0.52f);

    glVertex2f(0.56f, 0.52f);
    glVertex2f(0.56f, 0.48f);
    glVertex2f(0.58f, 0.48f);
    glVertex2f(0.58f, 0.52f);

    glVertex2f(0.60f, 0.52f);
    glVertex2f(0.60f, 0.48f);
    glVertex2f(0.62f, 0.48f);
    glVertex2f(0.62f, 0.52f);

    glVertex2f(0.64f, 0.52f);
    glVertex2f(0.64f, 0.48f);
    glVertex2f(0.66f, 0.48f);
    glVertex2f(0.66f, 0.52f);

    //3rd row

    glVertex2f(0.52f, 0.46f);
    glVertex2f(0.52f, 0.42f);
    glVertex2f(0.54f, 0.42f);
    glVertex2f(0.54f, 0.46f);



    glVertex2f(0.64f, 0.46f);
    glVertex2f(0.64f, 0.42f);
    glVertex2f(0.66f, 0.42f);
    glVertex2f(0.66f, 0.46f);
    glEnd();
//door
glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex2f(0.56f, 0.46f);
    glVertex2f(0.56f, 0.38f);
    glVertex2f(0.62f, 0.38f);
    glVertex2f(0.62f, 0.46f);
glEnd();
//house-5 school
 glBegin(GL_QUADS);
   glColor3ub(255,215,0);
   if(night)
   {
       glColor3ub(166,178,57);
   }

    glVertex2f(0.1f, 0.41f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.52f, 0.2f);
    glVertex2f(0.52f, 0.41f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(160,82,45);
    glVertex2f(0.09f, 0.42f);
    glVertex2f(0.09f, 0.41f);
    glVertex2f(0.53f, 0.41f);
    glVertex2f(0.53f, 0.42f);

    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.09f, 0.2f);
    glVertex2f(0.53f, 0.2f);
    glVertex2f(0.53f, 0.22f);

    glVertex2f(0.26f, 0.35f);
    glVertex2f(0.26f, 0.2f);
    glVertex2f(0.36f, 0.2f);
    glVertex2f(0.36f, 0.35f);

    glEnd();
glBegin(GL_QUADS);
   glColor3ub(139,69,19);
    glVertex2f(0.09f, 0.22f);
    glVertex2f(0.09f, 0.2f);
    glVertex2f(0.53f, 0.2f);
    glVertex2f(0.53f, 0.22f);
   glEnd();

     glBegin(GL_QUADS);
   glColor3ub(255,215,0);
   if(night)
   {
       glColor3ub(166,178,57);
   }

    glVertex2f(0.23f, 0.48f);
    glVertex2f(0.23f, 0.42f);
    glVertex2f(0.39f, 0.42f);
    glVertex2f(0.39f, 0.48f);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3ub(160,82,45);
   glVertex2f(0.21f, 0.48f);
   glVertex2f(0.41f, 0.48f);
   glVertex2f(0.3f, 0.55f);
   glEnd();
   //left side windows
   //1st row
    glBegin(GL_QUADS);
   glColor3ub(255,255,240);

    glVertex2f(0.12f, 0.40f);
    glVertex2f(0.12f, 0.36f);
    glVertex2f(0.15f, 0.36f);
    glVertex2f(0.15f, 0.40f);

    glVertex2f(0.16f, 0.40f);
    glVertex2f(0.16f, 0.36f);
    glVertex2f(0.19f, 0.36f);
    glVertex2f(0.19f, 0.40f);

    glVertex2f(0.20f, 0.40f);
    glVertex2f(0.20f, 0.36f);
    glVertex2f(0.23f, 0.36f);
    glVertex2f(0.23f, 0.40f);
    //2nd row
    glVertex2f(0.12f, 0.34f);
    glVertex2f(0.12f, 0.30f);
    glVertex2f(0.15f, 0.30f);
    glVertex2f(0.15f, 0.34f);

    glVertex2f(0.16f, 0.34f);
    glVertex2f(0.16f, 0.30f);
    glVertex2f(0.19f, 0.30f);
    glVertex2f(0.19f, 0.34f);

    glVertex2f(0.20f, 0.34f);
    glVertex2f(0.20f, 0.30f);
    glVertex2f(0.23f, 0.30f);
    glVertex2f(0.23f, 0.34f);

    //3rd row
    glVertex2f(0.12f, 0.28f);
    glVertex2f(0.12f, 0.24f);
    glVertex2f(0.15f, 0.24f);
    glVertex2f(0.15f, 0.28f);

    glVertex2f(0.16f, 0.28f);
    glVertex2f(0.16f, 0.24f);
    glVertex2f(0.19f, 0.24f);
    glVertex2f(0.19f, 0.28f);

    glVertex2f(0.20f, 0.28f);
    glVertex2f(0.20f, 0.24f);
    glVertex2f(0.23f, 0.24f);
    glVertex2f(0.23f, 0.28f);

    glEnd();

    //right side windows
    glBegin(GL_QUADS);
   glColor3ub(255,255,240);
//1st row
    glVertex2f(0.39f, 0.40f);
    glVertex2f(0.39f, 0.36f);
    glVertex2f(0.42f, 0.36f);
    glVertex2f(0.42f, 0.40f);

    glVertex2f(0.43f, 0.40f);
    glVertex2f(0.43f, 0.36f);
    glVertex2f(0.46f, 0.36f);
    glVertex2f(0.46f, 0.40f);

    glVertex2f(0.47f, 0.40f);
    glVertex2f(0.47f, 0.36f);
    glVertex2f(0.50f, 0.36f);
    glVertex2f(0.50f, 0.40f);
//2nd row

    glVertex2f(0.39f, 0.34f);
    glVertex2f(0.39f, 0.30f);
    glVertex2f(0.42f, 0.30f);
    glVertex2f(0.42f, 0.34f);

    glVertex2f(0.43f, 0.34f);
    glVertex2f(0.43f, 0.30f);
    glVertex2f(0.46f, 0.30f);
    glVertex2f(0.46f, 0.34f);

    glVertex2f(0.47f, 0.34f);
    glVertex2f(0.47f, 0.30f);
    glVertex2f(0.50f, 0.30f);
    glVertex2f(0.50f, 0.34f);

//3rd row
    glVertex2f(0.39f, 0.28f);
    glVertex2f(0.39f, 0.24f);
    glVertex2f(0.42f, 0.24f);
    glVertex2f(0.42f, 0.28f);

    glVertex2f(0.43f, 0.28f);
    glVertex2f(0.43f, 0.24f);
    glVertex2f(0.46f, 0.24f);
    glVertex2f(0.46f, 0.28f);

    glVertex2f(0.47f, 0.28f);
    glVertex2f(0.47f, 0.24f);
    glVertex2f(0.50f, 0.24f);
    glVertex2f(0.50f, 0.28f);

    glEnd();

//house-6
 glBegin(GL_QUADS);
   glColor3ub(255,215,0);
   if(night)
   {
       glColor3ub(166,178,57);
   }

    glVertex2f(0.66f, 0.5f);
    glVertex2f(0.66f, 0.28f);
    glVertex2f(0.98f, 0.28f);
    glVertex2f(0.98f, 0.5f);
    glEnd();
     glBegin(GL_QUADS);
   glColor3ub(240,230,140);

    glVertex2f(0.66f, 0.53f);
    glVertex2f(0.66f, 0.5f);
    glVertex2f(0.7f, 0.5f);
    glVertex2f(0.7f, 0.53f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(240,230,140);

    glVertex2f(0.94f, 0.53f);
    glVertex2f(0.94f, 0.5f);
    glVertex2f(0.98f, 0.5f);
    glVertex2f(0.98f, 0.53f);
    glEnd();
    glBegin(GL_QUADS);
   glColor3ub(240,230,140);

    glVertex2f(0.78f, 0.55f);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.87f, 0.5f);
    glVertex2f(0.87f, 0.55f);
    glEnd();
glBegin(GL_QUADS);
   glColor3ub(178,34,34);

    glVertex2f(0.68f, 0.46f);
    glVertex2f(0.68f, 0.28f);
    glVertex2f(0.765f, 0.28f);
    glVertex2f(0.765f, 0.46f);

    glVertex2f(0.87f, 0.46f);
    glVertex2f(0.87f, 0.28f);
    glVertex2f(0.96f, 0.28f);
    glVertex2f(0.96f, 0.46f);
    glEnd();
    glBegin(GL_QUADS);
    //right side windows
   glColor3ub(0,0,0);
//1st row
    glVertex2f(0.685f, 0.44f);
    glVertex2f(0.685f, 0.40f);
    glVertex2f(0.705f, 0.40f);
    glVertex2f(0.705f, 0.44f);

    glVertex2f(0.71f, 0.44f);
    glVertex2f(0.71f, 0.40f);
    glVertex2f(0.73f, 0.40f);
    glVertex2f(0.73f, 0.44f);

    glVertex2f(0.74f, 0.44f);
    glVertex2f(0.74f, 0.40f);
    glVertex2f(0.76f, 0.40f);
    glVertex2f(0.76f, 0.44f);
//2nd row
    glVertex2f(0.685f, 0.39f);
    glVertex2f(0.685f, 0.35f);
    glVertex2f(0.705f, 0.35f);
    glVertex2f(0.705f, 0.39f);

    glVertex2f(0.71f, 0.39f);
    glVertex2f(0.71f, 0.35f);
    glVertex2f(0.73f, 0.35f);
    glVertex2f(0.73f, 0.39f);

    glVertex2f(0.74f, 0.39f);
    glVertex2f(0.74f, 0.35f);
    glVertex2f(0.76f, 0.35f);
    glVertex2f(0.76f, 0.39f);
    //3rd row
    glVertex2f(0.685f, 0.34f);
    glVertex2f(0.685f, 0.30f);
    glVertex2f(0.705f, 0.30f);
    glVertex2f(0.705f, 0.34f);

    glVertex2f(0.71f, 0.34f);
    glVertex2f(0.71f, 0.30f);
    glVertex2f(0.73f, 0.30f);
    glVertex2f(0.73f, 0.34f);

    glVertex2f(0.74f, 0.34f);
    glVertex2f(0.74f, 0.30f);
    glVertex2f(0.76f, 0.30f);
    glVertex2f(0.76f, 0.34f);
    glEnd();
//left side window
   glBegin(GL_QUADS);
   glColor3ub(0,0,0);
//1st row
    glVertex2f(0.875f, 0.44f);
    glVertex2f(0.875f, 0.40f);
    glVertex2f(0.895f, 0.40f);
    glVertex2f(0.895f, 0.44f);

    glVertex2f(0.90f, 0.44f);
    glVertex2f(0.90f, 0.40f);
    glVertex2f(0.92f, 0.40f);
    glVertex2f(0.92f, 0.44f);

    glVertex2f(0.93f, 0.44f);
    glVertex2f(0.93f, 0.40f);
    glVertex2f(0.95f, 0.40f);
    glVertex2f(0.95f, 0.44f);
    //2nd row
     glVertex2f(0.875f, 0.39f);
    glVertex2f(0.875f, 0.35f);
    glVertex2f(0.895f, 0.35f);
    glVertex2f(0.895f, 0.39f);

    glVertex2f(0.90f, 0.39f);
    glVertex2f(0.90f, 0.35f);
    glVertex2f(0.92f, 0.35f);
    glVertex2f(0.92f, 0.39f);

    glVertex2f(0.93f, 0.39f);
    glVertex2f(0.93f, 0.35f);
    glVertex2f(0.95f, 0.35f);
    glVertex2f(0.95f, 0.39f);

    //3rd row
    glVertex2f(0.875f, 0.34f);
    glVertex2f(0.875f, 0.30f);
    glVertex2f(0.895f, 0.30f);
    glVertex2f(0.895f, 0.34f);

    glVertex2f(0.90f, 0.34f);
    glVertex2f(0.90f, 0.30f);
    glVertex2f(0.92f, 0.30f);
    glVertex2f(0.92f, 0.34f);

    glVertex2f(0.93f, 0.34f);
    glVertex2f(0.93f, 0.30f);
    glVertex2f(0.95f, 0.30f);
    glVertex2f(0.95f, 0.34f);

    glVertex2f(0.80f, 0.40f);
    glVertex2f(0.80f, 0.28f);
    glVertex2f(0.84f, 0.28f);
    glVertex2f(0.84f, 0.40f);

glEnd();
 glBegin(GL_QUADS);
   glColor3ub(255,0,0);

    glVertex2f(0.815f, 0.48f);
    glVertex2f(0.815f, 0.42f);
    glVertex2f(0.825f, 0.42f);
    glVertex2f(0.825f, 0.48f);

    glVertex2f(0.80f, 0.46f);
    glVertex2f(0.80f, 0.44f);
    glVertex2f(0.84f, 0.44f);
    glVertex2f(0.84f, 0.46f);
    glEnd();


    ///-----------------------road light start

    glPushMatrix();
    glTranslatef(1.8f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,0.04f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);

    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);

        glEnd();
    }
    glPopMatrix();

    ///-----------------------road light end

    ///-------------------------------Private car 01 start

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    ///glScalef(1.3,1.3,1.3);

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(0.42f, 0.0175f);
    glVertex2f(0.42f, -0.02f);
    glVertex2f(0.32f, -0.02f);
    glVertex2f(0.33f, 0.0175f);
    glEnd();

    glBegin(GL_QUADS);///------------------------------------------------------------------------------------
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(0.42f, -0.02f);
    glVertex2f(0.42f, -0.067f);
    glVertex2f(0.3f, -0.067f);
    glVertex2f(0.3f, -0.02f);

    glEnd();




//Light....................................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.038f,0.27f);



    glVertex2f(0.306f, -0.02f);
    glVertex2f(0.309f, -0.032f);

    glVertex2f(0.3f, -0.032f);
    glVertex2f(0.3f, -0.02f);
    glEnd();
    if(night)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(0.3f, -0.025f);
        glVertex2f(0.3f, -0.032f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(0.28f, -0.067f);
        glVertex2f(0.25f, -0.067f);

        glEnd();
    }


//back light.............................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.38f,0.27f);

    glVertex2f(0.42f, -0.04f);
    glVertex2f(0.413f, -0.04);
    glVertex2f(0.413f, -0.054f);
    glVertex2f(0.42f, -0.054f);


    glEnd();
//  //BACK SIDE WHELL.......................................................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.42f, -0.018f);
    glVertex2f(0.425f, -0.018f);
    glVertex2f(0.425f, -0.05f);
    glVertex2f(0.42f, -0.053f);



    glEnd();


    //window1..............................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);


    glVertex2f(0.352f, 0.012f);
    glVertex2f(0.352f, -0.02f);
    glVertex2f(0.325f, -0.02f);
    glVertex2f(0.334f, 0.012f);
    glEnd();

    //window2..................
    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.354f, 0.012f);
    glVertex2f(0.354f, -0.02f);
    glVertex2f(0.374f, -0.02f);
    glVertex2f(0.374f, 0.012f);



    glEnd();


    //window3.................................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.41f, 0.012f);
    glVertex2f(0.41f, -0.02f);
    glVertex2f(0.376f, -0.02f);
    glVertex2f(0.376f, 0.012f);



    glEnd();
//
    //Door1..........................................


    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.352f, -0.023f);
    glVertex2f(0.352f, -0.027f);
    glVertex2f(0.344f, -0.027f);
    glVertex2f(0.344f, -0.023f);



    glEnd();

    //Door2..........................................................



    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.373f, -0.023f);
    glVertex2f(0.373f, -0.027f);
    glVertex2f(0.367f, -0.027f);
    glVertex2f(0.367f, -0.023f);



    glEnd();

    //wheel1...................................



    GLfloat xc=0.33f;
    GLfloat yc=-0.067f;
    GLfloat radiusc6 =0.015f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc + (radiusc6 * cos(i *  twicePi / triangleAmount)),
                    yc+ (radiusc6 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc1=0.33f;
    GLfloat yc1=-0.067f;
    GLfloat radiusc7 =0.008f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc1, yc1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc1 + (radiusc7 * cos(i *  twicePi / triangleAmount)),
                    yc1 + (radiusc7 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


//wheel2.................................


    GLfloat xc2=0.39f;
    GLfloat yc2=-0.067f;
    GLfloat radiusc8=0.015f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc2, yc2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc2 + (radiusc8 * cos(i *  twicePi / triangleAmount)),
                    yc2 + (radiusc8 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xc3=0.39f;
    GLfloat yc3=-0.067f;
    GLfloat radiusc9=0.008f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc3, yc3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc3 + (radiusc9 * cos(i *  twicePi / triangleAmount)),
                    yc3 + (radiusc9 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    ///-------------------------------Private car 01 end







    ///-------------------------------bus 01 start


    glPushMatrix();
    glTranslatef(position5,0.0f, 0.0f);
    GLfloat xb1=-0.455f;
    GLfloat yb1=0.095f;
    GLfloat radiusb1 =.01f;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN); ///Bus light
    glVertex2f(xb1, yb1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb1 + (radiusb1 * cos(i *  twicePi / triangleAmount)),
                    yb1 + (radiusb1 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
    if(night)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(-0.445f, 0.097f);
        glVertex2f(-0.455f, 0.095f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(-0.435f, 0.06f);
        glVertex2f(-0.39f, 0.06f);

        glEnd();
    }




    glBegin(GL_QUADS);///-----bus body
    //glColor3f(1.0, 0.5, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-.45,.188);
    glVertex2f(-.45,.06);
    ///glColor3f(0.98, 0.88, 0.02);
    glVertex2f(-.6,.06);
    glVertex2f(-.6,.188);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.00, 0.00, 0.00);
    glColor3ub(0, 153, 178);
    glVertex2f(-.45,.077);
    glVertex2f(-.45,.069);
    glVertex2f(-.46,.069);
    glVertex2f(-.46,.077);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.455f,.17f);
    glVertex2f(-.455f,.12f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-.59f,.12f);
    glVertex2f(-.47f,.12f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-.59f,.1f);
    glVertex2f(-.47f,.1f);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();

    glPushMatrix();
    glTranslatef(-.022,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.044,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.066,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.088,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.11,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.465,.17);
    glVertex2f(-.465,.14);
    glVertex2f(-.48,.14);
    glVertex2f(-.48,.17);
    glEnd();
    glPopMatrix();



    GLfloat xb2=-0.49f;
    GLfloat yb2=0.06f;
    GLfloat radiusb2 =.02f;
    glColor3f(0.10, 0.10, 0.10);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb2, yb2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb2 + (radiusb2 * cos(i *  twicePi / triangleAmount)),
                    yb2 + (radiusb2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xb3=-.49f;
    GLfloat yb3=0.06f;
    GLfloat radiusb3 =.014f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb3, yb3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb3 + (radiusb3 * cos(i *  twicePi / triangleAmount)),
                    yb3 + (radiusb3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb4=-.57f;
    GLfloat yb4=0.06f;
    glColor3f(0.10, 0.10, 0.10 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb4, yb4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb4 + (radiusb2 * cos(i *  twicePi / triangleAmount)),
                    yb4 + (radiusb2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb5=-.57f;
    GLfloat yb5=0.06f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb5, yb5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb5 + (radiusb3 * cos(i *  twicePi / triangleAmount)),
                    yb5 + (radiusb3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

    ///------------------------bus 01 end



    ///-------------------------------bus 02 start


    glPushMatrix();
    glTranslatef(position7,0.0f, 0.0f);
    GLfloat xbb1=-0.596f;
    GLfloat ybb1=-0.095f;
    GLfloat radiusbbb1 =.01f;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN); ///Bus light
    glVertex2f(xbb1, ybb1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xbb1 + (radiusbbb1 * cos(i *  twicePi / triangleAmount)),
                    ybb1 + (radiusbbb1 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    if(night)
    {
        glPushMatrix();
        glTranslatef(-0.9,-0.064,0.0);
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(0.3f, -0.025f);
        glVertex2f(0.3f, -0.032f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(0.28f, -0.067f);
        glVertex2f(0.25f, -0.067f);

        glEnd();
        glPopMatrix();
    }



    glBegin(GL_QUADS);///-----bus body
    //glColor3f(1.0, 0.5, 0.0);
    glColor3ub(255,0,0);
    glVertex2f(-.45,-0.002);
    glVertex2f(-.45,-0.13);
    glVertex2f(-.6,-0.13);
    glVertex2f(-.6,-0.002);
    glEnd();

    glLineWidth(3);///-------bus down line
    glBegin(GL_LINES);
    glColor3ub(0, 153, 178);
    glVertex2f(-0.6, -0.113);
    glVertex2f(-0.59,-0.113);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.5970f,-0.02f);
    glVertex2f(-.5970f,-0.07f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-.59f,-0.07f);
    glVertex2f(-.47f,-0.07f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-.59f,-0.09f);
    glVertex2f(-.47f,-0.09f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 153, 178);
    glVertex2f(-.460,-0.02);
    glVertex2f(-.460,-0.05);
    glVertex2f(-.475,-0.05);
    glVertex2f(-.475,-0.02);
    glEnd();

    glPushMatrix();
    glTranslatef(-.022,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.460,-0.02);
    glVertex2f(-.460,-0.05);
    glVertex2f(-.475,-0.05);
    glVertex2f(-.475,-0.02);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.044,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.460,-0.02);
    glVertex2f(-.460,-0.05);
    glVertex2f(-.475,-0.05);
    glVertex2f(-.475,-0.02);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.066,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.460,-0.02);
    glVertex2f(-.460,-0.05);
    glVertex2f(-.475,-0.05);
    glVertex2f(-.475,-0.02);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.088,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.460,-0.02);
    glVertex2f(-.460,-0.05);
    glVertex2f(-.475,-0.05);
    glVertex2f(-.475,-0.02);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.11,0,0);
    glBegin(GL_QUADS);
    //glColor3f(0.76, 0.77, 0.78);
    glColor3ub(0, 153, 178);
    glVertex2f(-.460,-0.02);
    glVertex2f(-.460,-0.05);
    glVertex2f(-.475,-0.05);
    glVertex2f(-.475,-0.02);
    glEnd();
    glPopMatrix();



    GLfloat xbbb2=-0.49f;
    GLfloat ybb2=-0.124f;
    GLfloat radiusb222 =.02f;
    glColor3f(0.10, 0.10, 0.10);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xbbb2, ybb2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xbbb2 + (radiusb222 * cos(i *  twicePi / triangleAmount)),
                    ybb2 + (radiusb222 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xbb333=-.49f;
    GLfloat ybb3=-0.124f;
    GLfloat radiusbb333 =.014f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xbb333, ybb3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xbb333 + (radiusbb333 * cos(i *  twicePi / triangleAmount)),
                    ybb3 + (radiusbb333 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xb44=-.57f;
    GLfloat ybbb4=-0.124f;
    glColor3f(0.10, 0.10, 0.10 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xb44, ybbb4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xb44 + (radiusb222 * cos(i *  twicePi / triangleAmount)),
                    ybbb4 + (radiusb222 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xbb5=-.57f;
    GLfloat yb55=-0.124f;
    glColor3f(0.47, 0.46, 0.46 );
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xbb5, yb55);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xbb5 + (radiusbb333 * cos(i *  twicePi / triangleAmount)),
                    yb55 + (radiusbb333 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glPopMatrix();

    ///------------------------bus 02 end


    ///----------------------------------car 2 start

    glPushMatrix();
    glTranslatef(position8,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(0.3f, 0.097f);
    glVertex2f(0.40f, 0.097f);
    glVertex2f(0.39f, 0.1345f);
    glVertex2f(0.3f, 0.1345f);
    glEnd();

    glBegin(GL_QUADS);///--------------car 2 body
    glColor3f(0.0f,0.5f,0.0f);
    glVertex2f(0.42f, 0.097f);
    glVertex2f(0.42f, 0.05f);
    glVertex2f(0.3f, 0.05f);
    glVertex2f(0.3f, 0.097f);
    glEnd();


    //window1..............................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);


    glVertex2f(0.368f, 0.129f);
    glVertex2f(0.368f, 0.097f);
    glVertex2f(0.395f, 0.097f);
    glVertex2f(0.386f, 0.129f);
    glEnd();

    //window2..................
    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.366f, 0.129f);
    glVertex2f(0.366f, 0.097f);
    glVertex2f(0.346f, 0.097f);
    glVertex2f(0.346f, 0.129f);



    glEnd();


    //window3.................................

    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.31f, 0.129f);
    glVertex2f(0.31f, 0.097f);
    glVertex2f(0.344f, 0.097f);
    glVertex2f(0.344f, 0.129f);



    glEnd();

    //wheel1...................................



    GLfloat xcCar2=0.33f;
    GLfloat ycCar2= 0.05f;
    GLfloat radiuscCar2 =0.015f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xcCar2, ycCar2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xcCar2 + (radiuscCar2 * cos(i *  twicePi / triangleAmount)),
                    ycCar2+ (radiuscCar2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat xc1Car22=0.33f;
    GLfloat yc1Car22= 0.05f;
    GLfloat radiuscCar22 =0.008f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc1Car22, yc1Car22); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc1Car22 + (radiuscCar22 * cos(i *  twicePi / triangleAmount)),
                    yc1Car22 + (radiuscCar22 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //wheel2.................................


    GLfloat xc2Car22=0.39f;
    GLfloat yc2car22= 0.05f;
    GLfloat radiusc8Car2=0.015f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc2Car22, yc2car22); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc2Car22 + (radiusc8Car2 * cos(i *  twicePi / triangleAmount)),
                    yc2car22 + (radiusc8Car2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat xc3Car22=0.39f;
    GLfloat yc3Car22= 0.05f;
    GLfloat radiusc9Car2=0.008f;

    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc3Car22, yc3Car22); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xc3Car22 + (radiusc9Car2 * cos(i *  twicePi / triangleAmount)),
                    yc3Car22 + (radiusc9Car2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    //Light....................................................................
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.038f,0.27f);
    glVertex2f(0.414f, 0.097f);
    glVertex2f(0.411f, 0.085f);
    glVertex2f(0.42f, 0.085f);
    glVertex2f(0.42f, 0.097f);
    glEnd();
    if(night)
    {
        glPushMatrix();
        glTranslatef(0.87,-0.001,0.0);
        glBegin(GL_QUADS);
        glColor3f(1.0f,0.6f,0.2f);
        glVertex2f(-0.445f, 0.097f);
        glVertex2f(-0.455f, 0.095f);
        glColor3f(1.0f,1.0f,0.79f);
        glVertex2f(-0.435f, 0.06f);
        glVertex2f(-0.39f, 0.06f);
        glEnd();
        glPopMatrix();
    }

//back light.............................................

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.38f,0.27f);

    glVertex2f(0.42f, 0.077f);
    glVertex2f(0.413f, 0.077f);
    glVertex2f(0.413f, 0.063f);
    glVertex2f(0.42f, 0.063f);
    glEnd();
    glPopMatrix();

    /*//BACK SIDE WHELL.......................................................

    //glPushMatrix();
    //glTranslatef(0.77,0.0,0.0);
    glBegin(GL_QUADS);
    glColor3f(0.8f,1.0f,1.0f);

    glVertex2f(0.42f, -0.018f);
    glVertex2f(0.425f, -0.018f);
    glVertex2f(0.425f, -0.05f);
    glVertex2f(0.42f, -0.053f);
    glEnd();
   // glPopMatrix();*/

    glPopMatrix();

    ///-------------------down road light start

    glPushMatrix();
    glTranslatef(-0.01f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.8f,-0.255f,0.0f);
    glBegin(GL_QUADS);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.9025f, 0.21f);
    glVertex2f(-0.8975f, 0.21f);
    glVertex2f(-0.8975f, 0.11f);
    glVertex2f(-0.9025f, 0.11f);

    glColor3f(0.8f,0.9f,1.0f);
    glVertex2f(-0.915f, 0.21f);
    glVertex2f(-0.885f, 0.21f);
    glVertex2f(-0.885f, 0.216f);
    glVertex2f(-0.915f, 0.216f);

    glEnd();

    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f,0.0f);
    if(night)
    {
        glColor3f(0.9f,0.9f,0.0f);
    }
    glVertex2f(-0.915f, 0.213f);

    glVertex2f(-0.885f, 0.213f);
    glEnd();
    if(night)
    {
        //night light
        glBegin(GL_TRIANGLES);
        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.915f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.905f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.95f, 0.12f);

        glColor3f(0.9f,0.9f,0.0f);
        glVertex2f(-0.885f, 0.213f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.895f, 0.12f);
        glColor3f(0.2f,0.2f,0.2f);
        glVertex2f(-0.85f, 0.12f);


        glEnd();
    }
    glPopMatrix();

    ///-------------------down road light end







    ///-------------------------rain 01 start


    if(rain)
    {
    glPushMatrix();
    glTranslatef(0.0f, position11, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.95f);
    glVertex2f(-0.96f, 0.85f);

    glVertex2f(-0.9f, 0.95f);
    glVertex2f(-0.91f, 0.85f);

    glVertex2f(-0.85f, 0.95f);
    glVertex2f(-0.86f, 0.85f);

    glVertex2f(-0.8f, 0.95f);
    glVertex2f(-0.81f, 0.85f);

    glVertex2f(-0.75f, 0.95f);
    glVertex2f(-0.76f, 0.85f);

    glVertex2f(-0.7f, 0.95f);
    glVertex2f(-0.71f, 0.85f);

    glVertex2f(-0.65f, 0.95f);
    glVertex2f(-0.66f, 0.85f);

    glVertex2f(-0.6f, 0.95f);
    glVertex2f(-0.61f, 0.85f);

    glVertex2f(-0.55f, 0.95f);
    glVertex2f(-0.56f, 0.85f);

    glVertex2f(-0.5f, 0.95f);
    glVertex2f(-0.51f, 0.85f);

    glVertex2f(-0.45f, 0.95f);
    glVertex2f(-0.46f, 0.85f);

    glVertex2f(-0.4f, 0.95f);
    glVertex2f(-0.41f, 0.85f);

    glVertex2f(-0.35f, 0.95f);
    glVertex2f(-0.36f, 0.85f);

    glVertex2f(-0.3f, 0.95f);
    glVertex2f(-0.31f, 0.85f);

    glVertex2f(-0.25f, 0.95f);
    glVertex2f(-0.26f, 0.85f);

    glVertex2f(-0.2f, 0.95f);
    glVertex2f(-0.21f, 0.85f);

    glVertex2f(-0.15f, 0.95f);
    glVertex2f(-0.16f, 0.85f);

    glVertex2f(-0.1f, 0.95f);
    glVertex2f(-0.11f, 0.85f);

    glVertex2f(-0.05f, 0.95f);
    glVertex2f(-0.06f, 0.85f);

    glVertex2f(0.0f, 1.0f);
    glVertex2f(-0.01f, 0.85f);

    glVertex2f(0.05f, 0.95f);
    glVertex2f(0.04f, 0.85f);

    glVertex2f(0.10f, 0.95f);
    glVertex2f(0.09f, 0.85f);

    glVertex2f(0.15f, 0.95f);
    glVertex2f(0.14f, 0.85f);

    glVertex2f(0.20f, 0.95f);
    glVertex2f(0.19f, 0.85f);

    glVertex2f(0.25f, 0.95f);
    glVertex2f(0.24f, 0.85f);

    glVertex2f(0.30f, 0.95f);
    glVertex2f(0.29f, 0.85f);

    glVertex2f(0.35f, 0.95f);
    glVertex2f(0.34f, 0.85f);

    glVertex2f(0.40f, 0.95f);
    glVertex2f(0.39f, 0.85f);

    glVertex2f(0.45f, 0.95f);
    glVertex2f(0.44f, 0.85f);

    glVertex2f(0.50f, 0.95f);
    glVertex2f(0.49f, 0.85f);

    glVertex2f(0.55f, 0.95f);
    glVertex2f(0.54f, 0.85f);

    glVertex2f(0.60f, 0.95f);
    glVertex2f(0.59f, 0.85f);

    glVertex2f(0.65f, 0.95f);
    glVertex2f(0.64f, 0.85f);

    glVertex2f(0.70f, 0.95f);
    glVertex2f(0.69f, 0.85f);

    glVertex2f(0.75f, 0.95f);
    glVertex2f(0.74f, 0.85f);

    glVertex2f(0.80f, 0.95f);
    glVertex2f(0.79f, 0.85f);

    glVertex2f(0.85f, 0.95f);
    glVertex2f(0.84f, 0.85f);

    glVertex2f(0.90f, 0.95f);
    glVertex2f(0.89f, 0.85f);

    glVertex2f(0.95f, 0.95f);
    glVertex2f(0.94f, 0.85f);

    glVertex2f(1.0f, 0.95f);
    glVertex2f(0.99f, 0.85f);

    glVertex2f(1.05f, 0.95f);
    glVertex2f(1.04f, 0.85f);

    glEnd();


    ///2nd line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.75f);
    glVertex2f(-0.96f, 0.65f);

    glVertex2f(-0.9f, 0.75f);
    glVertex2f(-0.91f, 0.65f);

    glVertex2f(-0.85f, 0.75f);
    glVertex2f(-0.86f, 0.65f);

    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.81f, 0.65f);

    glVertex2f(-0.75f, 0.75f);
    glVertex2f(-0.76f, 0.65f);

    glVertex2f(-0.7f, 0.75f);
    glVertex2f(-0.71f, 0.65f);

    glVertex2f(-0.65f, 0.75f);
    glVertex2f(-0.66f, 0.65f);

    glVertex2f(-0.6f, 0.75f);
    glVertex2f(-0.61f, 0.65f);

    glVertex2f(-0.55f, 0.75f);
    glVertex2f(-0.56f, 0.65f);

    glVertex2f(-0.5f, 0.75f);
    glVertex2f(-0.51f, 0.65f);

    glVertex2f(-0.45f, 0.75f);
    glVertex2f(-0.46f, 0.65f);

    glVertex2f(-0.4f, 0.75f);
    glVertex2f(-0.41f, 0.65f);

    glVertex2f(-0.35f, 0.75f);
    glVertex2f(-0.36f, 0.65f);

    glVertex2f(-0.3f, 0.75f);
    glVertex2f(-0.31f, 0.65f);

    glVertex2f(-0.25f, 0.75f);
    glVertex2f(-0.26f, 0.65f);

    glVertex2f(-0.2f, 0.75f);
    glVertex2f(-0.21f, 0.65f);

    glVertex2f(-0.15f, 0.75f);
    glVertex2f(-0.16f, 0.65f);

    glVertex2f(-0.1f, 0.75f);
    glVertex2f(-0.11f, 0.65f);

    glVertex2f(-0.05f, 0.75f);
    glVertex2f(-0.06f, 0.65f);

    glVertex2f(0.0f, 0.75f);
    glVertex2f(-0.01f, 0.65f);

    glVertex2f(0.05f, 0.75f);
    glVertex2f(0.04f, 0.65f);

    glVertex2f(0.10f, 0.75f);
    glVertex2f(0.09f, 0.65f);

    glVertex2f(0.15f, 0.75f);
    glVertex2f(0.14f, 0.65f);

    glVertex2f(0.20f, 0.75f);
    glVertex2f(0.19f, 0.65f);

    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.24f, 0.65f);

    glVertex2f(0.30f, 0.75f);
    glVertex2f(0.29f, 0.65f);

    glVertex2f(0.35f, 0.75f);
    glVertex2f(0.34f, 0.65f);

    glVertex2f(0.40f, 0.75f);
    glVertex2f(0.39f, 0.65f);

    glVertex2f(0.45f, 0.75f);
    glVertex2f(0.44f, 0.65f);

    glVertex2f(0.50f, 0.75f);
    glVertex2f(0.49f, 0.65f);

    glVertex2f(0.55f, 0.75f);
    glVertex2f(0.54f, 0.65f);

    glVertex2f(0.60f, 0.75f);
    glVertex2f(0.59f, 0.65f);

    glVertex2f(0.65f, 0.75f);
    glVertex2f(0.64f, 0.65f);

    glVertex2f(0.70f, 0.75f);
    glVertex2f(0.69f, 0.65f);

    glVertex2f(0.75f, 0.75f);
    glVertex2f(0.74f, 0.65f);

    glVertex2f(0.80f, 0.75f);
    glVertex2f(0.79f, 0.65f);

    glVertex2f(0.85f, 0.75f);
    glVertex2f(0.84f, 0.65f);

    glVertex2f(0.90f, 0.75f);
    glVertex2f(0.89f, 0.65f);

    glVertex2f(0.95f, 0.75f);
    glVertex2f(0.94f, 0.65f);

    glVertex2f(1.0f, 0.75f);
    glVertex2f(0.99f, 0.65f);

    glVertex2f(1.05f, 0.75f);
    glVertex2f(1.04f, 0.65f);

    glEnd();

    ///2nd line end

    ///3rd line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.55f);
    glVertex2f(-0.96f, 0.45f);

    glVertex2f(-0.9f, 0.55f);
    glVertex2f(-0.91f, 0.45f);

    glVertex2f(-0.85f, 0.55f);
    glVertex2f(-0.86f, 0.45f);

    glVertex2f(-0.8f, 0.55f);
    glVertex2f(-0.81f, 0.45f);

    glVertex2f(-0.75f, 0.55f);
    glVertex2f(-0.76f, 0.45f);

    glVertex2f(-0.7f, 0.55f);
    glVertex2f(-0.71f, 0.45f);

    glVertex2f(-0.65f, 0.55f);
    glVertex2f(-0.66f, 0.45f);

    glVertex2f(-0.6f, 0.55f);
    glVertex2f(-0.61f, 0.45f);

    glVertex2f(-0.55f, 0.55f);
    glVertex2f(-0.56f, 0.45f);

    glVertex2f(-0.5f, 0.55f);
    glVertex2f(-0.51f, 0.45f);

    glVertex2f(-0.45f, 0.55f);
    glVertex2f(-0.46f, 0.45f);

    glVertex2f(-0.4f, 0.55f);
    glVertex2f(-0.41f, 0.45f);

    glVertex2f(-0.35f, 0.55f);
    glVertex2f(-0.36f, 0.45f);

    glVertex2f(-0.3f, 0.55f);
    glVertex2f(-0.31f, 0.45f);

    glVertex2f(-0.25f, 0.55f);
    glVertex2f(-0.26f, 0.45f);

    glVertex2f(-0.2f, 0.55f);
    glVertex2f(-0.21f, 0.45f);

    glVertex2f(-0.15f, 0.55f);
    glVertex2f(-0.16f, 0.45f);

    glVertex2f(-0.1f, 0.55f);
    glVertex2f(-0.11f, 0.45f);

    glVertex2f(-0.05f, 0.55f);
    glVertex2f(-0.06f, 0.45f);

    glVertex2f(0.0f, 0.55f);
    glVertex2f(-0.01f, 0.45f);

    glVertex2f(0.05f, 0.55f);
    glVertex2f(0.04f, 0.45f);

    glVertex2f(0.10f, 0.55f);
    glVertex2f(0.09f, 0.45f);

    glVertex2f(0.15f, 0.55f);
    glVertex2f(0.14f, 0.45f);

    glVertex2f(0.20f, 0.55f);
    glVertex2f(0.19f, 0.45f);

    glVertex2f(0.25f, 0.55f);
    glVertex2f(0.24f, 0.45f);

    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.29f, 0.45f);

    glVertex2f(0.35f, 0.55f);
    glVertex2f(0.34f, 0.45f);

    glVertex2f(0.40f, 0.55f);
    glVertex2f(0.39f, 0.45f);

    glVertex2f(0.45f, 0.55f);
    glVertex2f(0.44f, 0.45f);

    glVertex2f(0.50f, 0.55f);
    glVertex2f(0.49f, 0.45f);

    glVertex2f(0.55f, 0.55f);
    glVertex2f(0.54f, 0.45f);

    glVertex2f(0.60f, 0.55f);
    glVertex2f(0.59f, 0.45f);

    glVertex2f(0.65f, 0.55f);
    glVertex2f(0.64f, 0.45f);

    glVertex2f(0.70f, 0.55f);
    glVertex2f(0.69f, 0.45f);

    glVertex2f(0.75f, 0.55f);
    glVertex2f(0.74f, 0.45f);

    glVertex2f(0.80f, 0.55f);
    glVertex2f(0.79f, 0.45f);

    glVertex2f(0.85f, 0.55f);
    glVertex2f(0.84f, 0.45f);

    glVertex2f(0.90f, 0.55f);
    glVertex2f(0.89f, 0.45f);

    glVertex2f(0.95f, 0.55f);
    glVertex2f(0.94f, 0.45f);

    glVertex2f(1.0f, 0.55f);
    glVertex2f(0.99f, 0.45f);

    glVertex2f(1.05f, 0.55f);
    glVertex2f(1.04f, 0.45f);

    glEnd();

    ///3rd line end

    ///4th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.96f, 0.25f);

    glVertex2f(-0.9f, 0.35f);
    glVertex2f(-0.91f, 0.25f);

    glVertex2f(-0.85f, 0.35f);
    glVertex2f(-0.86f, 0.25f);

    glVertex2f(-0.8f, 0.35f);
    glVertex2f(-0.81f, 0.25f);

    glVertex2f(-0.75f, 0.35f);
    glVertex2f(-0.76f, 0.25f);

    glVertex2f(-0.7f, 0.35f);
    glVertex2f(-0.71f, 0.25f);

    glVertex2f(-0.65f, 0.35f);
    glVertex2f(-0.66f, 0.25f);

    glVertex2f(-0.6f, 0.35f);
    glVertex2f(-0.61f, 0.25f);

    glVertex2f(-0.55f, 0.35f);
    glVertex2f(-0.56f, 0.25f);

    glVertex2f(-0.5f, 0.35f);
    glVertex2f(-0.51f, 0.25f);

    glVertex2f(-0.45f, 0.35f);
    glVertex2f(-0.46f, 0.25f);

    glVertex2f(-0.4f, 0.35f);
    glVertex2f(-0.41f, 0.25f);

    glVertex2f(-0.35f, 0.35f);
    glVertex2f(-0.36f, 0.25f);

    glVertex2f(-0.3f, 0.35f);
    glVertex2f(-0.31f, 0.25f);

    glVertex2f(-0.25f, 0.35f);
    glVertex2f(-0.26f, 0.25f);

    glVertex2f(-0.2f, 0.35f);
    glVertex2f(-0.21f, 0.25f);

    glVertex2f(-0.15f, 0.35f);
    glVertex2f(-0.16f, 0.25f);

    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.11f, 0.25f);

    glVertex2f(-0.05f, 0.35f);
    glVertex2f(-0.06f, 0.25f);

    glVertex2f(0.0f, 0.35f);
    glVertex2f(-0.01f, 0.25f);

    glVertex2f(0.05f, 0.35f);
    glVertex2f(0.04f, 0.25f);

    glVertex2f(0.10f, 0.35f);
    glVertex2f(0.09f, 0.25f);

    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.14f, 0.25f);

    glVertex2f(0.20f, 0.35f);
    glVertex2f(0.19f, 0.25f);

    glVertex2f(0.25f, 0.35f);
    glVertex2f(0.24f, 0.25f);

    glVertex2f(0.30f, 0.35f);
    glVertex2f(0.29f, 0.25f);

    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.34f, 0.25f);

    glVertex2f(0.40f, 0.35f);
    glVertex2f(0.39f, 0.25f);

    glVertex2f(0.45f, 0.35f);
    glVertex2f(0.44f, 0.25f);

    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.49f, 0.25f);

    glVertex2f(0.55f, 0.35f);
    glVertex2f(0.54f, 0.25f);

    glVertex2f(0.60f, 0.35f);
    glVertex2f(0.59f, 0.25f);

    glVertex2f(0.65f, 0.35f);
    glVertex2f(0.64f, 0.25f);

    glVertex2f(0.70f, 0.35f);
    glVertex2f(0.69f, 0.25f);

    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.74f, 0.25f);

    glVertex2f(0.80f, 0.35f);
    glVertex2f(0.79f, 0.25f);

    glVertex2f(0.85f, 0.35f);
    glVertex2f(0.84f, 0.25f);

    glVertex2f(0.90f, 0.35f);
    glVertex2f(0.89f, 0.25f);

    glVertex2f(0.95f, 0.35f);
    glVertex2f(0.94f, 0.25f);

    glVertex2f(1.0f, 0.35f);
    glVertex2f(0.99f, 0.25f);

    glVertex2f(1.05f, 0.35f);
    glVertex2f(1.04f, 0.25f);

    glEnd();

    ///4th line end

    ///5th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.15f);
    glVertex2f(-0.96f, 0.05f);

    glVertex2f(-0.9f, 0.15f);
    glVertex2f(-0.91f, 0.05f);

    glVertex2f(-0.85f, 0.15f);
    glVertex2f(-0.86f, 0.05f);

    glVertex2f(-0.8f, 0.15f);
    glVertex2f(-0.81f, 0.05f);

    glVertex2f(-0.75f, 0.15f);
    glVertex2f(-0.76f, 0.05f);

    glVertex2f(-0.7f, 0.15f);
    glVertex2f(-0.71f, 0.05f);

    glVertex2f(-0.65f, 0.15f);
    glVertex2f(-0.66f, 0.05f);

    glVertex2f(-0.6f, 0.15f);
    glVertex2f(-0.61f, 0.05f);

    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.56f, 0.05f);

    glVertex2f(-0.5f, 0.15f);
    glVertex2f(-0.51f, 0.05f);

    glVertex2f(-0.45f, 0.15f);
    glVertex2f(-0.46f, 0.05f);

    glVertex2f(-0.4f, 0.15f);
    glVertex2f(-0.41f, 0.05f);

    glVertex2f(-0.35f, 0.15f);
    glVertex2f(-0.36f, 0.05f);

    glVertex2f(-0.3f, 0.15f);
    glVertex2f(-0.31f, 0.05f);

    glVertex2f(-0.25f, 0.15f);
    glVertex2f(-0.26f, 0.05f);

    glVertex2f(-0.2f, 0.15f);
    glVertex2f(-0.21f, 0.05f);

    glVertex2f(-0.15f, 0.15f);
    glVertex2f(-0.16f, 0.05f);

    glVertex2f(-0.1f, 0.15f);
    glVertex2f(-0.11f, 0.05f);

    glVertex2f(-0.05f, 0.15f);
    glVertex2f(-0.06f, 0.05f);

    glVertex2f(0.0f, 0.15f);
    glVertex2f(-0.01f, 0.05f);

    glVertex2f(0.05f, 0.15f);
    glVertex2f(0.04f, 0.05f);

    glVertex2f(0.10f, 0.15f);
    glVertex2f(0.09f, 0.05f);

    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.14f, 0.05f);

    glVertex2f(0.20f, 0.15f);
    glVertex2f(0.19f, 0.05f);

    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.24f, 0.05f);

    glVertex2f(0.30f, 0.15f);
    glVertex2f(0.29f, 0.05f);

    glVertex2f(0.35f, 0.15f);
    glVertex2f(0.34f, 0.05f);

    glVertex2f(0.40f, 0.15f);
    glVertex2f(0.39f, 0.05f);

    glVertex2f(0.45f, 0.15f);
    glVertex2f(0.44f, 0.05f);

    glVertex2f(0.50f, 0.15f);
    glVertex2f(0.49f, 0.05f);

    glVertex2f(0.55f, 0.15f);
    glVertex2f(0.54f, 0.05f);

    glVertex2f(0.60f, 0.15f);
    glVertex2f(0.59f, 0.05f);

    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.64f, 0.05f);

    glVertex2f(0.70f, 0.15f);
    glVertex2f(0.69f, 0.05f);

    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.74f, 0.05f);

    glVertex2f(0.80f, 0.15f);
    glVertex2f(0.79f, 0.05f);

    glVertex2f(0.85f, 0.15f);
    glVertex2f(0.84f, 0.05f);

    glVertex2f(0.90f, 0.15f);
    glVertex2f(0.89f, 0.05f);

    glVertex2f(0.95f, 0.15f);
    glVertex2f(0.94f, 0.05f);

    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.99f, 0.05f);

    glVertex2f(1.05f, 0.15f);
    glVertex2f(1.04f, 0.05f);

    glEnd();

    ///5th line end

    ///6th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.05f);
    glVertex2f(-0.96f, -0.15f);

    glVertex2f(-0.9f, -0.05f);
    glVertex2f(-0.91f, -0.15f);

    glVertex2f(-0.85f, -0.05f);
    glVertex2f(-0.86f, -0.15f);

    glVertex2f(-0.8f, -0.05f);
    glVertex2f(-0.81f, -0.15f);

    glVertex2f(-0.75f, -0.05f);
    glVertex2f(-0.76f, -0.15f);

    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.71f, -0.15f);

    glVertex2f(-0.65f, -0.05f);
    glVertex2f(-0.66f, -0.15f);

    glVertex2f(-0.6f, -0.05f);
    glVertex2f(-0.61f, -0.15f);

    glVertex2f(-0.55f, -0.05f);
    glVertex2f(-0.56f, -0.15f);

    glVertex2f(-0.5f, -0.05f);
    glVertex2f(-0.51f, -0.15f);

    glVertex2f(-0.45f, -0.05f);
    glVertex2f(-0.46f, -0.15f);

    glVertex2f(-0.4f, -0.05f);
    glVertex2f(-0.41f, -0.15f);

    glVertex2f(-0.35f, -0.05f);
    glVertex2f(-0.36f, -0.15f);

    glVertex2f(-0.3f, -0.05f);
    glVertex2f(-0.31f, -0.15f);

    glVertex2f(-0.25f, -0.05f);
    glVertex2f(-0.26f, -0.15f);

    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.21f, -0.15f);

    glVertex2f(-0.15f, -0.05f);
    glVertex2f(-0.16f, -0.15f);

    glVertex2f(-0.1f, -0.05f);
    glVertex2f(-0.11f, -0.15f);

    glVertex2f(-0.05f, -0.05f);
    glVertex2f(-0.06f, -0.15f);

    glVertex2f(0.0f, -0.05f);
    glVertex2f(-0.01f, -0.15f);

    glVertex2f(0.05f, -0.05f);
    glVertex2f(0.04f, -0.15f);

    glVertex2f(0.10f, -0.05f);
    glVertex2f(0.09f, -0.15f);

    glVertex2f(0.15f, -0.05f);
    glVertex2f(0.14f, -0.15f);

    glVertex2f(0.20f, -0.05f);
    glVertex2f(0.19f, -0.15f);

    glVertex2f(0.25f, -0.05f);
    glVertex2f(0.24f, -0.15f);

    glVertex2f(0.30f, -0.05f);
    glVertex2f(0.29f, -0.15f);

    glVertex2f(0.35f, -0.05f);
    glVertex2f(0.34f, -0.15f);

    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.39f, -0.15f);

    glVertex2f(0.45f, -0.05f);
    glVertex2f(0.44f, -0.15f);

    glVertex2f(0.50f, -0.05f);
    glVertex2f(0.49f, -0.15f);

    glVertex2f(0.55f, -0.05f);
    glVertex2f(0.54f, -0.15f);

    glVertex2f(0.60f, -0.05f);
    glVertex2f(0.59f, -0.15f);

    glVertex2f(0.65f, -0.05f);
    glVertex2f(0.64f, -0.15f);

    glVertex2f(0.70f, -0.05f);
    glVertex2f(0.69f, -0.15f);

    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.74f, -0.15f);

    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.79f, -0.15f);

    glVertex2f(0.85f, -0.05f);
    glVertex2f(0.84f, -0.15f);

    glVertex2f(0.90f, -0.05f);
    glVertex2f(0.89f, -0.15f);

    glVertex2f(0.95f, -0.05f);
    glVertex2f(0.94f, -0.15f);

    glVertex2f(1.0f, -0.05f);
    glVertex2f(0.99f, -0.15f);

    glVertex2f(1.05f, -0.05f);
    glVertex2f(1.04f, -0.15f);

    glEnd();

    ///6th line end


    ///7th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.25f);
    glVertex2f(-0.96f, -0.35f);

    glVertex2f(-0.9f, -0.25f);
    glVertex2f(-0.91f, -0.35f);

    glVertex2f(-0.85f, -0.25f);
    glVertex2f(-0.86f, -0.35f);

    glVertex2f(-0.8f, -0.25f);
    glVertex2f(-0.81f, -0.35f);

    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.76f, -0.35f);

    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.71f, -0.35f);

    glVertex2f(-0.65f, -0.25f);
    glVertex2f(-0.66f, -0.35f);

    glVertex2f(-0.6f, -0.25f);
    glVertex2f(-0.61f, -0.35f);

    glVertex2f(-0.55f, -0.25f);
    glVertex2f(-0.56f, -0.35f);

    glVertex2f(-0.5f, -0.25f);
    glVertex2f(-0.51f, -0.35f);

    glVertex2f(-0.45f, -0.25f);
    glVertex2f(-0.46f, -0.35f);

    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.41f, -0.35f);

    glVertex2f(-0.35f, -0.25f);
    glVertex2f(-0.36f, -0.35f);

    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.31f, -0.35f);

    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.26f, -0.35f);

    glVertex2f(-0.2f, -0.25f);
    glVertex2f(-0.21f, -0.35f);

    glVertex2f(-0.15f, -0.25f);
    glVertex2f(-0.16f, -0.35f);

    glVertex2f(-0.1f, -0.25f);
    glVertex2f(-0.11f, -0.35f);

    glVertex2f(-0.05f, -0.25f);
    glVertex2f(-0.06f, -0.35f);

    glVertex2f(0.0f, -0.25f);
    glVertex2f(-0.01f, -0.35f);

    glVertex2f(0.05f, -0.25f);
    glVertex2f(0.04f, -0.35f);

    glVertex2f(0.10f, -0.25f);
    glVertex2f(0.09f, -0.35f);

    glVertex2f(0.15f, -0.25f);
    glVertex2f(0.14f, -0.35f);

    glVertex2f(0.20f, -0.25f);
    glVertex2f(0.19f, -0.35f);

    glVertex2f(0.25f, -0.25f);
    glVertex2f(0.24f, -0.35f);

    glVertex2f(0.30f, -0.25f);
    glVertex2f(0.29f, -0.35f);

    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.34f, -0.35f);

    glVertex2f(0.40f, -0.25f);
    glVertex2f(0.39f, -0.35f);

    glVertex2f(0.45f, -0.25f);
    glVertex2f(0.44f, -0.35f);

    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.49f, -0.35f);

    glVertex2f(0.55f, -0.25f);
    glVertex2f(0.54f, -0.35f);

    glVertex2f(0.60f, -0.25f);
    glVertex2f(0.59f, -0.35f);

    glVertex2f(0.65f, -0.25f);
    glVertex2f(0.64f, -0.35f);

    glVertex2f(0.70f, -0.25f);
    glVertex2f(0.69f, -0.35f);

    glVertex2f(0.75f, -0.25f);
    glVertex2f(0.74f, -0.35f);

    glVertex2f(0.80f, -0.25f);
    glVertex2f(0.79f, -0.35f);

    glVertex2f(0.85f, -0.25f);
    glVertex2f(0.84f, -0.35f);

    glVertex2f(0.90f, -0.25f);
    glVertex2f(0.89f, -0.35f);

    glVertex2f(0.95f, -0.25f);
    glVertex2f(0.94f, -0.35f);

    glVertex2f(1.0f, -0.25f);
    glVertex2f(0.99f, -0.35f);

    glVertex2f(1.05f, -0.25f);
    glVertex2f(1.04f, -0.35f);

    glEnd();

    ///7th line end

    ///8th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.45f);
    glVertex2f(-0.96f, -0.55f);

    glVertex2f(-0.9f, -0.45f);
    glVertex2f(-0.91f, -0.55f);

    glVertex2f(-0.85f, -0.45f);
    glVertex2f(-0.86f, -0.55f);

    glVertex2f(-0.8f, -0.45f);
    glVertex2f(-0.81f, -0.55f);

    glVertex2f(-0.75f, -0.45f);
    glVertex2f(-0.76f, -0.55f);

    glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.71f, -0.55f);

    glVertex2f(-0.65f, -0.45f);
    glVertex2f(-0.66f, -0.55f);

    glVertex2f(-0.6f, -0.45f);
    glVertex2f(-0.61f, -0.55f);

    glVertex2f(-0.55f, -0.45f);
    glVertex2f(-0.56f, -0.55f);

    glVertex2f(-0.5f, -0.45f);
    glVertex2f(-0.51f, -0.55f);

    glVertex2f(-0.45f, -0.45f);
    glVertex2f(-0.46f, -0.55f);

    glVertex2f(-0.4f, -0.45f);
    glVertex2f(-0.41f, -0.55f);

    glVertex2f(-0.35f, -0.45f);
    glVertex2f(-0.36f, -0.55f);

    glVertex2f(-0.3f, -0.45f);
    glVertex2f(-0.31f, -0.55f);

    glVertex2f(-0.25f, -0.45f);
    glVertex2f(-0.26f, -0.55f);

    glVertex2f(-0.2f, -0.45f);
    glVertex2f(-0.21f, -0.55f);

    glVertex2f(-0.15f, -0.45f);
    glVertex2f(-0.16f, -0.55f);

    glVertex2f(-0.1f, -0.45f);
    glVertex2f(-0.11f, -0.55f);

    glVertex2f(-0.05f, -0.45f);
    glVertex2f(-0.06f, -0.55f);

    glVertex2f(0.0f, -0.45f);
    glVertex2f(-0.01f, -0.55f);

    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.04f, -0.55f);

    glVertex2f(0.10f, -0.45f);
    glVertex2f(0.09f, -0.55f);

    glVertex2f(0.15f, -0.45f);
    glVertex2f(0.14f, -0.55f);

    glVertex2f(0.20f, -0.45f);
    glVertex2f(0.19f, -0.55f);

    glVertex2f(0.25f, -0.45f);
    glVertex2f(0.24f, -0.55f);

    glVertex2f(0.30f, -0.45f);
    glVertex2f(0.29f, -0.55f);

    glVertex2f(0.35f, -0.45f);
    glVertex2f(0.34f, -0.55f);

    glVertex2f(0.40f, -0.45f);
    glVertex2f(0.39f, -0.55f);

    glVertex2f(0.45f, -0.45f);
    glVertex2f(0.44f, -0.55f);

    glVertex2f(0.50f, -0.45f);
    glVertex2f(0.49f, -0.55f);

    glVertex2f(0.55f, -0.45f);
    glVertex2f(0.54f, -0.55f);

    glVertex2f(0.60f, -0.45f);
    glVertex2f(0.59f, -0.55f);

    glVertex2f(0.65f, -0.45f);
    glVertex2f(0.64f, -0.55f);

    glVertex2f(0.70f, -0.45f);
    glVertex2f(0.69f, -0.55f);

    glVertex2f(0.75f, -0.45f);
    glVertex2f(0.74f, -0.55f);

    glVertex2f(0.80f, -0.45f);
    glVertex2f(0.79f, -0.55f);

    glVertex2f(0.85f, -0.45f);
    glVertex2f(0.84f, -0.55f);

    glVertex2f(0.90f, -0.45f);
    glVertex2f(0.89f, -0.55f);

    glVertex2f(0.95f, -0.45f);
    glVertex2f(0.94f, -0.55f);

    glVertex2f(1.0f, -0.45f);
    glVertex2f(0.99f, -0.55f);

    glVertex2f(1.05f, -0.45f);
    glVertex2f(1.04f, -0.55f);

    glEnd();

    ///8th line end

    ///9th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.65f);
    glVertex2f(-0.96f, -0.75f);

    glVertex2f(-0.9f, -0.65f);
    glVertex2f(-0.91f, -0.75f);

    glVertex2f(-0.85f, -0.65f);
    glVertex2f(-0.86f, -0.75f);

    glVertex2f(-0.8f, -0.65f);
    glVertex2f(-0.81f, -0.75f);

    glVertex2f(-0.75f, -0.65f);
    glVertex2f(-0.76f, -0.75f);

    glVertex2f(-0.7f, -0.65f);
    glVertex2f(-0.71f, -0.75f);

    glVertex2f(-0.65f, -0.65f);
    glVertex2f(-0.66f, -0.75f);

    glVertex2f(-0.6f, -0.65f);
    glVertex2f(-0.61f, -0.75f);

    glVertex2f(-0.55f, -0.65f);
    glVertex2f(-0.56f, -0.75f);

    glVertex2f(-0.5f, -0.65f);
    glVertex2f(-0.51f, -0.75f);

    glVertex2f(-0.45f, -0.65f);
    glVertex2f(-0.46f, -0.75f);

    glVertex2f(-0.4f, -0.65f);
    glVertex2f(-0.41f, -0.75f);

    glVertex2f(-0.35f, -0.65f);
    glVertex2f(-0.36f, -0.75f);

    glVertex2f(-0.3f, -0.65f);
    glVertex2f(-0.31f, -0.75f);

    glVertex2f(-0.25f, -0.65f);
    glVertex2f(-0.26f, -0.75f);

    glVertex2f(-0.2f, -0.65f);
    glVertex2f(-0.21f, -0.75f);

    glVertex2f(-0.15f, -0.65f);
    glVertex2f(-0.16f, -0.75f);

    glVertex2f(-0.1f, -0.65f);
    glVertex2f(-0.11f, -0.75f);

    glVertex2f(-0.05f, -0.65f);
    glVertex2f(-0.06f, -0.75f);

    glVertex2f(0.0f, -0.65f);
    glVertex2f(-0.01f, -0.75f);

    glVertex2f(0.05f, -0.65f);
    glVertex2f(0.04f, -0.75f);

    glVertex2f(0.10f, -0.65f);
    glVertex2f(0.09f, -0.75f);

    glVertex2f(0.15f, -0.65f);
    glVertex2f(0.14f, -0.75f);

    glVertex2f(0.20f, -0.65f);
    glVertex2f(0.19f, -0.75f);

    glVertex2f(0.25f, -0.65f);
    glVertex2f(0.24f, -0.75f);

    glVertex2f(0.30f, -0.65f);
    glVertex2f(0.29f, -0.75f);

    glVertex2f(0.35f, -0.65f);
    glVertex2f(0.34f, -0.75f);

    glVertex2f(0.40f, -0.65f);
    glVertex2f(0.39f, -0.75f);

    glVertex2f(0.45f, -0.65f);
    glVertex2f(0.44f, -0.75f);

    glVertex2f(0.50f, -0.65f);
    glVertex2f(0.49f, -0.75f);

    glVertex2f(0.55f, -0.65f);
    glVertex2f(0.54f, -0.75f);

    glVertex2f(0.60f, -0.65f);
    glVertex2f(0.59f, -0.75f);

    glVertex2f(0.65f, -0.65f);
    glVertex2f(0.64f, -0.75f);

    glVertex2f(0.70f, -0.65f);
    glVertex2f(0.69f, -0.75f);

    glVertex2f(0.75f, -0.65f);
    glVertex2f(0.74f, -0.75f);

    glVertex2f(0.80f, -0.65f);
    glVertex2f(0.79f, -0.75f);

    glVertex2f(0.85f, -0.65f);
    glVertex2f(0.84f, -0.75f);

    glVertex2f(0.90f, -0.65f);
    glVertex2f(0.89f, -0.75f);

    glVertex2f(0.95f, -0.65f);
    glVertex2f(0.94f, -0.75f);

    glVertex2f(1.0f, -0.65f);
    glVertex2f(0.99f, -0.75f);

    glVertex2f(1.05f, -0.65f);
    glVertex2f(1.04f, -0.75f);

    glEnd();

    ///9th line end


     ///10th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.85f);
    glVertex2f(-0.96f, -0.95f);

    glVertex2f(-0.9f, -0.85f);
    glVertex2f(-0.91f, -0.95f);

    glVertex2f(-0.85f, -0.85f);
    glVertex2f(-0.86f, -0.95f);

    glVertex2f(-0.8f, -0.85f);
    glVertex2f(-0.81f, -0.95f);

    glVertex2f(-0.75f, -0.85f);
    glVertex2f(-0.76f, -0.95f);

    glVertex2f(-0.7f, -0.85f);
    glVertex2f(-0.71f, -0.95f);

    glVertex2f(-0.65f, -0.85f);
    glVertex2f(-0.66f, -0.95f);

    glVertex2f(-0.6f, -0.85f);
    glVertex2f(-0.61f, -0.95f);

    glVertex2f(-0.55f, -0.85f);
    glVertex2f(-0.56f, -0.95f);

    glVertex2f(-0.5f, -0.85f);
    glVertex2f(-0.51f, -0.95f);

    glVertex2f(-0.45f, -0.85f);
    glVertex2f(-0.46f, -0.95f);

    glVertex2f(-0.4f, -0.85f);
    glVertex2f(-0.41f, -0.95f);

    glVertex2f(-0.35f, -0.85f);
    glVertex2f(-0.36f, -0.95f);

    glVertex2f(-0.3f, -0.85f);
    glVertex2f(-0.31f, -0.95f);

    glVertex2f(-0.25f, -0.85f);
    glVertex2f(-0.26f, -0.95f);

    glVertex2f(-0.2f, -0.85f);
    glVertex2f(-0.21f, -0.95f);

    glVertex2f(-0.15f, -0.85f);
    glVertex2f(-0.16f, -0.95f);

    glVertex2f(-0.1f, -0.85f);
    glVertex2f(-0.11f, -0.95f);

    glVertex2f(-0.05f, -0.85f);
    glVertex2f(-0.06f, -0.95f);

    glVertex2f(0.0f, -0.85f);
    glVertex2f(-0.01f, -0.95f);

    glVertex2f(0.05f, -0.85f);
    glVertex2f(0.04f, -0.95f);

    glVertex2f(0.10f, -0.85f);
    glVertex2f(0.09f, -0.95f);

    glVertex2f(0.15f, -0.85f);
    glVertex2f(0.14f, -0.95f);

    glVertex2f(0.20f, -0.85f);
    glVertex2f(0.19f, -0.95f);

    glVertex2f(0.25f, -0.85f);
    glVertex2f(0.24f, -0.95f);

    glVertex2f(0.30f, -0.85f);
    glVertex2f(0.29f, -0.95f);

    glVertex2f(0.35f, -0.85f);
    glVertex2f(0.34f, -0.95f);

    glVertex2f(0.40f, -0.85f);
    glVertex2f(0.39f, -0.95f);

    glVertex2f(0.45f, -0.85f);
    glVertex2f(0.44f, -0.95f);

    glVertex2f(0.50f, -0.85f);
    glVertex2f(0.49f, -0.95f);

    glVertex2f(0.55f, -0.85f);
    glVertex2f(0.54f, -1.0f);

    glVertex2f(0.60f, -0.85f);
    glVertex2f(0.59f, -0.95f);

    glVertex2f(0.65f, -0.85f);
    glVertex2f(0.64f, -0.95f);

    glVertex2f(0.70f, -0.85f);
    glVertex2f(0.69f, -0.95f);

    glVertex2f(0.75f, -0.85f);
    glVertex2f(0.74f, -0.95f);

    glVertex2f(0.80f, -0.85f);
    glVertex2f(0.79f, -0.95f);

    glVertex2f(0.85f, -0.85f);
    glVertex2f(0.84f, -0.95f);

    glVertex2f(0.90f, -0.85f);
    glVertex2f(0.89f, -0.95f);

    glVertex2f(0.95f, -0.85f);
    glVertex2f(0.94f, -0.95f);

    glVertex2f(1.0f, -0.85f);
    glVertex2f(0.99f, -0.95f);

    glVertex2f(1.05f, -0.85f);
    glVertex2f(1.04f, -0.95f);

    glEnd();
    glPopMatrix();
    }

    ///10th line end

    ///------------------------------rain 01 end

    ///-------------------------rain 02 start


    if(rain)
    {
        glPushMatrix();
    glTranslatef(0.0f, position12, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.95f);
    glVertex2f(-0.96f, 0.85f);

    glVertex2f(-0.9f, 0.95f);
    glVertex2f(-0.91f, 0.85f);

    glVertex2f(-0.85f, 0.95f);
    glVertex2f(-0.86f, 0.85f);

    glVertex2f(-0.8f, 0.95f);
    glVertex2f(-0.81f, 0.85f);

    glVertex2f(-0.75f, 0.95f);
    glVertex2f(-0.76f, 0.85f);

    glVertex2f(-0.7f, 0.95f);
    glVertex2f(-0.71f, 0.85f);

    glVertex2f(-0.65f, 0.95f);
    glVertex2f(-0.66f, 0.85f);

    glVertex2f(-0.6f, 0.95f);
    glVertex2f(-0.61f, 0.85f);

    glVertex2f(-0.55f, 0.95f);
    glVertex2f(-0.56f, 0.85f);

    glVertex2f(-0.5f, 0.95f);
    glVertex2f(-0.51f, 0.85f);

    glVertex2f(-0.45f, 0.95f);
    glVertex2f(-0.46f, 0.85f);

    glVertex2f(-0.4f, 0.95f);
    glVertex2f(-0.41f, 0.85f);

    glVertex2f(-0.35f, 0.95f);
    glVertex2f(-0.36f, 0.85f);

    glVertex2f(-0.3f, 0.95f);
    glVertex2f(-0.31f, 0.85f);

    glVertex2f(-0.25f, 0.95f);
    glVertex2f(-0.26f, 0.85f);

    glVertex2f(-0.2f, 0.95f);
    glVertex2f(-0.21f, 0.85f);

    glVertex2f(-0.15f, 0.95f);
    glVertex2f(-0.16f, 0.85f);

    glVertex2f(-0.1f, 0.95f);
    glVertex2f(-0.11f, 0.85f);

    glVertex2f(-0.05f, 0.95f);
    glVertex2f(-0.06f, 0.85f);

    glVertex2f(0.0f, 0.95f);
    glVertex2f(-0.01f, 0.85f);

    glVertex2f(0.05f, 0.95f);
    glVertex2f(0.04f, 0.85f);

    glVertex2f(0.10f, 0.95f);
    glVertex2f(0.09f, 0.85f);

    glVertex2f(0.15f, 0.95f);
    glVertex2f(0.14f, 0.85f);

    glVertex2f(0.20f, 0.95f);
    glVertex2f(0.19f, 0.85f);

    glVertex2f(0.25f, 0.95f);
    glVertex2f(0.24f, 0.85f);

    glVertex2f(0.30f, 0.95f);
    glVertex2f(0.29f, 0.85f);

    glVertex2f(0.35f, 0.95f);
    glVertex2f(0.34f, 0.85f);

    glVertex2f(0.40f, 1.0f);
    glVertex2f(0.39f, 0.85f);

    glVertex2f(0.45f, 0.95f);
    glVertex2f(0.44f, 0.85f);

    glVertex2f(0.50f, 0.95f);
    glVertex2f(0.49f, 0.85f);

    glVertex2f(0.55f, 0.95f);
    glVertex2f(0.54f, 0.85f);

    glVertex2f(0.60f, 0.95f);
    glVertex2f(0.59f, 0.85f);

    glVertex2f(0.65f, 0.95f);
    glVertex2f(0.64f, 0.85f);

    glVertex2f(0.70f, 0.95f);
    glVertex2f(0.69f, 0.85f);

    glVertex2f(0.75f, 0.95f);
    glVertex2f(0.74f, 0.85f);

    glVertex2f(0.80f, 0.95f);
    glVertex2f(0.79f, 0.85f);

    glVertex2f(0.85f, 0.95f);
    glVertex2f(0.84f, 0.85f);

    glVertex2f(0.90f, 0.95f);
    glVertex2f(0.89f, 0.85f);

    glVertex2f(0.95f, 0.95f);
    glVertex2f(0.94f, 0.85f);

    glVertex2f(1.0f, 0.95f);
    glVertex2f(0.99f, 0.85f);

    glVertex2f(1.05f, 0.95f);
    glVertex2f(1.04f, 0.85f);

    glEnd();


    ///2nd line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.75f);
    glVertex2f(-0.96f, 0.65f);

    glVertex2f(-0.9f, 0.75f);
    glVertex2f(-0.91f, 0.65f);

    glVertex2f(-0.85f, 0.75f);
    glVertex2f(-0.86f, 0.65f);

    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.81f, 0.65f);

    glVertex2f(-0.75f, 0.75f);
    glVertex2f(-0.76f, 0.65f);

    glVertex2f(-0.7f, 0.75f);
    glVertex2f(-0.71f, 0.65f);

    glVertex2f(-0.65f, 0.75f);
    glVertex2f(-0.66f, 0.65f);

    glVertex2f(-0.6f, 0.75f);
    glVertex2f(-0.61f, 0.65f);

    glVertex2f(-0.55f, 0.75f);
    glVertex2f(-0.56f, 0.65f);

    glVertex2f(-0.5f, 0.75f);
    glVertex2f(-0.51f, 0.65f);

    glVertex2f(-0.45f, 0.75f);
    glVertex2f(-0.46f, 0.65f);

    glVertex2f(-0.4f, 0.75f);
    glVertex2f(-0.41f, 0.65f);

    glVertex2f(-0.35f, 0.75f);
    glVertex2f(-0.36f, 0.65f);

    glVertex2f(-0.3f, 0.75f);
    glVertex2f(-0.31f, 0.65f);

    glVertex2f(-0.25f, 0.75f);
    glVertex2f(-0.26f, 0.65f);

    glVertex2f(-0.2f, 0.75f);
    glVertex2f(-0.21f, 0.65f);

    glVertex2f(-0.15f, 0.75f);
    glVertex2f(-0.16f, 0.65f);

    glVertex2f(-0.1f, 0.75f);
    glVertex2f(-0.11f, 0.65f);

    glVertex2f(-0.05f, 0.75f);
    glVertex2f(-0.06f, 0.65f);

    glVertex2f(0.0f, 0.75f);
    glVertex2f(-0.01f, 0.65f);

    glVertex2f(0.05f, 0.75f);
    glVertex2f(0.04f, 0.65f);

    glVertex2f(0.10f, 0.75f);
    glVertex2f(0.09f, 0.65f);

    glVertex2f(0.15f, 0.75f);
    glVertex2f(0.14f, 0.65f);

    glVertex2f(0.20f, 0.75f);
    glVertex2f(0.19f, 0.65f);

    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.24f, 0.65f);

    glVertex2f(0.30f, 0.75f);
    glVertex2f(0.29f, 0.65f);

    glVertex2f(0.35f, 0.75f);
    glVertex2f(0.34f, 0.65f);

    glVertex2f(0.40f, 0.75f);
    glVertex2f(0.39f, 0.65f);

    glVertex2f(0.45f, 0.75f);
    glVertex2f(0.44f, 0.65f);

    glVertex2f(0.50f, 0.75f);
    glVertex2f(0.49f, 0.65f);

    glVertex2f(0.55f, 0.75f);
    glVertex2f(0.54f, 0.65f);

    glVertex2f(0.60f, 0.75f);
    glVertex2f(0.59f, 0.65f);

    glVertex2f(0.65f, 0.75f);
    glVertex2f(0.64f, 0.65f);

    glVertex2f(0.70f, 0.75f);
    glVertex2f(0.69f, 0.65f);

    glVertex2f(0.75f, 0.75f);
    glVertex2f(0.74f, 0.65f);

    glVertex2f(0.80f, 0.75f);
    glVertex2f(0.79f, 0.65f);

    glVertex2f(0.85f, 0.75f);
    glVertex2f(0.84f, 0.65f);

    glVertex2f(0.90f, 0.75f);
    glVertex2f(0.89f, 0.65f);

    glVertex2f(0.95f, 0.75f);
    glVertex2f(0.94f, 0.65f);

    glVertex2f(1.0f, 0.75f);
    glVertex2f(0.99f, 0.65f);

    glVertex2f(1.05f, 0.75f);
    glVertex2f(1.04f, 0.65f);

    glEnd();

    ///2nd line end

    ///3rd line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.55f);
    glVertex2f(-0.96f, 0.45f);

    glVertex2f(-0.9f, 0.55f);
    glVertex2f(-0.91f, 0.45f);

    glVertex2f(-0.85f, 0.55f);
    glVertex2f(-0.86f, 0.45f);

    glVertex2f(-0.8f, 0.55f);
    glVertex2f(-0.81f, 0.45f);

    glVertex2f(-0.75f, 0.55f);
    glVertex2f(-0.76f, 0.45f);

    glVertex2f(-0.7f, 0.55f);
    glVertex2f(-0.71f, 0.45f);

    glVertex2f(-0.65f, 0.55f);
    glVertex2f(-0.66f, 0.45f);

    glVertex2f(-0.6f, 0.55f);
    glVertex2f(-0.61f, 0.45f);

    glVertex2f(-0.55f, 0.55f);
    glVertex2f(-0.56f, 0.45f);

    glVertex2f(-0.5f, 0.55f);
    glVertex2f(-0.51f, 0.45f);

    glVertex2f(-0.45f, 0.55f);
    glVertex2f(-0.46f, 0.45f);

    glVertex2f(-0.4f, 0.55f);
    glVertex2f(-0.41f, 0.45f);

    glVertex2f(-0.35f, 0.55f);
    glVertex2f(-0.36f, 0.45f);

    glVertex2f(-0.3f, 0.55f);
    glVertex2f(-0.31f, 0.45f);

    glVertex2f(-0.25f, 0.55f);
    glVertex2f(-0.26f, 0.45f);

    glVertex2f(-0.2f, 0.55f);
    glVertex2f(-0.21f, 0.45f);

    glVertex2f(-0.15f, 0.55f);
    glVertex2f(-0.16f, 0.45f);

    glVertex2f(-0.1f, 0.55f);
    glVertex2f(-0.11f, 0.45f);

    glVertex2f(-0.05f, 0.55f);
    glVertex2f(-0.06f, 0.45f);

    glVertex2f(0.0f, 0.55f);
    glVertex2f(-0.01f, 0.45f);

    glVertex2f(0.05f, 0.55f);
    glVertex2f(0.04f, 0.45f);

    glVertex2f(0.10f, 0.55f);
    glVertex2f(0.09f, 0.45f);

    glVertex2f(0.15f, 0.55f);
    glVertex2f(0.14f, 0.45f);

    glVertex2f(0.20f, 0.55f);
    glVertex2f(0.19f, 0.45f);

    glVertex2f(0.25f, 0.55f);
    glVertex2f(0.24f, 0.45f);

    glVertex2f(0.30f, 0.55f);
    glVertex2f(0.29f, 0.45f);

    glVertex2f(0.35f, 0.55f);
    glVertex2f(0.34f, 0.45f);

    glVertex2f(0.40f, 0.55f);
    glVertex2f(0.39f, 0.45f);

    glVertex2f(0.45f, 0.55f);
    glVertex2f(0.44f, 0.45f);

    glVertex2f(0.50f, 0.55f);
    glVertex2f(0.49f, 0.45f);

    glVertex2f(0.55f, 0.55f);
    glVertex2f(0.54f, 0.45f);

    glVertex2f(0.60f, 0.55f);
    glVertex2f(0.59f, 0.45f);

    glVertex2f(0.65f, 0.55f);
    glVertex2f(0.64f, 0.45f);

    glVertex2f(0.70f, 0.55f);
    glVertex2f(0.69f, 0.45f);

    glVertex2f(0.75f, 0.55f);
    glVertex2f(0.74f, 0.45f);

    glVertex2f(0.80f, 0.55f);
    glVertex2f(0.79f, 0.45f);

    glVertex2f(0.85f, 0.55f);
    glVertex2f(0.84f, 0.45f);

    glVertex2f(0.90f, 0.55f);
    glVertex2f(0.89f, 0.45f);

    glVertex2f(0.95f, 0.55f);
    glVertex2f(0.94f, 0.45f);

    glVertex2f(1.0f, 0.55f);
    glVertex2f(0.99f, 0.45f);

    glVertex2f(1.05f, 0.55f);
    glVertex2f(1.04f, 0.45f);

    glEnd();

    ///3rd line end

    ///4th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.35f);
    glVertex2f(-0.96f, 0.25f);

    glVertex2f(-0.9f, 0.35f);
    glVertex2f(-0.91f, 0.25f);

    glVertex2f(-0.85f, 0.35f);
    glVertex2f(-0.86f, 0.25f);

    glVertex2f(-0.8f, 0.35f);
    glVertex2f(-0.81f, 0.25f);

    glVertex2f(-0.75f, 0.35f);
    glVertex2f(-0.76f, 0.25f);

    glVertex2f(-0.7f, 0.35f);
    glVertex2f(-0.71f, 0.25f);

    glVertex2f(-0.65f, 0.35f);
    glVertex2f(-0.66f, 0.25f);

    glVertex2f(-0.6f, 0.35f);
    glVertex2f(-0.61f, 0.25f);

    glVertex2f(-0.55f, 0.35f);
    glVertex2f(-0.56f, 0.25f);

    glVertex2f(-0.5f, 0.35f);
    glVertex2f(-0.51f, 0.25f);

    glVertex2f(-0.45f, 0.35f);
    glVertex2f(-0.46f, 0.25f);

    glVertex2f(-0.4f, 0.35f);
    glVertex2f(-0.41f, 0.25f);

    glVertex2f(-0.35f, 0.35f);
    glVertex2f(-0.36f, 0.25f);

    glVertex2f(-0.3f, 0.35f);
    glVertex2f(-0.31f, 0.25f);

    glVertex2f(-0.25f, 0.35f);
    glVertex2f(-0.26f, 0.25f);

    glVertex2f(-0.2f, 0.35f);
    glVertex2f(-0.21f, 0.25f);

    glVertex2f(-0.15f, 0.35f);
    glVertex2f(-0.16f, 0.25f);

    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.11f, 0.25f);

    glVertex2f(-0.05f, 0.35f);
    glVertex2f(-0.06f, 0.25f);

    glVertex2f(0.0f, 0.35f);
    glVertex2f(-0.01f, 0.25f);

    glVertex2f(0.05f, 0.35f);
    glVertex2f(0.04f, 0.25f);

    glVertex2f(0.10f, 0.35f);
    glVertex2f(0.09f, 0.25f);

    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.14f, 0.25f);

    glVertex2f(0.20f, 0.35f);
    glVertex2f(0.19f, 0.25f);

    glVertex2f(0.25f, 0.35f);
    glVertex2f(0.24f, 0.25f);

    glVertex2f(0.30f, 0.35f);
    glVertex2f(0.29f, 0.25f);

    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.34f, 0.25f);

    glVertex2f(0.40f, 0.35f);
    glVertex2f(0.39f, 0.25f);

    glVertex2f(0.45f, 0.35f);
    glVertex2f(0.44f, 0.25f);

    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.49f, 0.25f);

    glVertex2f(0.55f, 0.35f);
    glVertex2f(0.54f, 0.25f);

    glVertex2f(0.60f, 0.35f);
    glVertex2f(0.59f, 0.25f);

    glVertex2f(0.65f, 0.35f);
    glVertex2f(0.64f, 0.25f);

    glVertex2f(0.70f, 0.35f);
    glVertex2f(0.69f, 0.25f);

    glVertex2f(0.75f, 0.35f);
    glVertex2f(0.74f, 0.25f);

    glVertex2f(0.80f, 0.35f);
    glVertex2f(0.79f, 0.25f);

    glVertex2f(0.85f, 0.35f);
    glVertex2f(0.84f, 0.25f);

    glVertex2f(0.90f, 0.35f);
    glVertex2f(0.89f, 0.25f);

    glVertex2f(0.95f, 0.35f);
    glVertex2f(0.94f, 0.25f);

    glVertex2f(1.0f, 0.35f);
    glVertex2f(0.99f, 0.25f);

    glVertex2f(1.05f, 0.35f);
    glVertex2f(1.04f, 0.25f);

    glEnd();

    ///4th line end

    ///5th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, 0.15f);
    glVertex2f(-0.96f, 0.05f);

    glVertex2f(-0.9f, 0.15f);
    glVertex2f(-0.91f, 0.05f);

    glVertex2f(-0.85f, 0.15f);
    glVertex2f(-0.86f, 0.05f);

    glVertex2f(-0.8f, 0.15f);
    glVertex2f(-0.81f, 0.05f);

    glVertex2f(-0.75f, 0.15f);
    glVertex2f(-0.76f, 0.05f);

    glVertex2f(-0.7f, 0.15f);
    glVertex2f(-0.71f, 0.05f);

    glVertex2f(-0.65f, 0.15f);
    glVertex2f(-0.66f, 0.05f);

    glVertex2f(-0.6f, 0.15f);
    glVertex2f(-0.61f, 0.05f);

    glVertex2f(-0.55f, 0.15f);
    glVertex2f(-0.56f, 0.05f);

    glVertex2f(-0.5f, 0.15f);
    glVertex2f(-0.51f, 0.05f);

    glVertex2f(-0.45f, 0.15f);
    glVertex2f(-0.46f, 0.05f);

    glVertex2f(-0.4f, 0.15f);
    glVertex2f(-0.41f, 0.05f);

    glVertex2f(-0.35f, 0.15f);
    glVertex2f(-0.36f, 0.05f);

    glVertex2f(-0.3f, 0.15f);
    glVertex2f(-0.31f, 0.05f);

    glVertex2f(-0.25f, 0.15f);
    glVertex2f(-0.26f, 0.05f);

    glVertex2f(-0.2f, 0.15f);
    glVertex2f(-0.21f, 0.05f);

    glVertex2f(-0.15f, 0.15f);
    glVertex2f(-0.16f, 0.05f);

    glVertex2f(-0.1f, 0.15f);
    glVertex2f(-0.11f, 0.05f);

    glVertex2f(-0.05f, 0.15f);
    glVertex2f(-0.06f, 0.05f);

    glVertex2f(0.0f, 0.15f);
    glVertex2f(-0.01f, 0.05f);

    glVertex2f(0.05f, 0.15f);
    glVertex2f(0.04f, 0.05f);

    glVertex2f(0.10f, 0.15f);
    glVertex2f(0.09f, 0.05f);

    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.14f, 0.05f);

    glVertex2f(0.20f, 0.15f);
    glVertex2f(0.19f, 0.05f);

    glVertex2f(0.25f, 0.15f);
    glVertex2f(0.24f, 0.05f);

    glVertex2f(0.30f, 0.15f);
    glVertex2f(0.29f, 0.05f);

    glVertex2f(0.35f, 0.15f);
    glVertex2f(0.34f, 0.05f);

    glVertex2f(0.40f, 0.15f);
    glVertex2f(0.39f, 0.05f);

    glVertex2f(0.45f, 0.15f);
    glVertex2f(0.44f, 0.05f);

    glVertex2f(0.50f, 0.15f);
    glVertex2f(0.49f, 0.05f);

    glVertex2f(0.55f, 0.15f);
    glVertex2f(0.54f, 0.05f);

    glVertex2f(0.60f, 0.15f);
    glVertex2f(0.59f, 0.05f);

    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.64f, 0.05f);

    glVertex2f(0.70f, 0.15f);
    glVertex2f(0.69f, 0.05f);

    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.74f, 0.05f);

    glVertex2f(0.80f, 0.15f);
    glVertex2f(0.79f, 0.05f);

    glVertex2f(0.85f, 0.15f);
    glVertex2f(0.84f, 0.05f);

    glVertex2f(0.90f, 0.15f);
    glVertex2f(0.89f, 0.05f);

    glVertex2f(0.95f, 0.15f);
    glVertex2f(0.94f, 0.05f);

    glVertex2f(1.0f, 0.15f);
    glVertex2f(0.99f, 0.05f);

    glVertex2f(1.05f, 0.15f);
    glVertex2f(1.04f, 0.05f);

    glEnd();

    ///5th line end

    ///6th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.05f);
    glVertex2f(-0.96f, -0.15f);

    glVertex2f(-0.9f, -0.05f);
    glVertex2f(-0.91f, -0.15f);

    glVertex2f(-0.85f, -0.05f);
    glVertex2f(-0.86f, -0.15f);

    glVertex2f(-0.8f, -0.05f);
    glVertex2f(-0.81f, -0.15f);

    glVertex2f(-0.75f, -0.05f);
    glVertex2f(-0.76f, -0.15f);

    glVertex2f(-0.7f, -0.05f);
    glVertex2f(-0.71f, -0.15f);

    glVertex2f(-0.65f, -0.05f);
    glVertex2f(-0.66f, -0.15f);

    glVertex2f(-0.6f, -0.05f);
    glVertex2f(-0.61f, -0.15f);

    glVertex2f(-0.55f, -0.05f);
    glVertex2f(-0.56f, -0.15f);

    glVertex2f(-0.5f, -0.05f);
    glVertex2f(-0.51f, -0.15f);

    glVertex2f(-0.45f, -0.05f);
    glVertex2f(-0.46f, -0.15f);

    glVertex2f(-0.4f, -0.05f);
    glVertex2f(-0.41f, -0.15f);

    glVertex2f(-0.35f, -0.05f);
    glVertex2f(-0.36f, -0.15f);

    glVertex2f(-0.3f, -0.05f);
    glVertex2f(-0.31f, -0.15f);

    glVertex2f(-0.25f, -0.05f);
    glVertex2f(-0.26f, -0.15f);

    glVertex2f(-0.2f, -0.05f);
    glVertex2f(-0.21f, -0.15f);

    glVertex2f(-0.15f, -0.05f);
    glVertex2f(-0.16f, -0.15f);

    glVertex2f(-0.1f, -0.05f);
    glVertex2f(-0.11f, -0.15f);

    glVertex2f(-0.05f, -0.05f);
    glVertex2f(-0.06f, -0.15f);

    glVertex2f(0.0f, -0.05f);
    glVertex2f(-0.01f, -0.15f);

    glVertex2f(0.05f, -0.05f);
    glVertex2f(0.04f, -0.15f);

    glVertex2f(0.10f, -0.05f);
    glVertex2f(0.09f, -0.15f);

    glVertex2f(0.15f, -0.05f);
    glVertex2f(0.14f, -0.15f);

    glVertex2f(0.20f, -0.05f);
    glVertex2f(0.19f, -0.15f);

    glVertex2f(0.25f, -0.05f);
    glVertex2f(0.24f, -0.15f);

    glVertex2f(0.30f, -0.05f);
    glVertex2f(0.29f, -0.15f);

    glVertex2f(0.35f, -0.05f);
    glVertex2f(0.34f, -0.15f);

    glVertex2f(0.40f, -0.05f);
    glVertex2f(0.39f, -0.15f);

    glVertex2f(0.45f, -0.05f);
    glVertex2f(0.44f, -0.15f);

    glVertex2f(0.50f, -0.05f);
    glVertex2f(0.49f, -0.15f);

    glVertex2f(0.55f, -0.05f);
    glVertex2f(0.54f, -0.15f);

    glVertex2f(0.60f, -0.05f);
    glVertex2f(0.59f, -0.15f);

    glVertex2f(0.65f, -0.05f);
    glVertex2f(0.64f, -0.15f);

    glVertex2f(0.70f, -0.05f);
    glVertex2f(0.69f, -0.15f);

    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.74f, -0.15f);

    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.79f, -0.15f);

    glVertex2f(0.85f, -0.05f);
    glVertex2f(0.84f, -0.15f);

    glVertex2f(0.90f, -0.05f);
    glVertex2f(0.89f, -0.15f);

    glVertex2f(0.95f, -0.05f);
    glVertex2f(0.94f, -0.15f);

    glVertex2f(1.0f, -0.05f);
    glVertex2f(0.99f, -0.15f);

    glVertex2f(1.05f, -0.05f);
    glVertex2f(1.04f, -0.15f);

    glEnd();

    ///6th line end


    ///7th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.25f);
    glVertex2f(-0.96f, -0.35f);

    glVertex2f(-0.9f, -0.25f);
    glVertex2f(-0.91f, -0.35f);

    glVertex2f(-0.85f, -0.25f);
    glVertex2f(-0.86f, -0.35f);

    glVertex2f(-0.8f, -0.25f);
    glVertex2f(-0.81f, -0.35f);

    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.76f, -0.35f);

    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.71f, -0.35f);

    glVertex2f(-0.65f, -0.25f);
    glVertex2f(-0.66f, -0.35f);

    glVertex2f(-0.6f, -0.25f);
    glVertex2f(-0.61f, -0.35f);

    glVertex2f(-0.55f, -0.25f);
    glVertex2f(-0.56f, -0.35f);

    glVertex2f(-0.5f, -0.25f);
    glVertex2f(-0.51f, -0.35f);

    glVertex2f(-0.45f, -0.25f);
    glVertex2f(-0.46f, -0.35f);

    glVertex2f(-0.4f, -0.25f);
    glVertex2f(-0.41f, -0.35f);

    glVertex2f(-0.35f, -0.25f);
    glVertex2f(-0.36f, -0.35f);

    glVertex2f(-0.3f, -0.25f);
    glVertex2f(-0.31f, -0.35f);

    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.26f, -0.35f);

    glVertex2f(-0.2f, -0.25f);
    glVertex2f(-0.21f, -0.35f);

    glVertex2f(-0.15f, -0.25f);
    glVertex2f(-0.16f, -0.35f);

    glVertex2f(-0.1f, -0.25f);
    glVertex2f(-0.11f, -0.35f);

    glVertex2f(-0.05f, -0.25f);
    glVertex2f(-0.06f, -0.35f);

    glVertex2f(0.0f, -0.25f);
    glVertex2f(-0.01f, -0.35f);

    glVertex2f(0.05f, -0.25f);
    glVertex2f(0.04f, -0.35f);

    glVertex2f(0.10f, -0.25f);
    glVertex2f(0.09f, -0.35f);

    glVertex2f(0.15f, -0.25f);
    glVertex2f(0.14f, -0.35f);

    glVertex2f(0.20f, -0.25f);
    glVertex2f(0.19f, -0.35f);

    glVertex2f(0.25f, -0.25f);
    glVertex2f(0.24f, -0.35f);

    glVertex2f(0.30f, -0.25f);
    glVertex2f(0.29f, -0.35f);

    glVertex2f(0.35f, -0.25f);
    glVertex2f(0.34f, -0.35f);

    glVertex2f(0.40f, -0.25f);
    glVertex2f(0.39f, -0.35f);

    glVertex2f(0.45f, -0.25f);
    glVertex2f(0.44f, -0.35f);

    glVertex2f(0.50f, -0.25f);
    glVertex2f(0.49f, -0.35f);

    glVertex2f(0.55f, -0.25f);
    glVertex2f(0.54f, -0.35f);

    glVertex2f(0.60f, -0.25f);
    glVertex2f(0.59f, -0.35f);

    glVertex2f(0.65f, -0.25f);
    glVertex2f(0.64f, -0.35f);

    glVertex2f(0.70f, -0.25f);
    glVertex2f(0.69f, -0.35f);

    glVertex2f(0.75f, -0.25f);
    glVertex2f(0.74f, -0.35f);

    glVertex2f(0.80f, -0.25f);
    glVertex2f(0.79f, -0.35f);

    glVertex2f(0.85f, -0.25f);
    glVertex2f(0.84f, -0.35f);

    glVertex2f(0.90f, -0.25f);
    glVertex2f(0.89f, -0.35f);

    glVertex2f(0.95f, -0.25f);
    glVertex2f(0.94f, -0.35f);

    glVertex2f(1.0f, -0.25f);
    glVertex2f(0.99f, -0.35f);

    glVertex2f(1.05f, -0.25f);
    glVertex2f(1.04f, -0.35f);

    glEnd();

    ///7th line end

    ///8th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.45f);
    glVertex2f(-0.96f, -0.55f);

    glVertex2f(-0.9f, -0.45f);
    glVertex2f(-0.91f, -0.55f);

    glVertex2f(-0.85f, -0.45f);
    glVertex2f(-0.86f, -0.55f);

    glVertex2f(-0.8f, -0.45f);
    glVertex2f(-0.81f, -0.55f);

    glVertex2f(-0.75f, -0.45f);
    glVertex2f(-0.76f, -0.55f);

    glVertex2f(-0.7f, -0.45f);
    glVertex2f(-0.71f, -0.55f);

    glVertex2f(-0.65f, -0.45f);
    glVertex2f(-0.66f, -0.55f);

    glVertex2f(-0.6f, -0.45f);
    glVertex2f(-0.61f, -0.55f);

    glVertex2f(-0.55f, -0.45f);
    glVertex2f(-0.56f, -0.55f);

    glVertex2f(-0.5f, -0.45f);
    glVertex2f(-0.51f, -0.55f);

    glVertex2f(-0.45f, -0.45f);
    glVertex2f(-0.46f, -0.55f);

    glVertex2f(-0.4f, -0.45f);
    glVertex2f(-0.41f, -0.55f);

    glVertex2f(-0.35f, -0.45f);
    glVertex2f(-0.36f, -0.55f);

    glVertex2f(-0.3f, -0.45f);
    glVertex2f(-0.31f, -0.55f);

    glVertex2f(-0.25f, -0.45f);
    glVertex2f(-0.26f, -0.55f);

    glVertex2f(-0.2f, -0.45f);
    glVertex2f(-0.21f, -0.55f);

    glVertex2f(-0.15f, -0.45f);
    glVertex2f(-0.16f, -0.55f);

    glVertex2f(-0.1f, -0.45f);
    glVertex2f(-0.11f, -0.55f);

    glVertex2f(-0.05f, -0.45f);
    glVertex2f(-0.06f, -0.55f);

    glVertex2f(0.0f, -0.45f);
    glVertex2f(-0.01f, -0.55f);

    glVertex2f(0.05f, -0.45f);
    glVertex2f(0.04f, -0.55f);

    glVertex2f(0.10f, -0.45f);
    glVertex2f(0.09f, -0.55f);

    glVertex2f(0.15f, -0.45f);
    glVertex2f(0.14f, -0.55f);

    glVertex2f(0.20f, -0.45f);
    glVertex2f(0.19f, -0.55f);

    glVertex2f(0.25f, -0.45f);
    glVertex2f(0.24f, -0.55f);

    glVertex2f(0.30f, -0.45f);
    glVertex2f(0.29f, -0.55f);

    glVertex2f(0.35f, -0.45f);
    glVertex2f(0.34f, -0.55f);

    glVertex2f(0.40f, -0.45f);
    glVertex2f(0.39f, -0.55f);

    glVertex2f(0.45f, -0.45f);
    glVertex2f(0.44f, -0.55f);

    glVertex2f(0.50f, -0.45f);
    glVertex2f(0.49f, -0.55f);

    glVertex2f(0.55f, -0.45f);
    glVertex2f(0.54f, -0.55f);

    glVertex2f(0.60f, -0.45f);
    glVertex2f(0.59f, -0.55f);

    glVertex2f(0.65f, -0.45f);
    glVertex2f(0.64f, -0.55f);

    glVertex2f(0.70f, -0.45f);
    glVertex2f(0.69f, -0.55f);

    glVertex2f(0.75f, -0.45f);
    glVertex2f(0.74f, -0.55f);

    glVertex2f(0.80f, -0.45f);
    glVertex2f(0.79f, -0.55f);

    glVertex2f(0.85f, -0.45f);
    glVertex2f(0.84f, -0.55f);

    glVertex2f(0.90f, -0.45f);
    glVertex2f(0.89f, -0.55f);

    glVertex2f(0.95f, -0.45f);
    glVertex2f(0.94f, -0.55f);

    glVertex2f(1.0f, -0.45f);
    glVertex2f(0.99f, -0.55f);

    glVertex2f(1.05f, -0.45f);
    glVertex2f(1.04f, -0.55f);

    glEnd();

    ///8th line end

    ///9th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.65f);
    glVertex2f(-0.96f, -0.75f);

    glVertex2f(-0.9f, -0.65f);
    glVertex2f(-0.91f, -0.75f);

    glVertex2f(-0.85f, -0.65f);
    glVertex2f(-0.86f, -0.75f);

    glVertex2f(-0.8f, -0.65f);
    glVertex2f(-0.81f, -0.75f);

    glVertex2f(-0.75f, -0.65f);
    glVertex2f(-0.76f, -0.75f);

    glVertex2f(-0.7f, -0.65f);
    glVertex2f(-0.71f, -0.75f);

    glVertex2f(-0.65f, -0.65f);
    glVertex2f(-0.66f, -0.75f);

    glVertex2f(-0.6f, -0.65f);
    glVertex2f(-0.61f, -0.75f);

    glVertex2f(-0.55f, -0.65f);
    glVertex2f(-0.56f, -0.75f);

    glVertex2f(-0.5f, -0.65f);
    glVertex2f(-0.51f, -0.75f);

    glVertex2f(-0.45f, -0.65f);
    glVertex2f(-0.46f, -0.75f);

    glVertex2f(-0.4f, -0.65f);
    glVertex2f(-0.41f, -0.75f);

    glVertex2f(-0.35f, -0.65f);
    glVertex2f(-0.36f, -0.75f);

    glVertex2f(-0.3f, -0.65f);
    glVertex2f(-0.31f, -0.75f);

    glVertex2f(-0.25f, -0.65f);
    glVertex2f(-0.26f, -0.75f);

    glVertex2f(-0.2f, -0.65f);
    glVertex2f(-0.21f, -0.75f);

    glVertex2f(-0.15f, -0.65f);
    glVertex2f(-0.16f, -0.75f);

    glVertex2f(-0.1f, -0.65f);
    glVertex2f(-0.11f, -0.75f);

    glVertex2f(-0.05f, -0.65f);
    glVertex2f(-0.06f, -0.75f);

    glVertex2f(0.0f, -0.65f);
    glVertex2f(-0.01f, -0.75f);

    glVertex2f(0.05f, -0.65f);
    glVertex2f(0.04f, -0.75f);

    glVertex2f(0.10f, -0.65f);
    glVertex2f(0.09f, -0.75f);

    glVertex2f(0.15f, -0.65f);
    glVertex2f(0.14f, -0.75f);

    glVertex2f(0.20f, -0.65f);
    glVertex2f(0.19f, -0.75f);

    glVertex2f(0.25f, -0.65f);
    glVertex2f(0.24f, -0.75f);

    glVertex2f(0.30f, -0.65f);
    glVertex2f(0.29f, -0.75f);

    glVertex2f(0.35f, -0.65f);
    glVertex2f(0.34f, -0.75f);

    glVertex2f(0.40f, -0.65f);
    glVertex2f(0.39f, -0.75f);

    glVertex2f(0.45f, -0.65f);
    glVertex2f(0.44f, -0.75f);

    glVertex2f(0.50f, -0.65f);
    glVertex2f(0.49f, -0.75f);

    glVertex2f(0.55f, -0.65f);
    glVertex2f(0.54f, -0.75f);

    glVertex2f(0.60f, -0.65f);
    glVertex2f(0.59f, -0.75f);

    glVertex2f(0.65f, -0.65f);
    glVertex2f(0.64f, -0.75f);

    glVertex2f(0.70f, -0.65f);
    glVertex2f(0.69f, -0.75f);

    glVertex2f(0.75f, -0.65f);
    glVertex2f(0.74f, -0.75f);

    glVertex2f(0.80f, -0.65f);
    glVertex2f(0.79f, -0.75f);

    glVertex2f(0.85f, -0.65f);
    glVertex2f(0.84f, -0.75f);

    glVertex2f(0.90f, -0.65f);
    glVertex2f(0.89f, -0.75f);

    glVertex2f(0.95f, -0.65f);
    glVertex2f(0.94f, -0.75f);

    glVertex2f(1.0f, -0.65f);
    glVertex2f(0.99f, -0.75f);

    glVertex2f(1.05f, -0.65f);
    glVertex2f(1.04f, -0.75f);

    glEnd();

    ///9th line end


     ///10th line start

    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-0.95f, -0.85f);
    glVertex2f(-0.96f, -0.95f);

    glVertex2f(-0.9f, -0.85f);
    glVertex2f(-0.91f, -0.95f);

    glVertex2f(-0.85f, -0.85f);
    glVertex2f(-0.86f, -0.95f);

    glVertex2f(-0.8f, -0.85f);
    glVertex2f(-0.81f, -0.95f);

    glVertex2f(-0.75f, -0.85f);
    glVertex2f(-0.76f, -0.95f);

    glVertex2f(-0.7f, -0.85f);
    glVertex2f(-0.71f, -0.95f);

    glVertex2f(-0.65f, -0.85f);
    glVertex2f(-0.66f, -0.95f);

    glVertex2f(-0.6f, -0.85f);
    glVertex2f(-0.61f, -0.95f);

     glVertex2f(-0.55f, -0.85f);
    glVertex2f(-0.56f, -0.95f);

    glVertex2f(-0.5f, -0.85f);
    glVertex2f(-0.51f, -0.95f);

    glVertex2f(-0.45f, -0.85f);
    glVertex2f(-0.46f, -0.95f);

    glVertex2f(-0.4f, -0.85f);
    glVertex2f(-0.41f, -0.95f);

    glVertex2f(-0.35f, -0.85f);
    glVertex2f(-0.36f, -0.95f);

    glVertex2f(-0.3f, -0.85f);
    glVertex2f(-0.31f, -0.95f);

    glVertex2f(-0.25f, -0.85f);
    glVertex2f(-0.26f, -0.95f);

    glVertex2f(-0.2f, -0.85f);
    glVertex2f(-0.21f, -0.95f);

    glVertex2f(-0.15f, -0.85f);
    glVertex2f(-0.16f, -0.95f);

    glVertex2f(-0.1f, -0.85f);
    glVertex2f(-0.11f, -0.95f);

    glVertex2f(-0.05f, -0.85f);
    glVertex2f(-0.06f, -0.95f);

    glVertex2f(0.0f, -0.85f);
    glVertex2f(-0.01f, -0.95f);

    glVertex2f(0.05f, -0.85f);
    glVertex2f(0.04f, -0.95f);

    glVertex2f(0.10f, -0.85f);
    glVertex2f(0.09f, -0.95f);

    glVertex2f(0.15f, -0.85f);
    glVertex2f(0.14f, -0.95f);

    glVertex2f(0.20f, -0.85f);
    glVertex2f(0.19f, -0.95f);

    glVertex2f(0.25f, -0.85f);
    glVertex2f(0.24f, -0.95f);

    glVertex2f(0.30f, -0.85f);
    glVertex2f(0.29f, -0.95f);

    glVertex2f(0.35f, -0.85f);
    glVertex2f(0.34f, -0.95f);

    glVertex2f(0.40f, -0.85f);
    glVertex2f(0.39f, -0.95f);

    glVertex2f(0.45f, -0.85f);
    glVertex2f(0.44f, -0.95f);

    glVertex2f(0.50f, -0.85f);
    glVertex2f(0.49f, -0.95f);

    glVertex2f(0.55f, -0.85f);
    glVertex2f(0.54f, -0.95f);

    glVertex2f(0.60f, -0.85f);
    glVertex2f(0.59f, -1.0f);

    glVertex2f(0.65f, -0.85f);
    glVertex2f(0.64f, -0.95f);

    glVertex2f(0.70f, -0.85f);
    glVertex2f(0.69f, -0.95f);

    glVertex2f(0.75f, -0.85f);
    glVertex2f(0.74f, -0.95f);

    glVertex2f(0.80f, -0.85f);
    glVertex2f(0.79f, -0.95f);

    glVertex2f(0.85f, -0.85f);
    glVertex2f(0.84f, -0.95f);

    glVertex2f(0.90f, -0.85f);
    glVertex2f(0.89f, -0.95f);

    glVertex2f(0.95f, -0.85f);
    glVertex2f(0.94f, -0.95f);

    glVertex2f(1.0f, -0.85f);
    glVertex2f(0.99f, -0.95f);

    glVertex2f(1.05f, -0.85f);
    glVertex2f(1.04f, -0.95f);

    glEnd();

    ///10th line end


    ///----------------------------------rain 02 end


    glPopMatrix();
    }


    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.8f, 0.52f, 0.0f, GLUT_BITMAP_HELVETICA_10, "HOSPITAL");

    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.245f, 0.44f, 0.0f, GLUT_BITMAP_HELVETICA_10, "KURATOLI SCHOOL");

    glColor3f(0.0,0.0,0.0);
    renderBitmapString(0.58f, 0.61f, 0.0f, GLUT_BITMAP_HELVETICA_10, "AIUB");

    glColor3f(0.0,0.0,0.0);
    renderBitmapString(-0.49f, 0.49f, 0.0f, GLUT_BITMAP_HELVETICA_10, "SCHOOL");



if(!cover)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0, 0.36, 0.0);
        glVertex2f(-1.0f,-1.0f);
        glVertex2f(1.0f, -1.0f);
        glColor3f(0.18, 0.36, 0.56);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
        glEnd();
        glColor3f(1.0,1.0,1.0);

        renderBitmapString(-0.3f, 0.85f, 0.0f, GLUT_BITMAP_HELVETICA_18, "        COMPUTER GRAPHICS [C]");


        glPushMatrix();
        //glTranslatef(_run11,0,0);
        renderBitmapString(-0.24f, 0.75f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SMART CITY & VILLAGE");
        glLoadIdentity();
        glPopMatrix();


        renderBitmapString(-0.28f, 0.65f, 0.0f, GLUT_BITMAP_HELVETICA_18, "           Submitted by : ");
        renderBitmapString(-0.4f, 0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18,      "ID                                                  Name                              Contribution ");
        renderBitmapString(-0.4f, 0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-43675-2               NAZMUL HASAN MAMUN                            -- ");
        renderBitmapString(-0.4f, 0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-43643-2               ZANNATUL FERDUS                                     -- ");
        renderBitmapString(-0.4f, 0.2f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-43191-1               KHAN NUSHRAT SULTANA NETU               -- ");
        renderBitmapString(-0.4f, 0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-43645-2               MD. TIHAM INKIAD                                       -- ");
        renderBitmapString(-0.4f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18,   "20-43302-1               WAHID SADIK                                                -- ");

        renderBitmapString(-0.11f, -0.5f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted to");
        renderBitmapString(-0.18f, -0.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "         MD.SYAMUL ISLAM");
        renderBitmapString(-0.22f, -0.65f, 0.0f, GLUT_BITMAP_HELVETICA_12,"       FACULTY OF SCIENCE & TECHNOLOGY");
        renderBitmapString(-0.2f, -0.7f, 0.0f, GLUT_BITMAP_HELVETICA_10,  "       American International University-Bangladesh");
    }



    glFlush();  // Render now
}

void Input(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'n':
        night = true;

        break;

        case 'N':
        night = true;



        break;

    case 'd':
        night = false;

        break;

        case 'D':
        night = false;

        break;

    case 's':
        if(cover)
        {
            cover = false;
        }
        else
        {
            cover = true;
        }
        break;

        case 'S':
        if(cover)
        {
            cover = false;
        }
        else
        {
            cover = true;
        }
        break;

        case 'r':
        rain = true;

        break;

        case 'R':
        rain = true;



        break;

    case 'e':
        rain = false;

        break;

        case 'E':
        rain = false;

        break;

    case'+':///-------------------try to increase speed
    {
        spin_speed++;
        glutPostRedisplay();
        break;
    }

    case'-':///-------------------try to increase speed
    {
        spin_speed--;
        glutPostRedisplay();
        break;
    }
    case'0':///-------------------try to increase speed
    {
        spin_speed =0.9;
        glutPostRedisplay();
        break;
    }

    /*case '+':
        glutFullScreen();
        break;

    case '-':
        glutReshapeWindow(1024,576);
        glutInitWindowPosition(50,40);
        break;*/

    }

    glutPostRedisplay();
}



int main(int argc, char** argv)
{
    cout << "Press s : For Start" << endl << endl;
    cout << "Press n : For Night " << endl << endl;
    cout << "Press d : For Day " << endl << endl;
    cout << "Press r : For Rain " << endl << endl;
    cout << "Press e : For Reset Rain " << endl << endl;
    cout << "Press + : For Increase windmill speed" << endl << endl;
    cout << "Press - : For Decrease windmill speed" << endl << endl;
    cout << "Press 0 : For Reset windmill speed" << endl << endl;



glutInit(&argc, argv);
glutCreateWindow("Smart City and Village");
glutTimerFunc(100, update, 0); ///car 01
glutTimerFunc(100, update2, 0);
glutTimerFunc(100, update3, 0);
glutTimerFunc(100, update4, 0);
glutTimerFunc(100, update5, 0);
glutTimerFunc(100, update6, 0);
glutTimerFunc(100, update7, 0);
glutTimerFunc(100, update8, 0);
glutTimerFunc(100, update9, 0);
glutTimerFunc(100, update10, 0);
glutTimerFunc(100, update11, 0);
glutTimerFunc(100, update12, 0);
glutTimerFunc(100, update13, 0);
glutTimerFunc(100, update14, 0);

glutKeyboardFunc(Input);
glutInitWindowSize(720, 480);
glutDisplayFunc(display);
glutMainLoop();
glutReshapeFunc(reshape);
return 0;
}


