#pragma once
#ifndef S_CONTROLLER_H
#define S_CONTROLLER_H

class InputController {
  protected:
    InputController();
    static InputController* controller_;

  public:
    static InputController *getInstance();
    void operator=(const InputController &) = delete;
    InputController(InputController &other) = delete;
};
#endif