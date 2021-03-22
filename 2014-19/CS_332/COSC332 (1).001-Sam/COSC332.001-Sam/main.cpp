#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
using namespace std;

#define ShipAngle glRotatef(-55, -10.0, 0.0, 0.0);
#define ThrustAngle glRotatef(-20, -10.0, 0.0, 0.0);

static bool _right = false;
static bool _left = false;
extern GLfloat spin = 0.;
GLfloat mat_ambient[] = { .9,.9,.9, 1.0 };
GLfloat mat_specular[] = { 1.,1.,1., 1.0 };
GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)
float xRotated = 50.0, yRotated = 0.0, zRotated = 0.0;
float width = 10.0, height = 20.0;

									//your gl function protos
void MyKeyboardFunc(unsigned char Key, int x, int y);
//void Ship();
//void Thrust();

//configure inits
void init(void)
{
	glClearColor(.0, .5, .5, .0);
	//glMatrixMode(GL_PROJECTION);
	//glOrtho(0, 800, 600, 0, 1, -1);
	//glShadeModel(GL_SMOOTH);
	//glViewport(0, 0, 800, 600);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0, 800, 600, 0, 1, -1);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 640 * height / width, 0, 1, -1);


	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_ambient);

	//glEnable(GL_LIGHTING); 
	//glEnable(GL_LIGHT1);		//enable some lighting

	glEnable(GL_DEPTH_TEST);
}

void spinDisplay()
{
	spin += spin;
	//glTranslatef(.0, .00005, .0);
	if (spin > 360)
	{
		spin = 0;
	}
	glutPostRedisplay();

}
void Blocks()
{

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.5f, -0.5f);    // x, y
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
	
	  // Render now
}
//use this for key input parameters
void KeyDown(unsigned char Key, int x, int y)
{
switch (Key)
	{
	//case 'a': glRotatef(2, 0.0, 50.0, 0.0); glTranslatef(-.03, 0, 0); break;
	//case 'd': glRotatef(2, 0.0, -50.0, 0.0); glTranslatef(.03, 0, 0); break;
	case 'l':  glTranslatef(-.1, 0, 0); break;
	case 'r':  glTranslatef(.1, 0, 0); break;
	case 'u': glTranslatef(0, .1, 0); break;
	case 'n': glTranslatef(0, -.1, 0); break;

		//case ' ': if (LeftButtonDown)
		//if (RightButtonDown) RightButtonDown=0; else RightButtonDown=1;
		//break;
		//case 27: 
		exit(1);
		break;
	}


}

void KeyUp(unsigned char Key, int x, int y)
{
	if (Key == 'd')
	{
		_right = false;
	}

}

//optional display a menu
void menu()
{
}

//main display for objects
void display(void)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw ship parts
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	
	ShipAngle;
	
	Blocks();
	//Ship(); // draw ship
	glPopMatrix();
	//glTranslatef(0.0, -.001, 0.0);
	spinDisplay(); //animate objects
	

	glutSwapBuffers();


}

/*void Thrust()
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
}*/

//create player ship design
/*void Ship()
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
	glTranslatef(.0, .0, -.05);
	glBegin(GL_TRIANGLES);
	glColor3f(.0, .0, 1.0);
	glVertex2f(-.1, .0);
	glColor3f(.5, 1.0, 1.0);
	glVertex2f(-.1, -.1);
	glVertex2f(-.2, -.1);
	glEnd();


	//left wing
	//glTranslatef(.0, .0, -.1);
	glBegin(GL_TRIANGLES);
	glColor3f(.0, .0, 1.0);
	glVertex2f(.1, .0);
	glColor3f(.5, 1.0, 0.5);
	glVertex2f(.1, -.1);
	glVertex2f(.2, -.1);

	glEnd();

	glFlush();

}*/

static void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
     glOrtho(-2.0, 2.0, -2.0, 2.0, -1.5, 1.5);

	glMatrixMode(GL_MODELVIEW);
}

//this is MAIN cycle of all code functions called
//void main(int argc, char** argv)
int main(int argc, char** argv)
{
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowPosition(50, 100);
	//glutInitWindowSize(700, 700);
	//glutCreateWindow("Game Test");
	//init();
	//glutDisplayFunc(display);
	//glutKeyboardFunc(KeyDown);
	//glutKeyboardUpFunc(KeyUp);
	//glutMainLoop();
	glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Square moves"); // Create a window with the given title
	glutInitWindowSize(700, 700);   // Set the window's initial width & height
	glutInitWindowPosition(50, 100); // Position the window's initial top-left corner
    glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
	}

