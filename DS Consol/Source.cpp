#include"Admin.h"
#include"Passenger.h"
#include<unordered_map>
#include <fstream>


void choose(int x);
void AddTrain();
void UpdateTrain();
void VeiwListOfTrain();

void Login();
void passenger();

void Loadmaps();


void savemaps();


unordered_map<int, Admin> map1;
unordered_map<string, Passenger> map2;
unordered_map<string, Passenger> map3;


string boarding;
string destination;
int seats;
double fare;
string date;

int main()
{
	Loadmaps();
	int chs;
	A: cout << "You are .." << endl;
	cout << "1- Admin" << endl;
	cout << "2- Passenger" << endl;
	cout << "3- Exit" << endl;
	cin >> chs;
	if (chs > 3 || chs < 1)
	{
		cout << "*****************************" << endl;
		cout << "INVALID NUMBER ,Choose from menu (1,2,3)" << endl;
		goto A;
	}
	choose(chs);
	savemaps();

	system("pause");
	return 0;
}



void choose(int x)
{	
	
	if (x == 1)
	{
		int choose, pass;
		C:cout << "Enter Password: ";
		cin >> pass;	
		if (pass == 123)
		{
			A: cout << "You want .." << endl;
			cout << "1- Add Train" << endl;
			cout << "2- Update Train Details" << endl;
			cout << "3- View the lists of Trains" << endl;
			cout << "4- Home" << endl;
			cout << "5- Exit" << endl;
			cin >> choose;
			
			if (choose == 1)
			{
				
				AddTrain();
				goto A;
			}
			else if (choose == 2)
			{
				UpdateTrain();
				goto A;

			}
			else if (choose == 3)
			{
				VeiwListOfTrain();
				goto A;
			}
			else if (choose == 4)
			{
				main();
			}
			else if (choose == 5)
				return ;
			else
			{
				cout << "*****************************" << endl;
				cout << "INVALID NUMBER ,Choose from menu (1,2,3,4,5)" << endl;
				goto A;
			}		
		}
		else
		{
			cout << "Password Incorrect!" << endl;
			goto C;
		}
	}
	else if (x == 2)
	{
		passenger();
	}
	else if (x == 3)
	{
		savemaps();
		return;
	}
}
void passenger()
{
	int d;
R:	cout << "You want .." << endl;
	cout << "1- Log-in" << endl;
	cout << "2- Sign-up" << endl;
	cout << "3- Home" << endl;
	cout << "4- Exit" << endl;
	cin >> d;
	if (d == 1)
	{
		Login();

	}
	else if (d == 2)
	{
		string email, password, name;
		cout << "Enter New E-mail: ";
		cin >> email;
		cout << "Enter New Password: ";
		cin >> password;
		cout << "Enter Your Name: ";
		cin >> name;
		Passenger C(email, password, name);
		map2[C.email] = C;
		cout << "Welcome " << endl;
		Login();
	}
	else if (d == 3)
	{
		main();
	}
	else if (d == 4)
	{
		savemaps();
		return;
	}
		
	else
	{
		cout << "*****************************" << endl;
		cout << "INVALID NUMBER ,Choose from menu (1,2,3,4)" << endl;
		goto R;
	}
}
void AddTrain()
{
	int num;
	B:cout << "Train Number: ";
	cin >> num;
	unordered_map<int, Admin>::iterator ll = map1.find(num);
	if (ll != map1.end())
	{
		cout << "*****************************" << endl;
		cout << "INVALID NUMBER!, There is find here" << endl;
		cout << "*****************************" << endl;
		goto B;

	}
	else
	{
		cout << "Enter Boarding Point: ";
		cin >> boarding;
		cout << "Enter Destination Point: ";
		cin >> destination;
		cout << "Enter Number of available seats: ";
		cin >> seats;

		cout << "Enter fare: ";
		cin >> fare;

		cout << "Enter Date of Travel: ";
		cin >> date;
		Admin a(num, boarding, destination, seats, fare, date);
		map1[a.train_num] = a;
		cout << "*****************************" << endl;
		cout << "Add Completed " << endl;
		cout << "*****************************" << endl;
	}
	
}
void UpdateTrain()
{
	int t_num;
	B:cout << "Enter Train Number: ";
	cin >> t_num;
	unordered_map<int, Admin>::iterator ll = map1.find(t_num);
	if (ll == map1.end())
	{
		cout << "*****************************" << endl;
		cout << "INVALID NUMBER!, There is find here" << endl;
		cout << "*****************************" << endl;
		goto B;

	}
	else
	{
		cout << "Enter Bording Point: ";
		cin >> boarding;
		cout << "Enter Destination Point: ";
		cin >> destination;
		cout << "Enter Number of available seats: ";
		cin >> seats;

		cout << "Enter Fare of Ticket: ";
		cin >> fare;

		cout << "Enter Date of Travel: ";
		cin >> date;

		Admin a(t_num, boarding, destination, seats, fare, date);
		map1[a.train_num] = a;
		cout << "*****************************" << endl;
		cout << "Update Completed " << endl;
		cout << "*****************************" << endl;
	}
	
}
void VeiwListOfTrain()
{
	unordered_map<int, Admin>::iterator it = map1.begin();
	while (it != map1.end())
	{
		cout << "*****************************" << endl;
		cout << "Train Number: " << it->second.train_num << endl;
		cout << "Bording Point: " << it->second.boarding << endl;
		cout << "Destination Point: " << it->second.destination << endl;
		cout << "Number of available seats: " << it->second.seats << endl;
		cout << "Fare of Ticket: " << it->second.fare << endl;
		cout << "Date of Travel: " << it->second.date << endl;
		it++;
	}
	cout << "*****************************" << endl;
}

