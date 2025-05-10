#include<stdio.h>
#define MAX 50;
struct pro {
    int wtime,arrtime,pno,ttime,extime,ftime;
}p[50],t;
void sort(int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(p[j].arrtime>p[j+1].arrtime){
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
}

void display(int n){
    int i;
    printf("Process no\tArrival Time\tExecution Time\tWaiting Time\tCompletion Time\tTurn Around Time\n");
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
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].arrtime,p[i].extime,p[i].wtime,p[i].ftime,p[i].ttime);
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
    sort(n);
    display(n);
}





OUTPUT
-------

Enter the number of Processes : 5

 Process No : 1
 Arrival time: 4
 Execution time : 3

 Process No : 2
 Arrival time: 2
 Execution time : 6

 Process No : 3
 Arrival time: 1
 Execution time : 9

 Process No : 4
 Arrival time: 5
 Execution time : 6

 Process No : 5
 Arrival time: 7
 Execution time : 2
Process no      Arrival Time    Execution Time  Waiting Time    Completion Time Turn Around Time
3               1               9               0               10              9
2               2               6               8               16              14
1               4               3               12              19              15
4               5               6               14              25              20
5               7               2               18              27              20
