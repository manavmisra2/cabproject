#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>

/*************** Customer Class Definition Start ***************/
class Customer
{
		char name[30];
		char mobile[15];
		char email[40];
		char pass[40];
	public:
		Customer();
		void Enter();
		void Display();
		void Update(char p[])
		{
			strcpy(pass,p);
		}
		void UpdateMobile(char m[])
		{
			strcpy(mobile,m);
		}
		char* getname()
		{
			return name;
		}
		char* getmobile()
		{
			return mobile;
		}
		char* getemail()
		{
			return email;
		}
		char* getpass()
		{
			return pass;
		}
};

Customer::Customer()
{
	strcpy(name,NULL);
	strcpy(mobile,NULL);
	strcpy(email,NULL);
	strcpy(pass,NULL);
}
void Customer::Display()
{
	cout<<"\n\t Mobile No \t: "<<mobile;
	cout<<"\n\t Customer Name \t: "<<name;
	cout<<"\n\t E-Mail \t: "<<email;
}

void Customer::Enter()
{
	cout<<"\n\t Mobile No \t: "<<mobile;
	cout<<"\n\t Customer Name \t: "; gets(name);
	cout<<"\t E-Mail \t: "; gets(email);
	cout<<"\t Password \t: ";
	int i=0;
	do
	{
		pass[i]=getch();
		if(pass[i]==13)
			break;
		cout<<"*";
		i++;
	}while(i<39);
	pass[i]='\0';
}
/*************** Customer Class Definition End ***************/

/*************** Booking Class Definition Start ***************/
class Booking
{
		int  bid;
		char bdate[15];
		char name[30];
		char address[40];
		char src[30];
		char dest[30];
		char email[40];
		char mobile[15];
		char regno[20];
		char driver[30];
		char model[30];
		char type[20];
		char company[20];
		float  base;
		float  rate;
		int km;
		float fare;
	public:
		Booking();
		void Update(char bd[], char t[], char s[], char d[], int k)
		{
			strcpy(bdate,bd);
			strcpy(type,t);
			strcpy(src,s);
			strcpy(dest,d);
			km = k;
			assignbase();
		}
		void UpdateDetails(char nm[], char mob[], char em[])
		{
			strcpy(name,nm);
			strcpy(mobile,mob);
			strcpy(email,em);
		}

		void Enter();
		void Display();
		void DisplayBill();
		void Estimate();
		void Edit();
		void assignbase();
		void Show();
		void rate_inc(int n)
		{
			rate += n;
		}
		int getbid()
		{
			return bid;
		}
		int getkm()
		{
			return km;
		}
		void setbid(int id)
		{
			bid = id;
		}
		char* getmobile()
		{
			return mobile;
		}
		char* getname()
		{
			return name;
		}
		char* getemail()
		{
			return email;
		}
		char* gettype()
		{
			return type;
		}

