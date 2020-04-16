/* include signal */
#include	"unp.h"

//第二个参数和返回值都是指向信号处理函数的指针
Sigfunc * signal(int signo, Sigfunc *func)
{
	struct sigaction	act, oact;

    //sigaction中的sa_handler被设置为func函数；
	act.sa_handler = func;
    //设置处理函数的信号掩码
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
    //设置SA_RESTART函数；
	if (signo == SIGALRM) {
#ifdef	SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;	/* SunOS 4.x */
#endif
	} else {
#ifdef	SA_RESTART
		act.sa_flags |= SA_RESTART;		/* SVR4, 44BSD */
#endif
	}
    //调用sigaction函数
	if (sigaction(signo, &act, &oact) < 0)
		return(SIG_ERR);
	return(oact.sa_handler);
}
/* end signal */

Sigfunc *
Signal(int signo, Sigfunc *func)	/* for our signal() function */
{
	Sigfunc	*sigfunc;

	if ( (sigfunc = signal(signo, func)) == SIG_ERR)
		err_sys("signal error");
	return(sigfunc);
}
