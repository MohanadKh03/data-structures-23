void BFS(unordered_map<int,vector<int>>&graph){
    int start = 1;
    queue<int>q;
    unordered_map<int,bool>visited;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        for(int child : graph[temp]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }
        }
    }
}
