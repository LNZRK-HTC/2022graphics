#include <GL/glut.h>
#include <stdio.h>///printf()
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();///交換兩倍的buffer
 }
void mouse(int button,int state,int x,int y)
{
    printf("%d %d %d %d\n",button,state,x,y);
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2倍+3D
    glutCreateWindow("week04 mouse");///建立視窗

    glutDisplayFunc(display);///用來畫圖的函式
    glutMouseFunc(mouse);///mouse滑鼠
    glutMainLoop();///主要的迴圈
    return 0;
}
