#include<stdio.h>
#include<stdlib.h>

int main(){
    int buffersize,in,out,bucket=0,n,drop;
    printf("Enter the buffer size:");
    scanf("%d",&buffersize);
    printf("Enter the no of inputs:");
    scanf("%d",&n);
    printf("Enter the output rate:");
    scanf("%d",&out);

    for(int i=0;i<n;i++){
        printf("Enter the input size:");
        scanf("%d",&in);
        if(in<=(buffersize-bucket)){
            bucket+=in;
            printf("After input %d of %d is filled..\n",bucket,buffersize);
        }
        else{
            drop=in+bucket-buffersize;
            bucket=buffersize;
            printf("After input %d of %d is filled..and %d is dropped..\n",bucket,buffersize,drop);
        }
        bucket-=out;
        printf("After output %d of %d is filled..\n",bucket,buffersize);
    }

}
