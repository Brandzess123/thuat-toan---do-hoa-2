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
	float m  =(float) abs (dy)/ abs(dx);
	
	//diem C la -diem tang dan khi thuc hien thuat toan 
	diem C;
	C.x = A.x;
	C.y = A.y;
	putpixel(A.x,A.y,BLUE);   //hien thi diem C
	
    //khoi tao gia tri count x va count y trong truong hop duong thang hoac duong ngang
	int cx = 1; //countx - x+= cx
	int cy = 1; //county - y+= cy
	
	if (dx < 0)  //trong truong hop dx,dy co gia tri < 0
	cx = -1;    
	else if (dy < 0)
	cy = -1;
	
	if (A.x == B.x)   //truong hop ve duong thang dung
    {
        while (C.y != B.y)
        {
            delay(10);  //
            C.y += cy;  //tang gia tri CY
            putpixel(C.x, C.y, BLUE); //hien thi diem C
        }   
    }
    else if (A.y == B.y)  //truong hop ve duong ngang
    {
        while (C.x != B.x)
        {
            delay(10);
            C.x += cx;   //tang gia tri CX
            putpixel(C.x, C.y, BLUE);  //hien thi diem C
        }
    }
    
    else if (A.x != B.x && A.y != B.y)//truong hop ve duong xien
	{
		cx = 1;  //khoi tao lai gia tri count x
        cy = m;  //khoi tao lai gia tri count y
        
		if (dx < 0)    //truong hop dx < 0
		cx =-1;        //count x = -1
		if (dy < 0)    //truong hop dx > 0
		cy = -m;       //count y = - m
	    
		while (C.x < B.x)      
	    {
		    if ( m <= 1)          //truong hop m < 1
		    {
			    delay(10);
			    C.x+= cx;             //x++;
		        C.y+= cy;             //y = y + m;
		    
		        putpixel(C.x,round(C.y), BLUE);  //hien thi diem	
		    }
		
		    else if (m > 1)     //truong hop m > 1
		    {
			    delay(10);
			    C.y+=cx;               //y++;
			    C.x+=(float)1/cy;          //x = x +1/m
			
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
