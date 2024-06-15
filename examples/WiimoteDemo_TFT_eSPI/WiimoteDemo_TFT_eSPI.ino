#include <ESP32Wiimote.h>
#include <TFT_eSPI.h>
#include "wiimote_png.h"

uint16_t xWiimote = 0;
uint16_t yWiimote = 78;

ESP32Wiimote wiimote;
TFT_eSPI tft = TFT_eSPI();
//TFT_eSprite sprite = TFT_eSprite(&tft);  

void setup()
{
  Serial.begin(115200);
  Serial.println("ESP32Wiimote");

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
    
  wiimote.init();
  
  tft.setSwapBytes(true); // We need to swap the colour bytes (endianess)
  tft.pushImage(xWiimote, yWiimote, 320, 83, Wiimote);       
}

void loop()
{
  wiimote.task();

  if (wiimote.available() > 0) 
  {
    uint16_t button = wiimote.getButtonState();
    Serial.printf("%04x\n", button);

    tft.pushImage(xWiimote, yWiimote, 320, 83, Wiimote); 
    if(button & ESP32Wiimote::BUTTON_RIGHT) tft.fillCircle(58 + xWiimote, 30 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_LEFT) tft.fillCircle(58 + xWiimote, 56 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_UP) tft.fillCircle(45 + xWiimote, 42 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_DOWN) tft.fillCircle(73 + xWiimote, 42 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_ONE) tft.fillCircle(230 + xWiimote, 42 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_TWO) tft.fillCircle(256 + xWiimote, 42 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_A) tft.fillCircle(103 + xWiimote, 42 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_B) tft.fillRoundRect(9 + xWiimote , 6 + yWiimote, 303, 75, 5, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_HOME) tft.fillCircle(153 + xWiimote, 42 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_PLUS) tft.fillCircle(153 + xWiimote, 22 + yWiimote, 10, TFT_RED);
    if(button & ESP32Wiimote::BUTTON_MINUS) tft.fillCircle(153 + xWiimote, 63 + yWiimote, 10, TFT_RED);
  }
  delay(10);
}
