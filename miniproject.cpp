/**************************************************************************************************************
******************************        **  ********  *****  *****   *******  ***********************************
******************************  ****  ***  ******  ****  **  ***  *  *****  ***********************************
******************************  ***********  **  ****** **** ***  ***  ***  ***********************************
******************************  *************  *******        **  ****  **  ***********************************
******************************  ****  *******  *******  ****  **  *****  *  ***********************************
******************************        *******  *******  ****  **  ******    ***********************************
**************************************************************************************************************/
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class admission{
	private:
		string name;
		string state;
		int _10th;
		int _12th;
		int jee;
		int year;
		char ch;
		char stream;
	public:
		admission();
		void getdata();
		void eligibility();
		void eligibility_h();
		void file_write();
		void file_read();
		void streamf(char);
		
};
admission::admission()
{
	_10th=0;
	_12th=0;
	jee=0;
	year=1990;
}
void admission::getdata()
{
	cout<<"Enter your name:";
	fflush(stdin);
	getline(cin,name);
	cout<<endl<<"Enter your state:";
	fflush(stdin);
	getline(cin,state);
	cout<<"Enter your 10th percentage:";
	cin>>_10th;
	while(_10th>100||_10th<20)
	{
		cout<<"\nYou've entered invalid percentage!\n";
		cout<<"Enter your 10th percentage:";
		cin>>_10th;
	}
	cout<<"Enter your 12th percentage(PCM only):";
	cin>>_12th;
	while(_12th>100||_12th<20)
	{
		cout<<"\nYou've entered invalid percentage!\n";
		cout<<"Enter your 12th percentage:";
		cin>>_12th;
	}
	cout<<"Enter your Jee Mains Score:";
	cin>>jee;
	while(jee>360||jee<0)
	{
		cout<<"\nYou've entered invalid Jee Mains Score!\n";
		cout<<"Enter your Jee Mains Score";
		cin>>jee;
	}
	cout<<"Enter Birth Year:";
	cin>>year;
	while(year>2010||year<1970)
	{
		cout<<"\nYou've entered Invalid Birth Year!\n";
		cout<<"Enter your Birth Year:";
		cin>>year;
	}
}
void admission::eligibility()
{
	int a,b,c,d,e;
	a=(_10th>=60)?1:0;
	b=(_12th>=60)?1:0;
	c=(jee>=60)?1:0;
	d=(year<=2001||year>=1996)?1:0;
	cout<<endl;
	if(a&&b&&c&&d)
	{
		cout<<"You are eligible!";
	}
	else
	{
		cout<<"Your not eligible because of following:";
		if(!a)
			cout<<"\n~10th grade marks";
		if(!b)
			cout<<"\n~12th grade marks";
		if(!c)
			cout<<"\n~Jee Score";
		if(!d)
			cout<<"\n~Year of Birth";
	}
	if((!a)||(!b)||(!c))
	{
		getche();
		cout<<"\n\n\t\t***Good News***\n"
		<<"You can give LPU-NEST to get eligible for addmissions";
		cout<<"\nAre you intrested in giving LPU-NEST(Y/N)";
		cin>>ch;
		if(ch=='Y'||ch=='y')
		{
			cout<<"\nYou can go to the link below to register for LPU-NEST!"
			<<"\nhttp://nest.lpu.in/engineering/frmNESTLoginNew.aspx"
			<<"\nLast Date for exams 25May";
		}
		else if(ch=='N'||ch=='n')
		{
			cout<<"\nIt is strongly recommended for giving LPU-NEST"
			<<"\nLast Date for exams 25May";
		}	
	}
}
void admission::eligibility_h()
{
	int a,b,c,d;
	a=(_10th>=70)?1:0;
	b=(_12th>=70)?1:0;
	c=(jee>=105)?1:0;
	d=(year<=2001||year>=1996)?1:0;
	cout<<endl;		
	if(a&&b&&c&&d)	
	{
		cout<<"You are eligible!";
	}
	else
	{
		cout<<"Your not eligible because of following:";
		if(!a)
			cout<<"\n~10th grade marks";
		if(!b)
			cout<<"\n~12th grade marks";
		if(!c)
			cout<<"\n~Jee Score";
		if(!d)
			cout<<"\n~Year of Birth";	
	}
	if((!a)||(!b)||(!c))
	{
		cout<<"\n\n\t\t***Good News***\n";
		cout<<"\nYou can give LPU-NEST to get eligible for addmissions";
		cout<<"\nAre you intrested in giving LPU-NEST(Y/N)";
		cin>>ch;
		if(ch=='Y'||ch=='y')
		{
			cout<<"\nYou can go to the link below to register for LPU-NEST!"
			<<"\nhttp://nest.lpu.in/engineering/frmNESTLoginNew.aspx";
		}
		else if(ch=='N'||ch=='n')
		{
			cout<<"\nIt is strongly recommended for giving LPU-NEST"
			<<"\nLast Date for exams 25May";
		}
	}
}
void admission::streamf(char st)
{
	if(st=='H')
	{
		stream='H';
	}
	else
	{
		stream='N';
	}
}
void admission::file_write()
{
	ofstream fout;
	string c;
	fout.open("admissions_data.dat",ios::binary|ios::app);
	eligibility_h();
	fout.write((char*)&c,sizeof(c));
	fout.close();	
}
void admission::file_read()
{
	ifstream fin;
	fin.open("admissions_data.dat",ios::binary|ios::app);
	fin.seekg(0,ios::beg);
	string c;
	do
	{
		fin.read((char*)&c,sizeof(c));
		cout<<c;
		
	}while(fin.good());
	
	fin.close();
}

