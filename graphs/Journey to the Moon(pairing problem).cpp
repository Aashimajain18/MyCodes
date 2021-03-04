/*
https://www.hackerrank.com/challenges/journey-to-the-moon/problem
*/

long long int findSet(long long int i, long long int parent[]) {
        if (parent[i] == -1) {
            return i;

        }
        return parent[i] = findSet(parent[i], parent);; //just added this for path compression optimization
    }
    
void unionSet(long long int x, long long int y, long long int parent[], long long int rank[]) {
        long long int S1 = findSet(x, parent);
        long long int S2 = findSet(y, parent);
        if (S1 != S2) {
            if (rank[S1] < rank[S2]) {
                parent[S1] = S2;
                rank[S2] += rank[S1];
            }
            else {
                parent[S2] = S1;
                rank[S1] += rank[S2];

            }
        }

        return;

}

// Complete the journeyToMoon function below.
long long int journeyToMoon(long long int n, vector<vector<long long int>> astronaut) {
    
       long long int p=astronaut.size();
long long int parent[n];
long long int rank[n];
for (long long int i = 0; i < n; i++)
        {
    //in the beginning
            parent[i] = -1;
            rank[i] = 1;
        }
        for (long long int i = 0; i < p; i++)
        {
            long long int x=astronaut[i][0];
            long long int y=astronaut[i][1];
            long long int S1 = findSet(x, parent);
            long long int S2 = findSet(y, parent);
            if (S1 != S2) {
                unionSet(S1, S2, parent, rank);
            }
        } 
    
    

// total=(n*(n-1))/2;
long long int ans=0;


for(long long int i=0;i<n;i++){

ans+=n-rank[findSet(i,parent)];
}
return ans/2;

}

