#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>

#define PIXEL_PIN 3
#define PIXEL_COUNT 4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  pixels.begin();
  Serial.begin(115200);
}

void loop(){
  if(Serial.available() > 0){
    StaticJsonBuffer<200> jsonBuffer;
    String inp = Serial.readStringUntil('\n');
    JsonObject& root = jsonBuffer.parseObject(inp);
    if(root.success()){
      // command = root["command"].asString();
      // red = root["red"];
      // green = root["green"];
      // blue = root["blue"];
      // index = root["index"];
    }
  }
}
