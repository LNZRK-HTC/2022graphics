#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage * img = cvLoadImage("earth.jpg");///�h��a��
    cvShowImage("img",img);///�bimg������img����
    cvWaitKey(0);///�����N���~��
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
 }
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week09 texture");

    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
    return 0;
}
