


#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
using namespace std;



class Graph
{
private:

	vector< vector<int> > allEdges;
	vector<bool> visited;
	int cVertices;
	int maxVertices;
	vector<LinkedList*> lVertices;
	static const int NULL_EDGE = 0;
public:

//################################################# 
// @par Name 
//    Graph
// @purpose 
//   Default constructor that sets the size of the vertex list to 53
// @param [in] : 
//     None 
// @return 
//     none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	
	~Graph()
	{
		for (int i = 0; i < cVertices; i++)
		{
			delete lVertices[i];
		}
	}

	//################################################# 
// @par Name 
//   insert
// @purpose 
//   Inserts a city into the graph
// @param [in] : 
//     city
// @return 
//     none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 

	void insert(LinkedList* city)
	{
		lVertices[cVertices] = city;
		for (int i = 0; i < maxVertices; i++)
		{
			allEdges[cVertices][i] = NULL_EDGE;
			allEdges[i][cVertices] = NULL_EDGE;
		}
		cVertices++;
	}
	//################################################# 
// @par Name 
//    insertEdge
// @purpose 
//    inserts source destiantion and weight.
// @param [in] : 
//     source,dest,weight
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void insertEdge(int source, int dest, int weight)
	{
		int mgam;
		int mgg;

		mgam = getPos(lVertices[source]);
		mgg = getPos(lVertices[dest]);
		allEdges[mgam][mgg] = weight;
	}
	 
	int getW(int source, int dest)

	{
		int mgam;
		int mgg;

		mgam = getPos(lVertices[source]);
		mgg = getPos(lVertices[dest]);
		return allEdges[mgam][mgg];
	}
	
	int getPos(LinkedList* aV)
	{
		int i = 0;
		while (i < cVertices)
		{
			if (lVertices[i] == aV)
				return i;
			i++;
		}
		return -1;
	}

	//################################################# 
// @par Name 
//   clearC
// @purpose 
//    clears the list
// @param [in] : 
//     None 
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void clearC()
	{
		for (int i = 0; i < maxVertices; i++)
			visited[i] = false;
	}
	//################################################# 
// @par Name 
//    markV
// @purpose 
//     mark true when a node is visited
// @param [in] : 
//     city
// @return 
//      none 
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void markV(LinkedList* city)
	{
		int mcount = getPos(city);
		visited[mcount] = true;
	}
	//################################################# 
// @par Name 
//   isVisited
// @purpose 
//    to check if the node was visited or not
// @param [in] : 
//     city
// @return 
//      true or false
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	bool isVisited(LinkedList* city)

	{
		int index = getPos(city);
		if (visited[index] == true)
			return true;
		else
			return false;
	}
	 
	LinkedList* getAllUnVisited()
	{
		for (int i = 0; i < cVertices; i++)
		{
			if (visited[i] == false)
				return lVertices[i];
		}
		return NULL;
	}
	//################################################# 
// @par Name 
//    dfs
// @purpose 
//  to print items into the graph
// @param [in] : 
//     start
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	void dfs(LinkedList* start)
	{
		int mcount, mcounty;
		if (start == NULL) return;

		cout << start->cCity << " --> ";
		mcount = getPos(start);
		visited[mcount] = true;

		for (int i = 0; i < cVertices; i++)
		{
			mcounty = getPos(lVertices[i]);
			if (allEdges[mcount][mcounty] != NULL_EDGE)
			{
				if (visited[i] == false)
					dfs(lVertices[i]);
			}
		}
	}
	//################################################# 
// @par Name 
//    Graph
// @purpose 
//    Overloaded constructor that sets the size of the vertex list to the size passed to it
// @param [in] : 
//     size
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
	Graph(int size)
	{
		cVertices = 0;
		maxVertices = size;

		lVertices.resize(size);
		for (int i = 0; i < size; i++)
			lVertices[i] = NULL;

		visited.resize(size);

		int rows = size;
		int columns = size;
		allEdges.resize(rows, vector<int>(columns, 0));
	}







};
