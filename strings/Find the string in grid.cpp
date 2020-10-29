/*
Given a 2D grid (G[]) of characters and a word(x), find all occurrences of given word in grid.
A word can be matched in all 8 directions at any point. Word is said be found in a direction if all
characters match in this direction (not in zig-zag form).

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically down and 4
Diagonal directions.

Example:

Input:  G[][] = {"GEEKSFORGEEKS",
                 "GEEKSQUIZGEEK",
                 "IDEQAPRACTICE"};
        x = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.
 Each test case contains two space separated integers N and M denoting the size of the grid. Then in the
 next line are N * M space separated values of the grid. In the next line is the word x.

Output:
For each test case in a new line print the space separated sorted indexes of the matrix where after each
index there is a ', ' . If there are no such occurences print -1.

Constraints:
1<=T<100
1<=N,M<=100
1<=G[]<=100

Example:
Input:
2
3 3
a b c d e f g h i
abc
4 3
a b a b a b e b e b e b
abe
Output:
0 0,
0 0, 0 2, 1 1,
*/


// C++ programs to search a word in a 2D grid
#include <bits/stdc++.h>
using namespace std;

// Rows and columns in given grid
#define R 3
#define C 14

// For searching in all 8 direction
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char grid[R][C], int row,
              int col, string word)
{
	// If first character of word doesn't
	// match with given starting point in grid.
	if (grid[row][col] != word[0])
		return false;

	int len = word.length();

	// Search word in all 8 directions
	// starting from (row, col)
	for (int dir = 0; dir < 8; dir++) {
		// Initialize starting point
		// for current direction
		int k, rd = row + x[dir], cd = col + y[dir];

		// First character is already checked,
		// match remaining characters
		for (k = 1; k < len; k++) {
			// If out of bound break
			if (rd >= R || rd < 0 || cd >= C || cd < 0)
				break;

			// If not matched,  break
			if (grid[rd][cd] != word[k])
				break;

			// Moving in particular direction
			rd += x[dir], cd += y[dir];
		}

		// If all character matched, then value of must
		// be equal to length of word
		if (k == len)
			return true;
	}
	return false;
}

// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char grid[R][C],
                   string word)
{
	// Consider every point as starting
	// point and search given word
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			if (search2D(grid, row, col, word))
				cout << "pattern found at "
				     << row << ", "
				     << col << endl;
}

// Driver program
int main()
{
	char grid[R][C] = { "GEEKSFORGEEKS",
	                    "GEEKSQUIZGEEK",
	                    "IDEQAPRACTICE"
	                  };

	patternSearch(grid, "GEEKS");
	cout << endl;
	patternSearch(grid, "EEE");
	return 0;
}

//for paasing 2d array to a function...prefer using vectors or arrays with predefined size like in the given solution:-
/*
#include<vector>
using namespace std;

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};

bool search2D(vector<vector<char>> arr , int r, int c, int n, int m, string str)
{
    if(arr[r][c]!=str[0])
    {
        return false;
    }
    int len=str.length();
    for(int d=0;d<8;d++)
    {
        int rd=r+X[d];
        int cd=c+Y[d];
        int k;
        for( k=1;k<len;k++)
        {
             if(rd>=n||cd>=m||rd<0||cd<0) break;
            if(str[k]!=arr[rd][cd])
            break;

            rd+=X[d];
            cd+=Y[d];
        }
        if(k==len) return true;

    }
    return false;
}


void patternSearch(vector<vector<char>> arr, int n, int m , string str)
{
     int flag=0;
     for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
        {
            if(search2D(arr,i,j,n,m,str))
              { cout<<i<<" "<<j<<", ";
                  flag=1;
              }
        }
    if(flag==0)
       cout<<"-1";
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;

	       vector <vector <char>> arr(n, vector <char> (m));
	     for(int i=0;i<n;i++)
	       for(int j=0;j<m;j++)
	       {

	           cin>>arr[i][j];

	       }
	    string str;
	    cin>>str;
	    patternSearch(arr,n,m,str);
	    cout<<endl;
	}
	return 0;
}
*/

/*
using namespace std;

static constexpr int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
static constexpr int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool exists(int n, int m, char a[100][100], const string& s, int r, int c, int k) {
    for (int i = 0; i < s.length(); i++) {
        if (r < 0 || r == n || c < 0 || c == m || a[r][c] != s[i]) {
            return false;
        }
        r += dx[k];
        c += dy[k];
    }
    return true;
}

void printRes(int n, int m, char a[100][100], const string& s) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != s[0]) {
                continue;
            }

            for (int k = 0; k < 8; k++) {
                if (exists(n,m,a,s,i,j,k)) {
                    found++;
                    cout << i << ' ' << j << ", ";
                    break;
                }
            }
        }
    }
    if (found == 0) cout << "-1";
    cout << '\n';
}

int main() {
	char a[100][100];

	int t;
	cin >> t;
	while (t-- > 0) {
	    int n,m;
	    cin >> n >> m;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < m; j++) {
	            cin >> a[i][j];
	        }
	    }
	    string s;
	    cin >> s;
	    printRes(n,m,a,s);
	}
	return 0;
}
*/
