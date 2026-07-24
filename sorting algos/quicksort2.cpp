#include <iostream>
#include <cstdlib>
using namespace std;

int set_pivot(int arr[],int L,int R){
    int p_index=0;
    
while(L<R){
        while(L<=p_index){
            if (arr[p_index]>arr[L]){
                swap(arr[p_index],arr[L]);
                p_index=L;
            }
            else{
                L++;
            }
        }


        
    
    }
    return p_index;
}

void quicksort(int arr[],int L,int R){
    if (L<R){
        int p_index=set_pivot(arr,L,R);
        quicksort(arr,L,p_index-1);
        quicksort(arr,p_index+1,R);
    }
       

}



int main(){
    int x[]={10,21,34,55,22,43,89,75,77,57,12,34,5};
    int n=size(x);
    int L=0;
    int R=n-1;
    quicksort(x,L,R);
     for(int i=L;i<R;i++){
            cout<<x[i]<<endl;
        }

}