// Check if linked list is a palindrome

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

UnorderedList* reverseAndClone(UnorderedList* inputList)
{
    UnorderedList *outputList = new UnorderedList();
    Node *current = inputList->getFirst();
    Node *head = nullptr;
    while (current != nullptr)
    {
        Node *temp = new Node(current->getData());
        temp->setNext(head);
        head = temp;
        current = current->getNext();
    }

    outputList->setFirst(head);
    return outputList;
}

bool isPalindrome(UnorderedList *list)
{
    UnorderedList *reverse = reverseAndClone(list);

    Node *one = list->getFirst();
    Node *two = reverse->getFirst();

    while (one != nullptr && two != nullptr)
    {
        if (one->getData() != two->getData())
            return false;
        one = one->getNext();
        two = two->getNext();
    }

    return true;
}

int main()
{
    UnorderedList list1;
    list1.appendToHead(1);
    list1.appendToHead(5);
    list1.appendToHead(6);
    list1.appendToHead(6);
    list1.appendToHead(5);
    list1.appendToHead(1);
    list1.printItems();
    std::cout << isPalindrome(&list1) << '\n';
    return 0;
}
