#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tq;
    cin >> n;
    int bt[n], rt[n], ct[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
        rt[i] = bt[i];   
    }
    cin >> tq;
    int time = 0;
    bool done;
    while (true) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = false;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];          
        wt[i] = tat[i] - bt[i];
    }
    cout << "Process\tBT\tCT\tTAT\tWT\n";
    cout << "-----------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "  P" << i + 1 << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }
    return 0;
}