		char rno[10][20];
		char dname[10][30];
		void assign()
		{
			strcpy(rno[0],"DL12A9045");
			strcpy(rno[1],"HR99D2301");
			strcpy(rno[2],"UP14R9021");
			strcpy(rno[3],"DL13E9082");
			strcpy(rno[4],"DL13SA9021");
			strcpy(rno[5],"UP14AS4501");
			strcpy(rno[6],"DL13AD5602");
			strcpy(rno[7],"UP14SA9012");
			strcpy(rno[8],"DL07AD8502");
			strcpy(rno[9], "DL01AS8801");

			strcpy(dname[0],"Vivek Pal");
			strcpy(dname[1],"Chhote Lal");
			strcpy(dname[2],"Md. Rafiq");
			strcpy(dname[3],"Surender Singh");
			strcpy(dname[4],"Babulal Meena");
			strcpy(dname[5],"Sumesh Bhati");
			strcpy(dname[6],"Dharmendra");
			strcpy(dname[7],"Md.Majeet");
			strcpy(dname[8],"Dharam Singh");
			strcpy(dname[9], "Roshan Lal");
		  }
};
Booking :: Booking()
{
	assign();
	bid = 0;
	base = 0;
	strcpy(company,NULL);
	strcpy(bdate, NULL);
	strcpy(name, NULL);
	strcpy(address,NULL);
	strcpy(email,NULL);
	strcpy(mobile,NULL);
	strcpy(model,NULL);

}
void Booking :: Estimate()
{
	cout<<"\n\t Booking Estimated Fares ";
	cout<<"\n\t=========================";
	cout<<"\n\t Booking Date   : "<<bdate;
	cout<<"\n\t Pick-Up Point  : "<<src;
	cout<<"\n\t Drop Off Point : "<<dest;
	cout<<"\n\t Cab Type       : "<<type;
	cout<<"\n\t Kilometer      : "<<km;
	int v = random(3)+1;
	int opt = random(2);
	float r = v/2.0;
	float ola,uber;
	if(opt==0)
	{
		ola = base + (km-2)*(rate+r);
		uber = base + (km-2)*rate;
	}
	else
	{
		uber = base + (km-2)*(rate+r);
		ola  = base + (km-2)*rate;
	}
	cout<<"\n\t Estimated Fare with Uber : "<<uber;
	cout<<"\n\t Estimated Fare with Ola  : "<<ola;
	int ch;
	do
	{
		cout<<"\n\t Choose 1.Uber 2.Ola  : ";
		cin>>ch;
		if(ch==1)
		{
			strcpy(company,"Uber");
			fare = uber;
		}
		else if(ch==2)
		{
			strcpy(company,"Ola");
			fare = ola;
		}
		else
		{
			cout<<"\n\t Invalid Choice. Please Re-Enter.";
		}
	}
	while(ch<1||ch>2);
}
void Booking :: Enter()
{
	randomize();
	int i = random(10);
	strcpy(regno,rno[i]);
	strcpy(driver,dname[i]);
}
void Booking ::Display()
{
	cout<<"\n Cab Booking Details ";
	cout<<"\n*********************\n";
	cout<<"\nBooking ID      : "<<bid;
	cout<<"\nBooking Date    : "<<bdate;
	cout<<"\nCab Type     	: "<<type;
	cout<<"\nCar Reg.No.     : "<<regno;
	cout<<"\nDriver Name     : "<<driver;
	cout<<"\nPick-Up Place   : "<<src;
	cout<<"\nDrop Place      : "<<dest;
	cout<<"\nKilometer       : "<<km;
	cout<<"\nCompany Name    : "<<company;
	cout<<"\nEstimated Fare	: "<<fare;
	cout<<"\nCustomer Name   : "<<name;
	cout<<"\nEmailId         : "<<email;
	cout<<"\nMobile No       : "<<mobile;
}
void Booking ::DisplayBill()
{
	cout<<"\n\t\t Cab Fare Detail ";
	cout<<"\n\t***********************************\n";
	cout<<"\n\tBooking ID   \t: "<<bid;
	cout<<"\n\tBooking Date \t: "<<bdate;
	cout<<"\n\tCustomer Name\t: "<<name;
	cout<<"\n\tMobile No   \t: "<<mobile;
	cout<<"\n\tCab Type    \t: "<<type;
	cout<<"\n\tKilometer   \t: "<<km;
	cout<<"\n\tPick-Up Place\t: "<<src;
	cout<<"\n\tDrop Place   \t: "<<dest;
	cout<<"\n\tCompany Name \t: "<<company;
	cout<<"\n\tFare	\t: "<<fare;
	float gst = fare*0.12;
	cout<<"\n\tGST (12%) \t: "<<setprecision(2)<<gst;
	cout<<"\n\tFare (with GST) : "<<fare+gst;
}

void Booking:: Show()
{
	cout.setf(ios::left);
	cout<<"\n"<<setw(4)<<bid<<setw(15)<<bdate<<setw(15)<<src<<setw(15)<<dest
		<<setw(8)<<company<<setw(12)<<regno<<setw(3)<<km<<setw(5)<<fare;
}
void Booking::Edit()
{
	int ch;
	do
	{
		clrscr();
		cout<<"\n        Cabs Edit Details      ";
		cout<<"\n*******************************";
		cout<<"\n Booking ID  \t: "<<bid;
		cout<<"\n Name   \t: "; puts(name);
		cout<<"\n Emailid    \t: "; puts(email);
		cout<<"\n Contact No \t: "; puts(mobile);
		cout<<"\n Kilometer    \t: "<<km;
		cout<<"\n Address\t: ";	puts(address);
		cout<<"\n Edit 1.Name 2.Email Id 3.Contact No"
		<<"4.Address 5.Kilometer ";
		cout<<"6.No more Edit \n Enter Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n Name      : ";
					gets(name);
					break;
			case 2: cout<<"\n Email Id  : ";
					gets(email);
					break;
			case 3: cout<<" Contact No  : ";
					gets(mobile);
					break;
			case 4: cout<<"\n Address   : ";
					gets(address);
					break;
			case 5: cout<<"\n Kilometer : ";
					cin>>km;
					break;
			case 6: cout<<"\n Updatation Completed";
					break;
			default:cout<<"\n Invalid Choice ";
		 }
	}
	while(ch != 6);

}

