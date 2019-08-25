#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
#include<windows.h>
#include<mmsystem.h>
#define CTRL_COUNT 100

int scene;

///1st scene
float movebaloon=0;
float bln=0;

///2nd scene
float movecloud=1;
float cld=0;
float moveman=0;
float man=0;

///3rd scene
float movemancl=0.0;
float mancl=0.0;

///4th scene
float movecloudu=1;
float cloudu=0;
float movemanu=0;
float manu=0;
float movecaru=1;
float caru=0;


char text[] = "ABC";
char t[] = "COLLEGE";
char text_1[] = "SCHOOL";
char t_1[] = "TUTION";
char text_2[] = "AIUB";
char text_3[] = "This is a small try to show the life of an Engineer";
char next[] = "Press 'n' to go to the next screen";
char previous[] = "Press 'b' to go to the previous screen";
char quit[] = "Press 'q' to quit the project";
char family[] = "Family Scenery";
char baloon[] = "Press 'u' to move the baloons";
char study[] = "Study Scenery";
char cloudT_S[] = "Press 'c' to stop the cloud";
char cloudT_M[] = "Press 'C' to move the cloud";
char manT_M[] = "Press 'm' to move the man";
char manT_S[] = "Press 'M' to stop the man";
char college[] = "College Scenery";
char manH_M[] = "Press 'k' to move the man";
char manH_S[] = "Press 'K' to stop the man";
char unuversity[] = "University Scenery";
char gari_S[] = "Press 'g' to stop the car";
char gari_M[] = "Press 'G' to move the car";
char cloudU_S[] = "Press 'Z' to stop the cloud";
char cloudU_M[] = "Press 'z' to move the cloud";
char manU_M[] = "Press 'p' to move the man";
char manU_S[] = "Press 'P' to stop the man";

char moral[] = "MORAL OF THE STORY";
char line_1[] = "Is this the life that we engineers want to lead?";
char line_2[] = "We know that, Education is the important part of our life.";
char line_3[] = "But there is no reason to spent all our time for studying.";
char line_4[] = "Entertainment and other co-curricular activities should be included in our study life as well.";
char line_5[] = "Unless we will just be a ' money earning ' ROBOT.";
char line_6[] = "NOT HUMAN!";
char line_7[] = "One day our life will flash before our eyes. Make sure it's worth watching.";

char tandry_1[] = "Once upon a time,";
char tandry_2[] = "In my childhood,";
char tandry_3[] = "I was living happily with my family.";

char tandry_4[] = "Then suddenly one day, I began my study life.";
char tandry_5[] = "Where the struggle begins and the happiness starts to fade out.";

char hrid_1[] = "They said, the struggle will disappear when I will be in College.";
char hrid_2[] = "But when I started my College, I realize that,";
char hrid_3[] = "It is just the beginning of the struggle.";

char ussash_1[] = "When I reached my University life,";
char ussash_2[] = "First couple of semester was really enjoyable as I met some new friends.";
char ussash_3[] = "But as time flew, the life was becoming harder.";
char ussash_4[] = "Because, responsibilities came along with the struggle.";

char waq_1[] = "Then I step into the most boring stage of my life.";
char waq_2[] = "THE JOB LIFE!";
char waq_3[] = "9 to 5 working 6 days in a week.";
char waq_4[] = "BOOOOOOOOOOORING!!!!!";

//Print
void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.

    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }


}


///////////////////circle////////////////////////////////

void DrawCircle(float a, float b, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int p = 0; p < num_segments; p++)
	{
		float theta = 2.0f * 3.1415926f * float(p) / float(num_segments);//calculate angle

		float x = r * cosf(theta);//x
		float y = r * sinf(theta);//y

		glVertex2f(x + a, y + b);//output

	}
	glEnd();
}
//for_the_upper_curve_line
int ctrlPointsCount;
int ctrlPointsX[CTRL_COUNT], ctrlPointsY[CTRL_COUNT];
int X1[3]={-6,-3,6}, Y1[3]={5,0,3};
int X2[3]={0,1,0.3}, Y2[3]={1,0,-1};
int X3[3]={-1,1,0}, Y3[3]={1,0,-1};
float getNextBezierPointX(float t)
{
	float x=0.0;
	for(int i=0; i<ctrlPointsCount; i++)
	{
		int c;
		if(i==0 || i==ctrlPointsCount-1)
			c = 1;
		else
		{
			c = ctrlPointsCount-1;
		}
		x +=  c * pow(t, i) * pow(1-t, (ctrlPointsCount-1)-i) * ctrlPointsX[i];
	}
	return x;
}
float getNextBezierPointY(float t)
{
	float y=0.0;

	for(int i=0; i<ctrlPointsCount; i++)
	{
		int c;
		if(i==0 || i==ctrlPointsCount-1)
			c = 1;
		else
		{
			c = ctrlPointsCount-1;
		}
		y +=  c * pow(t, i) * pow(1-t, ctrlPointsCount-1-i) * ctrlPointsY[i];
	}
	return y;
}
void drawline()
{
	float oldX=ctrlPointsX[0], oldY=ctrlPointsY[0];
	for(double t = 0.0;t <= 1.0; t += 0.01) {
		float x = getNextBezierPointX(t);
		float y = getNextBezierPointY(t);
		//glColor3f(1.0,t,1.0);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_LINES);
		glVertex2f(oldX, oldY);
		glVertex2f(x, y);
		glEnd();
		glFlush();
		oldX = x;
		oldY = y;
    }
}
///for_the_upper_curve_end






//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

