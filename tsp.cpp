#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

const int city = 10; // Number of cities
const int INFINITY = INT_MAX;

using namespace std;

vector<vector<int>> distanceMatrix(city + 1, vector<int>(city + 1, INFINITY)); // Matrix to store distances between cities
int Table[city + 1][1 << city]; // Memoization table for dynamic programming

int tsp(int j, int k, int numCities) {
    if (k == (1 << numCities) - 1) {
        return distanceMatrix[j][1]; // Return to the starting city if all cities are visited
    }

    if (Table[j][k] != 0) {
        return Table[j][k]; // Return the memoized result if available
    }

    int minCost = INFINITY;

    for (int i = 1; i <= numCities; ++i) {
        if (!(k & (1 << (i - 1)))) { // If city i is not visited
            int cost = distanceMatrix[j][i] + tsp(i, k | (1 << (i - 1)), numCities); // Recur for the next state
            minCost = min(minCost, cost); // Update the minimum cost
        }
    }

    return Table[j][k] = minCost; // Memoize the result and return
}

int main() {
    int numEdges, numNodes;
    cout << "Enter the number of edges and nodes: ";
    cin >> numEdges >> numNodes;
    cout << "Enter the cost between two cities:\n";
    for (int i = 0; i < numEdges; ++i) {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;
        distanceMatrix[city1][city2] = cost;
        distanceMatrix[city2][city1] = cost; // Update the distance matrix with input costs
    }

    int numCitiesToVisit = 3; // Number of cities to visit

    int optimalCost = tsp(1, 1, numCitiesToVisit); // Start the TSP calculation from city 1

    cout << "The minimum cost of visiting " << numCitiesToVisit << " cities: " << optimalCost << endl;

    return 0;
}
