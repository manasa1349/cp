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

}
int main(){
    Job job[]={{1, 4, 20}, {2, 1, 1}, {3, 1, 40}, {4, 1, 30}};
    int n=sizeof(job)/sizeof(job[0]);
    int cnt=0;
    int ans=0;
    int jobid[n];
    JobScheduling(job,n,ans,cnt,jobid);
    printf("MaxProfit: %d",ans);
    printf("No.of Jobs: %d",cnt);
    printf("Jobs done are:");
    for(int i=0;i<cnt;i++){
        
    }
}
