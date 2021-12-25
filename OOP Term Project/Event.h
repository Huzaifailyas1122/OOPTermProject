#pragma once
#include"Costumer.h"


class Event : public Costumer
{
private:
	string E_name;//event name
	string timeSlot1 = "9:00 - 11:00";//time slot1
	string timeSlot2 = "12:00 - 14:00";//time slot2
	string timeSlot3 = " 15:00 - 17:00";//time slot3
	int id = 1000;//Id of list of costumers added
	date Event_date;//event date
	int Eventoption;//user choice input for events
	void Addevent();//for case 1 
	void EditEventbydate();//for case 2 where user wants to edit his event date
	void EditEventbytime();//for case 2 where user wants to edit his event time

public:
	Event();
	Event(string, date, int);
	void options();
};

Event::Event() :E_name(""), Event_date(0, 0, 0), Eventoption(0)
{}

Event::Event(string Eventname, date D, int opt) : E_name(Eventname), Event_date(D), Eventoption(opt)
{}

void Event::Addevent()
{
	int day = 32, month, year;
	system("CLS");
	cout << "Event Name : ";
	cin >> E_name;
	ifstream Checkdate("Info.txt", ios::in);//variable of ifstream to read a file for check
	string checkfordateexistence;
	string savefile;//string to save file in it
	while (day >= 32 || month >= 13 || year < 2021)
	{
		cout << "Enter Day : ";
		cin >> day;
		cout << "Enter month : ";
		cin >> month;
		cout << "Enter year : ";
		cin >> year;
		system("CLS");
		cout << "Enter Valid Dates PLZ" << endl;

		string stringday = to_string(day);//converting to string 
		string stringmonth = to_string(month);//converting to month
		string stringyear = to_string(year);//converting to year
		checkfordateexistence.append(stringday);
		checkfordateexistence.append("/");
		checkfordateexistence.append(stringmonth);
		checkfordateexistence.append("/");
		checkfordateexistence.append(stringyear);

		while (!Checkdate.eof())
		{
			while (getline(Checkdate, savefile))
			{
				size_t found = savefile.find(checkfordateexistence);

				if (found != std::string::npos)
				{
					// Slot already booked
					//Testing github
					//created development branch
				}
				
				if (checkfordateexistence == savefile)
				{
					cout << "The date is already setted PLZ enter again " << endl;
					cout << "Enter Day : ";
					cin >> day;
					cout << "Enter month : ";
					cin >> month;
					cout << "Enter year : ";
					cin >> year;
					system("CLS");
				}
				else
				{
					break;
				}
			}

		}
		cout << endl;
		Event_date.Setday(day);//setting event day 
		Event_date.Setmonth(month);//setting event month
		Event_date.Setyear(year);//setting event year
		system("CLS");
		cout << "Enter Your First Name : ";
		cin >> C_FName;//costumer first name
		cout << "Enter Your Last Name : ";
		cin >> C_LName;//costumer last name
		cout << "Enter Your Email : ";
		cin >> C_Email;//costumer email
		cout << "Enter Number : ";
		cin >> C_Number;//costumer number
		cout << endl;
		system("CLS");
		ofstream writeTiming("Time.txt", ios::out);//writing in the file
		writeTiming << "Select Event Timing \n1- 9:00 - 11:00 \n2- 12:00 - 14:00 \n3- 15:00 - 17:00" << endl;
		ifstream Readtiming("Time.txt", ios::in);//reading from the file
		string time;//string for copying written file
		int timechoice;
		while (getline(Readtiming, time)) {
			// Output the text from the file
			cout << time << "\n";//\n is used bcoz getline is used just for one line reading
		}
		cout << "\nYour Slot choice : ";
		cin >> timechoice;//user choice of time slot


		ifstream ListOfcostumers("Info.txt", ios::in);//to show listed costumers
		string List;
		while (getline(ListOfcostumers, List))
		{
			string idValue = List.substr(0, 1);
			if (idValue != "I")
			{
				id = stoi(idValue);
			}
		}

		id = id + 1;

		ofstream SavingInfo("Info.txt", ios::app);//saving info of customers in file
		switch (timechoice)
		{
		case 1:
			SavingInfo << id << "\t" << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << "\t" << timeSlot1 << endl;
			break;
		case 2:
			SavingInfo << id << "\t" << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << "\t" << timeSlot2 << endl;
			break;
		case 3:
			SavingInfo << id << "\t" << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << "\t" << timeSlot3 << endl;
			break;
		}


		//read complete list -> id 1,2,3,4,5 

		cout << "Event Booked Successfully..............." << endl;
		system("pause");
		system("CLS");
	}
}

