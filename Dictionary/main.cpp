#include"treeNode.h"

int main()
{
	string key , key2;
	string arrayW[] = {"aback","Abaddon","abrupt","accuracy","acme","ADC","adit","0"};
	string arrayM[] = {"behind","hell","sudden and unexpected","exactness or precision","the highest point or period (of achievement, success etc.)","analogue-digital converter","a horizontal entrance or passage in a mine","0"};
	string arrayD[] = {"adjective","noun","adjective","noun","noun","abberivation","noun","0"};
	treeNode *tmp;
	treeNode *root = new treeNode(arrayW[0],arrayM[0],arrayD[0]);
	for(int i=1 ; arrayW[i]!= "0" ; i++)
	{
		insert(root,arrayW[i],arrayM[i],arrayD[i]);
	}
	
	printDictionary(root);

	do
	{
		cout << endl;
		cout << "press i to insert " << endl; 
	    cout << "      e to edit " << endl; 
		cout << "      d to delete" << endl;
		cout << "      s to show dictionary " << endl; 
		cout << "      f to find word" << endl;
		cout << "      exit to exit" << endl;
		//cin >> key;
		getline(cin,key);
		if(key == "e")
		{
			string m,d;
			cout << "enter Toreplace :    ";
			getline( cin,key);
			cout << "enter replaceWith :    ";
			getline( cin,key2);
			cout << "enter meaning :    ";
			getline( cin,m);
			cout << "enter description :    ";
			getline( cin,d);
			Edit(root, key , key2,m, d);
		}
		else if(key == "i")
		{
			cout << "enter new Value :    ";
			getline( cin,key2);
			insert(root,key2,key2,key2);
		}
		else if(key == "d")
		{
			cout << "enter Value To delete :    ";
			getline(cin,key2);
			if((root = Delete(root,key2)) != NULL)
				cout << "successfully deleted : " << key2 << endl; 
		}
		else if(key == "s")
		{
			
			printDictionary(root);
		}
		else if(key == "f")
		{
			getline(cin, key2);
			if(!Find(root, key2 ))
				cout << key2 << " not founded" << endl ;
		}

	}while(key != "exit");
	DeleteDictionary(root);
	return 0;
}