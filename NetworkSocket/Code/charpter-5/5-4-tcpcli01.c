#include	"unp.h"
//回射客户程序
int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: tcpcli <IPaddress>");
    //创建一个TCP套接字，用服务器的IP地址和端口号填写一个网际网套接字
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
    //进行表达式变为数值，sin_addr指针用于存放二进制结果
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    //与服务器创建连接；
	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
