#include "NoteItem.h"
#include <QDateTime>

NoteItem::NoteItem(QString nameOfNote,QString description,QString text, int id, QDateTime date, QObject *parent)
    : QObject{parent}, m_NameOfNote{nameOfNote}, m_Description{description}, m_Text{text}, m_LastDateOfRedact{date},
    m_idOfType{id}
{}

void NoteItem::setNameOfNote(const QString &newNameOfNote)
{
    if (m_NameOfNote == newNameOfNote || (m_NameOfNote == "" && m_NameOfNote == newNameOfNote))
        return;
    m_NameOfNote = newNameOfNote;
    emit NameOfNoteChanged();
}

void NoteItem::setDescription(const QString &newDescription)
{
    if (m_Description == newDescription || (m_Description == "" && m_Description == newDescription))
        return;
    m_Description = newDescription;
    emit DescriptionChanged();
}

void NoteItem::setText(const QString &newText)
{
    if (m_Text == newText || (m_Text == "" && m_Text == newText))
        return;
    m_Text = newText;
    emit TextChanged();
}

void NoteItem::setLastDateOfRedact(QDateTime &newLastDateOfRedact)
{
    if (m_LastDateOfRedact == newLastDateOfRedact)
        return;
    m_LastDateOfRedact = newLastDateOfRedact;
    emit LastDateOfRedactChanged();
}
void NoteItem::setIdOfType(int newIdOfType)
{
    if (m_idOfType == newIdOfType)
        return;
    m_idOfType = newIdOfType;
    emit idOfTypeChanged();
}

void NoteItem::setColor(const QColor &newColor)
{
    if (m_color == newColor)
        return;
    m_color = newColor;
    emit colorChanged();
}
