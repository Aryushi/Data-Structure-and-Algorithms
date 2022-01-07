#include<iostream>
#include<queue>
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
void LevelOrderTraversal(BTNode<int>* root){
    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();
        cout<<f->data <<":";
        if(f->left){
            cout<<"L"<<f->left->data;
            q.push(f->left);
        }
        if(f->right){
            cout<<"R"<<f->right->data;
            q.push(f->right);
        }
        cout<<endl;
    }
}
BTNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data :";
    cin>>rootData;
    queue<BTNode<int>*> q;
    BTNode<int>* root = new BTNode<int>(rootData);
    q.push(root);
    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();
        cout<<"enter left child of "<<f->data;
        int leftchildData;
        cin>>leftchildData;
        if(leftchildData != -1)
       { BTNode<int>* leftchild = new BTNode<int>(leftchildData); 
        f->left = leftchild;
        q.push(leftchild);}
        cout<<"Enter right child of "<<f->data;
        int rightchildData;
        cin>>rightchildData;
        if(rightchildData != -1){
        BTNode<int>* rightchild = new BTNode<int>(rightchildData); 
        f->right = rightchild;
        q.push(rightchild);
        }

    }
    return root;
 }
int main(){
     BTNode<int>* root = takeInputLevelWise();
     printTree(root);
     LevelOrderTraversal(root);
     delete root;
}