#include <LiquidCrystal.h>

byte kare[8] =
{
    B11111,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B11111
};

byte karedolu[8] =
{
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

// LCD Ekran Pinleri
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("1");
  Serial.begin(9600);
}

void loop()
{
  if (Serial.read() == 5)
  {
    lcd.createChar(1, kare);
    lcd.setCursor(0, 2);
    lcd.write(1);
    lcd.setCursor(3, 0);
    lcd.print("             ");
    lcd.setCursor(6, 2);
    lcd.print("       ");
  }
  else
  {
    lcd.createChar(2, karedolu);
    lcd.setCursor(0, 2);
    lcd.write(2);
    lcd.setCursor(3, 0);
    lcd.print("O T O P A R K");
    lcd.setCursor(6, 2);
    lcd.print("D O L U");
  }

  delay(100);
}