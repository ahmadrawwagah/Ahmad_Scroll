

#define IWIDTH  425
#define IHEIGHT 80
unsigned long lastMillis;
int dim = 0;

#define WAIT 10

#include <TFT_eSPI.h>                 

TFT_eSPI    tft = TFT_eSPI();        

TFT_eSprite img = TFT_eSprite(&tft); 

void setup(void) {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(0, 5000, 8); // 0-15, 5000, 8
  ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
  ledcWrite(0, 200);
  lastMillis = millis();
}

void loop() {

  img.createSprite(IWIDTH, IHEIGHT);
  int size = 1;
  int font = 4;
  int colorArray[] = {TFT_RED,TFT_BLUE,TFT_GREEN,TFT_WHITE,TFT_YELLOW,TFT_CYAN,
                      TFT_GOLD,TFT_DARKCYAN,TFT_BROWN,TFT_DARKGREY,TFT_ORANGE,
                      TFT_MAGENTA,TFT_NAVY,TFT_DARKGREEN,TFT_MAROON,TFT_PURPLE,TFT_OLIVE,
                      TFT_LIGHTGREY,TFT_GREENYELLOW,TFT_PINK};
  int cIndex = random(0,20);
  int updown = random(0,100);
  int heart = random(0,99);
  for (int pos = IWIDTH; pos > 0; pos--)
  {
    if(heart > 70){
      build_banner("<3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3", pos, font, size,colorArray[cIndex]);
      img.pushSprite(0, updown);
    }
    else{
    build_banner("TO BE LOVED IS TO BE CHANGED", pos, font, size,colorArray[cIndex]);
    img.pushSprite(0, updown);
    }
    delay(WAIT);
  }
  img.deleteSprite();
  if (millis() - lastMillis >= 5*60*1000UL) 
  {
    lastMillis = millis();
    if (dim)
    {
      pinMode(TFT_BL, OUTPUT);
      ledcSetup(0, 5000, 8); // 0-15, 5000, 8
      ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
      ledcWrite(0, 200);
      dim = 0; 
    }
    else{
      pinMode(TFT_BL, OUTPUT);
      ledcSetup(0, 5000, 8); // 0-15, 5000, 8
      ledcAttachPin(TFT_BL, 0); // TFT_BL, 0 - 15
      ledcWrite(0, 1);
      dim = 1;
    }
    
  }
}

void build_banner(String msg, int xpos, int font, int size, int color)
{
  int h = IHEIGHT;

  img.fillSprite(TFT_BLACK);

  img.setTextSize(size);          
  img.setTextFont(font);          
  img.setTextColor(color); 
  img.setTextWrap(false);       
  img.setCursor(xpos, 2); 
  img.print(msg);

  img.setCursor(xpos - IWIDTH, 2);
  img.print(msg);
}





