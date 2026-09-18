#include <LiquidCrystal.h>

// Khởi tạo các chân kết nối LCD với Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensor = A1; // Gắn chân analog A1 làm biến 'sensor'
float tempc;           // Biến lưu giá trị nhiệt độ độ C
float tempf;           // Biến lưu giá trị nhiệt độ độ F
float vout;            // Biến tạm chứa kết quả phép đọc

void setup()
{
  pinMode(sensor, INPUT); // Cấu hình chân A1 làm ngõ vào
  Serial.begin(9600);
  lcd.begin(16, 2);       // Khởi động màn hình LCD 16 cột, 2 hàng
  delay(500);
}

void loop()
{
  // Đọc tín hiệu Analog và tính toán điện áp
  vout = analogRead(sensor);
  vout = (vout * 500) / 1023;
  
  tempc = vout;                // Lưu kết quả dưới dạng độ C
  tempf = (vout * 1.8) + 32;   // Chuyển đổi từ độ C sang độ F

  // Cài đặt con trỏ ở hàng 1, cột 1 và in ra độ C
  lcd.setCursor(0, 0);
  lcd.print("in DegreeC= ");
  lcd.print(tempc);

  // Cài đặt con trỏ ở hàng 2, cột 1 và in ra độ F
  lcd.setCursor(0, 1);
  lcd.print("in Fahrenheit=");
  lcd.print(tempf);

  // Trì hoãn 1s để ổn định kết quả hiển thị
  delay(1000);
}