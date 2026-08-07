#include <iostream>
using namespace std;



struct graph
{
    int matrix [10][10];
    int limit;
    int vertex_count=0;
    int type;
    string name[10];
};
graph g;


void add_vertex(string name){
    if(g.vertex_count>g.limit){
        cout<<"Limit dull\n.";
        return;
    }

    g.name[g.vertex_count]=name;
    g.vertex_count++;

    for(int i=0;i<g.limit;i++){
        g.matrix[i][g.vertex_count-1]=0;
        g.matrix[g.vertex_count-1][i]=0;
    }

    cout<< name<<" vertex is added.\n";
}


void remove_vertex(string name){
    int index=-1;
    for(int i=0;i<g.vertex_count;i++){
        if(g.name[i]==name){
            index=i;
            break;
        }
    }

    if (index==-1){
        return;
    }


    for (int i=index;i<g.vertex_count-1;i++){
        for(int j=0;j<g.vertex_count;j++){
            g.matrix[i][j]=g.matrix[i+1][j];
        }
    }

    for (int i=index;i<g.vertex_count-1;i++){
        for (int j=0;j<g.vertex_count;j++){
            g.matrix[j][i]=g.matrix[j][i+1];
        }
    }

    for (int i=index;i<g.vertex_count;i++){
        g.name[i]=g.name[i+1];
    }

    g.vertex_count--;

    cout<<name<<" removed.\n";

}


void add_edge(string v1,string v2){
    int index1=-1;
    int index2=-1;

    for(int i=0;i<g.vertex_count;i++){
        if(g.name[i]==v1){
            index1=i;
        }
        if(g.name[i]==v2){
            index2=i;
        }
    }

    if(index1  ==-1|| index2 ==-1){
        cout<<"not fouund\n";
        return;
    }

    if(g.type==1){
        g.matrix[index1][index2]=1;
    }
    if(g.type==2){
        g.matrix[index1][index2]=1;
        g.matrix[index2][index1]=1;
    }

    cout<<"edge between: "<<v1<<" and "<<v2<<endl;

    
}

void remove_edge(string v1,string v2){
    int index1=-1;
    int index2=-1;

    for(int i=0;i<g.vertex_count;i++){
        if(g.name[i]==v1){
            index1=i;
        }
        if(g.name[i]==v2){
            index2=i;
        }
    }

    if(index1 ==-1 || index2 ==-1){
        cout<<"not fouund\n";
        return;
    }

    if(g.type==1){
        g.matrix[index1][index2]=0;
    }
    if(g.type==2){
        g.matrix[index1][index2]=0;
        g.matrix[index2][index1]=0;
    }

    cout<<"edge remove between: "<<v1<<" and "<<v2<<endl;

    
}

int stack[100];
int top = 0;

void Push(int value){
    if(top == 100){
        cout << "Stack overflow.\n";
        return;
    }
    stack[top] = value;
    top++;
}

int pop(){
    if(top == 0){
        cout << "Stack underflow\n";
        return -1; 
    }
    top--;
    return stack[top];
}

bool visited[10]={false};

bool dfs_path(string v1,string v2){
    int start=-1,target=-1;

    for(int i=0;i<g.vertex_count;i++){
        if(g.name[i]==v1) start=i;
        if(g.name[i]==v2) target=i;
    }

    if(start == -1 || target == -1){
        cout << "Vertex not found\n";
        return false;
    }

    for (int i=0;i<g.vertex_count;i++){  //reset
        visited[i]=false;
    }

    top=0; //reset stack;
    Push(start);

    while(top!=0){
        int cur=pop();


        if(cur==target){
            cout<<"path found\n";
            return true;
        }

        if(!visited[cur]){
            visited[cur]=true;
        }

        for (int i=0;i<g.vertex_count;i++){
            if(g.matrix[cur][i]==1 && !visited[i]){
                Push(i);
            }
        }

    }
    cout<<"No path found\n";
    return false;
}


int in_degree(string name){
    if(g.type==2){
        cout<<"invalid\n";
        return -1;
    }

    int cur=-1;
    int in_degree=0;
    for (int i=0;i<g.vertex_count;i++){
        if(g.name[i]==name){
            cur=i;
            break;
        }
    }
    if (cur==-1){
        return-1;
    }

    for(int i=0;i<g.vertex_count;i++){
        if(g.matrix[i][cur]==1){
            in_degree++;
        }
    }

    //cout<<"Degree of "<<name<<" is : "<<endl;
    return in_degree;
}

int out_degree(string name){
    if(g.type==2){
        cout<<"invalid\n";
        return -1;
    }

    int cur=-1;
    int out_degree=0;
    for (int i=0;i<g.vertex_count;i++){
        if(g.name[i]==name){
            cur=i;
            break;
        }
    }
    if (cur==-1){
        return -1;
    }

    for(int i=0;i<g.vertex_count;i++){
        if(g.matrix[cur][i]==1){
            out_degree++;
        }
    }

    //cout<<"Degree of "<<name<<" is : "<<endl;
    return out_degree;
}



void find_degree(string name){
    int cur=-1;
    int degree=0;

    for (int i=0;i<g.vertex_count;i++){
        if(g.name[i]==name){
            cur=i;
            break;
        }
    }
    if (cur==-1){
        return;
    }


    if(g.type==2){ 
        for (int i=0;i<g.vertex_count;i++){
            if(g.matrix[cur][i]==1){
                degree++;
            }
        }
    }
    else{
            int indeg= in_degree(name);
            int outdeg= out_degree(name);
            degree= indeg+outdeg;
        }

    cout<<"Degree of "<<name<<" is : "<<degree<<endl;
}








int main(){
    cout<<"How many vertices u want to add?";
    cin>>g.limit;
    
    cout<<"Directed graph or undirected graph?\nFor directed press 1 and for undirected press 2.\n";
    cin>>g.type;
    
    int choice;
    string name,name2;

    while (true){
        cout<<"1.Add vertex\n2.remove vertex\n3.add an edge\n4.remove an edge\n5.find a path\n6.find degree\n7.find in degree\n8.find out degree";
        cout<<"Enter the choice";
        cin>>choice;
    

        switch (choice)
        {
        case 1:
        cout << "Enter name of vertex: ";
        cin >> name;
        add_vertex(name);
        break;

        case 2 :   
        cout << "Enter name of vertex: ";
        cin >> name;
        remove_vertex(name);
        break; 

        case 3 :
        cout << "Enter two vertex names (e.g. A B): ";
        cin >> name >> name2;
        add_edge(name, name2);
        break;

        case 4:
        cout << "Enter two vertex names to remove (e.g. A B): ";
        cin >> name >> name2;
        remove_edge(name, name2);
        break;

        case 5:
        cout<<"Enter two vertex to find their path.\n";
        cin>>name>>name2;
        dfs_path(name,name2);
        break;

        case 6 :   
        cout << "Enter name of vertex: ";
        cin >> name;
        find_degree(name);
        break;

        case 7 :   
        cout << "Enter name of vertex: ";
        cin >> name;
        in_degree(name);
        break;

        case 8 :   
        cout << "Enter name of vertex: ";
        cin >> name;
        out_degree(name);
        break;
        
        default:
            break;
        }
}



}
