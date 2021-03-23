// freadBmp.cpp :
//#include "stdafx.h" 

#include  <cstdio> 
//#include  <cstdlib> 
#include <iostream>
using namespace std;
#include <windows.h>  
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib") 
#include <GL/glut.h>
///////////////////
GLfloat tr = 0.;
GLfloat mat_diffuse[] = { 1.,1.,1., tr }; //white color
GLfloat mat_diffuse0[] = { 1.,.9,.0, tr }; //yellow
GLfloat mat_diffuse1[] = { 1.,.0,.0, tr }; //red
GLfloat mat_diffuse2[] = { 0.,1.,.0, tr }; //green
GLfloat mat_diffuse3[] = { 0.,0.,1., tr }; //blue
GLfloat mat_diffuse4[] = { 0.,1.,1., tr }; //sky
GLfloat mat_diffuse5[] = { 1.,0.,1., tr }; //violet
GLfloat mat_diffuse6[] = { 1.,.5,0., tr }; //brown
GLfloat mat_diffuse7[] = { .9,.9,.8, tr }; //grey

GLfloat mat_ambient[] = { .9,.9,.9, 1.0 };
GLfloat mat_specular[] = { 1.,1.,1., 1.0 };
GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)
GLfloat light0_position[] = { 1., 1., 30., .0 };

GLfloat light1_position[] = { -1., 19., 29., .0 };
GLfloat light2_position[] = { 1., 19., 29., .0 };
GLfloat light3_position[] = { 0., 19., 29., .0 };
GLfloat light4_position[] = { -1., 29., 29., .0 };
GLfloat light5_position[] = { 0., 10., 39., .0 };
GLfloat light6_position[] = { 0., 10.,  39., .0 };
GLfloat light7_position[] = { 0., 10.,  39., .0 };
///////////////////

/**/int wid = 1025; //256 //1024		// "getImage.bmp"    533x300
/**/int hei = 1025; //256 //1024 
float L = 400.;
/**/unsigned char tex0[1069][603][3];  //for texture
/**/static GLuint texName[4];        //texture names

unsigned char* readBMPfile(int k)
{
	FILE *fil = NULL;

	//if (k == 0) fopen_s(&fil, "cliffClouds1.bmp", "rb"); else	//good "cliffClouds1.bmp", or "mycar1.bmp", works well
	//if (k == 1) fopen_s(&fil, "mycar1.bmp", "rb"); else		//good
	//if (k == 2) fopen_s(&fil, "getImage.bmp", "rb"); else	//good	Jounieh
	//if (k == 3) 
	fopen_s(&fil, "acrobats44.bmp", "rb");		//texture so so

	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, fil); // Read info: the 54-byte header;  info[18] and info[22]
	int width = wid = *(int*)&info[18];		// extract image_width  from header //no need to Polyview
	int height = hei = *(int*)&info[22];		// extract image_height from header
	int size = 3 * width * height;		/**/cout << "getImage.bmp:  " << width << 'x' << height << endl;
	unsigned char* data = new unsigned char[size]; // Allocate 3 bytes per pixel for all the image size=3*width*height (byte or unsigned char)
	fread(data, sizeof(unsigned char), size, fil); // Read the rest of the data at once (image data)
	fclose(fil);
	if (k<3)
		for (int i = 54; i < size; i += 3)  //swap Red-Blue
		{/**/unsigned char tmp = data[i];	data[i] = data[i + 2];	data[i + 2] = tmp;
	if (i > size - 900) cout << int(data[i]) << ' ' << int(data[i + 1]) << ' ' << int(data[i + 2]) << endl;
		}
	/**/glGenTextures(2, &texName[0]);
	/**/glBindTexture(GL_TEXTURE_2D, texName[0]);
	/**/glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	/**/glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //tex0 array[][]
	return (data);
}

void drawTexture()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName[0]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	//D..,BLEND,MODULATE);//
	glBegin(GL_QUADS);
	glTexCoord2f(0., 0.);	glVertex3f(-2.*L, -L, 0.);
	glTexCoord2f(1., 0.);	glVertex3f(2.*L, -L, 0.);
	glTexCoord2f(1., 1.);	glVertex3f(2.*L, L, 0.);
	glTexCoord2f(0., 1.);	glVertex3f(-2.*L, L, 0.);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

