#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <vector>
using namespace std;
int minDistance(int dist[], bool sptSet[],int V)
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
int printSolution(int dist[],vector<int> num, int n,int k,int cost)
{
    vector<int> ver;
    for (int i=0;i<n;i++){
        for(int j=i;j<num[i]+i;j++){
            ver.push_back(dist[i]);
        }
    }
    sort(ver.begin(),ver.end());
    cout<<"Costs are: -\n";
    for (int i=0;i<k;i++){
        cout<<ver[i]+cost<<"\t";
    }
	return 0;
}
void dijkstra(vector<vector<int>> graph,int V, vector<int> num,int src,int k,int cost)
{
	int dist[V];
	bool sptSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet,V);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist,num, V,k,cost);
}
int main()
{
	int n,k,m,u,v,w,cost;
	cout<<"Enter number of slots: -";
	cin>>n;
	cout<<"Enter number of routes: -";
	cin>>m;
	cout<<"Enter number of cars: -";
	cin>>k;
	cout<<"Enter parking fee: -";
	cin>>cost;
	cout<<"Enter number of subslots: -";
	vector<int> vec(n);
	for (int i=0;i<n;i++){
	    cin>>vec[i];
	}
	vector<vector<int>> graph( n , vector<int> (n, 0));
	for(int i = 0; i < m; i++)
	{
			cin>>u>>v>>w;
			graph[u-1][v-1]=w;
            graph[v-1][u-1]=w;
	}
	dijkstra(graph,n,vec, 0,k,cost);
	return 0;
}