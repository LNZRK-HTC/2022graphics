#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t)///t的單位是ms
{   ///1000代表1秒,1500代表1.5秒
    printf("鬧鐘%d,我起床了\n",t);///起床
    PlaySound("do.wav",NULL,SND_ASYNC);
    printf("設定下一個鬧鐘\n");
    glutTimerFunc(2000,timer,t+1);///2秒後
    ///printf("設定好鬧鐘,再回去睡\n");
}
void display()
{

}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000,timer,0);
    glutDisplayFunc(display); ///不放Idle
    glutMainLoop();
}
