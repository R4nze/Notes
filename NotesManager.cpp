#include "NotesManager.h"

NotesManager::NotesManager(QString nameOfNote, QString text, int date,QString description, QObject *parent)
    : QObject{parent}, m_NameOfNote{nameOfNote}, m_Description{description}, m_Text{text}, m_LastDateOfRedact{date}
{}





QString NotesManager::NameOfNote() const
{
    return m_NameOfNote;
}

void NotesManager::setNameOfNote(const QString &newNameOfNote)
{
    if (m_NameOfNote == newNameOfNote)
        return;
    m_NameOfNote = newNameOfNote;
    emit NameOfNoteChanged();
}

QString NotesManager::Description() const
{
    return m_Description;
}

void NotesManager::setDescription(const QString &newDescription)
{
    if (m_Description == newDescription)
        return;
    m_Description = newDescription;
    emit DescriptionChanged();
}

QString NotesManager::Text() const
{
    return m_Text;
}

void NotesManager::setText(const QString &newText)
{
    if (m_Text == newText)
        return;
    m_Text = newText;
    emit TextChanged();
}

int NotesManager::LastDateOfRedact() const
{
    return m_LastDateOfRedact;
}

void NotesManager::setLastDateOfRedact(int newLastDateOfRedact)
{
    if (m_LastDateOfRedact == newLastDateOfRedact)
        return;
    m_LastDateOfRedact = newLastDateOfRedact;
    emit LastDateOfRedactChanged();
}
