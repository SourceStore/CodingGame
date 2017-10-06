#include <stdio.h>
#include <iostream>

using namespace std;
int 	main()
{

    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    
	lightX = 2;
	lightY = 2;
	initialTX = 0;
	initialTY = 1;

    int diffX = lightX - initialTX;
    int diffY = lightY - initialTY;

    /////////////////
    //            T //
    //             //
    //             //
    //       L      //
    /////////////////


    cout << diffX << ' '<< diffY << endl;
    while (diffX || diffY)
    {
    	if (diffX && diffY)
    	{
    		if (diffX > 0 && diffY > 0)
    		{
    			cout << "SE" << endl;
                diffX--;
                diffY--;
    		}
            else if (diffX < 0 && diffY < 0)
            {
                cout << "NW" << endl;
                diffX++;
                diffY++;
            }
            else if (diffX > 0 && diffY < 0)
            {
                cout << "NE" << endl;
                diffX--;
                diffY++;
            }
            else if (diffX < 0 && diffY > 0)
            {
                cout << "SW" << endl;
                diffX++;
                diffY--;
            }
    	}
        else if (diffX && !diffY)
        {
            if (diffX > 0)
            {
                cout << "E" << endl;
                diffX--;
            }
            else
            {
                cout << "W" << endl;
                diffX++;
            }
        }
        else if (!diffX && diffY)
        {
            if (diffY > 0)
            {
                cout << "S" << endl;
                diffY--;
            }
            else
            {
                cout << "N" << endl;
                diffY++;
            }
        }  
    }
    return (0);
}