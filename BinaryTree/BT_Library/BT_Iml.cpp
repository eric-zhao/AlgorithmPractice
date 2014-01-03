#include "BT.h"

void BT::insert(int d)
    {
        TreeNode* t = new TreeNode;
        TreeNode* parent;
        t->val = d;
        t->left = NULL;
        t->right = NULL;
        parent = NULL;
        // is this a new tree?
        if(isEmpty()) root = t;
        else
        {
            //Note: ALL insertions are as leaf TreeNodes
            TreeNode* curr;
            curr = root;
            // Find the TreeNode's parent
            while(curr)
            {
                parent = curr;
                if(t->val > curr->val) curr = curr->right;
                else curr = curr->left;
            }
            if(t->val < parent->val)
               parent->left = t;
            else
               parent->right = t;
        }
    }
    void BT::displayinorder()
    {
      inorder(root);
    }
    void BT::inorder(TreeNode* p)
    {
        if(p != NULL)
        {
            if(p->left) inorder(p->left);
            cout<<" "<<p->val<<" ";
            if(p->right) inorder(p->right);
        }
        else return;
    }
    void BT::displaypreorder()
    {
        preorder(root);
    }
    void BT::preorder(TreeNode* p)
    {
        if(p != NULL)
        {
            cout<<" "<<p->val<<" ";
            if(p->left) preorder(p->left);
            if(p->right) preorder(p->right);
        }
        else return;
    }
    void BT::displaypostorder()
    {
        postorder(root);
    }
    void BT::postorder(TreeNode* p)
    {
        if(p != NULL)
        {
            if(p->left) postorder(p->left);
            if(p->right) postorder(p->right);
            cout<<" "<<p->val<<" ";
        }
        else return;
    }
    void BT::displayPath(){
        vector<int> myvector;
        output(root, myvector);
    }
    void BT::output(TreeNode* p, vector<int> myvector)
    {
        if(p == NULL) return;
        else{
            myvector.push_back(p->val);
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
    
    int BT::MaxDepth(TreeNode* root){
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
    
    void BT::displayLevelTraverse_Itr(){
    	vector<vector<int> > levelTraverse = levelOrderBottom_Itr(root);
    	int num_level = levelTraverse.size();
    	for (int i=0; i<num_level; i++){
    		cout << "The " << i << "th: "; 
    		outputVector(levelTraverse[i]);
    		cout << endl;
    	}
    }
    
    void BT::outputVector(vector<int> myvector){
    	for(vector<int>::iterator itr = myvector.begin(); itr < myvector.end(); itr++){
    		cout << *itr << " ";
    	}
    }
    
    
    vector<vector<int> > BT::levelOrderBottom_Itr(TreeNode* root){
    	vector<vector<int> > result;
        vector<int> level;
        queue<TreeNode*> myqueue;
        stack<vector<int> > mystack;
        if(root==NULL) return result;
        myqueue.push(root);
        myqueue.push(NULL);
        while(!myqueue.empty()){
            TreeNode* node = myqueue.front();
            myqueue.pop();
            if(node!=NULL){
                level.push_back(node->val);
                if(node->left != NULL) myqueue.push(node->left);
                if(node->right != NULL) myqueue.push(node->right);
            }
            else{
                mystack.push(level);
                level.clear();
                if(!myqueue.empty()) myqueue.push(NULL);
            }
        }
        while(!mystack.empty()){
            result.push_back(mystack.top());
            mystack.pop();
        }
        return result;
    }