#include <hidef.h> 
#include <mc9s12dg256.h> 
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"
#include "main_asm.h" 
int key_scan(void) {
  const char keycodes[] = {
    0xEE, 0xED, 0xEB, 0xE7,
    0xDE, 0xDD, 0xDB, 0xD7,
    0xBE, 0xBD, 0xBB, 0xB7,
    0x7E, 0x7D, 0x7B, 0x77
  };
  char readBack;
  int i, j, result, key;
  i = 0;
  result = 0;
  key = 16;
  while (i < 16 && result == 0) {
    PORTA = keycodes[i];
    for (j = 0; j < 10; j++){}
    readBack = PORTA;
    if (readBack == keycodes[i]) {
      key = i;
      result = 1;
    } else {
      i++;
    }
  }
  return key;
}
void waitForKeyUp() {
  while (key_scan() != 16) {}
}
int getKey() {
  int key;
  do {
    key = key_scan();
  } while (key == 16);
  return key;
}
  float x;
  char* q1;
  char* q2;
  char password[] = {1, 2, 3, 4}; 
  char c;
  int i;
  int j;
  int flag = 1;
   
void main(void) {
 DDRB = 0xff; 
 DDRA = 0x0f;
 PUCR = 0x01;
 DDRM |= 0x80; 
 
 PLL_init(); // clock frq = 24 MHz
 seg7_disable();
 led_enable();
 lcd_init();
 ad0_enable();
motor0_init();
 SW_enable();
  q1 = "WELCOME BACK";
  q2 = "INTRUDER";
DDRH |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
while(1){
int CO2;
 int waterLevel;
int tempSensor;
 int dcMotor;
int soilLevel;
char input[] = {0, 0, 0, 0}; 
 for (i = 0; i < 4; i++) {
  input[i] = getKey();
   seg7dec(input[i], 3);
    waitForKeyUp();
    }
    // compare input with pass
    for (j = 0; j < 4; j++) {
      if (input[j] != password[j]) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) { 
      set_lcd_addr(0x02);
      type_lcd(q1);
      ms_delay(1000);
      clear_lcd();
      ms_delay(1000);
    } else {
      set_lcd_addr(0x02);
      type_lcd(q2);
    }
    flag = 1;
    while (flag = 1){
    clear_lcd();
    ms_delay(2000);
      
     // temp sensor
    tempSensor = ad0conv(5) >> 1; 
    set_lcd_addr(0x00);
    write_int_lcd(tempSensor);
    set_lcd_addr(0x05);
    type_lcd(" C= ");
    //ms_delay(100);
      
    // dc motor
    if (tempSensor < 20){
    leds_on(SW1_dip());
    dcMotor = ad0conv(7)  * 0;  //0
    motor0(dcMotor);
    set_lcd_addr(0x08);
    type_lcd("0");
    //ms_delay(100);
} 
else if (20 > tempSensor && tempSensor < 25){
    leds_on(SW1_dip());
    dcMotor = ad0conv(7) >> 3; //127
    motor0(dcMotor);
    set_lcd_addr(0x09);
    type_lcd("L");
    //ms_delay(100);
} 

else if (tempSensor > 25 && tempSensor < 30){
    leds_on(SW1_dip());
    dcMotor = ad0conv(7) >> 2;  //255
    motor0(dcMotor);
    set_lcd_addr(0x09);
    type_lcd("M");
    //ms_delay(100);
} 
else {
    leds_on(SW1_dip());
    dcMotor = ad0conv(7) >> 1;  //511
    motor0(dcMotor);
    set_lcd_addr(0x09);
    type_lcd("H");
    //ms_delay(100);
} 
      
//water sensor and leds
 set_lcd_addr(0x0A);
 type_lcd("|H2O:");
 waterLevel = ad0conv(3);
 waterLevel = waterLevel >> 2;
if(waterLevel < 150){
 set_lcd_addr(0x0F);
 type_lcd("L");
PTH |= (1 << 0);
 PTH &= ~ (1 << 2);
 //ms_delay(100);
} 
else {
ms_delay(10);  
 set_lcd_addr(0x0F);
 type_lcd("H");
PTH |= (1 << 2);
 PTH &= ~ (1 << 0);
 //ms_delay(100);
}
      
//CO2 and buzzer
 set_lcd_addr(0x4A);
 type_lcd("|CO2: ");
CO2 = ad0conv(2);
 CO2 = CO2 >> 2;
if(CO2 >= 200){
 set_lcd_addr(0x4F);
 type_lcd("H");
PTH |= (1 << 3);
 ms_delay(50);
 PTH &= ~(1 << 3);
 ms_delay(1);
} else{
  set_lcd_addr(0x4F);
  type_lcd("N");
  //ms_delay(100);
 }
    //Moisture and led
    set_lcd_addr(0x40);
    write_int_lcd(soilLevel);
    soilLevel  = ad0conv(4);
    soilLevel  = soilLevel >> 1;
    ms_delay(1);
    if (soilLevel<280) {
    set_lcd_addr(0x40);
    type_lcd("TOO WET");
    PTH |= (1 << 1);
  } else if (soilLevel >= 300 && soilLevel <= 400){
    set_lcd_addr(0x40);
    type_lcd("GOOD");
    PTH &= ~(1 << 1);
  }
  else {
    set_lcd_addr(0x40);
    type_lcd("TOO Dry");
    PTH |= (1 << 1);
    ms_delay(1);
  }
      // Delay for stability
      ms_delay(1000); 
}
}     
}
