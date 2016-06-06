#include "GeneralTree.h"
#include <iostream>

using namespace std;

//default constructor that sets the start node to NULL
GeneralTree::GeneralTree() : start(NULL){ }

//copy constructor that sets start node to NULL
//Then, it copies the contents of other into the current tree
GeneralTree::GeneralTree(const GeneralTree& other) : start(NULL)
{
    copyOther(other);
}

//destructor, traverse the tree, freeing all the nodes
GeneralTree::~GeneralTree()
{
    clear();
}

//assignment operator
GeneralTree& GeneralTree::operator=(const GeneralTree& other)
{
    if (this != &other) {
        clear();
        copyOther(other);
    }

    return *this;
}

//inserts the characters into the node
TreeNode* GeneralTree::insert(char value, TreeNode* parent)
{
   TreeNode* newNode = new TreeNode(value);
    newNode->value;
    if(parent){
        parent->next.push_back(newNode);

    } else if(!parent && start){
        delete newNode;
        throw NoParentException;
    } else if(!parent && !start){
        start = newNode;
    } return newNode;

}

//calls printFrom
void GeneralTree::print() const
{
    printFrom(start);
    cout << endl;
}

//calls to copyFrom
void GeneralTree::copyOther(const GeneralTree& other)
{
    insert(other.start-> value, start);
    copyFrom(other.start, start);
}

//makes a call to clearFrom
void GeneralTree::clear()
{
    clearFrom(start);
}

//prints subtree recursively
void GeneralTree::printFrom(TreeNode* start) const {
    if (start == NULL) {
        return;
    }
    if (start->value != '.') {
        cout << start->value;
    }
    for(int i = 0; i < start->next.size(); i++){
        printFrom(start->next[i]);
    }

}

//Copying the current tree from another tree
void GeneralTree::copyFrom(TreeNode* start, TreeNode* parent)
{
    if(start == NULL){
        return;
    }

    insert(start->value, parent);
    for(int i = 0; i < start->next.size(); i++){
        copyFrom(start->next[i], parent);
    }
}

//deletes all nodes in the tree
void GeneralTree::clearFrom(TreeNode* start)
{
    if (start == NULL) {
        return;
    }

    for(int i = 0; i < start->next.size(); i++){
        clearFrom(start->next[i]);
    }
    delete start;
}