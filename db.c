#include "db.h"

int rc;
sqlite3 *db;
char *zErrMsg;
sqlite3_stmt *stmt;
bool openDB(const char* name)
{
	rc = sqlite3_open(name,&db);
	if(rc)
		return false;
	return true;
}

void closeDB()
{
	sqlite3_close(db);
}

void getAll()
{
	char *query = NULL;
	asprintf(&query,"SELECT * FROM anime");
	sqlite3_prepare(db,query,-1,&stmt,NULL);
	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
		char* name = (char*)sqlite3_column_text(stmt,1);
		printf("%s\n", name);
	}
	sqlite3_finalize(stmt);
	free(query);
}