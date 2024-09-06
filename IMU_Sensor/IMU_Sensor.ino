#include <Wire.h>
#define sensor_address 0x68  //Sensor address
//register address for acceleration
#define accel_x 0x3B
#define accel_y 0x3D
//register address for gyroscope
#define gyro_z 0x47

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}
//Function to read from sensor
int16_t read(uint8_t x) 
{
  Wire.beginTransmission(sensor_address);
  Wire.write(x);
  Wire.endTransmission();
  
  Wire.requestFrom(sensor_address, 2);
  uint8_t high = Wire.read();
  uint8_t low = Wire.read();
  return (high << 8) | low;
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ax = read(accel_x);
  uint16_t ay = read(accel_y);
  uint16_t gz = read(gyro_z);

  Serial.print("Ax= ");
  Serial.println(ax);

  Serial.print("Ay= ");
  Serial.println(ay);

  Serial.print("Gz= ");
  Serial.println(gz);
  delay(500);
}
