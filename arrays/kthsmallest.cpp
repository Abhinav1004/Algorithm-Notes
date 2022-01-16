// program to implement heaps and kth smallest number
#include<bits/stdc++.h>
using namespace std;
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(int ar[],int* heap_size,int i){
    int small = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<*heap_size && ar[left]<ar[small])
        small = left;
    if(right<*heap_size && ar[right]<ar[small])
        small = right;
    if(small!=i){
        swap(&ar[small],&ar[i]);
        minHeapify(ar,heap_size,small);
    }
}
void buildHeap(int ar[],int* heap_size){
    for(int i=(*heap_size-1)/2;i>=0;i--){
        minHeapify(ar,heap_size,i);
    }
}
int extractMin(int ar[],int* heap_size){
    int val;
    if(*heap_size<1)
    return INT_MAX;
    else{
        val = ar[0];
        ar[0] = ar[*heap_size];
        minHeapify(ar,heap_size,0);
    }
    *heap_size = *heap_size-1;
    return val;
}
int getKthSmallest(int ar[],int n,int k){
    int heap_size = n-1;
    buildHeap(ar,&heap_size);
    // for(int i=0;i<n;i++)
    // cout<<ar[i]<<" ";
    // cout<<"\n";
    for(int i=0;i<k-1;i++){
        int val = extractMin(ar,&heap_size);
        // cout<<val<<"\n"; 
    }
    return ar[0];
}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int size;
        cin>>size;
        int k;
        cin>>k;
        int* ar = new int[size];
        for(int j=0;j<size;j++)
        cin>>ar[j];
        int value = getKthSmallest(ar,size,k);
        cout<<value<<"\n";
    }
}