int main()
{
	admission a;
	int n,i=1;
	void menu();
	void table_heading();
	void student_choice(admission);
	while(i)
	{
		//system("CLS");
		menu();
		cin>> n;
		if(n==1)
		{
			table_heading();	
			a.file_read();
			getche();
			cout<<endl<<endl<<endl;
		}
		else if(n==2)
		{
			student_choice(a);
			getche();
			cout<<endl<<endl<<endl;
		}
		else if(n==3)
		{
			cout<<"Thanks for using! Goodbye!!";
			cout<<endl<<endl<<endl;
		}
	}
}
void menu()
	{
		cout<<"\n\t\t\t######################################################";
		cout<<"\n\t\t\t#      WELCOME TO LOVELY PROFESSIONAL UNIVERSITY     #";
    	cout<<"\n\t\t\t######################################################";
		cout<<"\n \t\t\t#             [1]  Admin                             #";
		cout<<"\n\t\t\t#             [2]  Students/Parents                  #";
		cout<<"\n \t\t\t#             [3]  Exit                              #";
		cout<<"\n\t\t\t######################################################";
		cout<<endl<<"->";
	}
void table_heading()
	{
		cout<<setw(20)<<"Name"<<setw(20)<<"State"
		<<setw(10)<<"Stream(H/N)"
		<<setw(7)<<"10th%"<<setw(7)<<"12th%"
		<<setw(15)<<"Jee Score"
		<<setw(15)<<"Birth Year"<<setw(10)<<"Choice"
		<<endl<<endl;
	}
void student_choice(admission a)
	{
		int x=1,y;
		while(x)
		{
			cout<<"\nWhich Course you want to opt for:"
			<<"\n[1]B.Tech\n[2]B.Tech(Hons)\n->";
			fflush(stdin);
			cin>>y;
			if(y==1)
			{
				a.getdata();
				a.eligibility();
				x=0;
				a.streamf('N');
				a.file_write();		
			}
			else if(y==2)
			{
				a.getdata();
				a.eligibility_h();
				x=0;
				a.streamf('H');
				a.file_write();
			}
			else
			{
				cout<<"Invalid Input!";
				x=1;
			}		
		}
	}


