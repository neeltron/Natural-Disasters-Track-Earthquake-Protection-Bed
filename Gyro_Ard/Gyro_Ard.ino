/*
 * I've used the GY-61 analog Gyroscope sensor with an Arduino Nano
 */

#include <math.h> // Library for analyzing gyroscope math
#include <Servo.h> # Library for working with the code
Servo myservo;
const int x_out = A0; /* connect x_out of module to A1 of UNO board */
const int y_out = A2;
const int z_out = A3;
int pos = 0;
void setup() {
  Serial.begin(9600); 
  myservo.attach(9);
}
int count;
void loop() {
  delay(70);
  int x_adc_value, y_adc_value; 
  double x_g_value;
  x_adc_value = map(analogRead(x_out), 355, 405, 0, 50);
  x_g_value = ( ( ( (double)(x_adc_value * 5)/1024) - 1.65 ) / 0.330 ); /* Acceleration in x-direction in g units */ 
  Serial.println(x_adc_value);
  if((x_adc_value < -20 || x_adc_value > 20) && count > 100) {
    myservo.write(0);
    delay(1000);
  }
  else {
    myservo.write(110);
  }
  count+=10;
}
