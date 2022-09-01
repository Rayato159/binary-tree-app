#include <iostream>

#include "../queue/circular.h"

using namespace std;

int main() {
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    return 0;
}