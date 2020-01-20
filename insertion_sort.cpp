/*
    mirza_inayat
    11.01.20
*/
#include <bits/stdc++.h>
    using namespace std;
#define F(i,k,n)    for(int i=k;i<n;i++)
#define N 15
void insertion_sort(int a[N]){
    F(i,1,N){
        int k = a[i];
        int j=i-1;
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];            
            j--;
        }
        a[j+1] = k;
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
    start = clock();
    insertion_sort(a);
    end = clock();
    print(a);
    double time = (double)(end - start)/CLOCKS_PER_SEC;
    cout << time << " seconds" << endl;
}