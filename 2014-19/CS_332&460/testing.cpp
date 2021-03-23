#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
using namespace std;

#define ShipAngle glRotatef(-55, -10.0, 0.0, 0.0);
static float maxjump = 50; //ammount of jump time
static float exptime = 60; //ammount of explosion time
bool _Right = false;
bool _Left = false;
bool Rlock = false;
bool Llock = false;
static bool _Jump = false;
float a1 = 0;
float Tx = 0.0;
float Ty = .00;
int option = 1;
int wid = 1025;
int hei = 1025;
float L = 400;
GLuint texName[2];
bool DeleteShip = false; //for deleting ship FLAG
static unsigned int texture[2]; // Array of texture indices.
static float d = 0.0; // Distance parameter in gluLookAt().
static int light_state = 1; // light on = 1, light off = 0
static int view_state = 1; // Ortho view = 1, Perspective = 0
struct tm *newtime;
time_t ltime;

						 //set lights details
GLfloat sun_ambient[] = { .0,.0,.0, 1.0 };
GLfloat sun_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat sun_specular[] = { 1.,1.,1., 1.0 };
GLfloat mat_emission[] = { 0.,0.,0., .0 };
GLfloat sun_position[] = { -2., 1., -.2, 0. };
GLfloat sun_globalambient[] = { 0.2,0.2,0.2,1 }; \
//void drawTexture();
//unsigned char* readBMPfile(int k);


/*unsigned char* readBMPfile(int k)
{
	FILE *fil = NULL;

	if (k == 0) fopen_s(&fil, "grass.bmp", "rb"); else	//good "cliffClouds1.bmp", or "mycar1.bmp", works well
	if (k == 1) fopen_s(&fil, "images.bmp", "rb"); else		//good
	if (k == 2) fopen_s(&fil, "sky.bmp", "rb"); else	//good	Jounieh
	//if (k == 3) 
	//fopen_s(&fil, "images.bmp", "rb");		//texture so so

	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, fil); // Read info: the 54-byte header;  info[18] and info[22]
	int width = wid = *(int*)&info[18];		// extract image_width  from header //no need to Polyview
	int height = hei = *(int*)&info[22];		// extract image_height from header
	int size = 3 * width * height;		//cout << "getImage.bmp:  " << width << 'x' << height << endl;
	unsigned char* data = new unsigned char[size]; // Allocate 3 bytes per pixel for all the image size=3*width*height (byte or unsigned char)
	fread(data, sizeof(unsigned char), size, fil); // Read the rest of the data at once (image data)
	fclose(fil);
	if (k<3)
		for (int i = 54; i < size; i += 3)  //swap Red-Blue
		{unsigned char tmp = data[i];	data[i] = data[i + 2];	data[i + 2] = tmp;
	if (i > size - 900) cout << int(data[i]) << ' ' << int(data[i + 1]) << ' ' << int(data[i + 2]) << endl;
		}
	glGenTextures(2, &texName[0]);
	glBindTexture(GL_TEXTURE_2D, texName[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); //tex0 array[][]
	return (data);
}*/

/*void drawTexture()
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
}*/

void Sprint(int x, int y, char *st)
{
	int l, i;

	l = strlen(st);
	glRasterPos3i(x, y, -1);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
	}

}

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




// Initialization routine.
void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
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

//CODE FOR COLLOSION
struct boxloc
{
	float x; float y; float z;
};
struct shiploc
{
	float x; float y; float z;
};


