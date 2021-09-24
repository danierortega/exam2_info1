int fil1[192]={
//incio
 
  
  
  
  
  //fin
};

#include <Adafruit_NeoPixel.h>

#define  LED_PIN 2

#define LED_COUNT 64

Adafruit_NeoPixel  leds(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  leds.begin();  
  for(int x=0, i=0; x < 192; i++){
    int r=fil1[x];
    int g=fil1[x+1];
    int b=fil1[x+2];
	if(r==255 && g==255 && b==255){b--;}
    leds.setPixelColor(i,r,g,b);
    x=x+3;
  }

  leds.show();  
}

void loop(){

}