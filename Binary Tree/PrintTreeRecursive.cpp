#include<iostream>

using namespace std;

template<typename T>
class BTNode{
 public:
 T data;
 BTNode<int>* left;
 BTNode<int>* right;

 BTNode(T data){
     this->data = data;
     left=NULL;
     right=NULL;
 }
 ~BTNode(){  //recursive destructor
     delete left;
     delete right;
 }
};

void printTree(BTNode<int>* root){
    if(root==NULL){  //base case :recursion will always hit the base case ; it was edge case in generic tree
        return;
    }
    cout<<root->data<<":";
    if(root->left){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int main(){
     BTNode<int>* root = new BTNode<int> (1);
     BTNode<int>* n1 = new BTNode<int> (2);
     BTNode<int>* n2 = new BTNode<int> (3);
     root->left = n1;
     root->right = n2;
     printTree(root);
     delete root;
}