#include "transmission_data.h"

Transmission::Transmission(QObject *obj): QObject(obj){
    this->client=new WebSocketClient(QUrl(QStringLiteral("ws://127.0.0.1:7878/graphics")));
    QObject::connect(client,&WebSocketClient::get_data,this,&Transmission::onData);
}

void Transmission::onData(int get_x_val, int get_y_val){
    emit this->send_data(get_x_val,get_y_val);
}