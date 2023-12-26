#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int calmincos(vector<int>& sales, vector<vector<int>>& costmat)
{
    int totalcost = 0;
    for (int i = 0; i < sales.size() - 1; ++i)
    {
        if (costmat[sales[i]][sales[i + 1]] == INF)
        {
            return INF;
        }
        totalcost += costmat[sales[i]][sales[i + 1]];
    }

   totalcost += costmat[sales.back()][sales[0]];
    return totalcost;
}

void tspb(int j, vector<int>&sales, vector<bool>& visited, vector<vector<int>>& costmat, int& minDistance)
{
    if (sales.size() == costmat.size())
    {
        int totalcost = calmincos(sales, costmat);
        if (totalcost < minDistance)
        {
            minDistance = totalcost;
        }
        return;
    }


for (int i = 0; i<  costmat.size(); ++i)
    {
        if (!visited[i] &&  costmat[j][i] != INF)
        {
            visited[i] = true;
           sales.push_back(i);
           tspb(i, sales, visited,  costmat, minDistance);
            visited[i] = false;
            sales.pop_back();
        }
    }
}


int tsp(vector<vector<int>>&  costmat)
{
    int numCities =  costmat.size();
    int minDistance = INF;
    vector<int> sales;
    vector<bool> visited(numCities, false);


  sales.push_back(0);
    visited[0] = true;
    tspb(0,sales, visited,  costmat, minDistance);

    return minDistance;
}

int main()
{

    vector<vector<int>> distanceMatrix =
    {
        {0, 20, 10, 15},
        {20, 0, 25, 30},
        {10, 25, 0, 35},
        {15, 30, 35, 0}
    };

    int mincost = tsp(distanceMatrix);

        cout << "Minimum cost for travel the city: " << mincost << endl;


    return 0;
}


