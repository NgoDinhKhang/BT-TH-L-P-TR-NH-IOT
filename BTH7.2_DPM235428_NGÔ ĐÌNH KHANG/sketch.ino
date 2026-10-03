// Khai báo chân nối LED (Sử dụng chân GPIO 4)
int ledPin = 4; 
// Biến giữ hệ số đóng (duty cycle) từ 0 đến 1023
int fadeValue = 1023; 

void setup() {
  // Cài đặt chân số 4 là ngõ ra
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Bật LED với mức độ sáng tương ứng với fadeValue
  analogWrite(ledPin, fadeValue);
  
  // Giảm dần độ sáng xuống 1 đơn vị
  if (fadeValue > 0) {
    fadeValue--;
  }
  
  // Trì hoãn 5 mili-giây để thấy hiệu ứng mờ dần
  delay(5); 
}