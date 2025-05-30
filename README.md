# 🔌 Arduino-Based Digital Ohmmeter

## 📘 Introduction

Measuring resistor values manually using color codes can be inaccurate or time-consuming. This project demonstrates how to build a **Digital Ohmmeter using an Arduino Uno** that calculates an unknown resistor's value using the **Voltage Divider Principle**, then displays the result on a **16x2 LCD**.

---

## 🖼️ Circuit View

![Circuit View](<Circuit View.png>)

## 🧩 Schematic View

![Schematic View](<Schemattic view.png>)

---

## 🧰 Components Required

* Arduino UNO
* Breadboard
* 16x2 LCD Display
* 10k Potentiometer (for LCD contrast)
* 470Ω Resistor (reference resistor – R2)
* Jumper Wires
* Unknown resistor to test

---

## 🛠️ Circuit Connections

Connect the LCD display to the Arduino Uno as shown below:

| LCD Pin | Description        | Arduino Pin       |
| ------- | ------------------ | ----------------- |
| 1       | GND                | GND               |
| 2       | VCC (+5V)          | 5V                |
| 3       | Contrast (via POT) | Middle pin of POT |
| 4       | RS                 | D12               |
| 5       | RW                 | GND               |
| 6       | EN                 | D11               |
| 11      | D4 (Data)          | D5                |
| 12      | D5 (Data)          | D4                |
| 13      | D6 (Data)          | D3                |
| 14      | D7 (Data)          | D2                |
| 15      | LED+ (Backlight)   | 5V                |
| 16      | LED− (Backlight)   | GND               |
| 7–10    | Not used           | —                 |

The unknown resistor (R1) and reference resistor (R2 = 470Ω) are connected in series between **5V** and **GND**, with the midpoint connected to **analog pin A0**.

---

## 🔧 How It Works

The project uses a voltage divider circuit to calculate the resistance:

### 🔣 Formula

```
Vout = Vin * R2 / (R1 + R2)
=> R1 = R2 * ((Vin / Vout) - 1)
```

Where:

* **Vin** = 5V (Arduino supply)
* **Vout** = Analog voltage read at A0
* **R2** = 470Ω (known resistor)
* **R1** = Unknown resistor

The Arduino reads the analog voltage using `analogRead()` and computes `R1` based on the above formula.

---

## 📟 Code Summary

The Arduino sketch:

* Reads the voltage from A0
* Applies the resistance calculation
* Displays the result on the LCD, updating every second

---

## ✅ Results & Conclusion

* Effectively measures resistances between **100Ω to 2kΩ**
* For larger resistor values, increase R2 proportionally
* Ideal for quick prototyping and learning resistor behavior

---

## 👨‍💻 Author

**Tushar Chaudhari**
*Electronics Enthusiast & Maker*

---
