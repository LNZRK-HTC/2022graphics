#include <GL/glut.h>
#include <stdio.h>
float x=250,y=250,z=0,scale=1.0,angle=0.0,oldx,oldy;
int now=1;///1.����,2.����,3.�Y��
void display()
 {
    glClearColor( 0.5, 0.5 , 0.5 , 1 );///�Ψ�Clear����m�AR,G,B,A Alpha�S�Ψ�
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push�ƥ��x�}
        glTranslatef( (x-250)/250.0 , -(y-250)/250.0 , z );///���ʡAMaya����̭���:w
        glRotatef( angle , 0 , 0 , 1);///����AMaya����̭���:e
        glScalef( scale , scale ,scale );///�Y��AMaya����̭���:r
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop�٭�x�}
    glutSwapBuffers();
 }
void keyboard(unsigned char key, int x, int y)
{
    ///printf("�{�b���U:%c �y�Цb:%d %d\n",key,x,y);
    if( key=='w' || key=='W')now=1;///���ʡA����g����
    if( key=='e' || key=='E')now=2;///����
    if( key=='r' || key=='R')now=3;///�Y��
}
void mouse(int button, int state,int mousex,int mousey)
{
    oldx = mousex;  oldy = mousey;
}
void motion(int mousex,int mousey)
{
    if(now==1)
    {
        x += (mousex-oldx);///x���ʪ��y��
        y += (mousey-oldy);///y���ʪ��y��
    }
    else if(now==2)
    {
        angle += (mousex-oldx);
    }
    else if(now==3)
    {
        if(mousex>oldx) scale = scale * 1.01;///�ƹ��V�k���ʡA�����N�|��j
        if(mousex<oldx) scale = scale * 0.99;///�ƹ��V�����ʡA�������N�|�Y�p
    }
    oldx = mousex;  oldy = mousey;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);///�������j�p
    glutCreateWindow("Week06 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
