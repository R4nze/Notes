#include "NotesManager.h"
#include<QDebug>
#include<algorithm>
NotesManager::NotesManager( QObject *parent)
    : QObject{parent}
{
   m_database.connectToDatabase();
   loadNotesFromDatabase();
}

void NotesManager::addNote(const QString &name, const QString &description, const QString &text, const int& id)
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString dateStr = currentTime.toString(Qt::ISODate);

    //цвет  для записи в базу
    QString colorStr = "#ffffff";
    QString typeNameStr = "Без названия";

    for(Type* type : m_typeModel) {
        if(type->id() == id) {
            colorStr = type->nameOfColor().name();
            typeNameStr = type->nameOfType();
            break;
        }
    }

    int newDbId = m_database.addNote(name, description, text, colorStr, id, typeNameStr, dateStr);

    if (newDbId == -1) {
        // Если база не сработала, делаем временный ID
        newDbId = -1;
        qDebug() << "Ошибка: Заметка не сохранена в БД!";
    }

    NoteItem *item = new NoteItem(newDbId, name, description, text, id, currentTime, false, this);

    // 4. Устанавливаем цвет объекта
    item->setColor(QColor(colorStr));

    m_allNotes.append(item);
    qDebug() << "Создана заметка. DB ID:" << newDbId << " Type ID:" << id;

    updateDisplayList();
}

void NotesManager::changeNote(NoteItem* item, const QString &name, const QString &description, const QString &text, const QString &nameOfColor, const QColor &color)
{
   QDateTime currentTime = QDateTime::currentDateTime();
   if(!item) return;

   if (!m_allNotes.contains(item)) return;

   int oldTypeId = item->idOfType();

   item->setNameOfNote(name);
   item->setDescription(description);
   item->setText(text);
   item->setLastDateOfRedact(currentTime);
   item->setIdOfType(getOrCreateTypeId(nameOfColor, color));
   item->setColor(color);

   QString dateStr = item->LastDateOfRedact().toString(Qt::ISODate);
   m_database.updateNote(item->id(), name, description, text, color.name(), item->idOfType(), nameOfColor, dateStr);
   qDebug() << "Заметка обновлена в БД. ID: " << item->id();

   updateDisplayList();

   if (oldTypeId != item->idOfType()) {
      checkToRemoveType(oldTypeId);
   }
   qDebug() << "Редактирование заметки завершено. ID:" << item->id();
}

void NotesManager::changeType(const int &id, const QString &name)
{
   qDebug() << "Используется changeType";
   for(Type *type : m_typeModel){
      if(type->id() == id){
         if(type->nameOfType() != name){

            QString oldName = type->nameOfType();
            QString colorStr = type->nameOfColor().name();

            type->setNameOfType(name);

            m_database.renameNoteType(oldName, name, colorStr);
            qDebug() << "Тип переименован: " << oldName << " -> " << name;

            emit typeModelChanged();
            emit noteListChanged();
         }
         return;
      }
   }
}

