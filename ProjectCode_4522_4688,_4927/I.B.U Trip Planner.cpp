#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Hotel;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto


void gotoXY(int x, int y) 
{	 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

class Hotel;

class Admin
{
	char name[20];
	char password[20];
	
	public:
		
		void setdata()
		{
			cout<<"Enter your username: ";
			cin>>name;
			
			cout<<endl<<"enter password: ";
			cin>>password;
			
			cout<<"Remember password: ";
			
			
			int menu_item=0, run, x=7;
			bool running = true;
			
			gotoXY(18,7); cout << "->";
			
			while(running)
			{
		            gotoXY(20,7);  cout << "1) YES";
					gotoXY(20,8);  cout << "2) NO";
				
					system("pause>nul"); // the >nul bit causes it the print no message
				
					if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
						{
							gotoXY(18,x); cout << "  ";
							x++;
							gotoXY(18,x); cout << "->";
							menu_item++;
							continue;
							
						}
						
					if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
						{
							gotoXY(18,x); cout << "  ";
							x--;
							gotoXY(18,x); cout << "->";
							menu_item--;
							continue;
						}
						
					if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
						
						switch(menu_item){
							
							case 0: {
								
								gotoXY(20,16);
								
								storeCustomer();
								
								cout<<"Info saved";
								
								system("cls");
								running=false;
								
								break;
							}
								
								
							case 1: {
								gotoXY(20,16);
								
								running=false;
								
								break;
								
							}
							
						}
							
					}		
					
		}
		
		gotoXY(20,21);
			
		}
		
				
		void getdata()
		{
			cout<<endl<<name<<" "<<password;
		}

        void setname(char a,int i) {name[i]=a;}
        void setpassword(char a,int i) {password[i]=a;}        
	
	
	int storeCustomer()
		{				
				ofstream fout;
				fout.open("Customer.dat",ios::app|ios::binary);
				fout.write((char*)this,sizeof(*this));
				fout.close();
				return (1);
			
		}
  
  	void viewAll()
		{
			ifstream fin;
			fin.open("Customer.dat",ios::in|ios::binary);
			
			if(!fin)
			{
				cout<<"File not found ";
				
			}
			
			else
			{
				fin.read((char*)this,sizeof(*this));
				
				while(!fin.eof())
				{
					
					getdata();
					fin.read((char*)this,sizeof(*this));
					
				}
			}
			fin.close();
			
		}

		
	
};



class Customer
{	
   
    int destination,i;
    int days[10],nights[10],rooms[10];
    string locations[10]; 
    int preference;

    public:	
	Customer()
	{
		
	}

    Customer(int a)
    {  	getch();
		system("cls");
	
        fflush(stdin);
		cout <<"Number of destinations: ";
        cin >> destination;
        locations[destination];
        days[destination];

        cout << "1-Karachi" <<endl <<"2-Islamabad" <<endl <<"3-Lahore" <<endl <<"4-Naran"<<endl<<endl;
        for (i=0;i<destination;i++)
        {
            cout <<"Enter destination " <<i+1<<": " ;
            cin >> locations[i];
           	cout <<"Enter number of days: ";
        	cin >> days[i];
			cout <<"Enter number of nights: ";
     		cin >> nights[i];
			cout <<"Enter number of rooms: ";
        	cin >> rooms[i];
        	cout<<endl;       	
        }
    }

	//getters
    int getdestination( ) {return destination;}
    int getpref() {return preference;}
    string * getlocation() {return locations;}
    int *getrooms() {return rooms;}
    void *getdays() {return days;}
    void *getnights() {return nights;}
    friend class Hotel;
};



class  Hotel 
{  
    string name[10];
	int price[10];
    int destination;;
	
    public:

    string *getName() {return name;}
    int *getPrice() {return price;}
    

    Hotel()
    {
        
    }

    void display(const char *a)
    {
		//display
        Customer c(1);
        destination=c.getdestination();
        fstream z;
    	z.open(a, ios::in);
    	string st;

        //display formating
        system("cls");
        cout <<"   AVAILABLE HOTELS"<<endl;

        const int name_width = 30 ;
        const int sno_width = 3 ;
        const std::string sep = " |" ;
        const int total_width = (name_width + +sno_width + sep.size())+2;
        const std::string line = sep + std::string( total_width-1, '-' ) + '|' ;

        std::cout<<left<< line << '\n' << sep <<        
        std::setw(sno_width) << "SNO" << sep << 
        std::setw(name_width) << "Hotel"  << sep << 
        '\n' << line << '\n' ;

		//for showing available hotels
		for(int k=0;k<destination;k++)
		{    
			z.seekg(0,ios::beg);
			z.seekg(0,ios::beg);
			for(int j=0;j<10;j++)  		
			{
				getline(z,st);
	            if(st[0]==c.locations[k][0] && !z.eof())
	            {		
				  	name[j]=st;

                    // display
                    		
                    std::cout << sep << 
                    std::setw(sno_width) << j  << sep << 
                    std::fixed << std::setprecision(2) << 
                    std::setw(name_width) << st << sep << 
                    '\n' ;
	        	}
			}

            cout<< line << '\n' ;
		}

        z.close();
        select(c);    
    }


