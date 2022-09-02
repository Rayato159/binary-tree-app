#include <iostream>
using namespace std;

int main() {

    int **A;
    A = new int*[3];
    A[0] = new int[4];
    A[1] = new int[5];
    A[2] = new int[6];

    for(int j=0; j<4; j++) {
        A[0][j] = j+1;
    }
    for(int j=0; j<5; j++) {
        A[1][j] = j+1;
    }
    for(int j=0; j<6; j++) {
        A[2][j] = j+1;
    }

    for(int j=0; j<4; j++) {
        cout << A[0][j] << " " << flush;
    }
    cout << endl;

    for(int j=0; j<5; j++) {
        cout << A[1][j] << " " << flush;
    }
    cout << endl;

    for(int j=0; j<6; j++) {
        cout << A[2][j] << " " << flush;
    }
    cout << endl;

    return 0;
}