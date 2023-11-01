#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

class solution
{
public:
    vector<int> findMode(TreeNode *root)
    {

        unordered_map<int, int> frequency; // This is used to find the frequency of how many times an key is repeated.

        int maxCount = 0;
        vector<int> modes;
        inorder(root, modes, frequency, maxCount);
    }

private:
    void inorder(TreeNode *root, vector<int> &modes, unordered_map<int, int> &frequency, int &maxCount)
    {
        if (root)
        {

            inorder(root->left, modes, frequency, maxCount);

            frequency[root->val]++;
            int count = frequency[root->val];
            if (count > maxCount)
            {
                maxCount = count;
                modes.clear();
                modes.push_back(root->val);
            }
            else if (count == maxCount)
            {
                modes.push_back(root->val);
            }

            inorder(root->right, modes, frequency, maxCount);
        }
    }
};

int main()
{
    // I don't want to bother writting the main function.
    return 0;
}