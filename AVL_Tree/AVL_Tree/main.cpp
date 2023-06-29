#include <iostream>

using namespace std;

template<typename T>

struct Node
{
    T data;
    unsigned int height;
    Node<T>* left;
    Node<T>* right;
    Node(T k) {
        data = k;
        left = right = 0;
        height = 1; };
};

template<typename T>

class Tree {
    Node <T>* root = nullptr;
    int count = 0;

public:
    
    unsigned int getHeight(Node<T>* node)
    {
        return node?node->height:0;
    }
    
    int getDiffHeight(Node<T>* node)
    {
        return height(node->right)-height(node->left);
    }
    
    void fixHeight(Node<T>* node)
    {
        unsigned int heightL = height(node->left);
        unsigned int heightR = height(node->right);
        node->height = (heightL>heightR?heightL:heightR)+1;
    }
    
    Node<T>* rotateRight(Node<T>* node)
    {
        Node<T>* buf = node->left;
        node->left = buf->right;
        buf->right = node;
        fixheight(node);
        fixheight(buf);
        return buf;
    }
    
    Node<T>* rotateLeft(Node<T>* node)
    {
        Node<T>* buf = node->right;
        node->right = buf->left;
        buf->left = node;
        fixheight(node);
        fixheight(buf);
        return buf;
    }
    
    Node<T>* balance(Node<T>* node)
    {
        fixheight(node);
        if(getHeight(node)==2 )
        {
            if( getHeight(node->right) < 0 )
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        if( getHeight(node)==-2 )
        {
            if( getHeight(node->left) > 0  )
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }
    
    Node<T>* insert(Node<T>* node, T data)
    {
        if( !node ) return new Node(data);
        if( data<node->data )
            node->left = insert(node->left,data);
        else
            node->right = insert(node->right,data);
        return balance(node);
    }
    
    Node<T>* findMin(Node<T>* node)
    {
        return node->left?findMin(node->left):node;
    }
    
    Node<T>* removeMin(Node<T>* node)
    {
        if( node->left==0 )
            return node->right;
        node->left = removeMin(node->left);
        return balance(node);
    }
    
    Node<T>* remove(Node<T>* node, T data)
    {
        if( !node ) return 0;
        if( data < node->data )
            node->left = remove(node->left,data);
        else if( data > node->data )
            node->right = remove(node->right,data);
        else {
                Node<T>* bufL = node->left;
                Node<T>* bufR = node->right;
                delete node;
                if( !bufR ) return bufL;
                Node<T>* min = findMin(bufR);
                min->right = removeMin(bufR);
                min->left = bufL;
                return balance(min);
            }
        return balance(node);
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




}


