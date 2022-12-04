//
// Created by Chris
//

#ifndef CONCURRENT_QUEUE_QUEUE_H
#define CONCURRENT_QUEUE_QUEUE_H

#include <iostream>

template<class T>
struct node {
    T value;
    node *next;

    explicit node(T value) : value(value), next(nullptr) {};
};


template<class T>
class queue {
private:
    node<T> *head;
    node<T> *tail;
    unsigned int size_queue;
public:
    queue() {    // Constructor
        head = nullptr;
        tail = nullptr;
        size_queue = 0;
    }

    ~queue();   // Destructor

    void push(T val);    // Push Back
    void pop();         // Front Remove
    T front();             // return Front
    T back();             // return Back
    bool empty();

    unsigned int size();

    void print();           // queue print
};

template<class T>
bool queue<T>::empty() {
    return (!size()) ? true : false;    // return true if queue is empty, false otherwise
}

template<class T>
unsigned int queue<T>::size() {
    return size_queue;
}

template<class T>
T queue<T>::back() {
    return tail->value;
}

template<class T>
queue<T>::~queue() {
    while (head) {
        node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<class T>
void queue<T>::push(T val) {
    if (head == nullptr) {
        head = new node<T>(val);
        tail = head;
        size_queue++;
    } else {
        tail->next = new node<T>(val);
        tail = tail->next;
        size_queue++;
    }
}

template<class T>
void queue<T>::pop() {
    if (head) {
        node<T> *tmp = head;
        head = head->next;
        delete tmp;
        size_queue--;
    }
}

template<class T>
T queue<T>::front() {
    return head->value;
}

template<class T>
void queue<T>::print() {
    std::cout << "head -> ";
    for (node<T> *i = head; i; i = i->next) {
        std::cout << i->value << " | ";
    }
    std::cout << " <- tail";
    std::cout << std::endl;
}

#endif //CONCURRENT_QUEUE_QUEUE_H
