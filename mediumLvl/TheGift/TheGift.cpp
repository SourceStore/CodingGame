#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
For example, the Oods wish to buy a gift that cost 100. The first Ood has a budget of 3, the second has a budget of 45 and the third has a budget of 100.

In that case:

Budget  Solution
3   3
45  45
100 52
Second example: they still wish to buy a gift that costs 100 but the second Ood has a budget of 100 this time.

In that case:

Budget  Solution
3   3
100 48
100 49

*/

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    int                 min_pay;
    std::vector<int>    money;
    std::vector<int>    ans;

    int N;
    cin >> N; cin.ignore();
    int C;
    cin >> C; cin.ignore();
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        money.push_back(B);
    }

    min_pay = C / N;
    std::sort(money.begin(), money.end());
    for (std::vector<int>::iterator it = money.begin(); it != money.end(); ++it) {

        if (*it < min_pay) {

            C -= *it;
            ans.push_back(*it);
            // std::cout << *it << std::endl;
        }
        else {

            C -= min_pay;
            ans.push_back(min_pay);
            // std::cout << min_pay << std::endl;
        }
        if (N != 1)
            N -= 1;
        min_pay = C / N;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (min_pay == 0)
        for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
            std::cout << *it << std::endl;
   else
    std::cout << "IMPOSSIBLE" << std::endl;
}