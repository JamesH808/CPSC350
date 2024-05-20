#ifndef SIM_H
#define SIM_H

#include "LazyBST.h"
#include "student.h"


class Sim{

    public:
        Sim(); //default constructor
        virtual ~Sim(); // destructor

        //core functions
        void runMain();
        int menuOptions();

        bool check_has(int facid);
        bool check_has_for_list(int* facid, int size);
        bool checkIDinlist(int studid);

        int choice;
        /*this is for students*/
        int x1;
        string x2;
        string x3;
        string x4;
        double x5;
        int x6;

        /*this is for faculty*/
        int y1;
        string y2;
        string y3;
        string y4;
        int y5;
        



    private:
    LazyBST<Student> studtree;
    LazyBST<Faculty> factree;
    int* studentlist;

    /*TODO: MAKE ONE FOR FACULTY LATER*/

};





#endif