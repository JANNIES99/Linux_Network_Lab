#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main(){
    int sockdesc,clientlength;
    struct sockaddr_in serveraddr,clientaddr;
    char smsg[200],cmsg[200];
    memset(smsg,'\0',sizeof(smsg));
    memset(cmsg,'\0',sizeof(cmsg));

    sockdesc=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(2000);
    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(bind(sockdesc,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        printf("binding failed.......!\n");
        return -1;
    }
    clientlength=sizeof(clientaddr);
    if(recvfrom(sockdesc,cmsg,sizeof(cmsg),0,(struct sockaddr*)&clientaddr,&clientlength)<0){
        printf("Receving message failed....!\n");
        return -1;
    }

    printf("Receving message successful....!\n");
    printf("Client message: %s\n",cmsg);
    printf("Message for server:");
    fgets(smsg,sizeof(smsg),stdin);
    if(sendto(sockdesc,smsg,sizeof(smsg),0,(struct sockaddr*)&clientaddr,clientlength)<0){
        printf("Send message failed......!\n");
        return -1;
    }

    printf("Sending message successful....!\n");
}
