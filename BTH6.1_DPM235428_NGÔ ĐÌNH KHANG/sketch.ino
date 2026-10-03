int ledPin = 5; 

void setup() {
  // BẮT BUỘC THÊM: Khởi động Serial Monitor ở tốc độ 115200
  Serial.begin(115200);
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Tắt đèn
  digitalWrite(ledPin, LOW);
  Serial.println("Đèn đang TẮT"); // Chuyển lên trước delay để báo ngay lập tức
  delay(1000); 
  
  // Bật đèn
  digitalWrite(ledPin, HIGH);
  Serial.println("Đèn đang SÁNG"); // Chuyển lên trước delay
  delay(2000); 
}