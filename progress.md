# 🛡️ ShieldAI (PhishGuard v2.0) — Smart Threat Detection & Reporting System
> From threat detection to legal complaint in under 60 seconds.

![Platform](https://img.shields.io/badge/Platform-Web%20%7C%20Arduino-blue) ![License](https://img.shields.io/badge/License-MIT-green)

---

## 📸 Hardware Demo

<p align="center">
  <img src="assets/demo.jpeg" width="600" alt="PhishGuard Arduino Alert System — LCD displaying PHISHING! THREAT DETECTED!" />
  <br/>
  <em>Live demo: Arduino Uno + 16×2 LCD + Red/Green LEDs triggering a physical phishing alert in real time</em>
</p>
## LOQIN THROUTH QR
<p align="center">
  <img src="assets/SHEILD AI QR.png" width="200" alt="ShieldAI QR Code — Scan to open the live demo" />
  <br/>
  <em>📱 Scan to try the live demo instantly → <a href="https://quail-unglazed-mutt.ngrok-free.dev">quail-unglazed-mutt.ngrok-free.dev</a></em>
</p>

## 🚀 Live Demo
🌐 Try the hosted version:

**https://quail-unglazed-mutt.ngrok-free.dev**

---

## 🚨 Problem Statement

### Background

India recorded over **1.5 million cybercrime complaints in 2023**, with financial fraud, phishing, and UPI scams being the most prevalent. A significant portion of victims — particularly first-time smartphone users and senior citizens — fall prey to scams delivered through SMS, WhatsApp, email, and malicious QR codes. The primary reason is a lack of accessible, real-time tools that can analyze suspicious content *before* the user acts on it.

Existing solutions are either too technical (requiring cybersecurity knowledge), too slow (waiting for reports to be filed after the damage is done), or not accessible offline. There is no widely available tool that combines AI-driven content analysis with a tangible, physical alert system suited for non-technical users.

---

### The Core Problem

> **How can we build a real-time, multi-layer scam and phishing detection system that is fast enough, simple enough, and physically intuitive enough for everyday Indian users — including those with low digital literacy — to use before engaging with suspicious digital content?**

Specifically, the system must address the following challenges:

| # | Challenge | Impact |
|---|---|---|
| 1 | **Inability to distinguish safe vs malicious content** | Users have no reliable way to assess whether a message or QR code is safe before interacting |
| 2 | **Delayed reporting pipeline** | By the time most victims report to cybercrime.gov.in or call 1930, financial loss has already occurred |
| 3 | **Lack of physical/sensory feedback** | Digital alerts are easy to miss — no low-cost solution provides a physical alert tied to AI analysis |
| 4 | **No unified scanning interface** | Users must switch between multiple tools for URLs, email headers, and QR codes |
| 5 | **Post-detection action gap** | Even when users suspect a scam, there is no streamlined path from detection to formal complaint filing |

---

## ✅ Our Solution

ShieldAI addresses these challenges through a **four-layer detection pipeline**:

| Layer | Technology | Purpose |
|---|---|---|
| 🤖 AI Analysis | Groq LLM (llama-3.3-70b) | Classifies threat type, severity, and indicators |
| 🌐 Domain Trust | Pattern matching + heuristics | Detects lookalike / fake domains |
| 🖥️ Server IP Tracing | ip-api.com | Flags VPN/proxy and datacenter-hosted scam servers |
| 🔍 Context Awareness | Keyword analysis | Identifies financial keywords, urgency patterns, bank impersonation |

Physical feedback is delivered via an **Arduino Uno** connected over USB serial, driving a **green LED** (safe), **red LED + buzzer** (danger), and a **16×2 I2C LCD** — providing immediate, screen-independent alerts independent of the user's digital attention.

```
📧 Suspicious Message / URL / QR Code / Screenshot
        ↓
🔍 Four-Layer AI Analysis (LLM + Domain + IP + Context)
        ↓
🚨 Physical Alert (Arduino: RED LED + Buzzer + LCD)
        ↓
🗺️  Server IP Traced → Geolocation Mapped
        ↓
📝 Auto-Generated Cybercrime Complaint (AES-256-GCM encrypted data)
        ↓
🌐 One-Click → cybercrime.gov.in (pre-filled)
```

### 🎯 Objectives

1. Detect phishing links, SMS scams, fake bank alerts, investment fraud, and malicious QR codes with **>95% accuracy** using LLM-based analysis
2. Deliver scan results in **under 2 seconds** end-to-end, including hardware feedback
3. Provide physical LED + buzzer + LCD alerts via Arduino for HIGH and LOW threat levels
4. Enable **one-click formal complaint generation** and submission pathway to cybercrime.gov.in
5. Support **bulk scanning of up to 20 items** simultaneously for repeated/batch threats
6. Store scan logs in a **local SQLite database** for dashboard analytics and CSV export

### 👥 Target Users

- General public receiving suspicious SMS / WhatsApp messages
- Elderly or low-digital-literacy users who need physical / visual alerts
- Small business owners verifying payment QR codes
- Students and developers building cybersecurity awareness tooling

---

## ⚙️ Features

### ⚡ Single Scan
- Paste any URL, email body, SMS, or WhatsApp message
- AI **auto-detects** the content type (URL / Email / SMS / WhatsApp)
- Returns threat level, confidence score, red flags, and recommended action
- Live **Threat Meter** in sidebar updates in real time

### 📋 Bulk Scanner *(New in v2.0)*
- Scan up to **20 URLs or messages at once** — one per line
- Each item is individually classified with a threat level badge and score
- Ideal for security teams reviewing multiple suspicious messages

### 📷 QR Code Blocker *(New in v2.0)*
- **Live camera scanner** detects and decodes QR codes in real time
- **Upload QR image** from your device for offline-style checking
- Before you open anything, ShieldAI checks where the QR leads
- Automatically pipes the decoded URL into the threat analyzer

### 📊 Live Dashboard *(New in v2.0)*
- Real-time KPI cards: Threats Blocked, Safe Scans, Total Scans, Avg Scan Time
- Full scan log table with Type, Level, Score, and Summary columns
- **Export CSV** of all scan history with one click
- Refresh button for live updates

### 🔬 Threat Analysis
- Parses raw email headers to extract sender IP addresses
- Identifies phishing patterns across Email, SMS, and WhatsApp messages
- Uses AI to classify threats and estimate attack origin
- Built-in test examples: Phishing URL, Scam SMS, Fake Email, Safe Email, UPI Scam, Real Bank SMS

### 🗺️ IP Geolocation & Mapping
- Geolocates the sender's server in real time
- Plots the origin on an interactive India map — visual evidence you can attach to your complaint

### 🔴 Physical Hardware Alert (Arduino)
- The moment a threat is detected, the system sends a serial signal to an Arduino Uno
- Red LED flashes + buzzer sounds + 16×2 LCD displays `PHISHING! THREAT DETECTED!`
- **Test Arduino LEDs** and **Reconnect Arduino** buttons available directly from the UI
- No way to miss it — even if your screen is minimized

### 📝 One-Click Police Complaint
- Hit **"Generate Police Complaint"** and the AI writes a ready-to-submit FIR draft — complete with IP, timestamp, message content, and threat classification
- User data is encrypted with **AES-256-GCM** before being embedded in the complaint
- A single click opens cybercrime.gov.in with the complaint pre-filled
- Reduces reporting time from hours → seconds

### 🌙 Additional UI Features *(New in v2.0)*
- **Live Stats Ticker** — Threats Today, Safe Scans, Total Scans, Avg Response Time, Detection Rate
- **Scan History** sidebar — browse all past scans with threat level color coding
- **Light / Dark mode** toggle
- **Backend + Arduino status chips** in header show live connection status
- **Clipboard paste** shortcut + Ctrl+Enter to scan

---

## 🧰 Tech Stack

| Layer | Technology |
|---|---|
| Backend | Python (Flask) |
| AI Analysis | Groq LLM (llama-3.3-70b) |
| IP Geolocation | ip-api.com |
| Database | SQLite (scan logs) |
| Map Visualization | Folium + Leaflet.js |
| Hardware | Arduino Uno, 16×2 LCD (I2C), LEDs, Buzzer |
| Serial Communication | PySerial |
| Frontend | HTML / CSS / JS |
| QR Scanning | html5-qrcode library |

---

## 🔌 Hardware Setup

**Components:**
- Arduino Uno
- 16×2 LCD Display (I2C)
- Red LED + Green LED
- Buzzer
- Breadboard + jumper wires

**Wiring:**

| Component | Arduino Pin |
|---|---|
| LCD SDA | A4 |
| LCD SCL | A5 |
| Red LED | D8 |
| Green LED | D9 |
| Buzzer | D10 |

> Upload `arduino/phishguard.ino` to your board before running the Python backend.

---

## 🚀 Getting Started

### 1. Clone the repo
```bash
git clone https://github.com/yourusername/phishguard.git
cd phishguard
```

### 2. Install dependencies
```bash
pip install -r requirements.txt
```

### 3. Configure
```bash
cp .env.example .env
# Add your API keys: GROQ_API_KEY, IPAPI_KEY
```

### 4. Flash the Arduino
Open `arduino/phishguard.ino` in the Arduino IDE and upload to your board.

### 5. Run the app
```bash
python app.py
```
Visit `http://localhost:5000` in your browser.

> **Tip:** To bypass the ngrok browser confirmation wall for public demos, run:
> ```bash
> ngrok http 5000 --request-header-add "ngrok-skip-browser-warning: true"
> ```

---

## 📁 Project Structure

```
phishguard/
├── app.py                  # Flask backend
├── analyzer/
│   ├── header_parser.py    # Email header extraction
│   ├── ip_geolocate.py     # IP → lat/lng lookup
│   └── ai_classifier.py   # Groq LLM threat classification
├── arduino/
│   └── phishguard.ino      # Arduino sketch
├── static/
│   ├── script.js           # Frontend logic (scan, bulk, QR, dashboard)
│   └── map/                # India map output (Folium)
├── templates/
│   └── index.html          # Frontend UI (ShieldAI v2.0)
├── assets/
│   └── demo.jpeg           # Hardware demo photo
├── shieldai.db             # SQLite scan log database
└── requirements.txt
```

---

## 📏 Scope

**In scope:** Text / URL / email / SMS scanning, QR code scanning (camera + upload), screenshot analysis, Arduino hardware integration (LEDs, buzzer, LCD), cybercrime report generation, scan history dashboard, bulk scanning, dark/light theme UI.

**Out of scope:** Real-time network packet inspection, mobile app (Android/iOS native), cloud deployment and multi-user accounts, browser extension integration.

---

## 🇮🇳 Why This Matters

India recorded over **1.5 million cybercrime complaints in 2023** alone. Most victims never file a report — not because they don't want to, but because the process is overwhelming. ShieldAI collapses the entire response pipeline into a single interface, making it accessible to anyone, regardless of technical background.

---

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you'd like to change.

---

## 📄 License

MIT License — see [LICENSE](LICENSE) for details.

---

> Built with ❤️ to make India's internet safer.
