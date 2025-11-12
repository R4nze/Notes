#ifndef NOTEITEM_H
#define NOTEITEM_H

#include <QObject>
#include<QDateTime>

class NoteItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString NameOfNote READ NameOfNote WRITE setNameOfNote NOTIFY NameOfNoteChanged FINAL)
    Q_PROPERTY(QString Description READ Description WRITE setDescription NOTIFY DescriptionChanged FINAL)
    Q_PROPERTY(QString Text READ Text WRITE setText NOTIFY TextChanged FINAL)
    Q_PROPERTY(QDateTime LastDateOfRedact READ LastDateOfRedact WRITE setLastDateOfRedact NOTIFY LastDateOfRedactChanged FINAL)
public:
    explicit NoteItem(QString nameOfNote,QString description = "",QString text = "", QDateTime date = QDateTime::currentDateTime(), QObject *parent = nullptr);

    QString NameOfNote() const;
    void setNameOfNote(const QString &newNameOfNote);

    QString Description() const;
    void setDescription(const QString &newDescription);

    QString Text() const;
    void setText(const QString &newText);

    QDateTime LastDateOfRedact() const;
    void setLastDateOfRedact(QDateTime &newLastDateOfRedact);

private:
    QString m_NameOfNote;
    QString m_Description;
    QString m_Text;
    QDateTime m_LastDateOfRedact;

signals:
    void NameOfNoteChanged();
    void DescriptionChanged();
    void TextChanged();
    void LastDateOfRedactChanged();
};

#endif // NOTEITEM_H
