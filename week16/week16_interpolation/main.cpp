#include <GL/glut.h>
#include <stdio.h>///為了printf,fopen,fclose...
float angle[20], oldX=0;
int angleID=0;///0:第0個關節, 1:第1個關節...
FILE * fout=NULL, * fin=NULL;
void myWrite()
{
    if(fout==NULL) fout=fopen("file.txt","w+");
    for(int i=0; i<20; i++)
    {
        printf(     "%.2f", angle[i]);
        fprintf(fout, "%.2f ", angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
float NewAngle[20], OldAngle[20];
void myRead()
{

    if(fout!=NULL)
    {
      fclose(fout);///關掉還在讀的檔案
      fout=NULL;
    }

   if(fin==NULL) fin=fopen("file.txt","r");

   for(int i=0; i<20; i++){
        OldAngle[i]=NewAngle[i];
        fscanf(fin, "%f", &NewAngle[i]);
        ///fscanf(fin, "%f", &angle[i]);

   }
   glutPostRedisplay();///重畫畫面
}
void myInterpolate(float alpha){
    for(int i=0; i<20; i++){
        angle[i]=alpha*NewAngle[i]+(1-alpha)*OldAngle[i];
        printf("%.2f", angle[i]);
    }
    printf("\n");
    glutPostRedisplay();
}
///float alpha=0;
void timer(int t)
{
    float alpha=(t%100)/100.0;///算出alpha
    if(t%100==0) myRead();///遇到100整除時，做新舊交替
    myInterpolate(alpha);
    glutTimerFunc(33, timer, t+1);
}
void keyboard(unsigned char key, int x, int y)
{///鍵盤數字鍵決定旋轉部位

    if(key=='p')
    {
        myRead();///先讀一行
        glutTimerFunc(0, timer, 0);///馬上開始播動畫
        ///myInterpolate(alpha);
        ///alpha=(alpha+0.01);
        ///if(alpha>1) alpha=alpha-1;
    }

    if(key=='r') myRead();
    if(key=='s') myWrite();
    if(key=='0') angleID=0;///預設0
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button, int state, int x, int y)
{
    oldX=x;
}
void motion(int x, int y)
{
    angle[angleID]+=(x-oldX);
    ///myWrite();
    oldX=x;
    glutPostRedisplay();///重畫畫面
}
void display()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.2);///身體瘦身(對比1)

    glPushMatrix();///右半邊
        glTranslatef(0.3, 0.5, 0);
        glRotatef(angle[0], 0, 0, 1);///旋轉
        glTranslatef(-0.3, -0.4, 0);///旋轉中心放正中心
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///把下手肘掛在關節上
            glRotatef(angle[1], 0, 0, 1);///旋轉
            glTranslatef(-0.8, -0.4, 0);///把下手肘的旋轉中心放正中心
            glColor3f(0, 1, 0);
            glRectf(0.8, 0.5, 1.1, 0.3);///右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3, 0.5, 0);
        glRotatef(angle[2], 0, 0, 1);///旋轉
        glTranslatef(+0.3, -0.4, 0);///旋轉中心放正中心
        glColor3f(1, 0, 0);
        glRectf(-0.3, 0.5, -0.8, 0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///把下手肘掛在關節上
            glRotatef(angle[3], 0, 0, 1);///旋轉
            glTranslatef(+0.8, -0.4, 0);///把下手肘的旋轉中心放正中心
            glColor3f(0, 1, 0);
            glRectf(-0.8, 0.5, -1.1, 0.3);///左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH );
    //glutInitWindowSize(600, 600);
    glutCreateWindow("Week16 interpolation");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
