#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct vertex;

struct edge{
    vertex* dest;
    edge* next;
};

struct vertex{
    int row, col;
    vertex* next;         // links this vertex into the master vertex list
    edge* edgelist;       // this vertex's own adjacency list
    bool visited = false;
    vertex* parent = nullptr;
};

vertex* v_head = nullptr;
vertex** lookup = nullptr;   // lookup[cell_id] -> vertex*, just for O(1) access by coordinate
int n, m;

int cell_id(int i, int j){ return i * m + j; }

void add_vertex(int row, int col){
    vertex* temp = new vertex;
    temp->row = row;
    temp->col = col;
    temp->next = nullptr;
    temp->edgelist = nullptr;

    if(v_head == nullptr){
        v_head = temp;
    } else {
        vertex* cur = v_head;
        while(cur->next != nullptr) cur = cur->next;
        cur->next = temp;
    }

    lookup[cell_id(row, col)] = temp;
}

void add_edge(vertex* src, vertex* dest){
    edge* e_temp = new edge;
    e_temp->dest = dest;
    e_temp->next = nullptr;

    if(src->edgelist == nullptr){
        src->edgelist = e_temp;
    } else {
        edge* e_cur = src->edgelist;
        while(e_cur->next != nullptr) e_cur = e_cur->next;
        e_cur->next = e_temp;
    }
}

struct queue{ vertex* data; queue* next; };
queue* front = nullptr; queue* rear = nullptr;

void enqueue(vertex* value){
    queue* temp = new queue;
    temp->data = value; temp->next = nullptr;
    if(rear == nullptr){ rear = temp; front = temp; }
    else { rear->next = temp; rear = temp; }
}
vertex* dequeue(){
    queue* cur = front;
    vertex* value = front->data;
    front = front->next;
    delete cur;
    if(front == nullptr) rear = nullptr;
    return value;
}
bool is_queue_empty(){ return front == nullptr; }

int** A = nullptr;

void allocate_and_fill_maze(){
    A = new int*[n];
    for(int i = 0; i < n; i++) A[i] = new int[m];
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            A[i][j] = rand() % 2;
    A[0][0] = 0;
    A[n-1][m-1] = 0;
}

void print_maze(){
    cout << "Maze (0=open, 1=blocked):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << A[i][j] << " ";
        cout << endl;
    }
}

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void build_graph(){
    lookup = new vertex*[n * m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            add_vertex(i, j);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 1) continue;
            vertex* src = lookup[cell_id(i,j)];
            for(int d = 0; d < 8; d++){
                int ni = i + dr[d];
                int nj = j + dc[d];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && A[ni][nj] == 0){
                    vertex* dst = lookup[cell_id(ni,nj)];
                    add_edge(src, dst);
                }
            }
        }
    }
}

bool find_path_bfs(vertex* start, vertex* end){
    enqueue(start);
    start->visited = true;

    while(!is_queue_empty()){
        vertex* cur = dequeue();

        if(cur == end){
            while(!is_queue_empty()) dequeue();
            return true;
        }

        edge* e = cur->edgelist;
        while(e != nullptr){
            if(!e->dest->visited){
                e->dest->visited = true;
                e->dest->parent = cur;
                enqueue(e->dest);
            }
            e = e->next;
        }
    }
    return false;
}

void print_path(vertex* end){
    if(end->parent == nullptr){
        cout << "(" << end->row << "," << end->col << ")";
        return;
    }
    print_path(end->parent);
    cout << " -> (" << end->row << "," << end->col << ")";
}

int main(){
    cout << "Enter n (rows): ";
    cin >> n;
    cout << "Enter m (columns): ";
    cin >> m;

    allocate_and_fill_maze();
    print_maze();
    build_graph();

    vertex* start = lookup[cell_id(0,0)];
    vertex* end = lookup[cell_id(n-1,m-1)];

    bool found = find_path_bfs(start, end);

    if(found){
        cout << "\nPath from (0,0) to (" << n-1 << "," << m-1 << "):\n";
        print_path(end);
        cout << endl;
    } else {
        cout << "\nNo path exists from (0,0) to (" << n-1 << "," << m-1 << ")\n";
    }

    return 0;
}