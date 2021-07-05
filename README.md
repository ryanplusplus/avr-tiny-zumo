# avr-tiny-zumo
[Arduino Uno R3](https://store.arduino.cc/usa/arduino-uno-rev3) powering a [Zumo Shield v1.2](https://www.pololu.com/product/2508).

## I/O
| Arduino | AVR | Peripheral | Function                 |
|:-------:|:---:|:----------:|:-------------------------|
|   D13   | PB5 |    GPIO    | Heartbeat LED            |
|   D7    | PD7 |    GPIO    | Right motor direction    |
|   D9    | PB1 |    OC1A    | Right motor power        |
|   D8    | PB0 |    GPIO    | Left motor direction     |
|   D10   | PB2 |    OC1B    | Left motor power         |
|   D5    | PD5 |    GPIO    | Far right reflectance    |
|   A2    | PC2 |    GPIO    | Middle right reflectance |
|   A0    | PC0 |    GPIO    | Inner right reflectance  |
|   D11   | PB3 |    GPIO    | Inner left reflectance   |
|   A3    | PC3 |    GPIO    | Middle left reflectance  |
|   D4    | PD4 |    GPIO    | Far left reflectance     |
|   D3    | PD3 |    OC2B    | Buzzer                   |
|   D12   | PB4 |    GPIO    | Button                   |