    string stringonlyname(string text)
    {
        int count=0;
        string cut = " ";
        size_t pos = 0;
        while ((pos = text.find(cut)) != string::npos) 
        {
            
            text.erase(0, pos + cut.length());
            count++;
            if (count==1 )
            {
                text.erase(text.size()-6);
                //cout<<text;
                break;
            }
        }
        return text;
    }

    int getNumberFromString(string s) 
    {
        string numbers="";
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                numbers+=s[i];
            }
        }
        stringstream g(numbers);
        int a;
        g>>a;
        return a;
    }

    void select(Customer c)
    {
        int choice,result=0;
        int op[destination];
        char *ch;
        string ss;
        cout<<endl<<"CHOOSE FROM ABOVE OPTIONS "<<endl;
        for(int i=0;i<destination;i++)
        {
            region:
            cout<<"Enter SNO for "<<c.locations[i]<<" : ";
            cin>>choice;

             //exceptional handling  
            try
            {
                if(c.locations[i][0]!=name[choice][0])
                {
                    throw choice;
                }               
                if(choice>7)
                {
                    throw choice;
                }              
            }

            catch (int x)
            {
                cout << "Invalid choice \n";
                goto region; 
            }
            
            //get only price
            op[i]=choice;
            ss=name[choice];
            int result=getNumberFromString(ss);
            price[op[i]]=result;

            
        }

        //totalling
        int p=0, total=0;
        //system("cls");
        cout<<endl <<"   TOTALING "<<endl;

        //display formating
        const int name_width = 20 ;
        const int city_width = 10 ;
        const int int_width = 7 ;
        const std::string sep = " |" ;
        const int total_width = (name_width + city_width + int_width*4 + sep.size() * int_width) -2 ;
        const std::string line = sep + std::string( total_width-1, '-' ) + '|' ;

        std::cout<< line << '\n' << sep << 
        std::setw(city_width) << "City" << sep << 
        std::setw(name_width) << "Hotel Name"  << sep << 
        std::setw(int_width) << "Rooms" << sep << 
        std::setw(int_width) << "Days" << sep << 
        std::setw(int_width) << "Nights" << sep << 
        std::setw(int_width) << "Cost" << sep << '\n' << line << '\n' ;

        for(int i=0;i<destination;i++)
        {	
            if (p<destination)
            {
                //extracting name
                string t=stringonlyname(name[op[i]]);

                //multiplying days
                price[op[i]]= price[op[i]] * c.days[p] * c.nights[p] * c.rooms[p];
                total=total+price[op[i]];

                //displaying		
                std::cout << sep << 
                std::setw(city_width) << c.locations[i]  << sep << 
                std::setw(name_width) << t << sep << 
                std::setw(int_width) << c.rooms[p]  << sep << 
                std::setw(int_width) << c.days[p] << sep << 
                std::setw(int_width) << c.nights[p]  << sep << 
                std::fixed << std::setprecision(2) << 
                std::setw(int_width) << price[op[i]] << sep << '\n' ;	
            }
        }

        std::cout << line << '\n' ;
        cout<<" |Total Cost : Rs "<<total<<endl;
        cout<<" |Thank you for planning your trip with us "<<endl;
        cout<<" |HERES A 10% DISCOUNT AS A TOKEN OF OUR APPRECIATION "<<endl;
        cout<<" |Cost After discount:  "<<total*0.90<<endl;
        cout<< line << '\n' ;

        
    }
  

};



class star5 : public Hotel
{
    public:        
    string getPath()
	{
		string a="C:\\Users\\Ishma\\Desktop\\5 star.txt"; //5 star
 		return a;
	}

    void facilities()
    {
        cout<<endl<<" Available Facillities:"<<endl;
        cout<<"-24 hour front desk "<<endl;
        cout<<"-Restaurant"<<endl;
        cout<<"-Free Breakfast"<<endl;
        cout<<"-Pool"<<endl;
        cout<<"-Free Wifi"<<endl;
        cout<<"-Mini-Bar"<<endl;
        cout<<"-Valet (parking) services to be available"<<endl;
        cout<<"-Room Service"<<endl;
        cout<<"-Gift Shop"<<endl;
        cout<<"-Fitness Center"<<endl;
        cout<<"-Parking Facilities.";
    }
};

