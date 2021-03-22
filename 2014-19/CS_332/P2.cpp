#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h> //sound "winmm.lib"
#include <iostream>
using namespace std;
#pragma comment(lib, "winmm.lib")  // PlaySound(TEXT("Gun+Luger.wav"), NULL, SND_SYNC);
#include <GL/glut.h>
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
extern int X = 0, Y = 1, Z = 0, wire = 0, rot = 0, player1 = 1;
extern GLfloat x = 0., y = 0., z = 0., spin = 0., scl = 4.;
extern GLfloat x11 = -10., y11 = -2., z11 = 0., ang11 = 10., x22 = 10., y22 = -2., z22 = 0., ang22 = 170.; //11 left gun, 22 right gun (location ,and aiming angles)

GLfloat mat_diffuse[] = { 1.,1.,1., 1.0 }; //white color. First component of color. 
GLfloat mat_diffuse0[] = { 1.,.9,.0, 1.0 }; //yellow. 1.0 is local and lower is direction.
GLfloat mat_diffuse1[] = { 1.,.0,.0, 1.0 }; //red
GLfloat mat_diffuse2[] = { 0.,1.,.0, 1.0 }; //green
GLfloat mat_diffuse3[] = { 0.,0.,1., 1.0 }; //blue
GLfloat mat_diffuse4[] = { 0.,1.,1., 1.0 }; //sky
GLfloat mat_diffuse5[] = { 1.,0.,1., 1.0 }; //violet
GLfloat mat_diffuse6[] = { 1.,.5,0., 1.0 }; //brown
GLfloat mat_diffuse7[] = { 0.,0.2,0., 1.0 }; //black

GLfloat mat_ambient[] = { .9,.9,.9, 1.0 }; //Second component of color
GLfloat mat_specular[] = { 1.,1.,1., 1.0 }; //Third component of color
GLfloat mat_shininess[] = { 128. };	//this needs specular (work together)
GLfloat light0_position[] = { 1., 1., 30., .0 };

GLfloat light1_position[] = { -1., 19., 29., .0 };
GLfloat light2_position[] = { 1., 19., 29., .0 };
GLfloat light3_position[] = { 0., 19., 29., .0 };
GLfloat light4_position[] = { -1., 29., 29., .0 };
GLfloat light5_position[] = { 0., 10., 19., .0 };
GLfloat light6_position[] = { 0., 10.,  9., .0 };
//////////////////////////////////////////
void drawJosePrimitives(void)
{

	glColor3f(0.1, 0.5, 1.0);              // Blue ball displaced to right.
	glPushMatrix();
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef(60.0, 1, 0, 0);
	glRotatef(zRotated, 0, 0, 1);
	glutWireCube(0.5);
	glPopMatrix();

	glColor3f(0.1, 0.5, 1.0);
	glPushMatrix();
	glTranslatef(1.5, 0.0, 0.0);
	glRotatef(60.0, 1, 0, 0);
	glRotatef(zRotated, 0, 0, 1);
	glutSolidSphere(0.5, 20, 50);
	glPopMatrix();

	glColor3f(0.1, 0.5, 1.0);              // Blue ball displaced to right.
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0.0, 1, 0, 0);
	glRotatef(zRotated, 0, 0, 1);
	glutSolidTorus(0.15, 0.20, 50, 20);
	glPopMatrix();

	glColor3f(1.0, 0.5, 0.1);              // Red ball displaced to left.
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(60.0, 1, 0, 0);
	glRotatef(zRotated*2.0, 0, 0, 1);// Red ball rotates at twice the rate of blue ball.
	glutWireSphere(0.5, 20, 50);
	glPopMatrix();

	glColor3f(1.0, 0.5, 0.1);              // Blue ball displaced to left
	glPushMatrix();
	glTranslatef(-1.5, 0.0, 0.0);
	glRotatef(-45.0, 1, 0, 0);
	glRotatef(zRotated, 0, 0, 1);
	glutSolidCone(0.5, 0.80, 20, 50);
	glPopMatrix();


	glColor3f(1.0, 0.5, 0.1);
	glPushMatrix();
	glTranslatef(-3.0, 0.0, 0.0);
	glRotatef(60.0, 1, 0, 0);
	glRotatef(zRotated, 0, 0, 1);
	glutSolidCube(0.5);
	glPopMatrix();


}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidCube(1.);        ///////		Original code from Dr. Tannouri 
	///glutSolidCube(2.);       //// student();
    ///glutSolidSphere(1.0, 75, 25);
	///glTranslatef(3, 0.0, 0.0);
	///glutSwapBuffers();

	///glColor3f(0.1, 0.5, 1.0);              // Test code Blue ball displaced to right.
	///glPushMatrix();
	///glTranslatef(1.5, 2.5, 0.0);
	///glRotatef(90.0, 1, 0, 0);
	///glRotatef(zRotated, 0, 0, 0);
	///glutSolidCone(1.0, 1.2, 40, 35);
	////glPopMatrix();

	drawJosePrimitives();
	glutSwapBuffers();

}

void spinDisplay() { spin += .02; if (spin>50.) { spin = 0.; cout << (char)7; /*rnd+=rand()%5-2.5;*/ } glutPostRedisplay(); } //rnd+=(rand()%5) -2.)

void menu() { cout << "\nUse 'x' 'y' 'z' 'a' 'b' 'c' 'w' ' '  keys for animation\n" << endl; }

void init(void)
{ //initParticles();
  //PlaySound(L"LASER.wav", NULL, SND_FILENAME); //or SND_LOOP
  //PlaySound(NULL, NULL, NULL); //stops all running sounds 

	glClearColor(1., 1., 1.,   1.);

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

void keyboard(unsigned char key, int xx, int yy)
{
	float t = .1;
	switch (key)
	{
	case '?':	menu(); break;
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
		//cx	case ' '	:	spin=x=y=z=.0; rnd=5.; x11=-10.; x22=10.; y11=y22=-2.; break;
	case 'n':	PlaySound(TEXT("Gun+Luger.wav"), NULL, SND_SYNC); break; //noise sound
	case 'm':	PlaySound(NULL, NULL, NULL); break; //noise sound

													//Spring-2018  I can share this keyboard() with SAM.h samKeyboard()   (I created a callback function in SAM.h file:)
													//	case '.'	:	samKeyboard('.',xx,yy);	 break;	//glutKeyboardFunc(samKeyboard); //perfectly works in SAM.h
													//	case ','	:	samKeyboard(',',xx,yy);	 break;	//glutKeyboardFunc(samKeyboard); //perfectly works in SAM.h
	}
	glutPostRedisplay();
}

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

void mouse(int button, int state, int xx, int yy)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:  if (state == GLUT_DOWN) { X = 0; Y = 1; Z = 0; glutIdleFunc(spinDisplay); } break;
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
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutMainLoop();
}