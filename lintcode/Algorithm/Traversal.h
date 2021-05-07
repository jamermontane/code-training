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

	//ǰ�����
	void preorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			path.push_back(root->val);
			preorder(root->left, path);
			preorder(root->right, path);
		}
	}

	//�������
	void inorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			inorder(root->left, path);
			path.push_back(root->val);
			inorder(root->right, path);
		}
	}

	//��������
	void postorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			postorder(root->left, path);
			postorder(root->right, path);
			path.push_back(root->val);
		}
	}

	//�ǵݹ�ǰ�����
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

	//�ǵݹ��������
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

	//�ǵݹ�������-����
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
			ans.emplace_back(cur->val);		//�洢���ڵ��ֵ
			if (cur->left != nullptr)
				s.push(cur->left);			//������Ӳ�Ϊ�գ���洢���ӵ�ֵ
			if (cur->right != nullptr)
				s.push(cur->right);			//����Һ��Ӳ�Ϊ�գ���洢�Һ��ӵ�ֵ
		}
		reverse(ans.begin(), ans.end());		//��ת���
		return ans;
	}
};

