#include <iostream>
using namespace std;
int main(){
    const int size=5;
    int arr[size]={2,4,1,6,4};
    for(int i=0;i<size-1;i++){
        int flag=0;
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(!flag)
            break;
    }
    for(int i:arr){
        cout<<i<<" ";
    }
}