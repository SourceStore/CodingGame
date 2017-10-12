#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <math.h>
#include <limits>
#include <string.h>

using namespace std;

#define EARTHRAD 6371

void split(const string &s, const char* delim, vector<string> & v){
    // to avoid modifying original string
    // first duplicate the original string and return a char pointer then free the memory
    char *dup = strdup(s.c_str());
    char *token = strtok(dup, delim);
    while(token != NULL){
        v.push_back(string(token));
        // the call is treated as a subsequent calls to strtok:
        // the function continues from where it left in previous invocation
        token = strtok(NULL, delim);
    }
    free(dup);
}


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    double  longitude;
    double  latitude;
    double  x;
    double  y;
    double  d;
    double  min;
    string  minName;
    vector<string> arrayOfNames;
    const char *delim = ";";
    string  lo_s;
    string  la_s;
    
    double  LOND;
    double  LATD;
    
    
    min = numeric_limits<double>::infinity();
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    LON = LON.replace(LON.find(','), 1, ".");
    LAT = LAT.replace(LAT.find(','), 1, ".");
    
    LOND = stod(LON, 0) * 180 / M_PI;
    LATD = stod(LAT, 0) * 180 / M_PI;
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        split(DEFIB, delim, arrayOfNames);
        lo_s = arrayOfNames[arrayOfNames.size()- 2];
        la_s = arrayOfNames[arrayOfNames.size()- 1];
        lo_s.replace(lo_s.find(','), 1, ".");
        la_s.replace(la_s.find(','), 1, ".");
        longitude = stod(lo_s, 0) * 180 / M_PI;
        latitude = stod(la_s, 0) * 180 / M_PI;
        x = (LOND - longitude) * cos((latitude + LATD) / 2);
        y = (LATD - latitude);
        d = sqrt(pow(x, 2) + pow(y, 2)) * EARTHRAD;
        if (d < min)
        {
            min = d;
            minName = arrayOfNames[1];
        }
        
        //clear buffer vector of names
        arrayOfNames.clear();
        vector<string>().swap(arrayOfNames);
    }

    cout << minName << endl;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}