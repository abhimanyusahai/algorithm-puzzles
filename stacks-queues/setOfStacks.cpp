// Implementation of set of stacks

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


class SetOfStacks
{
    std::vector<Stack*> m_stackPointers;
    int m_threshold;

public:
    SetOfStacks(int threshold): m_threshold(threshold)
    {
        Stack *myStack = new Stack();
        m_stackPointers.push_back(myStack);
    }

    void push(int data)
    {
        Stack *current = m_stackPointers.back();
        if (current->m_top == (m_threshold - 1))
        {
            Stack *myStack = new Stack();
            m_stackPointers.push_back(myStack);
            myStack->push(data);
        }
        else
        {
            current->push(data);
        }
    }

    int pop()
    {
        Stack *current = m_stackPointers.back();
        int data = current->pop();
        if (current->isEmpty())
            m_stackPointers.pop_back();
        return data;
    }
};


int main()
{
    SetOfStacks mySet(5);
    mySet.push(67);
    mySet.push(43);
    mySet.push(23);
    mySet.push(98);
    mySet.push(10);
    mySet.push(11);
    mySet.push(17);
    mySet.pop();
    mySet.pop();
    mySet.pop();

    return 0;
}
