#include<stdio.h>
int main(){
    int ms,ps,pages,np,pr[20],pt[50],im,pm,offset,i,j,k=0,temp=0;
    printf("enter the memory size:");
    scanf("%d",&ms);
    printf("enter the page size:");
    scanf("%d",&ps);
    pages=ms/ps;
    printf("\nno of pages available:%d\n\n",pages);
    printf("enter the number of processes:");
    scanf("%d",&np);
    for(i=0;i<np;i++){
        printf("enter the number of pages for p[%d]:",i+1);
        scanf("%d",&pr[i]);
        temp=temp+pr[i];
        if(temp>pages){
            printf("memory is full\n");
            break;
        }
        else{
            printf("enter the pages to frame:");
            for(j=0;j<pr[i];j++){
                scanf("%d",&pt[k]);
                k++;
            }
        }
    }
    printf("physical address\n");
    x:k=0;
    printf("page no:");
    scanf("%d",&i);
    printf("offset:");
    scanf("%d",&offset);
    pm=pt[i-1]*ps+offset;
    printf("physical memory of the page:%d",pm);
    printf("\ndo you want to continue(yes=1,no=0):");
    scanf("%d",&k);
    if (k==1)
    {
        goto x;
    }
    else
    {
        return 0;
    }
    return 0;
}



OUTPUT
--------
enter the memory size:1000
enter the page size:100
no of pages available:10

enter the number of processes:3
enter the number of pages for p[1]:4
enter the pages to frame:5 6 7 3
enter the number of pages for p[2]:3
enter the pages to frame:2 8 4
enter the number of pages for p[3]:6
memory is full
physical address
page no:5
offset:23
physical memory of the page:223
do you want to continue(yes=1,no=0):1
page no:6
offset:45
physical memory of the page:845
do you want to continue(yes=1,no=0):0
