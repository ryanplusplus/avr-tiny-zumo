# avr-tiny-zumo
[Arduino Uno R3](https://store.arduino.cc/usa/arduino-uno-rev3) powering a [Zumo Shield v1.2](https://www.pololu.com/product/2508).

## I/O
| Arduino | AVR | Peripheral | Function                 |
|:-------:|:---:|:----------:|:-------------------------|
|   D13   | PB5 |    GPIO    | Heartbeat LED            |
|   D8    | PB0 |    GPIO    | Left motor direction     |
|   D10   | PB2 |    OC1B    | Left motor power         |
|   D7    | PD7 |    GPIO    | Right motor direction    |
|   D9    | PB1 |    OC1A    | Right motor power        |
|   D2    | PD2 |    GPIO    | Reflectance disable      |
|   D4    | PD4 |    GPIO    | Outer left reflectance   |
|   A3    | PC3 |    GPIO    | Middle left reflectance  |
|   D11   | PB3 |    GPIO    | Inner left reflectance   |
|   A0    | PC0 |    GPIO    | Inner right reflectance  |
|   A2    | PC2 |    GPIO    | Middle right reflectance |
|   D5    | PD5 |    GPIO    | Outer right reflectance  |
|   D3    | PD3 |    OC2B    | Buzzer                   |
|   D12   | PB4 |    GPIO    | Button                   |
