// First Come First Serve

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout<<"Enter number of requests: ";
    cin>>n;

    vector<int> request(n);

    cout<<"Enter request sequence: ";
    for(int i=0;i<n;i++){
        cin>>request[i];
    }

    int head;
    cout<<"Enter initial head position: ";
    cin>>head;

    int seek_time=0;

    cout<<"\nFCFS Order: ";

    for(int i=0;i<n;i++){
        cout<<request[i]<<" ";
        seek_time+=abs(head-request[i]);
        head=request[i];
    }

    cout<<"\nTotal Seek Time: "<<seek_time;

    return 0;
}
