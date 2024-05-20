#ifndef LAZYBST_H
#define LAZYBST_H

#include "treeNode.h"
#include "stack.h"
#include <fstream>

template<class T>
class LazyBST{

    public: 
        LazyBST();
        virtual ~LazyBST();

        void insert(T value);
        void updateDepth(TreeNode<T>* node);
        bool check_height(TreeNode<T>* node);
        void rebuild(TreeNode<T>* node);
        int full_count(TreeNode<T>* node);
        bool contains(T value); //search function
        /*check to see if a student has an advisor that exists in faculty tree*/
        bool IDexists(int value);
        /*this goes through faculty's list of students*/
        bool containsID_infaculty(int value);
        /*check to see if a faculty has an advisee that exists in student tree*/
        bool deleteNode(int k);
        bool containsIDHelper(TreeNode<T>* node, int value);
        void deleteadvisee(int advisee);
        bool deleteadviseehelper(TreeNode<T>* node, int value);

        bool getstudAdvisor(int facid, int replacement);
        bool studadvisor_helper(TreeNode<T>* node, int value, int replacement);
        int getrootID();

        bool addadvisee(int fac, int advisee);
        bool addadviseehelper(int fac, int advisee);

        bool removefromlist(int targetfac, int toremove);
        bool removefromlisthelper(int targetfac, int toremove);

        TreeNode<T> *getSuccessor(TreeNode<T> *d); //finds the successor for the node being deleted

        bool isEmpty();
        T* getMin();
        T* getMax();
        

        void printTree();
        void printAscending();
        void printAscendingtofile(const string& filename);
        void printtofilehelper(TreeNode<T>* node, ofstream& outFile);
        void find(int id);
        void recPrint(TreeNode<T> *node); //takes a node and prints the tree beneath that node

    private:
        TreeNode<T> *root;
        
};
template<class T>
void LazyBST<T>::printAscendingtofile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "Error opening file " << filename << endl;
            return;
        }

        printtofilehelper(root, outFile);

        outFile.close();
        cout << "BST contents written to " << filename << endl;
    }

template<class T>
void LazyBST<T>::printtofilehelper(TreeNode<T>* node, ofstream& outFile) {
    int treeSize = full_count(node);
    /*we want the stack to be able to hold nodes*/
    GenStack<TreeNode<T>*> stack(treeSize);
    /*iterate through the tree to add nodes to a stack and pop off to get them in order to put into an array*/
    while(node != NULL || !stack.isEmpty()){
        if(node != NULL){
            stack.push(node);
            node = node->left;
        }
        else {
            node = stack.peek();
            outFile << node->key << endl;
            stack.pop();
            node = node->right;
        }
    }
    }


template<class T>
bool LazyBST<T>::addadvisee(int fac, int advisee){
    if(isEmpty()){
        return false;
    } else {
        return addadviseehelper(fac, advisee);
    }
}

template<class T>
bool LazyBST<T>::addadviseehelper(int fac, int advisee){
    if(isEmpty()){
        return false;
    } else {
        TreeNode<T> *current = root;
        while(current->key.get_ID() != fac){
            if(current->key.get_ID() > fac){
                current = current->left;
            } else {
                current = current->right;
            }
            if(current == NULL){
                return false;
            }
        
        }
        return current->key.add_advisee(advisee);
    }
}

template<class T>
bool LazyBST<T>::removefromlist(int targetfac, int toremove){
    if(isEmpty()){
        return false;
    } else {
        return removefromlisthelper(targetfac, toremove);
    }
}

template<class T>
bool LazyBST<T>::removefromlisthelper(int targetfac, int toremove){
    if(isEmpty()){
        return false;
    } else {
        TreeNode<T> *current = root;
        while(current->key.get_ID() != targetfac){
            if(current->key.get_ID() > targetfac){
                current = current->left;
            } else {
                current = current->right;
            }
            if(current == NULL){
                return false;
            }
        
        }
        return current->key.remove_advisee(toremove);
    }
}

template<class T>
int LazyBST<T>::getrootID(){
    if(isEmpty()){
        return false;
    } else {
        return root->key.get_ID();
    }
}

template<class T>
bool LazyBST<T>::getstudAdvisor(int facid, int replacement){
    if(isEmpty()){
        return false;
    } else {
        return studadvisor_helper(root, facid, replacement);
    }
}

