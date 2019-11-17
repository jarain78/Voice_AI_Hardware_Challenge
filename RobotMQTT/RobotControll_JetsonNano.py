# -*- coding: utf-8 -*-
import base64
import time
from pathlib import Path
import paho.mqtt.client as mqtt
from ArduinoControll.ArduinoControll import ArduinoContoll



class MQTT_Jetson_Communication:

    def __init__(self, ip_adress):
        self.mqttc = mqtt.Client("Arduino_Sensors", clean_session=False)
        self.mqttc.on_message = self.mqtt_on_message

        self.mqttc.connect(ip_adress, 1883)
        print("MQTT Connected...")
        self.mqttc.subscribe("actuator/motors")
        self.mqttc.subscribe("artificial_intelligence/encoder")
        self.low_level_control = ArduinoContoll("/dev/ttyUSB0")

        #self.people_id = PeopleIdentifier()

    def mqtt_on_message(self, client, userdata, msg):
        self.arduino_publish_actuator_data(msg)
        #self.artificial_intelligence(msg)


    # Arduino
    def arduino_publish_actuator_data(self, msg):
        # self.mqttc.publish("actuator/motors")

        if msg.payload == b'':
            pass
        else:
            try:
                message = msg.payload
                action = message.decode('utf8')
                print("Topic: ", msg.topic + ' Message: ' + action)
                self.low_level_control.write_command_to_arduino(action)
            except KeyboardInterrupt:
                pass

    # Artificial Intelligence
    def artificial_intelligence(self, msg):
        # arduino_data = self.ser_comm.read_command(self.car_socket)

        if msg.payload == b'':
            pass
        else:
            try:
                message = msg.payload
                print("Topic: ", msg.topic + ' Message: ' + message.decode('utf8'))

                with open("static/Temporal_Image/tempImg.jpg", "wb") as fh:
                    fh.write(base64.decodebytes(str(message.decode('utf8')).encode()))

                # people_id.create_npy_encodig_data()
                # people_id.rename_and_move_npy_file("Sol")

                #msg, list_of_true_or_false, n_faces, face_image = self.people_id.read_temporal_memory()
                print(msg)
                print(list_of_true_or_false)


            except KeyboardInterrupt:
                pass

    # Peson Identification
    def person_id(self):
        pass

    # MQTT
    def mqtt_main_loop(self):
        self.mqttc.loop_start()
        while True:
            try:
                pass
            except KeyboardInterrupt:
                pass
                break

    def clos_mqtt(self):
        self.mqttc.disconnect()  # disconnect
        self.mqttc.loop_stop()


# ----------------------------------------------

ip_adress = "Snip-Ip"

mqtt_comm = MQTT_Jetson_Communication(ip_adress)

# Steep 3: Init MQTT
mqtt_comm.mqtt_main_loop()

print("Close Communication...")
# Steep --: Close Communication
# ser_comm.close_communication(car_socket)
