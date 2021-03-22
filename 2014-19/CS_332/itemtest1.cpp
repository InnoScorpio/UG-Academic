#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <glut.h>
using namespace std;

#define ShipAngle glRotatef(-55, -10.0, 0.0, 0.0);
static float maxjump = 50; //ammount of jump time
static float exptime = 60; //ammount of explosion time
bool _Right= false;
bool _Left= false;
bool Rlock =false;
bool Llock = false;
static bool _Jump= false;
float a1= 0;
float Tx= 0.0;
float Ty= .00;

//set lights details
GLfloat sun_ambient[]={.0,.0,.0, 1.0}; 
GLfloat sun_diffuse[]={1.0, 1.0, 1.0, 1.0};	
GLfloat sun_specular[]={1.,1.,1., 1.0};	
GLfloat mat_emission[]={0.,0.,0., .0};	
GLfloat sun_position[]={-2., 1., -.2, 0.}; 
GLfloat sun_globalambient[]={0.2,0.2,0.2,1}; 
void LightSource(bool On)
{
	if (On)
	{
		//options
	//glLightModelfv(GL_AMBIENT, sun_globalambient);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sun_specular);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
	glLightfv(GL_LIGHT0, GL_POSITION, sun_position);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, sun_specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 140);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, sun_ambient);
	glEnable(GL_LIGHT0);
	}
}

//configure inits
void init(void)
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	//glMatrixMode(GL_PROJECTION);
	LightSource(true);
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

//handles your refresh. Currently set 16ms = 60fps
void Timer(int value)
{
glutPostRedisplay();
glutTimerFunc(16, Timer, 0);
}

void CollosionSystem()
{
}

//use this for keyup and keydown input parameters
void KeyDown(unsigned char Key, int x, int y)
{
	switch(Key)
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
	switch(Key)
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
	}else 
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
		glutSolidSphere(.097 , 10, 50);
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
void explosion(bool scatter)
{
	
	//make scatter effects
	if (scatter)
	{
		static float up, down, right, left;
		for (int t = 4; t>= 0 ;t--)
		{	
			glPushMatrix();
			switch (t)
				{
					case 4: glTranslatef(right, down, 0); break;
					case 3: glTranslatef(left, down, 0); break;
					case 2: glTranslatef(left, up, 0); break;
					case 1: glTranslatef(0, up, 0); break;
					case 0: glTranslatef(up, right, 0); break;
				}
		glBegin(GL_TRIANGLES);
		glColor3f(3.0, .9, .0);
				glVertex2f(.1, .0);
				glVertex2f(.1, -.1);
				glVertex2f(.2, -.1);
		glEnd();
			
			glPopMatrix();
		}
		up += 0.01; down -=0.01; left -= 0.01; right+= 0.02;
	} else 
	{
		//make spherical explosions
	static float i = 0;
	if (i == 3)
	{
	glPushMatrix();
	glColor3f(1.0, .6, .0);
	glutSolidSphere(.15, 10, 50);
	glPopMatrix();
	i = 0;
	}else 
	glPushMatrix();
	glColor3f(1, .0, .0);
	glutSolidSphere(.11, 10, 50);
	glPopMatrix();
	i++;
	}
	
	
}
void boxes()
{
	glPushMatrix();
	glutSolidCube(0.3f);
	glPopMatrix();
}
void Scene1()
{
	//This is Player Menu Scene

}

void Scene2()
{
	//Game starts. This scenery is stationary! Needs background image, boxes , CC

	//TEST boxes
	static float movz=3.0;
	if (movz < -3.0) {movz = 3.0;}
	glPushMatrix();
	glTranslatef(-.3, -.2, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz-= .03;
	glPopMatrix();

	//TEST explosion
	if (exptime > 30)
	{
	glPushMatrix();
	glTranslatef(-.5, 0, 0);
	explosion(false);
	glPopMatrix();
	exptime --;
	}else if(exptime > 0 && exptime <= 30)
	{
		glPushMatrix();
		glTranslatef(-.5, 0, 0);
		explosion(true);
		exptime --;
		glPopMatrix();
	}

	// spawn ship 
	glPushMatrix();
	//handle ship movements
	if (_Right || Rlock)
	{Tx += .03;a1 -= .3; }
	if (_Left || Llock)
	{Tx -= .03;a1 += .3; }

	if (_Jump) //set jump
	{
		maxjump-=1;

		if (_Right && maxjump == 49) //set movement jump locks
		{Rlock=true;}else if (_Left && maxjump == 49) {Llock = true;}

		if (maxjump >= 25) // jump by how long
		{Ty += .02;_Right = false; _Left = false;} 
		else if (maxjump < 25)
		{Ty -= .02;_Right = false; _Left = false;}

		if (maxjump == 0) //reset jump
		{
			maxjump = 50;
			_Jump = false;
			Rlock = false; Llock = false;
		}
	} 
	glRotatef(a1, 0.0, 0.5, 0.0); glTranslatef(Tx, Ty, 0);
	ShipAngle;
	//end movements
	Ship(); 
	glPopMatrix();
	// end ship
}

//main display for Scenes
void display(void) 
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	 
	

	Scene2();

	glutSwapBuffers();
}

//this is MAIN cycle of all code functions called
void main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("(RocketShift) Test");
	init(); 
	//let GL know your func names
	glutTimerFunc(0, Timer, 0); 
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMainLoop();
}
