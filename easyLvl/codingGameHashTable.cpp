#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef	struct 						s_node_openHashTable
{
	struct s_node_openHashTable 	*next;
	string 							fileExtation;
	string 							mimeType;
}									t_node;

typedef struct 						s_node_hashTable
{
	struct s_node_openHashTable		**head;
	struct s_node_openHashTable		**end;
}									t_nodeHT;

class HashTable
{
private:
	t_nodeHT nodes[256];	
public:
	HashTable();
	~HashTable();
	size_t 	hash(string data);
	void	inputNode(string fileExtation, string mimeType);
	t_node  *findNode(string data);
	void 	findAndPrint(string data);
	void	killKittens();
};

HashTable::HashTable()
{
	int 	i;

	i = -1;
	while (++i < 256)
	{
		nodes[i].head = NULL;
		nodes[i].end = NULL;
	}
}

HashTable::~HashTable()
{

}

void			HashTable::killKittens()
{
	t_node 		*currentKilling;
	t_node 		*nextKilling;
	int 		i;

	i = -1;
	while (++i < 256)
	{
		if ((nodes[i].head) != NULL)
		{
			currentKilling = *(nodes[i].head);
			while (currentKilling)
			{
				nextKilling = currentKilling->next;
				delete currentKilling;
				currentKilling = nextKilling;
			}
			delete nodes[i].end;
			delete nodes[i].head;
		}
	}
}
size_t 			HashTable::hash(string data)
{
	return(data.length() % 256);
}


void			HashTable::inputNode(string fileExtation, string mimeType)
{
	t_node 		*nodeForLink;
	size_t 		index;

	index = hash(fileExtation); 
	nodeForLink = new t_node;
	transform(fileExtation.begin(), fileExtation.end(), fileExtation.begin(), ::tolower);
	nodeForLink->fileExtation = fileExtation;
	nodeForLink->mimeType = mimeType;
	nodeForLink->next = NULL;
	if (nodes[index].head ==  NULL)
	{
		nodes[index].head = new t_node*;
		nodes[index].end = new t_node*;
		*(nodes[index].head) = nodeForLink;
		*(nodes[index].end) = nodeForLink;
	}
	else
	{
		(*(nodes[index].end))->next = nodeForLink;
		*(nodes[index].end) = nodeForLink;
	}
}

t_node 			*HashTable::findNode(string data)
{
	size_t 		index;
	t_node 		*searchingNode;

	index = hash(data);
	searchingNode = *(nodes[index].head);
	while (searchingNode)
	{
		if (searchingNode->fileExtation == data)
			return (searchingNode);
		searchingNode = searchingNode->next;
	}
	return (searchingNode);
}

void 			HashTable::findAndPrint(string data)
{
	size_t 		index;
	t_node 		*searchingNode;

	index = hash(data);
	searchingNode = *(nodes[index].head);
	while (searchingNode)
	{
		if (searchingNode->fileExtation == data)
		{
			cout << searchingNode->mimeType << endl;
			return ;
		}
		searchingNode = searchingNode->next;
	}
	cout << "UNKNOW" << endl; 
}

int 			main()
{
	t_node 		*myPreasure;
	string 		str;
	string 		str2;
	string 		buffer;
	HashTable 	hashTable;
	int 		pos;

	str = "A";
	str2 = "B";
	buffer = "anim.gif";
	hashTable.inputNode("jpg", "text/jpg");
	hashTable.inputNode("png", "image/png");
	transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
	pos = buffer.find(".");
	if (pos == -1)
		cout << "UNKNOW" << endl;
	else
	{
		string test = buffer.substr(pos + 1, buffer.length());
		//cout << test << endl;
		hashTable.findAndPrint(test);
	}
	// myPreasure = hashTable.findNode(str);
	// cout << myPreasure->data << endl;
	// myPreasure = hashTable.findNode(str2);
	// cout << myPreasure->data << endl;
	hashTable.killKittens();
	return (0);
}