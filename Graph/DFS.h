void DFSIterative(unordered_map<int,vector<int>>&graph){
    int start = 1;
    stack<int>s;
    unordered_map<int,bool>visited;
    s.push(start);
    visited[start] = true;
    while(!s.empty()){
        int temp = s.top();
        cout << temp << " ";
        s.pop();
        for(int child : graph[temp]){
            if(!visited[child]){
                s.push(child);
                visited[child] = true;
            }
        }
    }
    cout << endl;
}
/*----------------------------------------------------------------*/

void DFSRecursive(unordered_map<int,vector<int>>&graph,int node,unordered_map<int,bool>&vis){
    vis[node] = true;
    cout << node << endl;
    for(int child : graph[node]){
        if(!vis[child])
            DFSRecursive(graph,child);
    }
}
