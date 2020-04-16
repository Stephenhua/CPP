#include	"unp.h"

//完成客户处理循环：
void str_cli(FILE *fp, int sockfd)
{
        char	sendline[MAXLINE], recvline[MAXLINE];
    //从get读入一行文本，writeen把该行发送给服务器；
	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		Writen(sockfd, sendline, strlen(sendline));
        //从服务器读入回射行，fputs写到标准输出；
		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		Fputs(recvline, stdout);
	}
    //当遇到文件结束符或错误时，fgets将返回一个空指针，遇事客户处理循环终止；
}