void Event::EditEventbydate()
{
	int day = 32, month, year, previoustimeslot;//previous date which has to be changed 
	ifstream Temp("Info.txt");//temporary for editing
	ifstream Readtiming("Time.txt", ios::in);//reading from the file
	string temp;//temp string to copy
	string Time;//string to copy time
	cout << "what was your previous date ";//taking previous date to check for the event
	while (day >= 32 || month >= 13 || year < 2021)
	{
		cout << "Enter Day : ";
		cin >> day;
		cout << "Enter month : ";
		cin >> month;
		cout << "Enter year : ";
		cin >> year;
		system("CLS");
		cout << "Enter Valid Dates PLZ" << endl;

	}
	system("CLS");

	//input
	//ifstream ListOfcostumers("Info.txt", ios::in);//to show listed costumers
	//string List;
	//while (getline(ListOfcostumers, List))
	//{
	//	string idValue = List.substr(0, 1);
	//	if (idValue != "I")
	//	{
	//		id = stoi(idValue);
	//		//if (id == input) 
	//		//{
	//		//	//

	//		//}
	//	}
	//}


	while (!Temp.eof())
	{
		int newday = 32, newmonth, newyear;
		if (day == Event_date.Getday() && month == Event_date.Getmonth() && year == Event_date.Getyear())
		{
			cout << "We got your event date kindly add new date to change " << endl;//after getting user input date in file 
			while (newday >= 32 || newmonth >= 13 || newyear < 2021)
			{
				cout << "Enter Day : ";
				cin >> newday;
				cout << "Enter month : ";
				cin >> newmonth;
				cout << "Enter year : ";
				cin >> newyear;
				system("CLS");
				cout << "Enter Valid Dates PLZ" << endl;
				system("CLS");
				while (!Temp.eof())
				{
					if (newday == Event_date.Getday() && newmonth == Event_date.Getmonth() && newyear == Event_date.Getyear())
					{
						cout << "The date is already setted PLZ enter again " << endl;
						cout << "Enter Day : ";
						cin >> newday;
						cout << "Enter month : ";
						cin >> newmonth;
						cout << "Enter year : ";
						cin >> newyear;
						system("CLS");
					}
					else
						break;
				}

			}
			Event_date.Setday(newday);//setting to event date
			Event_date.Setmonth(newmonth);
			Event_date.Setyear(newyear);
			cout << "What was your previous time slot" << endl;
			while (getline(Readtiming, Time)) {
				// Output the text from the file
				cout << Time << "\n";//\n is used bcoz getline is used just for one line reading
			}
			cout << "Your slot : ";
			cin >> previoustimeslot;
			system("CLS");//clear screen
			cout << "Event date Changed" << endl;
			ofstream changeddate("Info.txt", ios::app);//after changing in date to write in file
			if (previoustimeslot == 1)
			{
				changeddate << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << "\t" << timeSlot1 << endl;
			}
			else if (previoustimeslot == 2)
			{
				changeddate << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << "\t" << timeSlot2 << endl;
			}
			else if (previoustimeslot == 3)
			{
				changeddate << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << "\t" << timeSlot3 << endl;
			}
			Temp.open("Info.txt", ios::in);//after date changing to read file 
			//while (getline(Temp, temp)) {
			//	// Output the text from the file
			//	cout << temp << "\n";
			//}
			break;
		}
		else
		{
			cout << "Sorry we can't recognize you";
			break;
		}
	}
	Temp.close();

}

