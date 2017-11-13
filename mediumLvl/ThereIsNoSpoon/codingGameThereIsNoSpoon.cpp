/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codingGameThereIsNoSpoon.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:54:35 by rishchen          #+#    #+#             */
/*   Updated: 2017/10/18 16:28:40 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef	struct answer
{
	int	x1, y1, x2, y2, x3, y3, width, height;
}				t_answer;

// void			recurFindConnecctions(vector<string> &array, t_answer &ans, int x, int y) {
// 	if (x + 1 != ans.width)
// 	{
// 		if (array[y][x + 1] == '0')
// 		{
// 			ans.x2 = x + 1;
// 			ans.y2 = y;
// 		}
// 		recurFindConnecctions(array, ans, x + 1, y);
// 	}
// 	if (y + 1 != ans.height)
// 	{
// 		if (array[y + 1][x] == '0')
// 		{
// 			ans.x3 = x;
// 			ans.y3 = y + 1;
// 		}
// 		recurFindConnecctions(array, ans, x, y + 1);
// 	}
// }

void			findConnections(vector<string> &array, t_answer &ans, int x, int y) {
		int 	x_copy;

		x_copy = x;
		x++;
		while (x < ans.width && array[y][x] != '0') {
			x++;
		}
		if (x < ans.width && array[y][x] == '0') {
			ans.x2 = x;
			ans.y2 = y;
		}
		x = x_copy;
		y++;
		while (y < ans.height && array[y][x] != '0') {
			y++;
		}
		if (y < ans.height && array[y][x] == '0') {
			ans.x3 = x;
			ans.y3 = y;
		}
}
	
// void			initAns(t_answer &ans, int width, int height) {

// 	ans = {-1, -1, -1, -1, -1, -1, width, height};
// }

int	main(){

	int width;
	int	height;
	vector<string> array;

	width = 3;
	height = 2;
	t_answer ans;// = {-1, -1, -1, -1, -1, -1, width, height};

	array.push_back("0");
	array.push_back("0");
	for (int i = 0; i <  ans.height; ++i) {
		for (int j = 0; j < ans.width; ++j) {
			ans = {-1, -1, -1, -1, -1, -1, width, height};
			if (array[i][j] == '0') {
				ans.x1 = j;
				ans.y1 = i;	
				findConnections(array, ans, j, i);
				cout << ans.x1 << " " << ans.y1 << " " << ans.x2 << " " << ans.y2 << " " << ans.x3 << " " << ans.y3 << endl;
			}
		}
	}
	return(0);
}