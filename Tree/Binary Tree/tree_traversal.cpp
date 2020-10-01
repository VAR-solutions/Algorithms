# include <iostream>
# include "create_tree.h"


void preorder(Node* root){
  if(root==nullptr){
    return;
  }
  std::cout << root->data <<"->";
  preorder(root->left_child);
  preorder(root->right_child);
}

void inorder(Node* root){
  if (root==nullptr)
  return;
  inorder(root->left_child);
  std::cout << root->data <<"->";
  inorder(root->right_child);
}

void postorder(Node* root){
  if(root==nullptr)
  return;
  postorder(root->left_child);
  postorder(root->right_child);
  std::cout << root->data <<"->" ;
}

int main(){
  create_tree tree;
  Node* root=new Node;
  tree.add_root(&root,89);
  tree.add_node(root,78);
  tree.add_node(root,36);
  tree.add_node(root,14);
  tree.add_node(root,12);
  tree.add_node(root,54);
  tree.add_node(root,23);
  tree.add_node(root,108);
  tree.add_node(root,95);
  tree.add_node(root,67);
  preorder(root);
  std::cout << "null" << '\n';
  postorder(root);
  std::cout << "null" << '\n';
  inorder(root);
  std::cout << "null" << '\n';

}
