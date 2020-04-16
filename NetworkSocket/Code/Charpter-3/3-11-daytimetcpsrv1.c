#include	"unp.h"
#include	<time.h>

int
main(int argc, char **argv)
{
	int				listenfd, connfd;
    /* 称为值-结果变量*/
	socklen_t		len;
	char			buff[MAXLINE];
	time_t			ticks;

    /*存放客户的协议地址*/
	struct sockaddr_storage	cliaddr;

	if (argc != 2)
		err_quit("usage: daytimetcpsrv1 <service or port#>");
    
    //用listen监听；
	listenfd = Tcp_listen(NULL, argv[1], NULL);

	for ( ; ; ) {
        //初始化套接字地址结构的大小；
		len = sizeof(cliaddr);
        //将cliaddr结构指针作为第二个参数，len作为第三个；
		connfd = Accept(listenfd, (SA *)&cliaddr, &len);

        //inet_ntop将套接字地址结构中的323位IP地址准环卫一个点分十进制数的ASCII字符串，
        //ntohs将16位的端口号从网络字节序转换为主机字节序；
		printf("connection from %s\n", Sock_ntop((SA *)&cliaddr, len));

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		Write(connfd, buff, strlen(buff));

		Close(connfd);
	}
}
