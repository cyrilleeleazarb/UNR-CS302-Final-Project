/* Cyrille Bernabe & David Lim
Traveling Sales Man Project
CS 302 
5/6/20
Professor Keith
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

float travelingSalesman(int miles[5][5], int col, vector<int>& city);

int bestPath[6] = {0};

int main()
{
    vector<int> City;

    //This 2D integer array contains the distances between each city.
    int distances[5][5] = {
        {0, 218, 518, 704, 439}, //Distances from Reno to the other cities (SF, Salt Lake City, Seattle, Vegas)
        {218, 0, 735, 807, 568},//Distances from SF to each of the other cities (Reno, Salt Lake, Seattle, Vegas)
        {518, 735, 0, 829, 421}, //Distances from Salt Lake City to each of the other cities (Reno, SF, Seattle, Vegas)
        {704, 807, 829, 0, 1114}, //Distances from Seattle to each of the other cities(Reno, SF, Salt Lake, Vegas)
        {439, 568, 421, 1114, 0}, //Distances from Las Vegas to each of the other cities (Reno, SF, Salt Lake, Seattle)
    };
    int column = 0;
    int pathWeight =  travelingSalesman(distances, column, City);
    cout << "Optimal Path (total miles): " << pathWeight << endl;
    cout << "Optimal Path: ";
    for (int i = 0 ; i < 5 ; ++i)
    {
        cout << bestPath[i] << "-->" ; 
    }

    cout << "0" << endl;
    cout << "Traveling cost with average gas prices (5/1/20): " << (pathWeight/40) * 2.35 << endl << endl;

    return 0;

}

//Function to solve TS problem, will return an float value that is the total amount of miles for the optimal path.
float travelingSalesman(int miles[5][5], int col, vector<int>& city)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        if( i != col)
        {
            city.push_back(i);
        }
    }

    int minimumPath = 100000;
    do
    {
        int row = col;
        int current = 10000;
        int cost = 0.0; 

        cout << "Start(0)" << "-->";

        for(int i = 0; i < city.size() ; i++)
        {
            cost += miles[row][city[i]];
            row = city[i];
            cout << row << "-->";
        }

        cout << "End(0)" << " Total: ";
        cost += miles[row][col];
        cout << cost << " " << endl;

        for (int i = 0 ; i < city.size(); i++)
        {
            if (cost < minimumPath)
            {
                bestPath[i+1] = city[i];
            }
        }

        minimumPath = min(minimumPath, cost);

    }
    while(next_permutation(city.begin(), city.end()));

    return minimumPath;


}