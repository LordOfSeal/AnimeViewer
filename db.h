#ifndef DB_H
#define DB_H
#include <sqlite3.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
bool openDB(const char * dbName);
void getAll();
void closeDB();
#endif
