    #include <iostream>
    #include <vector>
    #include <stack>
    #include <queue>
    using namespace std;
    class BT
    {
       private:
            struct TreeNode
            {
               TreeNode* left;
               TreeNode* right;
               int val;
               //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
            };

            TreeNode* root;
          public:
            BT()
            {
               root = NULL;
               insert(1);
               insert(2);
        	   insert(4);
               insert(3);
               insert(6);
               insert(5);		 
            	cout << "the pre-order of the binary tree is: " << endl;
            	displaypreorder();
            }
            bool isEmpty() const { return root==NULL; }
            void outputVector(vector<int>);
            void displayinorder();
            void inorder(TreeNode*);
            void displaypreorder();
            void preorder(TreeNode*);
            void displaypostorder();
            void postorder(TreeNode*);
            void insert(int);
            void output(TreeNode*, vector<int>);
            void displayPath();
            int MaxDepth(TreeNode*);
            void displayMaxDepth();
            void displayLevelTraverse_Itr();
            vector<vector<int> > levelOrderBottom_Itr(TreeNode*);
    };