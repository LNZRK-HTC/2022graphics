#include <GL/glut.h>
#include <stdio.h>///printf()
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();///�洫�⭿��buffer
 }
void mouse(int button,int state,int x,int y)
{
    printf("%d %d %d %d\n",button,state,x,y);
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
