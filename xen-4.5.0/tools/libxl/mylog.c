#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <mylog.h>
int log_out(char* flog, char *file, int line, char* fmt, ...)
{
    va_list arg;
    char pre[128], tmp[1024];
    long clock;
    struct tm *c_ptr;
    FILE *fp;
    time( &clock );
    c_ptr = localtime(&clock);
    sprintf( pre, "[%04d%02d%02d%02d%02d%02d_%s_%d]",
    c_ptr->tm_year+1900, c_ptr->tm_mon+1, c_ptr->tm_mday,
    c_ptr->tm_hour, c_ptr->tm_min, c_ptr->tm_sec, file, line );
    va_start(arg, fmt);
    vsprintf(tmp, fmt, arg);
    va_end (arg);
    //log to stdout
    if( !flog ){
    	printf( "%-32.32s %s", pre, tmp );
    	return 0;
    }
    //log to file
    if( !(fp = fopen( flog, "at" ) ) )
    	return -1;

    fprintf( fp, "%-34s %s", pre, tmp );
    fclose( fp );
    return 0;
} 
