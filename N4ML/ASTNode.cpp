#include "ASTNode.h"

// Constr. et Destr.
ASTNode::ASTNode()
{
}
ASTNode::~ASTNode()
{
}
// Fonctions de routine
void ASTNode::setParent(ASTNode *parptr)
{
	mparent = parptr;
}
void ASTNode::addChild(ASTNode *childptr)
{
	childs.push_back(childptr);
	childptr->setParent(this);
}
ASTNode* ASTNode::getParent()
{
	return mparent;
}
ASTNode* ASTNode::getChildAtIndex(int index)
{
	return childs[index];
}
//
