#include<stdio.h>
#define MAX 50;
struct pro {
    int wtime,arrtime,pno,ttime,extime,ftime,priority;
}p[50],t;
void sorta(int n){
    int i,j;
    for ( i = 0; i < n-1; i++){
        for ( j = 0; j < n-1-i; j++){
            if (p[j].arrtime>p[j+1].arrtime){
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
}
void sorts(int n,int i){
    int j;
    for(i;i<n-1;i++){
        for(j=i+1;j<n-1-i;j++){
            if(p[j].arrtime<=p[i].ftime||p[j+1].arrtime<=p[i].ftime){
                if (p[j].priority>p[j+1].priority){
                    t=p[j];
                    p[j]=p[j+1];
                    p[j+1]=t;
                }
            }
        }
    }
}
void display(int n){
    int i;
    printf("Process no\tArrival Time\tExecution Time\tPriority\tWaiting Time\tFinish Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
        if(i==0){
            p[i].wtime=0;
        }
        else{
            p[i].wtime=p[i-1].ftime-p[i].arrtime;
            if(p[i].wtime<0){ p[i].wtime=0;
            }
        }
            p[i].ftime=p[i].arrtime+p[i].extime+p[i].wtime;
            p[i].ttime=p[i].extime+p[i].wtime;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].arrtime,p[i].extime,p[i].priority,p[i].wtime,p[i].ftime,p[i].ttime);
        sorts(n,i);
    }
}
void main(){
    int n,i,j=0;
    printf("Enter the number of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        j++;
        p[i].pno=j;
        printf("\n Process No : %d",j);
        printf("\n Arrival time: ");
        scanf("%d",&p[i].arrtime);
        printf(" Execution time : ");
        scanf("%d",&p[i].extime);
        printf(" Priority:");
        scanf("%d",&p[i].priority);
    }
    sorta(n);
    display(n);
}


OUTPUT
--------
Enter the number of Processes : 5

 Process No : 1
 Arrival time: 4
 Execution time : 3
 Priority:2

 Process No : 2
 Arrival time: 1
 Execution time : 4
 Priority:3

 Process No : 3
 Arrival time: 5
 Execution time : 2
 Priority:1

 Process No : 4
 Arrival time: 2
 Execution time : 6
 Priority:4

 Process No : 5
 Arrival time: 3
 Execution time : 5
 Priority:2
Process no      Arrival Time    Execution Time  Priority        Waiting Time    Finish Time     Turn Around Time
2               1               4               3               0               5               4
5               3               5               2               2               10              7
3               5               2               1               5               12              7
1               4               3               2               8               15              11
4               2               6               4               13              21              19
