#include "lcdController.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27,20,4); 

LCDController* LCDController::controller_ = nullptr;
LCDController::LCDController(){
  Wire.begin(SDA_PIN, SDL_PIN);
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
}

LCDController *LCDController::getInstance() {
  if(controller_ == nullptr) controller_ = new LCDController();
  return controller_;
};