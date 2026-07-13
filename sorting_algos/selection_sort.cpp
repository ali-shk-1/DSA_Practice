#include <iostream>
using namespace std;
int main(){
    const int n=5;
    int i;
    int a[n]={2,4,1,6,4};
    for(i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min])
                min=j;
        }
    
        if(min!=i)
            swap(a[i],a[min]);
     }
    for(int i:a){
        cout<<i<<" ";
    }
}