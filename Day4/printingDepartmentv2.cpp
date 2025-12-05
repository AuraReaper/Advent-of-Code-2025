#include <bits/stdc++.h>
using namespace std;

int n, m;
const int rowCoord[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int colCoord[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

long long countPaperRolls(vector<string>& arr) {
    long long liftCount = 0;
    
    for(int l = 0 ; l < n ; l++) {
        vector<pair<int,int>> coord;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(arr[i][j] == '@') {
                    int adjPaperCount = 0;
                    for(int k = 0 ; k < 8 ; k++) {
                        int row = i + rowCoord[k];
                        int col = j + colCoord[k];
                        if(isValid(row, col) && arr[row][col] == '@') {
                            adjPaperCount++;
                        }
                    }
                    
                    if(adjPaperCount < 4) {
                        liftCount++;
                        coord.push_back({i,j});
                    }
                }
            }
            
            for(auto& p: coord) {
                arr[p.first][p.second] = '.';
            }
        }
    }
    
    return liftCount;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }
    
    vector<string> arr;
    string s;
    
    while (file >> s) {
        arr.push_back(s);
    }
    
    file.close();
    
    n = arr.size();
    m = arr[0].size();
    
    cout << countPaperRolls(arr) << "\n";
    
    return 0;
}
