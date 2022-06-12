#include<iostream>
#include<graphics.h>

using namespace std;

struct diem
{
	int x;
	int y;
};

void test1 (diem C,diem B,float big0,float small0,float p) //vong while 0 < m < 1
{
	while ( C.x <= B.x)           
	{
		delay(10);
		if (p >= 0 )               //neu p >= 0  
		{
			p += big0;            //p+= 
			C.y ++;			      //tang Cy len 1;
		}
	    else if (p < 0 )         //neu p < 0 
	    {
	    	p += small0;        //
		}
		C.x++;  //chu y 
		
		if (C.x <= B.x)
		putpixel(C.x,C.y,RED);   //hien thi diem C
	}	
}

void test2 (diem C,diem B,float big0,float small0,float p) //vong while truong hop -1 < m < 0
{
	while ( C.x <= B.x)
	{
		delay(10);
		if (p >= 0 )
		{
			p += big0;			
		}
	    else if (p < 0 )
	    {
	    	p += small0;
	    	C.y--;
		}
		
		C.x++;  //chu y
		
		if (C.x <= B.x)
		putpixel(C.x,C.y,RED);
	}	
}

void test3 (diem C,diem B,float big0,float small0,float p)  //vong while truong hop m > 1
{
	while ( C.x <= B.x)
	{
		delay(10);
		if (p >= 0 )
		{
			p += big0;
			C.x++;			
		}
	    else if (p < 0 )
	    {
	    	p += small0;
		}
		C.y++;  //chu y
		
		if (C.x <= B.x)
		putpixel(C.x,C.y,RED);
	}	
}

void test4 (diem C,diem B,float big0,float small0,float p)  //vong while truong hop m < -1
{
	while ( C.x <= B.x)
	{
		delay(10);
		
		if (p >= 0 )
		{
			p += big0;
					
		}
	    else if (p < 0 )
	    {
	    	p += small0;
	    	C.x--;
		}
		C.y++;  //chu y
		
		if (C.x <= B.x)
		putpixel(C.x,C.y,RED);
	}	
}


void bresenham (diem A,diem B)
{
		
	//tinh gia tri Dy va Dx va m
	float dy =(B.y-A.y);
	float dx =(B.x-A.x);
	float m  = (float)dy/dx;
	
     float small0;  // be hon 0 - day la gia tri cong vao khi < 0
     float big0;    // lon hon 0 - day la gia tri cong vao khi > 0
     float p;       //khai bao p
    
    //diem C la -diem ke tiep khi t hien thuat toan
	diem C;    //xay dung diem C la - diem hien thi khi thuc hien thuat toan
	C.x = A.x;
	C.y = A.y;
	putpixel(A.x,A.y,BLUE); //hien thi diem C
    
    //liet ke cac truong hop
    if (m > 0 && m <= 1)   // truong hop 0 < m <= 1
    {
    	small0 = 2*dy;       //khoi tao bien small = ..
	    big0 = 2*(dy-dx);    // khoi tao big = ....
	    p = 2*dy-dx;          //ham p co dang .... 
	    test1 (C,B,big0,small0,p);  //vong while truong hop:  0 < m <=1 
	}
	if (m >= -1 && m <0)   // truong hop -1 <= m < 0
	{
		p = 2*dy + dx;                 //tuong tu 
		small0 = 2*(dy+dx);
		big0 = 2*dy;
		test2 (C,B,big0,small0,p);
	}
	
	if (m > 1)              // truong hop m > 1 => khi do
	{
		p = 2*dx - dy;     // p = ...
		big0 = 2*(dx-dy);  // big0 = ...
		small0 = 2*dx;           //...
		test3 (C,B,big0,small0,p);   //ham chay vong lap while 
	}
	
	if ( m < -1)             //  m < -1
	{
		p =2*dx +dy;                    //tuong tu ... 
		small0 = 2*dx + 2*dy;
		big0 = 2*dx;
		test4 (C,B,big0,small0,p);
	}		
}

int main ()
{
	int gd,gm=VGA; gd=DETECT; //khoi tao ham do hoa
    initgraph(&gd,&gm,NULL);  //thiet lap cau hinh
    setbkcolor(WHITE);

    //khai bao a,b
	diem A,B;
    
	
	//nhap diem A va B
	cout<<"nhap A: "<<endl<<"x= ";
	cin>>A.x;
	cout<<endl<<"y= ";
	cin>>A.y;
	cout<<endl<<"nhap B: "<<endl<<"x= ";
	cin>>B.x;
	cout<<endl<<"y= ";
	cin>>B.y;

	//chay ham bresenham
	bresenham(A,B);
		
	
	Sleep(3000); //ham dung man hinh sau khi chay
	return 0;
}
