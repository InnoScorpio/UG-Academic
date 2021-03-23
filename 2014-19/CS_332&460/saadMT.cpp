

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h> 
#pragma comment(lib, "winmm.lib") 
#include <iostream>
using namespace std;
#include <GL/glut.h>
//#include "samTemplate.h"

#define W 600
#define H 600
#define P 800

//SamTemplate.h
/////////////////////////////////////////////////////
#define M glPushMatrix();		// MACROS
#define m glPopMatrix();
#define T glTranslatef(
#define	R glRotatef(
#define S glScalef(
#define L  glEnable(GL_LIGHTING);
#define l  glDisable(GL_LIGHTING);

#define L0 glEnable(GL_LIGHT0);	//red	// E/Disable four lights 0..3
#define l0 glDisable(GL_LIGHT0);
#define L1 glEnable(GL_LIGHT1);	//red
#define l1 glDisable(GL_LIGHT1);
#define L2 glEnable(GL_LIGHT2); //yellow
#define l2 glDisable(GL_LIGHT2);
#define L3 glEnable(GL_LIGHT3);	//move
#define l3 glDisable(GL_LIGHT3);
#define L4 glEnable(GL_LIGHT4);	//grey	// E/Disable four lights 0..3
#define l4 glDisable(GL_LIGHT4);
#define L5 glEnable(GL_LIGHT5); //move light 
#define l5 glDisable(GL_LIGHT5);
#define L6 glEnable(GL_LIGHT6); //red light
#define l6 glDisable(GL_LIGHT6);
#define L7 glEnable(GL_LIGHT7); // red
#define l7 glDisable(GL_LIGHT7);
#define L8 glEnable(GL_LIGHT8); // no can be set to a color
#define l8 glDisable(GL_LIGHT8);
#define L9 glEnable(GL_LIGHT9); // no "
#define l9 glDisable(GL_LIGHT9);

#define Scub glutSolidCube(			//four primitives
#define Ssph glutSolidSphere(
#define Scon glutSolidCone(
#define Stor glutSolidTorus(
#define Wcub glutWireCube(
#define Wsph glutWireSphere(
#define Wcon glutWireCone(
#define Wtor glutWireTorus(

GLfloat mat_ambient[] = { .0,.0,.0, .0 };
GLfloat mat_specular[] = { 0.,0.,0., .0 };

GLfloat mat_diffuse0[] = { 1.,1.,1., 1. }; //white
GLfloat mat_diffuse1[] = { 1.,.0,.0, 1. }; //red
GLfloat mat_diffuse2[] = { 0.,0.,1., 1. }; //blue
GLfloat mat_diffuse3[] = { 0.,0.,1., .5 }; //blue
GLfloat mat_diffuse4[] = { 0.,1.,1., .5 }; //sky
GLfloat mat_diffuse5[] = { 0.,0.,1., .5 }; //violet
GLfloat mat_diffuse6[] = { 1.,.5,0., .5 }; //brown
GLfloat mat_diffuse7[] = { 1.,1.,0., .5 }; //yellow
GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)

GLfloat light0_position[] = { 0., 190., 130., 1.0 };
GLfloat light1_position[] = { 0., 150., 150., 1.0 };
GLfloat light2_position[] = { 0., 150., 150., 1.0 };
GLfloat light3_position[] = { 0., 150., 150., 1.0 };
GLfloat light4_position[] = { 0., 150., 150., 1.0 };
GLfloat light5_position[] = { 0., 150., 150., 1.0 };
GLfloat light6_position[] = { 0., 150., 150., 1.0 };
GLfloat light7_position[] = { 0., 150., 150., 1.0 };

void initColoring(void)
{
	glClearColor(1., 1., 1., 1.);
	glShadeModel(GL_SMOOTH);	//default: SMOOTH   not  FLAT
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_ambient);

	glLightfv(GL_LIGHT0, GL_POSITION, light0_position); //three positions for light sources
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
	glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
	glLightfv(GL_LIGHT5, GL_POSITION, light5_position);
	glLightfv(GL_LIGHT6, GL_POSITION, light6_position);
	glLightfv(GL_LIGHT7, GL_POSITION, light7_position);

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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

float XXX = 0., YYY = 0.; //pointing: mouse position in window coordinates

void pointing(float xx, float yy)
{
	int Wid = glutGet(GLUT_WINDOW_WIDTH); int Hei = glutGet(GLUT_WINDOW_HEIGHT);  cout << "\nwindowWH : " << Wid << ',' << Hei << endl;
	cout << "mouse pixels: xx, yy :  " << xx << ",\t\t" << yy << endl;
	//glutGet(GLUT_WINDOW_X); glutGet(GLUT_WINDOW_Y); //https://www.opengl.org/resources/libraries/glut/spec3/node70.html
	XXX = (xx / Wid)*W; //-0  because the window origin is the same as the coords origin (left, top and botum corner )
	YYY = ((Hei - yy) / Hei)*H;
	cout << "mouse coords: XXX,YYY : " << XXX << ",\t" << YYY << endl;
}


///////////////////////////////////////////////////////////////  SamTemplate.h
static GLuint texName[6];

