#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

typedef struct		s_tree
{
	// std::string		number;
	int				n;
	char			*c;
	struct	s_tree	*left;
	struct	s_tree	*rigth;
}					t_tree;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void		init_tree(std::vector<t_tree *> & tree, std::vector<std::string> & numbers) {

	t_tree	*node = new t_tree;
	t_tree	*current;

	node->n = numbers[0][0];
	tree.push_back(node);
	for (unsigned int i = 1; i < numbers[0].size(); i++) {

		t_tree *node_buff = new t_tree{static_cast<int>(numbers[0][i]), NULL, NULL};
		if (node->n < static_cast<int>(numbers[0][i])) {

			node->rigth = node_buff;
			node = node->rigth;
		}
		else {
			node->left = node_buff;
			node = node->left;
		}
		// delete node_buff; wtf?
	}
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

	std::vector<t_tree *>			tree;
	std::vector<std::string>	numbers;

    int N;
    std::cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        std::string telephone;
        std::cin >> telephone; std::cin.ignore();
        numbers.push_back(telephone);
    }

    std::sort(numbers.begin(), numbers.end());
    //std::reverse(numbers.begin(), numbers.end());

    init_tree(tree, numbers);

    t_tree *node = tree[0];

    while (node) {

    	std::cout << node->n << std::endl;
    	if (node->left)
    		node = node->left;
    	else
    		node = node->rigth;
    }
	// for (std::vector<std::string>::iterator it = numbers.begin(); it != numbers.end(); it++)
			// std::cout << *it << std::endl;

	

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // The number of elements (referencing a number) stored in the structure.

    return (0);
}