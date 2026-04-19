#include "M5Cardputer.h"

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  // Liga o barramento da tela
  M5.Lcd.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setBrightness(100);

  // Coloca o fundo azul
  M5.Lcd.fillScreen(BLUE);

  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10,30);
  M5.Lcd.println("Hello World");

  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(10,70);
  M5.Lcd.println("Se vc está vendo isso,");
  M5.Lcd.println("o hardware está vivo");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
