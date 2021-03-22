//SAM.h         Location:    C:\test_progs\GLUT-Progs\closedGL\SAM_template
/*
#define P 10//particles
float col[P][3],loc[P][3],dir[P][3],stp[P]; //color,location,direction,step

void initParticles()
{	glEnable (GL_BLEND);
for (int i=0;i<P;i++)
{	stp[i] = .001*(rand()%10); //cout<<stp[i]<<endl;      stp is not used yet
for (int j=0;j<3;j++)	{col[i][j]=1.- .0001*(rand()%P);
loc[i][j]=.01*(rand()%P)-1.;
dir[i][j]=.001*(rand()%P);
//cout<<col[i][j]<<" "<<loc[i][j]<<" "<<dir[i][j]<<endl;
}
}
}
///////////////////////////////////////////////////////////////////////

/*  //try this
void SamDisplay(int X,int Y,int Z,int wire,  GLfloat x,GLfloat y,GLfloat z,GLfloat spin)
{
glEnable (GL_BLEND); //glEnable(GL_LIGHTING);
glDisable(GL_LIGHTING);
for (int i=0;i<P;i++)
{	glPushMatrix();
glColor4f(col[i][0],col[i][1],col[i][2],.6); glTranslatef(loc[i][0],loc[i][1],loc[i][2]); glutSolidSphere(.1,16,8);
glPopMatrix();
}

glDisable (GL_BLEND); glEnable(GL_LIGHTING);

glPushMatrix();			glEnable(GL_LIGHT0);
glTranslatef(x,y,z);	glRotatef(spin,X,Y,Z); if(wire)glutSolidSphere(1.,24,12);  else glutWireSphere(1.,24,12);
glPopMatrix();			glDisable(GL_LIGHT0);

glPushMatrix();			glEnable(GL_LIGHT1);
glTranslatef(-x,y,z);	glRotatef(spin,X,Y,Z); if(wire)glutSolidCube(1.6);  else glutWireCube(1.6);
glPopMatrix();			glDisable(GL_LIGHT1);

glPushMatrix();			glEnable(GL_LIGHT2);
glTranslatef(x,-y,z);	glRotatef(spin,X,Y,Z); if(wire)glutSolidTorus(.5, 1.2, 24,12);  else glutWireTorus(.5, 1.2 ,24,12);
glPopMatrix();			glDisable(GL_LIGHT2);

glPushMatrix();			glEnable(GL_LIGHT3);
glTranslatef(-x,-y,z);	glRotatef(spin,X,Y,Z); if(wire)glutSolidCone(1.5, 1.2, 24,12);  else glutWireCone(1.5, 1.2 ,24,12);
glPopMatrix();			glDisable(GL_LIGHT3);

//addition
for(int i=0;i<4;i++)
{
glPushMatrix();  //tossing red cubes and cones in four directions
if(i==0) glTranslatef(-.1*spin,0.,0.); else
if(i==1) glTranslatef( .1*spin,0.,0.); else
if(i==2) glTranslatef( 0.,-.1*spin,.0); else
if(i==3) glTranslatef( 0., .1*spin,.0);

float mat_diffuse1[]={.1,.8,1., 1.0}; glEnable(GL_LIGHT1); //set a color
if(wire)glutSolidCube(1.5);  else glutWireCube(1.5); glDisable(GL_LIGHT1); //cubes

glRotatef(45.*i,X,Y,Z);  //tilting cones inside cubes

GLfloat mat_diffuse[]={1.,.0,1.0, 1.0}; glEnable(GL_LIGHT0); //set a color
if(wire)glutSolidCone(1.5, 1.2, 4,2);  else glutWireCone(1.5, 1.2 ,4,1); glDisable(GL_LIGHT0); //cones
glPopMatrix();
}
}
*/
/////////////////////////////////////////////////////////////////////////////////////////

//try this 1
/*
void SamDisplay(int X,int Y,int Z,int wire,  GLfloat x,GLfloat y,GLfloat z,GLfloat spin)
{ glEnable(GL_LIGHT0); glEnable (GL_BLEND); glTranslatef(x,y,z); glutSolidSphere(.1,16,8); //only one sphere
}
*/

