#include<stdio.h>
#include<stdlib.h>
typedef struct Job{
    int id;
    int dead;
    int profit;
}Job;
int cmp(const void *a,const void *b){
    Job *a1=(Job *)a;
    Job *a2=(Job *)b;
    return a2->profit - a1->profit;
}
void JobScheduling(Job arr[],int n,int *ans,int *cnt,int jobid[]){
    qsort(arr,n,sizeof(Job),cmp);
    int max=0;
    int i,j;
    for(i=0;i<n;i++){
        if(arr[i].dead>max){
            max=arr[i].dead;
        }
    }
    int *li=(int *)malloc(max*sizeof(int));
    //int *li=(int *)calloc(max,sizeof(int));
    for(i=0;i<max;i++){
        li[i]=-1;
    }
    *ans=0;
    *cnt=0;
    for(i=0;i<n;i++){
        for(j=arr[i].dead-1;j>=0;j--){
            if(li[j]==-1){
                li[j]=1;
                *ans+=arr[i].profit;
                jobid[(*cnt)++]=arr[i].id;
                break;
            }
        }
    }
}
int main(){
    Job job[]={{1, 4, 20}, {2, 1, 1}, {3, 1, 40}, {4, 1, 30}};
    int n=sizeof(job)/sizeof(job[0]);
    int cnt=0;
    int ans=0;
    int jobid[n];
    JobScheduling(job,n,&ans,&cnt,jobid);
    printf("MaxProfit: %d\n",ans);
    printf("No.of Jobs: %d\n",cnt);
    printf("Jobs done are:");
    int i;
    for(i=0;i<cnt;i++){
        printf("%d ",jobid[i]);
    }
}
/*
    Job job[]={{1, 4, 20}, {2, 1, 1}, {3, 1, 40}, {4, 1, 30}};
    MaxProfit: 60
    No.of Jobs: 2
    Jobs done are:3 1 
*/
