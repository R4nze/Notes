#ifndef NOTEITEM_H
#define NOTEITEM_H

#include <QObject>
#include<QDateTime>
#include<QColor>

class NoteItem : public QObject
{
   Q_OBJECT
   Q_PROPERTY(QString NameOfNote READ NameOfNote WRITE setNameOfNote NOTIFY NameOfNoteChanged FINAL)
   Q_PROPERTY(QString Description READ Description WRITE setDescription NOTIFY DescriptionChanged FINAL)
   Q_PROPERTY(QString Text READ Text WRITE setText NOTIFY TextChanged FINAL)
   Q_PROPERTY(QDateTime LastDateOfRedact READ LastDateOfRedact WRITE setLastDateOfRedact NOTIFY LastDateOfRedactChanged FINAL)
   Q_PROPERTY(int idOfType READ idOfType WRITE setIdOfType NOTIFY idOfTypeChanged FINAL)
   Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged FINAL)
   Q_PROPERTY(int id READ id CONSTANT)
   Q_PROPERTY(bool isFavorite READ isFavorite WRITE setIsFavorite NOTIFY isFavoriteChanged FINAL)
public:
   explicit NoteItem(int m_id, QString nameOfNote,QString description = "",QString text = "", int id = 0, QDateTime date = QDateTime::currentDateTime(), bool isFavourite = false, QObject *parent = nullptr);

   QString NameOfNote() const {return m_NameOfNote;};
   void setNameOfNote(const QString &newNameOfNote);

   QString Description() const {return m_Description;};
   void setDescription(const QString &newDescription);

   QString Text() const {return m_Text;};
   void setText(const QString &newText);

   QDateTime LastDateOfRedact() const {return m_LastDateOfRedact;};
   void setLastDateOfRedact(QDateTime &newLastDateOfRedact);

   int idOfType() const {return m_idOfType;};
   void setIdOfType(int newIdOfType);

   QColor color() const {return m_color;};
   void setColor(const QColor &newColor);

   int id() const {return m_id;};

   bool isFavorite() const { return m_isFavorite; };
   void setIsFavorite(bool newIsFavorite);

private:
   QString m_NameOfNote;
   QString m_Description;
   QString m_Text;
   QDateTime m_LastDateOfRedact;
   int m_idOfType;
   QColor m_noteColor;
   QColor m_color;


   int m_id;

   bool m_isFavorite;

signals:
   void NameOfNoteChanged();
   void DescriptionChanged();
   void TextChanged();
   void LastDateOfRedactChanged();
   void idOfTypeChanged();
   void colorChanged();
   void isFavoriteChanged();
};

#endif // NOTEITEM_H
