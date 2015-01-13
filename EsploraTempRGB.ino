/*
  Show the temperature, in the RGB LED using a Esplora Arduino Board
  Based in  Esplora Temperature Sensor example by Tom Igoe

 Arduino Esplora uses a TMP36 sensor for reading the temperature.
 Its appears to depend heavily from the input voltage
  
 This example is in the public domain.
 CC by SA
 */
 
#include <Esplora.h>

void setup()
{
  Serial.begin(9600);      // initialize serial communications with your computer
} 

void loop()
{
  // read the temperature sensor in Celsius
  int celsius = Esplora.readTemperature(DEGREES_C);

  // send the value via Serial
  Serial.println(celsius);
  // the temperature values are typical of a house in Jaen
  switch(celsius)
  {
    case 10: Esplora.writeRGB(250,0,0); break;
    case 11: Esplora.writeRGB(200,50,0); break;    
    case 12: Esplora.writeRGB(150,100,0); break;
    case 13: Esplora.writeRGB(100,150,0); break;
    case 14: Esplora.writeRGB(50,200,0); break;    
    case 15: Esplora.writeRGB(0,250,0); break;        
    case 16: Esplora.writeRGB(0,200,50); break;            
    case 17: Esplora.writeRGB(0,150,100); break;            
    case 18: Esplora.writeRGB(0,100,150); break;                
    case 19: Esplora.writeRGB(0,50,200); break;                
    case 20: Esplora.writeRGB(0,0,250); break;                    
  }
  // wait a second before reading again:
  delay(1000);
}


