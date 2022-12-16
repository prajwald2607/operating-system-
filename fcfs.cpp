#include <iostream>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <queue>

using namespace std;
class Process{ // Process Object Template
    public:
    int n; // process id
    int AT;
    int BT;
    int WT;
    int TAT; 
    int CT;
    int PR;// Priority - higher number higher priority.
    int RT;  // burst remaining time
    Process(){}

    void findTATandWT(){
        TAT = CT - AT;
        WT = TAT - BT;
    }
};
void print(Process p[],int n){
    cout << "Prc \t AT \t BT \t CT \t TAT \t WT \t"<< endl;
    for(int i = 0;i < n;i++){
            p[i].findTATandWT();
            cout << p[i].n <<" \t ";
            cout << p[i].AT <<" \t ";
            cout << p[i].BT <<" \t ";
            cout << p[i].CT <<" \t ";
            cout << p[i].TAT<<" \t ";
            cout << p[i].WT <<" \t ";
            cout << "\n";
        }
}

void FCFSwithoutAT(){ // done
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];
    cout << "Enter Burst Time for every processes: \n";
    for (int i = 0; i < n; i++)
    { 
        cin >> p[i].BT;
        p[i].n = i + 1;
        p[i].AT = 0;  // without AT means at time 0 all processes has been arrived in ready queue.
    }

    int currTime = 0;
    for (int i = 0; i < n; i++)
    {
        currTime += p[i].BT;
        p[i].CT = currTime;
    }
    print(p,n);  
    float avgWT = 0;
    float avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        avgWT += p[i].WT;
        avgTAT += p[i].TAT;
    }
    cout << "\n";
    cout << "Average Waiting Time is : "<< avgWT/n;
    cout << "\nAverage Waiting Time is : "<< avgTAT/n;  
}

bool compareAT(Process a,Process b){
    return a.AT < b.AT;
}

int main(){ 
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process p[n];
    cout << "Enter Arrival Time and Burst Time for every processes: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].AT;
        cin >> p[i].BT;
        p[i].n = i + 1;
    }
    int currTime = 0;
    sort(p,p+n,compareAT); // sorting according to AT
    int complete = 0; // how many process completed
    int i = 0;
    while(complete != n){
        if(p[i].AT <= currTime){
            currTime += p[i].BT;
            p[i].CT = currTime;
            complete++;
            i++;
        }else{
            currTime++;
        } 
    }
    print(p,n);  
    float avgWT = 0;
    float avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        avgWT += p[i].WT;
        avgTAT += p[i].TAT;
    }
    cout << "\n";
    cout << "Average Waiting Time is : "<< avgWT/n;
    cout << "\nAverage Waiting Time is : "<< avgTAT/n;  
}