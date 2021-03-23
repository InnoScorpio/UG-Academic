#include <iostream>
#include <Windows.h>
#include <sstream>
#include <fstream>
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
int Gametime, fpscount; //Gametime is every one-second
bool DeleteShip = false; //for deleting ship FLAG
bool musicswap = false;
bool menumusic = true;

//set lights details
GLfloat sun_ambient[] = { .0,.0,.0, 1.0 };
GLfloat sun_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat sun_specular[] = { 1.,1.,1., 1.0 };
GLfloat mat_emission[] = { 0.,0.,0., .0 };
GLfloat sun_position[] = { -2., 1., -.2, 0. };
GLfloat sun_globalambient[] = { 0.2,0.2,0.2,1 }; \
void drawTexture();
unsigned char* readBMPfile(int k);


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

	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW | GLUT_RGB);
	glLoadIdentity();
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


static boxloc box[70];
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

//CODE FOR make particle effects
struct PartiSet
{
	float x; float y; float z;
};

//call on particles locations randomely
float plocx, plocy;
int pcount = 0;
int	inc;
float partZ;
static PartiSet aparticle[30];
bool negate = true;

float randomloc()
{
	time_t t;
	time(&t);
	srand(t);
	float x = (rand() % 5 + 1);


	if (negate == true)
	{
		negate = false; return x;
	}
	else if (negate == false)
	{
		negate = true; return -x;
	}
}

void MakeStars()
{
	glBegin(GL_TRIANGLES);
	glVertex2f(.0, .05);
	glVertex2f(.05, .0);
	glVertex2f(-.05, .0);
	glEnd();
}

void MakeParticles()
{
	float t = randomloc();
	//get new particle coords


	aparticle[pcount].x = randomloc();
	aparticle[pcount].y = randomloc();
	aparticle[pcount].z = 6.0;
	//add new particle to array
	//next particle
	pcount++;
}

void particle()
{
	glColor3f(1, 1, 1);
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(.1, 10, 2);
	glPopMatrix();
}

