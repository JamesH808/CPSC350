#include "faculty.h"

Faculty::Faculty(){
     ID = 0;
     name = ' ';
     level = ' ';
     department = ' ';
}


Faculty::Faculty(int I, string N, string L, string D, int* A, int arraysize){
    ID = I;
     name = N;
     level = L;
     department = D;
     advisees = new LinkedList<int>();
     for(int i=0; i < arraysize ; i++){
        advisees->insertFront(A[i]);
     }
     
}

Faculty::~Faculty(){}

string Faculty::get_name() const
{
    return name;
}
int Faculty::get_ID() const
{
    return ID;
}
string Faculty::get_level() const
{
    return level;
}
string Faculty::get_department() const
{
    return department;
}

/*TODO: WHAT IS THIS BEING USED FOR AND DOES IT NEED TO RETURN JUST ONE OR ALL*/
string Faculty::get_advisee() const
{
    int i = 0;
    string all = " ";
    for(int i = 0; i < advisees->getSize(); i++){
        all += to_string(advisees->get(i));
        all += " ";
    }
    return all;
}

bool Faculty::studIDcheck(int studID) const{
    int check;
    check = advisees->find(studID);
    if(check == -1){
        return false;
    } else {
        return true;
    }
}


bool Faculty::remove_advisee(int studID) const{
    if(advisees->getSize() < 2){
        advisees->removeFront();
        return 1;
    } else if(advisees->getSize() > 1){
        advisees->removeNode(studID);
        return 1;
    } else {
        return -1;
    }

}

bool Faculty::add_advisee(int studID) const{
    int result;
    advisees->insertFront(studID);
    return true;

}

void Faculty::print_info() {
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Department: " << department << endl;
    cout << "Advisee(s): " << advisees << endl; 
}

bool operator< (const Faculty &c1, const Faculty &c2)
{
    if(c1.get_ID() < c2.get_ID()) return true;
    else return false;
}

bool operator> (const Faculty &c1,  int c2)
{
    if(c1.get_ID() > c2) return true;
    else return false;
}

bool operator!= (const Faculty& c1, const Faculty &c2) {
    if(c1.get_ID() != c2.get_ID()) return true;
    else return false;
}

/*change was made here?*/
bool operator!= (const Faculty& c1, int c2) {
    if(c1.get_ID() != c2) return false;
    else return true;
}

bool operator== (const Faculty& c1, int c2) {
    if(c1.studIDcheck(c2)) return true;
    else return false;
}

bool operator== (int c2,const Faculty& c1) {
    if(c1.remove_advisee(c2)) return true;
    else return false;
}


ostream& operator<< (ostream& os, const Faculty& faculty) {
        os << "ID: " << faculty.get_ID() << endl;
        os << "Name: " <<faculty.get_name() << endl;
        os << "Level: " <<faculty.get_level() << endl;
        os << "Department: " << faculty.get_department() << endl;
        os << "Advisor: " << faculty.get_advisee() << endl; 
        return os;
 }


// bool operator> (const Student &c1, const Student &c2)
// {
//     if(c1.getArrivalTime() < c2.getArrivalTime()) return true;
//     else return false;
// }