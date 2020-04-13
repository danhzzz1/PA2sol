#include "BST.h"
#include <vector>

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */
    root = NULL;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}
void myHelper(BST::Node* node) {
    // do something
    if(node){    
        if(node -> leftChild)
            myHelper(node -> leftChild);
        if(node -> rightChild)
            myHelper(node -> rightChild);
        delete node;
    }
}
/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    myHelper(root);
    root = NULL;
    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
    if(!root){
        numElements++;
        root = new Node(element);
        return 1;
    }
    Node *temp = root;
    while(temp -> data != element){
        if(element < temp -> data){
            if(temp ->leftChild == NULL){
                temp -> leftChild = new Node(element);
                numElements++;
                return 1;
            }
            else{
                temp = temp -> leftChild;
            }
        }
        else if(element > temp -> data){
            if(temp ->rightChild == NULL){
                temp -> rightChild = new Node(element);
                numElements++;
                return 1;
            }
            else{
                temp = temp -> rightChild;
            }
        }
    }
    return 0;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    /* YOUR CODE HERE */
    Node *temp = root;
    while(query != temp -> data){
        if(query < temp -> data){
            temp = temp -> leftChild;
        }
        else if(query > temp -> data){
            temp = temp -> rightChild;
        }
        if(!temp){
            return false;
        }
    }
    return true;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    Node *temp = root;
    if(!temp){
        return NULL;
    }
    while ((temp -> leftChild)){
        temp = temp -> leftChild;
    }
    return temp;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    Node *temp;
    if(rightChild != NULL){
        temp = rightChild;
        while(temp-> leftChild != NULL){
            temp = temp -> leftChild;
        }
        return temp;
    }
    else{
        temp = this;
        while(temp -> parent != NULL){
            if(temp == temp -> parent -> leftChild){
                return temp -> parent;    
            }
            else{
                temp = temp -> parent;
            }
        }
        return NULL;
    }
}
