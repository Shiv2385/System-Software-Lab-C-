#include<stdio.h>
#define MAX 50;
struct pro {
    int wtime,arrtime,pno,ttime,extime,ftime;
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
            if(p[j].arrtime<p[i].ftime||p[j+1].arrtime<p[i].ftime){
                if (p[j].extime>p[j+1].extime){
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
    printf("Process no\tArrival Time\tExecution Time\tWaiting Time\tFinish Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
        if(i==0){
            p[i].wtime=0;
            p[i].ftime=p[i].arrtime+p[i].extime+p[i].wtime;
            p[i].ttime=p[i].extime+p[i].wtime;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].arrtime,p[i].extime,p[i].wtime,p[i].ftime,p[i].ttime);
        }
        else{
            p[i].wtime=p[i-1].ftime-p[i].arrtime;
            if(p[i].wtime<0){ p[i].wtime=0;
            }
            p[i].ftime=p[i].arrtime+p[i].extime+p[i].wtime;
            p[i].ttime=p[i].extime+p[i].wtime;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].arrtime,p[i].extime,p[i].wtime,p[i].ftime,p[i].ttime);
        }
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
    }
    sorta(n);
    display(n);
}


OUTPUT
-------
Enter the number of Processes : 5

 Process No : 1
 Arrival time: 4
 Execution time : 3

 Process No : 2
 Arrival time: 5
 Execution time : 9

 Process No : 3
 Arrival time: 1
 Execution time : 6

 Process No : 4
 Arrival time: 2
 Execution time : 8

 Process No : 5
 Arrival time: 3
 Execution time : 2
Process no      Arrival Time    Execution Time  Waiting Time    Finish Time     Turn Around Time
3               1               6               0               7               6
5               3               2               4               9               6
1               4               3               5               12              8
4               2               8               10              20              18
2               5               9               15              29              24