//call on as a last line in the display to update CC locations and particle locations
void UpdateCC()
{
	//update and test CC xyz's
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
	bcount = 0; //recount all current locations

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

bool up = true;
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

	if (Key == 13 && up == false)
	{
		exit(1);
	}
	else if (Key == 13 && up == true)
	{
		option = 2; fpscount = 0; Gametime = 0;
		if (musicswap == false)
		{
			//PlaySound("gamemux2.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			musicswap = true;
		}
		else if (musicswap == true)
		{
			//PlaySound("gamemux.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			musicswap = false;
		}

	} //ADD RESETS HERE FOR NEW SCENE 2 INSTANCE

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

void SpecialKey(int Key, int x, int y)
{
	if (Key == GLUT_KEY_UP)
	{
		up = true;
	}
	else if (Key == GLUT_KEY_DOWN)
	{
		up = false;
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
	glTranslatef(-.1, -.19, .0);
	Thrust(); //draw right thrust
	glPopMatrix();

	glPushMatrix();
	glTranslatef(.1, -.19, .0);
	Thrust(); //draw left thrust
	glPopMatrix();


	//BODY
	glColor3f(1.3, 1.1, 1.1);
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


	float x = -0.05; float l = 0; float r = 0; //make 3d wings
	int t = 0;
	while (t <= 1)
	{
		//right wing
		glPushMatrix();
		glTranslatef(.0, .0, x); //must be undone after
		glRotatef(12.0, 0, r, 0);
		glBegin(GL_TRIANGLES);
		glColor3f(.0, .0, 1.0);
		glVertex2f(-.1, .0);
		glColor3f(.5, 1.0, 1.0);
		glVertex2f(-.1, -.1);
		glVertex2f(-.2, -.1);
		glEnd();
		glPopMatrix();

		//left wing
		glPushMatrix();
		glTranslatef(.0, .0, x); //must be undone after
		glRotatef(12.0, 0, l, 0);
		glBegin(GL_TRIANGLES);
		glColor3f(.0, .0, 1.0);
		glVertex2f(.1, .0);
		glColor3f(.5, 1.0, 0.5);
		glVertex2f(.1, -.1);
		glVertex2f(.2, -.1);
		glEnd();
		glPopMatrix();
		t++;
		l -= 1; r += 1;
		x -= 0.08; //next set of wings location
	}
}

//This object earth 
void EarthObj()
{
	//water
	glPushMatrix();
	glColor3f(0, 0.2, 2.5);
	glutSolidSphere(.4, 20, 50);
	glPopMatrix();

	//lands
	glPushMatrix();
	glTranslatef(.05, .08, -.06);
	glColor3f(.2, 3., 0);
	glutSolidSphere(.3, 20, 50);
	glPopMatrix();

	//lands 2
	glPushMatrix();
	glTranslatef(.0, -.03, -.115);
	glColor3f(.1, 3., 0);
	glutSolidSphere(.3, 20, 50);
	glPopMatrix();

	//lands 3
	glPushMatrix();
	glTranslatef(-.08, .07, -.03);
	glColor3f(.2, 2., 0);
	glutSolidSphere(.3, 20, 50);
	glPopMatrix();
}

void MoonObj()
{
	glPushMatrix();
	glColor3f(.6, .6, .6);
	glutSolidSphere(.1, 20, 50);
	glPopMatrix();
}

//This object mars is the goal of the game
void MarsObj()
{
	//red rock
	glPushMatrix();
	glColor3f(.6, 0.3, 0.1);
	glutSolidSphere(.3, 20, 50);
	glPopMatrix();

	//polar cap
	glPushMatrix();
	glTranslatef(0, -.12, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(.2, 20, 50);
	glPopMatrix();
}

void SunObj()
{
	glPushMatrix();
	glColor3f(4, 1.6, .1);
	glutSolidSphere(1.2, 21, 50);
	glPopMatrix();
}

static float up_s, down_s, right_s, left_s;
static float i_s = 0;
void explosion(bool scatter)
{

	//make scatter effects
	if (scatter)
	{

		for (int t = 4; t >= 0; t--)
		{
			glPushMatrix();
			switch (t)
			{
			case 4: glTranslatef(right_s, down_s, 0); break;
			case 3: glTranslatef(left_s, down_s, 0); break;
			case 2: glTranslatef(left_s, up_s, 0); break;
			case 1: glTranslatef(0, up_s, 0); break;
			case 0: glTranslatef(up_s, right_s, 0); break;
			}
			glBegin(GL_TRIANGLES);
			glColor3f(1.8, .8, .0);
			glVertex2f(.1, .0);
			glVertex2f(.1, -.1);
			glVertex2f(.2, -.1);
			glEnd();

			glPopMatrix();
		}
		up_s += 0.01; down_s -= 0.01; left_s -= 0.01; right_s += 0.02;
	}
	else
	{
		//make spherical explosions

		if (i_s == 3)
		{
			glPushMatrix();
			glColor3f(1.0, .6, .0);
			glutSolidSphere(.15, 10, 50);
			glPopMatrix();
			i_s = 0;
		}
		else
			glPushMatrix();
		glColor3f(1, .0, .0);
		glutSolidSphere(.11, 10, 50);
		glPopMatrix();
		i_s++;
	}
}

void boxes()
{
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.7);
	glutSolidCube(0.3f);
	glPopMatrix();
}


void blocks()
{
	static float movz = 10.0;
	int i = 2;
	while (i > 0) {
		if (movz < -3.0) { movz = 19.0; }
		glPushMatrix();
		glTranslatef(-i, -.1, movz);
		CCboxes(-i, -.1, movz);
		glRotatef(10, -.2, 0, .0);
		boxes();
		movz -= .03;
		glPopMatrix();
		i--;
	}
	if (movz < -3.0) { movz = 19.0; }
	glPushMatrix();
	glTranslatef(-i, .7, movz);
	CCboxes(-i, -.7, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .03;
	glPopMatrix();
	i--;
}

void scene_X()
{
	static float movz = 10.0;
	if (movz < -3.0) { movz = 17.0; }
	glPushMatrix();
	glTranslatef(.1, -.1, movz);
	CCboxes(.1, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .03;
	glPopMatrix();

	if (movz < -3.0) { movz = 17.0; }
	glPushMatrix();
	glTranslatef(1.5, -.1, movz);
	CCboxes(1.5, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .03;
	glPopMatrix();

	if (movz < -3.0) { movz = 17.0; }
	glPushMatrix();
	glTranslatef(1.5, .7, movz);
	CCboxes(1.5, .7, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .03;
	glPopMatrix();

}

void next_brick()
{
	static float movz = 10.0;
	if (movz < -3.0) { movz = 15.0; }
	glPushMatrix();
	glTranslatef(-.5, -.1, movz);
	CCboxes(-.5, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .04;
	glPopMatrix();

	if (movz < -3.0) { movz = 15.0; }
	glPushMatrix();
	glTranslatef(.5, -.1, movz);
	CCboxes(.5, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .04;
	glPopMatrix();

	if (movz < -3.0) { movz = 14.0; }
	glPushMatrix();
	glTranslatef(-.5, .7, movz);
	CCboxes(-.5, .7, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .04;
	glPopMatrix();
}

void more_blocks()
{
	static float movz = 10.0;
	if (movz < -3.0) { movz = 15.0; }
	glPushMatrix();
	glTranslatef(-.5, .6, movz);
	CCboxes(-.5, .6, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .06;
	glPopMatrix();

	if (movz < -3.0) { movz = 15.0; }
	glPushMatrix();
	glTranslatef(.5, .6, movz);
	CCboxes(.5, .6, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .06;
	glPopMatrix();

	if (movz < -3.0) { movz = 15.0; }
	glPushMatrix();
	glTranslatef(-1.5, -.1, movz);
	CCboxes(-1.5, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .06;
	glPopMatrix();
}



void moving_blocks()
{
	next_brick();
	more_blocks();
}


void output(char* text)
{
	glRotatef(180, .0, 1.0, 0); //fix to original rotation
	glScalef(.2 / 152.38, .2 / 152.38, .2 / 152.38); // make text small for visibility 
	for (char* p = text; *p; p++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	}
}

int scr = 0;
int best = 0;
char Score[20] = { 0 };
char BScore[20] = { 0 };

void ScoreOutput(int scenenum)
{

	glPushMatrix();
	glTranslatef(-.7, -.9, 0);
	glScalef(.5, .5, .5);
	output("Closest Distance to Mars: ");
	glPopMatrix();

	if (scenenum == 1)
	{
		std::sprintf(BScore, "%d", best); //show best score
		glPushMatrix();
		glTranslatef(-1.9, -.9, 0);
		glScalef(.5, .5, .5);
		output(BScore);
		glPopMatrix();
	}
	else if (scenenum == 2) //show best and current score
	{
		float n = 0;
		while (n <= 0.41)
		{
			glPushMatrix();
			glTranslatef(-1.9, -.9 + n, 0);
			glScalef(.5, .5, .5);

			if (n == 0)
			{
				std::sprintf(BScore, "%d", best);
				output(BScore);
			}
			else
			{
				std::sprintf(Score, "%d", scr);
				output(Score);
			}
			glPopMatrix();
			n += 0.41;
		}
	}

}
static float chgclr;
float Erotate, Edistance, Emov;


float x1, x2;
void Scene1()
{

	//play menu music
	if (menumusic == true)
	{
		//PlaySound("gamemux.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		menumusic = false;
	}


	//MAIN MENU: text for main menu 
	glPushMatrix();
	glColor3f(0, 3, 0);
	glTranslatef(1.2, 1, 0);
	output("RocketShift 2: Mission For Mars");
	glPopMatrix();

	glPushMatrix();
	glColor3f(2, 1, 2);
	glTranslatef(x1 + .8, 0, 0);
	output("Start Game");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x2 + .9, -.3, 0);
	glScalef(.5, .5, .5);
	output("Exit Game");
	glPopMatrix();

	//select options
	glPushMatrix();
	if (up == true)
	{
		glTranslatef(x1 - .4, 0.02, 0);
	}
	else {
		glTranslatef(x2 + .2, -.3, 0);
	}
	glRotatef(fpscount, 10, 0, 0);
	glutSolidSphere(.1, 3, 2);
	glPopMatrix();

	ScoreOutput(1);

	//control the animations
	if (Gametime < 1 && fpscount <= 30)
	{
		x1 += 0.003; x2 += 0.002;
	}

	//count up to 60 frames for 1 Gametime seccond
	if (fpscount == 60)
	{
		Gametime += 1;
		fpscount = 0;
	}
	fpscount++;
}


void ResetAll()
{ //reset then set to menu
	scr = 0;
	menumusic = true;
	maxjump = 50; //ammount of jump time
	exptime = 60; //ammount of explosion time
	up_s = 0;
	down_s = 0;
	right_s = 0;
	left_s = 0;
	i_s = 0;
	up = true;
	x1 = 0;
	x2 = 0;
	Erotate = 0;
	Edistance = 0;
	Emov = 0;
	_Right = false;
	_Left = false;
	Rlock = false;
	Llock = false;
	_Jump = false;
	a1 = 0;
	Tx = 0;
	Ty = 0;
	option = 1;
	chgclr = 0;
	Gametime = 0;
	DeleteShip = false;
}

void Scene2()
{
	//Game starts. This scenery is stationary! Needs background image, boxes , CC
	glPushMatrix();
	glTranslatef(1, 2, 3 - Edistance);
	SunObj();
	glPopMatrix();

	//Make earth and moon
	glPushMatrix();
	glScalef(4, 4, 4);
	glTranslatef(-2 + Emov, 1, 16 - Edistance);
	glRotatef(Erotate, 0, 20, 0);
	EarthObj();
	glPushMatrix();
	glTranslatef(-.8, 0, 0);
	MoonObj();
	glPopMatrix();
	glPopMatrix();
	//Make mars
	glPushMatrix();
	glScalef(2, 2, 2);
	glTranslatef(6 - (Emov - 1), 1, 30 - Edistance);
	glRotatef(Erotate, 0, 20, 0);
	MarsObj();
	glPopMatrix();

	Edistance += 0.003; //distance of earth to reach
	Erotate += 0.2;
	Emov += .0008;
	//Make stars system
	float sx[30] = { 90,21,4,7,41,9,5,61,1,13,8,52,9,6,4,81,3,8,41,8,-21,-56,-11,-81,-32,-27,-67,-33,-57,-98 };
	float sy[30] = { 90,2,5,51,-2,8,21,5,31,-7,9,71,5,8,-9,6,4,31,2,6,32,47,-78,42,67,-57,-78,-23,34,23 };
	for (int x = 0; x < 30; x++)
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(sx[x], sy[x], 30);
		MakeStars();
		glPopMatrix();
	}

	//replace this with the code in scene2()
	static float movz = 3.0;
	int i = 2;
	while (i > 0)
	{
		if (movz < -3.0) { movz = 14.0; }
		glPushMatrix();
		glTranslatef(i, -.1, movz);
		CCboxes(i, -.1, movz);
		glRotatef(10, -.2, 0, .0);
		boxes();
		movz -= .01;
		glPopMatrix();
		i--;
	}
	if (movz < -3.0) { movz = 14.0; }
	glPushMatrix();
	glTranslatef(-2.0, -.1, movz);
	CCboxes(-2.0, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .01;
	glPopMatrix();


	if (movz < -3.0) { movz = 17.0; }
	glPushMatrix();
	glTranslatef(-2.0, .8, movz);
	CCboxes(-2.0, .8, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .02;
	glPopMatrix();

	if (movz < -3.0) { movz = 17.0; }
	glPushMatrix();
	glTranslatef(1.5, .8, movz);
	CCboxes(1.5, .8, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .02;
	glPopMatrix();

	if (movz < -3.0) { movz = 14.0; }
	glPushMatrix();
	glTranslatef(-.5, -.1, movz);
	CCboxes(-.5, -.1, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .01;
	glPopMatrix();

	if (movz < -3.0) { movz = 14.0; }
	glPushMatrix();
	glTranslatef(-.8, .7, movz);
	CCboxes(-.8, .7, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .01;
	glPopMatrix();

	if (movz < -3.0) { movz = 14.0; }
	glPushMatrix();
	glTranslatef(.1, .5, movz);
	CCboxes(.1, .5, movz);
	glRotatef(10, -.2, 0, .0);
	boxes();
	movz -= .01;
	glPopMatrix();

	if (Gametime >= 5)
	{
		scene_X();
	}
	if (Gametime >= 10)
	{
		blocks();
	}
	if (Gametime >= 15)
	{
		moving_blocks();
	}


	//make particles every 16 frames equivalent of .256 seconds
	if (pcount == 30)
	{
		pcount = 0;
	}
	if (inc == 8)
	{
		MakeParticles();
		inc = 0;
	}

	//update particles location
	if (aparticle[0].z != NULL)
	{
		for (int i = pcount - 1; i >= 0; i--)
		{
			if (aparticle[i].z > -3)
			{
				glPushMatrix();
				glTranslatef(aparticle[i].x, aparticle[i].y, aparticle[i].z);
				particle();
				aparticle[i].z -= 0.1;
				glPopMatrix();
			}
		}
	}

	//pcount = 0;
	inc += 1;


	// spawn ship 
	if (DeleteShip == false)
	{
		//glClearColor(0.03, 0, 0.02, 0);

		//Scoreboard
		ScoreOutput(2);
		scr++; //update points per frame

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
		//glRotatef(a1, 0.0, 0.5, 0.0); 
		glTranslatef(Tx, Ty, 0);
		if (Tx > 2.5 || Tx < -2.5)
		{
			DeleteShip = true;
		}
		ship.x = Tx; ship.y = Ty; ship.z = 0;
		ShipAngle; //turn ship to 3rd person angle
				   //end movements
		Ship();
		glPopMatrix();
	}
	else {
		//WHEN DELETESHIP = TRUE
		if (exptime > 30) //EXPLODE
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
		//NEEDS RESETS TO DEFAULT VALUES::: set highest best score and reset score
		if (scr > best)
		{
			best = scr;
		}
		ScoreOutput(1);
		// wait and go to menu screen
		static int wait;
		wait++;
		chgclr += 0.005;

		if (wait >= 250)
		{
			ResetAll();
			wait = 0;
		}
	}
	// end ship

	//count up to 60 frames for 1 Gametime seccond
	if (fpscount == 60)
	{
		Gametime += 1;
		fpscount = 0;
	}
	fpscount++;
}


//main display for Scenes
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glClearColor(chgclr, chgclr, chgclr, 0);


	if (option == 1)
	{
		Scene1();
	}
	else {
		Scene2();
		UpdateCC(); //for performance, this should be inside the else statement 'Note:for action scene2 only
	}


	glutSwapBuffers();
}

//this is MAIN cycle of all code functions called
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1700, 900);
	glutCreateWindow("(RocketShift) Test");
	init();
	//let GL know your func names
	glutTimerFunc(0, Timer, 0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutSpecialFunc(SpecialKey);
	glutMainLoop();
}
