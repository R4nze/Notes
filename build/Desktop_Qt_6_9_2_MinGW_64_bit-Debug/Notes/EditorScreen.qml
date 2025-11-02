import QtQuick
import QtQuick.Controls 2.3

Dialog{
    id: addDialog
    modal:true
    visible:true
    anchors.centerIn: parent

    Rectangle{
        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: parent.top
        }
        color: "blue"
    }
    width: 300
    height: 350
    standardButtons: Dialog.Ok | Dialog.Cancel
    onAccepted: console.log("Ok clicked")
    onRejected: console.log("Cancel clicked")
}
