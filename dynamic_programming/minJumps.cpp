//program to find minimum jumps required to reach end of array
#include<bits/stdc++.h>
using namespace std;
//Recursive Solution
int minJumpsRecursive(int ar[],int n1){
    int res = INT_MAX;
    if(n1==1)
    return 0;
    else{
        for(int i=n1-2;i>=0;i--){
            if(i+ar[i]>=n1-1){
                int sub_res = minJumpsRecursive(ar,i+1);
                if(sub_res!=INT_MAX){
                    res = min(res,sub_res+1);
                }
            }
        }
    }
    return res;
}
//Dynamic Programming Solution
int minJumps(int ar[],int n1){
    int jumps[n1];
    jumps[0] = 0;
    for(int i=1;i<n1;i++){
        jumps[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(j+ar[j]>=i && jumps[j]!=INT_MAX){
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }
    return jumps[n1-1];
}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int n1;
        cin>>n1;
        int* ar = new int[n1];
        for(int j=0;j<n1;j++)
            cin>>ar[j];
        // cout<<minJumps(ar,n1)<<"\n";
        cout<<minJumpsRecursive(ar,n1)<<"\n";
    }
    return 0;
}