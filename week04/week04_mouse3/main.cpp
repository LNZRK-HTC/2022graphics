#include <GL/glut.h>
#include <stdio.h>///printf()
int mouseX=0,mouseY=0,N=0;///N個點
int mx[100],my[100];///用來記錄，等一下要畫出來
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色的

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        glVertex2f( (mx[i]-150)/150.0,   -(my[i]-150)/150.0 );
    }
    glEnd();

    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    mouseX=x;mouseY=y;
    if(state==GLUT_DOWN)///按下去的(放開的那個不算數)
    {
        printf("  glVertex2f((%d-150)/150.0 , -(%d-150)/150.0);\n",x,y);
        N++;
        mx[N-1]=x;my[N-1]=y;
    }
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2倍+3D
    glutCreateWindow("week04 mouse");///建立視窗

    glutDisplayFunc(display);///display顯示
    glutMouseFunc(mouse);///mouse滑鼠
    glutMainLoop();///主要的迴圈
    return 0;
}