static boxloc box[25];
static shiploc ship;
int bcount = 0;
//call on anywhere xyz changes
void CCboxes(float boxx, float boxy, float boxz)
{
	box[bcount].x = boxx;
	box[bcount].y = boxy;
	box[bcount].z = boxz;
	bcount++; //go to next box info
}
//call on as a last line in the display to update CC locations
void CCupdate()
{
	//test CC xyz's
	for (int i = bcount - 1; i >= 0; i--)
	{
		if (box[i].x + 0.25 > ship.x && box[i].x - 0.25 < ship.x)
		{
			if (box[i].z + 0.25 > ship.z && box[i].z - 0.25 < ship.z)
			{
				if (box[i].y + 0.3 > ship.y && box[i].y - 0.3 < ship.y)
				{
					DeleteShip = true;
				}
			}

		}
	}
	bcount = 0;
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


//use this for keyup and keydown input parameters
void KeyDown(unsigned char Key, int x, int y)
{
	switch (Key)
	{
	case 'a': _Right = true; break;
	case 'd': _Left = true; break;
	case ' ': _Jump = true; break;
	case '1': option = 2; break;
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


void explosion(bool scatter)
{

	//make scatter effects
	if (scatter)
	{
		static float up, down, right, left;
		for (int t = 4; t >= 0; t--)
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
			glColor3f(1.8, .8, .0);
			glVertex2f(.1, .0);
			glVertex2f(.1, -.1);
			glVertex2f(.2, -.1);
			glEnd();

			glPopMatrix();
		}
		up += 0.01; down -= 0.01; left -= 0.01; right += 0.02;
	}
	else
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
		}
		else
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
	glColor3f(0, 0.7, 0.2);
	glutSolidCube(0.3f);
	glPopMatrix();
}
void writeBitmapString(void *font, char *string)
{
	char *c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}


void Scene1()
{
	

	glColor3f(1.0, 1.0, 1.0);

	glRasterPos3f(10.0, 90.0, 0.0);
	writeBitmapString(GLUT_BITMAP_8_BY_13, "GLUT_BITMAP_8_BY_13");

	// render text
	//writeBitmapString(GLUT_BITMAP_HELVETICA_18, "ROCKET_SHIFT");
	// go back to saved matrix in model view
	//glPopMatrix();

	// go back to saved matrix in projection (perspective)
	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();

	// change to model view
	//glMatrixMode(GL_MODELVIEW);
	//glDisable(GL_LIGHTING);
	//glRasterPos2f(0.0, 0.0);
	//glColor3f(1.0, 1.0, 1.0);
	//glPushMatrix();
	//glTranslatef(10.0, 10.0, 0.0);
	//glRotatef(45.0, 0.0, 0.0, 1.0);
	//glScalef(0.025, 0.025, 0.025);
	
	//glPopMatrix();
	
	
	
}



void Scene2()
{

	//Game starts. This scenery is stationary! Needs background image, boxes , CC
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//TEST boxes
	//glDisable(GL_LIGHTING);
	static float movz = 3.0;
	if (movz < -3.0) { movz = 3.0; }
	glPushMatrix();
	glTranslatef(-.3, -.2, movz);
	CCboxes(-.3, -.2, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .03;
	glPopMatrix();
	



	// spawn ship 
	if (DeleteShip == false)
	{
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
		glRotatef(a1, 0.0, 0.5, 0.0); glTranslatef(Tx, Ty, 0);
		ship.x = Tx; ship.y = Ty; ship.z = 0;
		ShipAngle; //turn ship to 3rd person angle
				   //end movements
		Ship();
		glPopMatrix();
	}
	else {
		//WHEN DELETESHIP = TRUE
		if (exptime > 30)
		{
			glPushMatrix();
			glTranslatef(Tx, Ty, 0);
			explosion(false);
			glPopMatrix();
			exptime--;
		}
		else if (exptime > 0 && exptime <= 30)
		{
			glPushMatrix();
			glTranslatef(Tx, Ty, 0);
			glRotatef(30, 2, 2, -2);
			explosion(true);
			glPopMatrix();
			exptime--;
		}
	}
	// end ship
}

//main display for Scenes
void display(void)
{
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	// easy way to put text on the screen.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8.0, 8.0, 8.0, -8.0, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Put view state on screen
	glColor3f(1.0, 1.0, 1.0);
	if (view_state == 0)
	{
		Sprint(-3, 4, "Perspective view");
	}
	else Sprint(-2, 4, "Ortho view");

	// Turn Perspective mode on/off
	if (view_state == 0)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(60.0, 1, 1.0, 30.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 0, -25, 0, 0, 0, 0, 1, 0);
	}

	if (light_state == 1)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);  // Enable for lighing
	}
	else
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);  // Disable for no lighing
	}

	//readBMPfile(3);
	//drawTexture();

	if (option == 1)
	{
		Scene1();
	}
	else 
		
		Scene2();




	CCupdate(); //for performance, this should be inside the else statement 'Note:for action scene2 only

	glutSwapBuffers();
	
}

//this is MAIN cycle of all code functions called
void main(int argc, char** argv)
{
	//drawTexture();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
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