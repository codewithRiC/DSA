#include<bits/stdc++.h>
using namespace std;

struct Edge {
  int src, dest, wt;
};

vector<Edge> graph[10001];

void createGraph(int v) {
  int e;
  for (int i = 0; i < v; i++) {
    cout << "Enter number of edges for vertex " << i << ": ";
    cin >> e;
    for (int j = 0; j < e; j++) {
      int src, dest, wt;
      cout << "Enter source, destination, and weight: ";
      cin >> src >> dest >> wt;
      graph[i].push_back({src, dest, wt});
    }
  }
}

void bfs(int start, int v) {
  queue<int> q;
  bool vis[10001];
  memset(vis, false, sizeof vis);
  q.push(start);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (!vis[curr]) {
      cout << curr << " ";
      vis[curr] = true;
      for (auto e : graph[curr]) {
        q.push(e.dest);
      }
    }
  }
}

void dfs(int curr, int v, bool vis[]) {
  
  cout << curr << " ";
  vis[curr] = true;
  for (auto e : graph[curr]) {
    if (!vis[e.dest]) {
      dfs(e.dest, v, vis);
    }
  }
}

int main() {
  int v;
  cout << "Enter number of vertices: ";
  cin >> v;
  createGraph(v);

  int choice;
  cout << "1. Breadth first search (bfs)\n";
  cout << "2. Depth first search (dfs)\n";
  cout << "3. Exit\n";
  do {
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1: {
        int start;
        cout << "Enter starting point: ";
        cin >> start;
        bfs(start, v);
        break;
      }
      case 2:
        dfs(0, v, new bool[v + 1]);
        break;
      case 3:
        return 0;
      default:
        cout << "Invalid input\n";
    }
  } while (choice != 3);
  return 0;
}