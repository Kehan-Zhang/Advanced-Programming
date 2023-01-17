const url = 'ws://127.0.0.1:8080';
const socket = new WebSocket(url);

var workload = 0;
var employeeID = 0;

socket.addEventListener('open', function(msg){
    socket.send(JSON.stringify({type: "hire", data: "Employee Hired"}));
});

socket.addEventListener('message', function(e){
    console.log("Client Message Recived: " + e.data);

    var msg = JSON.parse(e.data);

    if (msg.type == "work") {
        if (msg.data > 0) {
            employeeID = msg.data
        }
        work();
        socket.send(JSON.stringify({id: employeeID, type: "work", data: workload}));
    } else if (msg.type == "fire") {
        fire();
    }
    
});

function work() {
    workload += 1
    document.getElementById("workload").innerHTML = workload
}

function fire() {
    var stat = JSON.stringify({id: employeeID, type: "stat", data: document.getElementById("workload").textContent})
    socket.send(stat)

    window.opener = null;
    window.open('', '_self')
    window.close()
}