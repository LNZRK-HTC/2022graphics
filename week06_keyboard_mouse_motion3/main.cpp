#include <GL/glut.h>
#include <stdio.h>
float x=0,y=0,z=0,scale=1.0,oldx,oldy;
int now=1;///1.移動,2.旋轉,3.縮放
void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///push備份矩陣
        glTranslatef( (x-150)/150.0 , -(y-150)/150.0 , z );///移動，Maya按鍵裡面的:w
        ///glRotatef( angle , 0 , 0 , 1);///旋轉
        glScalef( scale , scale ,scale );///縮放，Maya按鍵裡面的:r
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop還原矩陣
    glutSwapBuffers();
 }
void keyboard(unsigned char key, int x, int y)
{
    ///printf("現在按下:%c 座標在:%d %d\n",key,x,y);
    if( key=='w' || key=='W')now=1;///移動，不能寫中文
    if( key=='e' || key=='E')now=2;///旋轉
    if( key=='r' || key=='R')now=3;///縮放
}
void mouse(int button, int state,int mousex,int mousey)
{
    oldx = mousex;  oldy = mousey;
}
void motion(int mousex,int mousey)
{

    if(now==1)
    {
        x += (mousex-oldx);///x移動的座標
        y += (mousey-oldy);///y移動的座標
    }
    else if(now==3)
    {
        if(mousex>oldx) scale = scale * 1.01;///滑鼠向右移動，茶壺就會放大
        if(mousex<oldx) scale = scale * 0.99;///滑鼠向左移動，除茶壺就會縮小
    }
    oldx = mousex;  oldy = mousey;
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week06 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
