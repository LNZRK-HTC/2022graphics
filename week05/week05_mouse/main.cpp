#include <stdio.h>
#include <GL/glut.h>
int N=0;
int x[1000],y[1000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)///�ΰj��eN�ӳ��I
    {
        glVertex2f((x[i]-150)/150.0,-(y[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int butten, int state, int mouseX, int mouseY)
{
    if(state==GLUT_DOWN)///�p�G���Umouse
    {
        N++;///�N�h�@�ӳ��I
        x[N-1]=mouseX;///�̫�@�ӷs�W�����I��x�y��
        y[N-1]=mouseY;///�̫�@�ӷs�W�����I��y�y��
        printf("�{�b���U�ƹ��A�o��s���y�� %d %d\n",x[N-1],y[N-1]);
    }
    display;
}
int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 �Ʋ� mouse");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

