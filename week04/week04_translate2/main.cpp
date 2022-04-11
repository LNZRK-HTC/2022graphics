#include <GL/glut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///push備份矩陣
        glTranslatef(x,y,0);
        glutSolidTeapot(0.3);///0.3實心茶壺
    glPopMatrix();///pop還原矩陣
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);///紅色
    myTeapot(+0.5,+0.5);
    myTeapot(+0.5,-0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(-0.5,+0.5);

    glutSwapBuffers();
 }

int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2倍+3D
    glutCreateWindow("HW2 bonus");///建立視窗

    glutDisplayFunc(display);///用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}


