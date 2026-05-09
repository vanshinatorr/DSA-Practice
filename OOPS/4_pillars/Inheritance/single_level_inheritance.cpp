/*
========================================================
        SINGLE INHERITANCE IN C++
========================================================

Topic:
-> Inheritance
-> Parent & Child Class
-> Protected Members
-> Constructor Calling Order

Concept:
-> Child class inherits properties of Parent class.
-> Parent constructor executes first.
-> Child constructor executes after parent.

========================================================
*/

#include <iostream>
using namespace std;

/*
========================================================
                    PARENT CLASS
========================================================
*/

class Human
{
protected:
    // Accessible inside child class
    string name;

public:

    // Parent Constructor
    Human(string n)
    {
        name = n;
    }
};

/*
========================================================
                    CHILD CLASS
========================================================
*/

class Student : public Human
{
private:
    int roll_no;

public:

    /*
    ----------------------------------------------------
    Child Constructor
    ----------------------------------------------------

    : Human(n)

    -> Calls Parent Class Constructor first
    -> Initializes Parent Part of Object
    */

    Student(string n, int r) : Human(n)
    {
        roll_no = r;
    }

    /*
    ----------------------------------------------------
    Display Function
    ----------------------------------------------------
    */

    void display()
    {
        cout << "Name     : " << name << endl;
        cout << "Roll No  : " << roll_no << endl;
    }
};

/*
========================================================
                        MAIN FUNCTION
========================================================
*/

int main()
{
    // Object Creation
    Student s1("Vansh", 101);

    // Function Call
    s1.display();

    return 0;
}

/*
========================================================
                        OUTPUT
========================================================

Name     : Vansh
Roll No  : 101

========================================================
                        FLOW
========================================================

main()
   ↓
Student object created
   ↓
Parent Constructor called first
   ↓
name initialized
   ↓
Child Constructor called
   ↓
roll_no initialized
   ↓
display() function called
   ↓
Output printed

========================================================
*/
