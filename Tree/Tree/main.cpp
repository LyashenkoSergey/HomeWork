#include <iostream>

using namespace std;

template<typename T>

struct Node {
    T data;
    Node <T>* left=nullptr;
    Node <T>* right=nullptr;
};

template<typename T>

class Tree {
    Node <T>* root = nullptr;
    int count = 0;

public:
    Tree(const T newData[], int size) {
        for (int i = 0; i < size; i++) {
            addNode(newData[i]);
        }
    };

    void addNode(T data) {
        if (root == nullptr) {
            root = new Node<T>{ data };
            count++;
        }
        else {
            Node <T>* buf = root;
            while (1) {
                if (buf->data == data) {
                    buf->data = data;
                    break;
                }
                if (data < buf->data) {
                    if (buf->left == nullptr) {
                        buf->left = new Node<T>{ data };
                        count++;
                        break;
                    }
                    else {
                        buf=buf->left;
                        continue;
                    }
                }
                else {
                    if (buf->right == nullptr) {
                        buf->right = new Node<T>{ data };
                        count++;
                        break;
                    }
                    else {
                        buf = buf->right;
                        continue;
                    }
                }
            }
        }
    }

    void deleteNode(T data) {
        Node <T>* buf = root;
        while (buf->data != data) {
            if (buf->left != nullptr) {
                if (buf->data > data) {
                    buf = buf->left;
                }
                else {
                    buf = buf->right;
                }
            }
            if (buf->right != nullptr) {
                if (buf->data > data) {
                    buf = buf->left;
                }
                else {
                    buf = buf->right;
                }
            }
        }
            if (buf->left == nullptr && buf->right == nullptr) {
                buf = nullptr;
                cout << "qqqqq";
                count--;
            }
            else if (buf->left == nullptr && buf->right != nullptr) {
                buf = buf->right;
            }
            else if (buf->left != nullptr && buf->right == nullptr) {
                buf = buf->left;
            }
            else {
                Node <T>* buf1 = buf->right;
                while (buf1->left != nullptr) {
                    buf1 = buf1->left;
                }
                if (buf1->right == nullptr) {
                    buf = buf1;
                }
                else {
                    buf = buf1;
                    buf1 = buf1->right;
                }
            }
        
    }



        void show() {
            showAll(root);
        }

        void showAll(Node<T>* buf){
            cout << buf->data << " " << endl;
            if (buf->left != nullptr) {
                showAll(buf->left);
            }
            if (buf->right != nullptr) {
                showAll(buf->right);
            }
        }
    
};

int main() {

    const int array[]{ 8,1,48,49,5,9,78,3,87,6 };

    Tree<int> myTree(array,10);
    
    myTree.show();
    myTree.deleteNode(3);
    myTree.show();




}

