int ldrPin = A0;  // Chân Analog A0 đọc giá trị LDR
int ledPin = 13;  // Chân Digital 13 điều khiển đèn LED
int ldrValue = 0; // Biến lưu trữ giá trị đọc được

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Đọc giá trị từ quang trở (Thang đo từ 0 - 1023)
  ldrValue = analogRead(ldrPin);
  
  // In giá trị ra Serial Monitor để theo dõi
  Serial.print("Gia tri anh sang: ");
  Serial.println(ldrValue);

  // Kiểm tra: Nếu trời tối (giá trị ánh sáng tụt xuống dưới 400)
  // Bạn có thể thay đổi số 400 này để điều chỉnh độ nhạy (tương đương với việc vặn biến trở trong mạch rời)
  if (ldrValue < 400) {
    digitalWrite(ledPin, HIGH); // Bật đèn LED
    Serial.println("=> Troi toi. BAT den!");
  } else {
    digitalWrite(ledPin, LOW);  // Tắt đèn LED
    Serial.println("=> Troi sang. TAT den!");
  }
  
  delay(500); // Trì hoãn 0.5 giây
}