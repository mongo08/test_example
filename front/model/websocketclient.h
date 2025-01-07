#pragma once

#include <QtCore/QObject>
#include <QtWebSockets/QtWebSockets>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtCore/QDebug>

#include <iostream>

class WebSocketClient : public QObject
{
Q_OBJECT
    public : 
    explicit WebSocketClient(const QUrl &url, QObject *obj = nullptr);
Q_SIGNALS:
    void closed();
    void get_data(int get_x_val, int get_y_val);
private Q_SLOTS: 
    void onConnected();
    void onTextMessageReceived(QString msg);

private:
    QWebSocket qws;
    QUrl url;
    QTimer *timer;
};