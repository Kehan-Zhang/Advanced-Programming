#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <assert.h>

#include "json.hpp"

#include "../../emsdk/upstream/emscripten/system/include/emscripten/websocket.h"

using namespace nlohmann;
using namespace std;

int workload = 0;
int employeeID = 0;

void work() {
    workload += 1;
    string script = "document.getElementById(\"workload\").innerHTML = " + to_string(workload);

    emscripten_run_script(script.c_str());
}

void fire() {
    emscripten_run_script("window.opener = null;window.open('', '_self');window.close();");
}

EM_BOOL WebSocketOpen(int eventType, const EmscriptenWebSocketOpenEvent *e, void *userData){
    json j;
    j["type"] = "hire";
    j["data"] = "Employee Hired";

    emscripten_websocket_send_utf8_text(e->socket, (j.dump()).c_str());
    return 0;
}

EM_BOOL WebSocketClose(int eventType, const EmscriptenWebSocketCloseEvent *e, void *userData){
    return 0;
}

EM_BOOL WebSocketError(int eventType, const EmscriptenWebSocketErrorEvent *e, void *userData){
    return 0;
}

EM_BOOL WebSocketMessage(int eventType, const EmscriptenWebSocketMessageEvent *e, void *userData){
    cout << "Client Message Received: " << e->data;

    if (e->isText) {
        auto msg = json::parse(e->data);
        if (msg["type"] == "work") {
            if (msg["data"] > 0) {
                employeeID = msg["data"];
            }
            work();

            json j;
            j["id"] = employeeID;
            j["type"] = "work";
            j["data"] = workload;
            emscripten_websocket_send_utf8_text(e->socket, (j.dump()).c_str());

        } else if (msg["type"] == "fire"){
            json j;
            j["id"] = employeeID;
            j["type"] = "stat";
            j["data"] = workload;

            emscripten_websocket_send_utf8_text(e->socket, (j.dump()).c_str());

            fire();
        }
    }

    return 0;
}

int main(){
    if(!emscripten_websocket_is_supported()){
        printf("Websocket are not supported, cannot continue\n");
        exit(1);
    }
    
    printf("Websockets are supported\n");
    EmscriptenWebSocketCreateAttributes attr;
    emscripten_websocket_init_create_attributes(&attr);

    const char *url = "ws://localhost:8080";
    attr.url = url;
    // attr.protocols = "binary, base64";
    attr.protocols = "protocol1,protocol2";
    attr.createOnMainThread = false;

    EMSCRIPTEN_WEBSOCKET_T socket = emscripten_websocket_new(&attr);

    if(socket <= 0){
        printf("WebSocket creation failed, error code %d\n", (EMSCRIPTEN_RESULT)socket);
        exit(1);
    }

    emscripten_websocket_set_onopen_callback(socket, (void*)42, WebSocketOpen);
    emscripten_websocket_set_onclose_callback(socket, (void*)43, WebSocketClose);
    emscripten_websocket_set_onerror_callback(socket, (void*)44, WebSocketError);
    emscripten_websocket_set_onmessage_callback(socket, (void*)45, WebSocketMessage);
}