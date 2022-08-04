#pragma once
#ifndef LCD_CONTROLLER_H
#define LCD_CONTROLLER_H
#include "consts.h"

class LCDController {
  protected:
    LCDController();
    static LCDController* controller_;

  public:
    static LCDController *getInstance();
    void operator=(const LCDController &) = delete;
    LCDController(LCDController &other) = delete;
};
#endif