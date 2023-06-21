#pragma once
#include <iostream>
using namespace std;


template <typename T>
struct Node {
    T data;
    Node<T>* next=nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
class List {
    Node<T>*head=nullptr;
    Node<T>* tale = nullptr;
    int counter = 0;
public:
    List(){}
    ~List() {
        if (counter > 0) {
            Node<T>* next = head->next;
            while (next != nullptr) {
                delete[] head;
                head = next;
                next = head->next;
            }
            delete[]head;
        }
    }

    void push(T data) {
        Node<T>* newNode= new Node<T>{data};
        if (head == nullptr) {
            head = newNode;
            tale = newNode;
        }
        else {
            Node<T>* iter = head;
            while (iter->next != nullptr) {
                iter = iter->next;
            }
            iter->next = newNode;
            newNode->prev=iter;
            tale = newNode;
            newNode->prev = tale;
            tale->next = newNode;
            tale = newNode;

        }
        counter++;
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>{ data };
        if (head == nullptr) {
            head = newNode;
            tale = newNode;
        }
        else {
            newNode->prev = tale;
            tale->next = newNode;
            tale = newNode;

        }
        counter++;
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>{ data };
        if (head == nullptr) {
            head = newNode;
            tale = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        counter++;
    }
    void insert(T data,int index) {
        if (index < counter) {
        int y = counter/2;
        if (index > y) {
            Node<T>* newNode=new Node<T>{ data };
            Node<T>* iter = tale;
            while (counter-index++  > 1) {
                iter = iter->prev;
            }
            Node<T>* buf = iter->prev;
            iter->prev = newNode;
            buf->next= newNode;
            newNode->next = iter;
            newNode->prev = buf;

        }
        else {
            Node<T>* newNode = new Node<T>{ data };
            Node<T>* iter = head;
            while (index-- - 1 > 0) {
                iter = iter->next;
            }
            Node<T>* buf = iter->next;
            iter->next = newNode;
            buf->prev = newNode;
            newNode->prev = iter;
            newNode->next = buf;
            
            counter++;
        }
        }
    }
    void deleteHead(int index) {
        if (counter != 0) {
            Node<T>* buf = head;
            head = buf->next;
            delete[]buf;
        }
    }

    void deleteIndex(int index) {
            if (index > counter / 2) {
                Node<T>* iter = tale;
                while (index-- > 1) {
                    iter = iter->prev;
                }
                iter = iter->prev;
                Node<T>* buf = iter->next;
                iter->next->next->prev = iter;
                iter->next = iter->next->next;
                delete[]buf;
            }
            else {
                Node<T>* iter = head;
                while (index-- - 1 > 0) {
                    iter = iter->next;
                }
                iter = iter->prev;
                Node<T>* buf = iter->next;
                iter->next->next->prev = iter;
                iter->next = iter->next->next;
                delete[]buf;
            }
            counter--;
        }

    void show() {
        if (head != nullptr) {
            Node<T>* iter = head;
            while (iter->next != nullptr) {
                cout << iter->data << " ";
                iter = iter->next;
            }
            cout << iter->data << " ";
        }
    }
    void pop_front() {
        if (counter > 1) {
            Node<T>* iter = tale;
            tale->prev->next = nullptr;
            tale = tale->prev;
            delete[]iter;
            counter--;
        }
        else if (counter == 1) {
            delete[] head;
            head = nullptr;
            tale = nullptr;
            counter--;
        }
    }
    void pop_back() {
        if (counter >1) {
            Node<T>* iter = tale;
            tale->prev->next = nullptr;
            tale = tale->prev;
            delete[]iter;
            counter--;
        }
        else if (counter == 1) {
            delete[] head;
            head = nullptr;
            tale = nullptr;
            counter--;



        }
    }

};

