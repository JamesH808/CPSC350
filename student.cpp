#include "student.h"

Student::Student(){
     ID = 0;
     name = ' ';
     level = ' ';
     major = ' ';
     GPA = 0;
     advisor= 0;
}


Student::Student(int I, string N, string L, string M, double G, int A){
    ID = I;
     name = N;
     level = L;
     major = M;
     GPA = G;
     advisor= A;
}

Student::~Student(){}

string Student::get_name() const
{
    return name;
}
int Student::get_ID() const
{
    return ID;
}
string Student::get_level() const
{
    return level;
}
string Student::get_major() const
{
    return major;
}


double Student::get_GPA() const
{
    return GPA;
}

int Student::get_advisor() const
{
    return advisor;
}


void Student::updateID(int replacement)
{
    advisor = replacement;
}

void Student::print_info() {
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Advisor: " << advisor << endl; 
}

bool operator< (const Student &c1, const Student &c2)
{
    if(c1.get_ID() < c2.get_ID()) return true;
    else return false;
}

bool operator> (const Student &c1,  int c2)
{
    if(c1.get_ID() > c2) return true;
    else return false;
}

bool operator!= (const Student& c1, const Student &c2) {
    if(c1.get_ID() != c2.get_ID()) return true;
    else return false;
}

bool operator!= (const Student& c1, int c2) {
    if(c1.get_ID() != c2) return true;
    else return false;
}

bool operator== (const Student& c1, int c2) {
    if(c1.get_advisor() == c2) return true;
    else return false;
}

ostream& operator<< (ostream& os, const Student& student) {
        os << "ID: " << student.get_ID() << endl;
        os << "Name: " <<student.get_name() << endl;
        os << "Level: " <<student.get_level() << endl;
        os << "Major: " <<student.get_major() << endl;
        os << "GPA: " <<student.get_GPA() << endl;
        os << "Advisor: " <<student.get_advisor() << endl;
        return os;
 }




//when a faculty is deleted, we assume that a student exists who was under this advisor, 
//find the student who has this advisor id and change it to a different adivsor