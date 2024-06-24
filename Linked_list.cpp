#include <iostream>
using namespace std;
class Node 
 {
    public:
    int data ;
    Node*next;
 };
class sll
 {
    Node *head=NULL;
    public:
    
    void create()
     {
    
        int data;
        Node*temp=new Node;
        
        cout << "Enter the element\n";
        cin >> data;
        
        temp->data=data;
        temp->next=NULL;
        head=temp;
     }
    void display()
     {
        Node*dis=head;
        cout<<"List is : \n";
        while(dis!=NULL)
        {
            cout <<dis->data<<" ";
            dis=dis->next;
            
        }cout<<"\n";
    }
    void insert_head()
     {
        Node*ptr=new Node();
        int data;
        
        cout << "Enter data to insert at head\n";
        cin >> data;
        
        ptr->data=data;
        ptr->next=NULL;
    
        Node*temp=head;
        ptr->next=head;
        head=ptr;
     }
    void insert_after()
     {
        int key;
        Node*ptr=new Node();
        
        cout << "Enter element which you want to insert\n";
        cin >> ptr->data;
        ptr->next=NULL;
   
        cout << "Enter element after which you want to insert\n";
        cin >> key;
     
        Node*temp=head;
        int prev=1;
        
        while(prev<key-1)
        {
            temp=temp->next;
            prev++;
        }
        
        ptr->next=temp->next;
        temp->next=ptr;
     }
    
    void insert_end()
     {
        Node*ptr= new Node();
        Node*temp=head;
        
        cout<<"Enter element you want to insert\n";
        cin>>ptr->data;
     
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=ptr;
        ptr->next=NULL;
     }  
    
    void Delete()
     {
        Node*temp,*prev;
        int key;
        temp=head;
        
        cout<<"Enter element to delete\n";
        cin>>key;
    
        while(temp!=NULL)
         {
            if(temp->data==key)
            break;
            prev=temp;
            temp=temp->next;
        }
        
        if(temp==NULL)
         {
            cout <<"\tNode not found\n";
         }else
         {
            if(temp==head)
                head=temp->next;
            else
                prev->next=temp->next;
        delete temp;
        cout<<"Element is deleted\n";
        }
    }
 };

 int main()
  {
    sll s;
    int choice,ch1,key;
    char ans='y';
    char ans1='y';
    
    while(ans=='y'||ans=='Y')
     {
        cout<<"---------------------------------------------------\n";
        cout<<"\tLINKED LIST\n";
        cout<<"---------------------------------------------------\n\n";
        cout<<"\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.quit\n\n";
        cout<<"Enter choice\n";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                s.create();
                cout<<"---------------------------------------------------\n";
                s.display();
                break;
            
            case 2:
                s.display();
                cout<<"---------------------------------------------------\n";
                break;
            
            case 3:
                cout<<"---------------------------------------------------\n";
                s.display();
                while(ans1=='y'||ans1=='Y')
                 {
                cout<<"\n1.Insert at beginning  \n2.Insert after\n3.Insert at end\n";
                cout<<"Enter choice\n";
                cin>>ch1;
                switch(ch1)
                 {
                    case 1:
                        s.insert_head();
                        cout<<"---------------------------------------------------\n";
                        s.display();
                        break;
                
                    case 2:
                        s.insert_after();
                        cout<<"---------------------------------------------------\n";
                        s.display();
                        break;
                
                    case 3:
                        s.insert_end();
                        cout<<"---------------------------------------------------\n";
                        s.display();
                        break;
                    
                    default:
                        cout<<"invalid choice\n";
                 }
                cout<<"\nWant to continue inserting?\n";
                cin>>ans1;
                 }
            break;
            
            case 4:
                s.Delete();
                cout<<"---------------------------------------------------\n";
                s.display();
                break;
            
            default:
                cout<<"invalid choice\n";
        }
       cout<<"\nWant to continue ?\n";
       cin>>ans;
     }
  }

