#include	"unp.h"

void
//处理每个客户的服务：从客户读入数据，并把他们回射给客户；
str_echo(int sockfd)
{
	ssize_t		n;
	char		buf[MAXLINE];

again:
    //read函数从套接字读入数据，如果接收到客户的FIN将导致服务器子进程的read函数返回0；
	while ( (n = read(sockfd, buf, MAXLINE)) > 0)
        //written函数把其中内容回射给客户，
		Writen(sockfd, buf, n);

	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_sys("str_echo: read error");
}
