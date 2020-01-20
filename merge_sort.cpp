/*
    mirza_inayat
    09.01.20
*/
#include <bits/stdc++.h>
    using namespace std;
#define F(i,k,n)    for(int i=k;i<n;i++)
#define N 5
//In merge sort we select the middle position and then apply D&C and also combining them 
void merge(int a[N],int low,int m,int high){
   int a1[N],a2[N];
   int k=0;
   F(i,low,m+1){
       a1[k] = a[i];
       k++;
   } 
   k=0;
   F(i,m+1,high+1){
       a2[k] = a[i];
       k++;
   } 
   k=low;
   int i=0,j=0;
   while(i < m+1-low && j < high-m){
       if(a1[i]<a2[j]){
           a[k]=a1[i];
           i++;
       }
       else{
           a[k]=a2[j];
           j++;
       }
       k++;
   }
    while(i < m+1-low){
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j < high-m){
        a[k]=a2[j];
        j++;
        k++;
    }
}
void merge_sort(int a[N],int low,int high){
    if(low == high)
        return;
    int m = (low + high)/2;
    merge_sort(a,low,m);
    merge_sort(a,m+1,high);
    merge(a,low,m,high);
}
void print(int a[N]){
    F(i,0,N)
        cout << a[i] << " ";
    cout << endl;
}
int main(){
    int a[N]={2,5,3,1,4};
    clock_t start,end;
    start = clock();
    merge_sort(a,0,N-1);
    end = clock();
    print(a);
    double time = (double)(end - start)/CLOCKS_PER_SEC;
    cout << time << " seconds" << endl;
}