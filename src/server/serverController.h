#pragma once
#ifndef S_CONTROLLER_H
#define S_CONTROLLER_H
#include "consts.h"

class ServerController {
  protected:
    ServerController();
    static ServerController* controller_;

  public:
    static ServerController *getInstance();
    void operator=(const ServerController &) = delete;
    ServerController(ServerController &other) = delete;
};
#endif