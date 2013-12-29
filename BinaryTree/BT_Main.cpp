#include "BT.h"
#include "iostream"
using namespace std;

int main()
    {
        BT b;
        int ch,tmp,num;
        vector<int> myvector;
            cout << "Enter number of nodes: ";
            cin >> num;
            for(int i=0; i<num; i++)
            {
                cout <<endl;
                cout << "Enter node: ";
                cin >> tmp;
                b.insert(tmp);
            }
            choice:
            cout <<endl<<endl;
            cout << "Enter your choice: ";
            cout << "[1] In-order Traversal" <<endl;
            cout << "[2] Pre-order Traversal" <<endl;
            cout << "[3] Post-order Traversal" <<endl;
            cout << "[4] Output Paths from root to leaves";
            cout << "[5] Output the maximum depth of the tree" <<endl;
            cout << "[6] Exit" <<endl;
            cin >> ch;
           switch(ch)
           {
               case 1: 
                   cout<<endl;
                   cout<<" In-Order Traversal "<<endl;
                   b.displayinorder();
                   break;
               case 2: 
                   cout<<endl;
                   cout<<" Pre-Order Traversal "<<endl;
                   b.displaypreorder();
                   break;
               case 3: 
                   cout<<endl;
                   cout<<" Post-Order Traversal "<<endl;
                   b.displaypostorder();
                   break;
               case 4:
                   cout<<endl;
                   cout<<" Output Paths from root to leaves: "<<endl;

                   b.displayPath();
               case 5:
               	   cout<<endl;
               	   cout<<" Output the maximum depth of the tree: "<<endl;
               	   b.displayMaxDepth();
               case 6: 
                   return 0;
                   break;
               default:
                   cout << "Invalid entry. Try Again";
                   goto choice;
                   break;                
           }
        return 0;
    }