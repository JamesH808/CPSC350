#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <exception>
#include <string>
#include "linkedlist.h"
using namespace std;

class Faculty{

    public:
        Faculty(); //default constructor
        Faculty(int I, string N, string L, string D, int* A, int arraysize); //overloaded constructor
        virtual ~Faculty(); // destructor

        //core functions
        string get_name() const;
        string get_level() const;
        string get_department() const;
        int get_ID() const;
        void print_info();
        string get_advisee() const;
        bool remove_advisee(int studID) const;
        bool studIDcheck(int studID) const;
        bool add_advisee(int studID) const;

        /*use this to compare ID's*/
        friend bool operator< (const Faculty& c1, const Faculty& c2);
        friend bool operator> (const Faculty& c1,  int c2);
        friend bool operator!= (const Faculty& c1, const Faculty &c2);
        friend bool operator!= (const Faculty& c1, int c2);
        friend bool operator== (const Faculty& c1, int c2);
        friend bool operator== (int c2,const Faculty& c1);
        friend ostream& operator<< (ostream& os, const Faculty& student);
        /*this can be used for advisor ID's*/

        /*TODO: connect this with faculty later*/
        //friend bool operator== (const Student& c1, const Faculty& c2);



    private:
        int ID;
        string name;
        string level;
        string department;
        /*TODO: MAKE THIS A LINKED LIST OF ADVISEES*/
        LinkedList<int>* advisees;


};





#endif