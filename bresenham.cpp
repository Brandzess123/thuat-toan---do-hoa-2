#include<iostream>
#include<iomanip>

using namespace std;

struct diem
{
	int x;
	int y;
};


void test1 (diem C,diem B,float big0,float small0,float p) //vong while 0 < m < 1
{
	int dem =1;

	cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
	while ( C.x <= B.x)           
	{
			dem++;
	
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
		cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
		
	}	
}

void test2 (diem C,diem B,float big0,float small0,float p) //vong while truong hop -1 < m < 0
{
	int dem =1;
	
	cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
	while ( C.x <= B.x)
	{
	    dem++;
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
		cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
	    	
	}	
}


void test4 (diem C,diem B,float big0,float small0,float p)  //vong while truong hop m < -1
{
	int dem =1;
	
	cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
	while ( C.x <= B.x)
	{
		
		dem++;
		
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
		cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
	  
	}	
}

void test3 (diem C,diem B,float big0,float small0,float p)  //vong while truong hop m > 1
{
	int dem =1;
	
	cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
    
    while ( C.x <= B.x)
	{
	
		dem++;
		
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
	    cout<<endl<<dem<<"  "<<"x= "<<C.x<<" y= "<<C.y<<" p ="<<fixed<<setprecision(2)<<p;	
	    
	}	
}


int main ()
{
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
	
	//tinh gia tri Dy va Dx
	float dy =(B.y-A.y);
	float dx =(B.x-A.x);
	float m  = dy/dx;
	
     float small0;
     float big0;
     float p;
    
    //diem C la -diem ke tiep khi t hien thuat toan
	diem C;
	C.x = A.x;
	C.y = A.y;
	cout<<"m la: "<<fixed<<setprecision(2)<<m;
	//liet ke cac truong hop
    if (m > 0 && m <= 1)
    {
    	small0 = 2*dy;
	    big0 = 2*(dy-dx);
	    p = 2*dy-dx;
	    
	    cout<<endl<<"small 0 la: "<<small0 <<"big0 la: "<<big0<<"p ban dau la: "<<p<<endl;
	    test1 (C,B,big0,small0,p);
	}
	
	if (m >= -1 && m <0)
	{
		p = 2*dy + dx;
		small0 = 2*(dy+dx);
		big0 = 2*dy;
		
		  cout<<endl<<"small 0 la: "<<small0 <<"big0 la: "<<big0<<"p ban dau la: "<<p<<endl;
		 test2 (C,B,big0,small0,p);
	}
	
	
	if (m > 1)
	{
		p = 2*dx - dy;
		big0 = 2*(dx-dy);
		small0 = 2*dx;
		
		  cout<<endl<<"small 0 la: "<<small0 <<"big0 la: "<<big0<<"p ban dau la: "<<p<<endl;
		test3 (C,B,big0,small0,p);   //ham chay vong lap while 
	}
	
	
	if ( m < -1)
	{
		p =2*dx +dy;
		small0 = 2*dx + 2*dy;
		big0 = 2*dx;
		
		  cout<<endl<<"small 0 la: "<<small0 <<"big0 la: "<<big0<<"p ban dau la: "<<p<<endl;
		 test4 (C,B,big0,small0,p);
	}

}
