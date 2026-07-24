#include <iostream>
#include <cstdlib>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}



int main(){
    int x[]={45,21,56,7,6};
    int n = size(x);

    bubble_sort(x,n);

    for(int i=0;i<n;i++){
        cout<<x[i]<<endl;
    }
}