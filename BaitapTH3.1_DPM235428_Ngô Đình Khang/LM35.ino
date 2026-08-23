void setup() {
  // Khởi tạo giao tiếp nối tiếp ở tốc độ 9600 bit/giây
  Serial.begin(9600);
}

void loop() {
  // Đọc ngõ ra tại chân A0 (trả về giá trị trong khoảng từ 0 đến 1023)
  int sensorValue = analogRead(A0);

  // In giá trị đọc được lên Serial Monitor
  Serial.println(sensorValue);

  // Tạo trễ 1ms để giá trị đọc được ổn định
  delay(1);
}