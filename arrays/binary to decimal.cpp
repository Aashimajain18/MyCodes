#include<iostream>
#include <cmath>
using namespace std;
int main() {
    long long int n;
    int i = 0, ans = 0, rem;
    cin >> n;
    while (n > 0) {
        rem = n % 10;

        ans = ans + rem * pow(2, i);
        n /= 10;

        i++;
    }
    cout << ans;
}