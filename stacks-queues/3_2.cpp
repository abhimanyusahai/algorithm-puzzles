// Stack allowing pop, push and access to minimum element all in O(1) time

#include <iostream>
#include <vector>

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

class StackWithMin : public Stack
{
    Stack m_minStack;

public:
    void push(int data)
    {
        m_data.push_back(data);
        ++m_top;
        if (m_top == 0)
            m_minStack.push(data);
        if (data < m_minStack.peek())
            m_minStack.push(data);
    }

    int pop()
    {
        int data = m_data.back();
        m_data.pop_back();
        --m_top;
        if (data == m_minStack.peek())
        {
            m_minStack.pop();
        }
        return data;
    }

    int min() { return m_minStack.peek(); }
};

int main()
{
    StackWithMin myStack;
    std::cout << myStack.isEmpty() << '\n';
    myStack.push(5);
    std::cout << myStack.isEmpty() << '\n';
    std::cout << myStack.peek() << '\n';
    myStack.push(7);
    std::cout << myStack.peek() << '\n';
    std::cout << myStack.pop() << '\n';
    std::cout << myStack.min() << '\n';
    myStack.push(3);
    std::cout << myStack.min() << '\n';
    myStack.push(6);
    std::cout << myStack.min() << '\n';
    myStack.push(10);
    std::cout << myStack.min() << '\n';
    myStack.push(1);
    std::cout << myStack.min() << '\n';

    return 0;
}
