#include "Student.h"

Student::Student(string i_ID, string i_FirstName, string i_LastName)
	: m_FirstName{ i_FirstName }, m_LastName{ i_LastName }
{
	if (!isValidID(i_ID)) throw Bad_ID;
	else m_ID = stoi(i_ID);
	if (!isValidName(i_FirstName)) throw Bad_FirstName;
	if (!isValidName(i_LastName)) throw Bad_LastName;
}



Student::Student(ifstream& in)
{
	in >> *this;
}

Student::Student(const Student& other)
{
	m_ID = other.m_ID;
	m_FirstName = other.m_FirstName;
	m_LastName = other.m_LastName;
}

Student::Student(Student&& other)
{
	*this = other;
}

bool Student::isValidID(string i_ID) {

	bool result = true;

	for (char ch : i_ID)
	{
		if (ch < '0' || ch > '9')
			result = false;
	}

	return result;
}

bool Student::isValidName(string i_Name) {

	return !i_Name.empty();
}

bool Student::operator>(const Student &other) const
{
	return (m_ID > other.m_ID);
}

bool Student::operator<(const Student &other) const
{
	return (m_ID < other.m_ID);
}

const Student& Student::operator=(const Student &other)
{
	if (this != &other)
	{
		m_ID = other.m_ID;
		m_FirstName = other.m_FirstName;
		m_LastName = other.m_LastName;
	}
	return *this;
}

istream& operator>>(istream &in, Student &p)
{
	in >> p.m_ID >> p.m_FirstName >> p.m_LastName;
	return in;
}

void Student::Swap(Student** a, Student** b)
{
	Student* temp = *a;
	*a = *b;
	*b = temp;
}
