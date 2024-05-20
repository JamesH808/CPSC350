#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <exception>
#include <string>
#include "faculty.h"
using namespace std;

class Student{

    public:
        Student(); //default constructor
        Student(int I, string N, string L, string M, double G, int A); //overloaded constructor
        virtual ~Student(); // destructor

        //core functions
        string get_name() const;
        string get_level() const;
        string get_major() const;
        double get_GPA() const;
        int get_ID() const;
        void print_info();
        int get_advisor() const;
        void updateID(int replacement);

        /*use this to compare ID's*/
        friend bool operator< (const Student& c1, const Student& c2);
        friend bool operator> (const Student& c1,  int c2);
        friend bool operator!= (const Student& c1, const Student &c2);
        friend bool operator!= (const Student& c1, int c2);
        friend ostream& operator<< (ostream& os, const Student& student);
        friend bool operator== (const Student& c1, int c2);
        /*this can be used for advisor ID's*/

        /*TODO: connect this with faculty later*/
        //friend bool operator== (const Student& c1, const Faculty& c2);



    private:
        int ID;
        string name;
        string level;
        string major;
        double GPA;
        int advisor;

};





#endif