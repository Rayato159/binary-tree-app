#include <iostream>
using namespace std;

int a[1001];

int fibbonacci(int n) {
    if (n <= 1) {
        a[n] = n;
        return n;
    } else {
        if(a[n - 2] == -1) {
            a[n - 2] = fibbonacci(n - 2);
        }
        if(a[n - 1] == -1) {
            a[n - 1] = fibbonacci(n - 1);
        }
        return a[n - 2] + a[n - 1]; 
    }
}

int main() {
    for(int i=0; i<1001; i++) {
        a[i] = -1;
    }
    cout << fibbonacci(10) << endl;
    return 0;
}