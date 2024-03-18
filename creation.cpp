#include<iostream>
using namespace std;

class Node{
    public:
    int data,height;
    Node* left,*right;

    Node(int value){
        data =value;
        height =1;
        left = right =NULL;
    }

};


int getHeight(Node* root){
    if(!root) return 0;
    
    return root->height;
}


Node* rightRotation(Node* root){
    Node* child = root->left;
    Node* rightChild =child->right;

    child->right=root;
    root->left=rightChild;

    //updating height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));

    return child;

}
Node* leftRotation(Node* root){
    Node* child = root->right;
    Node* leftChild =child->left;

    child->left=root;
    root->right=leftChild;

    //updating height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    child->height=1+max(getHeight(child->left),getHeight(child->right));

    return child;
}


int getbalance(Node* root){
    return getHeight(root->left)-getHeight(root->right);
}

Node* insert(Node* root,int key){
    //if doesn't exist
    if(!root)
    return new Node(key);
    //if exist
    if(key<root->data){
        root->left = insert(root->left,key);
    }
    else if(key>root->data){
        root ->right = insert(root->right,key);
    }
    
    else
    return root;

    //update height
    root->height = 1+ max(getHeight(root->left),getHeight(root->right));

    //balancing check
    int balance=getbalance(root);

    //RR
    if(balance>1 && root->left->data>key){
        return rightRotation(root);
    }
    //ll
    else if(balance<-1 && root->right->data<key){
        return leftRotation(root);

    }
    //rl
    else if(balance>1 && root->left->data<key){
        root->left =leftRotation(root->left);
        return rightRotation(root);
    }
    //lr
    else if(balance<-1 && root->right->data>key){
        root->right =rightRotation(root->right);
        return leftRotation(root);
    }
    else
    return root;
}


void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root =NULL;
    root = insert(root,23);
    root = insert(root,30);
    root = insert(root,14);
    root = insert(root,85);
    root = insert(root,90);
    root = insert(root,15);
    root = insert(root,37);
    root = insert(root,53);

    cout<<"Inorder traversal is: "<<endl;
    inorder(root);

}

