# include <bits/stdc++.h>
# define MX 50

using namespace std;

struct Process
{
    int id;
    int At;
    int Bt;
    int Ct;
    int Wt;
    int Rt;
    int Tat;
    int Pr;

    void P(){};

    void print()
    {
        cout<<"Process ID = "<<id<<" AT = "<<At<<" BT = "<<Bt<<" Rt = "<<Rt<<" CT = "<<Ct<<" WT = "<<Wt<<" TAT = "<<Tat<<" PR = "<<Pr<<endl;
    } 
};

Process P[MX];

// Priority Scheduling

bool operator < (const Process& A, const Process& B )
{
   return A.Pr < B.Pr;
}

/// Priority Scheduling
vector<int>Tim[100000];
priority_queue<Process>Q;

int main()
{
    // freopen("in.text", "r", stdin);
    int numberOfprocess, x, y;

    cin>>numberOfprocess;
    for(int i = 0; i < numberOfprocess; i++)
    {
        scanf("%d %d %d",&P[i].At, &P[i].Bt, &P[i].Pr);
        P[i].id = i+1;
        Q.push(P[i]);
    }

   vector<Process>ReadyQ; 
   vector<Process>Complete; 

   int curtime = -1, infi = 1000000, j = 0;

   while(1)
   {

       if(ReadyQ.size() == 0) { 
            curtime = max(curtime, P[j].At); 
        }

       while(j < numberOfprocess && P[j].At <= curtime)
       {
           ReadyQ.push_back(P[j]);
           j++;
       }

       sort(ReadyQ.begin(), ReadyQ.end());
       reverse(ReadyQ.begin(), ReadyQ.end());

       Process P1 = ReadyQ.back();
       ReadyQ.pop_back();


       P1.Ct = curtime + P1.Bt;
       P1.Wt = P1.Ct - P1.At - P1.Bt;
       P1.Tat = P1.Ct - P1.At;

       Complete.push_back(P1);

       curtime = curtime + P1.Bt;

       if(Complete.size() == numberOfprocess) {
        break;
       }
   }

   for(int i = 0; i < Complete.size(); i++)
   {
       Complete[i].print();
   }
}

/*
    Input 
    4
    0 8 1
    0 4 3
    0 9 2
    0 5 4
*/

//    0 1 2 3



