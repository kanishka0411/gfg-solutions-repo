/*
Definition for Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	bool isLeaf(Node *root) {
		if (!root->left && !root->right)
			return true;
		return false;
	}
	void addLeftBoundary(Node *root, vector<int>&ans) {
		Node *curr = root->left;
		while (curr != nullptr) {
			if (!isLeaf(curr)) {
				ans.push_back(curr->data);
			}
			if (curr->left)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
	void addLeaf(Node* root, vector<int>&ans) {
		if (isLeaf(root)) {
			ans.push_back(root->data);
			return;
		}
		if (root->left)
			addLeaf(root->left, ans);
		if (root->right)
			addLeaf(root->right, ans);
	}
	
	void addRightBoundary(Node *root, vector<int>&ans) {
		Node *curr = root->right;
		vector<int>temp;
		while (curr) {
			if (!isLeaf(curr)) {
				temp.push_back(curr->data);
			}
			if (curr->right)
				curr = curr->right;
			else
				curr = curr->left;
		}
		
		for (int i = temp.size() - 1; i >= 0; i--) {
			ans.push_back(temp[i]);
		}
	}
	vector<int> boundaryTraversal(Node *root) {
		vector<int>ans;
		if (!root)
			return ans;
		if (!isLeaf(root))
			ans.push_back(root->data);
		addLeftBoundary(root, ans);
		addLeaf(root, ans);
		addRightBoundary(root, ans);
		return ans;
		
	}
};
