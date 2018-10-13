//
// Created by insane-abhi on 23/9/18.
//

#include "AVL.hpp"
#include <iostream>
using namespace std;

inline int max(int a, int b) {
    return (a>b)? a: b;
}

template <class Key, class Value>
int height(AVLnode<Key,Value>* N) {
    if(N== nullptr)
        return 0;
    return N->height;
}

template <class Key, class Value>
AVLnode<Key,Value>* newNode(Key key, Value value) {
    AVLnode<Key,Value>* node = (AVLnode<Key,Value>*)malloc(sizeof(AVLnode<Key,Value>));
    node->key = key;
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

template <class Key, class Value>
AVLnode<Key,Value>* rightRotate(AVLnode<Key,Value> *y) {
    AVLnode<Key,Value> *x = y->left;
    AVLnode<Key,Value> *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}

template <class Key, class Value>
AVLnode<Key,Value>* leftRotate(AVLnode<Key,Value> *x) {
    AVLnode<Key,Value> *y = x->right;
    AVLnode<Key,Value> *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}

template <class Key, class Value>
int getBalance(AVLnode<Key,Value>* N) {
    if(N== nullptr)
        return 0;
    return height(N->left)-height(N->right);
}

template <class Key, class Value>
AVLnode<Key,Value>* insert(AVLnode<Key,Value>* node, Key key, Value value) {
    if(node== nullptr)
        return newNode(key,value);
    if (key <= node->key)
        node->left = insert(node->left,key,value);
    else if(key > node->key)
        node->right = insert(node->right,key,value);
    else
        return node;

    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);

    if(balance>1 && key<node->left->key)
        return rightRotate(node);
    if(balance<-1 && key>node->right->key)
        return leftRotate(node);
    if(balance>1 && key>node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template <class Key, class Value>
AVLnode<Key,Value>* minValueNode(AVLnode<Key,Value>* node) {
    AVLnode<Key,Value>* current = node;
    while (current->left!= nullptr)
        current = current->left;
    return current;
}

template <class Key, class Value>
AVLnode<Key,Value>* deleteNode(AVLnode<Key,Value>* root, Key key) {
    if(root== nullptr)
        return root;
    if(key<root->key)
        root->left = deleteNode(root->left,key);
    else if (key>root->key)
        root->right = deleteNode(root->right,key);
    else {
        if((root->left == nullptr) || (root->right== nullptr)) {
            AVLnode<Key,Value>* temp = root->left?root->left:root->right;
            if(temp== nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            AVLnode<Key,Value> *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1+max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if (balance>1 && getBalance(root->left) >=0)
        return rightRotate(root);
    if(balance>1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if(balance<-1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
template <class Key, class Value>
void preOrder(AVLnode<Key,Value> *root) {
    if(root!= nullptr) {
        cout << root->key << " " << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
template <class Key, class Value>
AVLnode<Key,Value>* Find(Key key, AVLnode<Key,Value>* node) {
    if (node->key == key)
        return node;
    else if (node->key > key) {
        if (node->left != nullptr)
            return Find(key, node->left);
        return node;
    } else if (node->key < key) {
        if (node->right != nullptr)
            return Find(key, node->right);
        return node;
    }
}
template <class Key, class Value>
void inOrder(AVLnode<Key,Value>* node) {
    if(node== nullptr)
        return;
    else {
        inOrder(node->left);
        cout << node->key << " " << node->val << endl;
        inOrder(node->right);
    }
}
template <class Key, class Value>
void postOrder(AVLnode<Key,Value>* node) {
    if(node== nullptr)
        return;
    else {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " " << node->val << endl;
    }
}
template <class Key, class Value>
AVLnode<Key,Value>* maxValueNode(AVLnode<Key,Value>* node) {
    AVLnode<Key,Value>* current = node;
    while (current->right!= nullptr)
        current = current->right;
    return current;
}
template <class Key, class Value>
void inOrderPredecesor(AVLnode<Key,Value>* root, AVLnode<Key,Value>*& pre, Key key) {
    if(root== nullptr) return;
    if(root->key==key) {
        if(root->left!= nullptr) {
            pre = maxValueNode(root->left);
        }
    }
    else if(root->key > key) {
        inOrderPredecesor(root->left,pre,key);
    }
    else {
        pre = root;
        inOrderPredecesor(root->right,pre,key);
    }
}
template <class Key, class Value>
void inOrderSuccessor(AVLnode<Key,Value>* root, AVLnode<Key,Value>*& suc, Key key) {
    if(root== nullptr) return;

    if (root->key == key) {
        if(root->right!= nullptr) {
            AVLnode<Key,Value>* tmp = root->right;
            while(tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
    }

    else if(root->key > key) {
        suc = root;
        inOrderSuccessor(root->left,suc,key);
    }
    else {
        inOrderSuccessor(root->right,suc,key);
    }
}
template <class Key, class Value>
int count(AVLnode<Key,Value>* n) {
    int c = 1;
    if(n== nullptr)
        return 0;
    else {
        c += count(n->left);
        c += count(n->right);
        return c;
    }
}
template <class Key, class Value>
void AVL<Key,Value>::put(const Key &key, const Value &value) {
    AVLnode<Key,Value>* current = root;
    current = insert(current,key,value);
    root = current;
}
template <class Key, class Value>
void AVL<Key,Value>::print_pre_order() {
    AVLnode<Key,Value>* current = root;
    preOrder(current);
    cout << endl;
}
template <class Key, class Value>
void AVL<Key,Value>::remove(const Key &key) {
    root = deleteNode(root,key);
}
template <class Key, class Value>
Value AVL<Key,Value>::get(const Key &key) {
    AVLnode<Key,Value>* current = root;
    return Find(key,current)->val;
}
template <class Key, class Value>
bool AVL<Key,Value>::has(const Key &key) {
    AVLnode<Key,Value>* current=root;
    if(Find(key,current)->key==key)
        return true;
    else
        return false;
}
template <class Key, class Value>
Key AVL<Key,Value>::successor(const Key &key) {
    AVLnode<Key,Value>* current = root;
    AVLnode<Key,Value>* suc = nullptr;
    inOrderSuccessor(current,suc,key);
    return suc->key;
}
template <class Key, class Value>
Key AVL<Key,Value>::predecessor(const Key &key) {
    AVLnode<Key,Value>* current = root;
    AVLnode<Key,Value>* pre = nullptr;
    inOrderPredecesor(current,pre,key);
    return pre->key;
}
template <class Key, class Value>
Key AVL<Key,Value>::minimum() {
    return minValueNode(root)->key;
}
template <class Key, class Value>
Key AVL<Key,Value>::maximum() {
    return maxValueNode(root)->key;
}
template <class Key, class Value>
void AVL<Key,Value>::print_in_order() {
    inOrder(root);
}
template <class Key, class Value>
void AVL<Key,Value>::print_post_order() {
    postOrder(root);
}
template <class Key, class Value>
int AVL<Key,Value>::getHeight() {
    return root->height;
}
template <class Key, class Value>
void AVL<Key,Value>::print() {
    inOrder(root);
}
template <class Key, class Value>
int AVL<Key,Value>::size() {
    return count(root);
}
template <class Key, class Value>
void q1(AVLnode<Key,Value>* root, Key k1, Key k2, Value val, Value& count) {
    if(root == nullptr)
        return;
    if(k1 < root->key)
        q1(root->left,k1,k2,val,count);
    if(k1 < root->key && k2 >= root->key) {
        if(abs(root->val-val)<count)
            count = abs(root->val-val);
    }

    if(k2 > root->key)
        q1(root->right,k1,k2,val,count);
}
template <class Key, class Value>
Value AVL<Key,Value>::que_1(Key &key, Value &val) {
    Value count = INT32_MAX;
    AVLnode<Key,Value>* current = root;
    Key max = maximum();
    q1(current,key,max,val,count);
    if(count == INT32_MAX)
        return -1;
    else
        return count;
}
template <class Key, class Value>
void q2(AVLnode<Key,Value>* root, Key k1, Key k2, Value val, Value& count) {
    if(root == nullptr)
        return;
    if(k1 < root->key)
        q2(root->left,k1,k2,val,count);
    if(k1 <= root->key && k2 > root->key) {
//        cout << root->key << " " << root->val << " ";
        if(root->val>val) {
            count++;
        }
    }

    if(k2 > root->key)
        q2(root->right,k1,k2,val,count);
}
template <class Key, class Value>
Value AVL<Key,Value>::que_2(Key &key, Value &val) {
    Value count = 0;
    AVLnode<Key,Value> *current = root;
    Key min = minimum();
    q2(current,min,key,val,count);
    return count;
}