void Booking::assignbase()
{
	if(strcmpi(type,"Mini")==0)
	{
		base=50;
		rate=12;
	}
	else
	 if(strcmpi(type,"Micro")==0)
	 {
		base=60;
		rate=13;
	 }
	else
	 if(strcmpi(type,"Prime")==0)
	 {
		base=70;
		rate=15;
	 }
	 else
	 if(strcmpi(type,"XL")==0)
	 {
		base=90;
		rate=20;
	 }
	 else
	  if(strcmpi(type,"Luxury")==0)
	 {
		base=150;
		rate=30;
	 }
}


/*************** Booking Class Definition End ***************/
int getbookingid()
{
	fstream F;
	Booking b1,b2;
	int id=1;
	F.open("booking.dat",ios::in|ios::binary);
	F.seekg(0,ios::end);
	if(F.tellg()>0)
	{
		F.seekg(F.tellg() - sizeof(b1));
		F.read((char*)&b1, sizeof(b1));
		id = b1.getbid() + 1;
	}
	F.close();
	return id;
}
int Findkm(char src[], char dest[])
{
	int km=0;
	if(strcmpi(src,"Dayanand Vihar")==0)
	{
		if(strcmpi(dest,"IGI Airport")==0)
			km = 50;
		else if(strcmpi(dest,"Noida")==0)
			km = 20;
		else if(strcmpi(dest,"Gurgaon")==0)
			km=60;
		else if(strcmpi(dest,"BVM School")==0)
			km=3;

	}
	else if(strcmpi(src,"BVM School")==0)
	{
		if(strcmpi(dest,"IGI Airport")==0)
			km = 50;
		else if(strcmpi(dest,"Noida")==0)
			km = 20;
		else if(strcmpi(dest,"Gurgaon")==0)
			km=60;
		else if(strcmpi(dest,"Dayanand Vihar")==0)
			km=3;
	}
	else if(strcmpi(src,"BVM School")==0)
	{
		if(strcmpi(dest,"IGI Airport")==0)
			km = 53;
		else if(strcmpi(dest,"Noida")==0)
			km = 23;
		else if(strcmpi(dest,"Gurgaon")==0)
			km=63;
		else if(strcmpi(dest,"Dayanand Vihar")==0)
			km=3;
	}
	else if(strcmpi(src,"IGI Airport")==0)
	{
		if(strcmpi(dest,"Dayanand Vihar")==0)
			km = 50;
		else if(strcmpi(dest,"Noida")==0)
			km = 70;
		else if(strcmpi(dest,"Gurgaon")==0)
			km=30;
		else if(strcmpi(dest,"BVM School")==0)
			km=53;
	}
	else if(strcmpi(src,"Noida")==0)
	{
		if(strcmpi(dest,"IGI Airport")==0)
			km = 70;
		else if(strcmpi(dest,"Dayanand Vihar")==0)
			km = 20;
		else if(strcmpi(dest,"BVM School")==0)
			km=23;
		else if(strcmpi(dest,"Gurgaon")==0)
			km=50;
	}
	else if(strcmpi(src,"Gurgaon")==0)
	{
		if(strcmpi(dest,"Noida")==0)
			km = 50;
		if(strcmpi(dest,"IGI Airport")==0)
			km = 30;
		else if(strcmpi(dest,"Dayanand Vihar")==0)
			km = 60;
		else if(strcmpi(dest,"BVM School")==0)
			km=63;
	}
	return km;
}

void insert(char cn[], char mob[], char em[])
{
	char date[20],type[10],src[30],dest[30];
	int km,ch;
	clrscr();
	cout<<"\n\t CAB Booking Details Form";
	cout<<"\n\t##########################\n";
	cout<<"\n\t Booking Date \t: "; gets(date);
	do
	{
		cout<<"\n\t Type \n\t1.Mini \n\t2.Micro \n\t"
			<<"3.Prime \n\t4.XL \n\t5.Luxury \n\tChoice : ";
		cin>>ch;
		if(ch==1)
			strcpy(type,"Mini");
		else if(ch==2)
			strcpy(type,"Micro");
		else if(ch==3)
			strcpy(type,"Prime");
		else if(ch==4)
			strcpy(type,"XL");
		else if(ch==5)
			strcpy(type,"Luxury");
		else
			cout<<"\n\tInvalid Choice. Please Re-Enter\n";
	}
	while(ch<1||ch>5);
	cout<<"\n\t Cab Type \t: "<<type;
	cout<<"\n\t Pickup Point \t: "; gets(src);
	cout<<"\t Drop Point \t: "; gets(dest);
	clrscr();
	km = Findkm(src,dest);
	Booking b1;
	b1.Update(date,type,src,dest,km);
	b1.Estimate();
	fstream f;
	int id;
	char ans;
	id = getbookingid();
	b1.setbid(id);
	b1.UpdateDetails(cn,mob,em);
	b1.Enter();
	f.open("booking.dat",ios::binary|ios::app);
	f.write((char*)&b1,sizeof(b1));
	f.close();
	clrscr();

	b1.Display();
	cout<<"\n\t Booking Confirmed !!! ";
}

