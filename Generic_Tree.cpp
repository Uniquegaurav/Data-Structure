#include<bits/stdc++.h>
using namespace std;
template <typename T >
class TreeNode{
    public :
        T data;
        vector<TreeNode *> children;
        TreeNode(T data){
            this->data = data;
        }
};
void printTree(TreeNode<int> * root){
    cout<<root->data<<":";
    for(int i =0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
// take input recursion wise
TreeNode<int> * takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of"<<rootData<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        TreeNode<int> * child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
// take input level wise
TreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendinNodes;
    pendinNodes.push(root);
    while(!pendinNodes.empty()){
        TreeNode<int> * front = pendinNodes.front();
        pendinNodes.pop();
        int n;
        cout<<"Enter number of children of"<<front->data<<endl;
        cin>>n;
        for(int i =0;i<n;i++){
            int childData;
            cout<<"Enter"<<i<<"th child of"<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendinNodes.push(child);
        }
    }
    return root;
}

int main(){
    // 1: 2 3 4
    // 2 : 5 6
    // 3 : 7
    // 4 : 8
    TreeNode<int> * root = takeInputLevelWise();
    printTree(root);
}