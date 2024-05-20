#include "sim.h"

Sim::Sim(){
    choice = 0;
    int x1 = 0;
    string x2 = " ";
    string x3 = " ";
    string x4 = " ";
    double x5 = 0;
    int x6 = 0;
    int y1 = 0;
    string y2 = " ";
    string y3 = " ";
    string y4 = " ";
    int y5 = 0;
}

Sim::~Sim(){}


void Sim::runMain(){
    while(choice != 11){
        choice = menuOptions();
        if(choice == 1){
            if(studtree.isEmpty()){
                cout << "Please add a student, tree is empty" << endl;
            } else {
                studtree.printAscending();
            }
        } else if(choice == 2){
            if(factree.isEmpty()){
                cout << "Please add a faculty, tree is empty" << endl;
            } else {
                factree.printAscending();
            }

        } else if(choice == 3){
            cout << "Please enter an ID to search for: " << endl;
            int tofind;
            cin >> tofind;
            if(studtree.isEmpty()){
                cout << "Please add a student, tree is empty" << endl;
            } else {
                studtree.find(tofind);
            }
            
        } else if(choice == 4){
            cout << "Please enter an ID to search for: " << endl;
            int toFind;
            cin >> toFind;
            if(factree.isEmpty()){
                cout << "Please add a student, tree is empty" << endl;
            } else {
                factree.find(toFind);
            }
            
        }else if(choice == 5){
            cout << "Enter ID: " << endl;
            cin >> x1;
            cout << "Enter name: " << endl;
            cin >> x2;
            cout << "Enter level: " << endl;
            cin >> x3;
            cout << "Enter major: " << endl;
            cin >> x4;
            cout << "Enter GPA: " << endl;
            cin >> x5;
            cout << "Enter Advisor ID: " << endl;
            cin >> x6;
             /*check if the advisor exists before creating student and whether that advisor has that student in their list*/
            if(check_has(x6) && checkIDinlist(x1)){
                cout << "faculty exists and faculty has student as an advisee" << endl;
                Student stud(x1, x2, x3, x4, x5, x6);
                studtree.insert(stud);
            } else if(factree.isEmpty()){
                /*if there are no faculty yet, user will be encouraged to add a faculty with matching ID's*/
                cout << "faculty ID doesn't exist because there are no faculty" << endl;
                cout << "add a faculty with a matching ID and the advisees ID" << endl;
                Student stud(x1, x2, x3, x4, x5, x6);
                studtree.insert(stud);
            } else {
                cout << "student created, but please enter a valid faculty ID" << endl;
                Student stud(x1, x2, x3, x4, x5, x6);
                studtree.insert(stud);
            }

           
        } else if(choice == 6){
            if(studtree.isEmpty()){
                cout << "Please add a student, tree is empty" << endl;
            } else {
                cout << "Please enter the student's ID you would like to delete: " << endl;
                int todelete;
                cin >> todelete;
                if(studtree.deleteNode(todelete)){
                    cout << "student was deleted" << endl;
                    /*update faculty advisee list by deleting the advisee*/
                    factree.deleteadvisee(todelete);
                    cout << "the advisee was deleted from the faculty's list of students" << endl;
                }
            }
        }else if(choice == 7){
            cout << "Enter ID: " << endl;
            cin >> y1;
            cout << "Enter name: " << endl;
            cin >> y2;
            cout << "Enter level: " << endl;
            cin >> y3;
            cout << "Enter department: " << endl;
            cin >> y4;
            /*user will be able to add as many ID's as they want*/
            cout << "How many student's does this faculty have? " << endl;
            int number;
            cin >> number;
            studentlist = new int [number];
            for(int i = 0; i < number; i++){
                cout << "Enter Advisee" << endl;
                cin >> studentlist[i];
            }

            /*check if student exists in student tree, for all values in faculty's student listl*/
            if(check_has_for_list(studentlist, number)){
                cout << "student exists" << endl;
                Faculty fac(y1, y2, y3, y4, studentlist, number);
                factree.insert(fac);
            }else if(studtree.isEmpty()){
                /*if there are no faculty yet, user will be encouraged to add a faculty with matching ID's*/
                cout << "student ID doesn't exist because there are no students" << endl;
                cout << "add a student with a matching ID" << endl;
                Faculty fac(y1, y2, y3, y4, studentlist, number);
                factree.insert(fac);
            } else {
                cout << "enter a valid student ID" << endl;
            }

            delete[] studentlist;

        } else if(choice == 8){
            if(factree.isEmpty()){
                cout << "Please add a faculty, tree is empty" << endl;
            } else {
                cout << "Please enter the faculty's ID you would like to delete: " << endl;
                int toDelete;
                cin >> toDelete;
                
                if(factree.deleteNode(toDelete)){
                    cout << "faculty was deleted" << endl;
                    /*gotta check if u just deleated the only faculty member*/
                    if(factree.isEmpty()){
                        cout << "Please add a faculty, tree is empty" << endl;
                    } else{
                        int newid;
                        newid = factree.getrootID();
                        if(studtree.getstudAdvisor(toDelete, newid)){
                            cout << "Students were given new advisors" << endl;
                        }

                    }
                                   
                }
            }

        } else if(choice == 9){
            cout << "what is the student's id you would like to change?" << endl;
            int toupdate;
            cin >> toupdate;
            cout << "what will the new advisor id be? " << endl;
            int newid;
            cin >> newid;
            if(studtree.getstudAdvisor(toupdate, newid)){
                cout << "Student was given new advisor" << endl;
            }
            if(check_has(newid) && checkIDinlist(toupdate)){
                cout << "faculty exists and faculty has student as an advisee" << endl;
            } else {
                cout << "please add a faculty with an id that matches the updated advisor ID" << endl;
            }
        } else if(choice == 10){

            cout << "what faculty would you like to modify: " << endl;
            int fac;
            cin >> fac;
            cout << "what advisee would you like to remove: " << endl;
            int toremove;
            cin >> toremove;

            if(factree.removefromlist(fac, toremove)){
                cout << "advisee was removed from faculty" << endl;
                /*going to need to update the student to have a new advisor since their advisor removed them from their list*/
                int newid;
                /*this will be students new advisor*/
                newid = factree.getrootID();
                /*give student the root faculty as an advisor*/
                if(studtree.getstudAdvisor(toremove, newid)){
                    cout << "Student was given new advisor" << endl;
                } 
                if (factree.addadvisee(newid, toremove)){
                    cout << "Student was updated in new advisor" << endl;
                }else 
                {
                    cout << "error giving student new advisor" << endl;
                }
            } else {
                cout << "error removinig advisee from faculty" << endl;
            }
        }

    }

    /*print out options 1 and 2 to txt file*/
    studtree.printAscendingtofile("runLog.txt");
    factree.printAscendingtofile("runLog.txt");

}

int Sim::menuOptions(){
    cout << "Please select a menu option: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the student id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Add a new student" << endl;
    cout << "6. Delete a student given the id" << endl;
    cout << "7. Add a new faculty member" << endl;
    cout << "8. Delete a faculty member given the id." << endl;
    cout << "9. Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "10. Remove an advisee from a faculty member given the ids" << endl;
    cout << "11. exit" << endl;
    int x;
    cin >> x;

    return x;

}

bool Sim::check_has(int facid){
    if(factree.isEmpty()){
        return false;
    } else if(factree.IDexists(facid)){
        return true;
    } else {
        return false;
    }

}

bool Sim::check_has_for_list(int* facid, int size){
    for(int i = 0; i < size; i++){
        if(studtree.IDexists(facid[i])){
            return true;
        }
    }
    return false;
}


bool Sim::checkIDinlist(int studid){
    if(factree.isEmpty()){
        return false;
    } else if(factree.containsID_infaculty(studid)){
        return true;
    } else {
        return false;
    }

}