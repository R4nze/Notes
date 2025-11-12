#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include <QObject>
#include<QList>
#include"NoteItem.h"

class NotesManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> noteList READ noteList  NOTIFY noteListChanged FINAL)
   Q_PROPERTY(bool deletemode READ deletemode WRITE setDeletemode NOTIFY deletemodeChanged FINAL)

public:
    explicit NotesManager(QObject *parent = nullptr);

    QList<QObject *> noteList() const {return m_noteList;}

    bool deletemode() const;
    void setDeletemode(bool newDeletemode);

public slots:
    void addNote(const QString &name, const QString &description, const QString &text);
    void changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text);
   void deleteSelectedNotes();
   void addSelectedNote(NoteItem* item);
   void removeSelectedNote(NoteItem* item);


private:
    QList<QObject *> m_noteList;
   QList<NoteItem *> m_selectedNotes;
    bool m_deletemode;

signals:
    void noteListChanged();
    void deletemodeChanged();
};

#endif // NOTESMANAGER_H
