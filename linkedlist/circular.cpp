#include <iostream>
#include <cstdlib>
using namespace std;


struct Node{ 
    int data;
    Node*next;
};
Node*head=NULL;

void insert(int value){
    
    Node*temp=(Node*)malloc(sizeof (Node));
    temp ->data=value;

    if(head==NULL){
        cout<<"inert";
        head = temp;
        temp->next = head;
    } else {
        Node*cur=head;
        while (cur->next!=head)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp ->next=head;
        
    }
}    

void search(int value) { 
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    Node*cur=head;
    int pos=1;
    bool found=false;
    if(cur->data==value){
        cout<<"value found at: "<<pos<<endl;
        found=true;
        }
        cur=cur->next;
        pos++;
    while(cur!=head){
        if(cur->data==value){
        cout<<"value found at: "<<pos<<endl;
        found=true;
        }
        cur=cur->next;
        pos++;
    }
    if(!found){
        cout<<value<<"aint here so give me 500rs \n";
    }
    else{ 
        cout<<"search complete\n";
    }   
}

void dele(int value){
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    Node*cur=head;
    bool found=false;
    while(value==head->data){ 
        if (head->next==head){
            found=true;
            delete cur;
            head=NULL;
            cout<<value<<" value successfully deleted at pos: 1\n";
            return;
        }
        else{ 
            while(cur->next!=head){
                cur=cur->next;
            }
            found=true;
            Node*prev=head;
            head=head->next;
            cur->next=head;
            free(prev);
            cout<<value<<" value successfully deleted at pos: 1\n";
        }
    }
    Node*prev=head;
    cur=head->next;
    while(cur!=head){
        if(value==cur->data){
            found=true;
            prev->next=cur->next;
            free(cur);
            cout<<value<<" value successfully deleted "<<endl;
            cur=prev->next;
        }
        else{     
            prev=cur;
            cur=cur->next;

        }
    }

    if(!found){
        cout<<value<<" kia delete karu jab kuch hai hi nahi........\n";
    }
}


void display(){
    Node*cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    cout<< cur->data<<" -> ";
    cur=cur->next;
    while(cur!=head){
        cout<< cur->data<<" -> ";
        cur=cur->next;
    }  
}       



int main(){
    int choice,value;
    while(true){
        cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit";
        cin>>choice;

       switch (choice){ 
        case 1:
        cout<<"Enter a value\n";
        cin>>choice;
        insert(choice);
        break;

        case 2:
        cout<<"Enter a value\n";
        cin>>choice;
        search(choice);
        break;

        case 3:
        cout<<"Enter a value to delete\n";
        cin>>choice;
        dele(choice);
        break;


        case 4:
        display();
        break;

        case 5:
        cout<<"bbyeee\n";
        return 0;

        default:
        cout<<"Sahi choose kroo\n";
        break;
       
       }
    }

}


