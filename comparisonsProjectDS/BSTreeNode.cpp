#include "BSTreeNode.h"

//this function inserts the tree Inorder into a vector 
void BSTreeNode::Inorder(vector<DataType> & i_ResultVector) {
	
	if (m_Left != nullptr) m_Left->Inorder(i_ResultVector);
	i_ResultVector.push_back(m_Data);
	if (m_Right != nullptr) m_Right->Inorder(i_ResultVector);
}

