///week15-2 SND_SYNC要等待同步 VS.
///SND_ASYNC不用等待、不同步
#include <windows.h>
#include <stdio.h>///printf()
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("07042111.wav",NULL,SND_ASYNC);
    printf("現在在PlaySiund()後\n");
    int N;
    scanf("%d",&N);///等你輸入數字
}
