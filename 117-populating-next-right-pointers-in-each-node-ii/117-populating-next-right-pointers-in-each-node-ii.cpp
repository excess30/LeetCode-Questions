/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelOrder(Node * &root , queue<Node*> levelOd)
    {
        Node*x = NULL;
        Node * temp = root ;
        while(!levelOd.empty())
        {
            
            int size = levelOd.size();
            for(int i = 0 ; i < size ; i++)
            {
                temp = levelOd.front();
                levelOd.pop();
                if(!levelOd.empty())
                {
                    temp->next = levelOd.front();
                }
                else
                {
                    temp->next = x;   
                }
                if(temp->left)
                    levelOd.push(temp->left);
                if(temp->right)
                    levelOd.push(temp->right);
            }
            temp->next = x;
        }
    }
    Node* connect(Node* root) {
        if(root == NULL)
        {
            return root;
        }
        queue<Node*> levelOd;
        
        levelOd.push(root);
        levelOrder(root , levelOd);
        return root;
    }
};