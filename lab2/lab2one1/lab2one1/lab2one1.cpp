#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};


class MyLinkedList
{
public:
    MyLinkedList() : head(nullptr), size(0)
    {
    }

    size_t get_size() { return size; }
    void addAtHead(int val);
    void add_at_tail(int val);
    void add_at_index(size_t index, int val);
    void delete_at_index(size_t index);
    void print();
    void reverse();
    void insertNode(size_t index, int val);

private:
    ListNode* head;
    size_t size;
};

void MyLinkedList::addAtHead(int val)
{
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    ++size;
}

void MyLinkedList::add_at_tail(int val)
{
    ListNode* newNode = new ListNode(val, nullptr);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode* it = head;
    while (it->next != nullptr)
        it = it->next;
    it->next = newNode;

    ++size;
}

void MyLinkedList::delete_at_index(size_t index)
{
    if (index >= size + 1)
    {
        cout << "Index is larger than the size=" << size << "\n";
        return;
    }

    ListNode* prev = head;

    if (index == 0)
    {
        head = head->next;
        delete prev;
    }

    ListNode* curr = head->next;
    size_t pos = 0;

    while (prev != nullptr && pos < index - 1)
    {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }
    prev->next = curr->next;
    delete curr;

    --size;
}

void MyLinkedList::add_at_index(size_t index, int val)
{
    ListNode* prev = head;
    ListNode* curr = head->next;
    size_t pos = 0;

    while (prev != nullptr && pos < index - 1)
    {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }
    ListNode* newNode = new ListNode(val, curr);
    prev->next = newNode;

    ++size;
}

void MyLinkedList::print()
{
    ListNode* current = head;

    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }

    cout << endl;
}

void MyLinkedList::reverse()
{
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void MyLinkedList::insertNode(size_t index, int val)
{
    if (index > size)
    {
        cout << "Index is larger than the size=" << size << "\n";
        return;
    }

    ListNode* newNode = new ListNode(val);

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ListNode* current = head;
        size_t pos = 0;
        while (pos < index - 1)
        {
            current = current->next;
            ++pos;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    ++size;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    MyLinkedList* obj = new MyLinkedList();
    for (int val : arr)
    {
        obj->add_at_tail(val);
    }
    cout << "Deleting the last element...\n";
    obj->delete_at_index(4);

    cout << "Add at index 3\n";
    obj->add_at_index((size_t)2, 10);
    obj->addAtHead(12);
    cout << "List after deletion: ";
    obj->print();
    cout << "List after reverse: ";
    obj->reverse();
    obj->print();
    return 0;
}
