#include <GL/glut.h>
#include <stdio.h>///printf()
int mouseX=0,mouseY=0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///���⪺
    glPushMatrix();///�f�Z:��@�b�B���@�b�By�٭˹L��
        glTranslatef((mouseX-150)/150.0,-(mouseY-150)/150.0,0);
        glutSolidTeapot(0.3);///����
    glPopMatrix();
    glutSwapBuffers();
 }
void mouse(int button,int state,int x,int y)
{
    //printf("%d %d %d %d\n",button,state,x,y);
    mouseX=x; mouseY=y;
}
int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2��+3D
    glutCreateWindow("week04 mouse");///�إߵ���

    glutDisplayFunc(display);///�Ψӵe�Ϫ��禡
    glutMouseFunc(mouse);///mouse�ƹ�
    glutMainLoop();///�D�n���j��
    return 0;
}
