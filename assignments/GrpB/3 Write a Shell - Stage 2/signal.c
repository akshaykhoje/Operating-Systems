// #include <stdio.h>
// #include <signal.h>

// int *p = 1234, i = 1234;

// void seg_handler(int signo)
// {
//     printf("signo : %d\n", signo);
//     printf("Seg fault occurred\n");
//     return;
// }

// void int_handler(int signo)
// {
//     printf("signo : %d\n", signo);
//     printf("INT signal received\n");
//     return;
// }

// int main(void)
// {
//     signal(SIGINT, int_handler);
//     getchar();
//     i=10;
//     signal(SIGSEGV, seg_handler);
//     *p = 100;
//     return 0;
// }

#include<stdio.h>
#include<signal.h>
  
// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
}
  
int main()
{
    signal(SIGSTOP, handle_sigint);
    while (1) ;
    return 0;
}