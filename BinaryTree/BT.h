    #include <iostream>
    #include <vector>
    using namespace std;
    class BT
    {
       private:
            struct node
            {
               node* left;
               node* right;
               int data;
            };
            node* root;
          public:
            BT()
            {
               root = NULL;
            }
            bool isEmpty() const { return root==NULL; }
            void displayinorder();
            void inorder(node*);
            void displaypreorder();
            void preorder(node*);
            void displaypostorder();
            void postorder(node*);
            void insert(int);
            void output(node*, vector<int>);
            void displayPath();
            int MaxDepth(node*);
            void displayMaxDepth();
    };