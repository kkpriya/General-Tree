Assignment 7: General Tree

The goal of this assignment is to print the general tree using linked list.
The following methods are use to implement the general tree:

    //default constructor
    GeneralTree();

    //copy constructor
    GeneralTree(const GeneralTree& other);

    //destructor
    ~GeneralTree();

    //assignment operator, removes everything from the current tree and copys it into another
    GeneralTree& operator=(const GeneralTree& other);

    //inserts the values into the node
    TreeNode* insert(char value, TreeNode *parent);

    //calls printFrom
    void print() const;

    //makes a call for copyFrom
    void copyOther(const GeneralTree& other);

    //makes a call for clearFrom
    void clear();

    //prints out the general tree
    void printFrom(TreeNode *start) const;

    //recursively copies the current tree into another tree
    void copyFrom(TreeNode *start, TreeNode *parent);

    //recursively deletes all the nodes
    void clearFrom(TreeNode *start);
