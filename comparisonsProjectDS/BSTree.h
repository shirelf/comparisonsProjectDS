#pragma once
#include "BSTreeNode.h"
#include <vector>
#include "Student.h"

typedef long KeyType;
typedef Student DataType;

class  BSTree {

private:
	BSTreeNode * m_Root;
public:
	BSTree() { m_Root = nullptr; }
	~BSTree() {
		
		if (m_Root != nullptr) delete m_Root;
	}
	BSTreeNode * Find(KeyType i_Key);
	void Insert(KeyType i_Key, DataType i_Data, int &NumComp);
	
	void Inorder(vector<DataType> & i_ResultVector);
	void deleteTreeRec(BSTreeNode * node);
	void makeEmpty();
	bool isEmpty();
	void DeleteNodeInBST(int Key);
	BSTreeNode * DeleteNodeInBSTRec(BSTreeNode * root, int Key);
	BSTreeNode * FindMax(BSTreeNode * root);

};

