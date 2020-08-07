/*
PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all
 countries between a and b (inclusive) , However due to shortage of time he can't visit
 each and every country , So PM Modi decides to visit only those countries,for which
 country number has two divisors. So your task is to find number of countries Mr. Modi will visit.
Input Format
The first line contains N , no of test cases. The next N lines contain two integers a and b denoting
the range of country numbers.
Constraints
a<=1000000 & b<=1000000.
N<=1000
Output Format
Output contains N lines each containing an answer for the test case.
Sample Input
2
1 10
11 20
Sample Output
4
4
Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.
*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        //  code starts using prime sieve
        int seivearray[m], i, j;
        for (i = 0; i < m; i++) {
            seivearray[i] = 1;
        }
        // 1 means prime
        // 0 means not prime
        seivearray[0] = 0; seivearray[1] = 0;
        for (i = 2; i < m; i++) { // whose multiples to be cancelled
            if (seivearray[i] == 1) {
                // if the number is prime
                for (j = i * 2; j < m; j += i) { // multiples of prime
                    seivearray[j] = 0;
                }
            }
        }
        // copy primes to the new array
        // here primes[i]= ith prime number
        int count = 0;
        for (i = n; i < m; i++) {
            if (seivearray[i] == 1) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;

}
