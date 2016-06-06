#ifndef GENERALTREE_GENERALTREE_H
#define GENERALTREE_GENERALTREE_H
#define NoParentException

#include <cstdlib>
#include <vector>
#include <string>

struct TreeNode{

    char value;
    std:: vector<TreeNode *> next;
    TreeNode(char value1) : value(value1) {};

};

class GeneralTree {

private:
    TreeNode *start;

public:
    GeneralTree();
    GeneralTree(const GeneralTree& other);
    ~GeneralTree();
    GeneralTree& operator=(const GeneralTree& other);
    TreeNode* insert(char value, TreeNode *parent);
    void print() const;
    void copyOther(const GeneralTree& other);
    void clear();
    void printFrom(TreeNode *start) const;
    void copyFrom(TreeNode *start, TreeNode *parent);
    void clearFrom(TreeNode *start);

};

#endif