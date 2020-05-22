//#include "BSTree.h"
//
//void BSTree::Inorder(vector<DataType> & i_ResultVector) {
//
//	if (m_Root != nullptr)
//		return m_Root->Inorder(i_ResultVector);
//}
//
//void BSTree::Preorder(vector<DataType> & i_ResultVector) {
//
//	if (m_Root != nullptr)
//		return m_Root->Preorder(i_ResultVector);
//}
//
//void BSTree::Postorder(vector<DataType> & i_ResultVector) {
//
//	if (m_Root != nullptr)
//		return m_Root->Postorder(i_ResultVector);
//}
//
//BSTreeNode * BSTree::Find(KeyType i_Key) {
//
//	BSTreeNode * result = m_Root;
//
//	while (result != nullptr) {
//		if (i_Key == result->Key()) break;
//		
//		result = i_Key < result->Key() ? result->GetLeft() : result->GetRight();
//	}
//
//	return result;
//}
//
//void BSTree::Insert(KeyType i_Key, DataType i_Data, int &NumComp) {
//
//	BSTreeNode * temp = m_Root;
//	BSTreeNode * parent = nullptr;
//	BSTreeNode * newNode;
//
//	while (temp != nullptr) {
//		
//		parent = temp;
//		NumComp++;
//		if(i_Key < temp->Key()) temp = temp->GetLeft();
//		else if (i_Key > temp->Key()) temp = temp->GetRight();
//		else throw i_Key;
//	}
//
//	newNode = new BSTreeNode(i_Key, i_Data, nullptr, nullptr);
//
//	if (parent == nullptr) m_Root = newNode;
//	else if (i_Key < parent->Key()) parent->SetLeft(newNode);
//	else parent->SetRight(newNode);
//}
//
//void BSTree::Delete(KeyType i_Key, DataType i_Data) {
//
//}
//
