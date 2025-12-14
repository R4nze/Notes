#include "DatabaseHandler.h"


DatabaseHandler::DatabaseHandler(QObject *parent)
   : QObject{parent}
{}

DatabaseHandler::~DatabaseHandler()
{
   if(m_db.isOpen()){
      m_db.close();
   }
}

QSqlQuery DatabaseHandler::loadAllNotes()
{
   QSqlQuery query(m_db);
   query.prepare("SELECT * FROM notes");

   if(!query.exec()){
      qDebug() << "Ошибка загрузки заметок: " << query.lastError().text();
   }
   return query;
}

bool DatabaseHandler::updateNote(int id, const QString &title, const QString &desc, const QString &text,
                                 const QString &color, int typeId, const QString &typeName, const QString &date)
{
   QSqlQuery query(m_db);

   query.prepare("UPDATE notes SET title = :title, description = :desc, note_text = :text, "
                 "color = :color, type_id = :type, type_name = :typeName, date_time = :date "
                 "WHERE id = :id");

   query.bindValue(":title", title);
   query.bindValue(":desc", desc);
   query.bindValue(":text",text);
   query.bindValue(":color", color);
   query.bindValue(":type",typeId);
   query.bindValue(":typeName", typeName);
   query.bindValue(":date",date);
   query.bindValue(":id",id);

   if(!query.exec()){
      qDebug() << "Ошибка обновления заметки: "  << query.lastError().text();
      return false;
   }
   return true;
}

bool DatabaseHandler::renameNoteType(const QString &oldName, const QString &newName, const QString &color)
{
   QSqlQuery query(m_db);

   query.prepare("UPDATE notes SET type_name = :newName "
                 "WHERE type_name = :oldName AND color = :color");

   query.bindValue(":newName", newName);
   query.bindValue(":oldName", oldName);
   query.bindValue(":color", color);

   if(!query.exec()){
      qDebug() << "Ошибка переименования типа в БД: " << query.lastError().text();
      return false;
   }
   qDebug() << "Тип переименован в БД. Затронуто строк: " <<query.numRowsAffected();
   return true;

}

bool DatabaseHandler::updateNoteFavorite(int id, bool isFavorite)
{
   QSqlQuery query(m_db);
   query.prepare("UPDATE notes SET is_favorite = :fav WHERE id = :id");
   query.bindValue(":fav", isFavorite ? 1 : 0);
   query.bindValue(":id", id);
   return query.exec();
}

bool DatabaseHandler::removeNote(int id)
{
   QSqlQuery query(m_db);

   query.prepare("DELETE FROM notes WHERE id = :id");
   query.bindValue(":id", id);

   if(!query.exec()){
      qDebug() << "Ошибка удаления заметки: " << query.lastError().text();
      return false;
   }
   return true;

}

void DatabaseHandler::connectToDatabase()
{
   QString dbPath = QCoreApplication::applicationDirPath() + "/my_notes.db";

   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(dbPath);

   if(!m_db.open()){
      qDebug() << "ОШИБКА: Не удалось открыть базу данных!" << m_db.lastError().text();
      return;
   }
   qDebug() << "База данных открыта: " << dbPath;

   QSqlQuery query;
   QString createTableQuery =
         "CREATE TABLE IF NOT EXISTS notes("
         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
         "title TEXT, "
         "description TEXT, "
         "note_text TEXT, "
         "color TEXT, "
         "type_id INTEGER, "
         "type_name TEXT, "
         "date_time TEXT, "
         "is_favorite INTEGER"
         ");";

   if(!query.exec(createTableQuery)){
      qDebug() << "Ошибка создания таблицы: " << query.lastError().text();
   }
}

int DatabaseHandler::addNote(const QString &title, const QString &desc, const QString &text,
                             const QString &color, int typeId, const QString &typeName, const QString &date)
{
   QSqlQuery query(m_db);
   query.prepare("INSERT INTO notes (title, description, note_text, color, type_id, type_name, date_time) "
                 "VALUES (:title, :desc, :text, :color, :type, :typeName, :date)");

   query.bindValue(":title", title);
   query.bindValue(":desc", desc);
   query.bindValue(":text", text);
   query.bindValue(":color", color);
   query.bindValue(":type", typeId);
   query.bindValue(":typeName", typeName);
   query.bindValue(":date", date);

   if(!query.exec()){
      qDebug() << "Ошибка добавления заметки: " << query.lastError().text();
      return -1;
   }
   return query.lastInsertId().toInt();
}

