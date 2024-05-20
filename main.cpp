#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

// nama variabel untuk menyambungkan Servo
Servo myservo;

// nama variabel untuk menyambungkan LCD
int SDA_pin = D0; // menghubungkan ke pin SDA
int SCL_pin = D1; // menghubungkan ke pin SCL
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    myservo.attach(D2); // menginisiasi fungsi Servo, menghubungkannya ke pin D2
    Wire.begin(SDA_pin, SCL_pin); // menyambungkan layar LCD
    // inisiasi Layar LCD
    lcd.begin(16,2);
    lcd.init();
    lcd.backlight();
}
void loop() {
    lcd.setCursor(0,0); // set kursor Layar LCD ke bagian (0,0)
    myservo.write(0); // menggerakan servo sebesar 0 derajat
    lcd.print("Terbuka"); // menampilkan teks "Terbuka" ke dalam Layar LCD
    delay(5000) // melakukan delay selama 5 detik
    lcd.setCursor(0,1) // set kursor Layar LCD ke bagian (0,1)
    myservo.write(90); // menggerakan servo sebesar 90 derajat
    lcd.print("Tertutup") // menampilkan teks "Tertutup" ke dalam Layar LCD
    delay(5000) // melakukan delay selama 5 detik
}