//try this 2
/* float off=.01;
void SamDisplay(int X,int Y,int Z,int wire, GLfloat x,GLfloat y,GLfloat z,GLfloat spin)
{ glEnable(GL_LIGHT0);
for(int i=0;i<P;i++) {x+= off*(rand()%10-5.); y+= off*(rand()%10-5.); z+= off*(rand()%10-5.); // P spheres
glTranslatef(x,y,z);	glutSolidSphere(.1,9,5);}
}
*/

//try this 3
/*
void SamDisplay(int X,int Y,int Z,int wire,  GLfloat x,GLfloat y,GLfloat z,GLfloat spin)
{ glEnable(GL_LIGHT0);
for(int i=0;i<P;i++) {loc[i][0]+= off*(rand()%10-5.); loc[i][1]+= off*(rand()%10-5.); loc[i][2]+= off*(rand()%10-5.); // P spheres
glTranslatef(loc[i][0],loc[i][1],loc[i][2]);	glutSolidSphere(.1,9,5);}
}
*/

/*
//// macro statements
#define M glPushMatrix();
#define m glPopMatrix();
//_________________________________________________________________________________________  complete articulation  Animation
float ang=0.,speed=.5, step=50.;

void barR() { M	glEnable(GL_LIGHT7);	glScalef(1.,9.,1.); glutSolidCube(.4);	  	glDisable(GL_LIGHT7); m }  //a colored bar
void barL() { M	glEnable(GL_LIGHT6);	glScalef(1.,9.,1.); glutSolidCube(.4);	  	glDisable(GL_LIGHT6); m }

void Articulation(float off)     //just call articulation() in any spot !
{	M glTranslatef(0.,2.,-off); glRotatef(-ang,0.,0.,1.);  glTranslatef(0.,-2.,-off); barR(); m
M glTranslatef(0.,2., off); glRotatef( ang,0.,0.,1.);  glTranslatef(0.,-2., off); barL(); m}
//___________________________________________________________________________________________

/*
void myRobot()
{
glPushMatrix();
glEnable(GL_LIGHT6); glTranslatef( 0.,2.7,0.); glutSolidTorus(.4,.8,8,32);  glDisable(GL_LIGHT6); //brown
glPopMatrix();
//-----------------
glPushMatrix();
glEnable(GL_LIGHT2); glTranslatef( 0.,1.5,0.); glutSolidTorus(.5,.9,8,32); glDisable(GL_LIGHT2); //green
glPopMatrix();
//-----------------
glPushMatrix();
glEnable(GL_LIGHT1); glTranslatef( 0.,-2.,0.); Articulation(.3); glTranslatef(0.,2.5,0.); glutSolidTorus(.3,.8,8,32); glDisable(GL_LIGHT1); //lower legs
glPopMatrix();
//------------------
glPushMatrix();
glEnable(GL_LIGHT4); glTranslatef( 0., 2.,0.); Articulation(.4); glTranslatef(0.,2.7,0.); glutSolidTorus(.5,.8,8,32); glDisable(GL_LIGHT4); //upper legs
glPopMatrix();
//------------------
}
*/




/* try this 4
int da=0;
void SamDisplay(int X,int Y,int Z,int wire,  GLfloat x,GLfloat y,GLfloat z,GLfloat spin)
{	da=++da%360;
//_____________________________________________________________________________________
if(ang<step && ang>-step) ang+=speed; else { if(ang>0.)ang=step-2.*speed; else ang=-step-2.*speed;  speed=-speed;} //articulation animation of <ang> by switching speed to -speed
//_____________________________________________________________________________________
//	glTranslatef(x,y,z);	//global translation
//	glRotatef(da,X,Y,Z);	//global rotation
glEnable(GL_LIGHTING);

glPushMatrix();
//-----------------
/*glPushMatrix();
glEnable(GL_LIGHT0); //gold=0,red=1,green=2,blue=3,   default>3
for(int i=0;i<P;i++) {loc[i][0]+= off*dir[i][0]; loc[i][1]+= off*dir[i][1]; loc[i][2]+= off*dir[i][2]; // P spheres
glTranslatef(loc[i][0],loc[i][1],loc[i][2]);	glutSolidSphere(.3,9,5);}
glEnable(GL_LIGHT0);
glPopMatrix();
*/
//======================== Animate one articulation of 2 bars


