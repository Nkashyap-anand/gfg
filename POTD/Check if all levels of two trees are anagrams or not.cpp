#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        queue<Node *> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (true)
        {
            int size1 = q1.size();
            int size2 = q2.size();

            if (size1 != size2)
                return false;
            if (size1 == 0)
                break;

            vector<int> level_tree1, level_tree2;

            while (size1--)
            {
                Node *node1 = q1.front();
                q1.pop();
                if (node1->left)
                    q1.push(node1->left);
                if (node1->right)
                    q1.push(node1->right);
                level_tree1.push_back(node1->data);

                Node *node2 = q2.front();
                q2.pop();
                if (node2->left)
                    q2.push(node2->left);
                if (node2->right)
                    q2.push(node2->right);
                level_tree2.push_back(node2->data);
            }

            sort(level_tree1.begin(), level_tree1.end());
            sort(level_tree2.begin(), level_tree2.end());

            if (level_tree1 != level_tree2)
                return false;
        }

        return true;
    }
};

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}