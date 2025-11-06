#include "NoteItem.h"

NoteItem::NoteItem(QString nameOfNote,QString description,QString text, int date, QObject *parent)
    : QObject{parent}, m_NameOfNote{nameOfNote}, m_Description{description}, m_Text{text}, m_LastDateOfRedact{date}
{}




QString NoteItem::NameOfNote() const
{
    return m_NameOfNote;
}

void NoteItem::setNameOfNote(const QString &newNameOfNote)
{
    if (m_NameOfNote == newNameOfNote)
        return;
    m_NameOfNote = newNameOfNote;
    emit NameOfNoteChanged();
}

QString NoteItem::Description() const
{
    return m_Description;
}

void NoteItem::setDescription(const QString &newDescription)
{
    if (m_Description == newDescription)
        return;
    m_Description = newDescription;
    emit DescriptionChanged();
}

QString NoteItem::Text() const
{
    return m_Text;
}

void NoteItem::setText(const QString &newText)
{
    if (m_Text == newText)
        return;
    m_Text = newText;
    emit TextChanged();
}

int NoteItem::LastDateOfRedact() const
{
    return m_LastDateOfRedact;
}

void NoteItem::setLastDateOfRedact(int newLastDateOfRedact)
{
    if (m_LastDateOfRedact == newLastDateOfRedact)
        return;
    m_LastDateOfRedact = newLastDateOfRedact;
    emit LastDateOfRedactChanged();
}
