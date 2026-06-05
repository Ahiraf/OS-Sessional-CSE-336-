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

    vector<int> left,right;

    for(int i=0;i<n;i++){
        if(request[i]<head)
            left.push_back(request[i]);
        else
            right.push_back(request[i]);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int seek_time=0;

    cout<<"\nC-LOOK Order: ";

    for(int i=0;i<right.size();i++){
        cout<<right[i]<<" ";
        seek_time+=abs(head-right[i]);
        head=right[i];
    }

    if(!left.empty()){
        seek_time+=abs(head-left[0]);
        head=left[0];
    }

    for(int i=0;i<left.size();i++){
        cout<<left[i]<<" ";
        seek_time+=abs(head-left[i]);
        head=left[i];
    }

    cout<<"\nTotal Seek Time: "<<seek_time;

    return 0;
}