#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t)///t�����Oms
{   ///1000�N��1��,1500�N��1.5��
    printf("�x��%d,�ڰ_�ɤF\n",t);///�_��
    PlaySound("do.wav",NULL,SND_ASYNC);
    printf("�]�w�U�@�Ӿx��\n");
    glutTimerFunc(2000,timer,t+1);///2���
    ///printf("�]�w�n�x��,�A�^�h��\n");
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
    glutDisplayFunc(display); ///����Idle
    glutMainLoop();
}
