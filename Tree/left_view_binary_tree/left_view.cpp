struct Node
{
    char data;
    Node* left;
    Node* right;
    Node(int v):data(v), left(NULL), right(NULL){}
};
void printLeftView(Node *r, int level, int* maxLevel)
{
    if(r == NULL){ return; }
    if(level > *maxLevel)
    {
        printf("%c ", r->data);
        *maxLevel = level;
    }
    printLeftView(r->left, level+1, maxLevel);
    printLeftView(r->right, level+1, maxLevel);
}
int main(int argc, const char * argv[]) {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->left->right = new Node('G');
    int maxLevel = -1;
    printLeftView(root, 0, &maxLevel);
    return 0;
}