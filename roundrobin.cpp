#include <iostream>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <queue>

using namespace std;
class Process{ // Process Object Template4

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

bool compareAT(Process a,Process b){
    return a.AT < b.AT;
}
// round robin
bool compare1(Process p1, Process p2) 
{ 
    return p1.AT < p2.AT;
}


void roundRobin(){
    int n;
    cout <<"Enter the number of process: ";
    cin >> n;
    Process p[n];
    cout << "Enter the AT and BT for each process \b";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].AT >> p[i].BT;
        p[i].n = i + 1;
        p[i].RT = p[i].BT;
    }
    cout << "Enter the time quantum/slice: ";
    int tq;
    cin >> tq;
    sort(p,p+n,compare1);
    queue<int> q;
    int currTime = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    //memset(mark,0,sizeof(mark));
    mark[0] = 1;
    
    while(completed != n){
        int idx = q.front();
        q.pop();
        if(p[idx].RT - tq > 0) {
            p[idx].RT -= tq;
            currTime += tq;
        }else{
            currTime += p[idx].RT;
            p[idx].RT = 0;
            p[idx].CT = currTime;
            completed++;
        }

        for(int i = 1; i < n; i++) {
            if(p[i].RT > 0 && p[i].AT <= currTime && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(p[idx].RT > 0) {
            q.push(idx);
        }
        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(p[i].RT > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }

    print(p,n);  
    int avgWT = 0;
    int avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        avgWT += p[i].WT;
        avgTAT += p[i].TAT;
    }
    cout << "\n";
    cout << "Average Waiting Time is : "<< avgWT/n;
    cout << "\nAverage Waiting Time is : "<< avgTAT/n;  
    
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