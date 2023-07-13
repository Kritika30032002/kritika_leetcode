class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj)
    {
        vector<int> inDegree(V, 0); // stores in-degree of each vertex
        vector<vector<int>> adjacencyList(V); // create an empty adjacency list

        for (auto& edge : adj) {
            int u = edge[0];
            int v = edge[1];
            adjacencyList[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q; // queue to store vertices with 0 in-degree
        int visited = 0; // count of visited vertices

        // enqueue vertices with 0 in-degree
        for (int u = 0; u < V; u++)
        {
            if (inDegree[u] == 0)
            {
                q.push(u);
            }
        }

        // BFS traversal
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            visited++;

            // reduce in-degree of adjacent vertices
            for (auto v : adjacencyList[u])
            {
                inDegree[v]--;
                // if in-degree becomes 0, enqueue the vertex
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return visited != V; // if not all vertices are visited, there is a cycle
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        return !isCyclic(numCourses, prerequisites);
    }

};