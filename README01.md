第一週小葉老師教學筆記  
https://github.com/jsyeh/2022graphics  

我的筆記  

week01  
https://2022graphicsb.blogspot.com/2022/02/tc-week01.html

week02  
https://2022graphicsb.blogspot.com/2022/03/tc-week03.html

第二周範例網址
https://jsyeh.org/3dcg10/

建 GitHub 倉庫  
1. 登入 GitHub  
2. 建 2022graphics 的 repo倉庫  
2.1. 要設定 Public  
2.2. 要 README.md  
2.3. Add .gitignore 設定 C++  

3. 利用 Git指令下載  
3.0. 安裝 Git for Windows  
3.1. 開啟 Git Bash  
3.2. cd desktop 進入桌面  
3.2. git clone https://你的倉庫網址  
3.3. 查看 桌面,多了 2022graphics 目錄  

3.4. 把今天的程式 複製到 剛剛目錄  

4. 把修改的資料, 推送到雲端  
4.1. cd 2022graphics 進入你的倉庫  
4.2. git status 看你的狀況(紅的,多了目錄)  
4.3. git add . 把檔案加進帳冊  
4.4. git status 再看一次(綠的)  

這裡要加入  
git config --global user.email "你的email"  
git config --global user.name "你的名"  
git commit -m "上傳第1週"  

4.5. git push 推送到雲端, BUT要登入  
4.6. 在 Chrome記得再登入哦  

第二周程式碼
```c++
#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);///黃色
    glutSolidTeapot(0.3);///0.3實心茶壺

    glutSwapBuffers();///交換兩倍的buffer
 }

int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2倍+3D
    glutCreateWindow("week03的視窗");///建立視窗

    glutDisplayFunc(display);///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}

```

```c++
#include <GL/glut.h>
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);///黃色

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);   glVertex2f(0.0f,   1.0f);
    glColor3f(0.0f,1.0f,0.0f);   glVertex2f(0.87f,  -0.5f);
    glColor3f(0.0f,0.0f,1.0f);   glVertex2f(-0.87f, -0.5f);

    glEnd();
    glutSwapBuffers();///交換兩倍的buffer
 }

int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///2倍+3D
    glutCreateWindow("week03的彩色視窗");///建立視窗

    glutDisplayFunc(display);///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```
