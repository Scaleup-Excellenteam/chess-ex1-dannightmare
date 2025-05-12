#include <list>
template <class T>
class PriorityQueue
{
private:
    std::list<T> priority_queue;

public:
    const T &poll() const;
    void push(const T &item);
};
