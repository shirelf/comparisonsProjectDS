//#pragma once
//#include <vector>
//#include "Person.h"
//
//using namespace std;
//
//typedef long KeyType;
//typedef Person DataType;
//
//class BSTreeNode {
//
//private:
//	KeyType m_Key;
//	DataType m_Data;
//	BSTreeNode * m_Left;
//	BSTreeNode * m_Right;
//
//public:
//	BSTreeNode() {
//
//		m_Left = m_Right = nullptr;
//		//m_Data = 0;
//	}
//	BSTreeNode(KeyType i_Key, DataType i_Data, BSTreeNode * i_Left, BSTreeNode * i_Right) 
//		: m_Key{ i_Key }, m_Data{ i_Data }, m_Left{ i_Left }, m_Right{ i_Right }{}
//	~BSTreeNode() {
//
//		if (m_Left != nullptr) delete m_Left;
//		if (m_Right != nullptr) delete m_Right;
//	}
//	KeyType Key() { return m_Key; }
//	DataType Data() { return m_Data; }
//	BSTreeNode * GetLeft() { return m_Left; }
//	BSTreeNode * GetRight() { return m_Right; }
//	void SetLeft(BSTreeNode * i_NodeToSet) { m_Left = i_NodeToSet; }
//	void SetRight(BSTreeNode * i_NodeToSet) { m_Right = i_NodeToSet; }
//	void Inorder(vector<DataType> & i_ResultVector);
//	void Preorder(vector<DataType> & i_ResultVector);
//	void Postorder(vector<DataType> & i_ResultVector);
//};
