#include <GL/glut.h>
#include <stdio.h>
float x=0,y=0,z=0,scale=1.0,oldx,oldy;
void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push�ƥ��x�}
        ///glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z );///���ʡAMaya����̭���:w
        ///glRotatef( angle , 0 , 0 , 1);///����
        glScalef( scale , scale ,scale );///�Y��AMaya����̭���:r
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop�٭�x�}
    glutSwapBuffers();
 }
void keyboard(unsigned char key, int x, int y)
{
    printf("�{�b���U:%c �y�Цb:%d %d\n",key,x,y);
}
void mouse(int button, int state,int mousex,int mousey)
{
    oldx = mousex;
    oldy = mousey;
}
void motion(int mousex,int mousey)
{
    if(mousex>oldx) scale = scale * 1.01;///�ƹ��V�k���ʡA�����N�|��j
    if(mousex<oldx) scale = scale * 0.99;///�ƹ��V�����ʡA�������N�|�Y�p

    ///x += (mousex-oldx);
    ///y += (mousey-oldy);
    oldx = mousex;
    oldy = mousey;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week06 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
