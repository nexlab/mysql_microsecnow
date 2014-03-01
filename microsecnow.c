#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef long long longlong;    
#include <mysql.h>
#include <ctype.h>    
#include <sys/time.h>
#include <unistd.h>
longlong microsecnow(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error);
my_bool microsecnow_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
void microsecnow_deinit(UDF_INIT *initid);
my_bool microsecnow_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
 return 0; //optional
}
void microsecnow_deinit(UDF_INIT *initid)
{ //optional
}

longlong microsecnow(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{
   struct timeval start;
   gettimeofday(&start, NULL);
   return start.tv_sec * 1000000 + start.tv_usec;
}
