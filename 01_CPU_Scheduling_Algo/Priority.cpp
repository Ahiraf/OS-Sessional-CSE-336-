#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pid(n), arrival(n), burst(n), priority(n);
    vector<bool> completed(n, false);
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cin >> arrival[i] >> burst[i] >> priority[i];
    }
    int currentTime = 0;
    int completedCount = 0;
    vector<int> ganttPID;
    vector<int> ganttTime;
    ganttTime.push_back(0);

    while (completedCount < n) {
        int idx = -1;
        int highestPriority = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && arrival[i] <= currentTime) {
                if (priority[i] < highestPriority) {
                    highestPriority = priority[i];
                    idx = i;
                }
            }
        }
        if (idx == -1) {
            currentTime++;
            continue;
        }
        ganttPID.push_back(pid[idx]);
        currentTime += burst[idx];
        ganttTime.push_back(currentTime);
        completed[idx] = true;
        completedCount++;
    }

    cout << "             Gantt Chart:\n";
    cout << "------------------------------------\n|";
    for (int p : ganttPID) {
        cout << " P" << p << "  |  ";
    }
    cout << "\n";

    for (int t : ganttTime) {
        cout <<  t << " " << "\t ";
    }
    cout << "\n";

    return 0;
}
