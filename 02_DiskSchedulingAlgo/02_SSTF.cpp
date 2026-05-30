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

    vector<bool> visited(n,false);

    int seek_time=0;

    cout<<"\nSSTF Order: ";

    for(int i=0;i<n;i++){

        int minimum=INT_MAX;
        int index=-1;

        for(int j=0;j<n;j++){
            if(!visited[j] && abs(head-request[j])<minimum){
                minimum=abs(head-request[j]);
                index=j;
            }
        }

        visited[index]=true;

        cout<<request[index]<<" ";

        seek_time+=abs(head-request[index]);

        head=request[index];
    }

    cout<<"\nTotal Seek Time: "<<seek_time;

    return 0;
}