#ifndef __LOG_H__
#define __LOG_H__

#include <libgen.h>
#include <stdio.h> 

#define LOG_ERR(fmt,args...)	do{fprintf(stderr   ,"[%s:%d][%s] ERR: "fmt"\n",basename(const_cast<char *>(__FILE__)),__LINE__,__FUNCTION__,##args);} while(0)
#define LOG_MSG(fmt,args...)	do{fprintf(stdout,"[%s:%d][%s] MSG: "fmt"\n",basename(const_cast<char *>(__FILE__)),__LINE__,__FUNCTION__,##args);} while(0)
#define LOG_DBG(fmt,args...)	do{fprintf(stdout ,"[%s:%d][%s] DBG: "fmt"\n",basename(const_cast<char *>(__FILE__)),__LINE__,__FUNCTION__,##args);} while(0)


#endif

