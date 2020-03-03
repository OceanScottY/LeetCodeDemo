//
// Created by Scott on 2019/12/28.
//

#include "TreeDemo.h"
#include <iostream>
#include <unordered_map>

using namespace std;
/*
 * 树是一种重要的非线性数据结构，广泛地应用于计算机技术的各个领域。采用树可以实现一些高效地查找算法，
 * 例如数据库系统中用到的红黑树等。
 * 树本身的定义是递归的，因此很多涉及到树的算法通常都可以用递归的方式来实现。然而递归算法在数据
 * 量较大的时候效率很低，所以通常会将递归改写成迭代算法。
 * 涉及到树的题目主要包括树的遍历，平衡二叉树，查找二叉树等。
 */



//Maximum Depth of Binary Tree
/** Problem 104
* 给定一个二叉树，找出其最大深度。
* 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
* 说明: 叶子节点是指没有子节点的节点。
* @param root
* @return
*/
#include <algorithm>

int maxDepth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }else if(root->left != NULL && root->right != NULL) {
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }else if(root->left != NULL){
        return maxDepth(root->left) + 1;
    }else {
        return maxDepth(root->right) + 1;
    }
}



int minDepth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }else if(root->left != NULL && root->right != NULL) {
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }else if(root->left != NULL){
        return minDepth(root->left) + 1;
    }else {
        return minDepth(root->right) + 1;
    }
}

/*
 * 例如，给出
 *      中序遍历 inorder = [9,3,15,20,7]
 *      后序遍历 postorder = [9,15,7,20,3]
 *      返回如下的二叉树：
                3
               / \
              9  20
                /  \
               15   7
 *
 *
 */
TreeNode* build(const unordered_map<int, int>& m, vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
    if(s0 > e0 || s1 > e1){
        return  NULL;
    }
    TreeNode* root = new TreeNode(postorder[e1]);

    int mid = m.at(postorder[e1]);
    int num = mid - s0;

    root->left = build(m, inorder, s0, mid - 1, postorder, s1, s1 + num - 1);
    root->right = build(m, inorder, mid + 1, e0, postorder, s1 + num, e1 - 1);

    return root;
}

TreeNode* buildYhy(const unordered_map<int, int>& m, vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
    if(s0 > e0 || s1 > e1){
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[e1]);

    int mid = m.at(postorder[e1]);
    int num = mid - s0;

    root->left = buildYhy(m, inorder, s0, mid -1, postorder, s1, s1 + num -1);
    root->right = buildYhy(m, inorder, mid + 1, e0, postorder, s1 + num, e1 - 1);

    return root;
}

#include <unordered_map>
TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder){
    unordered_map<int, int> m;
    if(postorder.empty()){
        return NULL;
    }
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]] = i;
    }
    return build(m, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}


/**
 * 根据前序和中序构造二叉树
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode* buildByPreAndIn(const unordered_map<int, int>& m, const vector<int>& preorder, const int& s0, const int& e0,
                            const vector<int>& inorder, const int& s1, const int& e1){
    if(s0 > e0 || s1 > e1){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[s0]);
    int mid = m.at(preorder[s0]);
    int num = mid - s1;

    root->left = buildByPreAndIn(m, preorder, s0 + 1, s0 + num , inorder, s1, mid - 1);
    root->right = buildByPreAndIn(m, preorder, e0 - num + 1, e0, inorder, mid + 1, e1);

    return root;
}

TreeNode* buildTreeByBeforAndIn(std::vector<int>& preorder, std::vector<int>& inorder){

    if(preorder.empty()){
        return NULL;
    }

    unordered_map<int, int> m;
    for (int i = 0; i < preorder.size(); i++){
        m[inorder[i]] = i;
    }

    return buildByPreAndIn(m, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}
/**
 * problem 107
 * @param root
 * @return
 */

// 心理学效应   48页
#include <queue>
#include <map>

