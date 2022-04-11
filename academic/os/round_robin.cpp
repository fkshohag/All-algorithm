# include <bits/stdc++.h>
using namespace std;

void roundRobin(int n, int bt[],
                                    int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    int rem_bt[n];
    for (int i = 0 ; i < n ; i++) {
        rem_bt[i] = bt[i];
    }
 
    int t = 0; 
    while (1)
    {
        bool done = true;

        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; 
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
        break;
    }

    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
 
    cout << " P "<< " BT "
        << " WT " << " TAT\n";
 
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t" << bt[i] <<"\t "
            << wt[i] <<"\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n << endl;
}
 
int main()
{
    freopen("in.text", "r", stdin);

    int n;
    cin>>n;

    int BT[100];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &BT[i]);
    }
 
    // Time quantum
    int quantum = 2;
    roundRobin(n, BT, quantum);
    return 0;
}