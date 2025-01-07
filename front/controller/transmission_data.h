#pragma once

#include <QtCore/QObject>

#include "../model/websocketclient.h"

class Transmission: public QObject{
    Q_OBJECT public: 
    explicit Transmission(QObject *obj = nullptr);
    Q_SIGNALS:
        void send_data(int x_val, int y_val);
    private Q_SLOTS:
        void onData(int get_x_val, int get_y_val);
    private:
        WebSocketClient *client;
};