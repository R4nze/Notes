import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQuick.Shapes 1.10
Item {
    id: root
    height: 320
    width: parent.width
    anchors.bottom: parent.bottom
    property alias sortNotesDialog: dialogOfSort
    property int activeSortId: -1
    Dialog{
        id: dialogOfSort
        width: 360
        height: 620
        anchors.centerIn: parent

        Item{
            id: itemOfText
            height: 35
            width: parent.width
            Rectangle{
                color: "#F4F6F9"
                height: itemOfText.height
                width: itemOfText.width
                radius: 8
                Text{
                    id: topText
                    anchors{
                        verticalCenter: parent.verticalCenter
                        left: parent.left
                        leftMargin: 10
                    }
                    font.pixelSize: 13
                    text: "Сортировка по"
                }
            }
        }
        Column{
            id: columnOfSortButton
            anchors.top: itemOfText.bottom
            anchors.topMargin: 15
            spacing: 10
            width: parent.width

            ListModel{
                id: sortModel
                ListElement{name: "Все"; modelId: -1}
                ListElement{name: "Имя (А-Я)"; modelId: 0 }
                ListElement{name: "Имя (Я-А)"; modelId: 1 }
                ListElement{name: "Избранное"; modelId: 2 }
                ListElement{name: "Время"; modelId: 3 }
                ListElement{name: "Папка"; modelId: 4 }
                ListElement{name: "Кол-во текста"; modelId: 5 }
            }

            Repeater{
                model: sortModel

                Rectangle{
                    id: buttonChoice
                    property bool isSelected: root.activeSortId === model.modelId
                    width: parent.width
                    height: 40
                    radius: 10
                    color: "white"
                    border.color: isSelected ? "blue" : buttonChoice.color
                    border.width: 2



                    Text{
                        anchors{
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                            leftMargin: 10
                        }
                        font.pixelSize: 13
                        text: model.name
                    }
                    Rectangle{
                        id: selectedCircle
                        width: 16
                        height: 16
                        border.color:isSelected ? "blue" : "black"
                        border.width: 2
                        color: buttonChoice.color
                        anchors{
                            verticalCenter: parent.verticalCenter
                            right: parent.right
                            rightMargin: 10
                        }
                        radius: 180
                        Rectangle{
                            anchors.centerIn: selectedCircle
                            width: 8
                            height: 8
                            visible: buttonChoice.isSelected ? true : false
                            color: "blue"
                            radius: 180
                        }
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            root.activeSortId = model.modelId
                            notesManager.sortByChoice(model.modelId);
                            dialogOfSort.close();
                        }
                    }
                }
            }
        }
    }
}
