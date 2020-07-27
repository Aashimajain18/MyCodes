/*
Print "lowercase" if user enters a character between 'a-z' , Print "UPPERCASE" is
character lies between 'A-Z' and print "Invalid" for all other characters like $,.^# etc.

Input Format
Single Character .

Constraints
-

Output Format
lowercase UPPERCASE Invalid

Sample Input
$
Sample Output
Invalid
*/
#include<iostream>
#include <algorithm>

using namespace std;


int main() {
    char n;
    cin >> n;

    if (n >= 'a' && n <= 'z') {
        cout << "lowercase" << endl;
    }
    else if (n >= 'A' && n <= 'Z') {
        cout << "UPPERCASE" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }



    return 0;
}