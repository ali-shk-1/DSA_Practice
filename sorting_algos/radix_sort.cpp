#include <iostream>
#include <vector>
using namespace std;

int maxDigCount(vector<int>& a){
    int count=0;
    for (int x : a){
        int lcount=0;
        while(x>0){
            x/=10;
            lcount++;
        }
        if(lcount>count)
            count=lcount;
    } 
    return count;
}

int main(){
    vector<int> a = {7, 12, 44, 9, 3, 8};
    int count=maxDigCount(a);
    int x;

    for(int j=0;j<a.size();j++){
        x=a[j];
        int lcount=0, num=x;
        while(num>0){
            num/=10;
            lcount++;
        }
        if(lcount<count){
            for(int i=0;i<(count-lcount);i++){
                
            }
        }
    }
    

    return 0;
}
void radixSort(vector<int>& a, int digPos){

}
