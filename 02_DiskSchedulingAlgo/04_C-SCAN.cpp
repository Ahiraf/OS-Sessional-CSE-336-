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

    int head,disk_size;

    cout<<"Enter initial head position: ";
    cin>>head;

    cout<<"Enter disk size: ";
    cin>>disk_size;

    vector<int> left,right;

    left.push_back(0);
    right.push_back(disk_size-1);

    for(int i=0;i<n;i++){
        if(request[i]<head)
            left.push_back(request[i]);
        else
            right.push_back(request[i]);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int seek_time=0;

    cout<<"\nC-SCAN Order: ";

    for(int i=0;i<right.size();i++){
        cout<<right[i]<<" ";
        seek_time+=abs(head-right[i]);
        head=right[i];
    }

    head=0;
    seek_time+=(disk_size-1);

    for(int i=0;i<left.size();i++){
        cout<<left[i]<<" ";
        seek_time+=abs(head-left[i]);
        head=left[i];
    }

    cout<<"\nTotal Seek Time: "<<seek_time;

    return 0;
}