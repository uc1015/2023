#include <GL/glut.h>
float angle = 0;
void myCube()
{

    glPushMatrix();///²�Ƶ{��
        glScalef(0.5, 0.2, 0.2);
        glutSolidCube(1);
    glPopMatrix();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0.5,0.5,0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.45, 0, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();


	glutSwapBuffers();
	angle++;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week04");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
