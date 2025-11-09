#include "NotesManager.h"
#include<QDebug>
NotesManager::NotesManager( QObject *parent)
    : QObject{parent}
{}





void NotesManager::addNote(const QString &name, const QString &description, const QString &text)
{
    NoteItem *item = new NoteItem(name, description, text, 0, this);

    m_noteList.append(item);

    qDebug() << "Создание заметки:";

    emit noteListChanged();
}

void NotesManager::changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text)
{
    if(!item) return;

    item->setNameOfNote(name);
    item->setDescription(description);
    item->setText(text);

    qDebug() << "Редактирование заметки:";
}
