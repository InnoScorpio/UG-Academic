#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
using namespace std;

#define ShipAngle glRotatef(-55, -10.0, 0.0, 0.0);
//#define ThrustAngle glRotatef(-20, -10.0, 0.0, 0.0);
static float maxjump = 50;
bool _Right = false;
bool _Left = false;
bool Rlock = false;
bool Llock = false;
static bool _Jump = false;
float a1 = 0;
float Tx = 0.0;
float Ty = .00;
static int g_counter = 0;
static int j = 0;
#define MAX_TEXT_SIZE  255			/* maximum text string length */
#define GAP		1000

GLfloat mat_ambient[] = { .9,.9,.9, 1.0 };
GLfloat mat_specular[] = { 1.,1.,1., 1.0 };
GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)

									//your gl function protos
void MyKeyboardFunc(unsigned char Key, int x, int y);
void Ship();
void Thrust();

//configure inits
void init(void)
{

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glEnable(GL_BLEND);
	glMatrixMode(GL_MODELVIEW);
	//glMatrixMode(GL_PROJECTION);
}

void drawText(const char * message, GLfloat x, GLfloat y)
{
	/* raster pos sets the current raster position
	* mapped via the modelview and projection matrices
	*/
	glRasterPos2f(x, y);

	/*
	* write using bitmap and stroke chars
	*/
	while (*message) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *message++);
	}
}

void reshape(GLsizei width, GLsizei height)
{


	glViewport(0, 0, (GLsizei)width, (GLsizei)height); //viewport to cover new window


	glLoadIdentity(); // Reset the projection matrix
	gluPerspective(50., (GLfloat)width / (GLfloat)height, .1, 100.); //set z to 100
	glMatrixMode(GL_MODELVIEW);
	//glMatrixMode(GL_PROJECTION);
	glTranslatef(.0, -.2, -2.5); //set start view location
	glRotatef(180, .0, 1.0, 0);
}
//handles your refresh
void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(16, Timer, 0);
}

void myTimer(int value) {
	if (j == 0)
	{
		g_counter = value + 1;
	}
	else if (j == 1)
	{
		g_counter = value + 0;
	}
	else
	{
		g_counter = 0;
	}
	glutPostRedisplay();
	glutTimerFunc(GAP, myTimer, g_counter);
}

//use this for keyup and keydown input parameters
void KeyDown(unsigned char Key, int x, int y)
{
	switch (Key)
	{
	case 'a': _Right = true; break;
	case 'd': _Left = true; break;
	case ' ': _Jump = true; break;
		exit(1);
		break;
	}

}

void KeyUp(unsigned char Key, int x, int y)
{
	switch (Key)
	{
	case 'a': _Right = false; break;
	case 'd': _Left = false; break;
		exit(1);
		break;
	}
}

//optional display a menu
void menu()
{
}

// create thruster design
void Thrust()
{
	static float i = 3;
	if (i == 3)
	{
		glColor3f(.8, .8, .0);
		glPushMatrix();
		glutSolidSphere(.06, 10, 50);
		glPopMatrix();
		i = 0;
	}
	else
		glColor3f(1., .0, .0);
	glPushMatrix();
	glScalef(.5, 2, .5);
	glutSolidSphere(.06, 10, 50);
	glPopMatrix();
	i++;
}

//create player ship design
void Ship()
{
	//THRUST
	glPushMatrix();
	glTranslatef(-.1, -.2, .0);
	Thrust(); //draw right thrust
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.1, -.2, .0);
	Thrust(); //draw left thrust
	glPopMatrix();

	//BODY
	glColor3f(2.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(.0, .0, -.05);
	glutSolidSphere(.097, 10, 50);
	glPopMatrix();

	//face wing
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(.0, .3);
	glColor3f(1.0, .0, .0);
	glVertex2f(.07, .1);
	glVertex2f(-.07, .1);
	glEnd();

	//right wing
	glTranslatef(.0, .0, -.05); //must be undone after
	glBegin(GL_TRIANGLES);
	glColor3f(.0, .0, 1.0);
	glVertex2f(-.1, .0);
	glColor3f(.5, 1.0, 1.0);
	glVertex2f(-.1, -.1);
	glVertex2f(-.2, -.1);
	glEnd();

	//left wing
	glBegin(GL_TRIANGLES);
	glColor3f(.0, .0, 1.0);
	glVertex2f(.1, .0);
	glColor3f(.5, 1.0, 0.5);
	glVertex2f(.1, -.1);
	glVertex2f(.2, -.1);
	glEnd();

}

void boxes()
{
	glPushMatrix();
	glutSolidCube(0.3f);
	glPopMatrix();
}

//main display for objects
void display(void)
{
	glPopMatrix();
	char text[MAX_TEXT_SIZE];
	cout << text << "seconds have elapsed" << g_counter << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	drawText(text, -2.0, 1);
	drawText("Press q to quit", -2.0, 0);
	glutTimerFunc(GAP, myTimer, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//TEST INSERT BOX CODES HERE
	static float movz = 3.0;
	if (movz < -3.0) { movz = 3.0; }
	glPushMatrix();
	glTranslatef(-.3, -.2, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .03;
	glPopMatrix();

	// spawn ship 
	glPushMatrix();
	//handle ship movements
	if (_Right || Rlock)
	{
		Tx += .03; a1 -= .3;
	}
	if (_Left || Llock)
	{
		Tx -= .03; a1 += .3;
	}

	if (_Jump) //set jump
	{
		maxjump -= 1;

		if (_Right && maxjump == 49) //set movement jump locks
		{
			Rlock = true;
		}
		else if (_Left && maxjump == 49) { Llock = true; }

		if (maxjump >= 25) // jump by how long
		{
			Ty += .02; _Right = false; _Left = false;
		}
		else if (maxjump < 25)
		{
			Ty -= .02; _Right = false; _Left = false;
		}

		if (maxjump == 0) //reset jump
		{
			maxjump = 50;
			_Jump = false;
			Rlock = false; Llock = false;
		}
	}
	//end movements
	glRotatef(a1, 0.0, 0.5, 0.0); glTranslatef(Tx, Ty, 0);
	ShipAngle;
	Ship();


	// end ship

	glutSwapBuffers();
}

//this is MAIN cycle of all code functions called
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Game Test");
	init();
	//let GL know your func names
	glutTimerFunc(0, Timer, 0);
	glutTimerFunc(GAP, myTimer, 0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMainLoop();
}
