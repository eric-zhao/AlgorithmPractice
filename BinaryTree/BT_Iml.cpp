#include "BT.h"

void BT::insert(int d)
    {
        node* t = new node;
        node* parent;
        t->data = d;
        t->left = NULL;
        t->right = NULL;
        parent = NULL;
        // is this a new tree?
        if(isEmpty()) root = t;
        else
        {
            //Note: ALL insertions are as leaf nodes
            node* curr;
            curr = root;
            // Find the Node's parent
            while(curr)
            {
                parent = curr;
                if(t->data > curr->data) curr = curr->right;
                else curr = curr->left;
            }
            if(t->data < parent->data)
               parent->left = t;
            else
               parent->right = t;
        }
    }
    void BT::displayinorder()
    {
      inorder(root);
    }
    void BT::inorder(node* p)
    {
        if(p != NULL)
        {
            if(p->left) inorder(p->left);
            cout<<" "<<p->data<<" ";
            if(p->right) inorder(p->right);
        }
        else return;
    }
    void BT::displaypreorder()
    {
        preorder(root);
    }
    void BT::preorder(node* p)
    {
        if(p != NULL)
        {
            cout<<" "<<p->data<<" ";
            if(p->left) preorder(p->left);
            if(p->right) preorder(p->right);
        }
        else return;
    }
    void BT::displaypostorder()
    {
        postorder(root);
    }
    void BT::postorder(node* p)
    {
        if(p != NULL)
        {
            if(p->left) postorder(p->left);
            if(p->right) postorder(p->right);
            cout<<" "<<p->data<<" ";
        }
        else return;
    }
    void BT::displayPath(){
        vector<int> myvector;
        output(root, myvector);
    }
    void BT::output(node* p, vector<int> myvector)
    {
        if(p == NULL) return;
        else{
            myvector.push_back(p->data);
            if(p->left==NULL && p->right==NULL){
                cout << "Output path: " <<endl;
                for(vector<int>::iterator itr =myvector.begin(); itr != myvector.end(); itr++){
                    cout << *itr << ",";
                }
                cout << endl;
            }
            else{
                output(p->left, myvector);
                output(p->right, myvector);
            }
        }
    }
    
    void BT::displayMaxDepth(){
    	cout << MaxDepth(root);
    }
    
    int BT::MaxDepth(node* root){
        if(root == NULL) return 0;
        else{
            if(root->left==NULL && root->right==NULL){
                return 1;
            }
            else{
            	int maxLeft = MaxDepth(root->left);
            	int maxRight = MaxDepth(root->right);
                return  maxLeft>maxRight  ? maxLeft+1 : maxRight+1;
            }
        }
    }