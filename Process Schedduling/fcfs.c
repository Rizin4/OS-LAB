#include <stdio.h>
#include <conio.h>

int main(){
    int i,j,n,tat[20],wt[20],bt[20];
    float avgwt=0,avgtat=0;
    
    printf("Number of processes: ");
    scanf("%d",&n);
    
    printf("Enter burst time:\n");
    for(i=0;i<n;i++){
        printf("P[%d]: ",i+1);
        scanf("%d",&bt[i]);
    }
    printf("Processes\t Burst time\t Waiting time\t Turn around time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        
        for(j=0;j<i;j++)
        {
            wt[i]+=bt[j];
        }
        tat[i]=wt[i]+bt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
        
        printf("P[%d]\t\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    avgwt=avgwt/n;
    avgtat/=n;
    printf("\n\tAverage Wating time = %f",avgwt);
    printf("\n\tAverage turn around time = %f",avgtat);

    
    return 0;    
}