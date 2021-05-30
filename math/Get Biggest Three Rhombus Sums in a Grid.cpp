/*
You are given an m x n integer matrix grid.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
Example 2:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 10^5

*/

Here i've used a way where if (i,j) is the center of rhombus and if (i+k,j),(i-k,j),(i,j-k),(i,j+k) are all points which lie inside the grid given then we can calculate rhombus sums for that center considering (i+k,j),(i-k,j),(i,j-k),(i,j+k) as vertices.

Now how did i calculate the sum, if you notice closely then other than individual values (the values themselves), all the other points have borders(edges) such that the sum of (x and y) coordinates are i+j-k,i+j+k (where k can range from 1 to half of the grid size). Thus for 4 sides i used 4 loops to calculate the sum of each side. And at last i reduced the vertices values once from my sum because they were being considered 2 times each.

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        set<int> pq;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(i==0 || j==0 || i==r-1 || j==c-1){
                    pq.insert(grid[i][j]);
                    if(pq.size()>3){
                        pq.erase(pq.begin());
                    }
                    continue;
                }
                pq.insert(grid[i][j]);
                
                if(pq.size()>3){
                    pq.erase(pq.begin());
                }
                
                for(int k=1;k<min(r,c)/2 + 1;++k){
                    
                    if(i+k < r && i-k >=0 && j+k<c && j-k>=0){
                        int temp=0;
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i+a][j+b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i-a][j+b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i+a][j-b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i-a][j-b];
                        }
                        temp -= (grid[i+k][j]+grid[i][j+k]+grid[i-k][j]+grid[i][j-k]);
                        pq.insert(temp);
                        if(pq.size()>3){
                            pq.erase(pq.begin());
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        int i=3;
        while(i-- && !pq.empty()){
            ans.push_back(*pq.begin());
            pq.erase(pq.begin());
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
