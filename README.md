# Dragon12 Smart Room Automation

An embedded systems project built using the **Dragon12-Plus / MC9S12DG256** microcontroller.

The system combines environmental sensing, automated responses, access control, LCD feedback, and actuator control in a smart room prototype.

## Features

- 4-digit PIN access control
- LCD status display
- Temperature monitoring
- Automatic fan speed control
- Gas / CO₂ monitoring
- Buzzer alert for unsafe gas levels
- Water level monitoring
- Red and green LED indicators
- Soil moisture monitoring
- Moisture status alerts
- Continuous room monitoring

## Tech Stack

- Embedded C
- Dragon12-Plus
- MC9S12DG256 Microcontroller
- CodeWarrior
- ADC
- GPIO
- 4x4 Keypad Interfacing
- 16x2 LCD Interfacing
- DC Motor Control
- Sensor Integration
- LED Indicators
- Buzzer Alerts

## Access Control

The system uses a keypad to enter a 4-digit PIN.

If the PIN is correct, the LCD displays:

```text
WELCOME BACK
