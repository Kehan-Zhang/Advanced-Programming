const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });

var employeeNum = 0
var startTime = []
var endTime = []
var executeTime = []

wss.on('connection', (ws, req) => {

    ws.isAlive = true;

    ws.on('message', message => {
        console.log("Server Message Recived: " + message)

        var msg = JSON.parse(message);

        if (msg.type == "hire") {
            startTime.push(performance.now())
            employeeNum++;
            ws.send(JSON.stringify({type: "work", data: employeeNum}))
        } else if (msg.type == "work") {
            if (msg.data >= 5000) {
                employeeNum--;
                ws.send(JSON.stringify({type: "fire"}))
                endTime.push(performance.now())

                if (employeeNum == 0) {
                    executeTime.push((endTime[endTime.length - 1] - startTime[0]) / 1000)
                    startTime = []
                    endTime = []
                    console.log(executeTime)
                }
            } else {
                ws.send(JSON.stringify({type: "work"}))
            }
        }
    })
})

console.log("Server Online");

