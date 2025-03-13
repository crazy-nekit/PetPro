
#### **📝 Русский вариант**
# **Проект: Управление реле через Bluetooth HC-06 на STM32F103C8T6**  
Этот проект реализует **управление реле** через **Bluetooth-модуль HC-06** с использованием **STM32F103C8T6**.  
Прием команд осуществляется по **UART** в **прерываниях**, а обработка команд выполняется в отдельном файле логики (`logic.c`).  

## **🔹 Функционал**  
✅ Прием команд `"on"` и `"off"` через Bluetooth HC-06.  
✅ Управление **реле**, подключенным к **PB9**.  
✅ Когда реле **включается**, загорается **светодиод на PB1**.  
✅ Использование **прерываний UART** для непрерывного приема данных.  

## **🔹 Подключение**  
- **STM32F103C8T6**  
- **HC-06 (Bluetooth)**  
  - TX → **PA10 (USART1_RX)**  
  - RX → **PA9 (USART1_TX)**  
- **Реле** → **PB9**  
- **Светодиод (индикатор реле)** → **PB1**  

## **🔹 Как использовать**  
1️⃣ Загрузить прошивку в STM32.  
2️⃣ Подключиться к HC-06 через **Bluetooth-терминал** (например, Serial Bluetooth Terminal).  
3️⃣ Отправить команду:  
   - `"on"` → **реле включается**, светодиод **загорается**.  
   - `"off"` → **реле выключается**, светодиод **гаснет**.  

🚀 **Готово! Теперь можно управлять реле удаленно через Bluetooth!**  

---

#### **📝 English version**
# **Project: Relay Control via Bluetooth HC-06 on STM32F103C8T6**  
This project implements **relay control** using **Bluetooth module HC-06** with **STM32F103C8T6**.  
Commands are received via **UART** using **interrupts**, and processing is done in a separate logic file (`logic.c`).  

## **🔹 Features**  
✅ Receive `"on"` and `"off"` commands via Bluetooth HC-06.  
✅ Control **relay** connected to **PB9**.  
✅ When the relay **turns on**, an **LED on PB1** lights up.  
✅ Use **UART interrupts** for continuous data reception.  

## **🔹 Wiring**  
- **STM32F103C8T6**  
- **HC-06 (Bluetooth)**  
  - TX → **PA10 (USART1_RX)**  
  - RX → **PA9 (USART1_TX)**  
- **Relay** → **PB9**  
- **LED (Relay Indicator)** → **PB1**  

## **🔹 How to Use**  
1️⃣ Flash the firmware to STM32.  
2️⃣ Connect to HC-06 using **Bluetooth terminal** (e.g., Serial Bluetooth Terminal).  
3️⃣ Send a command:  
   - `"on"` → **Relay turns ON**, LED **lights up**.  
   - `"off"` → **Relay turns OFF**, LED **turns off**.  

🚀 **Done! Now you can control the relay remotely via Bluetooth!**  