//articulation();
//M glTranslatef(0.,2.,0.); glRotatef(-ang,0.,0.,1.);  glTranslatef(0.,-2.,0.); bar1(); m
//M glTranslatef(0.,2.,0.); glRotatef( ang,0.,0.,1.);  glTranslatef(0.,-2.,0.); bar2(); m


//========================
//glTranslatef(-8.,0.,0.); for(int i=0;i<4;i++) {myRobot(); glTranslatef(4.,0.,0.);}   ///draw all robots
/*
glPushMatrix();
for(int i=0;i<P;i++) {glEnable(GL_LIGHT1); glTranslatef(loc[i][0],-loc[i][1],loc[i][2]); glutSolidTorus(.1,.6,8,32); glDisable(GL_LIGHT1);}
glPopMatrix();
*/
//-----------------
//glDisable(GL_LIGHTING);
//glPopMatrix();
//} 

/*
void samKeyboard(unsigned char key, int x,int y)
{	cout<<char(7)<<speed<<endl;
switch(key)
{	case '.': if(speed>0.) speed +=.1; else speed-=.1; break;
case ',': if(speed>0.) speed -=.1; else speed+=.1; break;
}
cout<<char(7)<<speed<<endl;
cout<<'\n'<<x<<" - "<<y<<endl;
glutPostRedisplay();
} */




//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//#define psh glPushMatrix(); 
//#define pop glPopMatrix(); 
/////////////////////////////
//#include "sam.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h> //sound "winmm.lib"
#include <iostream>
using namespace std;
#pragma comment(lib, "winmm.lib")  // PlaySound(TEXT("Gun+Luger.wav"), NULL, SND_SYNC);
#include <GL/glut.h>
//#include "C:\Users\Dr. Tannouri\Desktop\460_332_S2018\SAM.h" //ok
//#include "C:\Users\Dr. Tannouri\Desktop\SAM_HEADERS/SAM.h"

extern int X = 0, Y = 1, Z = 0, wire = 0, rot = 0, player1 = 1;
extern GLfloat x = 0., y = 0., z = 0., spin = 0., t = 0., scl = 4.;
extern GLfloat x11 = -10., y11 = -2., z11 = 0., ang11 = 10., x22 = 10., y22 = -2., z22 = 0., ang22 = 170.; //11 left gun, 22 right gun (location ,and aiming angles)
float spn = .02;
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;

GLfloat mat_diffuse[] = { 1.,1.,1., 1.0 }; //white color
GLfloat mat_diffuse0[] = { 1.,.9,.0, 1.0 }; //yellow
GLfloat mat_diffuse1[] = { 1.,.0,.0, 1.0 }; //red
GLfloat mat_diffuse2[] = { 0.,1.,.0, 1.0 }; //green
GLfloat mat_diffuse3[] = { 0.,0.,1., 1.0 }; //blue
GLfloat mat_diffuse4[] = { 0.,1.,1., 1.0 }; //sky
GLfloat mat_diffuse5[] = { 1.,0.,1., 1.0 }; //violet
GLfloat mat_diffuse6[] = { 1.,.5,0., 1.0 }; //brown
GLfloat mat_diffuse7[] = { 0.,0.2,0., 1.0 }; //black

GLfloat mat_ambient[] = { .9,.9,.9, 1.0 };
GLfloat mat_specular[] = { 1.,1.,1., 1.0 };
GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)
GLfloat light0_position[] = { 1., 1., 30., .0 };

GLfloat light1_position[] = { -1., 19., 29., .0 };
GLfloat light2_position[] = { 1., 19., 29., .0 };
GLfloat light3_position[] = { 0., 19., 29., .0 };
GLfloat light4_position[] = { -1., 29., 29., .0 };
GLfloat light5_position[] = { 0., 10., 19., .0 };
GLfloat light6_position[] = { 0., 10.,  9., .0 };
//////////////////////////////////////////
//////////////////////////////////////////		
///////////////////////////////////////////	sam.h (long text)

/**/ float rnd = 5.;
float ax = -11., ay = 5.;  //airplane position

