// Unordered linked list implementation

#include <iostream>

class Node {
    int m_data;
    Node *m_next;

public:
    Node(int data)
    {
        m_data = data;
        m_next = nullptr;
    }

    int getData() { return m_data; }
    void setData(int data) { m_data = data; }
    Node* getNext() { return m_next; }
    void setNext(Node *next) { m_next = next; }
};

class UnorderedList {
    Node *m_head;

public:
    UnorderedList()
    {
        m_head = nullptr;
    }

    bool isEmpty() { return m_head == nullptr; }

    Node* getFirst() { return m_head; }

    void setFirst(Node *head) { m_head = head; }

    void appendToHead(int data)
    {
        Node *temp = new Node(data);
        temp->setNext(m_head);
        m_head = temp;
    }

    void remove(int data)
    {
        Node *current = m_head;
        Node *previous = nullptr;
        bool found = false;

        while (!found)
        {
            if (current->getData() == data)
                found = true;
            else
            {
                previous = current;
                current = current->getNext();
            }
        }

        if (previous == nullptr)
            m_head = current->getNext();
        else
            previous->setNext(current->getNext());
    }

    void printItems()
    {
        Node *current = m_head;

        while (current != nullptr)
        {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }

        std::cout << '\n';
    }
};

int main()
{
    UnorderedList list1;
    list1.appendToHead(32);
    list1.appendToHead(47);
    list1.appendToHead(90);
    std::cout << list1.getFirst()->getData() << '\n';
    std::cout << list1.getFirst()->getNext()->getData() << '\n';
    std::cout << list1.getFirst()->getNext()->getNext()->getData() << '\n';
    list1.remove(47);
    std::cout << list1.getFirst()->getData() << '\n';
    std::cout << list1.getFirst()->getNext()->getData() << '\n';
    return 0;
}
