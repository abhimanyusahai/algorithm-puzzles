// Partition a list around a given element

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

void partition(UnorderedList& list, int threshold)
{
    Node *previous = list.getFirst();
    Node *current = list.getFirst()->getNext();

    while (current != nullptr)
    {
        int element = current->getData();
        if (element < threshold)
        {
            previous->setNext(current->getNext());
            list.appendToHead(element);
        }
        else
            previous = current;
        current = current->getNext();
    }
}

int main()
{
    UnorderedList list1;
    list1.appendToHead(1);
    list1.appendToHead(2);
    list1.appendToHead(10);
    list1.appendToHead(5);
    list1.appendToHead(8);
    list1.appendToHead(5);
    list1.appendToHead(3);
    list1.printItems();
    partition(list1, 5);
    list1.printItems();

    return 0;
}
