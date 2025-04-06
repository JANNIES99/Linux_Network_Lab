#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main(){
    int sockdesc,serverlength;
    struct sockaddr_in serveraddr;
    char smsg[200],cmsg[200];
    memset(smsg,'\0',sizeof(smsg));
    memset(cmsg,'\0',sizeof(cmsg));

    sockdesc=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(2000);
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    serverlength=sizeof(serveraddr);

    printf("Message for server:");
    fgets(cmsg,sizeof(cmsg),stdin);
    if(sendto(sockdesc,cmsg,sizeof(cmsg),0,(struct sockaddr*)&serveraddr,serverlength)<0){
        printf("Send message failed......!\n");
        return -1;
    }

    printf("Sending message successful....!\n");

    if(recvfrom(sockdesc,smsg,sizeof(smsg),0,(struct sockaddr*)&serveraddr,&serverlength)<0){
        printf("Receving message failed....!\n");
        return -1;
    }

    printf("Receving message successful....!\n");
    printf("Client message: %s\n",smsg);

}