template<class T>
bool LazyBST<T>::studadvisor_helper(TreeNode<T>* node, int value, int replacement) {
    if (node == nullptr) {
        return false;
    }
    
    if (value == node->key.get_ID()) {
        node->key.updateID(replacement);
        cout << "found" << endl;
        return true;
    }

    // Recursively check left and right subtrees
    return studadvisor_helper(node->left, value, replacement) || studadvisor_helper(node->right, value, replacement);
}



template<class T>
bool LazyBST<T>::IDexists(int value){
    if(isEmpty()){
        return false;
    } else {
        TreeNode<T> *current = root;
        while(current->key.get_ID() != value){
            if(current->key.get_ID() > value){
                current = current->left;
            } else {
                current = current->right;
            }
            if(current == NULL){
                return false;
            }
        
        }

        return true;
    }
}

template<class T>
void LazyBST<T>::deleteadvisee(int advisee){
    
    deleteadviseehelper(root, advisee);
    
   
}

template<class T>
bool LazyBST<T>::deleteadviseehelper(TreeNode<T>* node, int value) {
    if (node == nullptr) {
        return false;
    }
    
    if (value == node->key) {
        return true;
    }

    // Recursively check left and right subtrees
    return deleteadviseehelper(node->left, value) || deleteadviseehelper(node->right, value);
}

template<class T>
bool LazyBST<T>::containsID_infaculty(int value){
    if(isEmpty()){
        return false;
    } else {
        return containsIDHelper(root, value);
    }
}

template<class T>
bool LazyBST<T>::containsIDHelper(TreeNode<T>* node, int value) {
    if (node == nullptr) {
        return false;
    }
    
    if (node->key == value) {
        return true;
    }

    // Recursively check left and right subtrees
    return containsIDHelper(node->left, value) || containsIDHelper(node->right, value);
}

template<class T>
LazyBST<T>::LazyBST(){
    root = NULL;
    

}

template<class T>
LazyBST<T>::~LazyBST(){
    root = NULL;
    /*TODO: DOES THIS NEED ANYTHING ELSE?*/
}

template<class T>
void LazyBST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }
    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
    
    
    
}

template<class T>
void LazyBST<T>::printTree(){
    recPrint(root);
}

template<class T>
bool LazyBST<T>::isEmpty(){
    return(root == NULL);
}

template<class T>
T* LazyBST<T>::getMin(){
    if(isEmpty()){
        return NULL;
    }

    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }

    return &(current->key);
}

template<class T>
T* LazyBST<T>::getMax(){
    if(isEmpty()){
        return NULL;
    }

    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }

    return &(current->key);
}

template<class T>
int LazyBST<T>::full_count(TreeNode<T>* node){
    if (node == nullptr) {
        return 0;
    }
    
    return (1 + full_count(node->left) + full_count(node->right));
}


template<class T>
void LazyBST<T>::find(int id){
    if(isEmpty()){
        cout << "Table is empty" << endl;
    } else {
        TreeNode<T> *current = root;
        while(current->key != id){
            if(current->key > id){
                current = current->left;
            } else {
                current = current->right;
            }
            if(current == NULL){
                throw runtime_error("stack is empty, nothing to pop");
            }
        
        }

        cout << current->key << endl;
        
    }
}

template<class T>
void LazyBST<T>::insert(T value){
   TreeNode<T> *node = new TreeNode<T>(value);
    if(isEmpty()){
        root = node;
    } else {
        TreeNode<T> *current = root;
        TreeNode<T> *parent = root;

        while(true){
            parent = current;

            if(value < current->key){
                current = current->left;
                
                if(current == NULL){
                    parent->left = node;  
                    break;
                }

            } else {
                current = current->right;

                if(current == NULL){
                    parent->right = node;
                    break;
                }
            }


        }
            /*update the depth values of the nodes starting from the root*/
            updateDepth(root);
            if(check_height(root)){
                rebuild(root);
            }
    }

}

template<class T>
void LazyBST<T>::printAscending(){
    TreeNode<T> *node = root;
    int treeSize = full_count(node);
    /*we want the stack to be able to hold nodes*/
    GenStack<TreeNode<T>*> stack(treeSize);
    /*iterate through the tree to add nodes to a stack and pop off to get them in order to put into an array*/
    while(node != NULL || !stack.isEmpty()){
        if(node != NULL){
            stack.push(node);
            node = node->left;
        }
        else {
            node = stack.peek();
            cout << node->key << endl;
            stack.pop();
            node = node->right;
        }
    }
}

