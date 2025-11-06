#include "NotesManager.h"

NotesManager::NotesManager( QObject *parent)
    : QObject{parent}
{}





void NotesManager::addNote(const QString &name, const QString &description, const QString &text)
{
    NoteItem *item = new NoteItem(name, description, text, 0, this);

    m_noteList.append(item);

    emit noteListChanged();
}
