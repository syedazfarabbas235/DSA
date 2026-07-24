#include <iostream>
using namespace std;
void insert(int);
void search(int);


int main(){
    int choice,value;
    while(true){
        cout<<"\n1.Insert\n2.Search\n3.Exit";
        cin>>choice;

        if(choice==1){
            cin>>value;
            insert(value);
        }

        else if (choice==2){
            cin>>value;
            search(value);
        }
        else if (choice==3){
            cout<<"Time kio waste krwaiaaaaaaaa\n";
            break;
        }
        else{
            cout<<"Inavlid choice";
        }
    }

}