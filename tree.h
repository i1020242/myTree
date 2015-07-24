#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class cBST
{
	private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};
	node *root;
	void addLeafPrivate(int key, node* Ptr);
	void printOrderPrivate(node *Ptr);
	void printPreOrderPrivate(node *Ptr);
	node* ReturnPtrToNodePrivate(int key, node* Ptr);
	int FindSmallestKeyPrivate(node *Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);

	//public
	public:
	cBST();
	node *createLeaf(int key);
	void addLeaf(int key);
	void printOrder();
	void printPreOrder();
	node* ReturnPtrToNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallestKey();
	void RemoveNode(int key);
};
#endif // TREE_H_INCLUDED
