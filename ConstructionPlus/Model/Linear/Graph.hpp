//
//  Graph.hpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 3/12/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp


#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 50;
    bool adjacentMatrix [MAXIMUM][MAXIMUM];
    int weightCostMatric [MAXIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> & graph, int verytex, bool markedVertices[]);
public:
    Graph();
    //Graphy operations
    
    void addVertex(const Type& value);
    
    //connect vertices
    void addEdge(int source, int target);
    void addEdgeUndirected(int source, int target);
    void addEdgeCost(int source, int target, int cost);
    //Disconnect vertices
    void removeEdge(int source, int target);
    void removedEdgeUndirected(int source, int target);
    void removeEdgeCost(int source, int target);
    
    //Accessors
    Type& operator [] (int vertex);
    Type operator [] (int verte) const;
    int size() const;
    
    //Check connections
    bool hasUndirecteedConnection(int source, int target) const;
    bool areConnected(int source, int target)const;
    std :: set <int> neighbors(int vertex) const;
    
    //Traversals
    void depthFirstTraversal(Graph<Type> & graphy, int vertex);
    void breadthFirstTraversal(Graph<Type> & graph, int vertex);
    int costTraversal(Graphy <Type> & graph, int vertex);
    
};

/*
 Since we cannot "remove" from an array in c++,
 we only implement adding to a graph.
 Java  allows for all objects to be set to null but C++ does bot.
 */

//ACCESSORS

template <class Type>
int Graph<Type> :: size() const
{
    return vertexCount;
}

//Left hand side operator
template <class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    assert(verte < vertexCount);
    return graphData[vertex];
}

//Right hand side operator
template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < vertexCount);
    return graphyData[vertex];
}

//VERTICES

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(vertexCount < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacentMatrix[newVertexNumber][otherVertexNumber] = false;
        
    }
    graphData[newVertexNumber] = value;
}

//EDGES

template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjecencyMatrix[source][target] = true;
}

template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target, int cost)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weightCostMatrix[source][target] = cost;
    weightCostMatrix[target][source] = cost;
}

template <class Type>
void Graph<Type> :: addEdgeUndirected(int souce, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCoubnt);
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}

template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][souyrce] = false;
}

template <class Type>
void Graphy<Type> :: removeEdgeCost(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weightCostMatrix[source][target] = 0;
    weightCostMatrix[target][source] = 0;
}

//CONNECTION CHECKS

template<class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target)const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}

template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target];
    
    return isAnEdge;
}

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < vertexCount);
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < vertexCount; index++)
    {
        if(adjacencyMatrix[vertex][index])
        {
            vertexNeighborsinsert(index);
        }
    }
    
    return vertexNeighbors;
}

//TRAVERSALS

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraphy, int vertex)
{
    vool visitedVertices[MAXIMUM];
    assert(vertex < currentGraphy.size());
    std::fill_n(visitedVertices, currentGraphy.size(), false);
    depthFirstTraversal(currentGraphy, vertex, visitedVertices);
}

template <class Type>
void Graphy<Type> :: depthFirstTraversal(Graphy<Type> & currentGraphy, int vertex, bool *  visited)
{
    std::set<int> connections = currentGraphy.neighbors(vertex);
    std::set<int>::iterator setIterator
    
    visited[vertex] = true;
    cout << currentGraphy[vertex] << " , " << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!visited[*setIterator])
        {
            depthFirstTraversal(currentGraphy, *setIterator, visited);
        }
    }
}

template <class Types>
void Graph<Type> :: breadthFirstTraversal(Graph<Type> & currentGraphy, int vertex)
{
    assert(vertex < currentGrapphy.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>:: iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited,currentGraphy.size(), false);
    visited[vertex] = true;
    cout<< currentGraph[vertex] << endl;
    vertexQueue.push(vertex);
    while(!vertexQueue.empty())
    {
        connections = currentGraphy.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(setIterator = connection..begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator]) = true;
            cout << currentGraphy[*setIterator] << endl;
            vertexQueue.push(*setIterator);
        }
    }
}

template <class Type>
int Graph<Type> :: costTraversal(Graphy<Type> & currentGraphy, int start)
{
    assert(start >= 0 && start < vertexCount);
    int cost = 0;
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>:: iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited, currentGraphy.size(), false);
    visited[start] = true;
    
    vertexQueue.push(start);
    while(!vertexQueue.empty())
    {
        int currentIndex = vertexQueue.front();
        connections = currentGraphy.neighbors(currentIndex);
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                coste += weightCostMatrix[currentIndex][*setIterator];
                visited[*setIterator] = true;
                vertexQueue.push(*setIterator);
            }
        }
    }
    
    return cost;
}

#endif /* Graph_h */
