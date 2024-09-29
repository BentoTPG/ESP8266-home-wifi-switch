# Things you need
- ESP8266
- relay module
- power supply (I use Hi-Link HLK-PM01)
- ac outlet
- toggle switch for turn it on-off if didn't acces to smartphone
- AC wire and plug
- wire connector
- Ribbon cable for connect board to relay module
# Wiring
connect it like this
![Diagram](image/circult_diagram.jpg)
AC connect
(I use type-O ac plug)
| component       | hot wire    | neutral wire | ground wire        |
|-----------------|-----------------|-----------------  |----------------|
|   HLK-PM01      | right AC        | left AC           | -              |
| relay module    | Middle input    | -                 | left input     |
| AC outlet       | left from the back of outlet     | right from the back of outlet       |    lower center       |
| AC plug       | right from the back of outlet     | left from the back of outlet       |     lower center      |

ESP8266 connect
| component       | red wire        | ground wire     | control wire |
|-----------------|-----------------|-----------------|--------------|
| relay module    | 3v3 pin to vcc pin   | GND to GND | D1 pin to in pin|
| momentary switch | -              | -               | D2 to GND    |
| HLK-PM01        | +Vo to Vin pin  | -Vo to GND pin  | -            |

#Coding
