#include <iostream>
using namespace std;

struct edge{
    vertex*dest;
    edge*next;
};

struct vertex{
    char data;
    vertex*next;
    edge*edgelist;
    bool visited=false;
    vertex*parent=nullptr;
    bool in_path=false;
    int in_degree;
};
vertex*v_head=nullptr;
int type;


void add_vertex(char data){
    vertex*temp=new vertex;
    temp->data=data;
    temp->next=nullptr;
    temp->edgelist=nullptr;

    if(v_head==nullptr){
        v_head=temp;
    }
    else{
        vertex*cur=v_head;
        while(cur->next!=nullptr){
            cur=cur->next;
        }
        cur->next=temp;
    }

}

void remove_vertex(char value){

    if(v_head==nullptr){
        return;
    }
    vertex*cur=v_head;
    if(v_head->data==value){
        edge*e_cur=cur->edgelist;
        edge*temp=e_cur;
        while(e_cur!=nullptr){
            e_cur=e_cur->next;
            delete temp;
            temp=e_cur;
        }
        v_head=v_head->next;
        delete cur;
    }
    else{
        vertex*prev=v_head;
        cur=v_head->next;
        while(cur!=nullptr){
            if(cur->data==value){
                edge*e_cur=cur->edgelist;
                edge*temp=e_cur;
                while(e_cur!=nullptr){
                    e_cur=e_cur->next;
                    delete temp;
                    temp=e_cur;
                }
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }
            else{
                prev=cur;
                cur=cur->next;
            }

        }
    }

    cur=v_head;
    
    while(cur!=nullptr){
        edge*e_cur=cur->edgelist;

        if(e_cur==nullptr){
            cur=cur->next;
            continue;
        
        }
        if(e_cur->dest->data==value){
            cur->edgelist=e_cur->next;
            delete e_cur;
            e_cur=cur->edgelist;
        }
        edge*prev=cur->edgelist;
        if(e_cur!=nullptr){
            e_cur=e_cur->next;
        
            while(e_cur!=nullptr){
                if(e_cur->dest->data==value){
                    prev->next=e_cur->next;;
                    delete e_cur;
                    e_cur=prev->next;
                }
                else{
                    prev=e_cur;
                    e_cur=e_cur->next;  
                }
            }
        }
        cur=cur->next;
        
    }

}

void add_edge(char source,char destination){

    vertex*src=nullptr;
    vertex*destt=nullptr;

    vertex*cur=v_head;
    while(cur!=nullptr){
        if(cur->data==source) src=cur;
        if(cur->data==destination) destt=cur;
        cur=cur->next;
    }

    
    edge*e_temp=new edge;
    e_temp->dest=destt;
    e_temp->next=nullptr;
    if(src->edgelist==nullptr){
        src->edgelist=e_temp;
    }
    else{
        edge*e_cur=src->edgelist;
        while(e_cur->next!=nullptr){
            e_cur=e_cur->next;
        }
        e_cur->next=e_temp;
        }

    if(type==2){
        edge*e_temp2=new edge;
        e_temp2->dest=src;
        e_temp2->next=nullptr;
    
        if(destt->edgelist==nullptr){
            destt->edgelist=e_temp2;
        }
        else{
            edge*e_cur2=destt->edgelist;
            while(e_cur2->next!=nullptr){
                e_cur2=e_cur2->next;
            }
            e_cur2->next=e_temp2;
        }
    }

}

void remove_edge(char source,char destination){

    vertex*cur=v_head;
    vertex*src=nullptr;
    vertex*destt=nullptr;

    while(cur!=nullptr){
        if(cur->data==source) src=cur;
        if(cur->data==destination) destt=cur;
        cur=cur->next;
    }
    if(src==nullptr || destt==nullptr) return;

        if(src->edgelist==nullptr) return;
        edge*e_cur=src->edgelist;
        if(e_cur->dest==destt){
            src->edgelist=e_cur->next;
            delete e_cur;
            e_cur=src->edgelist;
        }
        else {
            edge*prev=e_cur;
            if(e_cur!=nullptr){
                e_cur=e_cur->next;
            }
            while(e_cur!=nullptr){
                if(e_cur->dest==destt){
                    prev->next=e_cur->next;
                    delete e_cur;
                    e_cur=prev->next;
                }
                else{
                    prev=e_cur;
                    e_cur=e_cur->next;
                }
            }
            
        }

        if (type==2){
            if(destt->edgelist==nullptr) return;
            edge*e_cur=destt->edgelist;
            if(e_cur->dest==src){
                destt->edgelist=e_cur->next;
                delete e_cur;
                e_cur=destt->edgelist;
            }
            else{
                edge*prev=e_cur;
                if(e_cur!=nullptr){
                    e_cur=e_cur->next;
                }
                while(e_cur!=nullptr){
                    if(e_cur->dest==src){
                        prev->next=e_cur->next;
                        delete e_cur;
                        e_cur=prev->next;
                    }
                    else{
                        prev=e_cur;
                        e_cur=e_cur->next;
                    }
                }

            }
        }

    

}


