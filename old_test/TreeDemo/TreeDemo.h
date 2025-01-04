//
// Created by Scott on 2019/12/28.
//
#ifndef LEETCODEDEMO_TREEDEMO_H
#define LEETCODEDEMO_TREEDEMO_H


#include <iostream>
// P41  Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//2019-12-31
/** Problem 104
 * 给定一个二叉树，找出其最大深度。
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 说明: 叶子节点是指没有子节点的节点。
 * @param root
 * @return
 */
int maxDepth(TreeNode* root);


/**
 * Problem 111
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 例如，给出
 *      中序遍历 inorder = [9,3,15,20,7]
 *      后序遍历 postorder = [9,15,7,20,3]
 *    返回如下的二叉树：
                3
               / \
              9  20
                /  \
               15   7
 *
 *
 */
int minDepth(TreeNode* root);

/**
 * problem 106
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 */
#include <vector>
TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);

/**
 * problem 105
 * 根据一棵树的中序遍历与前序遍历构造二叉树
 * @param preorder
 * @param inorder
 * @return
 */
TreeNode* buildTreeByBeforAndIn(std::vector<int>& preorder, std::vector<int>& inorder);


/**
 * problem 107
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 */

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root);


/**
 * problem 102
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 */

std::vector<std::vector<int>> levelOrder(TreeNode* root);

/**
 * problem 103
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 */
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);

/**
 *  2020-01-02
 *
 * problem 101
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
        1
       / \
      2   2
     / \ / \
    3  4 4  3
 * @param root
 * @return
 */
bool isSymmetric(TreeNode* root);

/**
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 如果两个树在结构上相同，并且节点具有相同的值，
 * 则认为它们是相同的。
 * @param p
 * @param q
 * @return
 */
bool isSameTree(TreeNode* p, TreeNode* q);


/**
 *  平衡二叉树
 *  给定一个二叉树，判断它是否是高度平衡的二叉树。本题中，
 *  一棵高度平衡二叉树定义为：
 *              一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * @param root
 * @return
 */
bool isBalanced(TreeNode* root);


/**
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
 * 这条路径上所有节点值相加等于目标和。
 * @param root
 * @param sum
 * @return
 */
bool hasPathSum(TreeNode* root, int sum);

/**  2020-01-06
 * problem 144
 * 给定一个二叉树，返回它的 前序 遍历。
 * @param root
 * @return
 */
std::vector<int> preorderTraversal(TreeNode* root);

/**
 * problem 94
 * 给定一个二叉树，返回它的中序 遍历。
 * @param root
 * @return
 */
std::vector<int> inorderTraversal(TreeNode* root);

/**
 * problem 145
 * 给定一个二叉树，返回它的后序 遍历。
 * @param root
 * @return
 */
std::vector<int> postorderTraversal(TreeNode* root);

/**
 * 2020 - 01 -07
 * problem 116
 * 给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 初始状态下，所有 next 指针都被设置为 NULL。
 * @param root
 * @return
 */
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};
Node* connect(Node* root);

Node* connect2(Node* root);


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * problem 109
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * @param head
 * @return
 */
TreeNode* sortedListToBST(ListNode* head);

/**
 * problem 108
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * @param nums
 * @return
 */
TreeNode* sortedArrayToBST(std::vector<int>& nums);

/**
 * problem 113
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * @param root
 * @param sum
 * @return
 */
std::vector<std::vector<int>> pathSum(TreeNode* root, int sum);


/**
 * problem 114
 * 给定一个二叉树，原地将它展开为链表。
 * @param root
 */
void flatten(TreeNode* root);



/**
 * problem 98
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 假设一个二叉搜索树具有如下特征：
 *      1、节点的左子树只包含小于当前节点的数。
 *      2、节点的右子树只包含大于当前节点的数。
 *      3、所有左子树和右子树自身必须也是二叉搜索树。
 * @param root
 * @return
 */
bool isValidBST(TreeNode* root);




/**
 * problem 99  恢复二叉搜索树 hard
 * 二叉搜索树中的两个节点被错误地交换。
 * 请在不改变其结构的情况下，恢复这棵树。
 *
 * @param root
 */
void recoverTree(TreeNode* root);


/**
 * problem 257
 * 给定一个二叉树，返回所有从根结点到叶子结点的路径
 * @param root
 * @return
 */
std::vector<std::string> binaryTreePaths(TreeNode* root);

/**
 * problem 129
 * 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 *
 * 例如，从根到叶子节点路径 1->2->3 代表数字 123。
 * 计算从根到叶子节点生成的所有数字之和。
 * @param root
 * @return
 */
int sumNumbers(TreeNode* root);




#endif //LEETCODEDEMO_TREEDEMO_H
