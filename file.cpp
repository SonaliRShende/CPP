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
   
    void deleteRecord(int studentNo)    
    {
        f.open("STUD", ios::in | ios::binary);
        fstream tempFile;
        tempFile.open("TEMP_STUD", ios::out | ios::binary);
    
        if (!f.is_open() || !tempFile.is_open()) {
            cout << "File(s) cannot be opened";
            exit(0);
        }
    
        bool found = false;
    
        while (f.read((char*)&stud1, sizeof(stud1))) {
            if (stud1.no == studentNo) {
                found = true;
                continue; // Skip writing this record to the temporary file
            }
            tempFile.write((char*)&stud1, sizeof(stud1)); // Write other records to temp file
        }
    
        f.close();
        tempFile.close();
    
        if (found) {
            remove("STUD");          // Delete the original file
            rename("TEMP_STUD", "STUD"); // Rename temp file to original file
            cout << "Record deleted successfully!" << endl;
        } else {
            remove("TEMP_STUD"); // Delete temp file if record not found
            cout << "Record not found!" << endl;
        }
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

