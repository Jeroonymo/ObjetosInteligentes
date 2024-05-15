# ObjetosInteligentes
Sistema de Monitoramento de Som em UTIN com IoT

Este repositório contém o código-fonte e a documentação para um sistema de monitoramento de som em tempo real para Unidades de Terapia Intensiva Neonatal (UTINs), utilizando a plataforma Arduino e o protocolo MQTT para comunicação via internet.
Descrição do Projeto

Ruídos excessivos em UTINs podem ser prejudiciais para recém-nascidos, especialmente prematuros. Este projeto visa criar um sistema que monitore continuamente os níveis de som na UTIN, alerte a equipe em caso de ruídos excessivos e forneça dados para análise posterior.

O sistema utiliza um sensor de som para detectar os níveis de ruído e um Arduino Mega para processar os dados e acionar um atuador, além de enviar informações para um broker MQTT via NodeMCU.
Hardware

    Arduino Mega 2560: Unidade central de processamento do sistema.

    NodeMCU (ESP8266): Módulo Wi-Fi para comunicação com a internet.

    Sensor de Som KY-037: Detecta os níveis de ruído no ambiente.

    Display LCD (LCM 2004A): Exibe os níveis de som em tempo real.


Software

    Arduino IDE: Ambiente de desenvolvimento para programar o Arduino Mega.

    Bibliotecas Arduino:

        Wire.h: Para comunicação I2C com o LCD.

        LiquidCrystal_I2C_Hangul.h: Para controlar o display LCD.

    Bibliotecas NodeMCU:

        ESP8266WiFi.h: Para conectar à rede Wi-Fi.

        PubSubClient.h: Para comunicação MQTT.

    Broker MQTT: Mosquitto ou similar (o endereço IP do broker deve ser configurado no código NodeMCU).

Funcionamento

    Detecção de Som: O sensor de som KY-037 detecta os níveis de ruído e envia os dados analógicos para o Arduino Mega.

    Processamento de Dados: O Arduino converte os dados analógicos em decibéis (dB) e os exibe no display LCD.

    Comunicação MQTT: O Arduino envia os dados de dB para o NodeMCU via comunicação serial. O NodeMCU conecta-se ao broker MQTT via Wi-Fi e publica os dados em um tópico específico.

    Monitoramento Remoto: Dispositivos autorizados podem se inscrever no tópico MQTT para receber os dados em tempo real e visualizar o histórico de ruídos.

Instalação e Uso

    Faça o download ou clone este repositório.

    Carregue o código do Arduino para o Arduino Mega usando a IDE Arduino.

    Carregue o código NodeMCU para o NodeMCU usando a IDE Arduino.

    Configure o endereço IP do broker MQTT no código NodeMCU.

    Conecte os componentes de hardware como indicado no diagrama de circuito (incluído na documentação).

    Alimente o circuito e monitore os níveis de som através do display LCD e do broker MQTT.

Documentação

	https://docs.google.com/document/d/1BSSTDmLdkh6CYmA6E1SU4fqSJ8X6cbMa/edit

Próximos Passos

    Integrar diferentes tipos de atuadores para alertas mais eficazes (ex: mensagens SMS).

    Melhorar a interface gráfica do Node-RED para visualização e análise dos dados coletados pelo sistema.