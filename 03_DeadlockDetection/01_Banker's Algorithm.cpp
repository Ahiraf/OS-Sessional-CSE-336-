#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> maximum(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));

    vector<int> available(m);

    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> allocation[i][j];
        }
    }

    cout << "\nEnter Maximum Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maximum[i][j];
        }
    }

    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < m; i++){
        cin >> available[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    vector<bool> finish(n, false);
    vector<int> safeSequence;

    int completed = 0;

    while(completed < n){

        bool found = false;

        for(int i = 0; i < n; i++){

            if(!finish[i]){

                bool possible = true;

                for(int j = 0; j < m; j++){
                    if(need[i][j] > available[j]){
                        possible = false;
                        break;
                    }
                }

                if(possible){

                    for(int j = 0; j < m; j++){
                        available[j] += allocation[i][j];
                    }

                    finish[i] = true;
                    safeSequence.push_back(i);
                    completed++;
                    found = true;
                }
            }
        }

        if(!found){
            break;
        }
    }

    if(completed == n){

        cout << "\nSystem is in Safe State\n";
        cout << "Safe Sequence: ";

        for(int i = 0; i < safeSequence.size(); i++){
            cout << "P" << safeSequence[i];

            if(i != safeSequence.size() - 1){
                cout << " -> ";
            }
        }

        cout << endl;
    }
    else{
        cout << "\nSystem is NOT in Safe State\n";
    }

    return 0;
}