void search(char mob[])
{
	fstream f;
	Booking b1;
	int flag=0;
	f.open("Booking.dat",ios::in|ios::binary);
	clrscr();
	cout<<"\n****************************************"
		<<"***************************************";
	cout<<"\n\t		DISPLAYING DETAILS OF PREVIOUS RIDES ";
	cout<<"\n****************************************"
		<<"***************************************\n";
	cout<<"\n\t\t\tMobile No. : "<<mob;
	cout<<"\n----------------------------------------"
		<<"---------------------------------------";
	cout.setf(ios::left);
	cout<<"\n"<<setw(4)<<"Id"<<setw(15)<<"Booking Date"<<setw(15)
		<<"Pickup Point"<<setw(15)<<"Drop Point"<<setw(8)<<"Company"
		<<setw(12)<<"Car Regno"<<setw(3)<<"KM"<<setw(5)<<"Fare";
	cout<<"\n----------------------------------------"
		<<"---------------------------------------";
	while(f.read((char*)&b1,sizeof(b1)))
	{
		if(strcmp(mob,b1.getmobile())==0)
		{
			flag=1;
			b1.Show();
		  }
	}
	if(flag==0)
	{
		cout<<"\n\t\t\tNo previous records found ";
	}

	cout<<"\n----------------------------------------"
		<<"---------------------------------------";

	f.close();

}
void cancel(char mob[])
{
	fstream f1,f2;
	Booking b1;
	int id,flag=0;
	char ans;
	f1.open("booking.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::binary);
	cout<<"\n\t\t\tEnter Booking Id to be deleted : ";
	cin>>id;
	while(f1.read((char*)&b1,sizeof(b1)))
	{
		if(id==b1.getbid() && strcmp(mob,b1.getmobile())==0)
		{
			b1.Display();
			flag=1;
			cout<<"\n Are you sure to want to be deleted ?";
			cin>>ans;
			if(ans=='y'||ans=='Y')
				cout<<"\n Booking Cancel Successfull.";
			else
			{
				cout<<"\n Booking not Canceled.";
				f2.write((char*)&b1, sizeof(b1));
			}
		}
		else
		{
			f2.write((char*)&b1,sizeof(b1));
		}
	}
	f1.close();
	f2.close();
	if(flag==0)
	{
		cout<<"\n\t\t\tRecord Not Found ";
		cout<<"\n\t\t\t**************** ";
	}
	remove("booking.dat");
	rename("temp.dat","booking.dat");
}

void update(char mob[])
{
	int id,flag=0;
	fstream f;
	Booking b1;
	f.open("booking.dat",ios::in|ios::out|ios::binary);
	cout<<"\n\t\t\tEnter Id to be searched for : ";
	cin>>id;
	while(f.read((char*)&b1,sizeof(b1)))
	{
		if(b1.getbid()==id && strcmp(mob,b1.getmobile())==0)
		{
			b1.Edit();
			flag=1;
			f.seekp(f.tellg() - sizeof(b1));
			f.write((char*)&b1, sizeof(b1));
		}
	}
	f.close();
	if(flag==0)
		cout<<"\n\t\t\tDetails Not Found ";
}

void bill(char mob[])
{
	int id,flag=0;
	fstream f;
	Booking b1;
	f.open("booking.dat",ios::in|ios::binary);
	cout<<"\n\t\t\tEnter Id to be searched for : ";
	cin>>id;
	clrscr();
	while(f.read((char*)&b1,sizeof(b1)))
	{
		if(b1.getbid()==id && strcmp(mob,b1.getmobile())==0)
		{
			b1.DisplayBill();
			flag=1;
		}
	}
	f.close();
	if(flag==0)
		cout<<"\n\t\t\tDetails Not Found ";
}
void bookingmenu(char nm[], char mob[], char em[])
{
	int ch;
	do
	{
		clrscr();
		cout<<"\n\t\t***********************************";
		cout<<"\n\t\t*  Cab Booking Management System  *";
		cout<<"\n\t\t***********************************";
		cout<<"\n\t\t* 	     By:- Manav Misra 	       * ";
		cout<<"\n\t\t*      (Session: 2018-2019)       *";
		cout<<"\n\t\t***********************************";
		cout<<"\n\t\t\t      Cab Menu    ";
		cout<<"\n\t\t\t -----------------";
		cout<<"\n\t\t\t 1.Enter Booking Details ";
		cout<<"\n\t\t\t 2.Display Previous Rides  ";
		cout<<"\n\t\t\t 3.Cancel Booking  ";
		cout<<"\n\t\t\t 4.Modify Booking Details ";
		cout<<"\n\t\t\t 5.Bill Reciept   ";
		cout<<"\n\t\t\t 6.Exit ";
		cout<<"\n\t\t\t Enter Choice [1-6] : ";
		cin>>ch;
		switch(ch)
		{
			case 1: insert(nm,mob,em);     break;
			case 2: search(mob); 	break;
			case 3: cancel(mob); break;
			case 4: update(mob);     break;
			case 5: bill(mob); break;
			case 6:	cout<<"\n Exit... "; break;
			default:cout<<"\n Invalid Choice ";
		}
		getch();
	}
	while(ch != 6);
}

void Login()
{
	char p[40],m[15],name[30],email[40];
	int  found=0,i;
	cout<<"\n\t Login Form ";
	cout<<"\n\t------------";
	cout<<"\n\t Mobile No. : ";
	gets(m);
	fstream F;
	Customer C;
	F.open("cust.dat",ios::in|ios::binary);
	while(F.read((char*)&C, sizeof(C)))
	{
		if(strcmp(m,C.getmobile())==0)
		{
			found=1;
			i=0;
			cout<<"\n\t Password   : ";
			do
			{
				p[i]=getch();
				if(p[i]==13)  // 13 is ASCII Code of Enter Key
					break;
				cout<<"*";
				i++;
			}while(i<39);
			p[i]='\0';
			if(strcmp(p,C.getpass())==0)
			{
				strcpy(name,C.getname());
				strcpy(email,C.getemail());
				found++;
			}
			break;
		}
	}
	F.close();
	if(found==2)
	{
		cout<<"\n\n\n\t\t\t Login Successfull.";
		cout<<"\n\t\t\t*******************";
		getch();
		bookingmenu(name,m,email);
	}
	else if(found==1)
	{
		cout<<"\n\n\n\t\t Password is wrong.\n\t\t Please try again.";
	}
	else
	{
		cout<<"\n\n\n\t\t\t Sign Up required. Please Signup.";
	}
}

void Signup()
{
	Customer C;
	fstream F;
	char mob[15];
	int found = 0;
	cout<<"\n\t  Sign Up Details Entry ";
	cout<<"\n\t -----------------------";
	cout<<"\n\t Mobile No.\t: "; gets(mob);
	F.open("cust.dat",ios::in|ios::binary);
	while(F.read((char*)&C, sizeof(C)) && found==0)
	{
		if(strcmp(mob,C.getmobile())==0)
		{
			found=1;
			cout<<"\n\t Account Already Exist.... ";
			C.Display();
			cout<<"\n\t Login Required ! ";
		}
	}
	F.close();
	if(found==0)
	{
		C.UpdateMobile(mob);
		C.Enter();
		F.open("cust.dat",ios::app|ios::binary);
		F.write((char*)&C, sizeof(C));
		F.close();
	}
}


void Loginmenu()
{
	int ch;
	do
	{
		clrscr();
		cout<<"\n\t\t***********************************";
		cout<<"\n\t\t*  Cab Booking Management System  *";
		cout<<"\n\t\t***********************************";
		cout<<"\n\t\t* By:- Manav Misra & Divyank Jain * ";
		cout<<"\n\t\t*      (Session: 2018-2019)       *";
		cout<<"\n\t\t***********************************";
		cout<<"\n\t\t\t      Login Menu    ";
		cout<<"\n\t\t\t -----------------";
		cout<<"\n\t\t\t 1.Login  ";
		cout<<"\n\t\t\t 2.Sign Up ";
		cout<<"\n\t\t\t 3.Exit ";
		cout<<"\n\t\t\t Enter Choice [1-3] : ";
		cin>>ch;
		switch(ch)
		{
			case 1: Login();     break;
			case 2: Signup();    break;
			case 3: cout<<"\n Exit... "; break;
			default:cout<<"\n Invalid Choice ";
		}
		getch();
	}
	while(ch != 3);
}

void main()
{
	textbackground(BLUE);
	textcolor(WHITE);
	Loginmenu();
	textbackground(BLUE);
	textcolor(WHITE);
}
