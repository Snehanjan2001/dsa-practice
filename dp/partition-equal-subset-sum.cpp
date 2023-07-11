#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{

    // writing the base cases
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
    {
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = taken || notTaken;
}

bool canPartition(int n, vector<int> &arr)
{

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    if (totSum % 2 == 1)
        return false;

    else
    {
        int k = totSum / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int k = 6;
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "Subset with given target found";
    else
        cout << "Subset with given target not found";
}