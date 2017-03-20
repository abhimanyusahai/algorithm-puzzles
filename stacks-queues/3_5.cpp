// Sort a stack, using only one other temporary buffer stack. Smallest elements appear at the bottom

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

void sort(Stack& stack)
{
    Stack bufferStack;

    while (!stack.isEmpty())
    {
        int temp = stack.pop();
        while (!bufferStack.isEmpty() && (bufferStack.peek() > temp))
        {
            stack.push(bufferStack.pop());
        }
        bufferStack.push(temp);
    }

    while (!bufferStack.isEmpty())
    {
        stack.push(bufferStack.pop());
    }
}


int main()
{
    Stack myStack;
    myStack.push(7);
    myStack.push(10);
    myStack.push(12);
    myStack.push(8);
    sort(myStack);
    std::cout << myStack.pop() << '\n';
    std::cout << myStack.pop() << '\n';
    std::cout << myStack.pop() << '\n';
    std::cout << myStack.pop() << '\n';

    return 0;
}
