#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

//tao cau truc diem
struct diem
{
	float x;
	float y;
};

void DDA (diem A,diem B)
{
	//tinh gia tri Dy va Dx
	float dy =(B.y-A.y);
	float dx =(B.x-A.x);
	float m  = abs(dy)/abs(dx);
	
	//diem C la -diem tang dan khi thuc hien thuat toan 
	diem C;
	C.x = A.x;
	C.y = A.y;
	putpixel(A.x,A.y,BLUE);   //hien thi diem C
	
    
	
	if (A.x == B.x)   //truong hop ve duong thang dung
    {
        while (C.y != B.y)
        {
            delay(10);  //
            C.y += 1;  //tang gia tri CY
            putpixel(C.x, C.y, BLUE); //hien thi diem C
        }   
    }
    else if (A.y == B.y)  //truong hop ve duong ngang
    {
        while (C.x != B.x)
        {
            delay(10);
            C.x += 1;   //tang gia tri CX
            putpixel(C.x, C.y, BLUE);  //hien thi diem C
        }
    }
    
    else if (A.x != B.x && A.y != B.y)//truong hop ve duong xien
	{
	    
		while (C.x < B.x)      
	    {
		    if ( m <= 1)          //truong hop m < 1
		    {
			    delay(10);
			    C.x+= 1;             //x++;
		        C.y+= (float)dy/dx;             //y = y + m;
		    
		        putpixel(C.x,round(C.y), BLUE);  //hien thi diem	
		    }
		
		    else if (m > 1)     //truong hop m > 1
		    {
			    delay(10);
			    C.y+=1;               //y++;
			    C.x+= (float)dx/dy;          //x = x +1/m
			
			    putpixel(round(C.x),C.y, BLUE);    //hien thi diem
		    }	
	    }
	}
	
}


main ()
{
	//khoi tao do hoa va thiet lap cau hinh
	int gd,gm=VGA; gd=DETECT;  
    initgraph(&gd,&gm,NULL); 
    setbkcolor(WHITE);
    
	//khai bao a,b
	diem A,B;
	
	//nhap 2 diem A va B 
	cout<<"nhap A: "<<endl<<"x= ";
	cin>>A.x;
	cout<<endl<<"y= ";
	cin>>A.y;
	cout<<endl<<"nhap B: "<<endl<<"x= ";
	cin>>B.x;
	cout<<endl<<"y= ";
	cin>>B.y;
	
    //thuc hien thuat toan
	DDA(A,B);	
    
		
	Sleep(3000); //ham dung man hinh
	getchar();
	return 0;
}
