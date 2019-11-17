# "{"stop_robot":"False","direction":"True","lineal_speed":"0.2", "angular_speed":"0.0"}"
import json
import serial
import time


class ArduinoContoll:

    def __init__(self, uart_port):
        self.ser = serial.Serial(uart_port, 115200, timeout=1)  # open serial port
        print(self.ser.name)  # check which port was really used

    def fordware(self):
        data_to_send = {"stop_robot": "True", "direction": "True", "lineal_speed": "0.2", "angular_speed": "0.0"}
        dumped_json_string = json.dumps(data_to_send)
        print(dumped_json_string)
        self.ser.write(str(data_to_send).encode())
        self.ser.write(b'\n')
        time.sleep(0.1)

    def backward(self):
        data_to_send = {"stop_robot": "True", "direction": "False", "lineal_speed": "0.2", "angular_speed": "0.0"}
        dumped_json_string = json.dumps(data_to_send)
        print(dumped_json_string)
        self.ser.write(str(data_to_send).encode())
        self.ser.write(b'\n')
        time.sleep(0.1)

    def left(self):
        data_to_send = {"stop_robot": "True", "direction": "True", "lineal_speed": "0.1", "angular_speed": "0.1"}
        dumped_json_string = json.dumps(data_to_send)
        print(dumped_json_string)
        self.ser.write(str(data_to_send).encode())
        self.ser.write(b'\n')
        time.sleep(0.1)

    def right(self):
        data_to_send = {"stop_robot": "True", "direction": "True", "lineal_speed": "0.1", "angular_speed": "-0.1"}
        dumped_json_string = json.dumps(data_to_send)
        print(dumped_json_string)
        self.ser.write(str(data_to_send).encode())
        self.ser.write(b'\n')
        time.sleep(0.1)

    def stop(self):
        data_to_send = {"stop_robot": "False", "direction": "True", "lineal_speed": "0.1", "angular_speed": "0.1"}
        dumped_json_string = json.dumps(data_to_send)
        print(dumped_json_string)
        self.ser.write(str(data_to_send).encode())
        self.ser.write(b'\n')
        time.sleep(0.1)

    def write_command_to_arduino(self, action_to_do):
        print(action_to_do)
        if "adelante" in action_to_do:
            self.fordware()
            time.sleep(3)
            self.stop()

        elif "atras" in action_to_do:
            self.backward()
            time.sleep(3)
            self.stop()

        elif "izquierda" in action_to_do:
            self.left()
            time.sleep(3)
            self.stop()

        elif "derecha" in action_to_do:
            self.right()
            time.sleep(3)
            self.stop()

        elif "parar" in action_to_do:
            self.stop()

    def close_serial_comm(self):
        self.ser.close()


def main():
    ac = ArduinoContoll("/dev/ttyUSB0")
    for i in range(10):
        print("Iteration: " + str(i))
        ac.write_command_to_arduino("adelante")
        time.sleep(1)


    ac.stop()
    ac.close_serial_comm()


if __name__ == "__main__":
    main()