void Event::EditEventbytime()
{
	string firstname, lastname;
	int day = 32, month, year, Newtimechoice;
	ifstream Changetime("Time.txt", ios::in);//file opening to read for user new time
	ifstream readinfo("Info.txt", ios::in);
	ofstream writechangedtime("Info.txt", ios::app);//file opening to write for user new time
	string Temptime;//string temperory for time changing
	cout << "Enter your first name : ";
	cin >> firstname;//taking name to check whether costumer is enrolled or not
	cout << "Enter your last name : ";
	cin >> lastname;
	cout << "PLZ enter your Event Date " << endl;
	while (day >= 32 || month >= 13 || year < 2021)
	{
		cout << "Enter Day : ";
		cin >> day;
		cout << "Enter month : ";
		cin >> month;
		cout << "Enter year : ";
		cin >> year;
		system("CLS");
		cout << "Enter Valid Dates PLZ" << endl;

	}
	system("CLS");
	while (!readinfo.eof())
	{
		if (firstname == C_FName && lastname == C_LName && day == Event_date.Getday() && month == Event_date.Getmonth() && year == Event_date.Getyear())
		{
			while (getline(Changetime, Temptime))
			{
				cout << Temptime << "\n";
			}
			cout << "Choose New Time for Event : ";
			cin >> Newtimechoice;//enter user choice new time
			if (Newtimechoice == 1)
			{
				//writing in file after changing time
				writechangedtime << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << timeSlot1 << endl;
			}
			else if (Newtimechoice == 2)
			{
				//id=f user choose second time
				writechangedtime << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << timeSlot2 << endl;
			}
			else if (Newtimechoice == 3)
			{
				writechangedtime << E_name << "\t" << C_FName << C_LName << "\t\t" << Event_date.Getday() << "/" << Event_date.Getmonth() << "/" << Event_date.Getyear() << timeSlot3 << endl;
			}
			cout << "Time of event changed successfully....................." << endl;
			system("pause");
			system("CLS");
			break;
		}
		else
		{
			cout << "Sorry We can't find your information" << endl;
			break;
		}
	}
}

void Event::options()
{
	char Continue;

	ifstream ifs("Info.txt", std::ios::ate); // std::ios::ate means open at end
	if (ifs.tellg() == 0)
	{
		ofstream Info("Info.txt", ios::app);
		Info << "ID \tEventName \tCostumerName \t\tDate \t\t\tTime" << endl;
	}


	do {
		ofstream Eventoptions("Option.txt", ios::out);//writing in the file
		Eventoptions << "1- Add Event \n2- Edit Your Event  \n3- Detail of Events \n4- List of Events \n5- Scheduel \n6- Exit" << endl;
		string Eventopts;//string for copying written file
		ifstream Event_Options("Option.txt", ios::in);//reading from the file

		//// Use a while loop together with the getline() function to read the file line by line
		while (getline(Event_Options, Eventopts)) {
			//	// Output the text from the file
			cout << Eventopts << "\n";
		}
		cout << "\nYour choice : ";
		cin >> Eventoption;//user choice choosing event option
		system("CLS");


		if (Eventoption == 1)
		{
			Addevent();
			system("CLS");

		}
		else if (Eventoption == 2)
		{
			string Edit;//string for coping to show
			cout << "What you want to change " << endl;
			ofstream writeediting("Edit.txt", ios::out);//writing in the file
			writeediting << "1- Event date \n2- Event Time" << endl;
			ifstream readediting("Edit.txt", ios::in);//reading from the file

			// Use a while loop together with the getline() function to read the file line by line
			while (getline(readediting, Edit)) {
				// Output the text from the file
				cout << Edit << "\n";
			}
			int Editchoice;//user choice to edit what?
			cout << "\nYour choice : ";
			cin >> Editchoice;//user choice choosing event option
			system("CLS");
			switch (Editchoice)//case 2 switch
			{
			case 1:
			{
				EditEventbydate();
				break;
			}
			case 2:
			{
				EditEventbytime();
				break;
			}
			default:
				break;
			}


		}
		else if (Eventoption == 3)
		{

		}
		else if (Eventoption == 4)
		{
			ifstream ListOfcostumers("Info.txt", ios::in);//to show listed costumers
			string List;
			while (getline(ListOfcostumers, List))
			{
				cout << List << "\n";
				string id = List.substr(0, 1);
			}

		}
		else if (Eventoption == 5)
		{


		}
		else if (Eventoption == 6)
		{
			break;
		}
		cout << "\nDo You want to continue ? ";
		cin >> Continue;
		system("CLS");
	} while (Continue == 'Y' || Continue == 'y');
}