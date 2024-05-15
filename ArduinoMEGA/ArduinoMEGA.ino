#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>

const int PinoSensor = A0;
const int ValorMaximoLeituras = 10000;
const float CoeficienteA = 87.1;
const float CoeficienteB = -75.4;

LiquidCrystal_I2C_Hangul lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);

  pinMode(PinoSensor, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Intensidade:");
  lcd.setCursor(0, 1);
  lcd.print("dB: ");
}

void loop() { 
  int valorMaior = 0;
  for (int i = 0; i < ValorMaximoLeituras; i++) {
    int valorAtual = analogRead(PinoSensor);
    if (valorAtual > valorMaior) {
      valorMaior = valorAtual;
    }
  }


  float tensao = valorMaior / 1023.0 * 4.53;
  int dB = CoeficienteA * tensao + CoeficienteB;
  if (dB < 0) {
    dB = 0;
  }

  lcd.setCursor(4, 1);
  lcd.print("    ");
  lcd.setCursor(4, 1);
  lcd.print(dB);

  Serial.print("Tensao: ");
  Serial.print(tensao);
  Serial.println(" V");
  Serial.print("Intensidade: ");
  Serial.print(dB);
  Serial.println(" dB");

    if (dB > 20) {
    Serial1.println(dB);
  }

  delay(500);
}
