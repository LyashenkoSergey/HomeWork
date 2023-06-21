#pragma once

template<typename T>
struct Node {
    T data;
    Node* next = nullptr;

};

template<typename T>
class List {
    Node <T>* head = nullptr;
    int counter = 0;
public:
    List() {};
    ~List() {
        Node <T>* next = head->next;
        while (next!=nullptr) {
        delete[] head;
        head = next;
        next = head->next;
        }
        delete[] head;
    }
    void push(T data) {
        Node<T>* newNode=new Node<T>{ data };
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* iter = head;
            while (iter->next != nullptr) {
                iter = iter->next;
            }
            iter->next = newNode;
        }
        counter++;
    }
    void insert(T data, int num) {
        if (num<counter){
            Node<T>* newNode=new Node<T>{ data };
            Node<T>* iter = head;
            while (counter-num++ > 1) {
                iter = iter->next;
            }
            Node<T>* buf = iter->next;
            iter->next = newNode;
            newNode=buf;
            counter++;
        }
        }
    
    void deleteHead() {
            if (counter != 0) {
                Node<T>* buf = head;
                head = buf->next;
                delete[]buf;
            }
        }
    
    void show() {
        if (head != nullptr) {
            Node<T>* iter = head;
            while (iter->next != nullptr) {
                std::cout << iter->data << " ";
                iter = iter->next;
            }
            std::cout << iter->data;
        }
    }
};
