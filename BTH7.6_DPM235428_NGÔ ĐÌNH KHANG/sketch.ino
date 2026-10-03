#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Chiều rộng màn hình OLED (pixel)
#define SCREEN_HEIGHT 64 // Chiều cao màn hình OLED (pixel)

// Khai báo đối tượng OLED (sử dụng giao tiếp I2C)
#define OLED_RESET -1    // Chân reset (nếu không dùng thì đặt là -1)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Khởi động màn hình OLED với địa chỉ I2C mặc định là 0x3C hoặc 0x3D
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Khong tim thay man hinh SSD1306 OLED!"));
    for(;;); // Treo chương trình nếu lỗi
  }

  // Xóa bộ nhớ đệm màn hình
  display.clearDisplay();

  // Cấu hình chữ hiển thị
  display.setTextSize(2);      // Kích thước chữ (1 là nhỏ, lớn hơn thì phóng to)
  display.setTextColor(WHITE); // Màu chữ (trắng)
  display.setCursor(10, 20);   // Tọa độ con trỏ (X, Y)
  display.println(F("Xin chao!")); // Nội dung cần in ra

  // Đẩy dữ liệu ra màn hình thực tế
  display.display();
}

void loop() {
  // Màn hình OLED hiển thị tĩnh nên vòng lặp để trống
}