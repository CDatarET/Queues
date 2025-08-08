#include <stdio.h>
#define max 20
    //Task- to implement linear and circular queue in C

struct job{
    int jobId;
    char jobName[20];
    int priority;
};

int isFullLinear(int r){
    if(r >= max){
        return(1);
    }
    return(0);
}

void insertLinear(struct job Q[], int r){
    r++;
    if(isFullLinear(r)){
        printf("Queue is Full!\n");
        return;
    }
    printf("enter job id\n");
    scanf("%d", &Q[r].jobId);

    printf("enter job name\n");
    scanf("%s", Q[r].jobName);

    printf("enter job priority\n");
    scanf("%d", &Q[r].priority);
}

int isEmpty(int f, int r){
    if(f == r){
        return(1);
    }
    return(0);
}

void deleteLinear(struct job Q[], int f, int r){
    if(isEmpty(f, r)){
        printf("Queue is Empty!\n");
        return;
    }
    f++;
    printf("Deleted job is %s, ID# %d, with priority of %d\n", Q[f].jobName, Q[f].jobId, Q[f].priority);
}

void dispLinear(struct job Q[], int f, int r){
    printf("ID#\t Name\t Priority\n");
    for(int i = f + 1; i <= r; i++){
        printf("%d\t %s\t %d\n", Q[i].jobId, Q[i].jobName, Q[i].priority);
    }
}

int isFullCircular(int r, int f){
    if((r + 1) % max == f){
        return(1);
    }
    else{
        return(0);
    }
}

void insertCircular(struct job Q[], int f, int r){
    if(isFullCircular(r, f)){
        printf("Queue is Full!\n");
        return;
    }

    r = (r + 1) % max;
    printf("enter job id\n");
    scanf("%d", &Q[r].jobId);

    printf("enter job name\n");
    scanf("%s", Q[r].jobName);

    printf("enter job priority\n");
    scanf("%d", &Q[r].priority);
}

void deleteCircular(struct job Q[], int f, int r){
    if(isEmpty(f, r)){
        printf("Queue is empty!\n");
        return;
    }

    f = (f + 1) % max;
    printf("Deleted job is %s, ID# %d, with priority of %d\n", Q[f].jobName, Q[f].jobId, Q[f].priority);
}

void dispCircular(struct job Q[], int f, int r){
    printf("ID#\t Name\t Priority\n");
    for(int i = (f + 1) % 20; i <= r; i++){
        printf("%d\t %s\t %d\n", Q[i].jobId, Q[i].jobName, Q[i].priority);
    }
}

int main(){
    printf("Hello World\n");
    struct job LQ[max];
    int linearF = -1;
    int linearR = -1;

    struct job CQ[max];
    int circularF = 0;
    int circularR = 0;

    int run = 1;
    while(run){
        printf("Enter operation-\n");
        printf("1 for insert in Linear Queue\n");
        printf("2 for delete from Linear Queue\n");
        printf("3 for display Linear Queue\n");
        printf("4 for insert in Circular Queue\n");
        printf("5 for delete from Circular Queue\n");
        printf("6 for display Circular Queue\n");
        int operation;
        scanf("%d", &operation);
        switch(operation){
            case 1:
                insertLinear(LQ, linearR);
                linearR++;
                break;

            case 2:
                deleteLinear(LQ, linearF, linearR);
                linearF++;
                break;
            
            case 3:
                dispLinear(LQ, linearF, linearR);
                break;

            case 4:
                insertCircular(CQ, circularF, circularR);
                circularR = (circularR + 1) % 20;
                break;

            case 5:
                deleteCircular(CQ, circularF, circularR);
                circularF = (circularF + 1) % 20;
                break;

            case 6:
                dispCircular(CQ, circularF, circularR);
                break;

            default:
                printf("not a valid operation\n");
        }
        

        printf("perform another operation? 1 for yes 0 for no\n");
        scanf("%d", &run);
    }
    printf("Goodbye World\n");
    return(0);
}
