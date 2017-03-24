// Sum lists

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

    UnorderedList(Node *head)
    {
        m_head = head;
    }

    bool isEmpty() { return m_head == nullptr; }

    Node* getFirst() { return m_head; }

    void appendToHead(int data)
    {
        Node *temp = new Node(data);
        if (m_head != nullptr)
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

    bool search(int data);
};

UnorderedList* sumLists(UnorderedList *list1, UnorderedList *list2)
{
    UnorderedList *sum;
    Node *sumTail;
    Node *current1 = list1->getFirst();
    Node *current2 = list2->getFirst();
    bool first = true;
    int carry = 0;
    int digit1, digit2, result;

    while (!(current1 == nullptr && current2 == nullptr))
    {
        digit1 = (current1 == nullptr) ? 0 : current1->getData();
        digit2 = (current2 == nullptr) ? 0 : current2->getData();
        result = digit1 + digit2 + carry;
        carry = (result > 9) ? 1 : 0;
        result %= 10;
        Node *resultNode = new Node(result);

        if (first)
        {
            sum = new UnorderedList(resultNode);
            sumTail = resultNode;
            first = false;
        }
        else
        {
            sumTail->setNext(resultNode);
            sumTail = resultNode;
        }

        current1 = (current1 == nullptr) ? nullptr : current1->getNext();
        current2 = (current2 == nullptr) ? nullptr : current2->getNext();
    }

    if (carry == 1)
    {
        Node *resultNode = new Node(1);
        sumTail->setNext(resultNode);
        sumTail = resultNode;
    }

    return sum;
}

int main()
{
    UnorderedList *num1 = new UnorderedList();
    num1->appendToHead(6);
    num1->appendToHead(1);
    num1->appendToHead(7);
    UnorderedList *num2 = new UnorderedList();
    num2->appendToHead(2);
    num2->appendToHead(9);
    num2->appendToHead(5);
    num1->printItems();
    num2->printItems();
    UnorderedList *sum = sumLists(num1, num2);
    sum->printItems();

    return 0;
}
