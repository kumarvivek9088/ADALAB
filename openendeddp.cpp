//dp approach
// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define INF 99999
void printSolution(vector<vector<int>> dist,vector<int> num,int n,int k,int cost);
void floydWarshall(vector<vector<int>> graph,vector<int> num,int V,int c,int cost)
{
	int i, j, k;
	vector<vector<int>> dist(V,vector<int>(V,0));
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist,num,V,c,cost);
}
void printSolution(vector<vector<int>> dist,vector<int> num, int n,int k,int cost)
{
	vector<int> vec;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < n; j++) {
				vec.push_back(dist[i][j]);
		}
	}
	vector<int> ver;
    for (int i=0;i<n;i++){
        for(int j=i;j<num[i]+i;j++){
            ver.push_back(vec[i]);
        }
    }
    sort(ver.begin(),ver.end());
    cout<<"Costs are: -\n";
    for (int i=0;i<k;i++){
        cout<<ver[i]+cost<<"\t";
    }
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
	cout<<"Enter paarking fee: -";
	cin>>cost;
	cout<<"Enter number of subslots: -";
	vector<int> vec(n);
	for (int i=0;i<n;i++){
	    cin>>vec[i];
	}
	vector<vector<int>> graph( n , vector<int> (n, INF));
	for(int i=0;i<n;i++){
	    graph[i][i]=0;
	}

	for(int i = 0; i < m; i++)
	{
			cin>>u>>v>>w;
			graph[u-1][v-1]=w;
	}
	floydWarshall(graph,vec,n,k,cost);
	return 0;
}