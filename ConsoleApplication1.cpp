
#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
using namespace std;
multimap <int, string> savedPatient;
class Person 
{
protected:
	string name, family, address, phone;
	int age;
public:
	Person(string name="name", string family="family", string address="address", string phone="phonenumber", int age=0)
	{
		this->name = name;
		this->family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setFamily(string family) 
	{
		this->family = family;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}
	void setAge(int age) 
	{
		this->age = age;
	}
	string getName() const 
	{
		return name;
	}
	string getFamily()const 
	{
		return family;
	}
	string getAddress()const 
	{
		return address;
	}
	string getPhone()const 
	{
		return phone;
	}
	int getAge()const 
	{
		return age;
	}
	void report() const 
	{
		cout << setw(10) << name << setw(15) << " " << family << setw(25) << address << setw(15) << phone << setw(4) << age << endl;
		_getch();
	}
};

class Patient : public Person
{
private:
	int patientCode,drCode;
	string ill, doctor;/////////////////////----------------------
public:
	Patient(string name, string family, string address, string phone, int age, int patientCode=0, string ill="ilness", string doctor ="doctorName",int drCode=0) :Person( name = "name", family = "family", address = "address", phone = "phonenumber", age = 0)
	{
		this->patientCode = patientCode;
		this->ill = ill;
		this->doctor = doctor;
		this->drCode = drCode;

	}
	void setPatientCode(int patientCode) 
	{
		this->patientCode = patientCode;
	}
	void setIll(string ill)
	{
		this->ill = ill;
	}
	void setDoctor(string doctor)
	{
		this->doctor = doctor;
	}
	void setDrCode(int drCode)
	{
		this->drCode = drCode;
	}
	int getPatientCode()const 
	{
		return patientCode;
	}
	string getIll()const
	{
		return ill;
	}
	string getDoctor()const
	{
		return doctor;
	}
	int getDrCode()
	{
		return drCode;
	}
	void report() const
	{
		cout << setw(10) << name << setw(15) << " " << family << setw(25) << address << setw(15) << phone << setw(4) << age << setw(6) << patientCode << setw(10) << ill << setw(15) << doctor << setw(6) << drCode << endl;
		_getch();
	}
};

class Doctor :public Person
{
private:
	int codeDoctor;
	string specialty;
public:
	Doctor(string name, string family, string address, string phone, int age, int codeDoctor=0, string specialty="specialty") :Person(name = "name", family = "family", address = "address", phone = "phonenumber", age = 0)
	{
		this->codeDoctor = codeDoctor;
		this->specialty = specialty;
	}
	void setCodeDoctor(int codeDoctor)
	{
		this->codeDoctor = codeDoctor;
	}
	int getCodeDoctor()const
	{
		return codeDoctor;
	}
	void setSpecialty(string specialty)
	{
		this->specialty = specialty;
	}
	string getSpecialty()
	{
		return specialty;
	}
	void report() const 
	{
		cout << setw(10) << name << setw(15) << " " << family << setw(25) << address << setw(15) << phone << setw(4) << age << setw(6) << codeDoctor << setw(10) << specialty << endl;
		_getch();
	}
};

//#########################  Patient  ###########################

vector <Patient> listp, listp2;
fstream outputfile;
void writep() 
{
	int patientCode, age, drCode;
	string name, family, address, phone, doctor, ill;
	cout << "\n Enter the code of Patient: ";
	cin >> patientCode;
	cout << "\n Enter the name of Patient: ";
	cin >> name;
	cout << "\n Enter the family of Patient: ";
	cin >> family;
	cout << "\n Enter the address of Patient: ";
	cin >> address;
	cout << "\n Enter the phone of Patient: ";
	cin >> phone;
	cout << "\n Enter the doctor of Patient: ";
	cin >> doctor;
	cout << "\n Enter the code of doctor: ";
	cin >> drCode;
	cout << "\n Enter the ill of Patient: ";
	cin >> ill;
	cout << "\n Enter the age of Patient: ";
	cin >> age;
	listp.push_back(Patient(name, family, address, phone, age, patientCode, ill, doctor));
	outputfile.open("Patient.csv", ios::app);
	outputfile << name + "," + family + "," + address + "," + to_string(age) + phone + ","
		+ to_string(patientCode) + "," + ill + doctor << endl;
	savedPatient.insert(pair<int, string>(drCode, name + " " + family + " : " + ill));
}
void displayallPatients() 
{
	system("cls");
	cout << "\n\n\t\tALL PatientS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   patientCode   ill    doctor" << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listp.size(); i++)
		listp[i].report();
	_getch();
}
void displayonePatient(int patientCode) 
{
	system("cls");
	cout << "\n\n\t\tALL PatientS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   patientCode   ill    doctor" << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listp.size(); i++)
		if (listp[i].getPatientCode() == patientCode) 
			listp[i].report();
	_getch();
}
void modify(int patientCode) 
{
	string name, family, phone;
	int a;
	for (int i = 0; i < listp.size(); i++)
	{
		if (listp[i].getPatientCode() == patientCode) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: 
				cout << "Enter a name" << endl;
				cin >> name;
				listp[i].setName(name); 
				break;
			case 2: 
				cout << "Enter a family" << endl;
				cin >> family;
				listp[i].setFamily(family);
				break;
			case 3: 
				cout << "Enter a phone" << endl;
				cin >> phone; 
				listp[i].setPhone(phone); 
				break;
			default:
				cout << "Your entrance is wrong.";
			}
		}
	}
}
void deleteallPatient()
{
	listp.clear();
}
void delete_Patient(int patientCode)
{
	for (int i = 0; i < listp.size(); i++) 
		if (listp[i].getPatientCode() != patientCode) 
			listp2.push_back(listp[i]);
	listp = listp2;
	vector<Patient>().swap(listp2);
}
multimap <int, string> getSavedPatient()
{
	return savedPatient;
}

