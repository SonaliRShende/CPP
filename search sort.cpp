#include <iostream>
#include <cstring>
using namespace std;
struct student 
{
  string name;
  int roll_no;
  float sgpa;
};

class sinfo 
{
  public:
    int n;
    float target;
    struct student s[30];
    void getdata();
    void bubsort();
    void insertionsort();
    void bsearch();
    int partition(student s[], int low, int high);
    void quickSort(student s[], int low, int high);
    void linearSearch();
    void display();
};

void sinfo::getdata() 
{
    int i;
    cout << "Enter no of students:\n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter student name:\n";
        cin >> s[i].name;
        cout << "Enter student sgpa:\n";
        cin >> s[i].sgpa;
        cout << "Enter student roll no:\n";
        cin >> s[i].roll_no;
    }
}
 //sorting roll no. in ascending order using bubble sort
void sinfo::bubsort() 
{
    int i, j;
    struct student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
           if(s[j].roll_no > s[j + 1].roll_no)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
//insertion sort for sorting names
void sinfo::insertionsort()
{
    int i, j;
    struct student key;
    for (i = 0; i < n; i++)
    {
      key = s[i];
      j = i - 1;
      while (s[j].name > key.name && j >= 0) 
        {
            s[j + 1] = s[j];
            j--;
        }
      s[j + 1] = key;
    }
}

void sinfo::bsearch()
{
    string name1;
    int low = 0;
    int high = n - 1;
    cout << "Enter name of student\n";
    cin >> name1;
    while (low <= high) 
    {
      int mid = (low + high) / 2;
      if (s[mid].name == name1)
        {
         cout << "Name :" << s[mid].name << "\n";
        cout << "Roll no :" << s[mid].roll_no << "\n";
        cout << "Sgpa :" << s[mid].sgpa << "\n";
        break;
        } else if (s[mid].name > name1)
         {
           high = mid - 1;
         } else
         {
           low = mid + 1;
         }
    }
}
//sorting SGPA using quick sorting
//this function is to partitiona list and decide pivote element
int sinfo::partition(student s[], int low, int high)
{
    float pivot = s[high].sgpa;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
      if (s[j].sgpa >= pivot)
      {
        i++;
        swap(s[i], s[j]);
      }
    }
    swap(s[i + 1], s[high]);
    return (i + 1);
}
//this function is to sort the element in sublist
void sinfo ::quickSort(student s[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

void sinfo:: linearSearch()
{
    cout << "Enter The SGPA to be found \n";
        cin >> target;
        for (int i = 1; i < n; i++) {
            if (target == s[i].sgpa) {
                cout << "SGPA found is " << s[i].sgpa << endl;
                cout << "The rollno is: " << s[i].roll_no << endl;
                cout << "The name is: " << s[i].name << endl;
    }

    if (target != s[i].sgpa) {
      cout << "SGPA doesn't exist \n";
    }
  }
  cout << endl;
}

void sinfo::display() 
{
    int i;
    cout << "Student Information:\n";
    cout << "\nName\tRoll no\tSgpa\n";
    for (i = 0; i < n; i++) 
    {
        cout << "\n"
         << s[i].name << "\t" << s[i].roll_no << "\t" << s[i].sgpa << "\n";
    }
}

int main() 
{
    sinfo std;
    std.getdata();
    char stopApp;
    stopApp = 'Y';
    while(stopApp == 'Y')
    {
        int choice;
        cout << "Enter choice:\t"<< "0.Exit \t"<< "1.Bubble sort \t"<< "2.insertionsort\t"<<" 3.binary search\t"<<" 4.quick search\t"<<"5.Linear search\n";
        cin >>choice;
        switch (choice)
        {
            case 0:
            break;
    
            case 1:
            std.bubsort();
            std.display();
            break;

            case 2:
            std.insertionsort();
            std.display();
            break;

            case 3:
            std.bsearch();
            break;

            case 4:
            std.quickSort(std.s, 0, std.n-1);
            std.display();
            break;
            
            case 5:
            std.linearSearch();
            break;

            default:
            cout << "Wrong choice";
        }
        cout<<"\n\nDo you want to continue (Y/N) ? : ";
        cin>>stopApp;
        if (stopApp == 'N' | 'n')
        {
            cout<<" -------------------------------\n";
        }
    }
    return 0;
}

 /*                 OUTPUT

Enter no of students:
3
Enter student name:
SONALI
Enter student sgpa:
7
Enter student roll no:
3
Enter student name:
ASMITA
Enter student sgpa:
9
Enter student roll no:
2
Enter student name:
POOJA
Enter student sgpa:
8
Enter student roll no:
1
Enter choice:	0.Exit 	1.Bubble sort 	2.insertionsort	 3.binary search	 4.quick search	5.Linear search
1

Student Information:

Name	Roll no	Sgpa

POOJA	1	8

ASMITA	2	9

SONALI	3	7

Do you want to continue (Y/N) ? : Y
 -------------------------------
Enter choice:	0.Exit 	1.Bubble sort 	2.insertionsort	 3.binary search	 4.quick search	5.Linear search
2
Student Information:

Name	Roll no	Sgpa

ASMITA	2	9

POOJA	1	8

SONALI	3	7

Do you want to continue (Y/N) ? : Y
 -------------------------------
Enter choice:	0.Exit 	1.Bubble sort 	2.insertionsort	 3.binary search	 4.quick search	5.Linear search
3
Enter name of student
SONALI
Name :SONALI
Roll no :3
Sgpa :7

Do you want to continue (Y/N) ? : Y
 -------------------------------
Enter choice:	0.Exit 	1.Bubble sort 	2.insertionsort	 3.binary search	 4.quick search	5.Linear search
4
Student Information:

Name	Roll no	Sgpa

ASMITA	2	9

POOJA	1	8

SONALI	3	7

Do you want to continue (Y/N) ? : Y
 -------------------------------
Enter choice:	0.Exit 	1.Bubble sort 	2.insertionsort	 3.binary search	 4.quick search	5.Linear search
5
Enter The SGPA to be found 
8
SGPA found is 8
The rollno is: 1
The name is: POOJA

Do you want to continue (Y/N) ? : N
 -------------------------------
*/