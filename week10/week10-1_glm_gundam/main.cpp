///Week08-2_glm_model_texture
///��d�ҥ��R,�K�W Week08-1_glm_model
///�A���X�W�g�� myTexture��(����)�{��
///�O�o�A�� opencv2.1, �A�t�W�g��3�өG�y �ؿ��B�ؿ��Bcv210 cxcore210 highgui210
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include "glm.h" ///step02-1 �� source.zip�̪� glm.h ��b�P�ؿ���
///step03-1�]�n��step02-1�� glm.h�]�ǳƦn
///glm.cpp �]�n�[��A���{���ؿ���
GLMmodel * pmodel = NULL; ///step02-1 �ҫ�������,�@�}�lNULL�Ū�
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ///step03-1����e,�T�{Gundam.obj Gundam.mtl ���bfreeglut��bin
    if(pmodel==NULL){ ///�Ĥ@���|�i�� step02-1
        pmodel = glmReadOBJ("Gundam.obj");///�ɦW�ӧA���ɦW step02-1
        glmUnitize(pmodel);///step02-2 �Y��Unit���j�p(-1..+1)
        glmFacetNormals(pmodel);///step03-1
        glmVertexNormals(pmodel, 90);///step03-1
    }
    if(phand==NULL){
        phand = glmReadOBJ("hand_Left.obj");
        glmUnitize(phand);
        glmFacetNormals(phand);
        glmVertexNormals(phand, 90);
    }
    glutSolidSphere(0.1,30,30);
    glPushMatrix();
        glRotatef(angle, 0,1,0);
        glTranslatef(0,-0.1,0);
        glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE); ///step02-1
    glPopMatrix();

    ///glutSolidTeapot( 0.3 );
    angle++;
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08");

    myTexture("Diffuse.jpg");///step03-2���ɤ]�O��freeglut��bin
    glEnable(GL_DEPTH_TEST);///�U�g�A��3D��glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
