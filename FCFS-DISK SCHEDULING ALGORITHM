#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nr,n,i,initial,total,tr[100],temp;
    float avg;
    printf("Enter the number of track requests: ");
    scanf("%d",&nr);
    printf("Enter the intial head position : ");
    scanf("%d",&initial);
    printf("Enter the track requests :\n ");
    for(i=0;i<nr;i++){
        scanf("%d",&tr[i]);
    }
    total=0;
    printf("%d",initial);
    for(i=0;i<nr;i++){
        printf("----->%d",tr[i]);
        total=total+abs(tr[i]-initial);
        initial=tr[i];
    }
    avg=total/nr;
    printf("\n Total seek time : %d",total);
    printf("\n average seek time : %f\n",avg);
    return 0;
}


OUTPUT
--------
Enter the number of track requests: 8
Enter the intial head position : 50
Enter the track requests : 
176
79
34
60
92
2
11
114
50----->176----->79----->34----->60----->92----->2----->11----->114
 Total seek time : 528
 average seek time : 66.000000
