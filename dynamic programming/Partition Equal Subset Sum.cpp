/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

//my solution
//top down dp
class Solution{
public:
int dp[1000]={0};
bool recursive_check(int arr[],int n,int sum){
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 if(dp[n]!=0){
     return dp[n];
 }
    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        dp[n]= recursive_check(arr, n - 1, sum);
        // return dp[n];
 
    /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
    */
    dp[n]= recursive_check(arr, n - 1, sum)
           || recursive_check(arr, n - 1, sum - arr[n - 1]);
    return dp[n];
}

    int equalPartition(int N, int arr[])
    {
        // code here
        //return 1 for yes and 0 for no
       
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            //odd sum
            return 0;  
        }
        //eachpartsum=eps
        int eps=sum/2;
        int checksum=eps;
        return recursive_check(arr,N,checksum);
    }
};



//solution 2
//most optimal
bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */
 
    return part[sum / 2][n];
}
