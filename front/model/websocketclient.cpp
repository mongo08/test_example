#include "websocketclient.h"

WebSocketClient::WebSocketClient(const QUrl &url, QObject *obj) : QObject(obj), url(url)
{
    connect(&this->qws, &QWebSocket::connected, this, &WebSocketClient::onConnected);
    connect(&this->qws, &QWebSocket::disconnected, this, &WebSocketClient::closed);
    this->qws.open(QUrl(this->url));
    this->timer=new QTimer(this);
    this->timer->setInterval(200);
    connect(this->timer,&QTimer::timeout, this, &WebSocketClient::onConnected);
    this->timer->start();
}

void WebSocketClient::onConnected()
{
    connect(&this->qws, &QWebSocket::textMessageReceived, this, &WebSocketClient::onTextMessageReceived);
    this->qws.sendTextMessage(QStringLiteral("Start"));
}

void WebSocketClient::onTextMessageReceived(QString msg)
{
    QJsonDocument get_val=QJsonDocument::fromJson(msg.toUtf8());
    QJsonObject obj=get_val.object();
    int get_x_val=obj["x_axis"].toInt();
    int get_y_val=obj["y_axis"].toInt();
    emit get_data(get_x_val,get_y_val);
}