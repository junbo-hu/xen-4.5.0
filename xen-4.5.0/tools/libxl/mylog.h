#ifndef _MYMSG_LOG_H_
#define _MYMSG_LOG_H_
#define LOG_FILE "/tmp/xen.log"
#define PHYLOG( fmt, ... ) log_out( LOG_FILE, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_TOXFILE( flog, fmt, ... ) log_out( flog, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
int log_out(char* flog, char *file, int line, char* fmt, ...);
#endif 
