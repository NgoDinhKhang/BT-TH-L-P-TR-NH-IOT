const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setRgb(0, 0, 0); // Đặt toàn bộ màu về 0 khi bắt đầu
}

void loop() {
  int Rgb[3];
  Rgb[0] = 255; // Bắt đầu từ màu Đỏ
  Rgb[1] = 0;
  Rgb[2] = 0;

  // Thuật toán hòa trộn màu sắc mượt mà của Bài 6
  for (int decrease = 0; decrease < 3; decrease += 1) {
    int increase = (decrease == 2) ? 0 : (decrease + 1);

    for (int i = 0; i < 255; i += 1) {
      Rgb[decrease] -= 1;
      Rgb[increase] += 1;

      setRgb(Rgb[0], Rgb[1], Rgb[2]);
      delay(20);
    }
  }
}

void setRgb(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}