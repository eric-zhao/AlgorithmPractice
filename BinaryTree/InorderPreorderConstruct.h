#include <header.h>

int findPosition(vector<int> myvector, int val){
        int counter=0;
        for(vector<int>::iterator itr=myvector.begin(); itr<myvector.end(); itr++){
            if(*itr != val) counter++;
            else return counter;
        }
    }
    
    vector<int> getPreOrder(vector<int> preOrderVector, vector<int> myvector){
        int num = myvector.size();
        vector<int> result;
        for(vector<int>::iterator itr=preOrderVector.begin(); itr<preOrderVector.end(); itr++){
            vector<int>::iterator it = find(myvector.begin(), myvector.end(), *itr);
            if( it != myvector.end()) {
                result.insert(result.begin(), it, it+num);
                return result;
            }
        }
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        else{
            int val = preorder[0];
            TreeNode* root=new TreeNode(val);
            int position = findPosition(inorder, val);
            vector<int> left;
            left.insert(left.begin(), inorder.begin(), inorder.begin()+position);
            vector<int> right;
            right.insert(right.begin(), inorder.begin()+position+1, inorder.end());
            vector<int> pre1 = getPreOrder(preorder, left);
            vector<int> pre2 = getPreOrder(preorder, right);
            TreeNode* leftSubTree = buildTree(pre1, left);
            TreeNode* rightSubTree = buildTree(pre2, right);
            root->left = leftSubTree;
            root->right = rightSubTree;
            return root;
        }
        
    }
    
    void displayResult(vector<int> &preorder, vector<int> &inorder){
    	TreeNode *root = buildTree(preorder, inorder);
    	cout << "Pre-order Traversal is: " << endl;
    	if(root==NULL) return;
    	else{
    		cout << root->val << ",";
    		displayResult(root->left);
    		displayResult(root->right);
    	}
    }