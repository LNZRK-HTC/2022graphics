#include <GL/glut.h>
#include <stdio.h>///printf()
int mouseX=0,mouseY=0,N=0;///N���I
int mx[100],my[100];///�ΨӰO���A���@�U�n�e�X��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///���⪺

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
    if(state==GLUT_DOWN)///���U�h��(��}�����Ӥ����)
    {
        printf("  glVertex2f((%d-150)/150.0 , -(%d-150)/150.0);\n",x,y);
        N++;
        mx[N-1]=x;my[N-1]=y;
    }
}
int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2��+3D
    glutCreateWindow("week04 mouse");///�إߵ���

    glutDisplayFunc(display);///display���
    glutMouseFunc(mouse);///mouse�ƹ�
    glutMainLoop();///�D�n���j��
    return 0;
}
