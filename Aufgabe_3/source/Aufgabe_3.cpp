#include <bits/stdc++.h>

using namespace std;

ifstream inputFile;
ofstream outputFile;

int sudoku1[9][9];
int sudoku2[9][9];

vector<pair<int,int>> countNumbers(int sudoku[9][9]){
    vector<pair<int,int>> count;
    for(int i = 0; i < 10; i++){
        count.emplace_back(0,i);
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            count[sudoku[i][j]].first++;
        }
    }
    sort(count.begin(), count.end());
    return count;
}

string check_Umbenennen(){
    vector<pair<int,int>> count1 = countNumbers(sudoku1);
    vector<pair<int,int>> count2 = countNumbers(sudoku2);
    bool isUmbenannt = false;
    int umformung[9];
    string umformungString;

    for(int i = 0; i < 9; i++){
        if(count1[i].second != count2[i].second)
            isUmbenannt = true;
        cout << "First : " << "Number: " << count1[i].second << " Menge: " << count1[i].first << " Second : " << " Number: " << count2[i].second << " Menge: " << count2[i].first << endl; 
    }
    if(isUmbenannt){
        for(int i = 0; i < 10; i++)
            umformung[count1[i].second] = count2[i].second;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                sudoku2[i][j] = umformung[sudoku1[i][j]];
            }
        }
        

        for(int i = 0; i < 9; i++)
            umformungString += to_string(umformung[i])+" ";
        return umformungString;
    }
    return "";
}

void solve(){
    string umbenennung;
    umbenennung = check_Umbenennen();
    if(umbenennung != ""){
        cout << umbenennung << endl;
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoku2[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    /*ios::sync_with_stdio(0);
    cin.tie(0);*/
    
    string filename;
    cout << "Please enter filename without file extension" << endl;
    cout << "Files must be located in '/beispieleingaben/'" << endl;
    cout << "-> ";
    cin >> filename;

    inputFile.open("../beispieleingaben/sudoku2.txt");
    for(int i = 0; i < 3; i++)
        inputFile.get();
    outputFile.open("../beispielausgaben/"+filename+".out");
    if(inputFile.is_open()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                inputFile >> sudoku1[i][j];
            }
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                inputFile >> sudoku2[i][j];
            }
        }
    } else {
        cout << "Unable to open file";
    }
    
    inputFile.close();
    solve();

    outputFile.close();
    
    return 0;
}