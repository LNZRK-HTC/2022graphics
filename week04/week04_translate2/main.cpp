#include <GL/glut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///push�ƥ��x�}
        glTranslatef(x,y,0);
        glutSolidTeapot(0.3);///0.3��߯���
    glPopMatrix();///pop�٭�x�}
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);///����
    myTeapot(+0.5,+0.5);
    myTeapot(+0.5,-0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(-0.5,+0.5);

    glutSwapBuffers();
 }

int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2��+3D
    glutCreateWindow("HW2 bonus");///�إߵ���

    glutDisplayFunc(display);///�Ψӵe�Ϫ��禡

    glutMainLoop();///�D�n���j��
    return 0;
}


