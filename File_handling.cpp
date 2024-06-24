#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudentRecord(ofstream& file, const Student& student) {
    file << student.rollNumber << ' ' << student.name << ' ' << student.division << ' ' << student.address << endl;
}

void displayStudentRecord(ifstream& file, int targetRollNumber) {
    Student student;
    bool found = false;

    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == targetRollNumber) {
            found = true;
            cout << "Student Record Found:" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student Record not found." << endl;
    }
}

void deleteStudentRecord(ifstream& inFile, int targetRollNumber) {
    Student student;
    ofstream tempFile("temp.txt");

    bool found = false;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == targetRollNumber) {
            found = true;
            cout << "Student Record Deleted:" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
        } else {
            tempFile << student.rollNumber << ' ' << student.name << ' ' << student.division << ' ' << student.address << endl;
        }
    }

    if (!found) {
        cout << "Student Record not found." << endl;
    }

    inFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");
}

int main() {
    ofstream outFile("students.txt", ios::app);
    ifstream inFile("students.txt");

    if (!outFile || !inFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int choice, rollNumber;
    Student newStudent;

    do {
        cout << "\n1. Add Student\n2. Display Student\n3. Delete Student\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> newStudent.rollNumber;
                cout << "Enter Name: ";
                cin >> newStudent.name;
                cout << "Enter Division: ";
                cin >> newStudent.division;
                cout << "Enter Address: ";
                cin.ignore(); 
                getline(cin, newStudent.address);
                addStudentRecord(outFile, newStudent);
                cout << "Student record added successfully." << endl;
                break;

            case 2:
                cout << "Enter Roll Number to display: ";
                cin >> rollNumber;
                displayStudentRecord(inFile, rollNumber);
                break;

            case 3:
                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;
                deleteStudentRecord(inFile, rollNumber);
                inFile.open("students.txt");  
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    outFile.close();
    inFile.close();

    return 0;
}











#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
class stud
{
    public:
    int no;
    char name[20];
};

class f_stud {
public:
    fstream f;
    stud stud1;
    int totalRecords;

   

    void deleteRecord(int studentNo) {
        f.open("STUD", ios::in | ios::out | ios::binary);

        if (!f.is_open()) {
            cout << "File can not be opened";
            exit(0);
        }

        f.seekg(0, ios::beg); // Move to the beginning of the file
        bool found = false;

        while (f.read((char*)&stud1, sizeof(stud1))) {
            if (stud1.no == studentNo) {
                found = true;
                break;
            }
        }

        if (found) {
            // Position to the beginning of the found record
            f.seekp(-sizeof(stud1), ios::cur);
            // Fill the record with empty values or any mark indicating deletion
            stud emptyStudent;
            emptyStudent.no = -1; // Mark as deleted or empty record
            strcpy(emptyStudent.name, "");
            f.write((char*)&emptyStudent, sizeof(emptyStudent));
            cout << "Record deleted successfully!" << endl;
        } else {
            cout << "Record not found!" << endl;
        }

        f.close();
    }


    void creat()
    {
        int i;
        int n;
        cout<<"enter no of students ";
        cin>>n;
     
        f.open("STUD", ios::out|ios::binary );
      
        if(!f.is_open())
        {
            cout <<"File can not be opened";
            exit(0);
        }
        cout <<endl<<"INPUT INFO - "<<endl;
        for(i=0;i<n;i++)
          {
              cin >> stud1.no;
              cin >> stud1.name;
             f.write((char*)&stud1,sizeof(stud1));
          }
          f.close();
    }
        
    void display()
    {
         f.open("STUD", ios::in |ios::binary); 
        
         cout << endl<<"OUTPUT - ";
         
         f.read((char*)&stud1,sizeof(stud1)); 
         while(f)   
         {
             cout <<endl<<stud1.no<<" "<<stud1.name;
            f.read((char*)&stud1,sizeof(stud1)); 
            
         }
            f.close();
    }
};

int main() {
    f_stud S;
    S.creat();
    S.display();
    
    int studentNoToDelete;
    cout << "Enter student number to delete: ";
    cin >> studentNoToDelete;

    S.deleteRecord(studentNoToDelete);
    S.display();

    return 0;
}

