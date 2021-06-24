#include <errno.h> /* for definition of errno */
#include <stdarg.h> /* ISO C variable aruments */
#include <stdlib.h>
#include <cstring>
#include <stdio.h>

#define MAXLINE 1024

/*
 * Nonfatal error related to a system call.
 * Print a message and return.
 */
void err_ret(const char *fmt, ...);


/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char *fmt, ...);
void err_sys_printf_noly(const char *fmt, ...);

/*
 * Fatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * Print a message and terminate.
 */
void err_exit(int error, const char *fmt, ...);


/*
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */
void err_dump(const char *fmt, ...);


/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */
void err_msg(const char *fmt, ...);


/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char *fmt, ...);


/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */
void err_doit(int errnoflag, int error, const char *fmt, va_list ap);