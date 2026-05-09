/*
========================================
        MULTIPLE INHERITANCE
========================================

Human ----\
            → Student
City  -----/

========================================
*/

#include <iostream>
using namespace std;

/* Parent Class 1 */

class Human
{
protected:
    string name;

public:
    Human(string n)
    {
        name = n;
    }
};

/* Parent Class 2 */

class City
{
protected:
    string place;

public:
    City(string p)
    {
        place = p;
    }
};

/* Child Class */

class Student : public Human, public City
{
    int roll_no;

public:

    // Calling both parent constructors
    Student(string n, string p, int r)
        : Human(n), City(p)
    {
        roll_no = r;
    }

    void display()
    {
        cout << "Name     : " << name << endl;
        cout << "City     : " << place << endl;
        cout << "Roll No  : " << roll_no << endl;
    }
};

int main()
{
    Student s1("Vansh", "Jaipur", 101);

    s1.display();

    return 0;
}

/*
========================================
OUTPUT
========================================

Name     : Vansh
City     : Jaipur
Roll No  : 101

========================================
FLOW
========================================

Student object created
        ↓
Human constructor runs
        ↓
City constructor runs
        ↓
Student constructor runs
        ↓
display() called

========================================
*/
