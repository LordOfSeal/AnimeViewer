/****************************
** Создатель : Косов Виктор
** Файл      : db.h
** Дата      : 4.03.2019
*****************************/
#ifndef DB_H
#define DB_H
#include <sqlite3.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
bool openDB(const char * dbName); // Открытие базы
void insertField(const char * name);
void getAll(); // Получение всех записей
void closeDB(); // Закрытие базы данных
#endif
