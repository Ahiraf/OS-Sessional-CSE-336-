//Shortest Job First
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>pid(n), at(n), bt(n), ct(n), tat(n), wt(n);
    vector<bool> completed(n, false);
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> at[i] >> bt[i];
    }
    int time = 0, done = 0;
    while (done < n) {
        int idx = -1;
        int min_bt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < min_bt){
                min_bt = bt[i];
                idx = i;
            }
        }
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        completed[idx] = true;
        done++;
    }
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << " " << "P" << pid[i] << " \t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }
    return 0;
}
