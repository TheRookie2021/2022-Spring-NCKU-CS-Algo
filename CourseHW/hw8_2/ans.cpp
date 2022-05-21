// C++ program to get maximum sum two non-overlapping
// subarrays of same specified length
#include <bits/stdc++.h>
using namespace std;

// Utility method to get sum of subarray
// from index i to j
int getSubarraySum(int sum[], int i, int j)
{
	if (i == 0)
		return sum[j];
	else
		return (sum[j] - sum[i - 1]);
}

// Method prints two non-overlapping subarrays of
// length K whose sum is maximum
void maximumSumTwoNonOverlappingSubarray(int arr[],
									int N, int K)
{
	int sum[N];

	// filling prefix sum array
	sum[0] = arr[0];
	for (int i = 1; i < N; i++)
		sum[i] = sum[i - 1] + arr[i];

	// initializing subarrays from (N-2K) and (N-K) indices
	pair<int, int> resIndex = make_pair(N - 2 * K, N - K);

	// initializing result sum from above subarray sums
	int maxSum2Subarray = getSubarraySum(sum, N - 2 * K, N - K - 1) +
						getSubarraySum(sum, N - K, N - 1);

	// storing second subarray maximum and its starting index
	pair<int, int> secondSubarrayMax = make_pair(N - K,
						getSubarraySum(sum, N - K, N - 1));

	// looping from N-2K-1 towards 0
	for (int i = N - 2 * K - 1; i >= 0; i--)
	{
		// get subarray sum from (current index + K)
		int cur = getSubarraySum(sum, i + K, i + 2 * K - 1);

		// if (current index + K) sum is more then update
		// secondSubarrayMax
		if (cur >= secondSubarrayMax.second)
			secondSubarrayMax = make_pair(i + K, cur);

		// now getting complete sum (sum of both subarrays)
		cur = getSubarraySum(sum, i, i + K - 1) +
			secondSubarrayMax.second;

		// if it is more then update main result
		if (cur >= maxSum2Subarray)
		{
			maxSum2Subarray = cur;
			resIndex = make_pair(i, secondSubarrayMax.first);
		}
	}

	// printing actual subarrays
	for (int i = resIndex.first; i < resIndex.first + K; i++)
		cout << arr[i] << " ";
	cout << endl;

	for (int i = resIndex.second; i < resIndex.second + K; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code to test above methods
int main()
{
	int arr[] = {2, 5, 1, 2, 7, 3, 0};
	int N = sizeof(arr) / sizeof(int);

	// K will be given such that (N >= 2K)
	int K = 2;

	maximumSumTwoNonOverlappingSubarray(arr, N, K);

	return 0;
}
