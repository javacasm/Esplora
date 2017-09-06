/*

 Esplora TFT EtchASketch

 This example for the Arduino TFT and Esplora draws
 a white line on the screen, based on the position
 of the joystick. To clear the screen, shake the
 Esplora, using the values from the accelerometer.

 This example code is in the public domain.

 Created 15 April 2013 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/EsploraTFTEtchASketch

 */

#include <Esplora.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// initial position of the cursor
int xPos = EsploraTFT.width() / 2;
int yPos = EsploraTFT.height() / 2;

void setup() {
  // initialize the display
  EsploraTFT.begin();

  // clear the background
  EsploraTFT.background(0, 0, 0);
  muestraColor();
}
 
int r=255,g=255,b=255;

void muestraColor(){
  char buffer[20];
  sprintf(buffer,"%d,%d,%d",r,g,b);
  EsploraTFT.setTextSize(1);
  //EsploraTFT.noStroke(); // don't draw a line around the next rectangle
  EsploraTFT.fill(0, 0, 0); // set the fill color to green
  EsploraTFT.rect(0, 0, 70, 13);
  EsploraTFT.text(buffer,3,3);

}
void loop() {

  int xAxis = Esplora.readJoystickX();    // read the X axis
  int yAxis = Esplora.readJoystickY();    // read the Y axis

  // update the position of the line
  // depending on the position of the joystick
  if (xAxis < 10 && xAxis > -10) {
    xPos = xPos;
  } else {
    xPos = xPos + (map(xAxis, -512, 512, 2, -2));
  }
  if (yAxis < 10 && yAxis > -10) {
    yAxis = yAxis;
  } else {
    yPos = yPos + (map(yAxis, -512, 512, -2, 2));
  }

  // don't let the point go past the screen edges
  if (xPos > 159) {
    (xPos = 159);
  }

  if (xPos < 0) {
    (xPos = 0);
  }
  if (yPos > 127) {
    (yPos = 127);
  }

  if (yPos < 0) {
    (yPos = 0);
  }

  // draw the point

  if(Esplora.readButton(SWITCH_LEFT)==PRESSED) {
    r=map(Esplora.readSlider(), 0, 1023, 0, 255); 
    muestraColor();
  }
  if(Esplora.readButton(SWITCH_UP)==PRESSED) {
    b=map(Esplora.readSlider(), 0, 1023, 0, 255); 
    muestraColor();
  }
  if(Esplora.readButton(SWITCH_DOWN)==PRESSED) {
    g=map(Esplora.readSlider(), 0, 1023, 0, 255); 
    muestraColor();
  }  
  EsploraTFT.stroke(r, g, b);

  
  EsploraTFT.point(xPos, yPos);

  
  // check the accelerometer values and clear
  // the screen if it is being shaken
  if (abs(Esplora.readAccelerometer(X_AXIS)) > 200 || abs(Esplora.readAccelerometer(Y_AXIS)) > 200) {
    EsploraTFT.background(0, 0, 0);
  }

  delay(33);
}

