


#include <iostream>
#include <vector>

using namespace std;

class Person {
private:
	int age;
public:
	Person() {
		cout << "Person()" << endl;
	}
 
	~Person() {
		cout << "~Person()" << endl;
	}
};
 
class Student :public Person {
private:
	int sno;
public:
	Student() {
		cout << "Student()" << endl;
	}
 
	~Student() {
		cout << "~Student()" << endl;
	}
};
 
class Teacher :public Person {
private:
	int tno;
public:
	Teacher() {
		cout << "Teacher()" << endl;
	}
	~Teacher() {
		cout << "~Teacher()" << endl;
	}
};
 
int main ( int argc ,char* argv[]) {
    
    Person p;
	Student s;
	Teacher t;
    system("pause");
    return 0 ;
}