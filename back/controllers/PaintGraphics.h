#pragma once

#include <drogon/WebSocketController.h>

#include <vector>
#include <random>
#include <unistd.h>
#include <iostream>

using namespace drogon;

class PaintGraphics : public drogon::WebSocketController<PaintGraphics>
{
  private:
    std::vector<int> x={0,2,3,7,10};
    std::vector<int> y={6,4,8,4,5};
    int count=0;
    std::vector<WebSocketConnectionPtr> connections;
    Json::Value json;
    int generated_number(int start_val, int end_val);
  public:
     void handleNewMessage(const WebSocketConnectionPtr&,
                                  std::string &&,
                                  const WebSocketMessageType &) override;
    void handleNewConnection(const HttpRequestPtr &,
                                     const WebSocketConnectionPtr&) override;
    void handleConnectionClosed(const WebSocketConnectionPtr&) override;
    WS_PATH_LIST_BEGIN
    // list path definitions here;
    WS_PATH_ADD("/graphics");
    WS_PATH_LIST_END
};
