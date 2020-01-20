/*
    mirza_inayat
    11.01.20
*/
#include <bits/stdc++.h>
    using namespace std;
#define F(i,k,n)    for(int i=k;i<n;i++)
#define N 15
void max_heapify(int a[N],int i,int n){
    int l,r;
    l = 2*i + 1;
    r = l+1;
    int largest = i;
    if(l < n)
    if(a[l] > a[largest])
        largest = l;
    if(r < n)
    if(a[r] > a[largest])
        largest = r;
    if(largest != i){
        swap(a[i],a[largest]);
        max_heapify(a,largest,n);
    }
}
void build_max_heap(int a[N]){
    for(int i=N/2;i>=0;i--)
        max_heapify(a,i,N);
}
void heap_sort(int a[N]){
    build_max_heap(a);
    for(int i=N-1;i>0;i--){
        swap(a[i],a[0]);
        max_heapify(a,0,i);
    }
}
void print(int a[N]){
    F(i,0,N)
        cout << a[i] <<" ";
    cout << endl;
}
int main(){
    int a[N]={2,5,3,1,4,15,48,95,47,25,-5,-8,-9,-7,-45};
    clock_t start,end;
    double time;
    start = clock();
    heap_sort(a);
    end = clock();
    time = (double)(end - start)/CLOCKS_PER_SEC;
    print(a);
    cout << time << " seconds" << endl;
}