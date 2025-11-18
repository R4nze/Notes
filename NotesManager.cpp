#include "NotesManager.h"
#include<QDebug>
NotesManager::NotesManager( QObject *parent)
    : QObject{parent}
{}

void NotesManager::addNote(const QString &name, const QString &description, const QString &text, const int& id)
{
    QDateTime currentTime = QDateTime::currentDateTime();

    NoteItem *item = new NoteItem(name, description, text, id, currentTime, this);
    m_noteList.append(item);
    qDebug() << "Создание заметки:";
    qDebug() << id;

    emit noteListChanged();
}

void NotesManager::changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text, const QString &nameOfColor, const QColor &color)
{
    QDateTime currentTime = QDateTime::currentDateTime();
    if(!item) return;

    int index = m_noteList.indexOf(item);
    if (index == -1) return; // Элемент не найден

    item->setNameOfNote(name);
    item->setDescription(description);
    item->setText(text);
    item->setLastDateOfRedact(currentTime);
    item->setIdOfType(getOrCreateTypeId(nameOfColor,color));


    m_noteList.removeAt(index); //Удаление, т.к. цвет не меняется у старого
    emit noteListChanged();
    m_noteList.insert(index, item); //Добавление с новым цветом
    emit noteListChanged();

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

void NotesManager::setDeletemode(bool newDeletemode)
{
   if (m_deletemode == newDeletemode)
      return;
   m_deletemode = newDeletemode;
   emit deletemodeChanged();
}

void NotesManager::sortByType(int idOfType)
{

}

int NotesManager::getOrCreateTypeId(const QString &name, const QColor &color)
{
    for(Type *type : m_typeModel){
        if(type->nameOfColor() == color){
            qDebug() << "Данный тип заметки уже есть";
            return type->id();
        }
    }
    Type* newType = new Type(color, name, m_nextTypeId, this);
    m_typeModel.append(newType);
    m_nextTypeId++;
    qDebug() << "Добавлен новый тип заметки";
    return newType->id();
}


QColor NotesManager::getTypeColor(NoteItem *item)
{
    for(Type *type : m_typeModel){
        if(type->id() == item->idOfType()){
            item->setColor(type->nameOfColor());
            return item->color();
        }
    }
    return QColor("gray");
}
