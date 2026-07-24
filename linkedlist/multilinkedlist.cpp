#include <iostream>
#include <cstdlib>
using namespace std;

struct S_node{
    string seat_no;
    S_node*next;
};

struct C_node{
    string course_no;
    C_node*next;
    S_node*student_list;
};

C_node*head=NULL;

void insert_course(string c_no){
    C_node*temp=new C_node;
    temp->course_no=c_no;
    temp->next=NULL;
    temp->student_list=NULL;

    if(head==NULL){
        head=temp;
    }
    else{  
    C_node*cur=head;
    while(cur->next!=NULL){
        if(cur->course_no==c_no){
            cout<<"Course no cant be repeated errorrrrrr\n";
            return;
        }
        cur=cur->next;
    }
    if(cur->course_no==c_no){
        cout<<"Course no cant be repeated errorrrrrr\n";
        return;
    }
    cur->next=temp;
    }
}


void insert_students(string c_no,string s_no){
    C_node*c_cur=head;
    bool found=false;
    if(head==NULL){
        cout<< "Course offer nahi horrha or students enroll karne hain zero civic sense\n";
        return; 
    }
    while(c_cur!=NULL){
        if(c_cur->course_no==c_no){
            found=true;
            S_node*temp=new S_node;
            temp->seat_no=s_no;
            temp->next=NULL;

            if(c_cur->student_list==NULL){
            c_cur->student_list=temp;
            return;
            }
            else{
                S_node*s_cur=c_cur->student_list;
                while(s_cur->next!=NULL){
                    if(s_cur->seat_no==s_no){
                        cout<<"seat no cant be repeated errorrrrrr\n";
                        return;
                        }
                        s_cur=s_cur->next;
                }
                if(s_cur->seat_no==s_no){
                    cout<<"seat no cant be repeated errorrrrrr\n";
                    return;
                    }
                s_cur->next=temp;
                return;
            }
        }
        c_cur=c_cur->next;
    }
    if(!found){
        cout<<c_no<<"course hi nh h yeh koi to kaha enroll\n";
    }
}

void search_courses(string c_no) { 
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    C_node*cur=head;
    int pos=1;
    bool found=false;
    while(cur!=NULL){
        if(cur->course_no==c_no){
        cout<<"value found at: "<<pos<<endl;
        found=true;
        }
        cur=cur->next;
        pos++;
    }
    if(!found){
        cout<<c_no<<"aint here so give me 500rs \n";
    }
    else{ 
        cout<<"search complete\n";
    }   
}

void search_student1(string c_no,string s_no){
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    C_node*c_cur=head;
    int pos=1;
    bool found=false;
    while(c_cur!=NULL){
        if(c_cur->course_no==c_no){
            cout<<"In "<<c_no;
            S_node*s_cur=c_cur->student_list;
            while(s_cur!=NULL){
                if(s_cur->seat_no==s_no){
                    found=true;
                    cout<<" student is find at pos: "<<pos<<endl;
                }
                s_cur=s_cur->next;
                pos++;
            }
            if(!found){
            cout<<s_no<<"aint here so give me 500rs \n";
            }
            return;
        }
        c_cur=c_cur->next;

    }
}

void search_student2(string s_no){
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    C_node*c_cur=head;
    while(c_cur!=NULL){  
        S_node*s_cur=c_cur->student_list;
        while(s_cur!=NULL){
            if(s_no==s_cur->seat_no){
                cout<<s_no<<" is found in the course: "<<c_cur->course_no<<endl;
            }
            s_cur=s_cur->next;
        }
        c_cur=c_cur->next;
    }

}

void delete_course(string c_no){
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    C_node*c_cur=head;
    if(head->course_no==c_no){
        S_node*s_cur=c_cur->student_list;
        while(s_cur!=NULL){
            S_node*temp=s_cur;
            s_cur=s_cur->next;
            delete temp;
        }
        head=head->next;
        delete c_cur;
        cout<<c_no<<" course successfully deleted at pos: 1\n";
        return;
    }

    C_node*prev=head;
    c_cur=head->next;
    bool found=false;
    while(c_cur!=NULL){
        if(c_cur->course_no==c_no){
            found=true;
            S_node*s_cur=c_cur->student_list;
            while(s_cur!=NULL){
                S_node*temp=s_cur;
                s_cur=s_cur->next;
                delete temp;
            }
            prev->next=c_cur->next;
            delete c_cur;
            c_cur=prev->next;
        }
        else{
            prev=c_cur;
            c_cur=c_cur->next;
        }
    }

    if(!found){
        cout<<c_no<<"aint here so give me 500rs \n";
    }
    else{ 
        cout<<"value deleted\n";
    }   
}

void remove_student1(string c_no,string s_no){
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    C_node*c_cur=head;
    int pos=2;
    bool found=false;
    while(c_cur!=NULL){
        if(c_cur->course_no==c_no){
            cout<<"In "<<c_no;
            S_node*s_head=c_cur->student_list;
            if(s_head==NULL){
            cout<<" No student in there"<<endl;
            return;
            }
            if(s_head->seat_no==s_no){
                found=true;
                c_cur->student_list=s_head->next;
                delete s_head;
                cout<<" student is removed at pos: 1 "<<endl;
                return;
            }
            else{   
                S_node*s_cur=s_head->next;
                S_node*s_prev=s_head;   
                while(s_cur!=NULL){
                    if(s_cur->seat_no==s_no){
                        found=true;
                        s_prev->next=s_cur->next;
                        delete s_cur;
                        s_cur=s_prev->next;
                        cout<<" student is removed at pos: "<<pos<<endl;
                        return;
                    }
                    else{ 
                        s_prev=s_cur;
                        s_cur=s_cur->next;
                        pos++;
                    }
                }
            }
            if(!found){
            cout<<s_no<<"aint here so give me 500rs \n";
            }
        }
        c_cur=c_cur->next;

    }
}

