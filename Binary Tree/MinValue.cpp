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
int countNodes(BTNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int c=1;
    if(root->left){
        c+=countNodes(root->left);
    }
    if(root->right){
        c+=countNodes(root->right);
    }
    return c;
}
void Inorder(BTNode<int>* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Postorder(BTNode<int>* root){
    if(root == NULL){  //base case od recursion
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
void Preorder(BTNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
//Height or maximum depth of tree
int Height(BTNode<int>* root){
   if(root ==NULL){
       return 0;
   }
   int left = Height(root->left);
   int right = Height(root->right);
   return max(left,right) + 1;
}
bool symmetricHelper(BTNode<int>* leftTree,BTNode<int>* rightTree){
    if(leftTree!=NULL && rightTree==NULL){
        return false;
    }
    if(leftTree==NULL && rightTree!=NULL){
        return false;
    }
    if(leftTree==NULL && rightTree==NULL){
        return true;
    }
    if(leftTree->data != rightTree->data){
        return false;
    }
    
    
    return (symmetricHelper(leftTree->left,rightTree->right) && symmetricHelper(leftTree->right,rightTree->left));
}
bool symmetric(BTNode<int>* root){
    if(root==NULL){
        return true;
    }
    return symmetricHelper(root->left,root->right);
}
bool searchNode(BTNode<int>* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }

    return(searchNode(root->left,key) || searchNode(root->right,key));
}
int minValue(BTNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    int leftmin = minValue(root->left);
    int rightmin = minValue(root->right);

    return min(root->data,min(leftmin,rightmin));
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
     cout<<"LevelOrder traversal :";
     LevelOrderTraversal(root);
     cout<<"Total number of nodes in the tree are :"<<countNodes(root)<<endl;
     cout<<"Inorder traversal :";
     Inorder(root);
     cout<<endl;
     cout<<"Postorder traversal :";
     Postorder(root);
     cout<<endl;
     cout<<"Preorder traversal :";
     Preorder(root);
     cout<<endl;
     cout<<"height of tree :"<<Height(root)<<endl;
     if(symmetric(root)){
         cout<<"Given binary tree is symmetric"<<endl;
     }
     else{
         cout<<"Given binary tree is not symmetric"<<endl;
     }
     cout<<"Enter the key you want to search";
     int key;
     cin>>key;
     if(searchNode(root,key)){
         cout<<key<<"is present"<<endl;
     }
     else{
         cout<<key<<"is not present"<<endl;
     }
     cout<<"Minimum value in tree is:"<<minValue(root)<<endl;
     delete root;
}