int rrr = 0, k = 0;

////////////////////////// MACROS
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
#define L4 glEnable(GL_LIGHT4);
#define l4 glDisable(GL_LIGHT4);
#define L5 glEnable(GL_LIGHT5);
#define l5 glDisable(GL_LIGHT5);
#define L6 glEnable(GL_LIGHT6);
#define l6 glDisable(GL_LIGHT6);
#define L7 glEnable(GL_LIGHT7);
#define l7 glDisable(GL_LIGHT7);

#define Scub glutSolidCube(			//four primitives
#define Ssph glutSolidSphere(
#define Scon glutSolidCone(
#define Stor glutSolidTorus(

#define Wcub glutWireCube(
#define Wsph glutWireSphere(
#define Wcon glutWireCone(
#define Wtor glutWireTorus(
///////////////////////////		End Macros
///////////////////////// Robots start here
/**/float spred = 150., widen = .03; //distance between 2 robots (spredding)
int n = 30;
float an = 0., da = 1. / n;  //da  must be inversly proportional to the number of robots n (for walking speed control)

float steer = 0., speed = .05; //angle in radians

							   /////////////////////////
void bar() { M	S 1., 9., 1.); glutSolidCube(1.1);	m }

void halfRobot(float w) //w width between the two arms and/or the two legs
{
	an += da; if (an <= -360. || an >= 360.) da = -da;
	M  T - w, 0., .0);  R - an*widen, 1., 0., 0.); T - w, -5., 0.); L1 bar();  l1 m	//left member
		M  T  w, 0., .0);  R  an*widen, 1., 0., 0.); T  w, -5., 0.); L2 bar();  l2 m	//right member
}

void Robot()
{
	M	S 3.3, 1.1, 2.2); bar();  m        M	T 0., 8., 0.);	Ssph 3., 8, 4);  m	//body, head
	M T 0., 5., 0.); halfRobot(1.); m   //hands are w=1. far from each other from -1. to 1. along X-axis
		M T 0., -5., 0.); halfRobot(.5); m	//legs  are w=.5 far from each other from -.5 to .5 along X-axis
}

void DancingRobots()  //draw n dancing robots
{
	M T  0., -70., 400.); S .2, .2, .2); for (int i = 0; i < n; i++) //n=50
	{
		T spred, 0., 0.);   //was 3.*spred
							//if(i % 2) T 2.*spred, 0.,-spred); 
							//if(i % 4 == 2)T spred, 0., spred); 
							//if(i % 4 == 3)T spred, -spred, spred);
							R 16.*i, 0., 1., 0.); Robot();
	} m
		// 	M  T 0., -20., 0.); S 60., 1., 60.); L4 Scub 10.); l4  m	//ground  L1
}

//////////////////////////////////////////////////////  save block is good, and try others below them
int fan = 0, cn = 0, cc = 0; // steps counter animator
int ang = 0., angl[4] = { 20., 40., 60., 20. }, fall = 0, shots = 0;

void rob(int i) {
	/**/M R 90., 0., 1., 0.);  //this was good, now possible falling in the next line
	if (fall&&i == 2 && rrr < 700) { if (++shots == 10) PlaySound(TEXT("shot.wav"), NULL, SND_FILENAME); T 0., -rrr, 0.); R rrr, 0.05, 0., 0.); } Robot(); //press f, what happened? press f again
	ang = angl[i] + (1 - rand() % 3);	//good
	if (cc % 10 == 0) angl[i] = ang;
	R ang, 1., 0., 0.);  S 1., 7., 1.);	//anim Rob bars
	bar(); m
}

void rollerCoster()
{
	glutSolidCube(20.); M T 0., -40., 0.); S 2., .3, 1.); glutSolidCube(20.); m 	M M L7 T 0., -10., 0.); S 4., 6., 6.); bar(); l7 m  //body_blocks of
		glRotatef(float(.1*rrr), 0., 0., 1.); glutWireSphere(40., 17, 6);  m
}