void airplane()
{
	ax = .5*spin - rand() % 2;  ay = rnd;   //update airplane position ax,ay
	glPushMatrix();
	glTranslatef(ax, ay, 0.);	//high=.4    will be randomized
	glEnable(GL_LIGHT0); glScalef(6., 1., 1.); glutSolidSphere(.1, 9, 5); glDisable(GL_LIGHT0);
	glPopMatrix();
}
////////////////////////
void sph()
{
	glPushMatrix();
	glTranslatef(spin, 0., 0.);		/**/if (fabs(spin*cos(ang11) - ax)<1. && fabs(spin*sin(ang11) - ay)<1.) { PlaySound(TEXT("Gun+Luger.wav"), NULL, SND_ASYNC);  PlaySound(NULL, NULL, NULL); } //SYNC loop
	glEnable(GL_LIGHT0); glutSolidSphere(.07, 9, 5); glDisable(GL_LIGHT0); //bullets
	glPopMatrix();
}
/////////////////////////
void gun()
{
	glEnable(GL_LIGHT1); glPushMatrix(); glScalef(.1, 1., 1.); glutSolidCube(.8); glPopMatrix(); glDisable(GL_LIGHT1); //canon
	glEnable(GL_LIGHT2); glPushMatrix();  glRotatef(90., 0., 1., 0.);  glScalef(1., 1., 40.); glutSolidTorus(.02, .1, 4, 16); glPopMatrix(); glDisable(GL_LIGHT2);	//gun//
	sph();													//bullet
}
/////////////////////////
void ground() { glPushMatrix(); glTranslatef(0, -3., 0.); glScalef(90., 1., 90.); glEnable(GL_LIGHT4); glutSolidCube(1.); glDisable(GL_LIGHT4); glPopMatrix(); }
/////////////////////////
void student()
{
	ground(); airplane();
	glPushMatrix(); glTranslatef(x11, y11, z11); glRotatef(ang11, 0., 0., 1.); gun(); glPopMatrix();
	glPushMatrix(); glTranslatef(x22, y22, z22); glRotatef(ang22, 0., 0., 1.); gun(); glPopMatrix();
}

void drawmidterm()
{
	glColor3f(1.0, 0.5, 0.1);              // Red ball displaced to left.
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(60.0, 1, 0, 0);
	glRotatef(zRotated*2.0, 0, 0, 1);// Red ball rotates at twice the rate of blue ball.
	glutSolidCube(2.);
	glPopMatrix();
}
/**/

//////////////////////////////////////////
//////////////////////////////////////////		
///////////////////////////////////////////				Start student code

//////////////////////////
#define M glPushMatrix();		//Macros   (abreviations to remember)
#define m glPopMatrix();
#define T glTranslatef(
#define	R glRotatef(
#define S glScalef(

#define L0 glEnable(GL_LIGHT0);		// E/Disable four lights 0..3
#define l0 glDisable(GL_LIGHT0);
#define L1 glEnable(GL_LIGHT1);
#define l1 glDisable(GL_LIGHT1);
#define L2 glEnable(GL_LIGHT2);
#define l2 glDisable(GL_LIGHT2);
#define L3 glEnable(GL_LIGHT3);
#define l3 glDisable(GL_LIGHT3);

#define Scub glutSolidCube(			//four primitives
#define Ssph glutSolidSphere(
#define Scon glutSolidCone(
#define Stor glutSolidTorus(

#define Wcub glutWireCube(
#define Wsph glutWireSphere(
#define Wcon glutWireCone(
#define Wtor glutWireTorus(
///////////////////////////		End Macros
///////////////////////////
/////////////////////////////////////////  sam.h (short text)        //// STUDENT Macro CODE ////
/*
void airplane()
{
M
T .5*spin-rand()%2,4.,0.);
L0 S 6.,1.,1.); Ssph .1,9,5); l0
m
}
////////////////////////
void sph()
{	M
T spin,0.,0.);
L0 Ssph .07,9,5); l0
m
}
/////////////////////////
void gun()
{
L2 M  R 90.,0.,1.,0.);  S 1.,1.,40.); Stor .02,.1,4,16); m l2	//gun//
sph();															//bullet
}
/////////////////////////
void ground(){M T 0,-3.,0.); S 90.,1.,90.); L3 Scub 1.); l3 m}
/////////////////////////
void student()
{	ground(); airplane();
M T x11,y11,z11); R ang11,0.,0.,1.); gun();	 m
M T x2,y2,z2); R ang2,0.,0.,1.); gun();	 m
}    */
///////////////////////////////////////////				End of	student code   
///////////////////////////////////////////
/*
void callSam()
{	glPushMatrix();
glutWireCube(1.); //glutSolidCube(1.);
//M T x,y,z);
//M R spin,X,Y,Z); glutSolidCube(1.); m m
glPopMatrix();
}*/
///////////////////////////////////////////

