import QtQuick
import QtQuick.Controls
Item {
    id: root

    property alias dialogController: addDialog

    Dialog{
        id: addDialog
        focus:true
        anchors.centerIn: parent
        width: 360
        height: 640
        standardButtons: Dialog.Apply | Dialog.Cancel
        onApplied:{
                  notesManager.addNote(nameField.text, descriptionField.text, textField.text)
                     addDialog.close()
        }
        onRejected: console.log("Cancel clicked")

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

                TextField{
                     id: nameField
                     anchors{
                         left: addColumn.left
                         right: addColumn.right

                     }
                     verticalAlignment: TextInput.AlignVCenter
                     height: 30
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
                     height: 30
                     placeholderText: "Введите описание"
                     placeholderTextColor: "#55000000"
                }
                TextField{
                     id: textField
                     anchors{
                         left: addColumn.left
                         right: addColumn.right
                     }
                     wrapMode: TextField.WrapAtWordBoundaryOrAnywhere

                     height: 200
                     placeholderText: "Введите текст"
                     placeholderTextColor: "#55000000"
                }
            }
        }
    }
}
