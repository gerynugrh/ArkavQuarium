#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>

using namespace std;

template <class T>
struct node {
    T * value;
    node * next;
};

template <class T>
class LinkedList {
private:
    node<T> * head, * tail;
public:
    // Constructor and destructor
    LinkedList();
    ~LinkedList();

    // Method
    T& get(int);
    void remove(const T&);
    void add(const T&);
    bool isEmpty();
    int find(const T&);
    T& operator[](const int&);
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    node<T> * curr = head;
    node<T> * next;

    while (curr != NULL) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    delete tail;
}

template <class T>
T & LinkedList<T>::get(int index) {
    node<T> * curr = head;
    int pos = 0;
    while (curr != NULL) {
        if (pos == index) return *(curr->value);
        curr = curr->next;
    }
    throw out_of_range();
}

template <class T>
void LinkedList<T>::remove(const T & value) {
    node<T> * curr = head;
    if (*(curr->value) == value) {
        delete head;
        head = NULL;
        tail = NULL;
    }
    while (curr->next != NULL && curr->next->value != value)
        curr = curr->next;
    if (curr->next == NULL) throw out_of_range();
    curr->next = curr->next->next;
}

template <class T>
void LinkedList<T>::add(const T & value) {
    node<T> * temp = new node<T>;
    *(temp->value) = value;
    temp->next = NULL;
    if (head != NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return head == NULL && tail == NULL;
}

template <class T>
int LinkedList<T>::find(const T & value) {
    node<T> * curr = head;
    int pos = 0;
    while (curr != NULL) {
        if (*(curr->value) == value) 
            return pos;
        curr = curr->next;
        pos++;
    }
}

template <class T>
T& LinkedList<T>::operator[](const int&) {

}

#endif
