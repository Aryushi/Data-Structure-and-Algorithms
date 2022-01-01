#include<iostream>
#include<vector>
#include<queue>

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
//LEVEL ORDER PRINT
void printTree(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
       TreeNode<int>* f = q.front();
       q.pop();
       cout<<f->data<<":";
       for(int i=0;i<f->children.size();i++){
           cout<<f->children[i]->data<<",";
           q.push(f->children[i]);
       }
       cout<<endl;
    }
}
int countNode(TreeNode<int>* root){
    if(root == NULL)  //EDGE CASE
    {return 0;}
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans += countNode(root->children[i]);
    }
    return ans;
}
//taking input in level order
TreeNode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int> (rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
    TreeNode<int>* f = q.front();
    q.pop();
    cout<<"Enter number of children of "<<f->data<<":";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int childdata;
        cout<<"Enter "<<i<<"th child of "<<f->data<<":";
        cin>>childdata;
        TreeNode<int>* child = new TreeNode<int> (childdata);
        q.push(child);
        f->children.push_back(child);
    }
        }
    
    return root;
}
int main(){
    //here in order to take input the user must know recursion 
    TreeNode<int>* root = takeinput();
    printTree(root);
    cout<<"No of nodes :"<<countNode(root)<<endl;
}