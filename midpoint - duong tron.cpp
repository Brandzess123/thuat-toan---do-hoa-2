#include<iostream>
#include<graphics.h>

using namespace std;

struct diem
{
	float x;
	float y;
};

void diemdx (diem &B, int x ,int y,float R)  //hien thi 8 diem doi xung + su dung phep tinh tien OI
{
	
	putpixel(B.x + x,B.y + y,BLUE);  //(x,y)
    putpixel(B.y + x,B.x + y,BLUE);  //(y,x)
	putpixel(B.y + x,-B.x + y,BLUE);  //(y,-x)
	putpixel(B.x + x,-B.y + y,BLUE);  //(x,-y)
	putpixel(-B.x + x,-B.y + y,BLUE);  //(-x,-y)
	putpixel(-B.y + x,-B.x + y,BLUE);  //(-y,-x)
	putpixel(-B.y + x,B.x + y,BLUE);   //(-y,x)
	putpixel(-B.x + x,B.y + y,BLUE);   //(-x,y)	
}

void midpoint (diem A,int R)
{
	diem B; //tao diem B(0,R) ->dung de ve duong tron tam 0(0,0)
	B.x = 0;                      
	B.y = R;
	
	float P = (float)5/4-R;     //tinh P
	diemdx(B,A.x,A.y,R);        //hien thi 
	
	while (B.x < B.y)    //chay vong while 
	{
	    delay(10);  
	    
		if (P < 0)   //neu p < 0
	    {	 
	    	P+=2*B.x+3;  //p + 2x +3        
		}
		
		else if ( P > 0)  //neu p > 0
		{
			B.y--;	            //y--;
			P+=2*(B.x-B.y)+5;  //p + 2(x-y)+5
		}
		
		B.x++;                 //x++;
		diemdx(B,A.x,A.y,R);   //hien thi 8 diem
	}
	
}

main ()
{
	int gd,gm=VGA; gd=DETECT; // khoi tao ham do hoa
    initgraph(&gd,&gm,NULL); // cai dat cau hinh  
    setbkcolor(WHITE);       //
    
	//khai bao gia tri
	diem A;  //tam A(x,y)
	
	//ham nhap gia tri
	cout<<"nhap tam A: ";
	cout<<endl<<"nhap x: ";
	cin>>A.x; 
	cout<<endl<<"nhap y: ";
	cin>>A.y;
	cout<<endl<<"nhap ban kinh R: ";
	float R ;
	cin>>R;
	
	//thuc hien thuat toan
	midpoint(A,R);
	
	
    Sleep(3000);  //ham dung man hinh
    return 0;
}
