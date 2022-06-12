#include<iostream>

using namespace std;

struct diem
{
	int x;
	int y;
};

void nhapdiem (diem &A)
{
	cout<<endl<<"nhap x: ";
	cin>>A.x;
	cout<<endl<<"nhap y: ";
	cin>>A.y;
}

void check (diem A,diem min,diem max,int mang[4])
{
	if (A.x < min.x)
	mang[3] = 1;
	else if (A.x >= min.x)
	mang[3] = 0;
	
	if (A.x > max.x)
    mang[2] = 1;
    else if (A.x <= max.x)
    mang[2] = 0;
    
    if (A.y < min.y)
    mang[1] = 1;
    else if (A.y >= min.y)
    mang[1] = 0;
    
    if (A.y > max.y)
    mang[0] =1;
    else if (A.y <= max.y)
    mang[0] = 0;
}   

void kiemtra (int mang1[4],diem A,diem check,diem check2 ,diem min,diem max)
{
	if (mang1[3] == 1)
	{
		A.x = min.x;
	
		
	}
	if (mang1[2] == 1)
	A.x =max.x;
	if (mang1[1] == 1)
	A.y = max.y;
	if (mang1[0] == 1)
	A.y = min.y;
		
}


void xuat (int mang[4])
{
	for (int i = 0; i < 4; i++ )
	cout<<mang[i];
}
main ()
{
	diem min,max;
	cout<<"nhap min va max khung cua so: ";
	cout<<endl<<"nhap min: ";
	nhapdiem(min);
	cout<<endl<<"nhap max: ";
	nhapdiem(max);
	
	
	
	diem A,B;  // A min B max
	cout<<endl<<endl<<"nhap toa do A va B: ";
	cout<<endl<<"nhap diem A: ";
	nhapdiem(A);
	cout<<endl<<"nhap diem B: ";
	nhapdiem(B);
	
	int mang1[4];
	int mang2[4];
	check(A,min,max,mang1);
	check(B,min,max,mang2);
	
	cout<<endl<<"4 bit a: ";
	xuat(mang1);
	
	cout<<endl<<"4 bit b: ";
	xuat(mang2);
	
	
	int and1 = 0;
	int or1 = 0;
	int a;
	for (int i = 0; i < 4; i++ )
	{
		if (mang1[i] == 0 && mang2[i] == 0) //phep or
		{
		    a = 10;
	    }
		else 
		{
		    or1 = 1;
	    }
	    
		cout<<endl;
		if (mang1[i] == 1 && mang2[i] == 1) //phep and
	    {
	    	
	    	and1 = 1;
		}
		else
		{
			 a = 10 ;
		}
	}
	
	if (or1 == 0)
	cout<<endl<<"A va B nam trong mat phang: ";
	if (or1 == 1 && and1 == 1)
	cout<<endl<<"A va B nam ngoai mat phang - nam ngoai";
	if (or1 == 1 && and1 == 0)
	cout<<endl<<"Xen tia: ";
	
	
}
