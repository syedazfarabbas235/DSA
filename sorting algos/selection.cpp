#include <iostream>
#include <cstdlib>
using namespace std;

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

int main(){
    int x[]={45,21,56,7};
    int n = sizeof(x)/sizeof(x[0]);

    selection(x,n);

    for(int i=0;i<n;i++){
        cout<<x[i]<<endl;
    }
}