// code for encapsulation and abstraction 

#include <bits/stdc++.h>
using namespace std;


class Student{
    private:
    string name  ; 
    int age ; 
    int roll_no ; 
    
    public:
    
    void setter(string m ,int a ,int r){
        name = m ; 
        age = a ; 
        roll_no  =r ; 
    }
    
    
    int getter(){
        return age; 
    }
    
} ; 


int main() {

	Student obj ; 
	obj.setter("vansh",20,101) ; 
	cout<<obj.getter() ; 
	

}
