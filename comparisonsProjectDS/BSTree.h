#pragma once
#include "BSTreeNode.h"
#include <vector>
#include "Person.h"

typedef long KeyType;
typedef Person DataType;

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
	void Delete(KeyType i_Key, DataType i_Data);
	KeyType Min();
	KeyType Max();
	void Inorder(vector<DataType> & i_ResultVector);
	void Preorder(vector<DataType> & i_ResultVector);
	void Postorder(vector<DataType> & i_ResultVector);

};

