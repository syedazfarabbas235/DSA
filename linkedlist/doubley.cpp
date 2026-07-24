#include <iostream>
#include <cstdlib>
using namespace std;


struct Node{ 
    int data;
    Node*next;
    Node*prev;
    int index;
};
Node*head=NULL;
Node*tail=NULL;
int countt=0;

void insert(int value){
    Node*temp=(Node*)malloc(sizeof (Node));
    temp ->data=value;
    temp ->next=NULL;
    temp->prev=NULL;

    if(head==NULL){
        head=temp;
    } else {
        Node*cur=head;
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
        
    }
    
}
void insert1(int value){
    Node*temp=(Node*)malloc(sizeof (Node));
    temp ->data=value;
    temp ->next=NULL;
    temp->prev=NULL;
    temp->index=countt;

    if(head==NULL){
        head=temp;
    } else {
        Node*cur=head;
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
        
    }
    tail=temp;
    countt++;
}

void search(int value) { 
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    Node*cur=head;
    int pos=1;
    bool found=false;
    while(cur!=NULL){
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
    int pos=2;
    bool found=false;
    if (value==head->data){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(cur);
        cout<<value<<" value successfully deleted at pos: 1\n";
        return;
    }
    Node*previ=head;
    cur=head->next;
    Node*temp1=cur->next;
    while(cur!=NULL){
        if(value ==cur->data){
            found=true;
            if(temp1!=NULL){
                temp1->prev=previ;
            }
            previ->next=cur->next;
            free(cur);
            break;
        }   
        temp1=temp1->next;
        previ=cur;
        cur=cur->next;
        pos++;
    }
    if(!found){
        cout<<value<<"kia delete karu jab kuch hai hi nahi........\n";
    }
    else{ 
        cout<<value<<" value successfully deleted at pos: "<<pos<<endl;
    }   


}

void reverse(){

    Node*prev1=NULL;
    Node*cur=head;
    Node*temp=NULL;
    while(cur!=NULL){

        temp=cur->next;
        cur->next=prev1;
        cur->prev=temp;
        prev1=cur;
        cur=temp;

    }

    head=prev1;
}

void find_minmax(){
    Node*min=head;
    Node*max=head;
    Node*cur=head;
    while(cur!=nullptr){
        if(cur->data<min->data){
            min=cur;
        }
        else if(cur->data>max->data){ 
            max=cur;
        }  
        cur=cur->next;
    }
    cout<<"min value is: "<<min->data<<endl;
    cout<<"max value is: "<<max->data;
}
void display_forward(){
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
void display_backward(){
    Node*cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    while(cur->next!=NULL){
        cur=cur->next;
    }
    while(cur!=NULL){
        cout<<cur->data<<"->";
        cur=cur->prev;
    }

    cout<<"NULL\n";  
}



Node*set_pivot(Node*L,Node*R){
    int pivot_data=R->data;
    Node*i=L->prev;

    for(Node*j=L;j!=R;j=j->next)
    if(j->data<pivot_data){
        if(i==nullptr){
            i=L;
        }
        else{
            i=i->next;

        }
        swap(i->data,j->data);
    }

    if(i==nullptr){
        i=L;
    }
    else{
        i=i->next;

    }
    swap(i->data,R->data);
    return i;

}

void quick_sort(Node*L,Node*R){
    if(L==NULL||R==NULL||L==R||L->prev==R) return;
        Node*p= set_pivot(L,R);
        quick_sort(L,p->prev);
        quick_sort(p->next,R);

    
}



int main(){
    int choice,value;
    while(true){
        cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display_forward\n5.Display_backward\n6.reverse\n7.find min max\n8.exit";
        cin>>choice;

       switch (choice){ 
        case 1:
        cout<<"Enter a value\n";
        cin>>choice;
        insert1(choice);
        break;

        case 2:
        cout<<"Enter the value to search\n";
        cin>>choice;
        search(choice);


        case 3:
        cout<<"Enter the value to delete\n";
        cin>>choice;
        dele(choice);




        case 4:
        display_forward();
        break;

        case 5:
        display_backward();
        break;

        case 6:
        reverse();
        break;

        case 7:
        find_minmax();
        break;

        case 8:
        quick_sort(head,tail);
        break;


        case 9:
        cout<<"bbyeee\n";
        return 0;
        
        

        default:
        cout<<"Sahi choose kroo\n";
        break;
       
       }
    }

}


