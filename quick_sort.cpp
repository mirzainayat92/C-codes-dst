/*
    mirza_inayat
    09.01.20
*/
#include <bits/stdc++.h>
    using namespace std;
#define F(i,k,n)    for(int i=k;i<n;i++)
#define N 15
//In quick sort we select one particular position(lets take first position) and then apply D&C to them
int partition(int a[N],int low,int high){
    int pivot = a[low];  //We have chosen first value as pivot
    int c = low;
    F(i,low+1,high)
        if(a[i] < pivot){
            c++;
            swap(a[i],a[c]);
        }
    c++;
    swap(a[low],a[c]);    
    return c;
}
void quick_sort(int a[N],int low,int high){
    if(low >= high)
        return;
    int pivot = partition(a,low,high);    //Setting the pivot to its final position in sorted array
    quick_sort(a,low,pivot-1);
    quick_sort(a,pivot+1,high);
}
void print(int a[N]){
    F(i,0,N)
        cout << a[i] <<" ";
    cout << endl;
}
int main(){
    int a[N]={2,5,3,1,4,15,48,95,47,25,-5,-8,-9,-7,-45};
    clock_t start,end;
    start = clock();
    quick_sort(a,0,N-1);
    end = clock();
    print(a);
    double time = (double)(end - start)/CLOCKS_PER_SEC;
    cout << time << " seconds" << endl;

}