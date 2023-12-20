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