template<class T>
void LazyBST<T>::rebuild(TreeNode<T>* node){
    /*get the number of nodes in tree from full_count function*/
    int treeSize = full_count(node);
    T array[treeSize];
    int i = 0;
    /*we want the stack to be able to hold nodes*/
    GenStack<TreeNode<T>*> stack(treeSize);
    /*iterate through the tree to add nodes to a stack and pop off to get them in order to put into an array*/
    while(node != NULL || !stack.isEmpty()){
        if(node != NULL){
            stack.push(node);
            node = node->left;
        }
        else {
            node = stack.peek();
            array[i] = node->key;
            i++;
            stack.pop();
            node = node->right;
        }
    }
    /*DELTE THE OLD TREE AFTER ALL THE VALUES HAVE BEEN MAPPED TO ASCENDING ARRAY*/
    for(int x = 0; x < treeSize; x++){
        deleteNode(array[x].get_ID());
    }

    /*this will insert the root first*/
    insert(array[treeSize/2]);

    /*insert the rest of the values, should order themselves accordingly*/
    for(int x = 0; x < treeSize; x++){
        /*if statement skips over root node that we inserted earlier in the array*/
        if(x != treeSize/2){
            insert(array[x]);
        }
    }

}


template<class T>
void LazyBST<T>::updateDepth(TreeNode<T>* node){
    if(node == nullptr){
        return;
    }

    updateDepth(node->left);  // Recursively update left subtree depth
    updateDepth(node->right); // Recursively update right subtree depth

    int leftDepth = (node->left) ? max(node->left->leftDepth, node->left->rightDepth) + 1 : 0;
    int rightDepth = (node->right) ? max(node->right->leftDepth, node->right->rightDepth) + 1 : 0;

    node->leftDepth = leftDepth;
    node->rightDepth = rightDepth;
}

template<class T>
bool LazyBST<T>::check_height(TreeNode<T>* node){
    if (node == nullptr) {
        return false;  
    }

    // Calculate the heights of the left and right subtrees of the current node
    int leftHeight = node->leftDepth;
    int rightHeight = node->rightDepth;

    //  Check if the difference between heights is greater than 1.5
    if (abs(leftHeight - rightHeight) > 1.5) {
        cout << "Imbalance detected at node " << node->key << endl;
        return true;  // Imbalance detected, return true
    }

    // Recursively check the left and right subtrees
    bool leftImbalance = check_height(node->left);
    bool rightImbalance = check_height(node->right);

    return leftImbalance || rightImbalance;  
}


template <class T>
bool LazyBST<T>::contains(T value){
    if(isEmpty()){
        return false;
    } else {
        TreeNode<T> *current = root;
        while(current->key != value){
            if(value < current->key){
                current = current->left;
            } else {
                current = current->right;
            }
            if(current == NULL){
                return false;
            }
        
        }

        return true;
    }
}

template <class T>
bool LazyBST<T>::deleteNode(int k){
    if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(current->key.get_ID() != k){
        parent = current;

        if(current->key.get_ID() > k){
            isLeft = true;
            current = current->left;
        }
        else {
            isLeft = false;
            current = current->right;
        }

        if(current == NULL){
            return false;
        }
    }

    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if(isLeft){
            parent->left = NULL;
        } else{
            parent->right = NULL;
        }
    }

    //node with left child
    else if(current->right == NULL){
         if(current == root){
            root = current->left;
        }
        else if(isLeft){
            parent->left = current->left;
        } else{
            parent->right = current->left;
        }
    }

    else if(current->right == NULL){

        //node has one child that is a right child
         if(current == root){
            root = current->right;
        }
        else if(isLeft){
            parent->left = current->right;
        } else{
            parent->right = current->right;
        }
    } else {
        //the node to be deleted has two children

        TreeNode<T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        } else if(isLeft){
            parent->left = successor;
        } else {
            parent->right = successor;
        }

        successor->left = current->left;
        current->left = NULL;
        current->right = NULL;

    }

    delete current;
    return true;
}

template <class T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }

    //we found the successor, check if successor is a descendant of the right child
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }

    return successor;
}





#endif