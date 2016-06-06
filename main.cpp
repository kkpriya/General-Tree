#include "GeneralTree.h"
#include <sstream>
using namespace std;

void parseRecursive(stringstream& ss, GeneralTree& gt, TreeNode* parent)
{
    char nextChar;
    while (true) {
        ss >> nextChar;
        if (ss.fail())
            return;

        if (nextChar == ')')
            return;

        if (nextChar == '(') {
            TreeNode* newNode = gt.insert(' ', parent);
            parseRecursive(ss, gt, newNode);
        } else {
            gt.insert(nextChar, parent);
        }
    }
}

void parseExpression(const string& expr, GeneralTree& gt)
{
    stringstream ss;
    ss << expr;

    parseRecursive(ss, gt, NULL);
}

int main()
{
    // This should print:
    // (c(ab))
    GeneralTree gt;
    TreeNode* grandparent = gt.insert('.', NULL);
    TreeNode* parent1 = gt.insert('c', grandparent);
    TreeNode* parent2 = gt.insert('.', grandparent);
    TreeNode* kid1 = gt.insert('a', parent2);
    TreeNode* kid2 = gt.insert('b', parent2);
    gt.print();

    // This should print:
    // (abab(cd)d(ef(g(h))))
    GeneralTree gt2;
    parseExpression("(abab(cd)d(ef(g(h))))", gt2);
    gt2.print();

    // This should print:
    // (c(ab))
    GeneralTree gt3 = gt;
    gt3.print();

    // This should print:
    // (abab(cd)d(ef(g(h))))
    GeneralTree gt4(gt2);
    gt4.print();

    return 0;
}
