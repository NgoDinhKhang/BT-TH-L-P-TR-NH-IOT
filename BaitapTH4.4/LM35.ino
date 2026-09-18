int buzzer = 8;
int LED = 7;
int flame_sensor = 4;
int flame_detected; // Biến lưu trạng thái đọc từ cảm biến

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
}

void loop()
{
  // Đọc đầu ra digital từ cảm biến cháy và lưu trữ vào biến
  flame_detected = digitalRead(flame_sensor);
  
  // Nếu flame_detected bằng 1 (HIGH), chỉ ra ngọn lửa đã được phát hiện
  if (flame_detected == 1)
  {
    Serial.println("Phat hien ngon lua...!");
    digitalWrite(buzzer, HIGH); // Bật còi
    
    // Tạo hiệu ứng chớp tắt cho đèn LED báo động
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
  else
  {
    // Nếu bằng 0 (LOW), không có ngọn lửa
    Serial.println("Khong co lua phat hien");
    digitalWrite(buzzer, LOW); // Tắt còi
    digitalWrite(LED, LOW);    // Tắt đèn
    delay(1000);
  }
}