#include "BSTree.h"

void BSTree::Inorder(vector<DataType> & i_ResultVector) {

	if (m_Root != nullptr)
		return m_Root->Inorder(i_ResultVector);
}

void BSTree::makeEmpty()
{
	BSTreeNode* root = m_Root;
	deleteTreeRec(root);
}
void BSTree::deleteTreeRec(BSTreeNode* node)
{
	if (node == NULL) return;

	/* first delete both subtrees */
	if(node->GetLeft() != NULL)
		deleteTreeRec(node->GetLeft());
	if (node->GetRight() != NULL)
		deleteTreeRec(node->GetRight());

	/* then delete the node */
	if (node != NULL)
		delete node;
}

bool BSTree::isEmpty()
{
	return (m_Root == NULL);
}
void BSTree::DeleteNodeInBST(int Key)// key id th Id
{
	BSTreeNode * temp = m_Root;
	this->m_Root = DeleteNodeInBSTRec(temp, Key);
}
BSTreeNode * BSTree::DeleteNodeInBSTRec(BSTreeNode* root, int Key)// key is the Id
{

	if (root == NULL) return root;
	else if (Key < root->Key())
		root->SetLeft(DeleteNodeInBSTRec(root->GetLeft(), Key));
	else if (Key > root->Key())
		root->SetRight(DeleteNodeInBSTRec(root->GetRight(), Key));
	else
	{
		//No child
		if (root->GetRight() == NULL && root->GetLeft() == NULL)
		{
			delete root;
			root = NULL;
		}
		//One child 
		else if (root->GetRight() == NULL)
		{
			BSTreeNode* temp = root;
			root = root->GetLeft();
			delete temp;
		}
		else if (root->GetLeft() == NULL)
		{
			BSTreeNode* temp = root;
			root = root->GetRight();
			delete temp;
		}
		//two child
		else
		{
			BSTreeNode* temp = FindMax(root->GetLeft());
			root->Data() = temp->Data();
			root->SetLeft(DeleteNodeInBSTRec(root->GetLeft(), temp->Key()));
		}
	}
	return root;
}

BSTreeNode* BSTree::FindMax(BSTreeNode* root)
{
	if (root == NULL)
		return NULL;

	while (root->GetRight() != NULL)
	{
		root = root->GetRight();
	}
	return root;
}
BSTreeNode * BSTree::Find(KeyType i_Key) {

	BSTreeNode * result = m_Root;

	while (result != nullptr) {
		if (i_Key == result->Key()) break;
		
		result = i_Key < result->Key() ? result->GetLeft() : result->GetRight();
	}

	return result;
}

void BSTree::Insert(KeyType i_Key, DataType i_Data, int &NumComp) {

	BSTreeNode * temp = m_Root;
	BSTreeNode * parent = nullptr;
	BSTreeNode * newNode;

	while (temp != nullptr) {
		
		parent = temp;
		NumComp++;
		if(i_Key < temp->Key()) temp = temp->GetLeft();
		else if (i_Key > temp->Key()) temp = temp->GetRight();
		else throw i_Key;
	}

	newNode = new BSTreeNode(i_Key, i_Data, nullptr, nullptr);

	if (parent == nullptr) m_Root = newNode;
	else if (i_Key < parent->Key()) parent->SetLeft(newNode);
	else parent->SetRight(newNode);
}



