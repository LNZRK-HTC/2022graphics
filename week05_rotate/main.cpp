#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push�ƥ��x�}
        glRotatef(180,0,0,1);///��180��
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop�٭�x�}
    glutSwapBuffers();
 }

int main(int argc,char**argv)
{///�i����main�禡
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
