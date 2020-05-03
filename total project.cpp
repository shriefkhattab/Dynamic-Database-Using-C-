#include <fstream> //for file I/O
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class student {
private:
    string name, dep, year, code;
public:
    void setName(string name1) {
        name = name1;
        }
    void setDep(string dep1) {
        dep = dep1;
        }
    void setYear(string year1) {
        year = year1;
        }
    void setcode(string code1) {
    code = code1;
        }

    string getName() {return name;}
    string getDep()  {return dep;}
    string getYear() {return year;}
    string getcode() {return code;}


};


class stuff {
private:
string name, title, dep;

public:
     void setTitle(string title1) {
        title = title1;
        }
    void setName(string name1) {
        name = name1;
        }
    void setDep(string dep1) {
        dep = dep1;
        }

    string getTitle()  {return title;}
    string getName() {return name;}
    string getDep() {return dep;}

};
stuff getStuffDetails() {
        bool answer;
        string titleArray[] = {"Demonstrator", "Teaching Assistant", "Teacher", "Assistant professor", "Professor"};
        string depArray[] = {"Structure", "Irrigation and hydraulics", "Public works", "Architecture", "Urban Design and Planning", "Power and Electrical Machines", "Electronics and Electrical Communication", "Computer and Systems", "Mechatronics", "Mechanical Power", "Automotive", "Design and Production"};
        string info;
        int index;
        stuff newStuff;

      cout << " Please enter your name "<<endl;
        cin.ignore();
        getline(cin,info);
        newStuff.setName(info);
        answer = false;
        while (!answer){

        cout << " Please select your title number from the list bellow "<<endl;
        for ( int i=0; i<5; i++)
            cout<< i << "- " << titleArray[i] << endl<<endl;
        cout<< " Your Title Number is (0/1/2/3/4) ?"<<endl;
        cin >> index;
        if (index == 0 || index == 1 || index == 2 || index == 3 || index == 4)
            answer = true ;
        else cout << "Wrong Answer !!" << endl;

        }
        cout<<"you are " << titleArray[index] <<endl<<endl;
        newStuff.setTitle(titleArray[index]);

        answer = false;

        while (!answer){

        cout << " Please select your department number from the list bellow "<<endl<<endl;
        for ( int i=0; i<12; i++)
            cout<< i << "- " << depArray[i] << endl<<endl;
        cout<< " Your department Number is (0/1/2/.../11) ?"<<endl;
        cin >> index;
        if (index == 0 || index == 1 || index == 2 || index == 3 || index == 4 || index == 5 || index == 6 || index == 7 || index == 8 || index == 9 || index == 10 || index == 11 || index == 12)
            answer = true ;
        else cout << "Wrong Answer !!" << endl;

        }
        cout<<"your department is " <<depArray[index] <<endl<<endl;
        newStuff.setDep(depArray[index]);

        return newStuff;
}
student getStudentDetails() {
    bool answer;
    string depArray[] = {"Structure", "Irrigation and hydraulics", "Public works", "Architecture", "Urban Design and Planning", "Power and Electrical Machines", "Electronics and Electrical Communication", "Computer and Systems", "Mechatronics", "Mechanical Power", "Automotive", "Design and Production"};
    string yearArray[] = {"Freshmen","Sophomore","Junior","Senior I","Senior II"};
    string info;
    int index;
    student newStudent;
     cout << " Please enter your name "<<endl;
      cin.ignore();
        getline(cin,info);
        newStudent.setName(info);
        answer = false;
         while (!answer){

        cout << " Please select your Year number from the list bellow "<<endl;
        for ( int i=0; i<5; i++)
            cout<< i << "- " << yearArray[i] << endl<<endl;
        cout<< " Your Year Number is (0/1/2/3/4) ?"<<endl;
        cin >> index;
        if (index == 0 || index == 1 || index == 2 || index == 3 || index == 4)
            answer = true ;
        else cout << "Wrong Answer !!" << endl;

        }
        cout<<"you are " << yearArray[index] <<endl<<endl;
        newStudent.setYear(yearArray[index]);
        answer = false;

        while (!answer){

        cout << " Please select your department number from the list bellow "<<endl<<endl;
        for ( int i=0; i<12; i++)
            cout<< i << "- " << depArray[i] << endl<<endl;
        cout<< " Your department Number is (0/1/2/.../11) ?"<<endl;
        cin >> index;
        if (index == 0 || index == 1 || index == 2 || index == 3 || index == 4 || index == 5 || index == 6 || index == 7 || index == 8 || index == 9 || index == 10 || index == 11 || index == 12)
            answer = true ;
        else cout << "Wrong Answer !!" << endl;

        }
         cout<<"your department is " <<depArray[index] <<endl<<endl;
        newStudent.setDep(depArray[index]);

        return newStudent;

}
string getCounter(){
           string counter;
           ifstream studentCounterRead ("counter.txt");
           if(!studentCounterRead.is_open()){
                    cout << "Cannot open the File"<< endl ;
            }
            else {
                    studentCounterRead>>counter;
                    studentCounterRead.close();

                    ofstream studentCounterWrite ("counter.txt");
                    if(counter == ""){
                        counter = "0";
                        studentCounterWrite << "1";

                    }
                    else{
                        int counterInt = atoi(counter.c_str());
                        counterInt ++;
                        studentCounterWrite<< counterInt;

                    }
                    studentCounterWrite.close();

            }
            return counter;

}
int main()
{

    bool answer = false;
    string member;
    while (!answer){
        cout << " Welcome, are you student or stuff (student/stuff)?"<<endl;
        cin >> member;
        if(member == "student" || member == "stuff") {
            answer = true;
        } else {
            answer = false;
            cout << "Wrong Answer !!";
        }
    }
    if (member == "student")

    {
        char exist;
        do {

            string choice;
            cout << " How do you want to access the database"<< endl
            << "(load/add/modify/remove/search)"<<endl;
            cin >> choice;
            if (choice == "add") {
                student newStudent;
                newStudent = getStudentDetails();
                string studentIndex = getCounter();
                string code = (newStudent.getName()).substr(0,2) + "_" + studentIndex;
                newStudent.setcode(code);
                cout<<newStudent.getcode()<<"\t"<<newStudent.getName()<<"\t"<<newStudent.getYear()
                <<"\t in \t"<<newStudent.getDep()<<endl;

                string ans;
                cout<<"Do you want to save the new student to the database?(y/n)"<<endl;
                cin>> ans;
                    if(ans == "y"){
                        ofstream studentDatabase("student-db.csv",std::ios_base::app | std::ios_base::out);
                    if(!studentDatabase.is_open()){
                        cout << "Cannot open the File"<< endl ;
                    }

                    else {
                        studentDatabase<<newStudent.getcode()<<","<<newStudent.getName()<<","<<newStudent.getDep()
                        <<","<<newStudent.getYear()<< endl;
                        cout << "Your Info has been added to the Faculty Database =)" << endl ;
                    }
            }
                    else {
                        cout<<"the new student created not saved in database!";
                    }
        }

            else if(choice == "load") {
            string line;
            ifstream studentDatabase("student-db.csv");
            if(!studentDatabase.is_open()){
                cout << "Cannot open the File"<< endl ;
            }
            else {
                   // cout<< "name" << "\t" << "\t" << "title" << "\t" << "\t"<< "department"<<endl;
                    while ( !studentDatabase.eof()){
                        getline(studentDatabase,line);
                        istringstream ss(line);
                        string fields;
                        while(getline(ss, fields, ',')) {
                            cout << fields << "\t" << "\t";
                        }
                        cout<<endl;
                    }
            }
             studentDatabase.close();
    }

        else if (choice == "search") {
        string line;
        string name;
        int counter = 0;
        cout << "Enter the name/code you want to search:" << endl;
        cin.ignore();
        getline(cin,name);
       // cout <<name;
        ifstream studentDatabase("student-db.csv");
        if(!studentDatabase.is_open()){
                cout << "Cannot open the File"<< endl ;
            }
        else {
                    //cout<< "name" << "title" << "department";
                while ( !studentDatabase.eof()){
                    getline(studentDatabase,line);
                    if(line.find(name) != std::string::npos){
                            counter ++;
                            cout<< counter <<"- "<< line <<endl;
                    }
                }
                if(counter == 0) {
                    cout<<" name/code you entered not exists in database :("<<endl;
                } else {
                    cout<<endl<< counter <<" records founded"<<endl;
                }
        }
        studentDatabase.close();


        }
        else if(choice == "modify"||choice == "remove") {

        if (choice =="modify")
            cout << "please enter the student name you want to modify" << endl;
        else
            cout << "Please enter the student name you want to remove" << endl;
        string name;
        int counter = 0;

        cin.ignore();
        getline(cin,name);


        ifstream studentDatabase("student-db.csv");
        if(!studentDatabase.is_open()){
                cout << "Cannot open the File"<< endl ;
            }
        else {
                   //cout<< "name" << "title" << "department";
                    string result [100];
                    student modifiedStudent;
                    int studentIndex;
                    string line;
                while ( !studentDatabase.eof()){
                    getline(studentDatabase,line);
                    if(line.find(name) != std::string::npos){
                            result[counter]= line;
                            counter ++;
                            cout<< counter <<"- "<< line <<endl;
                    }
                }
                studentDatabase.close();
                if(counter == 0) {
                    cout<<" name you entered not exists in database :("<<endl;
                } else {
                    cout<<endl<< counter <<" records founded"<<endl;
                    if (counter == 1 ){
                            if ( choice == "modify")
                                {cout << "enter the modified student: "<<endl;
                                modifiedStudent = getStudentDetails();
                                string stIndex = getCounter();
                                string code = (modifiedStudent.getName()).substr(0,2) + "_" + stIndex;
                                modifiedStudent.setcode(code);
                                }
                                studentIndex = 1;

                    }else {
                        if(choice == "modify") {
                            do{
                            cout<<"choose which student to modify?(1/../"<<counter<<")"<<endl;
                            cin>> studentIndex;
                            }while (studentIndex>counter||studentIndex<1);
                            cout << "enter the modified student: "<<endl;
                            modifiedStudent = getStudentDetails();
                            string stIndex = getCounter();
                            string code = (modifiedStudent.getName()).substr(0,2) + "_" + stIndex;
                            modifiedStudent.setcode(code);
                        }
                        else {
                              do{
                            cout<<"choose which student to remove?(1/../"<<counter<<")"<<endl;
                            cin>> studentIndex;
                            }while (studentIndex>counter);

                        }

                    }
                     cout << "do you want to save changes in database? (y/n)?";
                string save;
                cin>> save;
                if(save == "y") {
                    ifstream studentDatabaseMod("student-db.csv");

                    ofstream temp("temp.csv",std::ios_base::app | std::ios_base::out);
                    if(!temp.is_open()){
                        cout << "Cannot open temp File"<< endl ;
                    }
                    else {

                          while (!studentDatabaseMod.eof()){
                            getline(studentDatabaseMod,line);
                            if(result[studentIndex-1] == line) {
                                if(choice == "modify")
                                {
                                    temp<< modifiedStudent.getcode() <<","
                                    << modifiedStudent.getName()
                                    <<","<<modifiedStudent.getDep()
                                    <<","<<modifiedStudent.getYear()
                                    <<endl;
                                }
                                ////////////////////////////////////////////
                            }
                            else{
                                temp<<line<<endl;

                            }
                        }

                     studentDatabaseMod.close();
                     temp.close();
                     string student_db=("student-db.csv");
                     const char * p = student_db.c_str();
                     remove(p);
                     rename("temp.csv",p);
                    }
                } else {
                    cout<<"your changes is not saved in database!!";
                }

                }


                }
            }
        cout<< "Make another operation (y/n)?";
        cin >> exist;
        }while(exist == 'y');

    }
    else if (member == "stuff")
    {
        //string titleArray[] = {"Demonstrator", "Teaching Assistant", "Teacher", "Assistant professor", "Professor"};
       // string info;
       // int index;
       char exist;
        do{
        stuff newStuff;
        string choice;
        cout << " How do you want to access the database"<< endl
        << "(load/add/modify/remove/search)"<<endl;
        cin >> choice;

        if (choice == "add") {
                newStuff = getStuffDetails();
        cout<<newStuff.getTitle()<<"\t"<<newStuff.getName()<<"\t in \t"<<newStuff.getDep()<<endl;

        string ans;
        cout<<"Do you want to save the new stuff to the database?(y/n)"<<endl;
        cin>> ans;
        if(ans == "y"){
            ofstream stuffDatabase("stuff-db.csv",std::ios_base::app | std::ios_base::out);
            if(!stuffDatabase.is_open()){
                    cout << "Cannot open the File"<< endl ;
            }

            else {
                    stuffDatabase<<newStuff.getName()<<","<<newStuff.getTitle()<<","<<newStuff.getDep()<< endl;
                    cout << "Your Info has been added to the Faculty Database =)" << endl ;
            }
        }
        else {
            cout<<"the new stuff created not saved in database!";
        }

    } else if(choice == "load") {

            string line;
            ifstream stuffDatabase("stuff-db.csv");
            if(!stuffDatabase.is_open()){
                cout << "Cannot open the File"<< endl ;
            }
            else {
                   // cout<< "name" << "\t" << "\t" << "title" << "\t" << "\t"<< "department"<<endl;
                    while ( !stuffDatabase.eof()){
                        getline(stuffDatabase,line);
                        istringstream ss(line);
                        string fields;
                        while(getline(ss, fields, ',')) {
                            cout << fields << "\t" << "\t";
                        }
                        cout<<endl;
                    }
            }
             stuffDatabase.close();
    } else if (choice == "search") {
        string line;
        string name;
        int counter = 0;
        cout << "Enter the name you want to search:" << endl;
        cin.ignore();
        getline(cin,name);
       // cout <<name;
        ifstream stuffDatabase("stuff-db.csv");
        if(!stuffDatabase.is_open()){
                cout << "Cannot open the File"<< endl ;
            }
        else {
                    //cout<< "name" << "title" << "department";
                while ( !stuffDatabase.eof()){
                    getline(stuffDatabase,line);
                    istringstream ss(line);
                    string fieldName;
                    getline(ss,fieldName,',');
                    if(fieldName.find(name) != std::string::npos){
                            counter ++;
                            cout<< counter <<"- "<< line <<endl;
                    }
                }
                if(counter == 0) {
                    cout<<" name you entered not exists in database :("<<endl;
                } else {
                    cout<<endl<< counter <<" records founded"<<endl;
                }
        }
        stuffDatabase.close();
    }
    else if(choice == "modify"||choice == "remove") {

        if (choice =="modify")
            cout << "please enter the stuff name you want to modify" << endl;
        else
            cout << "Please enter the stuff name you want to remove" << endl;
        string name;
        int counter = 0;

        cin.ignore();
        getline(cin,name);

        ifstream stuffDatabase("stuff-db.csv");
        if(!stuffDatabase.is_open()){
                cout << "Cannot open the File"<< endl ;
            }
        else {
                   //cout<< "name" << "title" << "department";
                    string result [100];
                    stuff modifiedStuff;
                    int staffIndex;
                    string line;
                while ( !stuffDatabase.eof()){
                    getline(stuffDatabase,line);
                    istringstream ss(line);
                    string fieldName;
                    getline(ss,fieldName,',');
                    if(fieldName.find(name) != std::string::npos){
                            result[counter]= line;
                            counter ++;
                            cout<< counter <<"- "<< line <<endl;
                    }
                }
                stuffDatabase.close();
                if(counter == 0) {
                    cout<<" name you entered not exists in database :("<<endl;
                } else {
                    cout<<endl<< counter <<" records founded"<<endl;
                    if (counter == 1 ){
                            if ( choice == "modify")
                                {cout << "enter the modified stuff: "<<endl;
                                modifiedStuff = getStuffDetails();
                                }
                                staffIndex = 1;

                    }else {
                        if(choice == "modify") {
                            do{
                            cout<<"choose which staff to modify?(1/../"<<counter<<")"<<endl;
                            cin>> staffIndex;
                            }while (staffIndex>counter);
                            cout << "enter the modified stuff: "<<endl;
                            modifiedStuff = getStuffDetails();
                        }
                        else {
                              do{
                            cout<<"choose which staff to remove?(1/../"<<counter<<")"<<endl;
                            cin>> staffIndex;
                            }while (staffIndex>counter);
                        }

                    }
                     cout << "do you want to save changes in database? (y/n)?";
                string save;
                cin>> save;
                if(save == "y") {
                    ifstream stuffDatabaseMod ("stuff-db.csv");

                    ofstream temp("temp.csv",std::ios_base::app | std::ios_base::out);
                    if(!temp.is_open()){
                        cout << "Cannot open temp File"<< endl ;
                    }
                    else {

                          while (!stuffDatabaseMod.eof()){
                            getline(stuffDatabaseMod,line);
                            if(result[staffIndex-1] == line) {
                                if(choice == "modify")
                                {
                                    temp<< modifiedStuff.getName() <<","<<modifiedStuff.getTitle()<<","<<modifiedStuff.getDep()<<endl;
                                }

                            }
                            else{
                                temp<<line<<endl;

                            }
                        }

                     stuffDatabaseMod.close();
                     temp.close();
                     string stuff_db=("stuff-db.csv");
                     const char * p = stuff_db.c_str();
                     remove(p);
                     rename("temp.csv",p);
                    }
                } else {
                    cout<<"your changes is not saved in database!!";
                }

                }


                }
            }
            cout<< "make another operation (y/n)?";
            cin>> exist;

        }while (exist == 'y');
    }
    return 0;
}
