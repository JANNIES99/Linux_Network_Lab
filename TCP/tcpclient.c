#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
    int sockdesc;
    struct sockaddr_in serveraddr;
    char smsg[200],cmsg[200];

    memset(smsg,'\0',sizeof(smsg));
    memset(cmsg,'\0',sizeof(cmsg));

    sockdesc=socket(AF_INET,SOCK_STREAM,0);

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(2000);
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(sockdesc<0){
        printf("socket failed......!\n");
    }
    printf("socket creation successful.......!\n");

    if(connect(sockdesc,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        printf("connection failed.......!\n");
        return -1;
    }

    printf("connection successful......!\n");

    printf("Message for server:");
    fgets(cmsg,sizeof(cmsg),stdin);
    if(send(sockdesc,cmsg,sizeof(cmsg),0)<0){
        printf("Send message failed......!\n");
        return -1;
    }

    printf("Sending message successful....!\n");
    if(recv(sockdesc,smsg,sizeof(smsg),0)<0){
        printf("Receving message failed....!\n");
        return -1;
    }
    printf("Receving message successful....!\n");
    printf("Server message: %s\n",smsg);


}
