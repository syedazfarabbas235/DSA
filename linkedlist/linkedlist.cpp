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
    temp ->next=NULL;

    if(head==NULL){
        head=temp;
    } else {
        Node*cur=head;
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
        
    }
}


void bubblesort(){
    if (head==NULL){
        return;
    }
    bool swapped=true;
    Node*last=NULL;
    while(swapped){
        swapped=false;
        Node*cur=head;
        while(cur->next!=last){
            if(cur->data>cur->next->data){
                swap(cur->data,cur->next->data);
                swapped=true;
            }
            cur=cur->next;
        }
        last=cur;


    }
    cout<<"bubble sort done.\n";
}

void selectionsort(){
    if (head==NULL){
        return;
    }
    Node*cur=head;
    while(cur->next!=NULL){
        Node*min=cur;
        Node*temp=cur->next;
        while(temp!=NULL){
            if(temp->data<min->data){
                min=temp;
            }
            temp=temp->next;
        }
        swap(cur->data,min->data);
        cur=cur->next;
    }
}

void insertion_sort(){
    if (head==NULL){
        return;
    }
    Node*cur=head->next;
    while(cur!=NULL){
        int temp =cur->data;
        Node*prev=head;
        while(prev!=cur && prev->data<=temp){
            prev=prev->next;
        }
        Node*walker=cur;
        while(walker!=prev){
            Node*before=head;
            while(before->next!=walker){
                before=before->next;
            }
            walker->data=before->data;
            walker=before;
        }
        prev->data=temp;
        cur=cur->next;
    }

    cur=head->next;
    while(cur!=NULL){
        int temp=cur->data;
        Node*prev=head;
        while(prev>=head && prev->data>temp){
            prev->next->data=prev->data;

        }
        prev->next->data=temp;
        cur=cur->next;
    }
}

void unique_insertion(int value){
    Node*temp=(Node*)malloc(sizeof (Node));
    temp ->data=value;
    temp ->next =NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        Node*cur=head;
        
        while(cur->next!=NULL){
            if(cur->data==value){
            cout<<"Numbers cant be repeated errorrrrrr\n";
            return;
            }
            cur=cur->next;
            
        }
        if(cur->data==value){
            cout<<"Numbers cant be repeated errorrrrrr\n";
            return;
        }
        cur->next=temp;
    }
}



void sorted_insertion(int value){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL || head->data>value){
        temp->next=head;
        head=temp;
    }
    else{  
        Node*cur=head;
        while(cur->next!=NULL && cur->next->data<value){
            cur=cur->next;
        }
        temp->next=cur->next;
        cur->next=temp;
    }
    

}    

void search(int value) { 
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    Node*cur=head;
    bool found=false;
    while(cur!=NULL){
        if(cur->data==value){
        cout<<"value found at: "<<endl;
        found=true;
        }
        cur=cur->next;
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
    while (head!=NULL && value==head->data){
        found=true;
        head=head->next;
        free(cur);
        cur=head;
        cout<<value<<" value successfully deleted at pos: 1\n";
    }
    Node*prev=head;
    if(head!=NULL)
    cur=head->next;
    while(cur!=NULL){
    
        if(value ==cur->data){
            found=true;
            prev->next=cur->next;
            delete cur;
            cur=prev->next;
            cout<<value<<" value successfully deleted"<<endl;
        }
        else{  
            prev=cur;
            cur=cur->next;
        }
    }
    if(!found){
        cout<<value<<"kia delete karu jab kuch hai hi nahi........\n";
    }
}
void display(){
    Node*cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    while(cur!=NULL){
        cout<< cur->data<<" -> ";
        cur=cur->next;
    } 
    cout<<"NULL\n";  
}  


void insertion_at_index(int pos, int val){
    Node*temp=new Node;
    temp->data=val;
    temp->next=nullptr;
    int count=2;
    Node*cur=head;

    if(pos==1){
        temp->next=head;
        head=temp;
    }
    else{
        while(count<pos){
            cur=cur->next;
            count++;
        }
        temp->next=cur->next;
        cur->next=temp;
    }
    cout<<"Value inserted at pos: "<<pos<<endl;
}

void reverse(){
    Node*prev=NULL;
    Node*cur=head;
    Node*temp=NULL;
    while(cur!=NULL){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    head=prev;
}

void recursive_display(Node*cur=head){
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    recursive_display(cur->next);
    cout<<cur->data;

}

void recursive_display2(Node*cur=head){
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    if(cur!=NULL){ 
    cout<<cur->data<<endl;
    recursive_display2(cur->next);
    }
    

}
 


int main(){
    int choice,value;
    while(true){
        cout<<"\n1.Insert\n2.Sorted_insertion\n3.Unique_insertion\n4.Search\n5.Delete\n6.Display\n7.r display\n8.bubble sort\n9.selection\n10.insertion at index";
        cin>>choice;

       switch (choice){ 
        case 1:
        cout<<"Enter a value\n";
        cin>>value;
        insert(value);
        break;

        case 2:
        cout<<"Enter a value\n";
        cin>>value;
        sorted_insertion(value);
        break;

        
        case 3:
        cout<<"Enter a value\n";
        cin>>value;
        unique_insertion(value);
        break;


        case 4:
        cout<<"Enter a value\n";
        cin>>value;
        search(value);
        break;

        case 5:
        cout<<"Enter a value to delete\n";
        cin>>value;
        dele(value);
        break;


        case 6:
        display();
        break;

        case 7:
        reverse();
        break;

        case 8:
        bubblesort();
        break;

        case 9:
        selectionsort();
        break;

        case 10:
        cout<<"Enter pos first then value";
        cin>>choice;
        cin>>value;
        insertion_at_index(choice,value);
        break;




        case 11:
        cout<<"bbyeee\n";
        return 0;


        default:
        cout<<"Sahi choose kroo\n";
        break;
       
       }
    }

}


