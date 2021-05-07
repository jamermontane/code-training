#pragma once
#include <vector>
#include <stack>
using namespace std;

class TreeNode {

public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) 
	{
		this->val = val;
		this->left = this->right = NULL;

	}
};


class CTraversal
{
public:
	CTraversal();
	~CTraversal();

	//前序遍历
	void preorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			path.push_back(root->val);
			preorder(root->left, path);
			preorder(root->right, path);
		}
	}

	//中序遍历
	void inorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			inorder(root->left, path);
			path.push_back(root->val);
			inorder(root->right, path);
		}
	}

	//后续遍历
	void postorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			postorder(root->left, path);
			postorder(root->right, path);
			path.push_back(root->val);
		}
	}

	//非递归前序遍历
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> ans;
		if (root == nullptr)
			return ans;
		stack<TreeNode *> s;
		TreeNode *p = root;
		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				ans.push_back(p->val);
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
	}

	//非递归中序遍历
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> ans;
		if (root == nullptr)
			return ans;
		stack<TreeNode *> s;
		TreeNode *p = root;
		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				ans.push_back(p->val);
				s.pop();
				p = p->right;
			}
		}
	}

	//非递归后序遍历-迭代
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> ans;
		if (root == nullptr)
			return ans;
		stack<TreeNode *>s;
		s.push(root);
		while (!s.empty()) {
			auto cur = s.top();
			s.pop();
			ans.emplace_back(cur->val);		//存储根节点的值
			if (cur->left != nullptr)
				s.push(cur->left);			//如果左孩子不为空，则存储左孩子的值
			if (cur->right != nullptr)
				s.push(cur->right);			//如果右孩子不为空，则存储右孩子的值
		}
		reverse(ans.begin(), ans.end());		//反转结果
		return ans;
	}
};

