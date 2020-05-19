#include "Person.h"

Person::Person(string i_ID, string i_FirstName, string i_LastName)
    : m_FirstName{ i_FirstName }, m_LastName{ i_LastName }
{
	if (!isValidID(i_ID)) throw Bad_ID;
	else m_ID = stoi(i_ID);
	if (!isValidName(i_FirstName)) throw Bad_FirstName;
	if (!isValidName(i_LastName)) throw Bad_LastName;
}

//Person::Person(string i_ID, string i_Name)
//{
//    if (!isValidID(i_ID)) throw Bad_ID;
//    else m_ID = stoi(i_ID);
//    if (!isValidName(i_Name)) throw Bad_Name;
//    else m_Name = i_Name;
//}

Person::Person(ifstream& in)
{
    in >> *this;
}

Person::Person(const Person& other)
{
	m_ID = other.m_ID;
//	m_Name = other.m_Name;
	m_FirstName = other.m_FirstName;
	m_LastName = other.m_LastName;
}

Person::Person(Person&& other)
{
    *this = other;
}

bool Person::isValidID(string i_ID) {

	bool result = true;

//	if (i_ID.length() != 9) result = false;

	for (char ch : i_ID)
	{
		if (ch < '0' || ch > '9')
			result = false;
	}

	return result;
}

bool Person::isValidName(string i_Name) {

	return !i_Name.empty();
}

bool Person::operator>(const Person &other) const
{
    return (m_ID > other.m_ID);
}

bool Person::operator<(const Person &other) const
{
    return (m_ID < other.m_ID);
}

const Person& Person::operator=(const Person &other)
{
    if(this != &other)
    {
        m_ID = other.m_ID;
//        m_Name = other.m_Name;
        m_FirstName = other.m_FirstName;
        m_LastName = other.m_LastName;
    }
    return *this;
}

istream& operator>>(istream &in, Person &p)
{
    in >> p.m_ID >> p.m_FirstName >> p.m_LastName;
    return in;
}

void Person::Swap(Person** a, Person** b)
{
    Person* temp = *a;
    *a = *b;
    *b = temp;
}