void levelOrder(TreeNode* node, int level, vector<vector<int>>& res){
    if(!node)
        return;
    if(res.size() == level)
        res.push_back({});
    res[level].push_back(node->val);
    if(node->left)
        levelOrder(node->left, level+1, res);
    if(node->right)
        levelOrder(node->right, level+1, res);
}

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root){
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return vector<vector<int>>(res.rbegin(), res.rend());
}

/**
 * problem 102
 * @param root
 * @return
 */
std::vector<std::vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return vector<vector<int>>(res.begin(), res.end());
}

/**
 * problem 103
 * @param root
 * @return
 */
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> temp, res;
    levelOrder(root, 0, temp);
    for(int i = 0; i < temp.size(); i++){
        if(i%2 == 0){
            res.push_back(vector<int>(temp[i].begin(), temp[i].end()));
        }else{
            res.push_back(vector<int>(temp[i].rbegin(), temp[i].rend()));
        }
    }
    return res;
}

/**
 * problem 101   对称二叉树
 * @param root
 * @return
 */
bool help(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL)
        return true;
    else if(left == NULL || right == NULL)
        return false;
    bool r1 = (left->val == right->val);
    bool r2 = help(left->left, right->right);
    bool r3 = help(left->right, right->left);
    return r1&&r2&&r3;

}

bool isSymmetric(TreeNode* root){
    if(root == NULL)
        return true;
    return help(root->left, root->right);
}



/**
 * 相同的二叉树
 * @param p
 * @param q
 * @return
 */


bool isSameTree(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }else if (p == NULL || q == NULL){
        return true;
    }
    if(p->val != q->val){
        return false;
    }
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}


/**
 *  平衡二叉树
 *  给定一个二叉树，判断它是否是高度平衡的二叉树。本题中，
 *  一棵高度平衡二叉树定义为：
 *              一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * @param root
 * @return
 */
#include <math.h>

int height(TreeNode* node){
    if(node == NULL){
        return 0;
    }
    return max(height(node->left), height(node->right)) + 1;
}

bool isBalanced(TreeNode* root){
    if(root == NULL){
        return true;
    }
    if(abs(height(root->left) - height(root->right)) > 1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}



/**
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
 * 这条路径上所有节点值相加等于目标和。
 * @param root
 * @param sum
 * @return
 */

bool isPath(TreeNode* root, int sum){

}

bool DFS(TreeNode* root, int sum){
    if(root->left == NULL && root->right == NULL ){
        if(sum == root->val)
            return true;
        return false;
    }
    if(root->left != NULL && root->right != NULL){
        return DFS(root->left, sum - root->val) || DFS(root->right, sum - root->val);
    }else if(root->left != NULL){
        return DFS(root->left, sum - root->val);
    }else{
        return DFS(root->right, sum - root->val);
    }
}
bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL){
        return false;
    }
    return DFS(root, sum);
}


/**
 * problem 144
 * 给定一个二叉树，返回它的 前序 遍历。
 * @param root
 * @return
 */
#include <stack>
std::vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    if(root == NULL)
        return res;
    vector<TreeNode*> s;
    s.push_back(root);
    while(!s.empty()){
        TreeNode* temp = s.back();
        res.push_back(temp->val);
        s.pop_back();
        if(temp->right)
            s.push_back(temp->right);
        if(temp->left)
            s.push_back(temp->left);
    }
    return res;
}



/**
 * problem 94
 * 给定一个二叉树，返回它的中序 遍历。
 * @param root
 * @return
 */

void inorder(TreeNode* root, vector<int > &res){
    vector<TreeNode*> s;
    s.push_back(root);
    if(root->left != NULL){
        inorder(root->left, res);
    }
    res.push_back(root->val);
    s.pop_back();
    if(root->right != NULL){
        inorder(root->right, res);
    }
}

std::vector<int> inorderTraversal(TreeNode* root){
    vector<int > res;

    stack<TreeNode*> s;
    TreeNode* rt = root;

    while(!s.empty() || rt != NULL){
        while(rt != NULL){
            s.push(rt);
            rt = rt->left;
        }
        rt=s.top();
        s.pop();
        res.push_back(rt->val);
        rt=rt->right;
    }
    return res;
}


