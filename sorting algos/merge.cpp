#include <iostream>
#include <cstdlib>
using namespace std;

void merge(int arr[],int L,int mid,int R){
   int temp_array[R-L+1];
   int temp_index=0;
   int left_pointer=L;
   int right_pointer=mid+1;

   while(left_pointer<=mid && right_pointer<=R){
    if(arr[left_pointer]<= arr[right_pointer]){
        temp_array[temp_index]=arr[left_pointer];
        left_pointer++;
    }
    else{
        temp_array[temp_index]=arr[right_pointer];
        right_pointer++;
    }
    temp_index++;
   }

   while(left_pointer<=mid){
    temp_array[temp_index]=arr[left_pointer];
    left_pointer++;
    temp_index++;
   }

   while(right_pointer<=R){
    temp_array[temp_index]=arr[right_pointer];
    right_pointer++;
    temp_index++;
   }
   for(int i=0;i<temp_index;i++){
    arr[L+i]=temp_array[i];
   }

}


void merge_sort(int arr[],int L,int R){
    if(L<R){   
        int mid =(L+R)/2;
        merge_sort(arr,L,mid);
        merge_sort(arr,mid+1,R);
        merge(arr,L,mid,R);
    }

}


int main (){
    int x[]={4,25,7,2,6};
    int n=size(x);
    int L=0;
    int R=n-1;
    merge_sort(x,L,R);

    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
}