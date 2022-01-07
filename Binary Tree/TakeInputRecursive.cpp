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
BTNode<int>* takeInput(){
    int rootdata;
    cout<<" Enter data";
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    BTNode<int>* root = new BTNode<int>(rootdata);
    cout<<"Enter left child of "<<root->data;
    BTNode<int>* leftchild = takeInput();
    cout<<"Enter right child of "<<root->data;
    BTNode<int>* rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
 }
int main(){
     BTNode<int>* root = takeInput();
     printTree(root);
     delete root;
}