int in_degree(char destination){
    vertex*cur=v_head;
    int count =0;

    while(cur!=nullptr){
        edge*e_cur= cur->edgelist;
        while(e_cur!=nullptr){
            if(e_cur->dest->data==destination){
                count++;
            }
            e_cur=e_cur->next;
        }
        cur=cur->next;
    }
    return count;
}

int out_degree(char source){
    vertex*cur=v_head;
    int count=0;

    while(cur!=nullptr){
        if(cur->data==source){
            break;
        } 
        cur=cur->next;
    }

    edge*e_cur=cur->edgelist;
    while(e_cur!=nullptr){
        count++;
        e_cur=e_cur->next;
    }

    return count;
}

int degree(char source){
    return out_degree(source);
}



struct queue{
    vertex*data;
    queue*next;
};
queue*rear=NULL;
queue*front=NULL;

void enqueue(vertex* value){
    queue*temp=new queue;
    temp->data=value;
    temp->next=NULL;
    if(rear==NULL){
        rear=temp;
        front=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

vertex* dequeue(){
    if(front==NULL){
        cout<<"Nothing here cant dequeue\n";
        return nullptr;
    }
    queue*cur=front;
    vertex*value=front->data;
    //cout<<front->data;
    front=front->next;
    delete cur;
    if (front==NULL){
        rear=NULL;
    }
    return value;
}

void resetVertices() {
    vertex* cur = v_head;
    while(cur != nullptr) {
        cur->visited = false;
        cur->parent = nullptr;
        cur = cur->next;
    }
}

struct stack
{
    vertex*data;
    stack*next;
};
stack*top=nullptr;

void push(vertex*val){
    stack*temp=new stack;
    temp->data=val;
    temp->next=nullptr;
    if(top==nullptr){
        top=temp;
    }
    else{
        temp->next=top;
        top=temp;
    }
}

vertex*pop(){
    if(top==nullptr){
        return;
    }
    stack*temp=top;
    vertex*value=top->data;
    top=top->next;
    delete temp;
    return value;

}

void dfs_path(char source,char destination){
    resetVertices();
    vertex*src=nullptr;
    vertex*destt=nullptr;
    vertex*cur=v_head;
    while(cur!=nullptr){
        if(cur->data==source)src=cur;
        if(cur->data==destination)destt=cur;
        cur=cur->next;
    }
    if (src ==nullptr || destt==nullptr){
        return;
    }
    bool found=false;
    src->visited=true;
    push(src);
    while(top!=nullptr){
        vertex*current=pop();

        if(current->data == destination){
            cout<<"path found.\n";
            found=true;
            break;
        }

        edge*e_cur=current->edgelist;
        while(e_cur!=nullptr){
            vertex*neighbour=e_cur->dest;
            if(!neighbour->visited){
                neighbour->visited=true;
                push(neighbour);
                neighbour->parent=current;
            }
            e_cur=e_cur->next;
        }
    }
    if(!found){
        cout<<"No path\n";
        return;
    }
    vertex*path[100];
    int count=0;
    cur=destt;
    while(cur!=nullptr){
        path[count]=cur;
        count++;
        cur=cur->parent;
    }

    for(int i=count-1;i>=0;i--){
        cout<<path[i]->data;
    }


}

void dfs_cycle(){
    resetVertices();

    vertex*cur=v_head;
    if(cur==nullptr){
        return;
    }
    while(cur!=nullptr){
        if(!cur->visited){
            cur->visited=true;
            push(cur);
        

            while(top!=nullptr){
                vertex*current=pop();

                edge*e_cur=current->edgelist;
                while(e_cur!=nullptr){
                    vertex*neighbour=e_cur->dest;
                    if(neighbour->visited==true && neighbour!=current->parent){
                        cout<<"cycle found\n";
                        return;
                    }
                    if(!neighbour->visited){
                        neighbour->visited=true;
                        push(neighbour);
                        neighbour->parent=current;
                    }
                    e_cur=e_cur->next;
                }
            }
        }
        cur=cur->next;
    }
}

void dfs_directed_cycle(){
    resetVertices();
    vertex*cur=v_head;
    if(cur==nullptr){
        return;
    }
    while(cur!=nullptr){
        if(!cur->visited){
            cur->visited=true;
            cur->in_path=true;
            push(cur);

            while(top!=nullptr){
                vertex*current=top->data;
                edge*e_cur=current->edgelist;
                bool pushed=false;
                while(e_cur!=nullptr){
                    vertex*neighbour=e_cur->dest;
                    if(neighbour->in_path==true){
                        cout<<"its a cycle.\n";
                        return;
                    }
                    if(!neighbour->visited){
                        neighbour->visited=true;
                        neighbour->in_path=true;
                        push(neighbour);
                        pushed=true;
                    }
                    e_cur=e_cur->next;
                }
                if(!pushed){
                    pop();
                    current->in_path=false;
                }
            }
        }
        cur=cur->next;
    }
}



void bfs_path(char source,char destination){
    resetVertices();
    vertex*src=nullptr;
    vertex*destt=nullptr;
    vertex*cur=v_head;
    while(cur!=nullptr){
        if(cur->data==source)src=cur;
        if(cur->data==destination)destt=cur;
        cur=cur->next;
    }

    if (src ==nullptr || destt==nullptr){
        return;
    }

    src->visited=true;
    enqueue(src);
    bool found=false;
    while(front!=nullptr){
        vertex*current=dequeue();

        if(current->data == destination){
            cout<<"path found\n";
            found=true;
            break;
        }

        edge*e_cur=current->edgelist;
        while(e_cur!=nullptr){
            vertex*neighbour=e_cur->dest;// stores destination of where its pointing.
            
            if(!neighbour->visited){
                neighbour->visited=true;
                enqueue(neighbour);
                neighbour->parent=current;
            }
            e_cur=e_cur->next;
        }
    }
    if(!found){
        cout<<"No path\n";
        return;
    }

    vertex*path[100];
    int count =0;
    cur=destt;
    while(cur!=nullptr){
        path[count]=cur;
        count++;
        cur=cur->parent;
    }
    for(int i=count-1;i>=0;i--){
        cout<<path[i]->data;
    }
}

void bfs_traversal(char source){
    resetVertices();

    vertex*src=nullptr;
    vertex*cur=v_head;

    while(cur!=nullptr){
        if(cur->data==source) src= cur;
        cur=cur->next;
    }

    src->visited=true;
    enqueue(src);

    while(front!=nullptr){
        vertex*current=dequeue();

        cout<<current->data;

        edge*e_cur=current->edgelist;

        while(e_cur!=nullptr){
            vertex*neighbour=e_cur->dest;
            if(!neighbour->visited){
                neighbour->visited=true;
                enqueue(neighbour);
            }
            e_cur=e_cur->next;
        }
    }
}


void is_cycle(){
    resetVertices();

    vertex*cur=v_head;



    if(cur==nullptr){
        cout<<"Source not found\n";
        return;
    }

    while (cur!=nullptr){
        if(!cur->visited){
            cur->visited=true;
            enqueue(cur);
            


            while(front!=nullptr){
                vertex*current=dequeue();


                edge*e_cur=current->edgelist;

                while(e_cur!=nullptr){
                    vertex*neighbour=e_cur->dest;

                    if(neighbour->visited==true && neighbour!=current->parent){ // if neighbour isnt the parent then its cycle.
                        cout<<"cycle found.\n";
                        return;
                    }
                    if(!neighbour->visited){
                        neighbour->visited=true;
                        enqueue(neighbour);
                        neighbour->parent=current;
                    }
                    e_cur=e_cur->next;
                }
            }
        }
        cur=cur->next;
    }

    cout<<"No cycle.\n";
    
}

void directed_cycle(){

    vertex*cur=v_head;
    if(cur==nullptr){
        cout<<"Source not found\n";
        return;
    }


    int total_nodes=0;
    cur=v_head;
    while(cur!=nullptr){
        cur->in_degree=in_degree(cur->data);
        total_nodes++;
        cur=cur->next;
    }

    front = rear = nullptr;

    cur=v_head;
    while(cur!=nullptr){
        if(cur->in_degree==0){
            enqueue(cur);
            cur->visited=true;
        }
        cur=cur->next;
    }

    int processed=0;

    while(front!=nullptr){
        vertex*current=dequeue();
        processed++;
        
        edge*e_cur=current->edgelist;
        while(e_cur!=nullptr){
            vertex*neighbour=e_cur->dest;
            neighbour->in_degree--;
            if(neighbour->in_degree==0 && !neighbour->visited){
                neighbour->visited=true;
                enqueue(neighbour);
            }
            e_cur=e_cur->next;

        }
    }

    if(processed!=total_nodes){
        cout<<"cycle found\n";
    }
    else{
        cout<<"cycle not found.\n";
    }
}
















