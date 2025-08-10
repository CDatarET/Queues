#include <stdio.h>
#define max 5
    //Task- to implement linear and circular queue in C

struct job{
    int jobId;
    char jobName[20];
    int priority;
};

int isFullLinear(int r){
    if(r == max - 1){
        return(1);
    }
    return(0);
}

int insertLinear(struct job Q[], int r){
    if(isFullLinear(r)){
        printf("Queue is Full!\n");
        return(r);
    }
    r++;
    printf("enter job id\n");
    scanf("%d", &Q[r].jobId);

    printf("enter job name\n");
    scanf("%s", Q[r].jobName);

    printf("enter job priority\n");
    scanf("%d", &Q[r].priority);
    return(r);
}

int isEmpty(int f, int r){
    if(f == r){
        return(1);
    }
    return(0);
}

int deleteLinear(struct job Q[], int f, int r){
    if(isEmpty(f, r)){
        printf("Queue is Empty!\n");
        return(f);
    }
    f++;
    printf("Deleted job is %s, ID# %d, with priority of %d\n", Q[f].jobName, Q[f].jobId, Q[f].priority);
    return(f);
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
    return(0);
}

int insertCircular(struct job Q[], int f, int r){
    if(isFullCircular(r, f)){
        printf("Queue is Full!\n");
        return r;
    }

    r = (r + 1) % max;
    printf("enter job id\n");
    scanf("%d", &Q[r].jobId);

    printf("enter job name\n");
    scanf("%s", Q[r].jobName);

    printf("enter job priority\n");
    scanf("%d", &Q[r].priority);
    return r;
}

int deleteCircular(struct job Q[], int f, int r){
    if(isEmpty(f, r)){
        printf("Queue is empty!\n");
        return(f);
    }

    f = (f + 1) % max;
    printf("Deleted job is %s, ID# %d, with priority of %d\n", Q[f].jobName, Q[f].jobId, Q[f].priority);
    return(f);
}

void dispCircular(struct job Q[], int f, int r){
    printf("ID#\t Name\t Priority\n");
    for(int i = f + 1; i <= ((r + 1) % max) - 1; i++){
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
                linearR = insertLinear(LQ, linearR);
                break;

            case 2:
                linearF = deleteLinear(LQ, linearF, linearR);
                break;
            
            case 3:
                dispLinear(LQ, linearF, linearR);
                break;

            case 4:
                circularR = insertCircular(CQ, circularF, circularR);
                break;

            case 5:
                circularF = deleteCircular(CQ, circularF, circularR);
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
