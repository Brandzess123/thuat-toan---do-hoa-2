//# s? d?ng thu?t toán Breshenham d? v? du?ng th?ng
#include <graphics.h>
#include<iostream>

using namespace std;

int colorRedBlue = BLUE;
 
void lineBresenham(int x1, int y1, int x2, int y2){
    int x, y, Dx, Dy, p;
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    p = 2*Dy - Dx;
    x = x1;
    y = y1;
 
    int x_unit = 1, y_unit = 1;
 
    //#xét tru?ng h?p d? cho y_unit và x_unit d? v? tang lên hay gi?m xu?ng
    if (x2 - x1 < 0)
        x_unit = -x_unit;
    if (y2 - y1 < 0)
        y_unit = -y_unit;
 
    if (x1 == x2)   // tru?ng h?p v? du?ng th?ng d?ng
    {
        while (y != y2+1)
        {
            delay(10);
            y += y_unit;
            putpixel(x, y, colorRedBlue);
        }
    }
 
    else if (y1 == y2)  // tru?ng h?p v? du?ng ngang
    {
        while (x != x2+1)
        {
            delay(10);
            x += x_unit;
            putpixel(x, y, colorRedBlue);
        }
    }
            // tru?ng h?p v? các du?ng xiên
    else{          
        putpixel(x, y, colorRedBlue);
        while(x != x2){
            delay(10);
            if (p<0) p += 2*Dy;
            else{
                p += 2*(Dy-Dx);
                y += y_unit;
            }
            x += x_unit;
            putpixel(x, y, colorRedBlue);
        }
    }
}
 
int main(){
    int gd,gm=VGA; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    setbkcolor(WHITE);
 
    lineBresenham(200,200,50,60);
    lineBresenham(200,200,50,200);
 
    lineBresenham(200,200,50,300);
    lineBresenham(200,200,200,400);
 
    lineBresenham(200,200,300,400);
    lineBresenham(200,200,300,200);
 
    lineBresenham(200,200,400,60);
    lineBresenham(200,200,200,60);
    getchar();
    return 0;
}
