#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

const float steps = 400;
const float knobSteps = 900;
const float angle = 3.1415926 * 2.f / steps;

///////////////////////////////////////////////////////////
/* GLUT callback Handlers */
static void resize(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -0.9, 2.0, 3.0, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //INSERT YOUR CODES BELOW FOR THE DIFFERENT SHAPES

    //MOON START
    ///////////////////////////////////////////////////

    float xNPos = 0; float yNPos = 0; float radiusM = 0.3f;//MOON

    float prevNX = xNPos;
    float prevNY = yNPos - radiusM;
    for (int i = 0; i <= steps; i++) {
        float newNX = radiusM * sin(angle * i);
        float newNY = -radiusM * cos(angle * i);


        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
        glVertex3f(6, 9, -20);
        glVertex3f(prevNX, prevNY, 0.0f);
        glVertex3f(newNX, newNY, 0.0f);
        glEnd();


        prevNX = newNX;
        prevNY = newNY;
    }

    float xMPos = 0; float yMPos = 0;

    float prevMX = xMPos;
    float prevMY = yMPos - radiusM;
    for (int i = 0; i <= steps; i++) {
        float newMX = radiusM * sin(angle * i);
        float newMY = -radiusM * cos(angle * i);


        glBegin(GL_TRIANGLES);
        glColor3d(0, 0, 0);
        glVertex3f(6.5f, 9.3f, -20);
        glVertex3f(prevMX, prevMY, 0.0f);
        glVertex3f(newMX, newMY, 0.0f);
        glEnd();


        prevMX = newMX;
        prevMY = newMY;
    }



    //////////////////////////////////////////////////////////////
    //MOON END
    

    //HALF-CIRCLE START
    //////////////////////////////////////////////////////////////

    float xPos = 0; float yPos = 0; float radius = 0.7f;

    float prevX = xPos;
    float prevY = yPos - radius;
    for (int i = 0; i <= steps; i++) {
        float newX = radius * sin(angle * i);
        float newY = -radius * cos(angle * i);


        glBegin(GL_TRIANGLES);//half-circle
        glColor3d(0, 0.5f, 0);
        glVertex3f(0.0f, 3, -20);
        glVertex3f(prevX, prevY, 0.0f);
        glVertex3f(newX, newY, 0.0f);
        glEnd();


        prevX = newX;
        prevY = newY;
    }

     /////////////////////////////////////////////////////////////
    //HALF-CIRCLE END



    //RECTANGLE START
    ////////////////////////////////////////////////////////////

     glBegin(GL_POLYGON);//rectangle


    glColor3d(128, 0, 0);
    glVertex3f(-6, 3, -20);//1st

    glColor3d(128, 0, 0);
    glVertex3f(6, 3, -20);//2nd

    glColor3d(128, 0, 0);
    glVertex3f(6, 4, -20);//3rd

    glColor3d(128, 0, 0);
    glVertex3f(-6, 4, -20);//4th


    glEnd();

    ////////////////////////////////////////////////////////////
    //RECTANGLE END


    //OUTER-SQUARE START
    ///////////////////////////////////////////////////////////
glBegin(GL_POLYGON);//outer square


    glColor3d(128, 0, 0);
    glVertex3f(5, 3, -20);//1st

    glColor3d(128, 0, 0);
    glVertex3f(5, -3, -20);//2nd

    glColor3d(128, 0, 0);
    glVertex3f(-5, -3, -20);//3rd

    glColor3d(128, 0, 0);
    glVertex3f(-5, 3, -20);//4th


    glEnd();


    //////////////////////////////////////////////////////////
    //OUTER-SQUARE END


     //WINDOW 1 START
    /////////////////////////////////////////////////////////



    //////////////////////////////////////////////////
    //WINDOW 1 END



    //WINDOW 2 START
    //////////////////////////////////////////////////



    ////////////////////////////////////////////////////
    //WINDOW 2 END


    //DOOR START
    /////////////////////////////////////////////////////
 glBegin(GL_POLYGON);//Door


    glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glVertex3f(1, 1, -20);//1st

    glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glVertex3f(1, -3, -20);//2nd

    glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glVertex3f(-1, -3, -20);//3rd

    glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glVertex3f(-1, 1, -20);//4th


    glEnd();

    float xDPos = 0; float yDPos = 0; float radiusD = 0.03f;//Door Knob

    float prevDX = xDPos;
    float prevDY = yDPos - radiusD;
    for (int i = 0; i <= knobSteps; i++) {
        float newDX = radiusD * sin(angle * i);
        float newDY = -radiusD * cos(angle * i);


        glBegin(GL_TRIANGLES);
        glColor3d(0, 0.5f, 0);
        glVertex3f(0.7, -1, -20);
        glVertex3f(prevDX, prevDY, 0.0f);
        glVertex3f(newDX, newDY, 0.0f);
        glEnd();


        prevDX = newDX;
        prevDY = newDY;
    }


     ///////////////////////////////////////////////////////
    //DOOR END



    glutSwapBuffers();
}


//////////////////////////////////////////////////

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
    case 'q':
        exit(0);
        break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}


//////////////////////////////////////////////////////


///////////////////////////////////////////////////////
/* Program entry point */
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT quadPoly");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0, 0, 0, 0);

    glutMainLoop();

    return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////
//END
