#include <stdio.h>
typedef struct {
    int no;
    int at;
    int ct;
    int bt;
    int wt;
    int tt;
} process;
void calculate(process p2[], int n,) {
    int wt_total = 0;
    int tt_total = 0;
    int i;
    p2[0].ct=p2[0].at+p2[0].bt;
    for(i=1;i<n;i++){
        if(p2[i].at<p2[i-1].ct){
            p2[i].ct=p2[i-1].ct+ p2[i].bt;
        }
        else{
            p2[i].ct=p2[i].bt+ p2[i].at;
        }
    }
    for(i=0;i<n;i++){
        p2[i].tt=p2[i].ct -p2[i].at;
        p2[i].wt=p2[i].tt -p2[i].bt;
    }
    for (i=0;i<n;i++){
        wt_total += p2[i].wt;
        tt_total += p2[i].tt;
    }

    float wt_avg = (float) wt_total / n;
    float tt_avg = (float) tt_total / n;

    printf("\nProcess\t  Arrival Time\t  Burst Time\t completion time\t  Waiting Time\t  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p2[i].no, p2[i].at, p2[i].bt, p2[i].ct, p2[i].wt, p2[i].tt);
    }
    printf("\nAverage Waiting Time = %f\n", wt_avg);
    printf("Average Turnaround Time = %f\n", tt_avg);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process p1[n];
    printf("Enter AT and BT:\n");
    for (int i = 0; i < n; i++) {
        p1[i].no = i + 1;
        printf("Process %d:\n", p1[i].no);
        printf("Arrival Time: ");
        scanf("%d", &p1[i].at);
        printf("Burst Time: ");
        scanf("%d", &p1[i].bt);
    }
    calculate(p1, n,);
    return 0;
}
/*
COMPLETION TIME:
    total time taken by process to execute on CPU, which includes its waiting period
WAITING TIME:
      Time taken by process in whuch its ready to execute , but waits for earlier ones to get executed on CPU
 TURNAROUND TIME:
      Time talkemn by process to execute
      formula :
          TURNAROUND TIME:WAITING TIME +COMPLETION TIME

*/