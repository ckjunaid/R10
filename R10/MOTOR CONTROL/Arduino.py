import serial
import time
import keyboard  # pip install keyboard

# Change this to match your COM port
SERIAL_PORT = 'COM5'
BAUD_RATE = 9600

# Open serial connection to Arduino
ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # Wait for Arduino to reset

print("Use keys: W (forward), S (stop), R (reverse), Q (quit)")

try:
    while True:
        if keyboard.is_pressed('w'):
            ser.write(b'f')
            print("Forward")
            time.sleep(0.2)
        elif keyboard.is_pressed('r'):
            ser.write(b'r')
            print("Reverse")
            time.sleep(0.2)
        elif keyboard.is_pressed('s'):
            ser.write(b's')
            print("Stopped")
            time.sleep(0.2)
        elif keyboard.is_pressed('q'):
            print("Exiting...")
            ser.write(b's')  # Stop motor before exit
            break
except KeyboardInterrupt:
    pass
finally:
    ser.close()
