#include "NotesManager.h"
#include<QDebug>
NotesManager::NotesManager( QObject *parent)
    : QObject{parent}
{}

void NotesManager::addNote(const QString &name, const QString &description, const QString &text)
{
   QDateTime currentTime = QDateTime::currentDateTime();
   NoteItem *item = new NoteItem(name, description, text, currentTime, this);


    m_noteList.append(item);

    qDebug() << "Создание заметки:";

    emit noteListChanged();
}

void NotesManager::changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text)
{
   QDateTime currentTime = QDateTime::currentDateTime();
    if(!item) return;

    item->setNameOfNote(name);
    item->setDescription(description);
    item->setText(text);
    item->setLastDateOfRedact(currentTime);

    qDebug() << "Редактирование заметки:";
}

void NotesManager::deleteSelectedNotes()
{
   if(m_selectedNotes.isEmpty()){
      setDeletemode(false);
      return;
   }

   for(NoteItem* item : m_selectedNotes){
      m_noteList.removeAll(item);

      delete item;
      qDebug() << "Произошло удаление объектов";
   }
   m_selectedNotes.clear();
   setDeletemode(false);

   emit noteListChanged();
   emit deletemodeChanged();

}

void NotesManager::addSelectedNote(NoteItem* item)
{
   qDebug() << "Метод addSelectedNote сработал";
   if(item && !m_selectedNotes.contains(item)){
      m_selectedNotes.append(item);
      qDebug() << "Объект добавился в QList";
   }
}

void NotesManager::removeSelectedNote(NoteItem *item)
{
   m_selectedNotes.removeAll(item);
   qDebug() << "Объект удалился из QList";
}

bool NotesManager::deletemode() const
{
   return m_deletemode;
}

void NotesManager::setDeletemode(bool newDeletemode)
{
   if (m_deletemode == newDeletemode)
      return;
   m_deletemode = newDeletemode;
   emit deletemodeChanged();
}
