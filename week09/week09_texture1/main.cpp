#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage * img = cvLoadImage("earth.jpg");///去找地圖
    cvShowImage("img",img);///在img視窗放img的圖
    cvWaitKey(0);///等任意鍵繼續
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