///  1ST SCENE FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void people ()
{

    ///hashimukh
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0.15, .7, 0.0);
	glScalef(.5,0.16,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

	///lefteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0.07, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///nose
	glPushMatrix();
	glColor3ub(150,114,100);
	glTranslatef(0.06, .76, 0.0);
	glScalef(.15,.15,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.5,-2.4,0);
	glVertex3f (-.1,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();



	///lefteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();



	///head
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(-0.05, .6, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///hair
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .61, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.5,-0.5,0);
    glVertex3f (0,0,0);
    glVertex3f (.5,0,0);
    glVertex3f (1,-0.5,0);
    glVertex3f (1,-0.1,0);
    glVertex3f (0.5,0.3,0);
    glVertex3f (0,.3,0);
    glVertex3f (-0.5,-.1,0);
    glVertex3f (-0.5,-0.5,0);
    glEnd();
	glPopMatrix();

	///boyleftleg
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, -.1, 0.0);
	glScalef(.4,.3,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();

	///boyrightleg
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(.23, -.1, 0.0);
	glScalef(.4,.3,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();

		///boyleftshoe
	glPushMatrix();
	glColor3f(.9,0,0.1);
	glTranslatef(0.012, -.38, 0.0);
	glScalef(.4,.3,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

		///boyrightshoe
	glPushMatrix();
	glColor3f(.9,0,0.1);
	glTranslatef(0.25, -.38, 0.0);
	glScalef(.4,.3,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

	///boylefthand
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (-1,0.1,0);
	glVertex3f (-1,0.5,0);
	glVertex3f (-1.5,1,0);
  //  glVertex3f (-1.7,1.2,0);
   // glVertex3f (-1.9,1,0);


    glVertex3f (-1.5,0.8,0);
	glVertex3f (-1,0.1,0);
    glEnd();
	glPopMatrix();

		///boyrighthand
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (1,0.1,0);
	glVertex3f (1,0.5,0);
	glVertex3f (1.5,1,0);
    glVertex3f (1.5,0.8,0);
	glVertex3f (1,0.1,0);
    glEnd();
	glPopMatrix();

       ///neck
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.25,0.7,0);
    glVertex3f (-0.25,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();




	///boybody
	glPushMatrix();
	glColor3f(1,0.1,0);
	//glTranslatef(-1, 1.9, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (-0.3,0.5,0);
	glVertex3f (-1,0.5,0);
    glVertex3f (-1,0,0);
    glVertex3f (-.7,0,0);
    glVertex3f (-.6,-1,0);
    glVertex3f (.6,-1.0,0);
    glVertex3f (.7,0,0);
    glVertex3f (1,0,0);
    glVertex3f (1,0,0);
    glVertex3f (1,0.5,0);
    glVertex3f (.3,.5,0);
    glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

	///boypant
	glPushMatrix();
	glColor3f(0,.4,1);
	//glTranslatef(-1, 1.9, 0.0);
	glScalef(.5,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.45,-1,0);
	glVertex3f (-0.4,-2,0);
	glVertex3f (-.1,-2,0);
    glVertex3f (0.2,-1,0);
    glVertex3f (.1,-2,0);
    glVertex3f (0.4,-2,0);
    glVertex3f (0.45,-1,0);
	glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

}

void dad()
{
     ///beard
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0, 0.22, 0.0);
	glScalef(.54,.16,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.28,0.7,0);
    glVertex3f (-0.28,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    ///dadtotalfacestart
    glPushMatrix();
     ///hashimukh
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0.11, 0.4, 0.0);
	glScalef(.3,0.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

	///lefteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0.07, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///nose
	glPushMatrix();
	glColor3ub(150,114,100);
	glTranslatef(0.06, .76, 0.0);
	glScalef(.15,.15,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.5,-2.4,0);
	glVertex3f (-.1,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();



	///lefteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///head
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(-0.05, .6, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///hair
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .61, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.5,-0.5,0);
    glVertex3f (0,0,0);
    glVertex3f (.5,0,0);
    glVertex3f (1,-0.5,0);
    glVertex3f (1,-0.1,0);
    glVertex3f (0.5,0.3,0);
    glVertex3f (0,.3,0);
    glVertex3f (-0.5,-.1,0);
    glVertex3f (-0.5,-0.5,0);
    glEnd();
	glPopMatrix();
    ///neck
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.25,0.7,0);
    glVertex3f (-0.25,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    glPopMatrix();

    ///dadshirt
	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(.33,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (-0.3,0.7,0);
	glVertex3f (-1.02,0.5,0);
    glVertex3f (-1.02,-0.3,0);
    glVertex3f (-.7,-0.3,0);
    glVertex3f (-.6,-1,0);
    glVertex3f (.6,-1.0,0);
    glVertex3f (.7,-0.3,0);
    glVertex3f (1.02,-0.3,0);
    glVertex3f (1.02,0.5,0);
    glVertex3f (.3,.7,0);
    glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

	///dadleftleg
	glPushMatrix();
	glColor3f(0.4,.4,.4);
	glTranslatef(0, .3, 0.0);
	glScalef(.4,.7,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.45,-1,0);
	glVertex3f (-0.4,-2,0);
	glVertex3f (-.1,-2,0);
    glVertex3f (0.01,-1,0);
    glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

	///dadlefthand
	glPushMatrix();
	glColor3ub(195,149,130);
	glTranslatef(-0.25, .25, 0.0);
	glScalef(.2,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.45,-1,0);
	glVertex3f (-0.4,-2,0);
	glVertex3f (-.1,-2,0);
    glVertex3f (0.01,-1,0);
    glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

	///dadrighthand
	glPushMatrix();
	glColor3ub(195,149,130);
	glTranslatef(0.25, .25, 0.0);
	glScalef(.2,.35,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.01,-1,0);
    glVertex3f (.1,-2,0);
    glVertex3f (0.4,-2,0);
    glVertex3f (0.45,-1,0);
    glVertex3f (-0.01,-1,0);
	//glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

	///dadrightleg
	glPushMatrix();
	glColor3f(0.4,.4,.4);
	glTranslatef(0, .3, 0.0);
	glScalef(.4,.7,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.01,-1,0);
    glVertex3f (.1,-2,0);
    glVertex3f (0.4,-2,0);
    glVertex3f (0.45,-1,0);
    glVertex3f (-0.01,-1,0);
	//glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

		///dadleftshoe
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(0.02, -.4, 0.0);
	glScalef(.4,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

		///dadrightshoe
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(0.23, -.4, 0.0);
	glScalef(.4,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

}

void mom ()
{
    	///dadtotalfacestart
    glPushMatrix();
     ///hashimukh
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0.1, 0.5, 0.0);
	glScalef(.3,0.07,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

	///lefteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0.07, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///nose
	glPushMatrix();
	glColor3ub(150,114,100);
	glTranslatef(0.06, .76, 0.0);
	glScalef(.15,.15,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.5,-2.4,0);
	glVertex3f (-.1,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();



	///lefteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///head
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(-0.05, .6, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///hair
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .57, 0.0);
	glScalef(.2,.62,1);
	glBegin(GL_POLYGON);
    glVertex3f (-1,-0.5,0);
    glVertex3f (0,0,0);
    glVertex3f (.5,0,0);
    glVertex3f (1.5,-0.5,0);
    glVertex3f (1.5,-0.1,0);
    glVertex3f (0.5,0.3,0);
    glVertex3f (0,.3,0);
    glVertex3f (-1,-.1,0);
    glVertex3f (-1,-0.5,0);
    glEnd();
	glPopMatrix();
    ///neck
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.25,0.7,0);
    glVertex3f (-0.25,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    glPopMatrix();

    ///dadshirt
	glPushMatrix();
	glColor3ub(255,126,0);
	glScalef(.33,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (-0.3,0.7,0);
	glVertex3f (-1.02,0.5,0);
    glVertex3f (-1.02,-0.3,0);
    glVertex3f (-.7,-0.3,0);
    glVertex3f (-.6,-1,0);
    glVertex3f (.6,-1.0,0);
    glVertex3f (.7,-0.3,0);
    glVertex3f (1.02,-0.3,0);
    glVertex3f (1.02,0.5,0);
    glVertex3f (.3,.7,0);
    glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

	///momskirt
	glPushMatrix();
	glColor3ub(26,0,51);
	glTranslatef(0, .3, 0.0);
	glScalef(.4,.7,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.45,-1,0);
	glVertex3f (-0.85,-1.7,0);
	glVertex3f (.85,-1.7,0);
    glVertex3f (0.45,-1,0);
    glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

	///dadlefthand
	glPushMatrix();
	glColor3ub(195,149,130);
	glTranslatef(-0.25, .25, 0.0);
	glScalef(.2,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.45,-1,0);
	glVertex3f (-0.4,-2,0);
	glVertex3f (-.1,-2,0);
    glVertex3f (0.01,-1,0);
    glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();

	///dadrighthand
	glPushMatrix();
	glColor3ub(195,149,130);
	glTranslatef(0.25, .25, 0.0);
	glScalef(.2,.35,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.01,-1,0);
    glVertex3f (.1,-2,0);
    glVertex3f (0.4,-2,0);
    glVertex3f (0.45,-1,0);
    glVertex3f (-0.01,-1,0);
	//glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();


	///momleftleg
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, -.2, 0.0);
	glScalef(.4,.3,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();

	///momrightleg
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(.23, -.2, 0.0);
	glScalef(.4,.3,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();


		///dadleftshoe
	glPushMatrix();
	glColor3ub(0,66,37);
	glTranslatef(0.02, -.4, 0.0);
	glScalef(.4,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

		///dadrightshoe
	glPushMatrix();
	glColor3ub(0,66,37);
	glTranslatef(0.23, -.4, 0.0);
	glScalef(.4,.35,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();
}

void dog ()

{

    ///dognose
	 glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(.14, -1.44, 0.0);
	 glScalef(.14,.14,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

	///dognosebig
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(.04, -1.5, 0.0);
	 glScalef(.25,.18,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

      ///dogeyeleftpup
	 glPushMatrix();
	 glColor3f(.9,.9,.9);
	glTranslatef(.6, -.8, 0.0);
	 glScalef(.01,.01,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();
     ///dogeyerightpup
	 glPushMatrix();
	 glColor3f(.9,.9,.9);
	glTranslatef(-.1,-.8, 0.0);
	 glScalef(.01,.01,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();
    ///dogeyeleft
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(.5, -.9, 0.0);
	 glScalef(.09,.09,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();
     ///dogeyeright
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(-.2, -.9, 0.0);
	 glScalef(.09,.09,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();


    ///dogeyespot
	 glPushMatrix();
	 glColor3f(.9,.9,.9);
	glTranslatef(.5, -1, 0.0);
	 glScalef(.11,.18,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

	///doghead
	glPushMatrix();
	glColor3ub(139,69,19);
	//glTranslatef(-0.05, .485, 0.0);
	//glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.3,-.3,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
	//glVertex3f (-.5,-.5,0);
    glVertex3f (0.8,-.3,0);
    glVertex3f (-0.3,-.3,0);
    glEnd();
	glPopMatrix();

	///dogright-ear
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(.4, -1.9, 0.0);
	 glScalef(.5,1,1);
     DrawCircle(1, 1, .65, 1000);
     glPopMatrix();
     ///dogleft-ear
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(-.92, -1.9, 0.0);
	 glScalef(.5,1,1);
     DrawCircle(1, 1, .65, 1000);
     glPopMatrix();


      ///dogbody1
	 glPushMatrix();
	glColor3ub(160,82,45);
	glTranslatef(-.8, -3.1, 0.0);
	 glScalef(.34,1,1);
     DrawCircle(1, 1, 1.2, 1000);
     glPopMatrix();

     ///dogbody2
	 glPushMatrix();
	glColor3ub(160,82,45);
	glTranslatef(0.65, -3.1, 0.0);
	 glScalef(.34,1,1);
     DrawCircle(1, 1, 1.2, 1000);
     glPopMatrix();


     ///dogbody
	 glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(-.54, -3, 0.0);
	 glScalef(.74,1,1);
     DrawCircle(1, 1, 1.3, 1000);
     glPopMatrix();
      ///dogleftleg
	glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(0.3, .2, 0.0);
	glScalef(2,1.2,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();

	 ///dogtail
	 glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-1.4, -3.6, 0.0);
	 glScalef(3,1,1);
     DrawCircle(1, 1, .3, 1000);
     glPopMatrix();

	///dogrighttleg
	glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(1.3, .2, 0.0);
	glScalef(2,1.2,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();



}

/// /// /// //// //////////////////// 2ND SCENE FUNCTIONS ////////////////////////////////////////////////////////////////////////////

void ownhouse()
{




glPushMatrix();

 glTranslatef(-1.14, -.2, 0.0);
    glScalef(.5,.5,0);
    //doorborder
	 glPushMatrix();
    glTranslatef(0, -.6, 0.0);
    glScalef(.07,.9,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	 ///scldoor
	glPushMatrix();
	glTranslatef(0, -1.2, 0.0);
    glScalef(.14,.20,1);
    glBegin(GL_POLYGON);
    glColor3f(.9,.9,.9);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
     glColor3f(.79,.79,.79);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //bodyside
    glPushMatrix();
    glTranslatef(1.0, -2, 0.0);
    glColor3f(.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(-1.5, 3.0, 0.0);
    glVertex3f(-1.5, 1.0, 0.0);
    glColor3f(.6,.6,0.6);
    glVertex3f(-1.2, 1.2, 0.0);
    glVertex3f(-1.2, 2.8, 0.0);
    glEnd();
    glPopMatrix();





    glPushMatrix();
      glTranslatef(-.65, -.2, 0.0);
      glScalef(.5, .14, 0.0);
    glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.79,.79,.79);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.1, 03.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.25, -.2, 0.0);
    glScalef(.5, .14, 0.0);
    glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.79,.79,.79);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.1, 03.0, 0.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.15, -.2, 0.0);
    glScalef(.5, .14, 0.0);
    glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.79,.79,.79);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.1, 03.0, 0.0);
    glEnd();
    glPopMatrix();



glPushMatrix();
      glTranslatef(-.65, .4, 0.0);
      glScalef(.5, .14, 0.0);
glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.79,.79,.79);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.1, 03.0, 0.0);
    glEnd();
    glPopMatrix();

  glPushMatrix();
      glTranslatef(-.25, .4, 0.0);
      glScalef(.5, .14, 0.0);
glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.79,.79,.79);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.1, 03.0, 0.0);
    glEnd();
    glPopMatrix();


   glPushMatrix();
      glTranslatef(.15, .4, 0.0);
      glScalef(.5, .14, 0.0);
 glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.1, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.79,.79,.79);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.1, 03.0, 0.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
      glTranslatef(1, .3, 0.0);
      glScalef(1., .03, 0.0);
    glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.8, 01.0, 0.0);
    glColor3f(.9,.9,.9);
    glVertex3f(-1.5, 01.0, 0.0);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.8, 03.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(1, -.3, 0.0);
      glScalef(1., .03, 0.0);
    glColor3f(.9,.9,.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.8, 01.0, 0.0);
    glColor3f(.9,.9,.9);
    glVertex3f(-1.5, 01.0, 0.0);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.8, 03.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(01.0, -2, 0.0);
    glColor3f(.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(-2.8, 01.0, 0.0);
    glVertex3f(-1.5, 01.0, 0.0);
    glColor3f(.6,.6,0.6);
    glVertex3f(-1.5, 03.0, 0.0);
    glVertex3f(-2.8, 03.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(11, 1.6, 0.0);
    glScalef(.9,.9,1);
     ///sineboard
	glPushMatrix();
	glTranslatef(0, 1.4, 0.0);
    glScalef(.24,.10,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();
     ///sclsineboardboarder
	glPushMatrix();
	glTranslatef(0, 1.38, 0.0);
    glScalef(.25,.12,1);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

     ///sinebrdbar1
	 glPushMatrix();
    glTranslatef(-.9, 1.28, 0.0);
    glScalef(.05,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

    ///sinbrdbar2
	 glPushMatrix();
    glTranslatef(.9, 1.28, 0.0);
    glScalef(.05,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}

void school()
{
    //scldoordesign
	glPushMatrix();
    glTranslatef(0, -.7, 0.0);
    glScalef(.3,.3,0);
    glPushMatrix();
    glTranslatef(0, -.6, 0.0);
    glScalef(.07,.9,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -1.2, 0.0);
    glScalef(.14,.20,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();
    glPopMatrix();


	 ///sclwinf
	glPushMatrix();
	glTranslatef(-1.4, .55, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

    ///sclwinf
	glPushMatrix();
	glTranslatef(1.4, .55, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

     ///sclwinf
	glPushMatrix();
	glTranslatef(-.4, .55, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

    ///sclwinf
	glPushMatrix();
	glTranslatef(0.4, .55, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

     ///sclwinf
	glPushMatrix();
	glTranslatef(-.4, -0.1, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

    ///sclwinf
	glPushMatrix();
	glTranslatef(0.4, -.1, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

    ///sclwinf
	glPushMatrix();
	glTranslatef(-1.4, -.1, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();
    ///sclwinf
	glPushMatrix();
	glTranslatef(1.4, -.1, 0.0);
    glScalef(.04,.07,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();
	///school3dwin1
	glPushMatrix();
	glTranslatef(2.14, .4, 0.0);
    glScalef(.03,.06,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.2,0);
    glVertex3f (5,2.7,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();
    ///school3dwin2
	glPushMatrix();
	glTranslatef(2.14, -0.1, 0.0);
    glScalef(.03,.06,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.2,0);
    glVertex3f (5,2.7,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

	///doorborder
	 glPushMatrix();
    glTranslatef(0, -.6, 0.0);
    glScalef(.07,.9,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	 ///scldoor
	glPushMatrix();
	glTranslatef(0, -1.2, 0.0);
    glScalef(.14,.20,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();




	///border1
	 glPushMatrix();
    glTranslatef(-1, .98, 0.0);
    glScalef(.02,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
    ///border2
	 glPushMatrix();
    glTranslatef(-.9, .98, 0.0);
    glScalef(.02,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

    ///border3
	 glPushMatrix();
    glTranslatef(1, .98, 0.0);
    glScalef(.02,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
    ///border4
	 glPushMatrix();
    glTranslatef(.9, .98, 0.0);
    glScalef(.02,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	///sclrightborder
	 glPushMatrix();
    glTranslatef(1.8, .98, 0.0);
    glScalef(.1,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

///sclbrdr1
	 glPushMatrix();
    glTranslatef(0, .3, 0.0);
    glScalef(1.05,.7,1);
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.7,-.9,0);
    glVertex3f (-1.7,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

    ///sclbrdr2
	 glPushMatrix();
    glTranslatef(0, .9, 0.0);
    glScalef(1.05,.7,1);
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.7,-.9,0);
    glVertex3f (-1.7,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

	 ///school3d
	glPushMatrix();
	glTranslatef(2.1, -.677, 0.0);
    glScalef(.08,.555,1);
    glBegin(GL_POLYGON);
    glColor3ub(128,21,0);
    glVertex3f (-5,-1.5,0);
    glColor3ub(26,0,0);
    glVertex3f (5,-1.2,0);
    glVertex3f (5,2.7,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

	 ///school
	glPushMatrix();
	glTranslatef(0, -.67, 0.0);
    glScalef(.36,.55,1);
    glBegin(GL_POLYGON);
    glColor3ub(128,21,0);
    glVertex3f (-5,-1.5,0);
    glColor3ub(26,0,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

     ///sclsineboard
	glPushMatrix();
	glTranslatef(0, 1.4, 0.0);
    glScalef(.24,.10,1);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();

   ///sclsineboardboarder
	glPushMatrix();
	glTranslatef(0, 1.38, 0.0);
    glScalef(.25,.12,1);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f (-5,-1.5,0);
    glVertex3f (5,-1.5,0);
    glVertex3f (5,3,0);
    glVertex3f (-5,3,0);
    glVertex3f (-5,-1.5,0);
    glEnd();
    glPopMatrix();



     ///sinebrdbar1
	 glPushMatrix();
    glTranslatef(-.9, 1.28, 0.0);
    glScalef(.05,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

    ///sinbrdbar2
	 glPushMatrix();
    glTranslatef(.9, 1.28, 0.0);
    glScalef(.05,2.46,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

}

void oldhouse ()
{
    //rightbeam
	 glPushMatrix();
    glTranslatef(1.5, 0, 0.0);
    glScalef(.13,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.2);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	//leftbeam
	 glPushMatrix();
    glTranslatef(-1.5, 0, 0.0);
    glScalef(.13,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.2);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();



	//roofwindow
	 glPushMatrix();
    glTranslatef(0, 1.2, 0.0);
    glScalef(.7,.8,0);
    glBegin(GL_POLYGON);
    glColor3f(.4,.4,.4);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glColor3f(.6,.6,.6);
    glVertex3f (.4,-.2,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//rooflittletrian
	 glPushMatrix();
    glTranslatef(0, .9, 0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(.2,.2,.1);
    glVertex3f (0,0.8,0);
    glVertex3f (.1,.7,0);
    glVertex3f (-.1,.7,0);
    glEnd();
    glPopMatrix();

	//border
	 glPushMatrix();
    glTranslatef(1, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//border
	 glPushMatrix();
    glTranslatef(.8, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();


	//border
	 glPushMatrix();
    glTranslatef(.6, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//lborder
	 glPushMatrix();
    glTranslatef(-1, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//lborder
	 glPushMatrix();
    glTranslatef(-.8, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();


	//lborder
	 glPushMatrix();
    glTranslatef(-.6, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

    //rightwindow
	 glPushMatrix();
    glTranslatef(.8, 0, 0.0);
    glScalef(.5,.6,0);
    glBegin(GL_POLYGON);
    glColor3f(.4,.4,.4);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//leftwindow
	 glPushMatrix();
    glTranslatef(-.8, 0, 0.0);
    glScalef(.5,.6,0);
    glBegin(GL_POLYGON);
    glColor3f(.6,.6,.6);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
     glColor3f(.4,.4,.4);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//doorrightborder
	 glPushMatrix();
    glTranslatef(.4, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	//doorleftborder
	 glPushMatrix();
    glTranslatef(-.4, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//house1strightborder
	 glPushMatrix();
    glTranslatef(1.3, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//house1stleftborder
	 glPushMatrix();
    glTranslatef(-1.3, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//housedoor
	 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(.1,.1,.1);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//houserooftriangleright
	 glPushMatrix();
    glTranslatef(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (1.3,-1,0);
    glVertex3f (1.2,-1,0);
    glVertex3f (0,.7,0);
    glVertex3f (0,.8,0);
    glVertex3f (1.3,-1,0);
    glEnd();
    glPopMatrix();

	//houserooftriangleleft
	 glPushMatrix();
    glTranslatef(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-1.3,-1,0);
    glVertex3f (-1.2,-1,0);
    glVertex3f (0,.7,0);
    glVertex3f (0,.8,0);
    glVertex3f (-1.3,-1,0);
    glEnd();
    glPopMatrix();

	//houseroofborder
	 glPushMatrix();
    glTranslatef(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.7,-.9,0);
    glVertex3f (-1.7,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();


	//houseroof
	 glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.4,.4,.4);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.1,.6,0);
    glVertex3f (-1.1,.6,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

	 //housebody
	 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(.9,.9,.9);
    glVertex3f (-1.3,-1,0);
    glVertex3f (1.3,-1,0);
    glVertex3f (1.3,.6,0);
    glVertex3f (-1.3,.6,0);
    glVertex3f (-1.3,-1,0);
    glEnd();
    glPopMatrix();


}
void cloud()
{
    ///cloud1
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-3.3, .78, 0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();

     ///cloud2
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-3.3, .48, 0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();

     ///cloud3
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-3.6, .62,0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();

     ///cloud4
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-2.8, .69, 0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();
}

void sideman()
{
    ///mouth

	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.07, .2, 0.0);
	glScalef(.06,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

   ///eyepupil

	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.07, .335, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();
///eye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .35, 0.0);
	glScalef(.05,.05,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

//HAND
glPushMatrix();
glTranslatef(0,-0.09,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(240, 184, 160);
	glVertex3f(0.01, -0.1,0);
	//glVertex3f(645, 140,0);
	glVertex3f(0.01, -0.5,0);
	glVertex3f(0.1, -0.5,0);
   glVertex3f(0.1,-0.1 ,0);
	glVertex3f(0.01, -0.1,0);
	glEnd();

glPopMatrix();
//body
glPushMatrix();
glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(255, 20, 20);
	glVertex3f(-0.01, 0,0);
	glVertex3f(-.1, -0.3,0);
	glVertex3f(-0.05, -0.9,0);
	glVertex3f(0.15, -0.85,0);
   glVertex3f(0.15, 0.1,0);
	glVertex3f(0.01, 0,0);
	glEnd();

glPopMatrix();

//leg
glPushMatrix();
glTranslatef(0,0.5,0);
glScalef(1,1.5,0);
glBegin(GL_POLYGON);


	glColor3ub(139,69,19);
    glVertex3f(0.15, -0.85,0);
	glVertex3f(-0.05, -0.9,0);
	//glVertex3f(645, 140,0);

	//glVertex3f(-0.09, -1.0,0);
   glVertex3f(-0.07, -1.5,0);
	glVertex3f(0.18, -1.45,0);
    glVertex3f(0.15, -0.85,0);

	glEnd();

glPopMatrix();


//Bag
glPushMatrix();
glTranslatef(0.1,.8,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(25, 0, 220);
	glVertex3f(0.05, -0.85,0);
	//glVertex3f(645, 140,0);
	glVertex3f(0.19, -0.99,0);
	glVertex3f(0.15,-1.35,0);
   glVertex3f(0.05, -1.45,0);
	//glVertex3f(0.12, ,0);
		glVertex3f(0.05, -0.85,0);

	glEnd();

glPopMatrix();



//head
glPushMatrix();
glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(240, 184, 160);
	glVertex3f(-0.01, 0,0);
	glVertex3f(0.15, 0.1,0);
	glVertex3f(0.15, 0.3,0);
	glVertex3f(-0.01,0.5,0);
   glVertex3f(-0.07, 0.3,0);
	glVertex3f(-0.08, 0.15,0);
	glVertex3f(-0.01, 0,0);

	glEnd();

glPopMatrix();

//hair
glPushMatrix();
glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(0,0, 0);
	glVertex3f(-0.01,0.5,0);
	glVertex3f(0.15, 0.3,0);
	glVertex3f(0.15, 0.1,0);
	glVertex3f(0.2,0.3,0);
	glVertex3f(0.2, 0.5,0);
    glVertex3f(-0.04,0.7,0);
	glVertex3f(-0.01,0.5,0);



	glVertex3f(645, 165,0);

	glEnd();

glPopMatrix();

//shoe
glPushMatrix();
glTranslatef(0,-.22,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(0, 0, 0);
    glVertex3f(0.18, -1.45,0);
    glVertex3f(-0.07, -1.52,0);

	glVertex3f(-0.15, -1.6,0);
	glVertex3f(0.2, -1.6,0);
    glVertex3f(0.18, -1.45,0);
	glEnd();

glPopMatrix();
}

void doggy ()

{

    ///dognose
	 glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(.14, -1.44, 0.0);
	 glScalef(.14,.14,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

	///dognosebig
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(.04, -1.5, 0.0);
	 glScalef(.25,.18,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

      ///dogeyeleftpup
	 glPushMatrix();
	 glColor3f(.9,.9,.9);
	glTranslatef(.6, -.8, 0.0);
	 glScalef(.01,.01,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();
     ///dogeyerightpup
	 glPushMatrix();
	 glColor3f(.9,.9,.9);
	glTranslatef(-.1,-.8, 0.0);
	 glScalef(.01,.01,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();
    ///dogeyeleft
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(.5, -.9, 0.0);
	 glScalef(.09,.09,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();
     ///dogeyeright
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(-.2, -.9, 0.0);
	 glScalef(.09,.09,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();


    ///dogeyespot
	 glPushMatrix();
	 glColor3f(.9,.9,.9);
	glTranslatef(.5, -1, 0.0);
	 glScalef(.11,.18,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

	///doghead
	glPushMatrix();
	glColor3ub(139,69,19);
	//glTranslatef(-0.05, .485, 0.0);
	//glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (-0.3,-.3,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
	//glVertex3f (-.5,-.5,0);
    glVertex3f (0.8,-.3,0);
    glVertex3f (-0.3,-.3,0);
    glEnd();
	glPopMatrix();

	///dogright-ear
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(.4, -1.9, 0.0);
	 glScalef(.5,1,1);
     DrawCircle(1, 1, .65, 1000);
     glPopMatrix();
     ///dogleft-ear
	 glPushMatrix();
	 glColor3ub(.9,.9,.9);
	glTranslatef(-.92, -1.9, 0.0);
	 glScalef(.5,1,1);
     DrawCircle(1, 1, .65, 1000);
     glPopMatrix();


      ///dogbody1
	 glPushMatrix();
	glColor3ub(160,82,45);
	glTranslatef(-.8, -3.1, 0.0);
	 glScalef(.34,1,1);
     DrawCircle(1, 1, 1.2, 1000);
     glPopMatrix();

     ///dogbody2
	 glPushMatrix();
	glColor3ub(160,82,45);
	glTranslatef(0.65, -3.1, 0.0);
	 glScalef(.34,1,1);
     DrawCircle(1, 1, 1.2, 1000);
     glPopMatrix();


     ///dogbody
	 glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(-.54, -3, 0.0);
	 glScalef(.74,1,1);
     DrawCircle(1, 1, 1.3, 1000);
     glPopMatrix();
      ///dogleftleg
	glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(0.3, .2, 0.0);
	glScalef(2,1.2,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();

	 ///dogtail
	 glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-1.4, -3.6, 0.0);
	 glScalef(3,1,1);
     DrawCircle(1, 1, .3, 1000);
     glPopMatrix();

	///dogrighttleg
	glPushMatrix();
	glColor3ub(139,69,19);
	glTranslatef(1.3, .2, 0.0);
	glScalef(2,1.2,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.4,-2,0);
	glVertex3f (-.35,-3,0);
	glVertex3f (-.18,-3,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.4,-2,0);
    glEnd();
	glPopMatrix();



}
void bush()
{
     ///bush
	glPushMatrix();
	glColor3f(0,.65,0);
	glTranslatef(3, -1, 0.0);
	glScalef(.08,.08,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
    glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();
}

/// scene 3 function /////////////////////////////////////////////////////////////////////////////////////////

void manush()
{
    ///mouth

	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.07, .2, 0.0);
	glScalef(.06,.002,0);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();


    ///eyepupil

	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.07, .335, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();
///eye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .35, 0.0);
	glScalef(.05,.05,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();
//HAND
glPushMatrix();
glColor3ub(240, 184, 160);

glTranslatef(0,-0.09,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);

	glVertex3f(0.01, -0.1,0);
	glVertex3f(0.01, -0.5,0);
	glVertex3f(0.1, -0.5,0);
   glVertex3f(0.1,-0.1 ,0);
	glVertex3f(0.01, -0.1,0);
	glEnd();

glPopMatrix();
//body
glPushMatrix();
	glColor3ub(255, 20, 20);

glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);

	glVertex3f(-0.01, 0,0);
	glVertex3f(-.1, -0.3,0);
	glVertex3f(-0.05, -0.9,0);
	glVertex3f(0.15, -0.85,0);
   glVertex3f(0.15, 0.1,0);
	glVertex3f(0.01, 0,0);
	glEnd();

glPopMatrix();

//leg
glPushMatrix();
	glColor3ub(255, 20, 225);

glTranslatef(0,0.5,0);
glScalef(1,1.5,0);
glBegin(GL_POLYGON);


    glVertex3f(0.15, -0.85,0);
	glVertex3f(-0.05, -0.9,0);
	//glVertex3f(645, 140,0);

	//glVertex3f(-0.09, -1.0,0);
   glVertex3f(-0.07, -1.5,0);
	glVertex3f(0.18, -1.45,0);
    glVertex3f(0.15, -0.85,0);

	glEnd();

glPopMatrix();


//Bag
glPushMatrix();
	glColor3ub(25, 0, 220);

glTranslatef(0.1,.8,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glVertex3f(0.05, -0.85,0);
	//glVertex3f(645, 140,0);
	glVertex3f(0.19, -0.99,0);
	glVertex3f(0.15,-1.35,0);
   glVertex3f(0.05, -1.45,0);
	//glVertex3f(0.12, ,0);
		glVertex3f(0.05, -0.85,0);

	glEnd();

glPopMatrix();



//head
glPushMatrix();
	glColor3ub(240, 184, 160);

glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glVertex3f(-0.01, 0,0);
	glVertex3f(0.15, 0.1,0);
	glVertex3f(0.15, 0.3,0);
	glVertex3f(-0.01,0.5,0);
   glVertex3f(-0.07, 0.3,0);
	glVertex3f(-0.08, 0.15,0);
	glVertex3f(-0.01, 0,0);

	glEnd();

glPopMatrix();

//hair
glPushMatrix();
	glColor3ub(0,0, 0);

glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glVertex3f(-0.01,0.5,0);
	glVertex3f(0.15, 0.3,0);
	glVertex3f(0.15, 0.1,0);
	glVertex3f(0.2,0.3,0);
	glVertex3f(0.2, 0.5,0);
    glVertex3f(-0.04,0.7,0);
	glVertex3f(-0.01,0.5,0);





	glEnd();

glPopMatrix();

//shoe
glPushMatrix();
	glColor3ub(0, 0, 0);

glTranslatef(0,-.22,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


    glVertex3f(0.18, -1.45,0);
    glVertex3f(-0.07, -1.52,0);

	glVertex3f(-0.15, -1.6,0);
	glVertex3f(0.2, -1.6,0);
    glVertex3f(0.18, -1.45,0);
	glEnd();

glPopMatrix();
}
//Board
void Board()
{
    glPushMatrix();
    glColor3ub(50,0,200);
    glTranslatef(0,2.05,0);

    glScalef(2.5,.5,0);

    glutSolidCube(1);

    glPopMatrix();
}

//Board Border
void Board_Border()
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0,2.05,0);

    glScalef(2.5,.5,0);

    glutWireCube(1);

    glPopMatrix();
}

void Board_Stick()
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(0,2.6,0);

    glScalef(.1,.6,0);

    glutSolidCube(1);

    glPopMatrix();
}

/// scene 4  functions//////////////////////////////////////////////////////////////////////////////////////////////////

void car()
{
     glPushMatrix();
    glTranslatef(2.5,1.37,0);
    glScalef(.19,.65,0);
    glColor3f(1,.6,0);
    glutSolidCube(1);
    glPopMatrix();

	//line1
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f (1,2.1,0);
	glVertex3f (1,1.05,0);
	glEnd();
	glPopMatrix();
	//line 2
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f (0,1.7,0);
	glVertex3f (2,1.7,0);
	glEnd();
	glPopMatrix();


	//backwheel

	/*glPushMatrix();
	glTranslatef(1.8,1, 0.0);
	//glRotatef(_angle,0.0,0.0,1.0);
	glColor3f(1,1.0,1);
    glutWireSphere(0.3,20,2);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(1.8,1, 0.0);
	glRotatef(_angle,0.0,0.0,1.0);
	glColor3f(0,0,0);
    glutSolidSphere(0.3,20,2);
	glPopMatrix();


	/*//frontwheel
	glPushMatrix();
	glTranslatef(.2,1, 0.0);
	//glRotatef(_angle,0.0,0.0,1.0);

    glColor3f(1,1.0,1);
    glutWireSphere(0.3,20,2);
	glPopMatrix();*/


	glPushMatrix();
	glTranslatef(.2,1, 0.0);
	glRotatef(_angle,0.0,0.0,1.0);
    glColor3f(0,0,0);
    glutSolidSphere(0.3,20,2);
	glPopMatrix();


    //front
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,.6,.6);
    glVertex3f (-.8,1.05,0);
    glVertex3f (0,1.05,0);
    glVertex3f (0,1.7,0);
    glVertex3f (-.8,1.6,0);
     glEnd();
    glPopMatrix();

    //mid
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.6,.6,.6);
    glVertex3f (0,1.05,0);
    glVertex3f (2,1.05,0);
    glVertex3f (2,1.7,0);
    glVertex3f (0,1.7,0);
     glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.6,.6,.6);
    glVertex3f (0,1.7,0);
    glVertex3f (2,1.7,0);
    glVertex3f (1.3,2.1,0);
    glVertex3f (.5,2.1,0);
     glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.6,.6,.6);
    glVertex3f (2,1.05,0);
    glVertex3f (2.4,1.05,0);
    glVertex3f (2.4,1.7,0);
    glVertex3f (2,1.7,0);
     glEnd();
    glPopMatrix();
}
void Student()
{
    ///mouth

	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.07, .2, 0.0);
	glScalef(.06,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

   ///eyepupil

	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.07, .335, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();
///eye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .35, 0.0);
	glScalef(.05,.05,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

//HAND
glPushMatrix();
glTranslatef(0,-0.09,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(240, 184, 160);
	glVertex3f(0.01, -0.1,0);
	//glVertex3f(645, 140,0);
	glVertex3f(0.01, -0.5,0);
	glVertex3f(0.1, -0.5,0);
   glVertex3f(0.1,-0.1 ,0);
	glVertex3f(0.01, -0.1,0);
	glEnd();

glPopMatrix();
//body
glPushMatrix();
glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(255, 20, 20);
	glVertex3f(-0.01, 0,0);
	glVertex3f(-.1, -0.3,0);
	glVertex3f(-0.05, -0.9,0);
	glVertex3f(0.15, -0.85,0);
   glVertex3f(0.15, 0.1,0);
	glVertex3f(0.01, 0,0);
	glEnd();

glPopMatrix();

//leg
glPushMatrix();
glTranslatef(0,0.5,0);
glScalef(1,1.5,0);
glBegin(GL_POLYGON);


	glColor3ub(139,69,19);
    glVertex3f(0.15, -0.85,0);
	glVertex3f(-0.05, -0.9,0);
	//glVertex3f(645, 140,0);

	//glVertex3f(-0.09, -1.0,0);
   glVertex3f(-0.07, -1.5,0);
	glVertex3f(0.18, -1.45,0);
    glVertex3f(0.15, -0.85,0);

	glEnd();

glPopMatrix();


//Bag
glPushMatrix();
glTranslatef(0.1,.8,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(25, 0, 220);
	glVertex3f(0.05, -0.85,0);
	//glVertex3f(645, 140,0);
	glVertex3f(0.19, -0.99,0);
	glVertex3f(0.15,-1.35,0);
   glVertex3f(0.05, -1.45,0);
	//glVertex3f(0.12, ,0);
		glVertex3f(0.05, -0.85,0);

	glEnd();

glPopMatrix();



//head
glPushMatrix();
glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(240, 184, 160);
	glVertex3f(-0.01, 0,0);
	glVertex3f(0.15, 0.1,0);
	glVertex3f(0.15, 0.3,0);
	glVertex3f(-0.01,0.5,0);
   glVertex3f(-0.07, 0.3,0);
	glVertex3f(-0.08, 0.15,0);
	glVertex3f(-0.01, 0,0);

	glEnd();

glPopMatrix();

//hair
glPushMatrix();
glTranslatef(0,0,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(0,0, 0);
	glVertex3f(-0.01,0.5,0);
	glVertex3f(0.15, 0.3,0);
	glVertex3f(0.15, 0.1,0);
	glVertex3f(0.2,0.3,0);
	glVertex3f(0.2, 0.5,0);
    glVertex3f(-0.04,0.7,0);
	glVertex3f(-0.01,0.5,0);



	glVertex3f(645, 165,0);

	glEnd();

glPopMatrix();

//shoe
glPushMatrix();
glTranslatef(0,-.22,0);
glScalef(1,1,0);
glBegin(GL_POLYGON);


	glColor3ub(0, 0, 0);
    glVertex3f(0.18, -1.45,0);
    glVertex3f(-0.07, -1.52,0);

	glVertex3f(-0.15, -1.6,0);
	glVertex3f(0.2, -1.6,0);
    glVertex3f(0.18, -1.45,0);
	glEnd();

glPopMatrix();
}
void tree2()
{


    glPushMatrix();
	glTranslatef(-4,-1, 0.0);
    //glScalef(2,2,0);
    glColor3f(0,0.6,0.1);
    glutSolidSphere(0.2,20,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9,-.9, 0.0);
	//glScalef(2,2,0);
    glColor3f(0,0.6,0.1);
    glutSolidSphere(0.2,20,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.7,-.8, 0.0);
    //glScalef(2,2,0);
    glColor3f(0,0.6,0.1);
    glutSolidSphere(0.2,20,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.6,-.9, 0.0);
    //glScalef(2,2,0);
    glColor3f(0,0.6,0.1);
    glutSolidSphere(0.2,20,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9,-1, 0.0);
    glColor3f(0,0.6,0.1);
    glutSolidSphere(0.2,20,2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5,-1, 0.0);
    glColor3f(0,0.6,0.1);
    glutSolidSphere(0.2,20,2);
	glPopMatrix();

	glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,.26,0.26);
    glVertex3f (-3.8,-1.6,0);
    glVertex3f (-3.6,-1.6,0);
    glVertex3f (-3.7,-1,0);
    glVertex3f (-3.7,-1,0);
    glEnd();
    glPopMatrix();
    //glPopMatrix();
}


void cloudp()
{
    ///cloud1
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-3.3, .78, 0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();

     ///cloud2
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-3.3, .48, 0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();

     ///cloud3
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-3.6, .62,0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();

     ///cloud4
     glPushMatrix();
	 glColor3ub(255,255,255);
	 glTranslatef(-2.8, .69, 0.0);
	 glScalef(.5,.2,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();
}


void scene1()
{
    ///total dog/////
	glPushMatrix();
	glTranslatef(-.6, -1.2, 0.0);
	glScalef(.27,.27,1);
    dog();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(.1,bln,0);

	///baloon1
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(.45, 1.2, 0.0);
	glScalef(.28,.35,1);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

    ///baloon2
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(0, 1.2, 0.0);
	glScalef(.28,.35,1);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

    ///baloonline2
	glPushMatrix();
	glTranslatef(0.28, .3, 0.0);
	glScalef(.38,1.1,1);
	ctrlPointsCount=3;
	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X3[i];
		ctrlPointsY[i] = Y3[i];
	}
	drawline();
	glPopMatrix();

	///baloonline1
	glPushMatrix();
	glTranslatef(0.32, .3, 0.0);
	glScalef(.38,1.1,1);
	ctrlPointsCount=3;
	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X2[i];
		ctrlPointsY[i] = Y2[i];
	}
	drawline();
	glPopMatrix();
	glPopMatrix();

    ///totalmom
    glPushMatrix();
    glTranslatef(0.7, -0.7, 0.0);
	glScalef(.88,.9,1);
	mom();
    glPopMatrix();

    ///totaldad
    glPushMatrix();
    glTranslatef(-1, -0.6, 0.0);
	//glScalef(.8,.8,1);
	dad();
    glPopMatrix();


	///totalboy
	glPushMatrix();
    glTranslatef(-.1, -.9, 0.0);
	glScalef(.8,.8,1);
	people();
    glPopMatrix();

	///paperrpiecelef1
	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(-1, 1.9, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.6,0,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,0,0);
    glEnd();
	glPopMatrix();

	///paperrpiecelef2
	glPushMatrix();
	glColor3f(1,1,0);
	glTranslatef(-2, 2.0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,0.12,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,0,0);
    glEnd();
	glPopMatrix();

	///paperrpiecelef3
	glPushMatrix();
	glColor3f(0,.5,1);
	glTranslatef(-3, 2.3, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,0.1,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,-0.2,0);
    glEnd();
	glPopMatrix();

	///paperrpiecelef4
	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(-4, 2.7, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,0.27,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,-0.25,0);
    glEnd();
	glPopMatrix();

	///paperrpiecemid
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(0, 1.9, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,0,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,0,0);
    glEnd();
	glPopMatrix();

	///paperrpiecerig1
	glPushMatrix();
	glColor3f(0,0.9,1);
	glTranslatef(1, 2, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-.2,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,-.1,0);
    glEnd();
	glPopMatrix();

	///paperrpiecerig2
	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(2, 2.1, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-0.1,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,0,0);
    glEnd();
	glPopMatrix();

	///paperrpiecerig3
	glPushMatrix();
	glColor3f(1,1,0);
	glTranslatef(3, 2.2, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,0.1,0);
    glVertex3f (1,-.9,0);
    glVertex3f (1.5,0.3,0);
    glEnd();
	glPopMatrix();

	///paperrpiecerig4
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(4, 2.5, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-0.1,0);
    glVertex3f (1,-1,0);
    glVertex3f (1.5,0.2,0);
    glEnd();
	glPopMatrix();

    ///bush6
	glPushMatrix();
	glColor3f(0,.65,0);
	glTranslatef(3.4, -1.8, 0.0);
	glScalef(.2,.2,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
    glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();


	///upper linecurve
	glPushMatrix();
	ctrlPointsCount=3;
	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X1[i];
		ctrlPointsY[i] = Y1[i];
	}
	drawline();
	glPopMatrix();


	 ///bush5
	glPushMatrix();
	glColor3f(0,.65,0);
	glTranslatef(2.8, -1.5, 0.0);
	glScalef(.25,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
    glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();
	 ///bush4
	glPushMatrix();
	glColor3f(.0,.65,.0);
	glTranslatef(2, -1.8, 0.0);
	glScalef(.3,.3,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
     glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();
	 ///bush3
	glPushMatrix();
	glColor3f(.0,.65,.0);
	glTranslatef(1.3, -1.2, 0.0);
	glScalef(.25,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
     glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();

	 ///bush2new
	glPushMatrix();
	glColor3f(.0,.65,.0);
	glTranslatef(-3.5, -2., 0.0);
	glScalef(.2,.2,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
     glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();
	 ///bush2
	glPushMatrix();
	glColor3f(.0,.65,.0);
	glTranslatef(-2.5, -1.7, 0.0);
	glScalef(.25,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
     glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();

	 ///bush1
	glPushMatrix();
	glColor3f(.0,.65,.0);
	glTranslatef(-4, -1.3, 0.0);
	glScalef(.2,.2,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
     glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();



	//rightgrasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(3.9, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();
	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(3.5, -1, 0.0);
    glutSolidSphere(.2,200,150);
    glPopMatrix();
	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(3.2, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(2.9, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(2.7, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

     //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(2.4, -1, 0.0);
    glutSolidSphere(.2,200,150);
    glPopMatrix();


     //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(2, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

     //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(1.7, -1, 0.0);
    glutSolidSphere(.2,200,150);
    glPopMatrix();


	//leftgrasssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-3.9, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();
	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-3.5, -1, 0.0);
    glutSolidSphere(.2,200,150);
    glPopMatrix();
	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-3.2, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-2.9, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

	 //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-2.7, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

     //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-2.4, -1, 0.0);
    glutSolidSphere(.2,200,150);
    glPopMatrix();


     //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-2, -1, 0.0);
    glutSolidSphere(.3,200,150);
    glPopMatrix();

     //lgrass
	glPushMatrix();
	glColor3f(.0,.45,.0);
	glTranslatef(-1.7, -1, 0.0);
    glutSolidSphere(.2,200,150);
    glPopMatrix();

	 //lefttreeleaf5
	glPushMatrix();
	glColor3f(.004,.19,.12);
	glTranslatef(-2.7, .1, 0.0);
    glutSolidSphere(.4,200,150);
    glPopMatrix();

	//lefttreeleaf4
	glPushMatrix();
	glColor3f(.004,.24,.08);
	glTranslatef(-2.8, 1, 0.0);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

	//lefttreeleaf3
	glPushMatrix();
	glColor3f(.004,.24,.08);
	glTranslatef(-3.3, 0.65, 0.0);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

    //lefttreeleaf2
	glPushMatrix();
	glColor3f(.004,.19,.12);
	glTranslatef(-2.7, 0.65, 0.0);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

	//lefttreeleaf1
	glPushMatrix();
	glColor3f(.004,.19,.12);
	glTranslatef(-3.0, 0.5, 0.0);
    glScalef(.9,1.2,1);
    glutSolidSphere(.7,200,150);
    glPopMatrix();


    //righttreeleaf5
	glPushMatrix();
	glColor3f(.004,.24,.08);
	glTranslatef(3.4, .1, 0.0);
    glutSolidSphere(.4,200,150);
    glPopMatrix();

	//righttreeleaf4
	glPushMatrix();
	glColor3f(.004,.24,.08);
	glTranslatef(3.2, .9, 0.0);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

	//righttreeleaf3
	glPushMatrix();
	glColor3f(.004,.24,.08);
	glTranslatef(3.3, 0.65, 0.0);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

    //righttreeleaf2
	glPushMatrix();
	glColor3f(.004,.19,.12);
	glTranslatef(2.7, 0.65, 0.0);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

	//righttreeleaf1
	glPushMatrix();
	glColor3f(.004,.19,.12);
	glTranslatef(3.0, 0.5, 0.0);
    glScalef(.9,1.2,1);
    glutSolidSphere(.7,200,150);
    glPopMatrix();

	 //righttreebody
	glPushMatrix();
	glColor3f(.39,.26,.13);
	glTranslatef(3.0, -0.5, 0.0);
    glScalef(.4,2,1);
    glutSolidCube(.5);
    glPopMatrix();

	 //lefttreebody
	glPushMatrix();
	glColor3f(.39,.26,.13);
	glTranslatef(-3.0, -0.5, 0.0);
    glScalef(.4,2,1);
    glutSolidCube(.5);
    glPopMatrix();



	//rightbeam
	 glPushMatrix();
    glTranslatef(1.5, 0, 0.0);
    glScalef(.13,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.2);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	//leftbeam
	 glPushMatrix();
    glTranslatef(-1.5, 0, 0.0);
    glScalef(.13,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.2);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();



	//roofwindow
	 glPushMatrix();
    glTranslatef(0, 1.2, 0.0);
    glScalef(.7,.8,0);
    glBegin(GL_POLYGON);
    glColor3f(.4,.7,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
    glColor3f(.4,.6,.5);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//rooflittletrian
	 glPushMatrix();
    glTranslatef(0, .9, 0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(.2,.2,.1);
    glVertex3f (0,0.8,0);
    glVertex3f (.1,.7,0);
    glVertex3f (-.1,.7,0);
    glEnd();
    glPopMatrix();

	//border
	 glPushMatrix();
    glTranslatef(1, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//border
	 glPushMatrix();
    glTranslatef(.8, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();


	//border
	 glPushMatrix();
    glTranslatef(.6, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//lborder
	 glPushMatrix();
    glTranslatef(-1, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//lborder
	 glPushMatrix();
    glTranslatef(-.8, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();


	//lborder
	 glPushMatrix();
    glTranslatef(-.6, 0, 0.0);
    glScalef(.05,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.2,.1);
    glVertex3f (-.15,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

    //rightwindow
	 glPushMatrix();
    glTranslatef(.8, 0, 0.0);
    glScalef(.5,.6,0);
    glBegin(GL_POLYGON);
    glColor3f(.4,.7,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
    glColor3f(.4,.6,.5);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//leftwindow
	 glPushMatrix();
    glTranslatef(-.8, 0, 0.0);
    glScalef(.5,.6,0);
    glBegin(GL_POLYGON);
    glColor3f(.4,.7,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
    glColor3f(.4,.6,.5);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//doorrightborder
	 glPushMatrix();
    glTranslatef(.4, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
	//doorleftborder
	 glPushMatrix();
    glTranslatef(-.4, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//house1strightborder
	 glPushMatrix();
    glTranslatef(1.3, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//house1stleftborder
	 glPushMatrix();
    glTranslatef(-1.3, 0, 0.0);
    glScalef(.1,1,0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//housedoor
	 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(.1,.1,.1);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,-.2,0);
    glVertex3f (.4,-.2,0);
    glColor3f(.2,.2,.15);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();

	//houserooftriangleright
	 glPushMatrix();
    glTranslatef(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (1.3,-1,0);
    glVertex3f (1.2,-1,0);
    glVertex3f (0,.7,0);
    glVertex3f (0,.8,0);
    glVertex3f (1.3,-1,0);
    glEnd();
    glPopMatrix();

	//houserooftriangleleft
	 glPushMatrix();
    glTranslatef(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-1.3,-1,0);
    glVertex3f (-1.2,-1,0);
    glVertex3f (0,.7,0);
    glVertex3f (0,.8,0);
    glVertex3f (-1.3,-1,0);
    glEnd();
    glPopMatrix();

	//houseroofborder
	 glPushMatrix();
    glTranslatef(0.0, 1, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.2,.4,.5);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.7,-.9,0);
    glVertex3f (-1.7,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();


	//houseroof
	 glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(.3,.5,.5);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glColor3f(.3,.3,.3);
    glVertex3f (1.1,.6,0);
    glVertex3f (-1.1,.6,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

	 //housebody
	 glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(.9,.9,.9);
    glVertex3f (-1.3,-1,0);
    glVertex3f (1.3,-1,0);
    glVertex3f (1.3,.6,0);
    //glColor3f(.8,.8,.8);
    glVertex3f (-1.3,.6,0);
    glVertex3f (-1.3,-1,0);
    glEnd();
    glPopMatrix();




     ///sun
	 glPushMatrix();
	 glColor3ub(210,105,30);
	glTranslatef(-3, -.68, 0.0);
	 glScalef(.5,.5,1);
     DrawCircle(1, 1, 2, 1000);
     glPopMatrix();

    //sky
	glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.30,0.9);
    glVertex3f (-5.56,-1,0);
    glVertex3f (5.56,-1,0);
    glColor3ub(153,221,255);
    glVertex3f (5.56,3,0);
    glVertex3f (-5.56,3,0);
    glVertex3f (-5.56,-1,0);
    glEnd();
    glPopMatrix();

       //field
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,.45,0);
    glVertex3f (-5.56,-3,0);
    glVertex3f (5.56,-3,0);

    glVertex3f (5.56,1,0);
    glVertex3f (-5.56,1,0);
    glVertex3f (-5.56,-3,0);
    glEnd();
    glPopMatrix();

}

void scene2()
{

	///man
	glPushMatrix();
	glTranslatef(-man,-.01,0);
	glPushMatrix();
	glTranslatef(2.8, -.8, 0.0);
	glScalef(.5,.5,1);
	sideman();
	glPopMatrix();
	glPopMatrix();

glPushMatrix();

Sprint(-.4,1.7,text_1);
Sprint(3.65,1.5,t_1);
glPopMatrix();
	///bush1
	glPushMatrix();
	//glTranslatef(-2.2, -1.1, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();

	///bush2
	glPushMatrix();
	glTranslatef(-3.2, -.2, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();

	///bush3
	glPushMatrix();
	glTranslatef(-1.9, -.17, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();

	///bush4
	glPushMatrix();
	glTranslatef(-1.2, -.17, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();

	///bush5
	glPushMatrix();
	glTranslatef(-5.2, .17, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();

	///bush6
	glPushMatrix();
	glTranslatef(-5, .47, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();

    ///bush7
	glPushMatrix();
	glTranslatef(-5.7, 0, 0.0);
	//glScalef(.1,.1,1);
	bush();
	glPopMatrix();
	///doggy
	glPushMatrix();
	glTranslatef(-2.2, -1.1, 0.0);
	glScalef(.1,.1,1);
	doggy ();
	glPopMatrix();




	 ///bush1
	glPushMatrix();
	glColor3f(0,.65,0);
	glTranslatef(3, -1, 0.0);
	glScalef(.08,.08,1);
	glBegin(GL_POLYGON);
    glVertex3f (.5,-3,0);
    glVertex3f (1.3,-1.4,0);
    glVertex3f (0.7,-1.7,0);
    glVertex3f (.9,-1,0);
    glVertex3f (.3,-1.5,0);
    glVertex3f (.2,0,0);
    glColor3f(0.8, 0.65, 0.0);
    glVertex3f (-.3,-1.5,0);
    glVertex3f (-.8,-1,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-1.3,-1.7,0);
    glVertex3f (-0.5,-3,0);
    glVertex3f (.5,-3,0);
    glEnd();
	glPopMatrix();

	//lamplightleft
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(2.8, -.2, 0.0);
	glScalef(1,2,1);
    glutSolidSphere(.1,200,150);
    glPopMatrix();

    //lampleftleft
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(-2.4, -.2, 0.0);
	glScalef(1,2,1);
    glutSolidSphere(.1,200,150);
    glPopMatrix();

	///lamppost1
	 glPushMatrix();
    glTranslatef(2.8, -.05, 0.0);
    glScalef(.1,1.46,0);
    glBegin(GL_POLYGON);
    glColor3ub(102,93,30);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
    ///lamppost1
	 glPushMatrix();
    glTranslatef(-2.4, -.05, 0.0);
    glScalef(.1,1.46,0);
    glBegin(GL_POLYGON);
    glColor3ub(102,93,30);
    glVertex3f (-.4,-1,0);
    glVertex3f (-.4,0,0);
    glVertex3f (.4,0,0);
    glVertex3f (.4,-1,0);
    glVertex3f (-.4,-1,0);
    glEnd();
    glPopMatrix();
//ownhouse
	glPushMatrix();
	glTranslatef(5,-0,0);
	glScalef(1,1.2,1);
	ownhouse();
	glPopMatrix();
//scl
	glPushMatrix();
	glTranslatef(0,.3,0);
	glScalef(1,1,1);
	school();
	glPopMatrix();


	//ownhouse
	glPushMatrix();
	glTranslatef(-2.7,-.5,0);
	glScalef(.6,.7,1);
	ownhouse();
	glPopMatrix();
	///oldhouse
	//scl
	glPushMatrix();
	glTranslatef(-4.,-.9,0);
	glScalef(.3,.3,1);
	oldhouse();
	glPopMatrix();





	///zebra1
	 glPushMatrix();
    glTranslatef(-3, -1.3, 0.0);
    glScalef(.5,.7,1);
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.6,-.9,0);
    glVertex3f (-1.8,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

    ///zebra2
	 glPushMatrix();
    glTranslatef(0, -1.3, 0.0);
    glScalef(.5,.7,1);
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.6,-.9,0);
    glVertex3f (-1.8,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

    ///zebra3
	 glPushMatrix();
    glTranslatef(3, -1.3, 0.0);
    glScalef(.5,.7,1);
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glVertex3f (-1.7,-1,0);
    glVertex3f (1.7,-1,0);
    glVertex3f (1.6,-.9,0);
    glVertex3f (-1.8,-.9,0);
    glVertex3f (-1.7,-1,0);
    glEnd();
    glPopMatrix();

    ///total cloud

     glPushMatrix();
     glTranslatef(0+cld,-.01,0);
    ///cloud1st
     glPushMatrix();
	 glTranslatef(-2, 1.6, 0.0);
	 glScalef(.6,.6,1);
     cloud();
     glPopMatrix();

     ///cloud2nd
     glPushMatrix();
	 glTranslatef(.3, .9, 0.0);
	 glScalef(.6,.6,1);
     cloud();
     glPopMatrix();


     ///cloudlast
     glPushMatrix();
	 glTranslatef(4, 1.6, 0.0);
	 glScalef(.6,.6,1);
     cloud();
     glPopMatrix();

     glPopMatrix();

    ///sun
	 glPushMatrix();
	 glColor3ub(255,255,51);
	 glTranslatef(0.9, .78, 0.0);
	 glScalef(.5,.5,1);
     DrawCircle(1, 1, 1.4, 1000);
     glPopMatrix();


     ///grass
    glPushMatrix();
    glTranslatef(0,1.51,0);
    glBegin(GL_POLYGON);
    glColor3f(0,.45,0);
    glVertex3f (-5.6,-3,0);
    glVertex3f (5.6,-3,0);
     glColor3f(0,.65,0);
    glVertex3f (5.6,-2,0);
     glColor3f(0,.85,0);
    glVertex3f (-5.6,-2,0);
    glVertex3f (-5.6,-3,0);
    glEnd();
    glPopMatrix();

	 //sky
	glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(80,43,128);
    glVertex3f (-5.6,-1.5,0);
    glVertex3f (5.6,-1.5,0);
     glColor3ub(51,119,255);
    glVertex3f (5.6,3,0);
     glColor3ub(153,221,255);
    glVertex3f (-5.6,3,0);
    glVertex3f (-5.6,-1.5,0);
    glEnd();
    glPopMatrix();




    //road
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(32,32,32);
    glVertex3f (-5.6,-3,0);
    glVertex3f (5.6,-3,0);
    //glColor3ub(178,190,181);
    glVertex3f (5.6,-1,0);
    glColor3ub(48,48,48);
    glVertex3f (-5.6,-1,0);
    glVertex3f (-5.6,-3,0);
    glEnd();
    glPopMatrix();
}

void scene3()
{
    glPushMatrix();
glTranslatef(-mancl,0,0);
manush();
glPopMatrix();


glPushMatrix();
Sprint(-.7,2,text);
Sprint(.1,2,t);
glPopMatrix();



glPushMatrix();
Board_Stick();
glPopMatrix();

glPushMatrix();
Board_Border();
glPopMatrix();

glPushMatrix();
Board();
glPopMatrix();





glPushMatrix();
	// Second Wooden Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(1.6, -1.04,0);
	glVertex3f(1.07, -0.70,0);
	glVertex3f(1.07, 0.28,0);
	glVertex3f(1.6, 0.6,0);
    glVertex3f(1.6, -1.04,0);

	glEnd();
		glPopMatrix();
	glPushMatrix();

	// Second Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(85, 50, 15);
	glVertex3f(1.6, -1.04,0);
	glVertex3f(1.07, -0.70,0);
	glVertex3f(1.07, 0.28,0);
	glVertex3f(1.6, 0.6,0);
    glVertex3f(1.6, -1.04,0);

	glEnd();

    glPopMatrix();

	glPushMatrix();

	// Second Door border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(1.6, -1.04,0);
	glVertex3f(1.0, -0.74,0);
	glVertex3f(1.0, 0.35,0);
	glVertex3f(1.6, 0.6,0);
	glVertex3f(1.6, -1.04,0);

	glEnd();


    glPopMatrix();

	glPushMatrix();

	// Second Door
	glBegin(GL_POLYGON);
	glColor3ub(0, 210, 210);
	glVertex3f(1.6, -1.04,0);
	glVertex3f(1.0, -0.74,0);
	glVertex3f(1.0, 0.35,0);
	glVertex3f(1.6, 0.6,0);
	glVertex3f(1.6, -1.04,0);

	glEnd();

		glPopMatrix();


		glPushMatrix();
	// First Wooden Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(4.0, -2.23,0);
	glVertex3f(3.1, -1.7,0);
	glVertex3f(3.1, 0.8,0);
	glVertex3f(4.0, 1.4,0);
		glVertex3f(4.0, -2.23,0);

	glEnd();


		glPopMatrix();

				glPushMatrix();
	// First Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(85, 50, 15);
	glVertex3f(4.0, -2.23,0);
	glVertex3f(3.1, -1.7,0);
	glVertex3f(3.1, 0.8,0);
	glVertex3f(4.0, 1.4,0);
		glVertex3f(4.0, -2.23,0);

	glEnd();


		glPopMatrix();

	glPushMatrix();
	// First Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(4.0, -2.23,0);
	glVertex3f(3.0, -1.73,0);
	glVertex3f(3.0, 0.9,0);
	glVertex3f(4.0, 1.4,0);
    glVertex3f(4.0, -2.23,0);

	glEnd();

    glPopMatrix();
///Right DOORS


	glPushMatrix();
    // First Door
	glBegin(GL_POLYGON);
	glColor3ub(0, 210, 210);
	glVertex3f(4.0, -2.23,0);
	glVertex3f(3.0, -1.73,0);
	glVertex3f(3.0, 0.9,0);
	glVertex3f(4.0, 1.4,0);
    glVertex3f(4.0, -2.23,0);

	glEnd();


		glPopMatrix();

glPushMatrix();
	// Second Wooden Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-1.6, -1.04,0);
	glVertex3f(-1.07, -0.70,0);
	glVertex3f(-1.07, 0.28,0);
	glVertex3f(-1.6, 0.6,0);
    glVertex3f(-1.6, -1.04,0);

	glEnd();
		glPopMatrix();

	glPushMatrix();

	// Second Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(85, 50, 15);
	glVertex3f(-1.6, -1.04,0);
	glVertex3f(-1.07, -0.70,0);
	glVertex3f(-1.07, 0.28,0);
	glVertex3f(-1.6, 0.6,0);
    glVertex3f(-1.6, -1.04,0);

	glEnd();

    glPopMatrix();

	glPushMatrix();

	// Second Door border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-1.6, -1.04,0);
	glVertex3f(-1.0, -0.74,0);
	glVertex3f(-1.0, 0.35,0);
	glVertex3f(-1.6, 0.6,0);
	glVertex3f(-1.6, -1.04,0);

	glEnd();


    glPopMatrix();

	glPushMatrix();

	// Second Door
	glBegin(GL_POLYGON);
	glColor3ub(0, 210, 210);
	glVertex3f(-1.6, -1.04,0);
	glVertex3f(-1.0, -0.74,0);
	glVertex3f(-1.0, 0.35,0);
	glVertex3f(-1.6, 0.6,0);
	glVertex3f(-1.6, -1.04,0);

	glEnd();


		glPopMatrix();

	glPushMatrix();

	// left First Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(85, 50, 15);
	glVertex3f(-4.0, -2.23,0);
	glVertex3f(-3.1, -1.7,0);
	glVertex3f(-3.1, 0.8,0);
	glVertex3f(-4.0, 1.4,0);
		glVertex3f(-4.0, -2.23,0);

	glEnd();


		glPopMatrix();

glPushMatrix();
	// left First Wooden Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-4.0, -2.23,0);
	glVertex3f(-3.1, -1.7,0);
	glVertex3f(-3.1, 0.8,0);
	glVertex3f(-4.0, 1.4,0);
		glVertex3f(-4.0, -2.23,0);

	glEnd();


		glPopMatrix();


	glPushMatrix();
	// left First Wooden Door
	glBegin(GL_POLYGON);
	glColor3ub(85, 50, 15);
	glVertex3f(-4.0, -2.23,0);
	glVertex3f(-3.1, -1.7,0);
	glVertex3f(-3.1, 0.8,0);
	glVertex3f(-4.0, 1.4,0);
		glVertex3f(-4.0, -2.23,0);

	glEnd();


		glPopMatrix();
	glPushMatrix();

	// First Door Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-4.0, -2.23,0);
	glVertex3f(-3.0, -1.73,0);
	glVertex3f(-3.0, 0.9,0);
	glVertex3f(-4.0, 1.4,0);
		glVertex3f(-4.0, -2.23,0);

	glEnd();


		glPopMatrix();
	glPushMatrix();
///LEFT DOORS
		// First Door
	glBegin(GL_POLYGON);
	glColor3ub(20, 210, 255);
	glVertex3f(-4.0, -2.23,0);
	glVertex3f(-3.0, -1.73,0);
	glVertex3f(-3.0, 0.9,0);
	glVertex3f(-4.0, 1.4,0);
		glVertex3f(-4.0, -2.23,0);

	glEnd();

		glPopMatrix();

	glPushMatrix();

	// Right Wall Bottom Strip Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(0.5,-0.5,0);
	glVertex3f(5.55, -3.0,0);
	glVertex3f(5.55, -2.7,0);
	glVertex3f(0.5, -0.45,0);
		glVertex3f(0.5,-0.5,0);

	glEnd();

		glPopMatrix();
	glPushMatrix();

	// Right Wall Bottom Strip
	glBegin(GL_POLYGON);
	glColor3ub(255, 206, 100);
	glVertex3f(0.5,-0.5,0);
	glVertex3f(5.55, -3.0,0);
	glVertex3f(5.55, -2.7,0);
	glVertex3f(0.5, -0.45,0);
		glVertex3f(0.5,-0.5,0);

	glEnd();

		glPopMatrix();
		glPushMatrix();
	// Right Wall Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(5.55, -3.0,0);
	glVertex3f(5.55, 3.0,0);
	glVertex3f(0.5, 0.5,0);
	glVertex3f(0.5, -0.5,0);
		glVertex3f(5.55, -3.0,0);

	glEnd();


		glPopMatrix();

		glPushMatrix();

//Right wall
	glBegin(GL_POLYGON);
	glColor3ub(240, 240, 240);
	glVertex3f(5.55, -3.0,0);
	glVertex3f(5.55, 3.0,0);
	glVertex3f(0.5, 0.5,0);
	glVertex3f(0.5, -0.5,0);
		glVertex3f(5.55, -3.0,0);

	glEnd();

		glPopMatrix();

	glPushMatrix();


	// Left Wall Bottom Strip Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-5.55, -3.0,0);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(-0.5, -0.45,0.0);
	glVertex3f(-5.55, -2.7,0);
		glVertex3f(-5.55, -3.0,0);

	glEnd();


		glPopMatrix();


	glPushMatrix();



	// Left Wall Bottom Strip
	glBegin(GL_POLYGON);
	glColor3ub(255, 206, 100);
	glVertex3f(-5.55, -3.0,0);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(-0.5, -0.45,0.0);
	glVertex3f(-5.55, -2.7,0);
		glVertex3f(-5.55, -3.0,0);

	glEnd();


		glPopMatrix();

	glPushMatrix();
	// Ceiling Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-0.5, 0.5,0);
	glVertex3f(0.5, 0.5,0);

	glVertex3f(5.55, 3.0,0);
	glVertex3f(-5.55, 3.0,0);
	glEnd();


    glPopMatrix();

	glPushMatrix();

    	// Ceiling
	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 230);
	glVertex3f(-0.5, 0.5,0);
	glVertex3f(0.5, 0.5,0);
	glColor3ub(240, 240, 240);
	glVertex3f(5.55, 3.0,0);
	glVertex3f(-5.55, 3.0,0);
	glEnd();


    glPopMatrix();
		glPushMatrix();

	// Center Wall Strip border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(0.5, -0.5,0.0);
	glVertex3f(0.5, -0.45,0.0);
	glVertex3f(-0.5, -0.45,0.0);
		glVertex3f(-0.5, -0.5,0.0);

	glEnd();
	glPopMatrix();


		glPushMatrix();

	// Center Wall Strip
	glBegin(GL_POLYGON);
	glColor3ub(255, 206, 100);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(0.5, -0.5,0.0);
	glVertex3f(0.5, -0.45,0.0);
	glVertex3f(-0.5, -0.45,0.0);
		glVertex3f(-0.5, -0.5,0.0);

	glEnd();

	glPopMatrix();
		glPushMatrix();
	// Center Wall Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(0.5, -0.5,0.0);
	glVertex3f(0.5, 0.5,0.0);
	glVertex3f(-0.5, 0.5,0.0);
		glVertex3f(-0.5, -0.5,0.0);

	glEnd();
	glPopMatrix();
		glPushMatrix();
    // Center Wall
	glBegin(GL_POLYGON);
	glColor3ub(240, 240, 240);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(0.5, -0.5,0.0);
	glVertex3f(0.5, 0.5,0.0);
	glVertex3f(-0.5, 0.5,0.0);
		glVertex3f(-0.5, -0.5,0.0);

	glEnd();

	glPopMatrix();
	glPushMatrix();

	// Left Wall Border
	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-5.55, -3.0,0.0);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(-0.5, 0.5,0);
	glVertex3f(-5.55,3.0,0);
    glVertex3f(-5.55, -3.0,0.0);
	glEnd();
		glPopMatrix();

glPushMatrix();
	// Left Wall
	glBegin(GL_POLYGON);
	glColor3ub(240, 240, 240);
	glVertex3f(-5.55, -3.0,0.0);
	glVertex3f(-0.5, -0.5,0.0);
	glVertex3f(-0.5, 0.5,0);
	glVertex3f(-5.55,3.0,0);
    glVertex3f(-5.55, -3.0,0.0);
	glEnd();

		glPopMatrix();


			glPushMatrix();
	   /// Floor border

	glBegin(GL_LINE_LOOP);
	glColor3ub(20, 20, 20);
	glVertex3f(-5.55, -3.0,0.0);
	glVertex3f(5.55, -3.0,0.0);
	glVertex3f(0.5, -0.5,0.0);
	glVertex3f(-0.5, -0.5,0.0);
    glVertex3f(-5.55, -3.0,0.0);
	glEnd();

	glPopMatrix();



	glPushMatrix();
	   /// Floor

	glBegin(GL_POLYGON);
	glColor3ub(225, 215, 205);
	glVertex3f(-5.55, -3.0,0.0);
	glVertex3f(5.55, -3.0,0.0);
	glVertex3f(0.5, -0.5,0.0);
	glVertex3f(-0.5, -0.5,0.0);
    glVertex3f(-5.55, -3.0,0.0);
	glEnd();

	glPopMatrix();
}

void scene4()
{

    glPushMatrix();
    Sprint(-0.15,-0.5,text_2);
    glPopMatrix();
    //car
    glPushMatrix();
    glTranslatef(-caru,-.01,0);
     glPushMatrix();
    glTranslatef(0,-3.2,0);
    glScalef(.5,.5,0);
    car();
    glPopMatrix();
    glPopMatrix();

    /// student
    glPushMatrix();
    glTranslatef(-manu,-.01,0);
    glPushMatrix();
	glTranslatef(0,-1.7,0);
	glScalef(.3,.3,0);
	Student();
	glPopMatrix();
	glPopMatrix();

	  glPushMatrix();
     glTranslatef(11,1.5,0);
     glScalef(2,2,0);
     tree2();
     glPopMatrix();

      glPushMatrix();
     glTranslatef(0,0,0);
     glScalef(1,1,0);
     tree2();
     glPopMatrix();




     //divider
      glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-8,-2.5,0);
    glVertex3f (-4,-2.5,0);
    glVertex3f (-3,-2.5,0);
    glVertex3f (1,-2.5,0);
    glVertex3f (2,-2.5,0);
    glVertex3f (6,-2.5,0);
    glEnd();
    glPopMatrix();

    //road
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.2,.2,0.2);
    glVertex3f (-8,-3,0);
    glVertex3f (8,-3,0);
    glVertex3f (8,-2,0);
    glVertex3f (-8,-2,0);
    glEnd();
    glPopMatrix();

    //gatebar right
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.2,.2,0.2);
    glVertex3f (-.6,-2.2,0);
    glVertex3f (-.7,-2,0);
    glVertex3f (-.7,-1.2,0);
    glVertex3f (-.6,-1.2,0);
    glEnd();
    glPopMatrix();

    //gatebar left
     glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.2,.2,0.2);
    glVertex3f (.6,-2.2,0);
    glVertex3f (.7,-2,0);
    glVertex3f (.7,-1.2,0);
    glVertex3f (.6,-1.2,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f (-.01,-1.3,0);
    glVertex3f (-.01,-2,0);

     glVertex3f (0,-1.3,0);
    glVertex3f (0,-2,0);


    glEnd();
    glPopMatrix();

    //gate
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.26,.26,0.26);
    glVertex3f (-.3,-2,0);
    glVertex3f (.3,-2,0);
    glVertex3f (.3,-1.3,0);
    glVertex3f (-.3,-1.3,0);
    glEnd();
    glPopMatrix();

    //tinny mid rec
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.26,.26,0.26);
    glVertex3f (-1,-1.2,0);
    glVertex3f (1,-1.2,0);
    glVertex3f (.5,-.9,0);
    glVertex3f (-.5,-.9,0);
    glEnd();
    glPopMatrix();

    //midpart
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.4,.4,.4);
    glVertex3f (-1,-2,0);
    glVertex3f (1,-2,0);
    glVertex3f (1,0.4,0);
    glVertex3f (-1,0.4,0);
    glEnd();
    glPopMatrix();

    //windows left
    glPushMatrix();
    glTranslatef(0,0, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //2
    glPushMatrix();
    glTranslatef(.7,0, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //3
    glPushMatrix();
    glTranslatef(0,-.7, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //4
    glPushMatrix();
    glTranslatef(.7,-0.7, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //5
    glPushMatrix();
    glTranslatef(0,-1.4, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //6
    glPushMatrix();
    glTranslatef(0.7,-1.4,0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //7
    glPushMatrix();
    glTranslatef(3.5,-1.4, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //8
    glPushMatrix();
    glTranslatef(4.2,-1.4, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //9
    glPushMatrix();
    glTranslatef(3.5,-.7, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //10
    glPushMatrix();
    glTranslatef(4.2,-.7, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //11
    glPushMatrix();
    glTranslatef(3.5,0, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();

    //12
    glPushMatrix();
    glTranslatef(4.2,0, 0.0);
    glBegin(GL_LINES);
    glColor3f(1,1,0);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(.7,.7,0);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();





    //buildings

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.3,.3,0.3);
    glVertex3f (-2.5,-2,0);
    glVertex3f (2.5,-2,0);
    glVertex3f (2.5,0.4,0);
    glVertex3f (-2.5,.4,0);
    glEnd();
    glPopMatrix();



    //upper divider
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0,.5);
    glVertex3f (1,1,0);
    glVertex3f (-1,1,0);
    glVertex3f (-1,1.05,0);
    glVertex3f (1,1.05,0);
    glEnd();
    glPopMatrix();


      //top bars
   /* glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f (.5,1.7,0);
    glVertex3f (.4,1.7,0);
    glVertex3f (.4,2.2,0);
    glVertex3f (.5,2.2,0);
     glEnd();

       glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f (.1,1.7,0);
    glVertex3f (.0,1.7,0);
    glVertex3f (.0,2.2,0);
    glVertex3f (.1,2.2,0);
     glEnd();

        glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f (-.5,1.7,0);
    glVertex3f (-.4,1.7,0);
    glVertex3f (-.4,2.2,0);
    glVertex3f (-.5,2.2,0);
     glEnd(); */


    glPopMatrix();

   //top mid rec
    /*glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0.6,1);
    glVertex3f (.5,1.7,0);
    glVertex3f (-.5,1.7,0);
    glVertex3f (-.5,2.2,0);
    glVertex3f (.5,2.2,0);
    glPopMatrix();
    glEnd();*/


     //upper mid rec
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.4,.4,.4);
    glVertex3f (.5,1.05,0);
    glVertex3f (-.5,1.05,0);
    glVertex3f (-.5,1.7,0);
    glVertex3f (.5,1.7,0);
    glEnd();
    glPopMatrix();



    //upper right rec
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.5,.5,.5);
    glVertex3f (1,1.05,0);
    glVertex3f (.5,1.05,0);
    glVertex3f (.5,1.7,0);
    glVertex3f (1,1.6,0);
    glEnd();
    glPopMatrix();


    //upper left rec
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.6,.6,.6);
    glVertex3f (-1,1.05,0);
    glVertex3f (-.5,1.05,0);
    glVertex3f (-.5,1.7,0);
    glVertex3f (-1,1.6,0);
     glEnd();
    glPopMatrix();




    //upper rctnguar
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,.26,0.26);
    glVertex3f (-2.7,.4,0);
    glVertex3f (2.7,.4,0);
    glVertex3f (1,1,0);
    glVertex3f (-1,1,0);
    glEnd();
    glPopMatrix();

    //field

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,.4,0);
    glVertex3f (-8,-2,0);
    glVertex3f (8,-2,0);
    glVertex3f (8,-1,0);
    glVertex3f (-8,-1,0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloudu,-.01,0);
     //cloud
     glPushMatrix();
     glTranslatef(0.5,0.5,0);
     cloudp();
     glPopMatrix();

     //cloud2
     glPushMatrix();
     glTranslatef(4,1,0);
     cloudp();
     glPopMatrix();
      glPopMatrix();


    ///sun
	 glPushMatrix();
	 glColor3ub(255,255,51);
	 glTranslatef(-3.9, .78, 0.0);
	 glScalef(.5,.5,1);
     DrawCircle(1, 1, .9, 1000);
     glPopMatrix();

    //sky
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0,0.6,1);
    glVertex3f (-8,-1,0);
    glVertex3f (8,-1,0);
    glVertex3f (8,10,0);
    glVertex3f (-8,10,0);
    glEnd();
    glPopMatrix();

}

void scene5()
{
    glPushMatrix();
    glTranslated(0, -1.8, 0.0);

	//Laptop
    glPushMatrix();
    glTranslated(-3.8, -1.8, 0.0);
	glBegin(GL_POLYGON);
    glColor3ub(105,105,105);
	glVertex2f(1.1, 2.4);
	glVertex2f(2.2, 2.4);
	glVertex2f(2.2, 1.8);
	glVertex2f(1.1, 1.8);
	glEnd();
	glPopMatrix();

    // Monitor Stand
    glPushMatrix();
    glTranslated(-2.4, -0.3, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(192,192,192);
	glVertex2f(.1, .2);
	glVertex2f(.3, .2);
	glVertex2f(.3, .4);
	glVertex2f(.1, .4);
	glEnd();
	glPopMatrix();



	//Window

	glPushMatrix();
    glTranslatef(2.5,2.5, 0.0);
    glScalef(2.55,3.5,0);
    glBegin(GL_LINES);
    glColor3ub(5,5,5);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(135,206,235);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();


    //Window2

	glPushMatrix();
    glTranslatef(8.5,2.5, 0.0);
    glScalef(2.55,3.5,0);
    glBegin(GL_LINES);
    glColor3ub(5,5,5);
    glVertex3f (-2.28,.01,0);
    glVertex3f (-1.92,.01,0);
    glVertex3f (-2.1,.19,0);
    glVertex3f (-2.1,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(135,206,235);
    glVertex3f (-2.28,.19,0);
    glVertex3f (-1.92,.19,0);
    glVertex3f (-1.92,-.19,0);
    glVertex3f (-2.28,-.19,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0.2);
    glVertex3f (-2.3,.2,0);
    glVertex3f (-1.9,0.2,0);
    glVertex3f (-1.9,-.2,0);
    glVertex3f (-2.3,-.2,0);
    glEnd();
    glPopMatrix();







	//human1

    glPushMatrix();
    glTranslatef(-2.2, .4, 0.0);
     ///beard
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0, 0.22, 0.0);
	glScalef(.54,.16,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.28,0.7,0);
    glVertex3f (-0.28,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    ///dadtotalfacestart
    glPushMatrix();
     ///hashimukh
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0.11, 0.4, 0.0);
	glScalef(.3,0.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

	///lefteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0.07, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///nose
	glPushMatrix();
	glColor3ub(150,114,100);
	glTranslatef(0.06, .76, 0.0);
	glScalef(.15,.15,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.5,-2.4,0);
	glVertex3f (-.1,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();



	///lefteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///head
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(-0.05, .6, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///hair
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .61, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.5,-0.5,0);
    glVertex3f (0,0,0);
    glVertex3f (.5,0,0);
    glVertex3f (1,-0.5,0);
    glVertex3f (1,-0.1,0);
    glVertex3f (0.5,0.3,0);
    glVertex3f (0,.3,0);
    glVertex3f (-0.5,-.1,0);
    glVertex3f (-0.5,-0.5,0);
    glEnd();
	glPopMatrix();
    ///neck
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.25,0.7,0);
    glVertex3f (-0.25,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    glPopMatrix();

    ///dadshirt
	glPushMatrix();
	glColor3f(15,5,0);
	glScalef(.33,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (-0.3,0.7,0);
	glVertex3f (-1.02,0.5,0);
    glVertex3f (-1.02,-0.3,0);
    glVertex3f (-.7,-0.3,0);
    glVertex3f (-.6,-1,0);
    glVertex3f (.6,-1.0,0);
    glVertex3f (.7,-0.3,0);
    glVertex3f (1.02,-0.3,0);
    glVertex3f (1.02,0.5,0);
    glVertex3f (.3,.7,0);
    glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();



/*	///dadrighthand
	glPushMatrix();
	glColor3ub(195,149,130);
	glTranslatef(0.25, .25, 0.0);
	glScalef(.2,.35,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.01,-1,0);
    glVertex3f (.1,-2,0);
    glVertex3f (0.4,-2,0);
    glVertex3f (0.45,-1,0);
    glVertex3f (-0.01,-1,0);
	//glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();
*/
    glPopMatrix();

	 //table
	 glPushMatrix();
	 glTranslated(-2.2,-0.1,0);
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex3f (-1.6,-.2,0);
    glVertex3f (1.0,-.2,0);
    glVertex3f (1.3,.2,0);
    glVertex3f (-1.3,.2,0);
    //glVertex3f (-1.3,-1,0);
    glEnd();
    glPopMatrix();


    //table body
    glPushMatrix();
    glTranslated(-2.5, -.7, 0.0);
	glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex3f (-1.0,-.2,0);
    glVertex3f (1.3,-.2,0);
    glVertex3f (1.3,.4,0);
    glVertex3f (-1.3,.4,0);
    glVertex3f (-1.3,-.2,0);
    //glVertex3f (1.3,0,0);
	glEnd();
	glPopMatrix();


        //table right side
    glPushMatrix();
    glTranslated(-1.1, -.7, 0.0);
	glBegin(GL_POLYGON);
    glColor3ub(150,82,45);
    glVertex3f (-0.1,-.20,0);
    glVertex3f (0.2,.2,0);
    glVertex3f (0.2,.8,0);
    glVertex3f (-0.4,.8,0);
    //glVertex3f (-0.2,-.2,0);
    glVertex3f (-0.1,-.20,0);
    //glVertex3f (1.3,0,0);
	glEnd();
	glPopMatrix();
    glPopMatrix();




    // 2nd PC Set


    glPushMatrix();
    glTranslated(4.5, -1.8, 0.0);

	//Laptop
    glPushMatrix();
    glTranslated(-3.8, -1.8, 0.0);
	glBegin(GL_POLYGON);
	glColor3ub(105,105,105);
	glVertex2f(1.1, 2.4);
	glVertex2f(2.2, 2.4);
	glVertex2f(2.2, 1.8);
	glVertex2f(1.1, 1.8);
	glEnd();
	glPopMatrix();



// Monitor Stand
    glPushMatrix();
    glTranslated(-2.4, -0.3, 0.0);
	glBegin(GL_POLYGON);
	//glColor3ub(105,105,105);
	glColor3ub(192,192,192);

	glVertex2f(.1, .2);
	glVertex2f(.3, .2);
	glVertex2f(.3, .4);
	glVertex2f(.1, .4);
	glEnd();
	glPopMatrix();



		//human

    glPushMatrix();
    glTranslatef(-2.1, .4, 0.0);
     ///beard
	glPushMatrix();
	glColor3ub(255,250,250);
	glTranslatef(0, 0.22, 0.0);
	glScalef(.54,.16,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.28,0.7,0);
    glVertex3f (-0.28,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    ///dadtotalfacestart
    glPushMatrix();
     ///hashimukh
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0.11, 0.4, 0.0);
	glScalef(.3,0.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.35,-2.4,0);
	glVertex3f (-.18,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();

	///lefteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(-0.05, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteyepupil
	glPushMatrix();
	glColor3ub(0,0,0);
	glTranslatef(0.07, .485, 0.0);
	glScalef(.02,.02,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///nose
	glPushMatrix();
	glColor3ub(150,114,100);
	glTranslatef(0.06, .76, 0.0);
	glScalef(.15,.15,1);
	glBegin(GL_POLYGON);
	glVertex3f (-.45,-2,0);
	glVertex3f (-.5,-2.4,0);
	glVertex3f (-.1,-2.4,0);
    glVertex3f (-.15,-2,0);
    glVertex3f (-.45,-2,0);
    glEnd();
	glPopMatrix();



	///lefteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(-0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

		///righteye
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslatef(0.065, .5, 0.0);
	glScalef(.04,.04,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///head
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(-0.05, .6, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0,0);
	glVertex3f (-.5,-.5,0);
	glVertex3f (-.5,-1,0);
    glVertex3f (0,-1.5,0);
    glVertex3f (.5,-1.5,0);
	glVertex3f (1,-1,0);
	glVertex3f (1,-0.5,0);
    glVertex3f (0.5,0,0);
    glVertex3f (0,0,0);
    glEnd();
	glPopMatrix();

	///hair
	glPushMatrix();
	glColor3ub(250,250,250);
	glTranslatef(-0.05, .61, 0.0);
	glScalef(.22,.25,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.5,-0.5,0);
    glVertex3f (0,0,0);
    glVertex3f (.5,0,0);
    glVertex3f (1,-0.5,0);
    glVertex3f (1,-0.1,0);
    glVertex3f (0.5,0.3,0);
    glVertex3f (0,.3,0);
    glVertex3f (-0.5,-.1,0);
    glVertex3f (-0.5,-0.5,0);
    glEnd();
	glPopMatrix();
    ///neck
	glPushMatrix();
	glColor3ub(210,161,140);
	glTranslatef(0, 0, 0.0);
	glScalef(.4,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (0.25,0.5,0);
	glVertex3f (0.25,0.7,0);
    glVertex3f (-0.25,0.7,0);
    glVertex3f (-0.25,0.5,0);
	glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();

    glPopMatrix();

    ///dadshirt
	glPushMatrix();
	glColor3f(.3,.2,.4);
	glScalef(.33,.4,1);
	glBegin(GL_POLYGON);
	glVertex3f (0,0.2,0);
	glVertex3f (-0.3,0.7,0);
	glVertex3f (-1.02,0.5,0);
    glVertex3f (-1.02,-0.3,0);
    glVertex3f (-.7,-0.3,0);
    glVertex3f (-.6,-1,0);
    glVertex3f (.6,-1.0,0);
    glVertex3f (.7,-0.3,0);
    glVertex3f (1.02,-0.3,0);
    glVertex3f (1.02,0.5,0);
    glVertex3f (.3,.7,0);
    glVertex3f (0,0.2,0);
    glEnd();
	glPopMatrix();



/*	///dadrighthand
	glPushMatrix();
	glColor3ub(195,149,130);
	glTranslatef(0.25, .25, 0.0);
	glScalef(.2,.35,1);
	glBegin(GL_POLYGON);
    glVertex3f (-0.01,-1,0);
    glVertex3f (.1,-2,0);
    glVertex3f (0.4,-2,0);
    glVertex3f (0.45,-1,0);
    glVertex3f (-0.01,-1,0);
	//glVertex3f (-0.45,-1,0);
    glEnd();
	glPopMatrix();
*/
    glPopMatrix();





	 //table
	 //table
	 glPushMatrix();
	 glTranslated(-2.2,-0.1,0);
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex3f (-1.6,-.2,0);
    glVertex3f (1.0,-.2,0);
    glVertex3f (1.3,.2,0);
    glVertex3f (-1.3,.2,0);
    //glVertex3f (-1.3,-1,0);
    glEnd();
    glPopMatrix();


    //table body
    glPushMatrix();
    glTranslated(-2.5, -.7, 0.0);
	glBegin(GL_POLYGON);
    glColor3ub(160,82,45);
    glVertex3f (-1.0,-.2,0);
    glVertex3f (1.3,-.2,0);
    glVertex3f (1.3,.4,0);
    glVertex3f (-1.3,.4,0);
    glVertex3f (-1.3,-.2,0);
    //glVertex3f (1.3,0,0);
	glEnd();
	glPopMatrix();


        //table right side
    glPushMatrix();
    glTranslated(-1.1, -.7, 0.0);
	glBegin(GL_POLYGON);
    glColor3ub(150,82,45);
    glVertex3f (-0.1,-.20,0);
    glVertex3f (0.2,.2,0);
    glVertex3f (0.2,.8,0);
    glVertex3f (-0.4,.8,0);
    glVertex3f (-0.2,-.2,0);
    //glVertex3f (1.3,0,0);
	glEnd();
	glPopMatrix();
    glPopMatrix();


        //Clock
    glPushMatrix();
    glTranslatef(.3, 2, 0.0);

        //watchMiddle

        glPushMatrix();
    glTranslatef(0, -1.55, 0.0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.04;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    //watchArms

    glPushMatrix();

    glTranslatef(0.01, -1.55, 0.0);
    glRotatef(_angle,0.0,0.0,-1.0);
    glColor3f(0,.5,1);
    glBegin(GL_LINES);
	glVertex3f (0.01,0,0);
    glVertex3f (0.02,.3,0);
	glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(.220, -2.05, 0.0);
    //glRotatef(_angle,0.0,0.0,-0.5);
    glColor3f(0,.5,1);
    glBegin(GL_LINES);
	glVertex3f (-0.2,.5,0);
    glVertex3f (0.02,.5,0);
	glEnd();

    glPopMatrix();


    //watch body


    glPushMatrix();
    glTranslatef(0, -1.5, 0.0);
    glColor3f(0,0,1);
    glBegin(GL_LINES);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

    glColor3f(1,1,.9);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.45;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();





    //floor
    glPushMatrix();
    glTranslated(0,-2.7,0);
    glBegin(GL_POLYGON);
    glColor3ub(189,183,107);
    glVertex3f (-5,-3,0);
    glVertex3f (8,-3,0);
    glVertex3f (8,1,0);
    glVertex3f (-4.5,1,0);
    glVertex3f (-7.25,-3,0);
    glEnd();
    glPopMatrix();

        //leftSIde wall
    glPushMatrix();
    glTranslated(-4.5,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(95,158,160);
    glVertex3f (-2,10,0);
    glVertex3f (0,5,0);
    glVertex3f (0,-10,0);
    glVertex3f (-2,-5,0);
    glVertex3f (0,-3,0);
    glEnd();
    glPopMatrix();

    //WALL
	glPushMatrix();
	glTranslated(0,-2,0);
    glBegin(GL_POLYGON);
    glColor3ub(143,188,143);
    glVertex3f (-5,-1,0);
    glVertex3f (8,-1,0);
    glVertex3f (8,5,0);
    glVertex3f (-5,5,0);
    glVertex3f (-5,-1,0);
    glEnd();
    glPopMatrix();


    //AC
    glPushMatrix();
    glTranslated(1.5, 1.5, 0.0);


    glPushMatrix();
    glTranslatef(-1.4, 0.5, 0.0);
    glColor3ub(110,55,0);
    glScalef(.8, 0.2, -.3);
    glutWireCube(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.4, 0.5, 0.0);
    glColor3ub(220,110,55);
    glScalef(.8, 0.2, -.3);
    glutSolidCube(2);
    glPopMatrix();

    glPopMatrix();

}

void startscene()
{
    glPushMatrix();
glColor3ub(12,250,0);
Sprint(-1.5,2.5,text_3);

glPopMatrix();

glPushMatrix();
glColor3ub(1,100,0);

Sprint(-1,2.2,next);
Sprint(-1,2,previous);
Sprint(-1,1.8,quit);
glPopMatrix();

glPushMatrix();
glColor3ub(255,10,122);

Sprint(-0.5,1.3,family);
Sprint(-1,1.1,baloon);
glPopMatrix();

glPushMatrix();
glColor3ub(102,27,10);

Sprint(-0.5,0.9,study);
Sprint(-1,0.7,cloudT_S);
Sprint(-1,0.5,cloudT_M);
Sprint(-1,0.3,manT_M);
Sprint(-1,0.1,manT_S);
glPopMatrix();

glPushMatrix();
glColor3ub(255,10,10);


Sprint(-0.5,-0.1,college);
Sprint(-1,-0.3,manH_M);
Sprint(-1,-0.5,manH_S);
glPopMatrix();

glPushMatrix();
glColor3ub(1,10,200);

Sprint(-0.5,-0.7,unuversity);
Sprint(-1,-0.9,gari_S);
Sprint(-1,-1.1,gari_M);
Sprint(-1,-1.3,cloudU_S);
Sprint(-1,-1.5,cloudU_M);
Sprint(-1,-1.7,manU_M);
Sprint(-1,-1.9,manU_S);
glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(230, 230, 100);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);

	glEnd();

    glPopMatrix();
}

void endscene ()
{
   glPushMatrix();
glColor3ub(230, 230, 100);
Sprint(-.5,2,moral);
glPopMatrix();
glPushMatrix();
glColor3ub(255,255,255);
Sprint(-1.3,1.5,line_1);
glPopMatrix();
glPushMatrix();
glColor3ub(255,255,200);
Sprint(-1.5,1.3,line_2);
glPopMatrix();
glPushMatrix();
glColor3ub(255,255,200);
Sprint(-1.5,1.1,line_3);
glPopMatrix();
glPushMatrix();
glColor3ub(255,255,200);
Sprint(-2.6,0.9,line_4);
glPopMatrix();
glPushMatrix();
glColor3ub(255,27,10);
Sprint(-1.3,0.7,line_5);
glPopMatrix();
glPushMatrix();
glColor3ub(12,250,0);
Sprint(-0.3,0.5,line_6);
glPopMatrix();
glPushMatrix();
glColor3ub(12,250,155);
Sprint(-2,0,line_7);
glPopMatrix();
    glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);
	glEnd();
    glPopMatrix();

}

void story1 ()
{
    glPushMatrix();
glColor3ub(12,250,0);
Sprint(-.5,0.5,tandry_1);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-0.45,0.2,tandry_2);

glPopMatrix();
glPushMatrix();

glColor3ub(12,250,0);

Sprint(-1,-0.1,tandry_3);

glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);

	glEnd();

    glPopMatrix();

}

void story2 ()
{
    glPushMatrix();
glColor3ub(12,250,0);
Sprint(-1.5,0.2,tandry_4);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-2.1,-0.1,tandry_5);

glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);

	glEnd();

    glPopMatrix();

}

void story3 ()
{
    glPushMatrix();
glColor3ub(12,250,0);
Sprint(-1.5,0.5,hrid_1);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-1,0.2,hrid_2);

glPopMatrix();
glPushMatrix();
glColor3ub(12,250,0);

Sprint(-.8,-0.1,hrid_3);

glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);

	glEnd();

    glPopMatrix();
}

void story4 ()
{
    glPushMatrix();
glColor3ub(12,250,0);
Sprint(-1.2,0.8,ussash_1);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-2.3,0.5,ussash_2);

glPopMatrix();
glPushMatrix();
glColor3ub(12,250,0);

Sprint(-1.7,0.2,ussash_3);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-2,-0.1,ussash_4);

glPopMatrix();

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);

	glEnd();

    glPopMatrix();
}

void story5 ()
{
  glPushMatrix();
glColor3ub(12,250,0);
Sprint(-1.5,0.8,waq_1);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-0.6,0.5,waq_2);

glPopMatrix();
glPushMatrix();
glColor3ub(12,250,0);

Sprint(-1,0.2,waq_3);

glPopMatrix();

glPushMatrix();
glColor3ub(12,250,0);

Sprint(-.9,-0.1,waq_4);

glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	glVertex3f(-6, 3,0);
	glVertex3f(-6, -3,0);
	glVertex3f(6,-3,0);
	glVertex3f(6,3,0);
	glVertex3f(-6, 3,0);

	glEnd();

    glPopMatrix();
}


void drawScene() {


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units



	switch (scene) {

	    case 0:
		startscene();
		break;

		case 1:
		story1();
		break;

		case 2:
		scene1();
		break;

	    case 3:
		story2();
		break;

		case 4:
		scene2();
		break;


	    case 5:
		story3();
		break;

		case 6:
		scene3();
		break;

	    case 7:
		story4();
		break;

		case 8:
		scene4();
		break;

		case 9:
		story5();
		break;

		case 10:
		scene5();
		break;

		case 11:
		endscene();
		break;

	default:
		break;
	}

	glutSwapBuffers();


}





void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

void updatebaloon(int value) {
	if (movebaloon)
	{  bln += .050f;
	if (bln > 8) {
		bln -= 360;}

}


glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(60, updatebaloon, 0); }

void updatecloud(int value) {
	if (movecloud)
	{  cld += .050f;
	if (cld > 10) {
		cld -= 20;}

}


glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(70, updatecloud, 0); }

void updateman(int value) {
	if (moveman)
	{  man += .050f;
	if (man > 8) {
		man -= 12;}

}


glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(60, updateman, 0); }

void updatemancl(int value) {
	if (movemancl)
	{  mancl += .030f;
	if (mancl > 3) {
		mancl -= 7;}
     }

glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(60, updatemancl, 0); }

void updatemanu(int value) {
	if (movemanu)
	{  manu += .030f;
	if (manu > 8) {
		manu -= 15;}

}


glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(60, updatemanu, 0); }

void updatecloudu(int value) {
	if (movecloudu)
	{  cloudu += .050f;
	if (cloudu > 8) {
		cloudu -= 17;}

}


glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(60, updatecloudu, 0); }

void updatecaru(int value) {
	if (movecaru)
	{  caru += .070f;
	if (caru > 8) {
		caru -= 14;}

}


glutPostRedisplay(); //Tell GLUT that the display has changed
glutTimerFunc(60, updatecaru, 0); }




void updateclock(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(50, updateclock, 0);
}


void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	    ///back
	    case 'b':
		if (scene == 0)
        break;
		scene--;
		break;

	    ///next
	    case 'n':
		if (scene == 11)
        break;
		scene++;
		break;

	    ///quit
	    case 'q':
		exit(0);
		break;

		///scene1
		///baloon moving
	    case 'U':
		movebaloon= 0;
		break;
		case 'u':
		movebaloon= 1;
		break;


		///scene2
        ///cloud moving
        case 'c':
		movecloud= 0;
		break;
		case 'C':
		movecloud= 1;
		break;

        ///man move
        case 'M':
		moveman= 0;
		break;
		case 'm':
		moveman= 1;
		break;


		/// scene3
        ///manush moving
        case 'K':
		movemancl= 0;
		break;
		case 'k':
		movemancl= 1;
		break;


        ///scene4
        ///cloud moving
        case 'z':
		movecloudu= 0;
		break;
		case 'Z':
		movecloudu= 1;
		break;


        ///man move
        case 'P':
		movemanu= 0;
		break;
		case 'p':
		movemanu= 1;
		break;


        ///car move
        case 'g':
		movecaru= 0;
		break;
		case 'G':
		movecaru= 1;
		break;


	    default:
		break;
	}

	glutPostRedisplay();
}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutFullScreen();
	glutInitWindowSize(1290, 750);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
   /// glutFullScreen();
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	///1st
	glutTimerFunc(0, updatebaloon, 0);

	///2nd
	glutTimerFunc(15, updatecloud, 0);
	glutTimerFunc(0, updateman, 0);

	///3rd
	glutTimerFunc(60, updatemancl, 0);

	///4th
	glutTimerFunc(0, updatecloudu, 0);
	glutTimerFunc(0, updatemanu, 0);
	glutTimerFunc(0, updatecaru, 0);

	///5th
	glutTimerFunc(25, updateclock, 0);


	glutFullScreen();




	sndPlaySound("D:\\AIUB\\11th semester\\Graphics\\graphicsfinalpro\\graphicspro1.wav",SND_ASYNC|SND_LOOP);



	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}


