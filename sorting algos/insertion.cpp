#include <iostream>
#include <cstdlib>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int cur=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>cur){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=cur;
    }
}

int main(){
    int x[]={45,21,56,7};
    int n = sizeof(x)/sizeof(x[0]);

    insertion_sort(x,n);

    for(int i=0;i<n;i++){
        cout<<x[i]<<endl;
    }
}