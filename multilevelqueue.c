#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int n,pid[10],bt[10],type[10],at[10],wt[10],tat[10],i,j;
    float avg_wt=0,avg_tat=0;
    printf("Enter the total number of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the process id, type of process(user-0 and system-1), arrival time and burst time\n");
        scanf("%d",&pid[i]);
        scanf("%d",&type[i]);
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&type[j],&type[j+1]);

            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]==at[j+1] && type[j]<type[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&pid[j],&pid[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&type[j],&type[j+1]);
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1]-at[i-1];
    }
    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }
    printf("Process id\tType\tarrival time\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++)
    {
        avg_tat+=tat[i];
        avg_wt+=wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],type[i],at[i],bt[i],wt[i],tat[i]);
    }
    printf("average waiting time =%f",avg_wt/n);
    printf("average turnaround time =%f",avg_tat/n);

}
