#include<iostream>
#include <string>
using namespace std;
class Node
    {
        public:
        char data;
        Node *next;
    };
class stack
    {
        public:
        Node*top=NULL;
        
        void push(char value)
        {
 	        Node*newNode= new Node;
 	        newNode->data=value;
 	        newNode->next=top;
 	        top=newNode;
        }
        
        char pop()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty \n";
                return 1;
            }
            else 
            {
 	            Node*newNode;
 	            newNode=top;
 	            top=newNode->next;
 	            char temp =newNode->data;
 	            delete newNode;
 	            return temp;
            }
        }
 
        int isEmpty()
        {
 	        if(top==NULL)
 	        {
 		        return 1;
 	        }
 	        else
 	            return 0;
        }  
    };
class expression 
{
 public:
    string infix;
    string prefix="";
    string postfix="";
    stack st;
        
 public:
        
  bool is_operator(char c)
    {
        if(c=='/'||c=='*'||c=='+'||c=='-')
  	    {
  		    return true;
  	    }
  	    else
  	    {
  		    return false;
  	    }
    }
        
  int priority(char ch)
    {
        if(ch=='^')
  	    {
  		    return 3;
  	    }
  	    else if(ch=='/'||ch=='*')
  	    {
  		    return 2;
  	    } 
  	    else if(ch=='+'||ch=='-')
  	    {
  		    return 1;
        }
  	        return -1;
    }
  
  void infix_postfix(string infix)
    {
        for( int i=0 ; i < infix.length() ; i++)
  	    {
            if((infix[i] >= 'A' && infix[i] <= 'Z' )||( infix[i] >= 'a' && infix[i] <= 'z'))
  	        {
  		        postfix += infix[i];
  		    }
  		    else if(infix[i]=='(')
  	        {
  		        st.push(infix[i]);
  		    }
  	        else if(infix[i]==')')
  	        {
  	            while(!st.isEmpty()&& st.top->data!='(')
  		        {
  			       postfix+=st.pop();
  		        }
  		        if(st.top->data=='(')
  		        {
  		            st.pop();
  		        }
  		    }
  	        else if(is_operator(infix[i]))
  	        {
                if(st.isEmpty())
                {
                    st.push(infix[i]);
                }
                else
                {
                    if( priority(infix[i])>priority(st.top->data))
                    {
                        st.push(infix[i]);
                    }
                    else
                    {
                         while(priority(st.top->data)>priority(infix[i]))
                        {
                            postfix+=st.pop();
                        }
                        st.push(infix[i]);
                    }
                }
            }
  	    }
  	    while(!st.isEmpty())
  	    {
  	        postfix+=st.pop();
  	    }
        cout<<"\n";
        cout<<"Postfix Expression is : "<<postfix<<endl;
        cout<<"\n";
    }