void callSam()			//student work
{	////HW5 for Friday 2/16/2018         Do not touch any other parts of this program (stay inside callsam())
	////Always activate only one line, and study its action alone:  and write on a sheet of paper, your observation/explanation why is it so ?

	/**/	//R	.1, 0., 0., 1);		glutWireCube(2.);		//I activated this line for you to start, it remain 7 more lines for your experiment
															//	M   R	10., 0.,0.,1);		glutWireCube(2.);	m
															//		R	spin,0.,0.,1);		glutWireCube(2.);
															//	M   R	spin,0.,0.,1);		glutWireCube(2.);	m

															//		T	      .001,0.,0.);	glutWireCube(2.);
															//	M   T	        3.,0.,0.);	glutWireCube(2.);	m
															//		T	spin*.0001,0.,0.);	glutWireCube(2.);
															//	M   T	spin*.1   ,0.,0.);	glutWireCube(2.);	m
}
void final1()
{
	/**/	//R	.1, 0., 0., 1);		glutWireCube(2.);		//I activated this line for you to start, it remain 7 more lines for your experiment
																//M   R	10., 0.,0.,1);		glutWireCube(2.);	m
																	//R	spin,0.,0.,1);		glutWireCube(2.);
																//M   R	spin,0.,0.,1);		glutWireCube(2.);	m

															//		T	      .001,0.,0.);	glutWireCube(2.);
															//	M   T	        3.,0.,0.);	glutWireCube(2.);	m
																//	T	spin*.0001,0.,0.);	glutWireCube(2.);
	   // M   T	spin*.1, 0., 0.);	glutWireCube(2.);	m
		M   /*T   spin*-.1, 0., 0.);*/ glutSolidCube(2.); m
}
void callSam2()
{	/*R .1,X,Y,Z);
	M 	T -2.,-2.,0. );	R	spin,X,Y,Z);	glutSolidSphere	(1.,32,16);		m
	M  	T -2., 2.,0. );	R	spin,X,Y,Z);	glutSolidCube	(1.6);			m
	M  	T  2.,-2.,0. );	R	spin,X,Y,Z);	glutSolidTorus	(.4, 1.,32,16); m
	M  	T  2., 2.,0. );	R	spin,X,Y,Z);	glutSolidCone	(1.,1.6,32,16);	m */
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	callSam();    //callSam2();
	//keyboard();
	//drawmidterm();
	final1();
	glutSwapBuffers();
}

void spinDisplay() { spin += spn; if (spin>360.) { spin = 0.; /*cout<<(char)7;*/ rnd += rand() % 5 - 2.5; } glutPostRedisplay(); } //rnd+=(rand()%5) -2.)

void menu() { cout << "\nUse 'x' 'y' 'z' 'a' 'b' 'c' 'w' ' '  keys for animation\n" << endl; }

void init(void)
{ //initParticles();
  //PlaySound(L"LASER.wav", NULL, SND_FILENAME); //or SND_LOOP
  //PlaySound(NULL, NULL, NULL); //stops all running sounds 

	glClearColor(1., 1., 1., 1.);

	glShadeModel(GL_SMOOTH);	//default: SMOOTH   not  FLAT

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_ambient);

	glLightfv(GL_LIGHT0, GL_POSITION, light0_position); //three positions for light sources
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
	glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
	glLightfv(GL_LIGHT5, GL_POSITION, light5_position);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse0);	//eight different colors for material lighting	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_diffuse1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, mat_diffuse2);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, mat_diffuse3);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, mat_diffuse4);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, mat_diffuse5);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, mat_diffuse6);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, mat_diffuse7);

	glEnable(GL_LIGHTING); glEnable(GL_LIGHT1);		//enable some lighting

	/**/	glEnable(GL_DEPTH_TEST);
	//	glEnable(GL_BLEND);
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	menu();
}
//glutKeyboardFunc(myKeyboard)

void myKeyboard(unsigned char Key, int x, int y)
{
	switch (Key)
	{
	case 'w': T   spin*-.1, 0., 0.); break;
	case 'x': T   spin*.1, 0., 0.); break;

		break;
	case 27:
		exit(1);
		break;
	}
}


