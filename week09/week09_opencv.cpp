#include <opencv/highgui.h>
int main()
{
    ///Ipl�OIntel performance library���Y�g
    IplImage * img = cvLoadImage("week09.jpg");///Ū��
    cvShowImage("week09",img);///�q��
    cvWaitKey(0);///�����N���~��

}

