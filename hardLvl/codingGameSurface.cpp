/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codingGameSurface.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:33:06 by rishchen          #+#    #+#             */
/*   Updated: 2017/10/12 17:29:42 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm> 

using namespace std;
	

/*
	####
	##O#
	#OO#
	####
*/

void	recurClearArea(vector<string> &array, int x, int y, int &count)
{
	if (array[y][x] == '$')
	{
		count--;
		array[y][x] = 'O';
	}

	if (x + 1 != 4 && array[y][x + 1] == '$')
		recurClearArea(array, x + 1, y, count);
	if (x != 0 && array[y][x - 1] == '$')
		recurClearArea(array, x - 1, y, count);
	if (y + 1 != 4 && array[y + 1][x] == '$')
		recurClearArea(array, x, y + 1, count);
	if (y != 0 && array[y - 1][x] == '$')
		recurClearArea(array, x, y - 1, count);
}

void	recurFindArea(vector<string> &array, int x, int y, int &count)
{
	if (array[y][x] == 'O')
	{
		count++;
		array[y][x] = '$';
	}
	else if (array[y][x] != 'O')
		return ;
	//cout << array[y][x] << "\t";
	if (x + 1 != 4 && array[y][x + 1] == 'O')
		recurFindArea(array, x + 1, y, count);
	if (x != 0 && array[y][x - 1] == 'O')
		recurFindArea(array, x - 1, y, count);
	if (y + 1 != 4 && array[y + 1][x] == 'O')
		recurFindArea(array, x, y + 1, count);
	if (y != 0 && array[y - 1][x] == 'O')
		recurFindArea(array, x, y - 1, count);
}

/*
OO###O
#O###O
#OO##O
####O#
##OO##
##OO##
*/

int		main(){
	static int c;
	vector<string> array;
	string test = "####";
	// array.push_back("####");
	// array.push_back("##O#");
	// array.push_back("#OO#");
	// array.push_back("##O#");
	// array.push_back("OOOO");
	// array.push_back("OOOO");
	// array.push_back("OOOO");
	// array.push_back("OOOO");

	array.push_back("OO###O");
	array.push_back("#O###O");
	array.push_back("#OO##O");
	array.push_back("####O#");
	array.push_back("##OO##");
	array.push_back("##OO##");


	c = 0;
	recurFindArea(array, 3, 3, c);
	cout << c << endl;
	recurClearArea(array, 3, 3, c);

	return (0);
}