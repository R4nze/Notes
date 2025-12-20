import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQml.Models
Item {
    id: root
    width: parent.width
    property alias dialogController: addDialog
    property var currentNote: null
    property var currentColor: null
    property bool basicColorOfType: false

    function changeNote(note){
                    editorScreen.currentNote = note;
                    editorScreen.currentColor = note.color
                    nameField.text = note.NameOfNote;
                    descriptionField.text = note.Description;
                    textField.text = note.Text;
    }
    function refreshModelNames(){
        console.log("Работает refreshModelNames")
        for(var i = 0; i < myModel.count; i++){
            var item = myModel.get(i);
            var actualName = notesManager.getTypeNameForColor(item.value);
            if(actualName !== "" && item.key !== actualName){
                myModel.setProperty(i, "key", actualName);
            }
        }
    }
    Connections{
        target: notesManager
        function onTypeModelChanged(){
            refreshModelNames();
        }
    }
    Component.onCompleted: {
        refreshModelNames();
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
        onOpened: {
            refreshModelNames();
            if(editorScreen.currentNote){
                var foundIndex = -1;
                console.log("On opened открыт");
                for(var i = 0; i < myModel.count; ++i){
                    var item = myModel.get(i);
                    if(item.value == editorScreen.currentColor){
                        console.log("Цвет совпал открыт");
                        foundIndex = i;
                        break;
                    }
                }
                typesOfNote.currentIndex = (foundIndex !== -1) ? foundIndex : 0;
            }
            else{
                typesOfNote.currentIndex = 0;
            }
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
                console.log("On Applied открыт");
                notesManager.changeNote(editorScreen.currentNote,
                nameField.text,
                descriptionField.text,
                textField.text,
                selectedName,
                selectedColor);
                typesOfNote.currentIndex = 0;
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
                ListElement { key: "Работа"; value: "#53ecec"}
                ListElement { key: "Личное"; value: "#ee69b1" }
                ListElement { key: "Другое"; value: "#db7093" }
                ListElement { key: "Без названия"; value: "#90ee90"}
                ListElement { key: "Без названия"; value: "#778899"}
                ListElement { key: "Без названия"; value: "#fa8072"}
                ListElement { key: "Без названия"; value: "#ff6347"}
                ListElement { key: "Без названия"; value: "#ffff00"}
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
                            id: rowOfTextAndCyrcle
                            // Используем RowLayout для размещения кружка и текста
                            anchors.fill: parent
                            spacing: 5

                            // 1. Цветной кружок
                            Rectangle {
                                width: 10
                                height: 10
                                radius: 180
                                // Получаем цвет из модели по текущему индексу ComboBox
                                //color: typesOfNote.model.get(typesOfNote.currentIndex).value

                                gradient: Gradient{
                                    GradientStop{
                                        position:0.0
                                        color: typesOfNote.model.get(typesOfNote.currentIndex).value
                                    }
                                    GradientStop{
                                        position:1.0
                                        color: Qt.darker(typesOfNote.model.get(typesOfNote.currentIndex).value)
                                    }
                                }
                                Layout.alignment: Qt.AlignLeft
                                Layout.leftMargin: 10
                            }

                            // 2. Текст (название типа)
                            Text {
                                text: typesOfNote.currentText
                                elide: Text.ElideRight
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
                        gradient: Gradient{
                            GradientStop{
                                position:0.0
                                color: model.value
                            }
                            GradientStop{
                                position:1.0
                                color: Qt.darker(model.value)
                            }
                        }

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
