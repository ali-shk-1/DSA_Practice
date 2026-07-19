#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector<int>& a, int lb, int ub);
int main() {
    vector<int> a = {7, 12, 4, 9, 3, 8};
    int lb = 0;
    int ub = a.size() - 1;

    quickSort(a,lb,ub);

    for (int x : a) 
        cout << x << " ";
    cout << endl;

    return 0;
}
void quickSort(vector<int>& a, int lb, int ub) {
    
    if (lb >= ub) return;   
    
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (start < ub && a[start] <= pivot) {
            start++;
        }
        while (end > lb && a[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(a[start], a[end]);
        }
    }

    swap(a[lb], a[end]);

    quickSort(a, lb, end - 1);
    quickSort(a, end + 1, ub);
} 