/**
 * problem 145
 * 给定一个二叉树，返回它的后序 遍历。
 * @param root
 * @return
 */
std::vector<int> postorderTraversal(TreeNode* root){
    vector<int> res;
    if(root == NULL)
        return res;
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        res.push_back(temp->val);
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
    }
    std::reverse(begin(res), end(res));
    return res;
}



/**
 *
 * problem 116
 * 给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 初始状态下，所有 next 指针都被设置为 NULL。
 * @param root
 * @return
 */
Node* connect(Node* root){
    if(root == NULL)
        return root;
    stack<Node*> node;
    node.push(root);
    while(!node.empty()){
        Node* temp = node.top();
        node.pop();
        if(temp->right != NULL && temp->left != NULL){
            node.push(temp->right);
            node.push(temp->left);
            node.top()->next = temp->right;
            if( temp->next != NULL){
                temp->right->next = temp->next->left;
            }
        }
    }
    return root;
}

/************************************************************************************************************************
 * 2020 - 01 -07
 * problem 116
 * @param root
 * @return
 */
Node* connect2(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* p = root;
    Node* first = NULL;
    Node* last = NULL;
    while(p){
        //设置下一层的第一个元素
        if(!first){
            if(p->left){
                first = p->left;
            }else if(p->right){
                first = p->right;
            }
        }

        if(p->left){
            //如果有last  则设置last的next
            if(last){
                last->next = p->left;
            }
            last = p->left;
        }

        if(p->right){
            if(last){
                last->next = p->right;
            }
            last = p->right;
        }

        if(p->next){
            p = p->next;
        }else{
            p = first;
            last = NULL;
            first = NULL;
        }
    }
    return root;
}

/**
 * problem 109
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 *
 *
 * 给定的有序链表： [-10, -3, 0, 5, 9],
    一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
          0
         / \
       -3   9
       /   /
     -10  5
 *
 *
 * @param head
 * @return
 */
TreeNode* buildTree(const vector<int> &vec, int start, int end){
    if(end < start){
        return nullptr;
    }
    int mid = (start + end)/2;
    TreeNode *root = new TreeNode(vec[mid]);
    if(mid - 1>= start){
        root->left = buildTree(vec, start, mid - 1);
    }
    if(mid + 1 <= end){
        root->right = buildTree(vec, mid + 1, end);
    }
    return root;
 }
TreeNode* sortedListToBST(ListNode* head){
    if(!head){
        return nullptr;
    }
    vector<int> sortedVec;
    ListNode *temp = head;
    while(temp){
        sortedVec.push_back(temp->val);
        temp = temp->next;
    }
    int mid = sortedVec.size()/2;
    TreeNode *root = new TreeNode(sortedVec[mid]);
    root->left = buildTree(sortedVec, 0, mid - 1);
    root->right = buildTree(sortedVec, mid + 1, sortedVec.size() - 1);
    return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums){
    if(nums.size() == 0){
        return nullptr;
    }
    int mid = nums.size()/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, 0, mid - 1);
    root->right = buildTree(nums, mid + 1, nums.size() - 1);
    return root;
}



/**
 * problem 113
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * @param root
 * @param sum
 * @return
 */
void searchPath(vector<vector<int>> &res, vector<int> temp, TreeNode* node, int sum){
    temp.push_back(node->val);
    if(!node->left && !node->right && (sum == node->val)){
        res.push_back(temp);
        return;
    }
    if(node->left){
        searchPath(res, temp, node->left, sum - node->val);
    }
    if(node->right){
        searchPath(res, temp, node->right, sum - node->val);
    }
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum){
    vector<vector<int>> res;
    if(!root){
        return res;
    }
    vector<int> cur;
    searchPath(res, cur, root, sum);
    return res;
}

/**
 * problem 114
 * 给定一个二叉树，原地将它展开为链表。
 * @param root
 */
