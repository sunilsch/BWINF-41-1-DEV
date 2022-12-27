#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;
ofstream outputFile;

const int maxNodes = 101;

int n,m;
vector<vector<int>> G(maxNodes);
vector<vector<vector<int>>> paths1(maxNodes);
vector<vector<vector<int>>> paths2(maxNodes);

int getMiddleNode(){
    for(vector<int> x : paths1[5]){
        for(int y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

void visit(int node, vector<vector<vector<int>>> &paths, vector<int> path, int p){
    if(path.size() > n){
        return;
    }
    if(path.size() > 0){
        paths[node].push_back(path);
    }
    
    for(int newNode : G[node]){
        if(newNode != p){
            vector<int> pathCopy = path;
            pathCopy.push_back(newNode);
            /*for(int i : pathCopy){
                cout << i << " ";
            }
            cout << endl;*/
            visit(newNode, paths, pathCopy, node);
        }
    }
}

void solve(int startPoint1, int startPoint2){
    string result;
    vector<int> pathTmp;
    visit(startPoint1, paths1, pathTmp, -1);
    visit(startPoint2, paths2, pathTmp, -1);
    int node = getMiddleNode();
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
    solve(0,1);

    outputFile.close();
    
    return 0;
}