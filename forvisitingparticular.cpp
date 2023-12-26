#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

const int city= 10;
const int INFINITY = INT_MAX;

using namespace std;

vector<vector<int>> distanceMatrix(city + 1,vector<int>(city + 1, INFINITY));
int Table[city+ 1][1 <<city];

int tsp(int j, int k, int numCities) {
    if (k == (1 << numCities) - 1) {
        return distanceMatrix[j][1];

    if (Table[j][k] != 0) {
        return Table[j][k];
    }

    int minCost = INFINITY;

    for (int i = 1; i <= numCities; ++i) {
        if (!(k & (1 << (i - 1)))) {
            int cost = distanceMatrix[j][i] + tsp(i,k| (1 << (i- 1)), numCities);
            minCost =min(minCost, cost);
        }
    }

    return Table[j][k] = minCost;
}  }

int main() {
    int numEdges, numNodes;
   cout << "Enter the number of edges and nodes: ";
    cin >> numEdges >> numNodes;
   cout << "Enter the cost between two cities:\n";
    for (int i = 0; i < numEdges; ++i) {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;
        distanceMatrix[city1][city2] = cost;
        distanceMatrix[city2][city1] = cost;
    }

    int num = 3;

    int optimalCost = tsp(1, 1, num);

  cout << "The minimum cost of visiting " << num << " cities: " << optimalCost <<endl;

    return 0;
}

