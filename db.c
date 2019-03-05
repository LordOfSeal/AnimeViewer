/****************************
** Создатель : Косов Виктор
** Файл      : db.c
** Дата      : 4.03.2019
*****************************/
#include "db.h"

int rc; // Код возврата
sqlite3 *db; // Хэндлер базы данных
char *zErrMsg; // Сообщение оь ошибке
sqlite3_stmt *stmt; // Хэндлер состояния

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

void insertField(const char * name)
{
	char *query = NULL;
	asprintf(&query,"INSERT INTO anime(name) VALUES('%s');",name);
	sqlite3_prepare(db,query,-1,&stmt,NULL);
	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	free(query);
}