void  rollerCoster1()
{
	M  L0 T - 100., 30., 100); S .5, .2, .5); rollerCoster(); l0 m
}

void drawScene()
{
	drawTexture();
	rollerCoster(); rollerCoster1();
	M S 2., 2., 2.);
	M T - 126. - (.8*cn), 0. + (.35*cn), 1.);	L1 rob(1); l1 m //Rob1 in the middle
		M T - 300. - (cn), 50., 1.);			L2 rob(2); l2 m //Rob2 going left on top
		M T 0. - (.6*cn), -80. + (.45*cn), 1.);	L3 rob(3); l3 m //Rob3 ascending on the bottom
		m
		/**/										DancingRobots();	//closest group of people
	/**/M T - 280., 80., -150.); S .7, .7, .7);	DancingRobots(); m  //middle group
		/**/M T - 200., 60., -150.); S .5, .5, .5); DancingRobots(); m  //farthest group

		M T - 600. - .05*rrr, -150., 10.);  L1 rob(1); l1 m	//climbers
		M T - 800. + .05*rrr, -300. - .01*rrr, 10.);  L1 rob(3); l1 m	//climbers
																		//////// flying stuff
		M T .3*rrr - 300., 200., 4.); Ssph 2., 4, 2); m //airplane1
		M T - .5*rrr + 600., 300. - .05*rrr, 4. ); S 3., .3, 2.); Ssph 4., 3, 2); m //airplane2
																					//////////////////////////////
		M T  0., .1*rrr + 50., 4.);  //spaceship
									 //if (rrr % 2)
		{
		glEnable(GL_COLOR_MATERIAL);
		//glColor3f(1., 1., 0.);	R - 90., 1., 0., 0.); Scon 5., 25., 32, 2); 
		R - 90., 1., 0., 0.); T 0., -80., 0.);  S 1., 1., 10.); Stor 1., 4., 32, 16);
		glDisable(GL_COLOR_MATERIAL);
		}
		m
}

void wheel() { M Wtor .2, 1.5, 3, 10); m }
void biker()
{
	M T 380., -140., 220.); L1 Ssph 4., 3., 3); l1 T - 5., 1., 2.); wheel(); T 7., -3., 0.); wheel(); m
} //at initial position, draw a bike
void bikers()
{//animate bikers
	M T - .002*rrr, .0005*rrr, 0.); float scl = (3600. - rrr) / 3600.; S scl, scl, scl); biker(); T - 10., -20., 0.); biker(); m
}
//////////////////////////////////////////////////////
int orth = 0, people = 1;

void display()
{
	cc = ++cc % 30000; cn = .005*cc; //animator
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // | GL_RGBA);
	bikers(); drawScene();
	glutSwapBuffers();
}
void spinRedisplay() { rrr = (++rrr) % 3600; if (spred < 400.)spred += .01; else spred = 100.; glutPostRedisplay(); }

void init()
{
	glClearColor(0., 1., 1., 1.); //glShadeModel(GL_SMOOTH);
	readBMPfile(3);  //texture 4  out of (0..4)
					 /////////////////////
	cout << "0=perspective 1=ortho  \nSelect projection <0,1> "; cin >> orth;
	glClearColor(0., 1., 1., 1.);
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
	glEnable(GL_DEPTH_TEST);

	/**/	glEnable(GL_BLEND);
	/**/	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/**/	PlaySound(TEXT("robotsMusic.wav"), NULL, SND_ASYNC);
	glutIdleFunc(spinRedisplay);
	/////////////////////
}

void reshape(int w, int h) //w = glutGet(GLUT_WINDOW_WIDTH); h= glutGet(GLUT_WINDOW_HEIGHT);
{
	int W = 1000, H = 600;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	{ gluPerspective(80., (GLfloat)w / (GLfloat)h, .1, 900.); glTranslatef(.0, .0, -.5*W); }
	glMatrixMode(GL_MODELVIEW);		glLoadIdentity();
}

