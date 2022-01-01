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
//leaf node is acting as a base case
int height(TreeNode<int>* root){
    int maxm=0;
    for(int i=0;i<root->children.size();i++){
       /* int childheight = height(root->children[i]);
        if(childheight > max){
            max = childheight;  
    }  */
     maxm = max(maxm, height(root->children[i]));
    }
    return maxm+1;
}
//how far from root node
//depth or level of node
//print all nodes at level k
//if value of k becomes 0 print the data
void depth(int k,TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
       depth(k-1,root->children[i]);
    }
}
//count number of leaf nodes
// int countleafnodes(TreeNode<int>* root){
//     if(root == NULL){
//         return 0;
//     }
//     int ans=0;
//     if(root->children.size()==0){
//         return 1;
//     }
//     for(int i=0;i<root->children.size();i++){
//         ans+=countleafnodes(root->children[i]);
//     }
//     return ans;
// }
void countleafnodes(TreeNode<int>* root,int &c){
    if(root == NULL){
        return;
    }
    
    if(root->children.size()==0){
        c++;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        countleafnodes(root->children[i],c);
    }
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
    cout<<"height of tree :"<<height(root)<<endl;
    int k;
    cout<<"Enter the level of tree to be printed :";
    cin>>k;
    cout<<"All the nodes at level "<<k<<" are :";
    depth(k,root);
    cout<<endl;
    // cout<<"No of leaf nodes :"<<countleafnodes(root)<<endl;//this also works just uncomment the commented counleafnodes function with ans variable
    int c=0;
    countleafnodes(root,c);
    cout<<"No of leaf nodes :"<<c<<endl;
    return 0;
}