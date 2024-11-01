#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:

    struct Node 
    {
        T data;        
        Node* next;    
        Node* prev;    

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;  
    Node* tail;  

public:
    
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue()
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    void enqueue(const T& value)
    {
        Node* newNode = new Node(value);

        if (isEmpty()) 
        {
            head = tail = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head) 
        {
            head->prev = nullptr;
        }

        else 
        {
            tail = nullptr;
        }

        delete temp;
    }

    T front() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty.\n";
            return T(); 
        }

        return head->data;
    }

    T back() const 
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return T(); 
        }

        return tail->data;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }
};

int main()
{
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.front() << "\n";  
    cout << "Back element: " << queue.back() << "\n";    

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << "\n";  

    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); 

    return 0;
}