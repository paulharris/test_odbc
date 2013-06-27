#include <sql.h>
#include <sqlext.h>
#include <stdio.h>
#include <stdlib.h>

void check(SQLRETURN r)
{
   if (r != SQL_SUCCESS)
   {
      printf("ERROR\n");
      exit(1);
   }
}

int main( int argc, char** argv )
{
   SQLRETURN r;
   SQLCHAR * dsn;
   SQLHANDLE env;
   SQLHANDLE conn;

   if (argc < 2)
   {
      printf("USAGE: test_odbc DSNNAME\n");
      return 1;
   }

   printf("Will connect to %s\n", argv[1]);
   dsn = argv[1];

   printf("alloc env\n");
   r = SQLAllocHandle( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env );
   check(r);

   printf("setup version\n");
   r = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
   check(r);

   printf("alloc con\n");
   r = SQLAllocHandle( SQL_HANDLE_DBC, env, &conn );
   check(r);

   printf("connect\n");
   r = SQLConnect( conn, dsn, SQL_NTS, NULL, 0, NULL, 0 );
   check(r);

   return 0;
}
