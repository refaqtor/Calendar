/*
 * Copyight 2017 Akshay Agarwal, agarwal.akshay.akshay8@gmail.com
 * All rights reserved. Distributed under the terms of the MIT License.
 */
#ifndef _SQLITE_MANAGER_H_
#define _SQLITE_MANAGER_H_


#include <DateTime.h>
#include <Path.h>
#include <sqlite3.h>


class Category;
class Event;


extern const char* kDirectoryName;
extern const char* kDatabaseName;


class SQLiteManager {
public:
					SQLiteManager();
					~SQLiteManager();

		bool		AddEvent(Event* event);
		bool		UpdateEvent(Event* event, Event* newEvent);
		BList*		GetEventsOfDay(BDate& date);
		bool		RemoveEvent(Event* event);

		bool		AddCategory(Category* category);
		bool		UpdateCategory(Category* category,
						Category* newCategory);
		Category*	GetCategory(uint32 id);
		BList*		GetAllCategories();
		bool		RemoveCategory(Category* category);

private:

	void			_Initialise();

	sqlite3*		db;
	BPath			fDatabaseFile;
};

#endif //_SQLITE_MANAGER_H_
