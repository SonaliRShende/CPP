#include<iostream>
using namespace std;
class heapsort
{
   public:
   int heap_arr[50];
    
    void display(int arr[], int size)
    {
        for (int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void max_Heapify(int arr[], int size, int root)
    {
        int largest = root;
        int Left = 2 * root + 1;
        int Right = 2 * root + 2;
        
        if(Left <size&&arr[Left]>arr[largest])
        {
            largest=Left;
        }
        
        if (Right <size&&arr[Right]>arr[largest])
        {
            largest=Right;
        }
        
        if (largest!=root)
        {    
            swap (arr[root],arr[largest]);
            max_Heapify(arr,size,largest);
        }
    }
    void min_Heapify(int arr[], int size, int root)
    {
        int largest = root;
        int Left = 2 * root + 1;
        int Right = 2 * root + 2;
        
        if(Left <size&&arr[Left]<arr[largest])
        {
            largest=Left;
        }
        
        if (Right <size&&arr[Right]<arr[largest])
        {
            largest=Right;
        }
        
        if (largest!=root)
        {    
            swap (arr[root],arr[largest]);
            min_Heapify(arr,size,largest);
        }
        
    }
    
    void Heap_sort(int ch,int arr[], int size)
    {
        cout<<"\nARRAY (Befor sorting) :";
        display(arr,size);
    
        
            if(ch==1){
                    for(int i = size /2 - 1 ; i >= 0 ; i--)
                    {
                        max_Heapify(arr,size,i);
                    }
                    cout<<"\nARRAY (After building heap) :";
                    display(arr,size);
                    cout<<endl;
                    
                    for (int i = size - 1; i >0; i--) 
                    {
                        swap(arr[0], arr[i]);
                        max_Heapify(arr, i, 0);
                        cout << "ARRAY (After  pass " << size - i << ") : ";
                        display(arr, size);
                    }
            }
            if(ch==2){
                    for(int i = size /2 - 1 ; i >= 0 ; i--)
                    {
                        min_Heapify(arr,size,i);
                    }
                    cout<<"\nARRAY (After building heap) :";
                    display(arr,size);
                    cout<<endl;
                    
                    for (int i = size - 1; i >0; i--) 
                    {
                        swap(arr[0], arr[i]);
                        min_Heapify(arr, i, 0);
                        cout << "ARRAY (After  pass " << size - i << ") : ";
                        display(arr, size);
                    }
                    
            
        }
        
    }
};
int main()
{
    heapsort HS;
    int n,choice;
    cout<<"Enter size of tree :\n";
    cin>>n;
    cout<<"Enter elements in tree : ";
    
    for(int i=0;i<n;i++)
    {
        cin>>HS.heap_arr[i];
    }
    do{
        cout<<"\n\n----------HEAP SORT----------\n";
        cout<<"1. Max Heap\n";
        cout << "2. Min Heap\n";
        cout << "3. Exit\n";
        cout<<"Enter choice :";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                    HS.Heap_sort(1,HS.heap_arr, n);
                    cout << "\nARRAY(After sorting ) : ";
                    HS.display(HS.heap_arr, n);
                    break;
            case 2:
                    HS.Heap_sort(2,HS.heap_arr, n);
                    cout << "\nARRAY(After sorting ) : ";
                    HS.display(HS.heap_arr, n);
                    break;
            case 3:
                    cout<<"------------------------\n";
                    break;
            default:
                    cout<<"Invalid choice \n";
                    break;
            
        }
    }while(choice <3);
}
/*
    OUTPUT
Enter size of tree :
10
Enter elements in tree : 10
1
4
7
8
9
6
3
2
5


----------HEAP SORT----------
1. Max Heap
2. Min Heap
3. Exit
Enter choice :1

ARRAY (Befor sorting) :10 1 4 7 8 9 6 3 2 5 

ARRAY (After building heap) :10 8 9 7 5 4 6 3 2 1 

ARRAY (After  pass 1) : 9 8 6 7 5 4 1 3 2 10 
ARRAY (After  pass 2) : 8 7 6 3 5 4 1 2 9 10 
ARRAY (After  pass 3) : 7 5 6 3 2 4 1 8 9 10 
ARRAY (After  pass 4) : 6 5 4 3 2 1 7 8 9 10 
ARRAY (After  pass 5) : 5 3 4 1 2 6 7 8 9 10 
ARRAY (After  pass 6) : 4 3 2 1 5 6 7 8 9 10 
ARRAY (After  pass 7) : 3 1 2 4 5 6 7 8 9 10 
ARRAY (After  pass 8) : 2 1 3 4 5 6 7 8 9 10 
ARRAY (After  pass 9) : 1 2 3 4 5 6 7 8 9 10 

ARRAY(After sorting ) : 1 2 3 4 5 6 7 8 9 10 


----------HEAP SORT----------
1. Max Heap
2. Min Heap
3. Exit
Enter choice :2

ARRAY (Befor sorting) :1 2 3 4 5 6 7 8 9 10 

ARRAY (After building heap) :1 2 3 4 5 6 7 8 9 10 

ARRAY (After  pass 1) : 2 4 3 8 5 6 7 10 9 1 
ARRAY (After  pass 2) : 3 4 6 8 5 9 7 10 2 1 
ARRAY (After  pass 3) : 4 5 6 8 10 9 7 3 2 1 
ARRAY (After  pass 4) : 5 7 6 8 10 9 4 3 2 1 
ARRAY (After  pass 5) : 6 7 9 8 10 5 4 3 2 1 
ARRAY (After  pass 6) : 7 8 9 10 6 5 4 3 2 1 
ARRAY (After  pass 7) : 8 10 9 7 6 5 4 3 2 1 
ARRAY (After  pass 8) : 9 10 8 7 6 5 4 3 2 1 
ARRAY (After  pass 9) : 10 9 8 7 6 5 4 3 2 1 

ARRAY(After sorting ) : 10 9 8 7 6 5 4 3 2 1 


----------HEAP SORT----------
1. Max Heap
2. Min Heap
3. Exit
Enter choice :3
------------------------

*/