//#########################  Doctor  ###########################

vector <Doctor> listd, listd2;
fstream outputfiled;
void writed() 
{
	int codeDoctor, age;
	string name, family, address, phone, specialty;
	cout << "\n Enter the code of Doctor: ";
	cin >> codeDoctor;
	cout << "\n Enter the name of Doctor: ";
	cin >> name;
	cout << "\n Enter the family of Doctor: ";
	cin >> family;
	cout << "\n Enter the address of Doctor: ";
	cin >> address;
	cout << "\n Enter the phone of Doctor: ";
	cin >> phone;
	cout << "\n Enter the specialty of Doctor: ";
	cin >> specialty;
	cout << "\n Enter the age of Doctor: ";
	cin >> age;
	listd.push_back(Doctor(name, family, address, phone, age, codeDoctor, specialty));
	outputfiled.open("Doctor.csv", ios::app);
	outputfiled << name + "," + family + "," + address + "," + to_string(age) +","+ phone + ","
		+ to_string(codeDoctor) + "," + specialty << endl;
}
void displayallDrs() 
{
	system("cls");
	cout << "\n\n\t\tALL DOCTORS RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   doctorcode      specialty;" << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listd.size(); i++)
		listd[i].report();
	_getch();
}
void displayoneDr(int codeDoctor) ////-----------
{
	system("cls");
	cout << "\n\n\t\tONE DOCTOR RESULT \n\n";
	cout << "==========================================================\n";
	cout << "Name       Family        Address   Phone   age   doctorcode      specialty" << endl;
	cout << "==========================================================\n";
	for (int i = 0; i < listd.size(); i++)
		if (listd[i].getCodeDoctor() == codeDoctor)
			listd[i].report();
	_getch();
}
void modifyDrs(int codeDoctor)
{
	string name, family, phone;
	int a;
	for (int i = 0; i < listd.size(); i++)
	{
		if (listd[i].getCodeDoctor() == codeDoctor) 
		{
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "Enter a name" << endl;
				cin >> name; 
				listd[i].setName(name); 
				break;
			case 2: 
				cout << "Enter a family" << endl; 
				cin >> family;
				listd[i].setFamily(family);
				break;
			case 3: 
				cout << "Enter a phone" << endl; 
				cin >> phone;
				listd[i].setPhone(phone); 
				break;
			default:
				cout << "Your  entrance is wrong."; 
			}
		}
	}
}
void deleteallD() 
{
	listd.clear();
}
void delete_D(int doctorCode)
{
	for (int i = 0; i < listd.size(); i++) 
		if (listd[i].getCodeDoctor() != doctorCode) 
			listd2.push_back(listd[i]);
	listd = listd2;
	vector<Doctor>().swap(listd2);
}
void printSavedPatient(int code) 
{
	multimap<int, string> list = getSavedPatient();
	for (multimap<int, string> ::iterator i = list.begin(); i != list.end(); i++) 
		if (code == i->first)
			cout << i->second;
}

//###################################  MENU ####################################