void Login()
{
	
	int d;
	string Email, Pass;
E: cout << "Enter Your E-mail: ";
	cin >> Email;
	cout << "Enter Password: ";
	cin >> Pass;
	unordered_map<string, Passenger>::iterator IT = map2.find(Email);
	if (Pass == IT->second.pass)
	{

	AZ:cout << "You want .." << endl;
		cout << "1- Booking Ticket" << endl;
		cout << "2- Update your Ticket" << endl;
		cout << "3- Delete your Booking" << endl;
		cout << "4- View your Booking" << endl;
		cout << "5- Home" << endl;	
		cout << "6- Exit" << endl;
		cin >> d;

		if (d == 1)
		{
			unordered_map<string, Passenger>::iterator It2 = map3.find(Email);
			if (It2 != map3.end())
			{
				cout << "You are already Reserve ..." << endl;
				cout << "Choose Update from menu .." << endl;
				goto AZ;
			}
			else
			{
			SD: VeiwListOfTrain();
				int id;
				cout << "Enter Train ID: ";
				cin >> id;
				unordered_map<int, Admin>::iterator It = map1.find(id);
				if (It != map1.end())
				{

					if (It->second.seats <= 0)
					{

					AZZ: cout << "This Train Completed .." << endl;
						cout << "1- Choose another Train" << endl;
						cout << "2- Exit" << endl;
						cin >> d;
						if (d == 1)
							goto SD;
						else if (d == 2)
							return;
						else
						{
							cout << "*****************************" << endl;
							cout << "INVALID NUMBER ,Choose from menu (1,2)" << endl;
							goto AZZ;
						}
					}
					Passenger p;
					p.Passenger22(IT->second.email, IT->second.name, IT->second.pass, It->second.boarding, It->second.destination, It->second.date, id);
					map2[Email] = p;
					cout << "Booking Completed" << endl;
					cout << "Name: " << IT->second.name << endl;
					cout << "E-mail: " << IT->second.email << endl;
					cout << "Password: " << IT->second.pass << endl;
					cout << "Boarding Point: " << IT->second.boarding_point << endl;
					cout << "Destination Point: " << IT->second.destination_point << endl;
					cout << "Date of Traver: " << IT->second.Date << endl;
					cout << "Train Number: " << IT->second.Tnum << endl;
					It->second.seats -= 1;
					map3[Email] = p;
					goto AZ;
				}
				else
				{
					cout << "*****************************" << endl;
					cout << "INVALID NUMBER ,Choose from Available Trains" << endl;
					goto SD;
				}
			}
		}
		else if (d == 2)
		{
			unordered_map<string, Passenger>::iterator It1 = map2.find(Email);
			int k = It1->second.Tnum;
		SDD: VeiwListOfTrain();
			int id;
			cout << "Enter Train ID: ";
			cin >> id;
			unordered_map<int, Admin>::iterator It = map1.find(id);
			if (It != map1.end())
			{

				if (It->second.seats <= 0)
				{
					
				ASZ: cout << "This Train Completed .." << endl;
					cout << "1- Choose another Train" << endl;
					cout << "2- Exit" << endl;
					cin >> d;
					if (d == 1)
						goto SDD;
					else if (d == 2)
						return;
					else
					{
						cout << "*****************************" << endl;
						cout << "INVALID NUMBER ,Choose from menu (1,2)" << endl;
						goto ASZ;
					}
				}
				Passenger p;
				p.Passenger22(IT->second.email, IT->second.name, IT->second.pass, It->second.boarding, It->second.destination, It->second.date, id);
				map2[Email] = p;
				cout << "Booking Completed" << endl;
				cout << "Name: " << IT->second.name << endl;
				cout << "E-mail: " << IT->second.email << endl;
				cout << "Password: " << IT->second.pass << endl;
				cout << "Boarding Point: " << IT->second.boarding_point << endl;
				cout << "Destination Point: " << IT->second.destination_point << endl;
				cout << "Date of Travel: " << IT->second.Date << endl;
				cout << "Train Number: " << IT->second.Tnum << endl;
				map3[Email] = p;
				if (k != id)
				{
					It->second.seats -= 1;
					unordered_map<int, Admin>::iterator Ittt = map1.find(k);
					Ittt->second.seats += 1;
				}
				
				goto AZ;
			}
			else
			{
				cout << "*****************************" << endl;
				cout << "INVALID NUMBER ,Choose from Available Trains" << endl;
				goto SDD;
			}

		}
		else if (d == 3)
		{	
			int u =IT->second.Tnum;
			unordered_map<int, Admin>::iterator IIt = map1.find(u);
			IIt->second.seats += 1;
			map3.erase(Email);

			
			cout << "Removing Completed" << endl;
			goto AZ;
		}
		else if (d == 4)
		{
		
			unordered_map<string, Passenger>::iterator It1 = map3.find(Email);
			cout << "******************************************* " << endl;
			cout << "Check if your train reservation changed.. " << endl;
			cout << "******************************************* " << endl;
			VeiwListOfTrain();
			if (It1 == map3.end())
			{
				cout << "Not Found" << endl;
				goto AZ;
			}
			else
			{
				cout << "Name: " << It1->second.name << endl;
				cout << "E-mail: " << It1->second.email << endl;
				cout << "Password: " << It1->second.pass << endl;
				cout << "Boarding Point: " << It1->second.boarding_point << endl;
				cout << "Destination Point: " << It1->second.destination_point << endl;
				cout << "Date of Travel: " << It1->second.Date << endl;
				cout << "Train Number: " << It1->second.Tnum << endl;
				goto AZ;
			}
			
		}
		else if (d == 5)
		{
			main();
		}
		else if (d == 6)
		{
			savemaps();
			return;
		}
		else
		{
			cout << "*****************************" << endl;
			cout << "INVALID NUMBER ,Choose from menu (1,2,3,4,5)" << endl;
			goto AZ;
		}


	}
	else if (IT == map2.end())
	{
	Y:cout << "Your E-mail Invalid!" << endl;
		cout << "You want .." << endl;
		cout << "1- Try Again" << endl;
		cout << "2- Home" << endl;
		cout << "3- Exit" << endl;
		cin >> d;

		if (d == 1)
			goto E;
		else if (d == 2)
		{
			main();
		}
		else if (d == 3)
		{
			savemaps();
			return;
		}
			
		else
		{
			cout << "*****************************" << endl;
			cout << "INVALID NUMBER ,Choose from menu (1,2,3)" << endl;
			goto Y;
		}
	}
	
}
void savemaps()
{
	ofstream out;
	unordered_map<int, Admin>::iterator h = map1.begin();
	out.open("map1.txt");
	while (h != map1.end())
	{
		out << h->second.train_num << "\t" << h->second.boarding << "\t" << h->second.destination << "\t" << h->second.seats << "\t" << h->second.fare << "\t" << h->second.date << endl;
		h++;
	
	}
	out.close();

	unordered_map<string, Passenger>::iterator y = map2.begin();
	out.open("map2.txt");
	while (y != map2.end())
	{
		out << y->second.email << "\t" << y->second.pass << "\t" << y->second.name << endl;
		y++;

	}
	out.close();


	unordered_map<string, Passenger>::iterator z = map3.begin();
	out.open("map3.txt");
	while (z != map3.end())
	{
		out << z->second.email << "\t" << z->second.pass << "\t" << z->second.name << "\t" << z->second.boarding_point << "\t" << z->second.destination_point << "\t" << z->second.Tnum << "\t" << z->second.Date << endl;
		z++;

	}
	out.close();
}
void Loadmaps()
{
	ifstream in;
	
	int tn,s;
	string b, d, D;
	double f;
	
	in.open("map1.txt");
	while (in>>tn>>b>>d>>s>>f>>D)
	{
		Admin a(tn, b, d, s, f, D);
		map1[a.train_num] = a;
		
	}
	in.close();

	string E, P, N;
	in.open("map2.txt");
	while (in >> E >> P >> N)
	{
		Passenger p(E, P, N);
		map2[p.email] = p;

	}
	in.close();

	in.open("map3.txt");
	while (in >> E >> P >> N >> b >> d >> tn >> D)
	{
		Passenger passe;
		passe.Passenger22(E, P, N, b, d, D, tn);
		map3[passe.email] = passe;

	}
	in.close();
	
}