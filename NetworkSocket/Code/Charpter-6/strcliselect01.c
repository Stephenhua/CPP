#include	"unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	int			maxfdp1;
	fd_set		rset;
	char		sendline[MAXLINE], recvline[MAXLINE];
//用于检查可读性的描述符集。该集合由Fd_ZERo初始化，并用FD_SET打开两位：一位对应于标准I/O文件指针fp,
//一位对应于套接字sockfd，select值工作在描述符上，计算两个描述符中的较大值
	FD_ZERO(&rset);
	for ( ; ; ) {
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfdp1 = max(fileno(fp), sockfd) + 1;

        //调用select，在该调用中，写集合指针和异常集合指针都是空指针，最后一个参数也是空指针；
		Select(maxfdp1, &rset, NULL, NULL, NULL);
        ///如果select返回时套接字是可读的，那就先用ReadLine读入回射文本行，再用fputs输出它；
		if (FD_ISSET(sockfd, &rset)) {	/* socket is readable */
			if (Readline(sockfd, recvline, MAXLINE) == 0)
				err_quit("str_cli: server terminated prematurely");
			Fputs(recvline, stdout);
		}
        //如果标准输入可读，就先用fgets读入一行文本，再用written把它写到套接字中，
		if (FD_ISSET(fileno(fp), &rset)) {  /* input is readable */
			if (Fgets(sendline, MAXLINE, fp) == NULL)
				return;		/* all done */
			Writen(sockfd, sendline, strlen(sendline));
		}
	}
}
