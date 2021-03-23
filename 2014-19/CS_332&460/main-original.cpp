#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h> 
#pragma comment(lib, "winmm.lib") 
#include <iostream>
using namespace std;
#include <GL/glut.h>
#include "template.h"
#define  W 800  //window Sz=600x600 = WxH
#define  H 800	//window Sz=600x600 = WxH
#define  P 800


float XXX = 0., YYY = 0.; //pointing: mouse position in window coordinates
int airpin = 0;
int MajorProg = 0;  //select 0= nCubes or 1 = MajorProg
int n = 1, ob = 0;
float alpha = 0., xa[5], yb[5], zc[5], x = 0., y = 1., z = 0., dt = 1., dt1 = .001, ha = 1., va = 1., speed = .001; //ha, and speed used by the car only (car animation)



void pointing(float xx, float yy)
{
	int Wid = glutGet(GLUT_WINDOW_WIDTH); int Hei = glutGet(GLUT_WINDOW_HEIGHT);  cout << "\nwindowWH : " << Wid << ',' << Hei << endl;
	cout << "mouse pixels: xx, yy :  " << xx << ",\t\t" << yy << endl;
	//glutGet(GLUT_WINDOW_X); glutGet(GLUT_WINDOW_Y); //https://www.opengl.org/resources/libraries/glut/spec3/node70.html
	XXX = (xx / Wid)*W; //-0  because the window origin is the same as the coords origin (left, top and botum corner )
	YYY = ((Hei - yy) / Hei)*H;
	cout << "mouse coords: XXX,YYY : " << XXX << ",\t" << YYY << endl;
}

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
//float d = 400., ang = 0.;

int nn = 10;

void car() { L1 S 1., 1., 2.); Scub .5); l1 }
void air() {
	L1 M S 1., 1., 6.); Ssph .05, 16, 8); m
	M S 6., .2, 1.); Ssph .06, 16, 6); m
	M T 0., .03, -.3); S 2., .2, 1.); Ssph .06, 16, 6); m
	M T 0., .03, -.3); S .06, .5, .3); Ssph .2, 3, 3); m l1
}
void grid()
{
	M  R alpha, 1., 0., 0.);
	T - 50., 50., -50.);
	//M S 10., .5, 10.);
	for (int i = 0; i < nn; i++) { M for (int j = 0; j < nn; j++) { Scub 1.); T 11., 0., 0.); }m  T 0., -11., 0.); }m

		L4 Ssph 3., 16, 8); l4
		m
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//M L1 T 100., 100., 0.); Scub 100.); l1 m
	//grid();

	//if (MajorProg)d
	//{
	//	///**/T xa[0], yb[0] - 10., zc[0]);  R alpha, 1., 0., 0.); //use with 5 cubes only
	//	///**/R ha, 1., 0., 0.);
	//	/**/M drawScene(); drawCar(); m //global positionning
	//}
	//else //n cubes
	//{
	//readBMPfile(1);
	
	//M	
	//	R alpha, 1., 0., 0.); 
	//l drawTexture(1); L
	//M S .05*W, .001*W, .05*W); M S 10., .5, 10.); L5 Scub 1.); l5 m		//terrain 
	//T x, 1. + y, z); R ha, 0., 1., 0.); R va, 1., 0., 0.); if (airpin) air; else;
	//M S 10., .5, 10.); L5 Scub 1.); l5 m		//terrain 
	//M S 10., 5., 10.); L5 drawTexture(1); l5 m
	//{
	M	R alpha, 1., 0., 0.);
	drawTexture(0);
	//	M S 10., .5, 10.);      L5 Scub 1.); l5 m											 //terrain 
	//for (int i = 0; i < n; i++) { M  T xa[i], yb[i] + 1., zc[i] - 10.); R - ha, 0., 1., 0.); L3 Scub 1.); l3 m } //n=5 cubes 
	T x, 1. + y, z); R ha, 0., 1., 0.); R va, 1., 0., 0.); if (airpin)air(); else car();
	m
		//}																			 //for (int i = 0; i < n; i++) { M  T xa[i], yb[i] + 1., zc[i] - 10.); R - ha, 0., 1., 0.); L3 Scub 1.); l3 m } //n=5 cubes 
	//T 1. + x, + y, z); R ha, 0., 1., 0.); R va, 1., 0., 0.); if (airpin)air(); else car();
		//T x, y, 1. + z); R ha, 0., 1., 0.); R va, 1., 0., 0.); if (airpin)air(); else car();
	m
	
		//}
		glutSwapBuffers();
	//glutSwapBuffers();
}