//void intro() 
//{
//	system("cls");
//	cout << "\n\n\n\t\t  SYSTEM HOSPITAL";
//	cout << "\n\n\t\t  ADVANCED C++ PROJECT";
//	cout << "\n\n\n\tMADE BY : MAHBOOBE REZAEI";
//	cout << "\n\tSCHOOL : QOM HOSPITAL";
//	cin.get();
//}
void report_men()
{
	int  patientCode, codeDoctor;
	short int a;
	system("cls");
	cout << "\n\n\n\tREPORTs MENU";
	cout << "\n\n\t1. Patient Reports";
	cout << "\n\n\t2. Doctor Reports";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> a;
	switch (a)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n\n\tSELECT";
		cout << "\n\n\t1. All Patient Report";
		cout << "\n\n\t2. Patient Report";
		cout << "\n\n\t3. Number Of Patients";
		cout << "\n\n\n\tEnter Choice (1/2/3)? ";
		cin >> a;
		switch (a)
		{
		case 1:
			displayallPatients();
			break;
		case 2:
			cout << "\n Enter the code of Patient: ";
			cin >> patientCode;
			displayonePatient(patientCode);
			break;
		case 3:
			cout << "There is information of" << listp.size() << " patient(s) in list.\n";
			_getch();
			break;
		default:
			cout << "Your  entrance is wrong.";
			_getch();
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "\n\n\n\tSELECT";
		cout << "\n\n\t1. All Doctor Report";
		cout << "\n\n\t2. Doctor Report";
		cout << "\n\n\t3. Number Of Patients";
		cout << "\n\n\n\tEnter Choice (1/2/3)? ";
		cin >> a;
		switch (a)
		{
		case 1:
			displayallDrs();
			break;
		case 2:
			cout << "\n Enter the code of Doctor: ";
			cin >> codeDoctor;
			displayoneDr(codeDoctor);
			break;
		case 3:
			cout << "There is information of" << listd.size() << " doctor(s) in list.\n";
			_getch();
			break;
		default:
			cout << "Your  entrance is wrong.";
			_getch();
		}
		break;
	}
	default:
		cout << "Your  entrance is wrong.";
		_getch();
	}
}



void entry_men() 
{
	short int a;
	int code;
	char choice;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\n\t1.ENTRY MENU Patient";
	cout << "\n\n\t2.ENTRY MENU Doctor";
	cout << "\n\n\t3.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-3) ";
	cin >> a;
	switch (a)
	{
	case 1:
	{   
	system("cls");
	cout << "\n\n\n\tENTRY MENU Patient";
	cout << "\n\n\t1.CREATE Patient RECORD";
	cout << "\n\n\t2.MODIFY Patient RECORD";
	cout << "\n\n\t3.DELETE Patient RECORD";
	cout << "\n\n\t4.DELETE Patient RECORDS";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a)
	{
	case 1:
		do {
			writep();
			cout << "\n Patient record has been created";
			system("cls");
			cout << "Do you want to insert new record of Patient? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2:
		cout << "\nEnter the code of Patient " << endl;
		cin >> code; 
		modify(code); 
		break;
	case 3:
		cout << "\nEnter the code of Patient " << endl;
		cin >> code;
		delete_Patient(code);
		break;
	case 4:  deleteallPatient(); 
		break;
	case 5:
		break;
	default:
		cout << "Your  entrance is wrong.";
		_getch();
	}
	break;
	}
	case 2:
	{ 
	system("cls");
	cout << "\n\n\n\tENTRY MENU Doctor";
	cout << "\n\n\t1.CREATE Doctor RECORD";
	cout << "\n\n\t2.MODIFY Doctor RECORD";
	cout << "\n\n\t3.DELETE Doctor RECORD";
	cout << "\n\n\t4.DELETE Doctor RECORDS";
	cout << "\n\n\t5.SHOW A Doctor's Patient(s)";
	cout << "\n\n\t6.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-6) ";
	cin >> a;
	switch (a)
	{
	case 1:
		do {
			writed();
			cout << "\n Doctor record has been created";
			_getch();
			system("cls");
			cout << "Do you want to insert new record of Doctor? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: 
		cout << "\nEnter the code of Doctor " << endl;
		cin >> code; 
		modifyDrs(code);
		break;
	case 3:
		cout << "\nEnter the code of Doctor " << endl;
		cin >> code;
		delete_D(code);
		break;
	case 4: 
		deleteallD(); 
		break;
	case 5:
		cout << "\nEnter the code of Doctor " << endl;
		cin >> code;
		printSavedPatient(code);
		break;
	case 6: 
		break;
	default:
		cout << "Your  entrance is wrong.";
		_getch();
	}
	break;
	}
	case 3:
		break;
	default:
		cout << "Your  entrance is wrong.";
		_getch();
	}
}

int main()
{
	int a;
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. REPORT MENU";
		cout << "\n\n\t02. ENTRY/EDIT MENU";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
			report_men();
			break;
		case 2:
			entry_men();
			break;
		case 3:
			break;
		default:
			cout << "Your  entrance is wrong.";
			_getch();
		}
	} while (a != 3);
	return 0;
}


