#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include <QObject>
#include<QList>
#include"NoteItem.h"

class NotesManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> noteList READ noteList  NOTIFY noteListChanged FINAL)

public:
    explicit NotesManager(QObject *parent = nullptr);

    QList<QObject *> noteList() const {return m_noteList;}

public slots:
    void addNote(const QString &name, const QString &description, const QString &text);
    void changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text);

private:
    QList<QObject *> m_noteList;

signals:
    void noteListChanged();
};

#endif // NOTESMANAGER_H
