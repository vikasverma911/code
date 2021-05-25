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
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first

using namespace std;

int getSum(int BITree[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}

int sum(int x, int BITTree1[], int BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}

void updateRange(int BITTree1[], int BITTree2[], int n,
                 int val, int l, int r)
{
    updateBIT(BITTree1, n, l, val);
    updateBIT(BITTree1, n, r + 1, -val);

    updateBIT(BITTree2, n, l, val * (l - 1));
    updateBIT(BITTree2, n, r + 1, -val * r);
}

int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
    return sum(r, BITTree1, BITTree2) - sum(l - 1, BITTree1, BITTree2);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int BITTree1[n + 1];
    int BITTree2[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        BITTree1[i] = 0;
        BITTree2[i] = 0;
    } // 0 0 0 0 0 0 0
    int l = 0, r = 3, val = 5;
    updateRange(BITTree1, BITTree2, n, val, l, r); // 5 5 5 5 0 0 0
    l = 2, r = 5, val = 2;
    updateRange(BITTree1, BITTree2, n, val, l, r); // 5 5 7 7 2 2 0

    l = 3, r = 6;
    cout << rangeSum(l, r, BITTree1, BITTree2);

    return 0;
}
