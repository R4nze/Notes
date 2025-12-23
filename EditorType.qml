import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
Item {
    id: root
    height: 320
    width: parent.width
    anchors.bottom: parent.bottom
    property alias dialogController: typeChangeDialog
    Dialog{
        id: typeChangeDialog
        width: 360
        height: 320
        anchors.centerIn: parent


        background: Rectangle {
            color: "white"
            radius: 20 // Скругляем всё

            // Прямоугольник-"заплатка" снизу, чтобы убрать скругление там
            Rectangle {
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                height: 15 // Высота равна радиусу
                color: "white" // Цвет такой же, как у фона
            }
        }
        header: Item{
            height: 40
            width: parent.width

            Text{
                id: textOfChangeType
                anchors{
                    top: parent.top
                    topMargin: 21
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                    leftMargin: 20
                }
                font.pixelSize: 15
                text: "Изменение"
            }

            FancyButton{
                anchors{
                    top: parent.top
                    right: parent.right
                    rightMargin: 10
                    topMargin: 17
                }
                startColor: "#E0E0E0"
                endColor: "#E0E0E0"
                width: 75;
                height: 28
                radius: 8
                Text{
                    anchors.centerIn: parent
                    color: "black"
                    font.pixelSize: 15
                    text: "Готово"
                }
                onClicked: {
                    for(var i = 0; i < typeRepeater.count; i++){
                        var field = typeRepeater.itemAt(i);
                        notesManager.changeType(field.idField, field.text);
                    }
                    typeChangeDialog.close()

                }

            }
        }
        contentItem: Flickable{
            id: flickableContent
            contentHeight: contentColumn.implicitHeight
            clip: true
            Column{
                id: contentColumn
                spacing: 10
                width: parent.width
                topPadding: 10

                Repeater{
                    id: typeRepeater
                    model: notesManager.typeModel


                    TextField{
                        id: typeField
                        property int idField: modelData.id
                        height: 35
                        width: parent.width
                        anchors.horizontalCenter: parent.horizontalCenter

                        text: modelData.nameOfType
                        verticalAlignment: TextInput.AlignVCenter

                        leftPadding: 35
                        placeholderTextColor: "#55000000"

                        Rectangle {
                            id: circleColor
                            anchors{
                                left: parent.left
                                leftMargin: 10
                                verticalCenter: parent.verticalCenter
                            }
                            width: 10
                            height: 10
                            radius: 180

                            gradient: Gradient{
                                GradientStop{
                                    position:0.0
                                    color: modelData.nameOfColor
                                }
                                GradientStop{
                                    position:1.0
                                    color: Qt.darker(modelData.nameOfColor)
                                }
                            }


                        }
                    }

                }

            }

        }


    }





}
