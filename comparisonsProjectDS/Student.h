#pragma once
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Student {

private:
	long m_ID;
	string m_FirstName;
	string m_LastName;

	const string Bad_ID = "Bad ID";

	const string Bad_FirstName = "Bad first name";
	const string Bad_LastName = "Bad last name";

public:
	Student(string i_ID, string i_FirstName, string i_LastName);
	Student() = default;
	Student(ifstream& in);
	Student(const Student& other);
	Student(Student&& other);
	long getId() { return m_ID; }

	string getFirstName() { return m_FirstName; }
	string getLastName() { return m_LastName; }
	//	bool operator<(const Student& other) const;
	//	bool operator>(const Student& other) const;
	const Student& operator=(const Student& other);
	friend istream& operator>>(istream& in, Student& p);
	static void Swap(Student** a, Student** b);

private:
	bool isValidID(string i_ID);
	bool isValidName(string i_name);
};
