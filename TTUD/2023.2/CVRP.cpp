#include <bits/stdc++.h>
using namespace std;

#define Max 101

int numCities, numTrucks, capacity;
int distances[Max], choices[Max], paths[Max], loads[Max];
int costs[Max][Max];
bool visitedCities[Max];
int minLastCost, minCurrentCost, numRoutes, currentSegments;
int minCost = 1e9;

void updateBestCost() {
    if (minCurrentCost != 0 && minCurrentCost < minLastCost)
    {
        minLastCost = minCurrentCost;
    }
}

bool checkPath(int city, int truck) {
    if (city > 0 && visitedCities[city])
    {
        return false;
    }
    if (loads[truck] + distances[city] > capacity)
    {
        return false;
    }
    return true;
}

void findPaths(int start, int truck) {
    if (start == 0)
    {
        if (truck < numTrucks)
        {
            findPaths(choices[truck + 1], truck + 1);
        }
        return;
    }
    for (int city = 0; city <= numCities; city++)
    {
        if (checkPath(city, truck))
        {
            paths[start] = city;
            visitedCities[city] = true;
            minCurrentCost += costs[start][city];
            loads[truck] += distances[city];
            currentSegments++;
            if (city > 0)
            {
                if (minCurrentCost + (numCities + numRoutes - currentSegments) * minCost < minLastCost)
                {
                    findPaths(city, truck);
                }
            }
            else
            {
                if (truck == numTrucks)
                {
                    if (currentSegments == (numCities + numRoutes))
                    {
                        updateBestCost();
                    }
                }
                else
                {
                    if (minCurrentCost + (numCities + numRoutes - currentSegments) * minCost < minLastCost)
                    {
                        findPaths(choices[truck + 1], truck + 1);
                    }
                }
            }
            visitedCities[city] = false;
            minCurrentCost -= costs[start][city];
            loads[truck] -= distances[city];
            currentSegments--;
        }
    }
}

bool checkChoice(int city, int truck) {
    if (city == 0)
    {
        return true;
    }
    if (loads[truck] + distances[city] > capacity)
    {
        return false;
    }
    if (visitedCities[city])
    {
        return false;
    }
    return true;
}

void exploreChoices(int truck) {
    int start = 0;
    if (choices[truck - 1] > 0)
    {
        start = choices[truck - 1] + 1;
    }
    for (int city = start; city <= numCities; city++)
    {
        if (checkChoice(city, truck))
        {
            choices[truck] = city;
            if (city > 0)
            {
                currentSegments++;
            }
            visitedCities[city] = true;
            minCurrentCost += costs[0][city];
            loads[truck] += distances[city];
            if (truck < numTrucks)
            {
                exploreChoices(truck + 1);
            }
            else
            {
                numRoutes = currentSegments;
                findPaths(choices[1], 1);
            }
            loads[truck] -= distances[city];
            visitedCities[city] = false;
            minCurrentCost -= costs[0][city];
            if (city > 0)
            {
                currentSegments--;
            }
        }
    }
}

void calculateMinCost() {
    minCurrentCost = 0;
    minLastCost = 1e9;
    choices[0] = 0;
    for (int city = 1; city <= numCities; city++)
    {
        visitedCities[city] = false;
    }
    exploreChoices(1);
    updateBestCost();
    cout << minLastCost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numCities >> numTrucks >> capacity;
    for (int i = 1; i <= numCities; i++)
    {
        cin >> distances[i];
    }
    for (int i = 0; i <= numCities; i++)
    {
        for (int j = 0; j <= numCities; j++)
        {
            cin >> costs[i][j];
            if (i != j && costs[i][j] < minCost)
            {
                minCost = costs[i][j];
            }
        }
    }

    calculateMinCost();

    return 0;
}
