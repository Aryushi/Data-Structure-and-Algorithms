#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<int>*> children;
    TreeNode(T data){
        this->data = data;
    }
};
void printTree(TreeNode<int>* root){
    if(root==NULL) //edge case and not base case of recursion ,here leaf node acts as base case
    {return;}
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
TreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int> (rootdata);
    cout<<"Enter number of children of "<<rootdata<<":";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    TreeNode<int>* child= takeinput();
    root->children.push_back(child);
    }
    return root;
}
int main(){
    //here in order to take input the user must know recursion
    TreeNode<int>* root = takeinput();
    printTree(root);
}