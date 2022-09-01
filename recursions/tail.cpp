#include <iostream>
using namespace std;

void func(int n) {
    if(n > 0) {
        cout << n << endl;
        func(n - 1);
    }
}

int main() {
    func(5);
    return 0;
}