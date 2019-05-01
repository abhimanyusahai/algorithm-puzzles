// Stack implementation using std::vector

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

int main()
{
    Stack myStack;
    std::cout << myStack.isEmpty() << '\n';
    myStack.push(5);
    std::cout << myStack.isEmpty() << '\n';
    std::cout << myStack.peek() << '\n';
    myStack.push(7);
    std::cout << myStack.peek() << '\n';
    std::cout << myStack.pop() << '\n';

    return 0;
}
