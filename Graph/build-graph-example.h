#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
unordered_map<int,vector<int>>graph;//unweighted/same cost in all edges
  for(int i=0;i<6;i++){
      int u,v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u); // UNDIRECTED
  }
  unordered_map<int,vector<int>>::iterator node;
  for(node = graph.begin(); node != graph.end(); node++){
      int from = node->first;
      cout << from << ": ";
      for(int neighbor : graph[from])
          cout << neighbor << ", ";
      cout << endl;
  }
  cout << endl << endl;
  return 0;
}
