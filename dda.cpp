#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

struct diem
{
	float x;
	float y;
};



main ()
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
    cout<<endl<<"gia tri m phan so: "<<dy<<"/"<<dx;
	cout<<endl<<"diem M: "<<m;
	//diem C la -diem ke tiep khi t hien thuat toan
	diem C;
	C.x = A.x;
	C.y = A.y;
	
	//
	int dem = 1;
	cout<<endl<<dem<<" x= "<<A.x<<"y= "<<A.y;
	
	/*
	    int cx = 1;  //khoi tao lai gia tri count x
        int cy = m;  //khoi tao lai gia tri count y
        
        //phan nay co the bo
		if (dx < 0)    //truong hop dx < 0
		cx =-1;        //count x = -1
		if (dy < 0)    //truong hop dx > 0
		cy = -m;       //count y = - m
	    */
	   
	    
		while (C.x < B.x)      
	    {
		    dem++;
		    if ( m <= 1)          //truong hop m <= 1
		    {
			   
			    C.x+= 1;             //x++;
		        C.y+= (float)dy/dx;             //y = y + m;
		        
		        cout<<endl<<dem<<" x= "<<C.x<<"y= "<<round(C.y); 
		    }
		
		    else if (m > 1)     //truong hop m > 1
		    {
			    C.y+= 1;               //y++;
	            C.x= C.x + (float)dx/dy;          //chu y (float)1/cy ko phai (float)(1/cy)
	     
	            cout<<endl<<dem<<" x= "<<round(C.x)<<"y= "<<C.y<<" gt Cx = "<<C.x;
	          
		    }	
		    
		    
	    }
	    
}