float t = .01, x = 0., y = 0., z = 0.; int X, Y, Z;

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'f': PlaySound(TEXT("robotsMusic.wav"), NULL, SND_ASYNC); if (fall)  PlaySound(TEXT("shot.wav"), NULL, SND_ASYNC);
		/**/	  fall = fan = ++fan % 2; break;  //try the falling rob2
	case 'i':	k = ++k % 4;	readBMPfile(k); 	break;
		//case 'I':	glutIdleFunc(spinRedisplay); break;
	case 'X':	X = 1; Y = Z = 0;  R  1., X, Y, Z); break;
	case 'x':	X = 1; Y = Z = 0;  R - 1., X, Y, Z); break;
	case 'Y':	Y = 1; X = Z = 0;  R  1., X, Y, Z); break;
	case 'y':	Y = 1; X = Z = 0;  R - 1., X, Y, Z); break;
	case 'Z':	Z = 1; X = Y = 0;  R  1., X, Y, Z); break;
	case 'z':	Z = 1; X = Y = 0;  R - 1., X, Y, Z); break;
	case 's':	spred += .1; break;
	case 'S':	spred -= .1; break;
	case 'p':	people = ++people % 2; break;
	case 'A':	  T 1, 0., 0.); break;
	case 'B':	  T 0., 1, 0.); break;
	case 'C':	  T 0., 0., 1); break;
	case 'a':	  T - 1, 0., 0.); break;
	case 'b':	  T 0., -1, 0.); break;
	case 'c':	  T 0., 0., -1); break;
	case '0':	x = y = z = 0.; break;
	}	glutPostRedisplay();
}

void mouse(int key, int state, int x, int y)
{
	switch (key)
	{
	case	GLUT_KEY_LEFT:		if (state == GLUT_DOWN) { glutIdleFunc(spinRedisplay); cout << "leftMouse" << endl; } break;
	case	GLUT_KEY_RIGHT:		if (state == GLUT_DOWN) { glutIdleFunc(NULL); cout << "rightMouse" << endl; } break;
	}	glutPostRedisplay();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1600., 800.);  glutInitWindowPosition(0, 0);
	glutCreateWindow("THE FALLING ROB IN A SUNNY DAY !!!");
	init();
	/**/glutKeyboardFunc(keyboard);
	/**/glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
////////////////////////  END  PROGRAM ////////////////
/////////////////////////////////////
/*
unsigned char* readBMP()
{	int i;
FILE* f = fopen("getImage.bmp", "rb");			 //filename
unsigned char info[54];
fread(info, sizeof(unsigned char), 54, f);		// read the 54-byte header	// extract image height and width from header
int width = *(int*)&info[18];
int height = *(int*)&info[22];
int size = 3 * width * height;
unsigned char* data = new unsigned char[size];	// allocate 3 bytes per pixel
fread(data, sizeof(unsigned char), size, f);	// read the rest of the data at once
fclose(f);
for (i = 0; i < size; i += 3)	{unsigned char tmp = data[i];	data[i] = data[i + 2];		data[i + 2] = tmp;}	return data;
}
void fileToTexture()	//create texture array: tex0[wid][hei][3] //3 for RGB
{	FILE *fil; unsigned char *arr; int i, j, k;
arr = (unsigned char *)malloc(wid*hei * 3 * sizeof(unsigned char));
fopen_s(&fil, "roads256.bmp", "rb");
fread(arr, wid*hei * 3 + 1, 1, fil);  	//fread(arr,1,wid*hei*3,fil); //original
for (i = 0;i<54;i++)arr++;			//skip 54 bytes, the image overlead
for (i = 0;i<wid;i++)for (j = 0;j<hei;j++) { for (k = 0;k<3;k++) tex0[j][i][2 - k] = *(arr++); tex0[j][i][3] = 128; } //copy array to texture[256x256]
fclose(fil);
glGenTextures(2, &texName[0]);	//2 = Size
glBindTexture(GL_TEXTURE_2D, texName[0]);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, wid, hei, 0, GL_RGB, GL_UNSIGNED_BYTE, tex0); //tex0[wid=1024][hei=1024][3]
}
*/