void readBMPfile(int txk)
{
	FILE *fil = NULL;    unsigned char info[54];
	if (txk == 0) fopen_s(&fil, "bg.bmp", "rb"); else
		if (txk == 1) fopen_s(&fil, "bg1.bmp", "rb"); else
			if (txk == 2) fopen_s(&fil, "bg2.bmp", "rb");
	if (!fil) { cout << fil << " txk= " << txk << " cannot open this file: fil\n"; getchar(); exit(0); }
	else fread(info, sizeof(unsigned char), 54, fil); // Read info: 54-byte_header;  info[18] and info[22]  //Problem ?

	int width = *(int*)&info[18];		// extract image_width  from header
	int height = *(int*)&info[22];		// extract image_height from header
	int size = 3 * width * height;

	unsigned char *data = new unsigned char[3 * width*height];

	fread(data, sizeof(unsigned char), size, fil); // Read the rest of the data (image data)
	fclose(fil);
	/////////////////////////	S  W  A  P       R,B colors       
	for (int i = 0; i < size; i += 3) { unsigned char tmp; tmp = data[i]; data[i] = data[i + 2]; data[i + 2] = tmp; }
	/////////////////////////
	glGenTextures(2, &texName[txk]);		// genTexture(2D,texName[txk])
	glBindTexture(GL_TEXTURE_2D, texName[txk]);	// bind(texture,texName)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
}

void drawTexture(int txk) {
	float h = 500.; short int  w = 1000., d = -300.;
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName[txk]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	//D..,BLEND,MODULATE,REPLACE);//
	glBegin(GL_QUADS);					//x,y,z
	glTexCoord2f(0., 0.);	glVertex3f(-w, -h, d);
	glTexCoord2f(0., 1.);	glVertex3f(-w, h, d);
	glTexCoord2f(1., 1.);	glVertex3f(w, h, d);
	glTexCoord2f(1., 0.);	glVertex3f(w, -h, d);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

int MajorProg = 0;  //select 0= nCubes or 1 = MajorProg
int n = 5, ob = 0;
float alpha = 0., xa[5], yb[5], zc[5], x = 0., y = 0., z = 0., dt = .1, ha = 0., speed = .01; //ha, and speed used by the car only (car animation)

void ini() { for (int i = 0; i < n; i++) { xa[i] = yb[i] = zc[i] = 0.; } } //loop over the 5-cubes

void drawScene()
{
	M L7 T .5*W, -.3*W, -.5*W);						S 15., .4, 8.);		Scub .25*W); l7 m				//terrain (Major Project only)
	M L3 T .5*W, -.26*W, -.1*W);  R  60., 0., 1., 0.);	S 100., 1., 3.);	Scub .03*W);  l3 m				//road straight
	M L3 T .5*W, -.26*W, -.5*W);  R - 90., 1., 0., 0.);	S 1., .1, 1.); 		Stor .03*W, W, 16, 64); l3 m	//road curve
	M L2 T .1*W, -.20*W, -.52*W);											Scub .1*W);  l2 m				//house
	M L1 T .1*W, -.15*W, -.52*W); R - 90., 1., 0., 0.);	R 45., 0., 0., 1.);	Scon .1*W, .1*W, 4, 1); l1 m	//roof

	//M S 10., .5, 10.);      L5 Scub 1.); l5 m																//terrain (5 cubes only)
}

void twoLeftTires()
{
	M T .5*W + 9., .41*H, -.5*W);  Stor 1., 2.4, 4, 16); m	//one tire of the four (rear)
	M T .5*W - 9., .41*H, -.5*W);  Stor 1., 2.4, 4, 16); m	//one tire of the four (front)
}
void drawCar()
{
	M
		/**/R ha, 0., 1., 0.);
		M T 0., -.63*W, 0.);
		L0	R ha, 0., 1., 0.); { M T 0., 0., 5.); twoLeftTires(); T 0., 0., -10.); twoLeftTires(); m } //fourTires() 
		T .5*W, .415*H, -.5*W);  S 4., .7, 1.); Scub 8.);		//lower body
		T 0., 6., 0.);   S 1., 2., 1.); Scub 3.5);				//upper body
		l0 m
			m
}

int Clik()
{
	if (XXX < W / 2 && YYY < H / 2) return 1;
	else if (XXX > P / 2 && YYY > H / 2) return 3;
	else if (XXX > P / 2 && YYY < H / 2) return 2;
	else if (XXX < W / 2 && YYY > H / 2) return 4;
	else if (XXX > W / 2 && YYY > H / 2) return 5;
	else if (XXX > W / 2 && YYY < H / 2) return 6;
}

