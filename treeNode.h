#include <iostream>
#include <exception>
using namespace std;

template <class T> 
class TreeNode{

    public:
        TreeNode();
        TreeNode(T k);
        virtual ~TreeNode();

        T key; //key = data
        TreeNode<T> *left;
        TreeNode<T> *right;

        int leftDepth;
        int rightDepth;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
    leftDepth = 0;
    rightDepth = 0;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
    leftDepth = 0;
    rightDepth = 0;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}