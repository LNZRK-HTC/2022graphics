#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push備份矩陣
        glTranslatef(0.3,0.2,0);///右上角
        ///就不會一直偷偷移動，因為移動會累積
        glColor3f(1,0,0);///紅色
        glutSolidTeapot(0.3);///0.3實心茶壺
    glPopMatrix();///pop還原矩陣
    glutSwapBuffers();///交換兩倍的buffer
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
