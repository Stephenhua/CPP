 #include <winsock2.h>
#include <iostream>
using namespace std;

//创建socket
int socket(int domian, int type ,int protocol){

}

//将socket绑定到地址：bind（）；

int bind(int sockfd, const struct sockaddr *addr ,socklen_t addrlen);

//监听接入连接
int listen( int sockfd ,int backlog );

//接收accept（）

int accept( int sockfd, struct dokaddr* ,socklen_t* addrlen);


//连接到对等的socket：：connec（）

int connect( int sockfd , const struct sockaddr *addr ,soklen_t addrlen);
struct sockaddr_un{
    sa_familt_t sun_family;

    char sum_path[108];
};

int main ( int argc,char *argv[]){
    struct sockaddr_un addr;
    int sfd ,cfd;

    ssize_t numRead;

    sfd = scoket( AF_UNIX ,SOCK_STREAM ，0)；

    if(sfd == -1){

        errExit("socket");
    }

    if(remove(SV_SOCK_PA))

}