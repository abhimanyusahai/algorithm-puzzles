// Queue implementation using linked list

#include <iostream>

class Queue
{
    class QueueNode
    {
        int m_data;
        QueueNode *m_next;

    public:
        QueueNode(int data) : m_data(data)
        {
            m_next = nullptr;
        }
        void setData(int data) { m_data = data; }
        int getData() { return m_data; }
        void setNext(QueueNode *next) {m_next = next; }
        QueueNode* getNext() { return m_next; }
    };

    QueueNode *m_head;
    QueueNode *m_tail;

public:
    Queue() : m_head(nullptr), m_tail(nullptr)
    {
    }

    bool isEmpty() { return m_head == nullptr; }

    void enqueue(int data) // Enqueue at the tail
    {
        QueueNode *temp = new QueueNode(data);
        if (m_tail != nullptr)
            m_tail->setNext(temp);
        m_tail = temp;
        if (m_head == nullptr)
            m_head = m_tail;
    }

    int peek() { return m_head->getData(); }

    int dequeue() // Dequeue at the head
    {
        int data = m_head->getData();
        m_head = m_head->getNext();
        if (m_head == nullptr)
            m_tail = nullptr;
        return data;
    }
};


int main()
{
    Queue myQueue;
    std::cout << myQueue.isEmpty() << '\n';
    myQueue.enqueue(5);
    std::cout << myQueue.isEmpty() << '\n';
    std::cout << myQueue.peek() << '\n';
    myQueue.enqueue(7);
    std::cout << myQueue.peek() << '\n';
    std::cout << myQueue.dequeue() << '\n';
    std::cout << myQueue.peek() << '\n';
    std::cout << myQueue.dequeue() << '\n';
    std::cout << myQueue.isEmpty() << '\n';

    return 0;
}
