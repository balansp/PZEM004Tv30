
#include <PZEM004Tv30.h>

PZEM004Tv30 pzem(&Serial);

float voltage = 0;
float current = 0;
float power = 0;
float energy = 0;
float frequency = 0;
float pf = 0;
String output ="";
unsigned long tmr = 0;



void setup() {
  Serial.begin(9600);
}

void loop() {
   if((millis() - tmr) > 1000) {
          tmr = millis();
          voltage = pzem.voltage();
          current = pzem.current();
          power = pzem.power();
          energy = pzem.energy();
          frequency = pzem.frequency();
          pf = pzem.pf();
        
          
          output ="";
          if (!isnan(voltage)) {
            output += String(voltage, 1) + "V,";
          } else {
            output += "Error,";
          }
        
          if (!isnan(current)) {
            output += String(current, 3) + "A,";
          } else {
            output += "Error,";
          }
        
          if (!isnan(power)) {
            output += String(power, 0) + "W,";
          } else {
            output += "Error,";
          }
        
          if (!isnan(energy)) {
            output += String(energy, 3) + "kWh,";
          } else {
            output += "Error,";
          }
        
          if (!isnan(frequency)) {
            output += String(frequency, 1) + "Hz,";
          } else {
            output += "Error,";
          }
        
          if (!isnan(pf)) {
            output += String(pf) + "pf";
          } else {
            output += "Error";
          }

         Serial.println(output);
   }
}
