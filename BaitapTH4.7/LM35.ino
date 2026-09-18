int mq2Pin = A0;   // Chân Analog A0 đọc tín hiệu từ cảm biến MQ-2
int buzzerPin = 8; // Chân còi báo động
int ledPin = 13;   // Chân đèn báo động
int gasLevel = 0;  // Biến lưu nồng độ khí gas đọc được

// Đặt ngưỡng cảnh báo (Threshold). Thang đo từ 0-1023.
// Trong thực tế, bạn sẽ phải thử xịt ga để tìm ra con số phù hợp. Ở đây mình ví dụ là 400.
int threshold = 400; 

void setup() {
  Serial.begin(9600); // Khởi động Serial Monitor
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 1. Đọc giá trị Analog từ cảm biến MQ-2
  gasLevel = analogRead(mq2Pin); 
  
  // 2. In giá trị ra màn hình để theo dõi giám sát
  Serial.print("Nong do khi Gas/Khoi: ");
  Serial.println(gasLevel);

  // 3. So sánh với ngưỡng an toàn để ra quyết định
  if (gasLevel > threshold) {
    // Vượt ngưỡng -> Báo động!
    Serial.println("!!! CANH BAO: Phat hien ro ri khi Gas !!!");
    digitalWrite(ledPin, HIGH);    // Bật đèn
    digitalWrite(buzzerPin, HIGH); // Bật còi
  } else {
    // An toàn -> Tắt báo động
    digitalWrite(ledPin, LOW);     // Tắt đèn
    digitalWrite(buzzerPin, LOW);  // Tắt còi
  }
  
  delay(500); // Trì hoãn 0.5s trước khi đọc lần tiếp theo
}