void flatten(TreeNode* root){
    if(!root){
        return;
    }
    TreeNode *curr;
    curr = root;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *temp = s.top();
        s.pop();
        if(temp->right){
            s.push(temp->right);
            temp->right = nullptr;
        }
        if(temp->left){
            s.push(temp->left);
            temp->left = nullptr;
        }
        curr->right = temp;
        curr->left = nullptr;
        curr = curr->right;
        curr->right = nullptr;
    }
    root = root->right;
}



/**
 * problem 98
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 *      1、节点的左子树只包含小于当前节点的数。
 *      2、节点的右子树只包含大于当前节点的数。
 *      3、所有左子树和右子树自身必须也是二叉搜索树。
 *
 *  二叉搜索树的中序遍历应该是递增的。
 * @param root
 * @return
 */

bool isValidBST(TreeNode* root){
    vector<int> vec_val;

    stack<TreeNode*> s;
    TreeNode* rt = root;

    while(!s.empty() || rt != NULL){
        while(rt != NULL){
            s.push(rt);
            rt = rt->left;
        }
        rt=s.top();
        s.pop();
        //判断是否满足二叉搜索树
        if(!vec_val.empty()){
            if(rt->val <= vec_val.back()){
                return false;
            }
        }
        vec_val.push_back(rt->val);
        rt=rt->right;
    }
    return true;

}

/**
 * problem 99  恢复二叉搜索树 hard
 * 二叉搜索树中的两个节点被错误地交换。
 * 请在不改变其结构的情况下，恢复这棵树。
 *
 * @param root
 */
void recoverTree(TreeNode* root){
    if(!root){
        return;;
    }

    TreeNode* curr;
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
    TreeNode* preCurr;

    bool found = false;
    curr = root;
    while(curr){
        if(!curr->left){
            if(preCurr && preCurr->val > curr->val){
                if(!found){
                    first = preCurr;
                    found = true;
                }
                second = curr;
            }
            preCurr = curr;
            curr = curr->right;
        }else{
            pre = curr->right;
            while(pre->right && pre->right != curr){
                pre = pre->right;
            }
            if(!pre->right){
                pre->right = curr;
                curr = curr->right;
            }else{
//                记录first和second
                if(preCurr->val > curr->val){
                    if(!found){
                        first = preCurr;
                        found = true;
                    }
                    second = curr;
                }
                preCurr = curr;
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    if(first && second){
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
}


/**
 * problem 257
 * 给定一个二叉树，返回所有从根结点到叶子结点的路径
 * @param root
 * @return
 */
void DFS(TreeNode* node, vector<string> &paths, string path){

    if(!node)
        return;
    path = path + to_string(node->val) + "->";
    if(node->left){
        DFS(node->left, paths, path);
    }
    if(node->right){
        DFS(node->right, paths, path);
    }
    if(!node->left && !node->right){
        path = path.erase(path.size()-2, path.size());
        paths.push_back(path);
    }

}
std::vector<std::string> binaryTreePaths(TreeNode* root){
    vector<string> res;
    if(!root){
        return res;
    }
    string path("");

    DFS(root, res, path);
    return res;
}


/**
 * problem 129
 * 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 *
 * 例如，从根到叶子节点路径 1->2->3 代表数字 123。
 * 计算从根到叶子节点生成的所有数字之和。
 * @param root
 * @return
 */
void DFS(TreeNode* node, vector<int> &res, int sum){

    if(!node)
        return;
    sum = sum * 10 + node->val;
    if(node->left){
        DFS(node->left, res, sum);
    }
    if(node->right){
        DFS(node->right, res, sum);
    }
    if(!node->left && !node->right){
        res.push_back(sum);
    }

}
int sumNumbers(TreeNode* root){
    int res = 0;
    if(!root)
        return res;

    vector<int> sums;
    DFS(root, sums, 0);

    for(auto it = sums.begin(); it != sums.end(); it++){
        res += *it;
    }
    return res;
}
