const int kPinPot = A0;  // Chân đọc tín hiệu từ chiết áp
const int kPinLed = 9;   // Chân xuất tín hiệu điều khiển LED (PWM)

void setup() {
  pinMode(kPinPot, INPUT);
  pinMode(kPinLed, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(kPinPot);                // Đọc giá trị từ 0 đến 1023
  int ledBrightness = map(sensorValue, 0, 1023, 0, 255); // Quy đổi sang khoảng 0 đến 255

  analogWrite(kPinLed, ledBrightness);                  // Xuất độ sáng ra LED
}