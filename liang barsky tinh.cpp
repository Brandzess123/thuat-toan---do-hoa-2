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
	
	//tinh gia tri
    int dx = B.x -A.x;
	int dy = B.y - A.y;
	
	//tinh gia tri dau
	int p1 = -dx;
	int p2 =  dx;
	int p3 =  -dy;
	int p4 = dy;
	
	int mang[4]= {p1,p2,p3,p4};
	cout<<endl<<"p1 la: "<<p1<<endl<<"p2 la: "<<p2<<endl<<"p3 la: "<<p3<<endl<<"p4 la: "<<p4;
	
	int q1 = A.x - min.x;
	int q2 = max.x - A.x;
	int q3 = A.y - min.y;
	int q4 = max.y - A.y;
	
	
	int mangq[4] = {q1,q2,q3,q4};
	cout<<endl<<"q1 la: "<<q1<<endl<<"q2 la: "<<q2<<endl<<"q3 la: "<<q3<<endl<<"q4 la: "<<q4<<endl<<endl;
	
	float t1 = 0; 
	float t2 = 1; 
		
	int Q1 = 0,P1 = 0;
	int Q2 = 0,P2 = 0;
	
	int check  = 0;
	for (int i = 0; i  < 4; i++ )
	{
		if (mang[i] == 0)
		{
			if (mangq[i] < 0 )
			{
				cout<<"phuong trinh vo nghiem vi : p"<<i<<" = 0  va q"<<i<<"= "<<mangq[i]<<" < 0 ";
			
				check = 1;
				break;
			}
		}
		
		if (mang[i] < 0  && t1 < (float)mangq[i]/mang[i]  )
		{	
		    t1 = (float)mangq[i]/mang[i];    
		    
		    Q1 = mangq[i];
		    P1 = mang[i];
		    cout<<endl<<"gia tri t1 la: "<<Q1<<"/"<<P1;	
	        cout<<endl<<"t1: "<<t1;
	    }                                                   
		if (mang[i] > 0  && t2 > (float)mangq[i]/mang[i] )
		{
		    t2 = (float)mangq[i]/mang[i];
		    
		    Q2 = mangq[i];
		    P2 = mang[i];
			cout<<endl<<"gia tri t2 la: "<<Q2<<"/"<<P2;	
			cout<<endl<<"t2: "<<t2;
		}         
	}

    cout<<endl<<endl<<"gia tri cuoi: ";
    cout<<endl<<"t1: "<<t1;
    cout<<endl<<"gia tri t1 la: "<<Q1<<"/"<<P1;	
    cout<<endl<<"t2: "<<t2;
    cout<<endl<<"gia tri t2 la: "<<Q2<<"/"<<P2;	
    	
    if (check == 1)
	{
		cout<<endl<<endl<<"doan thang nam ngoai cua so: ";
		
	}
		
	if (t1 == 0 && t2 == 1 && check == 0)
	cout<<endl<<endl<<"2 diem nam trong cua so: ";
	
	else if (t1 <= t2 && check == 0)
	{
		cout<<endl<<endl<<endl<<"cat nhau o diem:";
		cout<<endl<<"x= "<<A.x<<"+ "<<Q2<<"/"<<P2<<" * "<<dx<<"= "<<(A.x + t2*dx );
		cout<<endl<<"y= "<<A.y<<"+ "<<Q2<<"/"<<P2<<" * "<<dy<<"= "<<(A.y+ t2*dy );
		
		cout<<endl<<"diem 2: ";
	   cout<<endl<<"x= "<<A.x<<"+ "<<Q1<<"/"<<P1<<" * "<<dx<<"= "<<(A.x + t1*dx );
		cout<<endl<<"y= "<<A.y<<"+ "<<Q1<<"/"<<P1<<" * "<<dy<<"= "<<(A.y+ t1*dy );
	}
	


}
