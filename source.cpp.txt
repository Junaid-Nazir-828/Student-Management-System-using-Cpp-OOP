#include "Source_7.h"

using namespace std;

void student_record::add_student() {
	system("cls");
	fstream file; 
	
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << "\t\t\t| Add New Student Details |\n";
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << endl;

	cout << "Enter Student Name:\n";
	cin >> student_name;
	cout << "Enter Student ID:\n";
	cin >> student_id;
	cout << "Enter Student Course:\n";
	cin >> course_enrolled;
	cout << "Enter Student Email:\n";
	cin >> email;
	cout << "Enter Student Address:\n";
	cin >> address;
	cout << "Enter Student Contact Number:\n";
	cin >> contact;
	//creating file named "record_student.txt" to store info
	file.open("record_student.txt", ios::app | ios::out);
	file << " " << student_name << " " << student_id << " " << course_enrolled << " " << email << " " << address
		<< " " << contact << " \n";
	file.close();
}
void student_record::view_record() {
	system("cls");
	
	cout << endl;
	cout << "\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << "\t\t\t\t\t| Show Student Record |\n";
	cout << "\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << endl;

	fstream file;
	file.open("record_student.txt", ios::in);
	int student_number = 0;
	if (!file) {		
		cout << "!!!!----No Such File Exists----!!!!\n";
		file.close();
	}
	else {
		file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;
		while (!file.eof()) {
			cout << endl;
			student_number++;
			cout << "\t\t\tStudent Number: " << student_number << endl;
			cout << "\t\t\tStudent Name: " << student_name << endl;
			cout << "\t\t\tStudent ID: " << student_id << endl;
			cout << "\t\t\tStudent Course: " << course_enrolled << endl;
			cout << "\t\t\tStudent Email: " << email << endl;
			cout << "\t\t\tStudent Address: " << address << endl;
			cout << "\t\t\tStudent Contact Number: " << contact << endl;
			file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;
		}
		if (student_number == 0) {
			cout << "!!!!----No Data Exists----!!!!\n";
		}
	}
	file.close();
}
void student_record::change() {
	system("cls");
	fstream file, file_1;
	cout << endl;
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << "\t\t\t| Change Student Record |\n";
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << endl;
	int find = 0;
	string roll_number;
	file.open("record_student.txt", ios::in);
	if (!file) {
		cout << "!!!!----No Such File Exists----!!!!\n";
		file.close();
	}
	else {
		cout << "Enter ID of the student:\n";
		cin >> roll_number;
		file_1.open("student.txt", ios::app | ios::out);
		file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;
		while (!file.eof()) {
			if (roll_number != student_id) {
				file_1 << " " << student_name << " " << student_id << " " << course_enrolled << " " << email << " " << address
					<< " " << contact << " \n";
			}
			else {
				cout << endl;
				cout << "Enter Student Name:\n";
				cin >> student_name;
				cout << "Enter Student ID:\n";
				cin >> student_id;
				cout << "Enter Student Course:\n";
				cin >> course_enrolled;
				cout << "Enter Student Email:\n";
				cin >> email;
				cout << "Enter Student Address:\n";
				cin >> address;
				cout << "Enter Student Contact Number:\n";
				cin >> contact;
				file_1 << " " << student_name << " " << student_id << " " << course_enrolled << " " << email << " " <<
					address << " " << contact << " \n";
				find++;
			}
			file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;
		}
		if (find == 0) {
			cout << "\t\t!!!---Unable to find Student with entered ID---!!!\n";
		}
		file.close();
		file_1.close();
		remove("record_student.txt");
		rename("student.txt", "record_student.txt");
	}
}
void student_record::find_student() {
	system("cls");
	
	cout << endl;
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << "\t\t\t| Search Student Record |\n";
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << endl;
	
	fstream file;
	file.open("record_student.txt", ios::in);

	if (!file) {
		cout << "!!!!----No Such File Exists----!!!!\n";
	}
	else {
		int find = 0;
		string roll_number;
		cout << "Enter Student ID of which you want to see data:\n";
		cin >> roll_number;

		file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;

		while (!file.eof()) {
			if (roll_number == student_id) {
				cout << endl;
				cout << "\t\t\tStudent Name: " << student_name << endl;
				cout << "\t\t\tStudent ID: " << student_id << endl;
				cout << "\t\t\tStudent Course: " << course_enrolled << endl;
				cout << "\t\t\tStudent Email: " << email << endl;
				cout << "\t\t\tStudent Address: " << address << endl;
				cout << "\t\t\tStudent Contact Number: " << contact << endl;
				find++;
			}
			file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;

		}
		if (find == 0) {
			cout << "\t\t!!!---Unable to find Student with entered Roll Number---!!!\n";
		}
		file.close();
	}
}
void student_record::remove_student() {
	system ("cls");
	
	cout << endl;
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << "\t\t\t| Delete Student Record |\n";
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << endl;
	
	fstream file, file_1;
	string roll_number;
	int find = 0;
	file.open("record_student.txt", ios::in);
	if (!file) {
		cout << "!!!!----No Such File Exists----!!!!\n";
	}
	else {
		cout << "Enter ID of the student:\n";
		cin >> roll_number;
		file_1.open("student.txt", ios::app | ios::out);
		file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;
		while (!file.eof()) {
			if (roll_number != student_id) {
				file_1 << " " << student_name << " " << student_id << " " << course_enrolled << " " << email << " " <<
					address << " " << contact << " \n";
			}
			else {
				find++;
				cout << endl;
				cout << "\t\t!!!---Data Successfully Deleted---!!!\n";
			}
			file >> student_name >> student_id >> course_enrolled >> email >> address >> contact;
		}
		if (find == 0) {
			cout << "\t\t!!!---Unable to find Student with entered Student ID---!!!\n";
		}
		file_1.close();
		file.close();
		remove("record_student.txt");
		rename("student.txt", "record_student.txt");
	}
}
void student_record::options() {
beginning:
	
	int select;

	cout << endl;
	cout << "\t\t\t++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t ! Air University Student Management System !\n";
	cout << "\t\t\t++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << endl << endl;

	cout << "\tPress 1 to enter new student in database\n";
	cout << "\tPress 2 to display all students in database\n";
	cout << "\tPress 3 to change student's detail in database\n";
	cout << "\tPress 4 to search student in database\n";
	cout << "\tPress 5 to delete student record in database\n";
	cout << "\tPress 6 to close system\n";
	cout << endl;

	cout << "enter your choice here:\t";
	cin >> select;
	
	char z;
	char x;
	char o;
	char p;
	if (select == 1) {
		do {
			add_student();
			cout << endl;
			cout << "Do you want to enter new student [Y/N]\n";
			cin >> z;
		} while (z == 'y' || z == 'Y');
		cout << endl << endl;
		cin.ignore();
		cout << "\t\t\t!!++press enter to return to main menu++!!\n";
		cout << "\t\t\t\t\t";
		cin.get();
		system("cls");
	}
	else if (select == 2) {
		view_record();
		cout << endl << endl;
		cin.ignore();
		cout << "\t\t\t!!++press enter to return to main menu++!!\n";
		cout << "\t\t\t\t\t";
		cin.get();
		system("cls");
	}
	else if (select == 3) {
		do {
			change();
			cout << endl;
			cout << "Do you want to change any other record [Y/N]\n";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		cout << endl << endl;
		cin.ignore();
		cout << "\t\t\t!!++press enter to return to main menu++!!\n";
		cout << "\t\t\t\t\t";
		cin.get();
		system("cls");
	}
	else if (select == 4) {
		do {
			find_student();
			cout << endl;
			cout << "Do you want to find any other record [Y/N]\n";
			cin >> o;
		} while (o == 'y' || o == 'Y');
		cout << endl << endl;
		cin.ignore();
		cout << "\t\t\t!!++press enter to return to main menu++!!\n";
		cout << "\t\t\t\t\t";
		cin.get();
		system("cls");
	}
	else if (select == 5) {
		do {
			remove_student();
			cout << endl;
			cout << "Do you want to remove any other record [Y/N]\n";
			cin >> p;
		} while (p == 'y' || p == 'Y');
		cout << endl << endl;
		cin.ignore();
		cout << "\t\t\t!!++press enter to return to main menu++!!\n";
		cout << "\t\t\t\t\t";
		cin.get();
		system("cls");
	}
	else if (select == 6) {
		system("cls");
		cout << endl << endl << endl;
		cout << "\t\t\t!!!---Program Exited---!!!\n";
		exit(0);
	}
	if (select < 1 || select > 6) {
		int times = 0;
		while (times < 3) {
			system("cls");

			cout << "\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << "\t\t\t!!!---Wrong Number Entered---!!!\n";
			cout << "\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << endl;

			Sleep(1500);

			cout << "\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << "\t\t!!!---Please Enter your choice again---!!!\n";
			cout << "\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cout << endl;

			Sleep(1000);
			cout << endl << endl;
			cout << "\tPress 1 to enter new student in database\n";
			cout << "\tPress 2 to display all students in database\n";
			cout << "\tPress 3 to modify student's detail in database\n";
			cout << "\tPress 4 to search student in database\n";
			cout << "\tPress 5 to delete student record in database\n";
			cout << "\tPress 6 to close system\n";
			cout << endl;
			cout << "enter your choice here:\t";
			cin >> select;
			times++;
		}
		if (times == 3) {
			system("cls");

			cout << endl << endl << endl;
			cout << "\t\t!!!***Wrong Choice Entered Three Times***!!!\n";
			cout << "\t\t\t!!!---Please Log in again---!!!\n";
			exit(0);
		}
	}
		goto beginning;
}