/*void keyboard(unsigned char key, int xx, int yy)
{// float t=.1;
	switch (key)
	{
	case '?':	menu(); break;
	case '+':	t += .01; break; //translation speed
	case '-':	t -= .01; break;
	case '<':	spn -= .01; break;//rotation speed
	case '>':	spn += .01; break;
	case 'x':	X = 1; Y = Z = 0; break;
	case 'y':	Y = 1; X = Z = 0;	break;
	case 'z':	Z = 1; X = Y = 0; break;
	case 'A':	x += t;  if (player1)x11 += t; else x22 += t; break;
	case 'B':	y += t;  if (player1)y11 += t; else y22 += t; break;
	case 'C':	z += t;  if (player1)z11 += t; else z22 += t; break;
	case 'a':	x -= t;  if (player1)x11 -= t; else x22 -= t; break;
	case 'b':	y -= t;  if (player1)y11 -= t; else y22 -= t; break;
	case 'c':	z -= t;  if (player1)z11 -= t; else z22 -= t; break;
	case 'p':	 player1 = (++player1) % 2; break;  //change players turns
	case 'S':	glScalef(.9, .9, .9);  break; //global scaling
	case 's':	glScalef(1.1, 1.1, 1.1); break;
	case ' ':	spin = x = y = z = .0; rnd = 5.; x11 = -10.; x22 = 10.; y11 = y22 = -2.; spn = .02; t = 0.; break;
	case 'n':	PlaySound(TEXT("Gun+Luger.wav"), NULL, SND_SYNC); break; //noise sound
	case 'm':	PlaySound(NULL, NULL, NULL); break; //noise sound

													//Spring-2018  I can share this keyboard() with SAM.h samKeyboard()   (I created a callback function in SAM.h file:)
													//	case '.'	:	samKeyboard('.',xx,yy);	 break;	//glutKeyboardFunc(samKeyboard); //perfectly works in SAM.h
													//	case ','	:	samKeyboard(',',xx,yy);	 break;	//glutKeyboardFunc(samKeyboard); //perfectly works in SAM.h
	}
	glutPostRedisplay();
}
*/

void special(GLint key, GLint x, GLint y)
{
	if (player1) { if (key == GLUT_KEY_UP)	ang11 += 1.; else if (key == GLUT_KEY_DOWN) ang11 -= 1.; } //player1
	else { if (key == GLUT_KEY_UP)	ang22 += 1.; else if (key == GLUT_KEY_DOWN) ang22 -= 1.; } //player2

																							   //	else if(key== GLUT_KEY_LEFT)	{ ang2+=1.;}
																							   //	else if(key== GLUT_KEY_RIGHT)	{ ang2+=1.;}
																							   //	else if(key== GLUT_KEY_RIGHT) { aH-=KK*k*pi; if(yaw< 60.&&ye>3.*track)yaw+=KK;} //steer right
																							   //	else if(key== GLUT_KEY_LEFT)  { aH+=KK*k*pi; if(yaw>-60.&&ye>3.*track)yaw-=KK;} //steer left
	glutPostRedisplay();
}

void pointing(int xx, int yy)
{
	cout << "\n\nmouse position xx,yy (in pixels): " << xx << "\t" << yy << endl;
	int Wid = glutGet(GLUT_WINDOW_WIDTH); int Hei = glutGet(GLUT_WINDOW_HEIGHT);  cout << "winWH : " << Wid << ',' << Hei << endl;
	//glutGet(GLUT_WINDOW_X); glutGet(GLUT_WINDOW_Y); //https://www.opengl.org/resources/libraries/glut/spec3/node70.html
}

void mouse(int button, int state, int xx, int yy)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:  if (state == GLUT_DOWN) { X = 0; Y = 1; Z = 0; glutIdleFunc(spinDisplay); pointing(xx, yy); } break;
	case GLUT_RIGHT_BUTTON: if (state == GLUT_UP) glutIdleFunc(NULL);
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	gluPerspective(60., (GLfloat)w / (GLfloat)h, .1, 100.);
	glMatrixMode(GL_MODELVIEW);		//glLoadIdentity();	
	glTranslatef(.0, .0, -7.);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 900); glutInitWindowPosition(0, 0);
	glutCreateWindow("Dr. Tannouri's easiest volume visualization");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(myKeyboard);
	//glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutMainLoop();
}