  string reversest(string s)
    {
        int n = s.length();
        for (int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
        return s;
    }
    
  void infix_prefix(string infix)
    {
        string inf=reversest(infix);
        string temp_prefix="";
        for(int i=0;i<inf.length();i++)
        {
            if (inf[i]=='(')
            {
                inf[i]=')';
            }
            else if (inf[i]==')')
            {
                inf[i]='(';
            }
        }
        for(int i=0;i<inf.length();i++)
        {
            if((inf[i] >= 'A' && inf[i] <= 'Z' )||( inf[i] >= 'a' && inf[i] <= 'z'))
  	        {
              temp_prefix += inf[i];
  	        } 
  	        else if(inf[i]=='(')
  	        {
                st.push(inf[i]);
  		    }
  		    else if(inf[i]==')')
  		    {
  		        while(st.top->data!='('&& !st.isEmpty()  )
  		        {
  		            temp_prefix+=st.pop();
  		        }
  		        if(st.top->data=='(')
  		        {
  		            st.pop();
  		        }
  		    }
  		    else if(is_operator(inf[i]))
  		    {
  		        if(st.isEmpty())
  		        {
  		            st.push(inf[i]);
  		        }
  		        else
  		        {
  		            if(priority(inf[i])>priority(st.top->data))
  		            {
  		                st.push(inf[i]);
  		            }
  		            else if(priority(inf[i])==priority(st.top->data)&& inf[i]=='^')
  		            {
  		                while(priority(inf[i])==priority(st.top->data) && inf[i]!='^')
  		                {
  		                    temp_prefix+=st.pop();
  		                }
  		                st.push(inf[i]);
  		            }
  		            else if(priority(inf[i])==priority(st.top->data))
  		            {
  		                st.push(inf[i]);
  		            }
  		            else
  		            {
  		                while(!st.isEmpty()&& priority(st.top->data) > priority(inf[i]))
  		                {
  		                    temp_prefix+=st.pop();
  		                }
  		                st.push(inf[i]);
  		            }
  		        }
  		    }
        }
            while(!st.isEmpty())
            {
                temp_prefix+=st.pop();
            }
            prefix=reversest(temp_prefix);
            cout<<"\nPrefix Expression is : "<<prefix<<endl;
            cout<<"\n";
        }
    
        bool is_char(char ch)
        {
            if(ch >= 'a' && ch<= 'z'||ch >= 'A' && ch<= 'Z')
            {
                return true ;
            }
            else 
            {
                return false;
            }
        }
        
        bool is_num(char ch)
        {
            if (ch >= '0'&& ch<='9')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        bool is_operand(char ch)
        {
            return is_char(ch) || is_num(ch);
        }
    
        int postfix_evalution(string postfix)
        {
            for(int i=0;i<postfix.length();i++)
            {
                if(is_operand(postfix[i]))
                {   
                    int val;
                    cout<<"Enter value of : "<<postfix[i]<<" ";
                    cin>>val;
                    st.push(val);
                }
                else
                {
                    int a=st.pop();
                    int b=st.pop();
                    switch (postfix[i])
                    {
                        case '/':
                            st.push(b/a);
                            break;
                        
                        case '*':
                            st.push(b*a);
                            break;
                        
                        case '+':
                            st.push(b+a);
                            break;
                        
                        case '-':
                            st.push(b-a);
                            break;
                    }
                }
            }
            int ans =st.pop();
            cout<<"Solution of  "<<postfix<<" is "<<ans<<"\n";
            return ans;
        }
    
  int prefix_evalution(string prefix)
    {
        for(int i=prefix.length()-1;i>=0;i--)
        {
            if(is_operand(prefix[i]))
            {
                int val;
                cout<<"Enter value of : "<<prefix[i]<<" ";
                cin>>val;
                st.push(val);
            }
            else
            {
                int a=st.pop();
                int b=st.pop();
                switch (prefix[i])
                {
                    case '/':
                        st.push(a/b);
                        break;
                        
                    case '*':
                        st.push(a*b);
                        break;
                        
                    case '+':
                        st.push(a+b);
                        break;
                        
                    case '-':
                        st.push(a-b);
                        break;
                }
            }
        }
        int ans =st.pop();
        cout<<"Solution of  "<<prefix<<" is "<<ans<<"\n";
        return ans;
    }
    
};
  
int main()
 {
 	expression e1;
 	string infix;
 	int choice;
 	
 	cout<<"Enter expression :\n";
  	cin>>infix;
  	
  	while (choice!=5)
  	{
  	    cout<<"----------------------------------------------------------------------------\n";
  	    cout<<"\n\tSTACK\n";
  	    cout<<"1.Infix to Postfix conversion\n2.Postfix evalution\n3.Infix to Prefix conversion\n4.Prefix evalution\n5.exit\n";
  	    cout<<"\nENTER CHOICE :\n";
  	    cin>>choice;
  	    switch(choice)
  	    {
  	        case 1:
  	        e1.infix_postfix(infix);
  	        break;
  	        case 2:
  	        e1.postfix_evalution(e1.postfix);
  	        break;
  	        case 3:
  	        e1.infix_prefix(infix);
  	        break;
  	        
  	        case 4:
  	        e1.prefix_evalution(e1.prefix);
  	        break;
  	        
  	        case 5:
  	        cout<<"Exiting the program \n";
  	        break;
  	        default:
  	        cout<<"Invalid choice \n";
  	    }
  	}
 	return 0;
 }
 /* OUTPUT 
 
Enter expression :
(a+b)
----------------------------------------------------------------------------

	STACK
1.Infix to Postfix conversion
2.Postfix evalution
3.Infix to Prefix conversion
4.Prefix evalution
5.exit

ENTER CHOICE :
1

Postfix Expression is : ab+

----------------------------------------------------------------------------

	STACK
1.Infix to Postfix conversion
2.Postfix evalution
3.Infix to Prefix conversion
4.Prefix evalution
5.exit

ENTER CHOICE :
2
Enter value of : a 1
Enter value of : b 2
Solution of  ab+ is 3

----------------------------------------------------------------------------

	STACK
1.Infix to Postfix conversion
2.Postfix evalution
3.Infix to Prefix conversion
4.Prefix evalution
5.exit

ENTER CHOICE :
3

Prefix Expression is : +ab

----------------------------------------------------------------------------

	STACK
1.Infix to Postfix conversion
2.Postfix evalution
3.Infix to Prefix conversion
4.Prefix evalution
5.exit

ENTER CHOICE :
4
Enter value of : b 5
Enter value of : a 4
Solution of  +ab is 9
----------------------------------------------------------------------------

	STACK
1.Infix to Postfix conversion
2.Postfix evalution
3.Infix to Prefix conversion
4.Prefix evalution
5.exit

ENTER CHOICE :
5
Exiting the program */

 



















