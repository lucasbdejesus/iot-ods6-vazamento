# iot-ods6-vazamento
Sistema IoT para detecção de vazamentos com MQTT.

Este projeto utiliza sensores e atuadores com Arduino e protocolo MQTT para detectar vazamentos de água e enviar alertas locais e remotos.

## 🚀 Funcionalidades
- Detecção de vazamento com sensor YL-83
- Alerta sonoro com buzzer
- Envio de mensagem via MQTT usando módulo ESP8266
- Simulação no Wokwi

## 💻 Como usar
1. Clone este repositório
2. Abra o código na IDE do Arduino
3. Configure o Wi-Fi e broker MQTT no código
4. Carregue para o Arduino e execute

## 🧰 Componentes
- Arduino Uno
- ESP8266 (ESP-01)
- Sensor YL-83
- Buzzer
- Fios, protoboard

## 🌐 Comunicação
- Protocolo: MQTT
- Broker: HiveMQ (broker público gratuito)
- Tópico: `vazamentos/agua`
