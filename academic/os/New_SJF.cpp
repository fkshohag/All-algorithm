#include <bits/stdc++.h>
#define Mx 50

using namespace std;


struct Process
{
    int id;
    int At;
    int Bt;
    int Ct;
    int Wt;
    int Tat;

    void P(){};

    void print()
    {
        cout<<"Process ID = "<<id<<" AT = "<<At<<" BT = "<<Bt<<" CT = "<<Ct<<" WT = "<<Wt<<" TAT = "<<Tat<<endl;
    }
};

Process P[Mx];

/// FCFS       /// Priority Scheduling


/// SJF
bool operator < (const Process& A, const Process& B )
{
   return A.Bt < B.Bt;
}

/// FCFS

int main()
{
    freopen("in.text", "r", stdin);

    int numberOfprocess,x,y;


    cin>>numberOfprocess;
    for(int i=0;i<numberOfprocess;i++)
    {
        scanf("%d%d",&P[i].At,&P[i].Bt);
        P[i].id = i+1;
    }


    vector<Process>ReadyQ; /// Already Arrived Process.
                     /// Current Time
                     /// Queue Data Structure use,
                     /// Priority Queue or anything

    vector<Process>Complete; /// Already Terminated,

    int curtime=-1,infi=1000000,j=0;
    /// j variable nxt process k track / point kore

//    while(curtime<infi)
    while(1)
    {

        if(ReadyQ.size()==0){curtime = max(curtime, P[j].At); }

        while(j<numberOfprocess && P[j].At<=curtime)
        {
            ReadyQ.push_back(P[j]);
            j++;
        }

        sort(ReadyQ.begin(),ReadyQ.end());
        reverse(ReadyQ.begin(),ReadyQ.end());

        /// Print ReadyQ after reverse
//        for(int i=0;i<ReadyQ.size();i++)
//        {
//            ReadyQ[i].print();
//        }

//        cout<<"Current Time = "<<curtime<<"\n";

        // CPU_te_Running_Process
        Process P1 = ReadyQ.back();
        ReadyQ.pop_back();


        P1.Ct = curtime + P1.Bt;
        P1.Wt = P1.Ct - P1.At - P1.Bt;
        P1.Tat = P1.Ct - P1.At;

        Complete.push_back(P1);

        curtime = curtime + P1.Bt;

        if(Complete.size()==numberOfprocess)break;


    }



    for(int i=0;i<numberOfprocess;i++)
    {

        Complete[i].print();
    }



}

/*

4
0 2
1 2
6 10
7 5


4
0 6
0 8
0 7
0 3'


3
0 7
10 12
15 3

*/


