#include "BSTreeNode.h"

void BSTreeNode::Inorder(vector<DataType> & i_ResultVector) {
	
	if (m_Left != nullptr) m_Left->Inorder(i_ResultVector);
	i_ResultVector.push_back(m_Data);
	if (m_Right != nullptr) m_Right->Inorder(i_ResultVector);
}

void BSTreeNode::Preorder(vector<DataType> & i_ResultVector) {

	i_ResultVector.push_back(m_Data);
	if (m_Left != nullptr) m_Left->Inorder(i_ResultVector);
	if (m_Right != nullptr) m_Right->Inorder(i_ResultVector);
}

void BSTreeNode::Postorder(vector<DataType> & i_ResultVector) {

	if (m_Left != nullptr) m_Left->Inorder(i_ResultVector);
	if (m_Right != nullptr) m_Right->Inorder(i_ResultVector);
	i_ResultVector.push_back(m_Data);
}
