import processing.serial.*;

Serial myPort; // シリアル通信オブジェクト

void setup() {
  size(500, 500);
  background(255);
  myPort = new Serial(this, Serial.list()[0], 9600); // Arduinoに接続
}

void draw() {

}

void keyPressed() {
  writePort(key);
}

void writePort(char c) {
  myPort.write(c);
}
