/*
Copyright (c) 2014 Unixmedia S.r.l. <info@unixmedia.it>
Copyright (c) 2014 Franco (nextime) Lanza <franco@unixmedia.it>

Domotika System Domain utils [http://trac.unixmedia.it]

This file is part of DMDomain.

DMDomain is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
