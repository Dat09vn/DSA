1. Array
2. String
3. Recursion
4. Sorting
5. Binary Search
6. Hash Table
7. LiskedList
	One stylist for implement linkedlist: using dummy node that have val = none to point to the head node.
	insertToTail: 	C1: loop from head to tail and insert newNode. O(n)
			C2: everytime when insert, set ptr to store tail node. O(1)
	
9. Queue & Stack
10. Graph
12. BFS 
	Ideal of BFS: It starts at the root of the graph and visits all nodes at the current depth level before moving on to the nodes at the next depth level.
	Applications:
		1. Find a path from start node to destination node
		2. Find the shortest path from a start node to a destination node
	Using queue to implementation:
		create a queue Q 
		mark v as visited and put v into Q 
		while Q is non-empty 
    			remove the head u of Q 
    			mark and enqueue all (unvisited) neighbours of u
	Time complexity:O(v+e)
---------------------------------------------------------------------
Example: https://leetcode.com/problems/find-if-path-exists-in-graph/description/
13. DFS
	Template of DFS:
	void traverseGraph(int V, List<List<Integer>> connect) {
	    // Initialize visited array
	    boolean[] vis = new boolean[V];
	    // Go through all the nodes
	    for (int i = 0; i < V; ++i) {
	        // Ignore already visited node
	        if (vis[i]) {
	            continue;
	        }
	        // If this node is not visited, call DFS to visit all nodes reachable from this one
	        dfs(i, connect, vis);
	    }
	}
---------------------------------------------------------------------------
	void dfs(int node, List<List<Integer>> connect, boolean[] vis) {
	    // Mark current node as visited
	    vis[node] = true;
	    // Find all neighbors of this node
	    for (int u : connect.get(node)) {
	        // Ignore already visited neighbors
	        if (vis[u]) {
	            continue;
	        }
	        // If not visited neighbor, recursively call DFS to process this
	        dfs(u, connect, vis);
	    }
	}
14. Island Matrix Traversal
	// Up, Right, Down, Left
	int[] dx = new int[]{-1,0,1,0};
	int[] dy = new int[]{0,1,0,-1};
	private void traverseMatrix(int[][] arr, int m, int n) {
	    // Initialize visited array
	    boolean[][] vis = new boolean[m][n];
	    // Go thru each element in the array
	    for (int i = 0; i < m; ++i) {
	        for (int j = 0; j < n; ++j) {
	            // Skip invalid or visited cell
	            if (arr[i][j] == 0 || vis[i][j]) {
	                continue;
	            }
	            // Call DFS to traverse all connected cells and do some calculation
	            dfs(i,j,m,n,arr);
	        }
	    }
	}
---------------------------------------------------------------------------------
	private void dfs(int x, int y, int m, int n, int[][] arr) {
	    vis[x][y] = true;
	    // Find neighbors in 4 direction
	    for (int k = 0; k < 4; ++k) {
	        int u = x + dx[k];
	        int v = y + dy[k];
	        // Skip out of bound cells
	        // Skip visited cells
	        // Skip invalid cells
	        if (!inside(u,v,m,n) || vis[u][v] || arr[u][v] == 0) continue;
	        // Recursively call DFS for the neighbor cell.
	        dfs(u, v, m, n, arr);
	    }
	}
	// Function for boundary check
	private boolean inside(int x, int y, int m, int n) {
	    return x >= 0 && x < m && y >= 0 && y < n;
	}
15. Topological Sort
Implement by DFS:
	List<Integer> topologicalSortDFS(int n, List<List<Integer>> cons) {
	boolean[] vis = new boolean[n];
		List<Integer> res = new ArrayList<>();
		For (int i = 0; i < n; ++i) {
			If (vis[i]) continue;
			dfs(i, vis, cons, res);
		}
		Collections.reverse(res);
		return res;
	}
	private void dfs(int cur, boolean[] vis, List<List<Integer>> cons, List<Integer> res) {
		vis[cur] = true;
		for (int u : cons.get(cur)) {
			// Skip visited node
			if (vis[u]) continue;
			// Recursively compute for this descendant node 
			dfs(u, vis, cons, res);
		}
		// All descendants have been processed, add the current node to the result
	 	// Note that the result list here is in reverse-order
		res.add(cur);
	}
-----------------------------------------------------------------------
Implement by BFS:
	List<Integer> topologicalSortBFS(int n, List<List<Integer>> cons) {
	    // Build inDegree array
	    int[] inDegree = new int[n];
	    for (int i = 0; i < n; ++i) {
	        for (int u : cons.get(i)) {
	            inDegree[u]++;
	        }
	    }
	    Queue<Integer> q = new LinkedList<>(); 
	    for (int i = 0; i < n; ++i) {
	        // Add to queue if inDegree == 0. I.e no incoming edge to this node.
	        if (inDegree[i] == 0) {
	            q.add(i);
	        }
	    }
	    List<Integer> res = new ArrayList<>();
	    while(!q.isEmpty()) {
	        // Get the current node that has no incoming edge.
	        int cur = q.poll();
	        // Add to the result
	        res.add(cur);
	        // Go through neighbor nodes that current node connect to
	        for (int u : cons.get(cur)) {
	            // Decrease inDegree of this neighbor node. I.e “remove” the edge from current node to this node
	            inDegree[u]--;
	            // Add to queue if inDegree == 0. I.e no incoming edge to this node.
	            if (inDegree[u] == 0) {
	                q.add(u);
	            }
	        }
	    }
	    return res;
	}
16. Interval
	def intersect(A: Interval, B: Interval) -> Interval:
	    if notOverlaps(A, B):
	        return None
	    return Interval(max(A.L, B.L), min(A.R, B.R))
	
	def merge(A: Interval, B: Interval) -> Interval:
	    if notOverlaps(A, B):
	        raise Exception("Intervals don't overlap!")
	    return Interval(min(A.L, B.L), max(A.R, B.R))

