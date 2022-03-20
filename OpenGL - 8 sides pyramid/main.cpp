#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(0.02, 0.1, 0.0, 0.1);

    glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.8,0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.0,0.0,0.8);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.6,0.2,0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.7, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.0,0.6,0.2);
        glVertex3f(0.7, 0.0, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.6,0.0,0.2);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.0, -0.7, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.5,0.5,0.5);
        glVertex3f(0.0, -0.7, 0.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.25,0.6,0.8);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(-0.7, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 1);

        glColor3f(0.8,0.6,0.25);
        glVertex3f(-0.7, 0.0, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1,0.0,0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.7, 0.0, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.0, -0.7, 0.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(-0.7, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP );
        glColor3f(0.0,0.0,0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.7, 0.0, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.0, -0.7, 0.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(-0.7, 0.0, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(0.2, 0.2, 0.0);
        glVertex3f(0.7, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(0.7, 0.0, 0.0);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(0.2, -0.2, 0.0);
        glVertex3f(0.0, -0.7, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(0.0, -0.7, 0.0);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f(-0.7, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 1);
        glVertex3f(-0.7, 0.0, 0.0);
        glVertex3f(-0.2, 0.2, 0.0);
        glVertex3f(0.0, 0.0, 1);
    glEnd();


    glutSwapBuffers();
}
void reshape( int w, int h)
{
    glViewport(0,0,w,h);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(800,600);

    glutInitWindowPosition(100,100);

    glutCreateWindow("Proiect OpenGL");

    glClearColor(1.0,1.0,0.9,1.0);
    glutDisplayFunc( display );
    glutIdleFunc( display );
    glutReshapeFunc( reshape );

    glutMainLoop();

    return 0;
}
