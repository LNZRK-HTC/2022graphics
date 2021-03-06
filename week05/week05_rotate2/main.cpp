#include <GL/glut.h>
float angle=0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push備份矩陣
        glRotatef(angle,0,0,1);///轉180度
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop還原矩陣
    glutSwapBuffers();
 }
void motion(int x ,int y)
{
    angle=x;
    display();
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
