#include <iostream>
using namespace std;
int main(){
    const int n=5;
    int j;
    int a[n]={2,4,1,6,4};
    for(int i=1;i<n;i++){
        int temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
    for(int i:a){
        cout<<i<<" ";
    }
}