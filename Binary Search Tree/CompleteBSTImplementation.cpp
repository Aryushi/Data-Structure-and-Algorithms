#include<iostream>

using namespace std;

template<typename T>
class BTNode{
public:
 T data;
  BTNode* left;
  BTNode* right;

  BTNode(T data){
     this->data = data;
     left = NULL;
     right= NULL;
 }

   BTNode(){
     delete left;
     delete right;
 }

};
class Pair{
   public:
   BTNode<int>* head;
   BTNode<int>* tail;
};
class BST{
  BTNode<int>* root;
  
  void printTree(BTNode<int>* root){
   if(root==NULL){
       return;
   }
   cout<<root->data<<":";

   if(root->left!=NULL){
       cout<<"L"<<root->left->data;
   }
   if(root->right!=NULL){
       cout<<"R"<<root->right->data;
   }
   cout<<endl;
   printTree(root->left);
   printTree(root->right);
}
bool hasData(BTNode<int>* root,int data){
       if(root==NULL){
           return false;
       }
       if(root->data == data){
           return true;
       }
       if(root->data>data){
           return hasData(root->left,data);
       }
       if(root->data<data){
           return hasData(root->right,data);
       }
   }

   BTNode<int>* insert(BTNode<int>* node,int data){
       if(node==NULL)
      { BTNode<int>* n = new BTNode<int> (data);
       return n;}
       if(data <node->data){
           node->left = insert(node->left,data);
       }
       else{
           node->right = insert(node->right,data);
       }
       return node;
   }
   BTNode<int>* deleteData(BTNode<int>* root,int data){
          if(root==NULL){
              return NULL;
          }
          if(data > root->data){
              root->right = deleteData(root->right,data);
          }
          else if(data< root->data){
              root->left = deleteData(root->left,data);
          }
          else{
              if(root->left ==NULL && root->right==NULL){
                  delete root;
                  return NULL;
              }
              else if(root->right==NULL && root->left!=NULL){
                  BTNode<int>* temp = root->left;
                  root->left = NULL;
                  delete root;
                  return temp;
              }
              else if(root->right!=NULL && root->left==NULL){
                  BTNode<int>* temp = root->right;
                  root->right = NULL;
                  delete root;
                  return temp;
              }
              else{
                    BTNode<int>* minNode = root->right;
                    while(minNode->left!=NULL){
                        minNode = minNode->left;
                    }
                    int rightMin = minNode->data;
                    root->data = rightMin;
                    root->right = deleteData(root->right,rightMin);
              }
          }
          return root;
   }
   Pair convertToLL(BTNode<int>* root){
       if(root == NULL){
           Pair ans;
           ans.head = NULL;
           ans.tail = NULL;
           return ans;
       }
       if(root->left==NULL && root->right==NULL){
           Pair p;
           p.head = root;
           p.tail = root;
           return p;
       }
       else if(root->left!=NULL && root->right == NULL){
           Pair leftLL = convertToLL(root->left);
           leftLL.tail->right = root;
           Pair ans;
           ans.head = leftLL.head;
           ans.tail = root;
           return ans;
       }else if(root->left==NULL && root->right != NULL){
           Pair rightLL = convertToLL(root->right);
           root->right = rightLL.head;
           Pair ans;
           ans.head = root;
           ans.tail = rightLL.tail;
           return ans;
       }
       else{
           Pair leftLL = convertToLL(root->left);
           Pair rightLL = convertToLL(root->right);
           leftLL.tail->right = root;
           root->right = rightLL.head;
           Pair ans;
           ans.head = leftLL.head;
           ans.tail = rightLL.tail;
           return ans;
       }

   }
public:
  BST(){
      root=NULL;
  }
  ~BST(){
      delete root;
  }
  
   void deleteData(int data){
      root = deleteData(root,data);
   }

   void print(){
      printTree(root);
   }

   int hasData(int data){
      return hasData(root,data);  //function overloading
   }

   void insert(int data){
    root = insert(root,data);
   }

   BTNode<int>* convertToLL(){
       Pair p = convertToLL(root);
       BTNode<int>* temp = p.head;
       while(temp!=NULL){
           temp->left=NULL;
           temp=temp->right;
    }
       return p.head;
   }
};
int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);

    b.print();
    cout<<endl;
    // int data;
    // cout<<"enter data to be searched";
    // cin>>data;
    // if(b.hasData(data)){
    //     cout<<data<<" is present";
    // }
    BTNode<int>* head = b.convertToLL();
    BTNode<int>* temp = head;
    cout<<"LinkedList :";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
    b.deleteData(10);
    b.print();
}
