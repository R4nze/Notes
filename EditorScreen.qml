import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQml.Models
Item {
    id: root

    property alias dialogController: addDialog
    property var currentNote: null

    function changeNote(note){
                     editorScreen.currentNote = note;
                     nameField.text = note.NameOfNote;
                     descriptionField.text = note.Description;
                     textField.text = note.Text;
    }

    Dialog{
        id: addDialog
        focus:true
        anchors.centerIn: parent
        width: 360
        height: 640
        standardButtons: Dialog.Apply | Dialog.Cancel
        background: Rectangle {
                color: Material.background
                radius: 0
        }
        onClosed: {
            // Очищаем каждое поле ввода
            nameField.text = "";
            descriptionField.text = "";
            textField.text = "";
        }
        onApplied:{
            var selectedItem = typesOfNote.model.get(typesOfNote.currentIndex);
            var selectedName = selectedItem.key
            var selectedColor = selectedItem.value

            if(editorScreen.currentNote)
            {
                notesManager.changeNote(editorScreen.currentNote,
                nameField.text,
                descriptionField.text,
                textField.text,
                selectedName,
                selectedColor);
            }

            else{
                typesOfNote.currentIndex = 0;
                notesManager.addNote(nameField.text,
                    descriptionField.text,
                    textField.text,
                    notesManager.getOrCreateTypeId(selectedName,selectedColor));
            }

            addDialog.close()
        }
        onRejected:{
                    console.log("Cancel clicked")
                    addDialog.close()
        }
        Rectangle{
            id: inRectangle
            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                top: parent.top
            }

            ListModel {
                id: myModel
                ListElement { key: "работа"; value: "#00ffff"}
                ListElement { key: "личное"; value: "#ff1493" }
                ListElement { key: "другое"; value: "#b22222" }
            }

            ComboBox {
                id: typesOfNote
                height: 30
                anchors{
                    top: inRectangle.top
                    right: inRectangle.right
                    topMargin: 10
                    rightMargin: 10
                }

                textRole: "key"
                valueRole: "value"
                model: myModel

                contentItem: Item {
                        width: typesOfNote.width
                        height: typesOfNote.height

                        RowLayout {
                            // Используем RowLayout для размещения кружка и текста
                            anchors.fill: parent
                            spacing: 5

                            // 1. Цветной кружок
                            Rectangle {
                                width: 10
                                height: 10
                                radius: 180
                                // Получаем цвет из модели по текущему индексу ComboBox
                                color: typesOfNote.model.get(typesOfNote.currentIndex).value
                                Layout.alignment: Qt.AlignLeft
                                Layout.leftMargin: 10
                            }

                            // 2. Текст (название типа)
                            Text {
                                text: typesOfNote.currentText
                                Layout.fillWidth: true
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                delegate: ItemDelegate {
                    width: parent.width
                    height: 23
                    // Здесь мы создаем прямоугольник для каждого элемента
                    Rectangle {
                        id:colorRectangle

                        width: 10
                        height: 10
                        color: model.value // Используем цвет из модели
                        anchors{
                            left: parent.left
                            leftMargin: 5
                            verticalCenter: parent.verticalCenter
                        }
                        radius: 180
                    }
                    Text{
                        text: model.key
                        anchors{
                            top:  colorRectangle.top
                            bottom: colorRectangle.bottom
                            left: colorRectangle.right
                            leftMargin: 10
                        }
                        Layout.fillWidth: true
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }

            Column{
                id: addColumn
                spacing: 20
                anchors{
                    top: typesOfNote.bottom
                    left: inRectangle.left
                    right: inRectangle.right
                    bottom: inRectangle.bottom
                    leftMargin: 15
                    topMargin: 15
                    rightMargin: 15
                }

                TextField{
                    id: nameField
                    anchors{
                        left: addColumn.left
                        right: addColumn.right
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    height: 35
                    placeholderText: "Введите имя"
                    placeholderTextColor: "#55000000"

                }
                TextField{
                    id: descriptionField
                    anchors{
                        left: addColumn.left
                        right: addColumn.right
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    height: 35
                    placeholderText: "Введите описание"
                    placeholderTextColor: "#55000000"
                }
                TextArea{
                    id: textField
                    anchors{
                        left: addColumn.left
                        right: addColumn.right
                    }
                    Layout.alignment: Qt.AlignTop
                    wrapMode: TextField.WrapAtWordBoundaryOrAnywhere
                    height: 200
                    placeholderText: "Введите текс"
                    placeholderTextColor: "#55000000"
                }
            }
        }
    }
}
