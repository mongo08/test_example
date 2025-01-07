#include "PaintGraphics.h"

int PaintGraphics::generated_number(int start_val, int end_val){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distrib(start_val,end_val);
    return distrib(gen);
}


void PaintGraphics::handleNewMessage(const WebSocketConnectionPtr& wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    if (type!=WebSocketMessageType::Ping){
        for (const WebSocketConnectionPtr& connect : connections)
        {
            
            this->json["x_axis"]=this->x[count]+std::abs(generated_number(0,9));
            this->json["y_axis"]=this->y[count]+std::abs(generated_number(0,9));
            connect->sendJson(this->json);
            if (this->count==5)
            {
                this->count=0;
            }
            this->count++;
        }
    }
}

void PaintGraphics::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr& wsConnPtr)
{
    this->connections.push_back(wsConnPtr);
    std::cout<<"count connected "<<this->connections.size()<<std::endl;
}


void PaintGraphics::handleConnectionClosed(const WebSocketConnectionPtr& wsConnPtr)
{
}
