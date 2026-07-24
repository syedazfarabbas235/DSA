#include <iostream>
#include <cstdlib>
using namespace std;

int set_pivot(int arr[],int L,int R){
    int p_index=(L+R)/2;
    
while(L<R){
        while(R>=p_index){
            if (arr[p_index]>arr[R]){
                swap(arr[p_index],arr[R]);
                p_index=R;
                break;
            }
            else{
                R--;
            }
        }


        while(L<=p_index){
            if (arr[p_index]<arr[L]){
                swap(arr[p_index],arr[L]);
                p_index=L;
                break;
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
    int x[]={4,25,7,2,6};
    int n=size(x);
    int L=0;
    int R=n-1;
    quicksort(x,L,R);
     for(int i=L;i<=R;i++){
            cout<<x[i]<<endl;
        }

}