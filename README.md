# 🌊 M5Tough Balboa Spa Monitor

An ESP32-based project for monitoring Balboa spa systems using the M5Tough device with RS485 communication. This project is built on ESPHome and provides real-time spa monitoring capabilities.

![M5Tough Balboa Spa Wiring](documentation/hw-setup-final.png)


## 🛠️ Required Components

To build this Balboa spa monitoring system, you'll need the following hardware components:

### 💻 Core Hardware
- **[M5Stack Tough ESP32 IoT Development Board Kit](https://shop.m5stack.com/products/m5stack-tough-esp32-iot-development-board-kit?variant=40644956160172)** - The main ESP32 controller with integrated 2.4" TFT display and touch screen
- **[RS485 Module](https://shop.m5stack.com/products/rs485-module)** - M5Stack RS485 communication module for Grove Port A connection

### 🔌 Cable Connection
- **[CY ATX Molex Micro Fit Grid 3.0 mm 4-Pin Male Cable](https://www.amazon.de/gp/product/B07Z7X5KW1)** Cable for connecting the RS485 module to your Balboa spa's RS485 communication lines

⚠️ **ATTENTION**: We will not use USB to power the M5Tough! Instead, we use the 12V and GND from the Balboa spa system via the RS485 Unit to power the M5Stack. All 4 wires are required (12V, GND, A+, B-). Exact pinout can be found in the referenced ESPHome Balboa projects.

### ➕ Additional Requirements
- **Balboa Spa System** - Compatible spa system with accessible RS485 communication port
- **Network Connection** - WiFi network for MQTT and web interface connectivity

## 📊 Baseline and Current Status

This project is based on excellent reference projects adapted specifically for the M5Tough ESP32 platform:

- **[ESPHome Balboa Spa (Dakoriki)](https://github.com/Dakoriki/ESPHome-Balboa-Spa)** - Original ESPHome Balboa spa integration
- **[ESPHome Balboa Spa (brianfeucht)](https://github.com/brianfeucht/ESPHome-Balboa-Spa)** - Enhanced implementation with additional features
- **[ESPHome Balboa Spa (mhetzi)](https://github.com/mhetzi/esphome-balboa-spa)** - Most current and actively maintained version

### ✅ Currently Implemented
- ✅ **Real-time Spa Monitoring**: Temperature, jets, lights, heater, and filter status
- ✅ **Web Interface**: ESPHome web interface accessible from any device
- ✅ **RS485 Communication**: Direct communication with Balboa spa control systems via Grove Port A
- ✅ **ESPHome Integration**: Native ESPHome platform with optimized performance
- ✅ **MQTT Integration**: Full MQTT broker connectivity with Last Will Testament (LWT) messages
- ✅ **Home Automation Controls**: Control spa functions via MQTT commands
- ✅ **Status Monitoring**: Real-time status updates via MQTT topics
- ✅ **Stability**: Auto-restart configuration for improved device stability

### 📋 Todo List
- ⬜ **Touch Screen Display**: M5Tough TFT display output for local spa status and controls
- ⬜ **Enhanced UI**: Custom touch interface for the M5Tough display
- ⬜ **Home Assistant Discovery**: Auto-discovery integration (currently disabled for manual MQTT setup)

## 🔧 Hardware Requirements

- **M5Tough ESP32 Device**: ESP32-based development board with integrated TFT display and touch screen
- **RS485 Unit**: Connected to Grove Port A for spa communication
- **Balboa Spa System**: Compatible spa system with RS485 communication support

## ⚙️ Hardware Configuration

### M5Tough ESP32 Platform
- **Base**: ESP32 microcontroller with WiFi capability
- **Display**: 2.4" TFT LCD with touch screen (currently unused - on todo list)
- **Connectivity**: Grove ports for easy sensor/module connection

### RS485 Connection via Grove Port A
- **Grove Port A**: Used for RS485 Unit connection
- **TX Pin**: GPIO 32 (connected to RS485 Unit TX)
- **RX Pin**: GPIO 33 (connected to RS485 Unit RX)
- **RS485 Lines**: Connect A/B differential pair to your Balboa spa system

## 📡 Protocol Implementation

This project uses the ESPHome Balboa component for communication protocol handling:

- Status message parsing and control commands
- Temperature monitoring and thermostat control
- Pump, jet, and accessory status and control
- Connection monitoring and error handling
- Optimized UART communication to reduce CRC errors

## 📁 Project Structure

```
├── esphome-m5tough-balboa-spa.yaml    # Main ESPHome configuration
├── secrets.yaml                       # WiFi and sensitive configuration  
├── secrets_template.yaml              # Template for new installations
└── README.md                          # This documentation
```

## 🚀 Getting Started

### 📋 Prerequisites
- ESPHome installed (`pip install esphome`)
- M5Tough device with RS485 Unit on Grove Port A
- Access to Balboa spa RS485 communication lines

### 🔧 Initial Setup

1. **Configure Secrets**: Copy `secrets_template.yaml` to `secrets.yaml` and configure your WiFi settings
2. **Compile**: `esphome compile esphome-m5tough-balboa-spa.yaml`
3. **First Upload**: Connect M5Tough via USB and upload initial firmware
4. **OTA Updates**: After initial setup, use OTA for subsequent updates

## 🔨 Building and Uploading

### Using ESPHome

```bash
# Compile the configuration
esphome compile esphome-m5tough-balboa-spa.yaml

# Upload to M5Tough device via USB (first time)
esphome upload esphome-m5tough-balboa-spa.yaml

# Upload via OTA (after initial setup - replace with your device's IP)
esphome upload esphome-m5tough-balboa-spa.yaml --device 192.168.1.xxx

# Monitor logs
esphome logs esphome-m5tough-balboa-spa.yaml --device 192.168.1.xxx
```

## ⚙️ Configuration

The main configuration is in `esphome-m5tough-balboa-spa.yaml`. Key settings:

- **WiFi**: Configure in `secrets.yaml`
- **RS485**: Uses UART with TX=GPIO32, RX=GPIO33 (Grove Port A)
- **Display**: M5Tough TFT display (todo - not yet implemented)
- **Sensors**: Temperature sensors with ESPHome Balboa component
- **Climate**: Thermostat control for spa temperature
- **MQTT**: Full MQTT integration with configurable broker, authentication, and LWT messages

## 🌐 Current Functionality

### 🌐 Web Interface Access
Once uploaded, access the spa controls via:
1. **ESPHome Web Interface**: Navigate to your device's IP address in a browser
2. **MQTT Control**: Send commands via MQTT topics for automation
3. **Home Automation**: Integrate with any MQTT-compatible system

### 📡 MQTT Control Topics

The system uses MQTT for real-time control and monitoring:

#### 📤 Control Commands (Publish to these topics):
```bash
# Light Control
home/m5tough-balboa-spa/switch/spa_light/command
# Payloads: "ON" or "OFF"

# Jet 1 Control  
home/m5tough-balboa-spa/switch/spa_jet_1/command
# Payloads: "ON" or "OFF"

# Jet 2 Control
home/m5tough-balboa-spa/switch/spa_jet_2/command  
# Payloads: "ON" or "OFF"

# Temperature Control
home/m5tough-balboa-spa/climate/spa_thermostat/command
# Payloads: JSON format for temperature setting
```

#### 📊 Status Monitoring (Subscribe to these topics):
```bash
# Device Status (LWT)
home/m5tough-balboa-spa/LWT
# Payloads: "online" or "offline"

# Temperature Readings
home/m5tough-balboa-spa/sensor/spa_current_temperature/state
home/m5tough-balboa-spa/sensor/spa_target_temperature/state

# Switch States
home/m5tough-balboa-spa/switch/spa_light/state
home/m5tough-balboa-spa/switch/spa_jet_1/state
home/m5tough-balboa-spa/switch/spa_jet_2/state
```

### 🎛️ Available Controls
The system currently monitors and controls:
- **Temperature**: Current and target temperature readings via MQTT
- **Climate Control**: Heat mode (Off/Heat/Rest/Ready) via MQTT and web interface
- **Jets**: Jet 1 and Jet 2 on/off control via MQTT commands
- **Light**: Spa light on/off control via MQTT commands
- **Heater**: Heater operation status monitoring
- **Filter**: Filter pump operation status
- **Connection**: Real-time RS485 and MQTT connection status with LWT

## 📡 MQTT Configuration

### 🔌 Broker Setup
Configure your MQTT broker details in `secrets.yaml`:
```yaml
mqtt_broker: "your_mqtt_broker_ip"
mqtt_port: 1883
mqtt_username: "your_mqtt_username" 
mqtt_password: "your_mqtt_password"
```

### ✨ Features Implemented
- **Last Will Testament (LWT)**: Device reports "online"/"offline" status
- **Retained Messages**: Status persists on broker for new subscribers
- **Custom Topic Prefix**: `home/m5tough-balboa-spa/` for organized MQTT namespace
- **Quality of Service**: Reliable message delivery
- **Authentication**: Username/password authentication support

## 🚀 Future Enhancements (Todo)

### 📱 M5Tough Display Integration
- ⬜ Custom ESPHome display component for the M5Tough TFT screen
- ⬜ Touch screen interface for local spa control
- ⬜ Real-time status display on device
- ⬜ Temperature, jets, and light status visualization

### 📡 Enhanced MQTT Features
- ⬜ Home Assistant MQTT discovery (currently disabled for manual setup)
- ⬜ Additional sensor data publishing
- ⬜ MQTT-based configuration updates
- ⬜ Advanced automation triggers

## 🔧 Troubleshooting

### 🔌 RS485 Communication Issues
- **Check Physical Connections**: Ensure RS485 Unit is properly connected to Grove Port A
  - TX: GPIO 32
  - RX: GPIO 33  
  - A/B lines connected to spa system
- **Verify Baud Rate**: Confirm 115200 baud rate in ESPHome configuration
- **Check Polarity**: Ensure proper A/B line polarity (swap if no communication)
- **Monitor Logs**: Look for CRC errors or connection timeouts

### 🌐 Web Interface Issues
- **Network Connectivity**: Verify M5Tough has WiFi connection
- **IP Address**: Check device logs for assigned IP address
- **Firewall**: Ensure no firewall blocking ESPHome web interface
- **Browser Cache**: Clear cache if interface appears stale

### 📊 ESPHome Logs and Monitoring

Monitor device operation with:
```bash
esphome logs esphome-m5tough-balboa-spa.yaml --device 192.168.1.xxx
```

Watch for:
- RS485 connection status updates  
- Temperature reading success/failures
- CRC error messages
- Status change notifications
- WiFi connection status
- MQTT connection and authentication status
- LWT message publishing

### 📡 MQTT Troubleshooting

#### ❌ No MQTT Communication
- **Verify Broker**: Ensure MQTT broker is running and accessible
- **Check Credentials**: Verify username/password in `secrets.yaml`
- **Network Access**: Confirm device can reach broker IP/port
- **Topic Structure**: Verify topic paths match the documented format

#### 📊 Monitor MQTT Traffic
```bash
# Subscribe to all device topics
mosquitto_sub -h YOUR_BROKER_IP -u YOUR_USERNAME -P YOUR_PASSWORD -t "home/m5tough-balboa-spa/#"

# Monitor LWT status
mosquitto_sub -h YOUR_BROKER_IP -u YOUR_USERNAME -P YOUR_PASSWORD -t "home/m5tough-balboa-spa/LWT"
```

## 🔧 Technical Details

### 📍 GPIO Pin Assignment (M5Tough)
- **Grove Port A TX**: GPIO 32 (connected to RS485 Unit)
- **Grove Port A RX**: GPIO 33 (connected to RS485 Unit)
- **Display Interface**: Internal TFT connection (not yet utilized)
- **Touch Screen**: Internal touch controller (not yet utilized)

### ⚙️ ESPHome Configuration Highlights
- **Platform**: ESP32 with M5Tough board definition
- **UART Configuration**: Hardware serial for reliable RS485 communication
- **Balboa Component**: Official ESPHome Balboa integration
- **OTA Updates**: Over-the-air firmware updates enabled

## 🙏 Credits and References

This project builds upon excellent work from the ESPHome community:
- **[ESPHome Balboa Spa (Dakoriki)](https://github.com/Dakoriki/ESPHome-Balboa-Spa)**
- **[ESPHome Balboa Spa (brianfeucht)](https://github.com/brianfeucht/ESPHome-Balboa-Spa)** 
- **[ESPHome Balboa Spa (mhetzi)](https://github.com/mhetzi/esphome-balboa-spa)** 
- **Protocol Documentation**: ESPHome Balboa component documentation
- **Hardware Platform**: M5Stack M5Tough ESP32 development board
- **Framework**: ESPHome home automation platform

