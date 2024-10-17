#pragma once
//name "list.h"

template <class T>

class List
{

  
class Node 
{
public:
    T data;
    Node* prev;
    Node* next;
    
    
    bool isHiddenNode = false;
};

    Node* head = nullptr;
    Node* tail = nullptr;
    
private:
    
    void setupList() 
    {
        Node* newNode = new Node();
        newNode->next = tail;
        newNode->prev = head;
        head->next = newNode;
        tail->prev = newNode;
    };
    
    void deleteListContents() 
    {
        Node* current = head->next;
        Node* temp = nullptr;
        while (current != tail->prev) 
        {
            temp = current->next;
            delete current;
            current = temp;
        }
    };

public:
    List()
    {
        head = new Node();
        head->isHiddenNode = true;
        tail = new Node();
        tail->isHiddenNode = true;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    };
    
    List(T newData)
    {
        setupList();
        (head->next)->data = newData;
    };
    
    List(List& rhs)
    { 
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    };
    
    ~List()
    {
       deleteListContents(); 
       delete head;
       delete tail;
    };
    
    bool  empty()
    {
        return (head->next == tail);
    };
    
    void push_front(T data)
    {
        if (this->empty())
        {
            setupList();
            Node * actualHead = head->next;
            actualHead->data = data;
        }
        else
        {
            Node *actualHead = head->next;
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = actualHead;
            actualHead->prev = newNode;
            newNode->prev = head;
            head->next = newNode;
        }
    };
    
    void push_back(T data)
    {
        if (this->empty())
        {
            setupList();
            Node *actualTail = tail->prev;
            actualTail->data = data;
        }
        else
        {
            Node *actualTail = tail->prev;
            Node *newNode = new Node();
            newNode->data = data;
            newNode->prev = actualTail;
            actualTail->next = newNode;
            newNode->next = tail;
            tail->prev = newNode;
        }
    };
    
    T front()
    {
        Node *actualHead = head->next;
        return (actualHead->data);
    };
    
    T back()
    {
        Node *actualTail = tail->prev;
        return (actualTail->data);
    };
    
    void pop_back()
    {
        if (!empty())
        {
        Node *lastNode = tail->prev;
        tail->prev = lastNode->prev;
        Node *newLastNode = tail->prev;
        newLastNode->next = tail;
        delete lastNode;
        lastNode = nullptr;
        }
        
        else 
        {
            std::cerr << "It's already empty (pop_back error)" << std::endl;
        }
    };
    
    void pop_front()
    {
        if (!empty())
        {
        Node *firstNode = head->next;
        head->next = firstNode->next;
        Node *newFirstNode = head->next;
        newFirstNode->prev = head;
        delete firstNode;
        firstNode = nullptr;
        }
        
        else
        {
            std::cerr << "It's already empty (pop_front error)" << std::endl;
        }
    };
    
    /*Exam 1 question 1
    void find(int val) 
    {
        Node* current = head;
        
        while (current != nullptr) 
        {
            if (current->data == val) 
            {
                if (current == head) 
                {
                    return;
                } 
                else if (current == tail)
                {
                    current->prev->next = nullptr;
                    tail = current->prev;
                } 
                else 
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                
                current->prev = nullptr;
                current->next = head;
                head->prev = current;
                push_front(val);
                return;
            } 
            else 
            {
                current = current->next;
            }
        }
        std::cout << "Item not found in the list" << std::endl;
    }
    */
    
    void printTheList() 
    {
        Node* current = head;
        current = current->next;
        while (current != tail) 
        {
            std::cout << current->data <<std::endl;
            current = current->next;
        }
    
    };
};