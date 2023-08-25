

#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
#include "Graph.h"

using namespace std;

int main()
{
	Graph adgGragh(53);
	LinkedList* rCity;
	LinkedList* bCity;


	rCity = new LinkedList("New York");
	adgGragh.insert(rCity);
	bCity = new LinkedList("Los Angeles");
	adgGragh.insert(bCity);
	bCity = new LinkedList("San Francisco");
	adgGragh.insert(bCity);
	bCity = new LinkedList("Riverside");
	adgGragh.insert(bCity);


	adgGragh.insertEdge(0, 1, 1);
	adgGragh.insertEdge(0, 2, 1);
	adgGragh.insertEdge(1, 3, 1);
	adgGragh.insertEdge(3, 2, 1);


	adgGragh.clearC();
	adgGragh.dfs(rCity);

	cout << endl;


	adgGragh.clearC();


	return 0;
}