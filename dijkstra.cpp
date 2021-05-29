#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first

using namespace std;

priority_queue<pii> q;

int main()
{
	int n,m;
	cin>>n>>m;
	std::vector<pii> adj[n];

	int a,b,c;
	for (int i=0;i<m;i++) {
		cin>>a>>b>>c;
		a--, b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}

	int dist[n];
	for (int i=0;i<n;i++) dist[i]=INT_MAX;
	dist[0] = 0;
	q.push({0,0});

	pii p;
	while (!q.empty()) {
		p = q.top();
		q.pop();
		for (auto &i : adj[p.second]) {
			if (dist[p.second] + i.second < dist[i.first]) {
				dist[i.first] = dist[p.second] + i.second;
				q.push({-dist[i.first] , i.first});
			}
		}
	}


	for (int i=0;i<n;i++) cout<<dist[i]<<" ";
	return 0;
}