void NotesManager::deleteSelectedNotes()
{
   if(m_selectedNotes.isEmpty()){
      setDeletemode(false);
      return;
   }

   for(NoteItem* item : m_selectedNotes){
      int typeIdToCheck = item->idOfType();

      m_database.removeNote(item->id());
      qDebug() << "Заметка удалена из БД. ID: " << item->id();

      m_allNotes.removeAll(item);

      delete item;
      checkToRemoveType(typeIdToCheck);

      qDebug() << "Произошло удаление объектов";
   }
   m_selectedNotes.clear();
   setDeletemode(false);

   updateDisplayList();
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

void NotesManager::removeAllSelectedNote()
{
   m_selectedNotes.clear();
   qDebug() << "Очистка выбранных элементов";
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
   if(m_currentFilterId == idOfType){
      m_currentFilterId = -1;
      qDebug() << "Фильтр сброшен!!!";
   }
   else{
      m_currentFilterId = idOfType;
      qDebug() << "Фильтр включён, ID: " << m_currentFilterId;
   }
   updateDisplayList();
}

void NotesManager::sortByChoice(int idOfType)
{
   switch(idOfType){
      case -1:
      updateDisplayList();
      break;

      case 0:
      std::sort(m_displayList.begin(), m_displayList.end(), [](QObject* a, QObject* b){
         NoteItem * itemA = static_cast<NoteItem*>(a);
         NoteItem* itemB = static_cast<NoteItem*>(b);
         return itemA->NameOfNote().toLower() < itemB->NameOfNote().toLower();
      });
      emit noteListChanged();
      break;

      case 1:
      std::sort(m_displayList.begin(), m_displayList.end(), [](QObject* a, QObject* b){
         NoteItem * itemA = static_cast<NoteItem*>(a);
         NoteItem* itemB = static_cast<NoteItem*>(b);
         return itemA->NameOfNote().toLower() > itemB->NameOfNote().toLower();
      });
      emit noteListChanged();
      break;

      case 2:
      std::sort(m_displayList.begin(), m_displayList.end(), [](QObject* a, QObject* b){
         NoteItem* itemA = static_cast<NoteItem*>(a);
         NoteItem* itemB = static_cast<NoteItem*>(b);

         if(itemA->isFavorite() != itemB->isFavorite()){
            return itemA->isFavorite() > itemB->isFavorite();
         }
         return itemA->LastDateOfRedact() > itemB->LastDateOfRedact();
      });
         qDebug() << "Сортировка: Избранные сверху";
         emit noteListChanged();
         break;

      case 3:
      std::sort(m_displayList.begin(), m_displayList.end(), [](QObject* a, QObject* b){
         NoteItem * itemA = static_cast<NoteItem*>(a);
         NoteItem* itemB = static_cast<NoteItem*>(b);
         return itemA->LastDateOfRedact() < itemB->LastDateOfRedact();
      });
      emit noteListChanged();
      break;

      case 4:
      std::sort(m_displayList.begin(), m_displayList.end(), [](QObject* a, QObject* b){
         NoteItem * itemA = static_cast<NoteItem*>(a);
         NoteItem* itemB = static_cast<NoteItem*>(b);
         return itemA->idOfType() < itemB->idOfType();
      });
      emit noteListChanged();
      break;

      case 5:
      std::sort(m_displayList.begin(), m_displayList.end(), [](QObject* a, QObject* b){
         NoteItem * itemA = static_cast<NoteItem*>(a);
         NoteItem* itemB = static_cast<NoteItem*>(b);
         return itemA->Text().length() < itemB->Text().length();
      });
      emit noteListChanged();
      break;
   }
}

void NotesManager::searchNotes(const QString &query)
{
   if(query.isEmpty()){
      updateDisplayList();
      return;
   }

   m_displayList.clear();
   for(NoteItem* item : m_allNotes){
      bool matchName = item->NameOfNote().contains(query, Qt::CaseInsensitive);
      bool matchDesc = item->Description().contains(query, Qt::CaseInsensitive);
      bool matchText = item->Text().contains(query, Qt::CaseInsensitive);
      if(matchName || matchDesc || matchText){
         m_displayList.append(item);
      }
   }
   emit noteListChanged();
}

void NotesManager::toggleFavorites(int noteId)
{
   for (NoteItem * item : m_allNotes){
      if(item->id() == noteId){
         bool newState = !item->isFavorite();
         item->setIsFavorite(newState);
         m_database.updateNoteFavorite(noteId, newState);
         qDebug() << "Избранное изменено для ID " << noteId << ": " << newState;
         return;
      }
   }
}

void NotesManager::toggleSelectedFavorites()
{
   if(m_selectedNotes.isEmpty()) return;

   for(NoteItem *item : m_selectedNotes){
      bool newState = !item->isFavorite();
      item->setIsFavorite(newState);
      m_database.updateNoteFavorite(item->id(), newState);
   }
   m_selectedNotes.clear();
   setDeletemode(false);
}

void NotesManager::checkToRemoveType(int idType)
{
   for(auto *item : m_allNotes){
      if(item->idOfType() == idType){
         return;
      }
   }
   for(int i = 0; i < m_typeModel.size(); i++){
      if(m_typeModel[i]->id() == idType){
         Type* typeToDelete = m_typeModel[i];

         m_typeModel.removeAt(i);
         delete typeToDelete;

         qDebug() << "Тип с ID " << idType << " был удалён, т.к. он пуст.";
         emit typeModelChanged();
         return;
      }
   }
}

void NotesManager::updateDisplayList()
{
   m_displayList.clear();

   for(NoteItem* item : m_allNotes){
      if(m_currentFilterId == -1 || item->idOfType() == m_currentFilterId){
         m_displayList.append(item);
      }
   }
   qDebug() << "Витрина обновлена. Показано: " << m_displayList.size();
   emit noteListChanged();
}

void NotesManager::loadNotesFromDatabase()
{
   QSqlQuery query = m_database.loadAllNotes();
   m_allNotes.clear();

   while(query.next()){
      int id = query.value("id").toInt();

      QString title = query.value("title").toString();
      QString desc = query.value("description").toString();
      QString text = query.value("note_text").toString();
      QString colorStr = query.value("color").toString();
      QString typeName = query.value("type_name").toString();
      QString dateStr = query.value("date_time").toString();

      QDateTime date = QDateTime::fromString(dateStr, Qt::ISODate);
      int currentTypeId = getOrCreateTypeId(typeName, QColor(colorStr));
      bool isFav = query.value("is_favorite").toInt() == 1;

      NoteItem *item = new NoteItem(id, title, desc, text, currentTypeId, date, isFav, this);
      item->setColor(QColor(colorStr));

      m_allNotes.append(item);
   }
   qDebug() << "Загрузка заметок из Базы Данных: " << m_allNotes.size();
   updateDisplayList();
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
    emit typeModelChanged();
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

QColor NotesManager::getColor(int id)
{
   qDebug() << m_typeModel[id]->nameOfColor();
   qDebug() << id;

   return m_typeModel[id]->nameOfColor();
}

QColor NotesManager::getDarkerColor(const QColor &color, int factor)
{
   return color.darker(factor);
}

QString NotesManager::getTypeNameForColor(const QString &colorCode)
{
   QColor colorToCheck(colorCode);
   for(Type* type : m_typeModel){
      if(type->nameOfColor() == colorToCheck){
         return type->nameOfType();
      }
   }
   return "";
}
