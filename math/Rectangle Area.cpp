/*
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

 

Example 1:

Rectangle Area
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45
Example 2:

Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16
 

Constraints:

-10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4
*/

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    int total = (C-A) * (D-B) + (G-E) * (H-F);
    
    if (C<=E || A>=G || B>=H || D<=F )
        return total;
    else
    {
        vector <int> h;
        h.push_back(A);
        h.push_back(C);
        h.push_back(E);
        h.push_back(G);
   
        vector <int> v;
        v.push_back(B);
        v.push_back(D);
        v.push_back(F);
        v.push_back(H);
    
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
    
        total = total - (h[2] - h [1]) * (v[2] - v[1]);
        return total;
    }
}
