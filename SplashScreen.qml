import QtQuick
import QtQuick.Shapes

Rectangle {
    id: splashRoot
    anchors.fill: parent
    color: "#F4F6F9"
    z: 100

    signal finished()

    Item {
        width: 350
        height: 180
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50

        // --- БУКВА "R" ---
        Shape {
            id: letterR
            width: 160
            height: 170
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: -80

            layer.enabled: true
            layer.samples: 8

            // --- ШТРИХ 1: ПАЛОЧКА (Наклонная) ---
            ShapePath {
                id: strokeStem
                strokeWidth: 6
                strokeColor: "#0575E6"
                fillColor: "transparent"
                capStyle: ShapePath.RoundCap

                // Более выраженный наклон палочки
                // Верх (70), Низ (40) -> Диагональ /
                PathSvg { path: "M 25 55 Q 50 25 70 45 L 35 145" }

                strokeStyle: ShapePath.DashLine
                dashPattern: [ 250, 250 ]
                dashOffset: 250
            }

            // --- ШТРИХ 2: ГОЛОВА И НОГА ---
            ShapePath {
                id: strokeLoop
                strokeWidth: 6
                strokeColor: "#0575E6"
                fillColor: "transparent"
                capStyle: ShapePath.RoundCap
                joinStyle: ShapePath.RoundJoin

                PathSvg {
                    path: "M 40 65 C 40 5 140 5 130 65 Q 125 100 50 95 Q 80 120 130 145"
                }

                strokeStyle: ShapePath.DashLine
                dashPattern: [ 600, 600 ]
                dashOffset: 600
            }
        }

        // --- АНИМАЦИЯ ---
        SequentialAnimation {
            running: true

            // 1. Палочка
            NumberAnimation {
                target: strokeStem
                property: "dashOffset"
                from: 250
                to: 0
                duration: 700
                easing.type: Easing.InOutQuad
            }

            // 2. Голова и нога
            NumberAnimation {
                target: strokeLoop
                property: "dashOffset"
                from: 600
                to: 0
                duration: 1500
                easing.type: Easing.InOutQuad
            }
        }

        // --- ТЕКСТ "aNes" ---
        Text {
            id: restText
            text: "aNes"
            font.family: "Dancing Script"
            font.pixelSize: 84
            color: "#333333"

            // ПРИВЯЗКА
            anchors.left: letterR.right

            anchors.leftMargin: -25

            anchors.baseline: letterR.bottom
            anchors.baselineOffset: -25

            opacity: 0

            NumberAnimation on opacity {
                id: textFadeIn
                to: 1
                duration: 1000
                running: false
            }
        }
    }

    // --- ТАЙМИНГИ ---
    Timer {
        interval: 1900
        running: true
        onTriggered: textFadeIn.start()
    }

    Timer {
        id: closeTimer
        interval: 4000
        running: true
        onTriggered: fadeOut.start()
    }

    NumberAnimation {
        id: fadeOut
        target: splashRoot
        property: "opacity"
        to: 0
        duration: 800
        onFinished: {
            splashRoot.visible = false
            splashRoot.finished()
        }
    }
}
