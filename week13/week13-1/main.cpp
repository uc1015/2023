#include <stdio.h>

#include <GL/glut.h>

float teapotX=0,teapotY=0;

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

        glTranslatef(teapotX, teapotY, 0);

        glutSolidTeapot(0.3);

    glPopMatrix();

    glutSwapBuffers();

}

void mouse(int button, int state, int x, int y)

{

    teapotX=(x-150)/150.0;

    teapotY=(150-y)/150.0;

    display();

}

int main(int argc,char** argv)

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week12");



    glutDisplayFunc(display);

    glutMouseFunc(mouse);



    glutMainLoop();

}