class star4 : public Hotel
{
	public:		
    string getPath()
	{
		string a="C:\\Users\\Ishma\\Desktop\\4 star.txt"; //4 star
 		return a;
		
	}

    void facilities()
    {
        cout<<endl<<" Available Facillities:"<<endl;
        cout<<"-24 hour front desk "<<endl;
        cout<<"-Restaurant"<<endl;
        cout<<"-Pool"<<endl;
        cout<<"-Mini-Bar"<<endl;
        cout<<"-Valet (parking) services to be available"<<endl;
        cout<<"-Room Service"<<endl;
        cout<<"-Gift Shop"<<endl;
        cout<<"-Parking Facilities.";
    }
};

class star3 : public Hotel
{
	public:	
    string getPath()
	{
		string a="C:\\Users\\Ishma\\Desktop\\3 star.txt"; //3 star
 		return a;
	}

    void facilities()
    {
        cout<<endl<<" Available Facillities:"<<endl;
        cout<<"-24 hr. lifts for buildings higher than ground plus two floors"<<endl;
        cout<<"Restaurant"<<endl;
        cout<<"-Bedrooms, Bathroom, Public areas and kitchen fully serviced daily."<<endl;
        cout<<"-Valet (parking) services to be available"<<endl;
        cout<<"-Wifi internet access not mandatory."<<endl;
        cout<<"-Fax, photocopy and printing Services."<<endl;
        cout<<"-Parking Facilities.";
    }
};

class star2 : public Hotel
{
	public:
    string getPath()
	{
		string a="C:\\Users\\Ishma\\Desktop\\2 star.txt"; //2 star
 		return a;
	}

    void facilities()
    {
        cout<<endl<<" Available Facillities:"<<endl;
        cout<<"-24 hr. lifts for buildings higher than ground plus two floors"<<endl;
        cout<<"-Bedrooms, Bathroom, Public areas and kitchen fully serviced daily."<<endl;
        cout<<"-All floor surfaces clean and in good shape."<<endl;
        cout<<"Restaurant"<<endl;
    }
};


int date()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    cout << endl <<endl;
    cout << "Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    cout << "Time     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    return 0;
}


int main() 
{
	char *ch;
	int pre;

    //displaying screen
    while(1)
	{
		date();
		break;
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO MY TRIP.COM ================|";
	
	getch();
	system("cls");
	
	Admin A;
	A.setdata();
	//A.getdata();
	//A.viewAll();
	
	getch();
	system("cls");
	
    cout<<"Price ranges per day " <<endl;
    cout<<"5 STAR: 3000-5000 " <<endl;
    cout<<"4 STAR: 2000-3000 " <<endl;
    cout<<"3 STAR: 1000-2000 " <<endl;
    cout<<"2 STAR: 300-1000 " <<endl;
//	cout<<"Enter your preference: ";
	//cin>>pre;

	
	int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); cout<<"Price ranges per day " <<endl;
	gotoXY(18,5); cout<<"Enter your preference"<<endl;					
	
	gotoXY(18,7); cout << "->";
	
	while(running)
	{
                gotoXY(20,7);  cout << " 1) 5 STAR: 3000-5000 ";
		gotoXY(20,8);  cout << " 2) 4 STAR: 2000-3000";
		gotoXY(20,9);  cout << " 3) 3 STAR: 1000-2000";
		gotoXY(20,10); cout << " 4) 2 STAR: 300-1000";
		//gotoXY(20,11); cout << "Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					pre=5;
					running = false;
					break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					pre=4;
					running = false;
					break;
				}
					
				case 2: {
					gotoXY(20,16);
					pre=3;
					running = false;
					break;
				}
					
				case 3: {
					gotoXY(20,16);
					pre=2;
					running = false;
				
					break;
				}
					
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
		
	
	
	if(pre==5)
	{
		string a;
		star5 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.display(ch);	 
        s.facilities();
	}
	
	else if(pre==4)
	{
		 string a;
		star4 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.display(ch);
        s.facilities();
	}
	
	else if(pre==3)
	{
		 string a;
		star3 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.display(ch);
        s.facilities();
	}
	
	else if(pre==2)
	{
		 string a;
		star2 s;
		a=s.getPath();
		char* ch = const_cast<char*>(a.c_str());
		s.display(ch);
        s.facilities();

       
	}

    else
    {
        cout<<" Invalid preference";
    }
	
	
	// cout<<endl<<endl<<"View customer(s) data: ";
	// A.viewAll();
	
	return 0;
}




