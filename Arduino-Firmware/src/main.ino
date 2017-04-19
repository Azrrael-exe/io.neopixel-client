#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>

#define PIXEL_PIN 4
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
      changeColors(pixels, root);
    }
  }
}

void changeColors(Adafruit_NeoPixel& pix, JsonObject& json){
  uint8_t num_pixels = pix.numPixels();
  for(int i=0; i<num_pixels; i++){
    uint8_t red = json["r"];
    uint8_t green = json["g"];
    uint8_t blue = json["b"];
    pix.setPixelColor(i, red, green, blue);
  }
  pix.show();
}
