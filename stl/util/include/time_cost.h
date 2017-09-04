#ifndef __TIME_COST_H__
#define __TIME_COST_H__

#include <stdint.h> 
#include <vector> 
#include <string> 
#include <time.h>
#include <sys/time.h>    
#include <unistd.h>

#include "log.h"

using namespace std;
#define TIME_COST_TEST 

namespace bruce { 
    namespace util {
        class TimeCost 
        {
		public:
			TimeCost(const std::string& sFileName, const std::string& sFunctionName,
							const int line,const char *object):
                m_line(line), m_end(false)
            {
		        gettimeofday( &m_TvStart, NULL );
                m_sKey.append(sFileName);
                m_sKey.append(":");
                m_sKey.append(sFunctionName);
                m_obj.append(object);
			}
			~TimeCost( ) 
            {	
                if (m_end)
                {
                    return;
                }
                Cost(0,false);
			}

            void Cost(const int line,bool end=true) 
            {	
                m_end = end;
			    gettimeofday( &m_TvEnd, NULL);
                int64_t time = (m_TvEnd.tv_sec-m_TvStart.tv_sec)*1000 + (m_TvEnd.tv_usec -m_TvStart.tv_usec)/1000;
                
                LOG_ERR("[L:%s:%d  %d]:%s:%ld ms--(%ld s %ld ms)",m_sKey.c_str(),m_line,line,\
					m_obj.c_str(),time,
                    time/1000,(time%1000));
			}

		private:
			std::string m_sKey;
			std::string m_obj;
            const uint32_t m_line;
            struct timeval m_TvStart;
            struct timeval m_TvEnd;
            bool m_end;
		};
	#ifdef TIME_COST_TEST
		#define TIME_COST_TMP(test,file,fun,line) com::bruce::util::TimeCost _tc_##test(file,fun,line,#test)
		
		#define TIME_COST_START(test) TIME_COST_TMP(test,__FILE__,__FUNCTION__,__LINE__)

		#define TIME_COST_STOP(test) _tc_##test.Cost(__LINE__)

		#define TIME_COST_MID(test) _tc_##test.Cost(__LINE__,false)
	#else
		#define TIME_COST_TMP(test,file,fun,line) 
		
		#define TIME_COST_START(test) 

		#define TIME_COST_STOP(test)

		#define TIME_COST_MID(test)
	#endif
	
    }
}



#endif

