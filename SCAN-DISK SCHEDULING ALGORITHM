#include<stdio.h>
#include<stdlib.h>
int main(){
    int nr,n,i,initial,total=0,tr[100],temp,j,k,loc=0;
    float avg;
    printf("Enter the number of track requests: ");
    scanf("%d",&nr);
    printf("Enter the intial head position : ");
    scanf("%d",&initial);
    printf("Enter the track requests :\n ");
    for(i=0;i<nr;i++){
        scanf("%d",&tr[i]); 
    }
    for(j=0;j<nr;j++){
        for(k=0;k<nr-1;k++){
            if(tr[k]<tr[k+1]){
                temp=tr[k];
                tr[k]=tr[k+1];
                tr[k+1]=temp; 
            }
        }
    }
    for(j=0;j<nr;j++){
        if(tr[j]<initial){
            loc=j;
            break;
        }
    }
    if(loc!=0){
        tr[nr]=0;
    }
    printf("%d",initial);
    for(i=loc;i<=nr;i++){
        if((loc==0)&&(i==nr)){
            break;
        }
        printf("---->%d",tr[i]);
        total=total+abs(tr[i]-initial);
        initial=tr[i];
    }
    for(i=loc-1;i>=0;i--){
            printf("---->%d",tr[i]);
            total=total+abs(tr[i]-initial);
            initial=tr[i];
    }
    avg=total/nr;
    printf("\n Total seek time : %d",total);
    printf("\n Avg seek time : %f",avg);
    return 0;
}


OUTPUT
-------
Enter the number of track requests: 8
Enter the intial head position : 50
Enter the track requests : 
176
79
34
60
92
28
11
114
50---->34---->28---->11---->0---->60---->79---->92---->114---->176
 Total seek time : 226
 Avg seek time : 28.000000
