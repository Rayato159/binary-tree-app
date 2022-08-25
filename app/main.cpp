#include <iostream>
#include "../queue/circular_queue.h"
using namespace std;

int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(5);
    q.display();

    return 0;
}