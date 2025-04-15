
# Python script to read air quality data from NodeMCU via serial (USB)
import serial
import time

def read_serial_data(port='/dev/ttyUSB0', baudrate=9600):
    try:
        ser = serial.Serial(port, baudrate, timeout=2)
        time.sleep(2)  # Wait for connection to establish

        print("Reading data from NodeMCU...
")
        while True:
            if ser.in_waiting:
                line = ser.readline().decode('utf-8').strip()
                print(f"Received: {line}")
    except serial.SerialException as e:
        print(f"Serial connection error: {e}")
    except KeyboardInterrupt:
        print("Stopped by user")
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()

if __name__ == '__main__':
    # Change port as needed: COM3 for Windows, /dev/ttyUSB0 or /dev/ttyACM0 for Linux
    read_serial_data(port='/dev/ttyUSB0', baudrate=9600)
