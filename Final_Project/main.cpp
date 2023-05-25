///Final_Project ���᳣�ΦP�@�ӵ{��,�Ӷi�� Final Project
#include <stdio.h> ///�n�ɮת�Input/Output
#include <GL/glut.h>
#include "glm.h" ///week13_step02-2
///week13_step02-2 �A�� glm.cpp �b���� Add files �[�i�h
GLMmodel * head = NULL;///week13_step02-2
GLMmodel * body = NULL;///week13_step02-2
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,1,1,1}; ///week14_step03_1 ���q�X�� ///week13_step03-1
int ID = 3; ///week14_step03_1 �]�w���` ID
float teapotX = 0, teapotY = 0;
float angle = 0;
FILE * fout = NULL;///step02-1
FILE * fin = NULL;///step02-2
void keyboard(unsigned char key, int x, int y) {///week13_step03-1
    if(key=='0') ID = 0; ///week14_step03_1 ///show[0] = ! show[0];///week13_step03-1
    if(key=='1') ID = 1; ///week14_step03_1 ///show[1] = ! show[1];///week13_step03-1
    if(key=='2') ID = 2; ///week14_step03_1 ///show[2] = ! show[2];///week13_step03-1
    if(key=='3') ID = 3; ///week14_step03_1 ///show[3] = ! show[3];///week13_step03-1
    glutPostRedisplay();///week13_step03-1
}///week13_step03-1
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL){///week13_step02-2
        head = glmReadOBJ("model/head.obj");///week13_step02-2
        body = glmReadOBJ("model/body.obj");
        uparmR = glmReadOBJ("model/uparmR.obj");
        lowarmR = glmReadOBJ("model/lowarmR.obj");
        ///glmUnitize(head); ///week13_step02-2 ����|��
    }///week13_step02-2
    glPushMatrix();
        glScalef(0.3, 0.3, 0.3);///week13_step02-3
        glPushMatrix();///week13_step03-2
            ///glTranslatef(teapotX, teapotY, 0); ///week13_step03-2

            if(ID==0) glColor3f(1,0,0);///week14_step03_1 �q����
            else glColor3f(1,1,1);///week14_step03_1 �q�զ�
            if(show[0]) glmDraw(head, GLM_MATERIAL);///week13_step02-3
        glPopMatrix();///week13_step03-2

        if(ID==1) glColor3f(1,0,0);///week14_step03_1 �q����
        else glColor3f(1,1,1);///week14_step03_1 �q�զ�
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13_step02-2

        glPushMatrix(); ///week14_step03_2
            ///glTranslatef(teapotX, teapotY, 0); ///week14_step03_2 �n�]�w TRT
            glTranslatef(-1.360000, +0.360000, 0); ///week14_step03_2
            glRotatef(angle, 0, 0, 1); ///week14_step03_2
            glTranslatef(1.360000, -0.360000, 0); ///week14_step03_2

            if(ID==2) glColor3f(1,0,0);///week14_step03_1 �q����
            else glColor3f(1,1,1);///week14_step03_1 �q�զ�
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///week13_step02-3

            glPushMatrix();  ///week14_step03_2
                ///glTranslatef(teapotX, teapotY, 0); ///week14_step03_2 �n�]�w TRT
                glTranslatef(-1.959999, +0.080000, 0);
                glRotatef(angle, 0, 0, 1);
                glTranslatef(1.959999, -0.080000, 0);

                if(ID==3) glColor3f(1,0,0);///week14_step03_1 �q����
                else glColor3f(1,1,1);///week14_step03_1 �q�զ�
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///week13_step02-3
            glPopMatrix();  ///week14_step03_2
        glPopMatrix(); ///week14_step03_2


    glPopMatrix();
    glColor3f(0,1,0);  ///week14_step03_2 ��⪺
    glutSolidTeapot( 0.02 ); ///week14_step03_2
    glutSwapBuffers();
}
int oldX=0, oldY=0; ///week13_step03-2
void mouse(int button, int state, int x, int y) {
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y) { ///week13_step03-2
    teapotX += (x - oldX)/150.0*3;
    teapotY -= (y - oldY)/150.0*3;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY); ///week14_step03_2
    angle += x-oldX; ///week14_step03_2
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutMotionFunc(motion); ///week13_step03-2
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