void spinDisplay() { //if (ang < 360.)ang += .3; else ang = 0.;
	x += speed * sin(ha / 57.3)*cos(va / 57.3); z += speed * cos(ha / 57.3)*cos(va / 57.3); if (y >= -3.)y += speed * sin(-va / 57.3); else { y = .01; va = 0.; }; 
	glutPostRedisplay(); }

void keyboard(unsigned char key, int xx, int yy)
{
	switch (key)
	{
	//case 'm':	PlaySound(TEXT("music.wav"), NULL, SND_ASYNC); break;
	//case 'M':	PlaySound(NULL, NULL, NULL); break;
	//case ' ':	MajorProg = ++MajorProg % 2;  break; //case 'm': PlaySound(TEXT("music.wav"), NULL, SND_ASYNC); break;	case 'M':	PlaySound(NULL, NULL, NULL); break;
	case 'r':	alpha += dt; break;		case 'R':	alpha -= dt; break;  //global tilt  about X alpha degrees

																		 //use with 5 cubes only 
	/**/	case '0':	ob = 0; break;	case '1':	ob = 1; break;	case '2':	ob = 2; break;	case '3':	ob = 3; break;	case '4':	ob = 4; break;
	///**/case 'a':	ha += dt; break;	case 'A':	ha -= dt; break;  //tilt about X a degrees
	///**/case 'b':	yb[ob] += dt; break;	case 'B':	yb[ob] -= dt; break;  //tilt about X a degrees
	///**/case 'c':	x += ha; break;	case 'C':	x -= ha; break;  //tilt about X a degrees
	case '+':	if (speed < .01)speed += dt1; break;			case '-': if (speed > 0.) speed -= dt1; break;
	case ' ':	va = 0.; break;
	case '?':	airpin = ++airpin % 2; break;
	case '/':	va = ha = x = y = z = speed = 0; break;
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
	if (key == GLUT_KEY_LEFT) { ha += 1.; if (ha > 350.) ha = 1.; } else
	if (key == GLUT_KEY_RIGHT) { ha -= 1.; if (ha < -350.) ha = 1.; } else
	if (key == GLUT_KEY_UP) { va += 1.; if (va > 350.) va = 0.; } else
	if (key == GLUT_KEY_DOWN) { va -= 1.; if (va < -350. || y < -.001) y = va = .01; } else
    if (key == GLUT_KEY_END) y = va = 0.;
	glutPostRedisplay();
}

void mouse(int button, int state, int xx, int yy)
{
	pointing(xx, yy);
	switch (button)
	{
	//case GLUT_LEFT_BUTTON: if (state == GLUT_DOWN) { glutIdleFunc(spinDisplay); } break;
	//case GLUT_RIGHT_BUTTON: if (state == GLUT_UP) { glutIdleFunc(NULL); } break;
	case GLUT_LEFT_BUTTON: if (state == GLUT_DOWN) { glutIdleFunc(spinDisplay); } //pointing(xx, yy);}
																				  //if(sound)	PlaySound(TEXT("goodBadUgly.wav"), NULL, SND_ASYNC);
						   break;
	case GLUT_RIGHT_BUTTON: if (state == GLUT_UP) { glutIdleFunc(NULL); PlaySound(NULL, NULL, NULL); } break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	//ORIGINAL
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	//glOrtho(0, W, 0, H, -W, H);
	//glMatrixMode(GL_MODELVIEW);		glLoadIdentity();
	///////
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	//gluPerspective(60., (GLfloat)w / (GLfloat)h, .1, d);
	gluPerspective(90., 1., .1, 10.*W);
	glMatrixMode(GL_MODELVIEW);	glLoadIdentity();
	//glTranslatef(.0, .0, -50);
	if (MajorProg) { T - .5*W, .01*W, -W); } //used with Major Project only
	else { T 0., 0., -10.); }      //used with the 5 cubes only
}

void init() {
	//glClearColor(1., 1., 1., 1.); initColoring();
	//srand(time(0)); 
	glClearColor(.3, .7, 1., 1.);
	//glClearColor(0., 1., 1., 1.);
	initColoring();  readBMPfile(1); //ini();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
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