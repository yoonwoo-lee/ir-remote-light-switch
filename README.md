# ir-remote-light-switch

## Context
As someone who is always up late at night studying, I found myself often falling asleep with the lights turned on because the light switch was too far from my bed. So I wanted to build something that would solve this minor inconvenience in my daily life, while also learning about the hardware that would later bolster my career. Therefore, I built this IR-remote-powered light switch, which allows me to control my light switch with an infrared remote. This is my first project and proper github repository (other than my arduino learning phase reports), so bear with me while I unearth the beauties of electrical engineering. Thank you!

## Components
- Arduino Mega 2560
- IR receiver
- Servo motor
- IR remote
- Breadboard + jumper wires (female-to-male and male-to-male)
- Double-sided adhesive
- Wooden Chopsticks
- Styrofoam

## How It Works
Brief explanation: IR remote sends a signal → IR receiver decodes it → 
Arduino checks which button was pressed → servo taps the switch → 
returns to neutral after 3 seconds so the switch can still be used manually.

## Installation / Setup
1. Wire the IR receiver to pin 11, servo to pin 9 (adjust as needed)
2. Install the IRremote library and Servo Library via Arduino IDE Library Manager
3. Upload the sketch
4. Point remote at receiver, press assigned buttons to toggle

## Lessons Learned
This was my first real hardware + code project outside of guided tutorials, 
and a few things genuinely tripped me up:

- **Variable scope**: I initially declared a variable inside an `if` block 
  and tried to use it outside that block. I learned the hard way that 
  variables only exist within the `{ }` they're declared in.

- **`delay()` vs `millis()`**: My first instinct was to use `delay()` to 
  make the servo pause before returning to its resting position. But 
  `delay()` freezes the entire program, meaning the Arduino would ignore 
  any remote button presses during that pause. Switching to `millis()`-based 
  timing let the servo "wait" without blocking the rest of the program.

- **Hardware constraints shape software design**: I originally had the 
  servo hold its "on" or "off" position. But I realized that if someone 
  (like me) tried to flip the switch by hand while the servo was holding 
  position, they'd be fighting the motor. I redesigned the logic so the 
  servo briefly "taps" the switch and returns to a neutral position, 
  meaning the switch can always still be used manually, regardless of 
  what the servo last did.

- Adaptation: Initially, I was going to just have two chopsticks run down
  perpendicular to the servo horn to flip the light switches, but I
  quickly realized that it didn't exert enough force, so I added extra support
  to form a triangle shape, which I heard was the best shape for stability. 

## Future Improvements
- Mount refinements for more reliable switch alignment
- Stronger servo
- Clean up wiring with a proper enclosure instead of a breadboard
- Replace adhesive material with screws
- Use an external powerbank that could power the servo and the arduino board (you can see my failed attempt at the battery in the video)
