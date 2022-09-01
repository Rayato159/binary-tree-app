#include <iostream>
using namespace std;

void tree(int n) {
    if(n > 0) {
        cout << n << " " << flush;
        tree(n - 1);
        tree(n - 1);
    }
}

int main() {
    tree(5);
    return 0;
}