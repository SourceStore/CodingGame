/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codingGameAscii.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:09:14 by rishchen          #+#    #+#             */
/*   Updated: 2017/09/28 18:29:00 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <ctype.h>
//#include <locale> 

using namespace std;

int	main()
{
	string ROW;
	string T;

	int size;
	int posAlpha;

	// cout << t << endl;
	// cout << posAlpha << endl;
	// cout << strlen(" #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### ") << endl;
/*
	" #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### 
     # # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   # 
     ### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ## 
	 # # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #       
	 # # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #  "
*/


	//ROW = " #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### # # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   # ### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ## # # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #       # # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #  ";
	char a = 'a';
	while (a <= 'z')
	{
		ROW += a;
		ROW += ' ';
		a++;
	}

	//cout << ROW << endl;
	//ROW = " #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ### # # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   # ### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ## # # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #       # # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #  ";

	// cout << size << endl;

	//cout << ROW << endl;

	//h = 0..H - 1
 	// (posAlpha + (h * (sl / 4)) * (size / h)- i * L;
	// 108 - i * L;
	// 216 - i * L;
	// 540
	int i;
		
	int	w;

	T = "AZ";
	// int L = 4;
	// int H = 5;
	int L = 2;
	int H = 1;
	locale loc;

	std::transform(T.begin(), T.end(), T.begin(), ::tolower);

	size = ROW.length();
	int j = 0;
	cout << T.length() << endl;
	for (int w = 0; w < T.length(); w++)
	{
		posAlpha = ((isalpha(T.at(w))) ? ((unsigned int)(T.at(w)) - 97) : 26);
		int h = 0;
		for (int i = 0; i < ((h + 1) * (size / H)); i++)
		{
			//cout << w << " " << T.at(w) << " "<< i << " posAlpha = " << posAlpha << endl;;//endl;
			if (i == (posAlpha * L) + (h * (size / H)))
			{
				//cout << w << " " << t.at(w) << " "<< i << " posAlpha = " << posAlpha << endl;;//endl;
				for (int j = 0; j < L; j++)
				{
					cout << ROW[i + j];
				}		
			}
			if (i % ((27 * L * (h + 1)) - 1) == 0 && i != 0)
			{
				w++;
				if (w != T.length())
					posAlpha = ((isalpha(T.at(w))) ? ((unsigned int)(T.at(w)) - 97) : 26);
				i = -1 + (h * (size / H)); 
			}
			if (w == T.length())
			{
				if (H != 1)
					h++;
				w = 0;
				posAlpha = ((isalpha(T.at(w))) ? ((unsigned int)(T.at(w)) - 97) : 26);
				cout << endl;
			}
			if (i + 1 == L * H * 27)
			{
				return (0);
			}
		}
	}

// for (int w = 0; w < t.length(); w++)
// {
// 	posAlpha = (unsigned int)(t.at(w)) - 97;
// 	int h = 0;
// 	//cout << posAlpha << " ";
// 	//cout << endl;
// 	for (int i = 0; i < size; ++i)
// 	{
// 		// cout << posAlpha << endl;
// 		// cout << (h * (size / H)) << endl;
// 		// cout << (posAlpha * 4) + (h * (size / H)) << " " << i << endl;
// 			// cout << "DING!\n";
// 		// cout << (posAlpha * 4) + (h * (size / H)) << endl;
// 		// cout << i << endl;
// 		if (i == (posAlpha * 4) + (h * (size / H)))
// 		{
// 			for (int j = 0; j < L; j++)
// 			{
// 				cout << ROW[i];
// 				i++;
// 			}		
// 		}
// 		if (i % (26 * L) == 0 && i != 0)
// 		{
// 			h++;
// 			cout << endl;
// 		}
// 	}
// }
	//cout << endl;
	return (0);
}