float d = 400., ang = 0.;
void cubes()
{
	M T - 30., -20., 0.);
	if (Clik() == 1) R ang, 1., 0, 1.);
	L6 Wcub 6.); l1
	m
		M T 30., -20., 0.);
		if (Clik() == 2) R ang, 1., 0, 1.);
		L5 Wsph 4., 18, 9); l2
		m
			M T 30., 20., 0.);
			if (Clik() == 3) R ang, 1., 0, 1.);
			L4 Scub 6.); l2
			m
				M T 1., 20., 0.);
				if (Clik() == 5) R ang, 1., 0, 1.);
				L3 Scon 4., 20, 16, 1); l2
				m

					M T 1., -20., 0.);
					if (Clik() == 6) R ang, 1., 0, 1.);
					L2 Wcon 4., 20, 16, 1); l1
					m

						M T - 30., 20., 0.);
						if (Clik() == 4) R ang, 1., 0, 1.);
						L1 Ssph 4., 18, 9); l1
						m
}

int nn = 10;

void grid()
{
	M  T - 50., 50., -50.);
	for (int i = 0; i < nn; i++) { M for (int j = 0; j < nn; j++) { Scub 10.); T 11., 0., 0.); }m  T 0., -11., 0.); }m

		L5 Ssph 3., 16, 8); l5
		m
}
/////////////////////////////////////////////////////////////// end samTemplate.h

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//grid();
	//cubes();

	if (MajorProg)
	{
		/**/T xa[0], yb[0] - 10., zc[0]);  R alpha, 1., 0., 0.); //use with 5 cubes only
		/**/R ha, 1., 0., 0.);
		/**/M drawScene(); drawCar(); m //global positionning
	}
	else //n cubes
	{
		M
			R alpha, 1., 0., 0.);
			M S 10., .5, 10.);      L5 Scub 1.); l5 m											 //terrain 
			for (int i = 0; i < n; i++) { M  T xa[i], yb[i] + 1., zc[i] - 10.); L3 Scub 1.); l3 m } //n=5 cubes  
			m
	}

	glutSwapBuffers();
}

void spinDisplay() { 	//calculate changes from last frame
	//if (ang < 360.)ang += .3; else ang = 0.;
	x += speed * cos(ha / 57.3); z += speed * sin(ha / 57.3);
	glutPostRedisplay();
}

/////////////////////////////
void keyboard(unsigned char key, int xx, int yy)
{
	switch (key)
	{
		//case ' ':	MajorProg = ++MajorProg % 2;  break; //case 'm': PlaySound(TEXT("music.wav"), NULL, SND_ASYNC); break;	case 'M':	PlaySound(NULL, NULL, NULL); break;
	case 'r':	alpha += dt; break;		case 'R':	alpha -= dt; break;  //global tilt  about X alpha degrees

	//use with 5 cubes only 
	/**/	case '0':	ob = 0; break;	case '1':	ob = 1; break;	case '2':	ob = 2; break;	case '3':	ob = 3; break;	case '4':	ob = 4; break;
	/**/case 'a':	xa[ob] += dt; break;	case 'A':	xa[ob] -= dt; break;  //tilt about X a degrees
	/**/case 'b':	yb[ob] += dt; break;	case 'B':	yb[ob] -= dt; break;  //tilt about X a degrees
	/**/case 'c':	zc[ob] += dt; break;	case 'C':	zc[ob] -= dt; break;  //tilt about X a degrees

/*either one not both blocks*/

//use with Major Project only 
	//case 'x':	x +=90.*dt; break;	case 'X':	x -= 90.*dt; break; //X translate scene
	//case 'y':	y +=90.*dt; break;	case 'Y':	y -= 90.*dt; break; //Y translate scene
	//case 'z':	z +=90.*dt; break;	case 'Z':	z -= 90.*dt; break; //Z translate scene   //global positionning
	}

	glutPostRedisplay();
}

void special(GLint key, GLint x, GLint y)
{	//if (key == GLUT_KEY_F2) 	
	if (key == GLUT_KEY_LEFT) { ha += 1.; if (ha > 350.) ha = 0.; }
	else
		if (key == GLUT_KEY_RIGHT) { ha -= 1.; if (ha < -350.) ha = 0.; }
	glutPostRedisplay();
}

void mouse(int button, int state, int xx, int yy)
{
	pointing(xx, yy);
	switch (button)
	{
	case GLUT_LEFT_BUTTON: if (state == GLUT_DOWN) { glutIdleFunc(spinDisplay); } //pointing(xx, yy);}
					//if(sound)	PlaySound(TEXT("goodBadUgly.wav"), NULL, SND_ASYNC);
						   break;
	case GLUT_RIGHT_BUTTON: if (state == GLUT_UP) { glutIdleFunc(NULL); PlaySound(NULL, NULL, NULL); } break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	//gluPerspective(60., (GLfloat)w / (GLfloat)h, .1, d);
	gluPerspective(70., 1., .1, 10.*W);
	glMatrixMode(GL_MODELVIEW);	glLoadIdentity();
	//glTranslatef(.0, .0, -50);
	if (MajorProg) { T - .5*W, .01*W, -W); } //used with Major Project only
	else { T 0., 0., -10.); }      //used with the 5 cubes only
}

void init()
{	//srand(time(0)); 
	glClearColor(.3, .7, 1., 1.); initColoring(); ini();// readBMPfile(1); drawTexture(txk);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(W, H); glutInitWindowPosition(0, 0);
	glutCreateWindow("Dr. Tannouri's easiest volume visualization");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutMainLoop();
}

