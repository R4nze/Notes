import QtQuick
import QtQuick.Controls
Window {
    width: 360
    height: 640
    visible: true
    title: qsTr("Notes")

    Rectangle{
        id: addNotesButton

        width: 50
        height: 50
        color: "green"

        anchors{
            right: parent.right
            bottom: parent.bottom
            rightMargin: 40
            bottomMargin: 90
        }
        MouseArea{

            anchors.fill: parent
            onClicked: {
                addDialog.visible = true

            }
        }
    }

    Dialog{
        id: addDialog
        focus:true
        anchors.centerIn: parent

        Rectangle{
            id: inRectangle

            anchors{
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                top: parent.top
            }
            Column{
                id: addColumn

                spacing: 20
                anchors{
                    fill: inRectangle
                    leftMargin: 15
                    topMargin: 15
                    rightMargin: 15
                }

                Rectangle {
                    id: nameRectangle

                    color: "red"
                     height: 25
                     width: parent.width

                     TextInput{
                         text: "Введите название"
                     }
                }
                Rectangle {
                    id: descriptionRectangle

                    color: "yellow"
                     height: 25
                     width: parent.width
                }
                Rectangle {
                    id: textRectangle

                    color: "pink"
                     height: 25
                     width: parent.width
                }
                Rectangle {
                    id: dateRectangle

                    color: "purple"

                     height: 25
                     width: parent.width
                }
            }



            // TextInput{
            //     text: "Введите название"
            // }

            color: "blue"
        }
        width: 300
        height: 350
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")
    }


}
