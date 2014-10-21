#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
class ASTNode
{
public:
	ASTNode();
	~ASTNode();
	void setParent(ASTNode *parptr);
	void addChild(ASTNode *childptr);

	ASTNode* getParent();
	ASTNode* getChildAtIndex(int index);
private:
	vector<ASTNode*> childs;
	ASTNode *mparent = 0;

};

