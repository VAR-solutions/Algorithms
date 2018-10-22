/**
 * This is a simple example of binary search tree in C++.
 * In this example, left subtree is less than or equal to the node,
 * and right subtree is greater than the node.
*/

#include <iostream>
using namespace std;

int main()
{
    struct Node {
        int data;
        Node *left;
        Node *right;
    };

    Node *root = new Node();
    Node *lchild = new Node();
    root->left = lchild;
    Node *rchild = new Node();
    root->right = rchild;

    int input;
    cout << "Choose an integer greater than 0: ";
    cin >> input;
    while(cin.fail() || input == 0) {
        cout << "Invalid input. Please re-enter: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> input;
    }
    root->data = input;
    cout << "Value at root is: " << input << endl;

    // Input left child
    int linput;
    cout << "Choose value between 0 and " << input << " (inclusive)";
    cin >> linput;
    while(cin.fail() || linput > input) {
        cout << "Invalid input. Please re-enter: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> linput;
    }
    root->left->data = linput;
    cout << "Value of left child is :" << linput << endl;

    // Input right child
    int rinput;
    cout << "Choose value greater or equal to " << input+1;
    cin >> rinput;
    while(cin.fail() || rinput <= input) {
        cout << "Invalid input. Please re-enter: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> rinput;
    }
    root->right->data = rinput;
    cout << "Value of right child is: " << rinput << endl;

    // Printing tree
    cout << "Printing your binary tree..." << endl;
    cout << "      " << root->data << "      \n" <<
     "  /      \\\n" << lchild->data << "          "
     << rchild->data << endl;

     return 0;
}