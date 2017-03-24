// Implement queue using two stacks

#include <iostream>

class Stack
{
public:
    std::vector<int> m_data;
    int m_top;

    Stack()
    {
        m_top = -1;
    }

    void push(int data)
    {
        m_data.push_back(data);
        ++m_top;
    }

    int pop()
    {
        int data = m_data.back();
        m_data.pop_back();
        --m_top;
        return data;
    }

    int peek() { return m_data.at(m_top); }

    bool isEmpty() { return m_top == -1; }
};


class MyQueue
{
    Stack m_stackNewest;
    Stack m_stackOldest;

    void shiftStacks()
    {
        if (m_stackOldest.isEmpty())
        {
            while (!m_stackNewest.isEmpty())
                m_stackOldest.push(m_stackNewest.pop());
        }
    }

public:
    void enqueue(int data)
    {
        m_stackNewest.push(data);
    }

    int dequeue()
    {
        shiftStacks();
        return m_stackOldest.pop();
    }

    int peek()
    {
        shiftStacks();
        return m_stackOldest.peek();
    }

    bool isEmpty()
    {
        return (m_stackNewest.isEmpty() && m_stackOldest.isEmpty());
    }
};

int main()
{
    MyQueue queue;
    std::cout << queue.isEmpty() << '\n';
    queue.enqueue(5);
    queue.enqueue(6);
    std::cout << queue.peek() << '\n';
    std::cout << queue.dequeue() << '\n';
    std::cout << queue.dequeue() << '\n';

    return 0;
}
