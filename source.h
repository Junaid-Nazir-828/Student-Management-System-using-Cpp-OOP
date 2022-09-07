#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
#include<cstdio>

using namespace std;

class student_record {
private:
	string student_name;
	string student_id;
	string course_enrolled;
	string email;
	string address;
	string contact;
public:
	void options();			//function to display menu
	void add_student();		//function to add new student
	void view_record();		//function to view all students record in file
	void change();			//function to change any student's record
	void find_student();	// function search any student
	void remove_student();  //function to remove any student
};
