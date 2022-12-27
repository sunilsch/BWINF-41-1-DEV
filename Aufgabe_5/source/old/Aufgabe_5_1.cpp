#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;
ofstream outputFile;

const int maxNodes = 151;

int n,m;
vector<vector<int>> G(maxNodes);

void bfs(int node, vector<vector<int>> &distancesSave){ // Calculate depth for each node
    vector<int> distances(maxNodes, 0);
    cout << "Start Function!" << endl;
    queue<int> q;
    queue<int> qPath;
    q.push(node);
    while(!q.empty()){
        int w = q.front();
        q.pop();
        distancesSave[w].push_back(distances[w]);
        if(distances[w] > n){
            break;
        }
        for(int x : G[w]){
            distances[x] = distances[w]+1; 
            q.push(x);
        }
    }
    cout << "END" << endl;
    for(int i = 0; i < n; i++){
        distancesSave[i].erase(unique(distancesSave[i].begin(), distancesSave[i].end()), distancesSave[i].end());
    }
}


int calculateNode(vector<vector<int>> &distances1, vector<vector<int>> &distances2){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < distances1[i].size(); j++){
            for(int k = 0; k < distances2[i].size(); k++){
                if(distances1[i][j] == distances2[i][k]){
                    return i;
                }
            }
        }
    }
    return -1;
}


string solve(int startPoint1, int startPoint2){
    vector<vector<int>> distances1(maxNodes);
    vector<vector<int>> distances2(maxNodes);
    bfs(startPoint1, distances1);
    bfs(startPoint2, distances2);
    int midNode = calculateNode(distances1, distances2);
    cout << midNode;
    return "";
}

int main(){
    /*ios::sync_with_stdio(0);
    cin.tie(0);*/
    
    string filename;
    cout << "Please enter filename without file extension" << endl;
    cout << "Files must be located in '/beispieleingaben/'" << endl;
    cout << "-> ";
    cin >> filename;

    inputFile.open("../beispieleingaben/"+filename+".txt");
    outputFile.open("../beispielausgaben/"+filename+".out");
    if(inputFile.is_open()){
        inputFile >> n >> m;
        for (int i = 0; i < m; i++){
            int n1, n2;
            inputFile >> n1 >> n2;
            n1--; n2--;
            G[n1].push_back(n2);
            cout << n1 << " " << n2 << endl;
        }
        inputFile.close();
    } else {
        cout << "Unable to open file";
    }
    cout << solve(0,1) << endl;

    outputFile.close();
    
    return 0;
}