#include "PriorityQueue.h"

template <class T>
const T &PriorityQueue<T>::poll() const
{
    return priority_queue.front();
}
