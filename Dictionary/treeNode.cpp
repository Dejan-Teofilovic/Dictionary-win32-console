#include "treeNode.h"


treeNode::treeNode(string w,string m, string d)
{
	word = w;
	meaning = m;
	description = d;
	left = NULL;
	right = NULL;
}

void treeNode::setData(string w,string m, string d)
{
	word = w;
	meaning = m;
	description = d;
}
void treeNode::DisplayWordMeaning()
{
	cout << word << setw(20) << meaning << setw(20) << description << endl ;
}
string treeNode::getWord()
{
	return word;
}
string treeNode::getMeaning()
{
	return meaning;
}
string treeNode::getDescription()
{
	return description;
}
void treeNode::setLeft(treeNode *l)
{
	left = l;
}
void treeNode::setRight(treeNode *r)
{
	right = r;
}
treeNode* treeNode::getRight()
{
	return right;
}
treeNode* treeNode::getLeft()
{
	return left;
}

/* An algorithm produced by Professor Daniel J. Bernstein 
	and shown first to the world on the usenet newsgroup comp.lang.c. 
	It is one of the most efficient hash functions ever published. 
	*/
unsigned int DJBHash(string str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }
   return hash;
}


treeNode* FindMin(treeNode * T)
{
	if(T == NULL)
		return NULL;
	else if(T->getLeft() == NULL)
		return T;
	else 
		return FindMin(T->getLeft());
}

bool Find(treeNode* root, string wrd )
{
	if(root != NULL)
	{
		
		if(Find(root->getLeft(), wrd ) == true)	 return true;
		if(Find(root->getRight(), wrd ) == true) return true;
		if(wrd == root->getWord())
		{
			root->DisplayWordMeaning();	
			return true;
		}
		else
			return false;
		
	}
}

void Edit(treeNode* root, string wrd , string newWrd,  string mng, string des)
{
	if(root != NULL)
	{
		Edit(root->getLeft(),wrd,newWrd,mng,des);
		Edit(root->getRight(),wrd,newWrd,mng,des);
		if(wrd == root->getWord())
		{
     		// edit here
			root->setData(newWrd,mng,des);
		}
	}
}

void insert(treeNode* root, string wrd , string mng, string des)
{
	unsigned int d = 0 ;
	treeNode* Newnode = new treeNode(wrd, mng, des);
	treeNode *p,*q;
	p = q = root;
	d = DJBHash(wrd);
	while(d != DJBHash(p->getWord()) && q != NULL)
	{
		p = q;
		if(d < DJBHash(p->getWord()))
		{
			q = p->getLeft();
		}
		else
		{
			q = p->getRight();
		}
	
	}
		if(d == DJBHash(p->getWord()))
		{
			cout << endl << "dublicate value :" << p->getWord() << endl;
			 
		}
		else if(d < DJBHash(p->getWord()))
		{
			p->setLeft(Newnode);
		}
		else if(d > DJBHash(p->getWord()))
		{
			p->setRight(Newnode);
		}
}

void printDictionary(treeNode* root)
{
	if(root != NULL)
	{
		root->DisplayWordMeaning();
		printDictionary(root->getLeft());
		printDictionary(root->getRight());
	}
	
}

void DeleteDictionary(treeNode* root)
{
	if(root != NULL)
	{
		DeleteDictionary(root->getLeft());
		DeleteDictionary(root->getRight());
		delete root;
	}
}
treeNode* Delete(treeNode* root, string wrd)
{
	treeNode* tmpCell;
    if(root == NULL)
	{
		cout << "Element not found" << endl;
		return NULL;
	}
	else if(DJBHash(wrd) < DJBHash(root->getWord()))       // Go Left
		root->setLeft(Delete(root->getLeft(),wrd));
	else if(DJBHash(wrd) > DJBHash(root->getWord()))       // Go Right
		root->setRight(Delete(root->getRight(),wrd));

	else if(root->getLeft() && root->getRight())           // Two children
	{
		tmpCell = FindMin(root->getRight());
		root->setData(tmpCell->getWord(),tmpCell->getMeaning(),tmpCell->getDescription());
		root->setRight(Delete(root->getRight(),wrd));
	}
	else												   // one Child or zero   
	{
		tmpCell = root;
		if(root->getLeft() == NULL)
			root = root->getRight();
		else if(root->getRight() == NULL)
			root = root->getLeft();
		delete tmpCell;
	}

	return root;
}