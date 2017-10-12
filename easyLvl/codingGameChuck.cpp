#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void    printAns(vector<int> &arr, int i, int count) {

    int toPrint;
    toPrint = arr[i - 1];
    if (toPrint == 0)
        cout << "00 ";
    else
        cout << "0 ";
    for (int i = 0; i < count; i++) {
        cout << 0;
    }
    if (i <= arr.size() - 1)
        cout << " ";
}

int main()
{
    vector<int> array;
    vector<int> answer;
    
    int chr;
    int counter;

    string MESSAGE = "Hello";
    for (int i = 0; i <= MESSAGE.size(); i++) {
        counter = 0;
        chr = (int)MESSAGE[i];
        while (chr > 0) {
            array.push_back(chr % 2);
            chr /= 2;
            counter++;
        }
        cout << counter << endl;
        if (counter != 7)
            array.push_back(0);
    }
    reverse(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i % 7 == 0)
            cout << endl;
    }
    cout << endl;

    for (int i = 1; i < array.size(); i++) {
        counter = 1;
        while (array[i] == array[i - 1] && i != array.size()) {
            counter++;
            i++;
        }
        printAns(array, i, counter);
        if (i % 7 == 0 || counter % 7 != 0)
            cout << endl;
        counter = 1;
    }
    cout << endl;
    return (0);
}