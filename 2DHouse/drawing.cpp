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



     /////////////////////////////////////////////////////////////
    //HALF-CIRCLE END



    //RECTANGLE START
    ////////////////////////////////////////////////////////////



    ////////////////////////////////////////////////////////////
    //RECTANGLE END


    //OUTER-SQUARE START
    ///////////////////////////////////////////////////////////



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