#include	"unp.h"

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
    //创建一个TCP套接字，
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;

    //在网际网套接字地址结构中填入通配地址（INADDR_ANY）
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    //服务器众所周知端口；
	servaddr.sin_port        = htons(SERV_PORT);

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	for ( ; ; ) {

        //服务器阻塞于accept调用，等待客户连接完成；

		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);

        //派生子进程；
		if ( (childpid = Fork()) == 0) {	/* child process */
            //关闭监听套接字，父进程关禁闭已连接套接字；
			Close(listenfd);	/* close listening socket */
			str_echo(connfd);	/* process the request */
			exit(0);
		}
		Close(connfd);			/* parent closes connected socket */
	}
}
