#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include<QCoreApplication>

class DatabaseHandler : public QObject
{
   Q_OBJECT
public:
   explicit DatabaseHandler(QObject *parent = nullptr);
   ~DatabaseHandler();

public slots:
   QSqlQuery loadAllNotes();
   bool updateNote(int id, const QString &title, const QString &desc, const QString &text,
                   const QString &color, int typeId, const QString &typeName, const QString &date);
   bool renameNoteType(const QString &oldName, const QString &newName, const QString &color);
   bool updateNoteFavorite(int id, bool isFavorite);
   bool removeNote(int id);
   void connectToDatabase();
   int addNote(const QString &title, const QString &desc, const QString &text,
               const QString &color, int typeId, const QString &typeName, const QString &date);

private:
   QSqlDatabase m_db;

signals:

};

#endif // DATABASEHANDLER_H
