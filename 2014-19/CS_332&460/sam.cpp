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
#define  W 600  //window Sz=600x600 = WxH
#define  H 600	//window Sz=600x600 = WxH

float XXX = 0., YYY = 0.; //pointing: mouse position in window coordinates

void pointing(float xx, float yy)
{	int Wid = glutGet(GLUT_WINDOW_WIDTH); int Hei = glutGet(GLUT_WINDOW_HEIGHT);  cout << "\nwindowWH : " << Wid << ',' << Hei << endl;
	cout << "mouse pixels: xx, yy :  " << xx << ",\t\t" << yy << endl;
	//glutGet(GLUT_WINDOW_X); glutGet(GLUT_WINDOW_Y); //https://www.opengl.org/resources/libraries/glut/spec3/node70.html
	XXX = (xx		/ Wid)*W; //-0  because the window origin is the same as the coords origin (left, top and botum corner )
	YYY = ((Hei-yy) / Hei)*H;
	cout << "mouse coords: XXX,YYY : " << XXX << ",\t" << YYY << endl;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//M L1 T 100., 100., 0.); Scub 100.); l1 m
	M T W / 4., H / 4., 0.); R an, 1., 0, 0); Wcub 90.); m
	M T W/4., 3 * H / 4., 0.); R an, 1., 0, 0); L L4 Scub 60.); l4 } m
	glutSwapBuffers();
}

void spinDisplay() {glutPostRedisplay(); } 

void keyboard(unsigned char key, int xx, int yy)
{	switch (key)
	{
	case 'm':	PlaySound(TEXT("music.wav"), NULL, SND_ASYNC); break;
	case 'M':	PlaySound(NULL, NULL, NULL); break;
	}
	glutPostRedisplay();
}

void special(GLint key, GLint x, GLint y)
{	//if (key == GLUT_KEY_F2) 	
	glutPostRedisplay();
}

void mouse(int button, int state, int xx, int yy)
{	pointing(xx, yy);
	switch (button)
	{
	case GLUT_LEFT_BUTTON: if(state == GLUT_DOWN) { glutIdleFunc(spinDisplay); } break;
	case GLUT_RIGHT_BUTTON: if(state == GLUT_UP)  { glutIdleFunc(NULL); } break; 
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION); 	glLoadIdentity();
	glOrtho(0,W,0,H, -W,H);	
	glMatrixMode(GL_MODELVIEW);		glLoadIdentity();	
}

void init() {
	glClearColor(1., 1., 1., 1.); initColoring();
}

void main(int argc, char **argv)
{ glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize (W, H); glutInitWindowPosition(0,0);
  glutCreateWindow("Dr. Tannouri's easiest volume visualization");
  init(); 
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);  
  glutSpecialFunc(special);
  glutReshapeFunc(reshape);
  glutMainLoop(); 
}