void remove_student2(string s_no){
    if(head==NULL){
        cout<<"List is empty kia find kroge esa karo sojao.\n";
        return;
    }
    C_node*c_cur=head;
    bool found=false;
    while(c_cur!=NULL){
        S_node*s_head=c_cur->student_list;
        if(s_head==NULL){
        cout<<"No student in this course: "<<c_cur->course_no<<endl;
        c_cur=c_cur->next;
        continue;
        }
        if(s_head->seat_no==s_no){
            found=true;
            c_cur->student_list=s_head->next;
            delete s_head;
            cout<<"student is removed from the course: "<<c_cur->course_no<<endl;
        }
        else{   
            S_node*s_cur=c_cur->student_list->next;
            S_node*s_prev=c_cur->student_list;   
            while(s_cur!=NULL){
                if(s_cur->seat_no==s_no){
                    found=true;
                    s_prev->next=s_cur->next;
                    delete s_cur;
                    s_cur=s_prev->next;
                    cout<<"student is removed from the course: "<<c_cur->course_no<<endl;
                }
                else{ 
                    s_prev=s_cur;
                    s_cur=s_cur->next;
                }
            }
        }
        c_cur=c_cur->next;

    }
    if(!found){
            cout<<s_no<<" aint here so give me 500rs \n";
        }
    else{ 
        cout<<"remove complete\n";
        }   
}

    



void display_all(){
    C_node*c_cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    while(c_cur!=NULL){
        cout<<c_cur->course_no<<": ";
        S_node*s_cur=c_cur->student_list;
        while(s_cur!=NULL){
            cout<<s_cur->seat_no;
            if(s_cur->next!=NULL){
                cout<<",";
            }
            s_cur=s_cur->next;
        }
        cout<<endl; 
        c_cur=c_cur->next;       
    }
}
void display_courses(){
    C_node*c_cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    while(c_cur!=NULL){
        cout<<c_cur->course_no<<endl;
        c_cur=c_cur->next;
    }    
}

void display_course_students(string c_no){
    C_node*c_cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    while(c_cur!=NULL){
        if(c_cur->course_no==c_no){
            cout<<c_cur->course_no<<": ";
            S_node*s_cur=c_cur->student_list;
            while(s_cur!=NULL){
                cout<<s_cur->seat_no;
                if(s_cur->next!=NULL){
                    cout<<",";
                }
                s_cur=s_cur->next;
            }
            return;
        }
        c_cur=c_cur->next;
    }
    


}
void display_students(){
    C_node*c_cur=head;
    if(head==NULL){
        cout<< "List is empty kuch daalo phele\n";
        return; 
    }
    while(c_cur!=NULL){
        S_node*s_cur=c_cur->student_list;
        while(s_cur!=NULL){
            cout<<s_cur->seat_no<<endl;
            s_cur=s_cur->next;
        }
        c_cur=c_cur->next;
    }
}



int main(){
    int choice;
    string c_no,s_no;
    while(true){
        cout<<"\n1.Insert a course\n2.Insert a student\n3.Search a course\n4.Search a student in a course\n5.Search a student\n6.Delete a course\n7.Remove a student from a course\n8.Remove a student\n9.Display the courses\n10.Display the students\n11.Display all\n12.Exit\n";
        cin>>choice;
    

    switch (choice){ 
        case 1:
        cout<<"Enter the course no\n";
        cin>>c_no;
        insert_course(c_no);
        break;

        case 2:
        cout<<"Enter the course no first then student's seat no\n";
        cin>>c_no>>s_no;
        insert_students(c_no,s_no);
        break;

        
        case 3:
        cout<<"Enter the course to search\n";
        cin>>c_no;
        search_courses(c_no);
        break;

        case 4:
        cout<<"Enter the course no first then student's seat no\n";
        cin>>c_no>>s_no;
        search_student1(c_no,s_no);
        break;

        case 5:
        cout<<"Enter the student to search\n";
        cin>>s_no;
        search_student2(s_no);
        break;


        case 6:
        cout<<"Enter the course to delete\n";
        cin>>c_no;
        delete_course(c_no);
        break;

        case 7:
        cout<<"Enter the course no first then student's seat no\n";
        cin>>c_no>>s_no;
        remove_student1(c_no,s_no);
        break;

        case 8:
        cout<<"Enter the seat no to remove\n";
        cin>>s_no;
        remove_student2(s_no);
        break;


        case 9:
        display_courses();
        break;


        case 10:
        cout<<"Enter which course students you want to see\n";
        cin>>c_no;
        display_course_students(c_no);
        break;

        case 11:
        display_all();
        break;

        case 12:
        cout<<"bbyeee\n";
        return 0;

        default:
        cout<<"Sahi choose kroo\n";
        break;
       
       }
    }

}

