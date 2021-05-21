/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:

//see leetcode

Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["\\/","/\\"]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
Example 4:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
Example 5:


Input: grid = ["//","/ "]
Output: 3
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
*/


// Intuition
// Split a cell in to 4 parts like this.
// We give it a number top is 0, right is 1, bottom is 2 left is 3.

// image
// (photo by @Sabbi_coder)

// Two adjacent parts in different cells are contiguous regions.
// In case '/', top and left are contiguous, botton and right are contiguous.
// In case '\\', top and right are contiguous, bottom and left are contiguous.
// In case ' ', all 4 parts are contiguous.

// Congratulation.
// Now you have another problem of counting the number of islands.


// Explanation
// DFS will be good enough to solve it.
// As I did in 947.Most Stones Removed with Same Row or Column
// I solved it with union find.


// Complexity
// Time O(N^2)
// Space O(N^2)


C++

   int count, n;
   vector<int> f; //build an array to store all parents of all triangles
   int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = n * n * 4;  //total number of polygons
        for (int i = 0; i < n * n * 4; ++i)
            f.push_back(i);  //initialize the parent array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0)); // merge triangles 2 and 0 from two squares vertically
                if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3)); // merge trianges 1 and 3 from two squares horizontally. These triangles are supposed to be contiguous originally
                if (grid[i][j] != '/') {.                       // if it is "\\" or empty, apply common operations
                    uni(g(i , j, 0), g(i , j,  1));
                    uni(g(i , j, 2), g(i , j,  3));
                }
                if (grid[i][j] != '\\') { // if it is "/" or empty, apply common operations.
                    uni(g(i , j, 0), g(i , j,  3));  // These two if statements solve the repetition issue caused by traditional three if statements
                    uni(g(i , j, 2), g(i , j,  1));
                }
            }
        }
        return count;
    }

    int find(int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }
    void uni(int x, int y) {. //merge two polygons to a bigger polygon will decrease number of polygons by 1
        x = find(x); y = find(y);
        if (x != y) {
            f[x] = y;
            count--;
        }
    }
    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k; //find the corresponding position for current triangle. Thinks this 1D array as a 2D array and each element is an array of size 4.
    }
