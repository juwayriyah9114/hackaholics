# 🛡️ ShieldAI — TechFusion 2.0 Hackathon Progress

> **Team:** ShieldAI (PhishGuard v2.0) &nbsp;|&nbsp; **Event:** TechFusion 2.0 by Oculus Aegis &nbsp;|&nbsp; **Venue:** Dayananda Sagar Academy of Technology & Management, Bengaluru

---

## 📍 Overall Progress

Checkpoint 1 ██████████ ✅ Done<br>
Checkpoint 2 ██████████ ✅ Done<br>
Checkpoint 3 ██████████ ✅ Done<br>
Checkpoint 4 ██████████ ✅ Done<br>
Checkpoint 5 ██████████ ✅ Done<br>
Checkpoint 6 ██████████ ✅ Done<br>

**6 / 6 checkpoints complete 🎉**

---

## ✅ Checkpoint 1 — Initial Setup & Idea Validation
**🕒 03:00 PM · Day 1 (April 28)**

### What we built
- Flask backend initialized and running on `localhost:5000`
- Project folder structure set up (`app.py`, `analyzer/`, `arduino/`, `static/`, `templates/`)
- Groq API key configured in `.env` with `llama-3.3-70b` model selected
- Arduino Uno wired: Red LED (D8), Green LED (D9), Buzzer (D10), 16×2 LCD via I2C (A4/A5)
- `arduino/phishguard.ino` uploaded and tested — green LED confirms connection
- GitHub repository initialized with README and `.gitignore`

### Problem statement validated
> India recorded **1.5 million+ cybercrime complaints in 2023**. No real-time, accessible tool exists for non-technical users to detect phishing before acting on it.

### Status
| Item | Status |
|---|---|
| Flask server running | ✅ |
| Groq API connected | ✅ |
| Arduino wired & tested | ✅ |
| GitHub repo live | ✅ |

---

## ✅ Checkpoint 2 — Core Development Progress
**🕒 05:00 PM · Day 1 (April 28)**

### What we built
Four-layer threat detection pipeline fully operational:

| Layer | File | What it does |
|---|---|---|
| 🤖 AI Analysis | `analyzer/ai_classifier.py` | Groq LLM classifies threat type, severity, confidence score, red flags |
| 🌐 Domain Trust | `app.py` (heuristics) | Detects lookalike / fake domains via pattern matching |
| 🖥️ IP Tracing | `analyzer/ip_geolocate.py` | Calls `ip-api.com` to flag VPN/proxy/datacenter servers |
| 🔍 Context | `analyzer/header_parser.py` | Extracts sender IP from email headers; keyword analysis for urgency/bank patterns |

- Single scan UI live — paste URL / SMS / email body → result in under 2 seconds
- Arduino serial signal fires: **RED LED + Buzzer + LCD `PHISHING! THREAT DETECTED!`** on HIGH threat
- **GREEN LED** on safe content

### Status
| Item | Status |
|---|---|
| `ai_classifier.py` (Groq LLM) | ✅ |
| `ip_geolocate.py` (ip-api.com) | ✅ |
| `header_parser.py` | ✅ |
| Single scan UI | ✅ |
| Arduino alert on threat | ✅ |

---

## ✅ Checkpoint 3 — Feature Integration & Refinement
**🕒 09:00 PM · Day 1 (April 28)**

### What we built
- **Bulk Scanner** — scan up to 20 URLs/messages at once, each with individual threat badge + confidence score
- **QR Code Blocker** — live camera scanner (html5-qrcode) + upload QR image; decoded URL auto-piped into threat analyzer
- **India Map** — Folium + Leaflet.js plots attacker server origin on an interactive map (visual evidence for complaint)
- **Scan History sidebar** — all past scans stored in SQLite (`shieldai.db`), color-coded by threat level
- **Dark / Light mode toggle** — full UI theme switch
- **Live Stats Ticker** — Threats Today, Safe Scans, Total Scans, Avg Response Time, Detection Rate

### Status
| Item | Status |
|---|---|
| Bulk scanner (20 items) | ✅ |
| QR camera + upload scanner | ✅ |
| Folium India map | ✅ |
| SQLite scan log | ✅ |
| Dark / light mode | ✅ |
| Live stats ticker | ✅ |

---

## ✅ Checkpoint 4 — Mid-Progress Review
**🕒 11:00 PM · Day 1 (April 28)**

### What we built
- **Live Dashboard** — real-time KPI cards: Threats Blocked, Safe Scans, Total Scans, Avg Scan Time; full scan log table; CSV export
- **One-Click Police Complaint** — AI generates ready-to-submit FIR draft with IP, timestamp, message content, and threat classification; user data encrypted with **AES-256-GCM** before embedding; single click opens `cybercrime.gov.in` pre-filled
- **Arduino UI controls** — "Test Arduino LEDs" and "Reconnect Arduino" buttons in the frontend
- **Backend + Arduino status chips** in header showing live connection status
- **Clipboard paste shortcut** + `Ctrl+Enter` to scan

### Status
| Item | Status |
|---|---|
| Live dashboard with KPI cards | ✅ |
| CSV export | ✅ |
| Police complaint generator | ✅ |
| AES-256-GCM encryption | ✅ |
| One-click → cybercrime.gov.in | ✅ |
| Arduino reconnect UI | ✅ |

---

## ✅ Checkpoint 5 — Stability & Debugging
**🕒 06:00 AM · Day 2 (April 29)**

### What we completed
- [x] Wrapped all Groq API calls in `try/except` with retry on rate limit
- [x] Handled `ip-api.com` timeout gracefully (fallback message, no crash)
- [x] Tested Arduino disconnect → "Reconnect Arduino" button → serial re-established
- [x] Bulk scanner handles malformed/empty URLs without breaking
- [x] All 6 built-in test cases passing:
  - [x] Phishing URL → HIGH threat
  - [x] Scam SMS → HIGH threat
  - [x] Fake Email → HIGH threat
  - [x] Safe Email → SAFE
  - [x] UPI Scam → HIGH threat
  - [x] Real Bank SMS → SAFE
- [x] End-to-end scan time confirmed under 2 seconds
- [x] QR decode error handled gracefully

### Status
| Item | Status |
|---|---|
| Error handling & retries | ✅ |
| Arduino reconnect test | ✅ |
| All 6 test cases passing | ✅ |
| Sub-2-second scan verified | ✅ |

---

## ✅ Checkpoint 6 — Pre-Final Build Stage
**🕒 09:00 AM · Day 2 (April 29)**

### What we completed
- [x] All code committed and pushed to GitHub
- [x] `assets/demo.jpeg` and `assets/SHIELD AI QR.png` present in repo
- [x] README live demo link updated with current ngrok URL
- [x] `requirements.txt` tested from a clean environment
- [x] `.env.example` present (no real keys committed)
- [x] `arduino/phishguard.ino` present and uploadable
- [x] ngrok tunnel running with browser-warning bypass
- [x] 60-second demo rehearsed:
  1. Open app → paste phishing URL
  2. Arduino fires RED LED + buzzer + LCD
  3. India map shows attacker server origin
  4. Generate Police Complaint → opens cybercrime.gov.in
- [x] No debug logs or test keys in final commit

### Status
| Item | Status |
|---|---|
| Final GitHub push | ✅ |
| README polished | ✅ |
| ngrok tunnel live | ✅ |
| Demo rehearsed | ✅ |

---

## 🚀 Tech Stack Summary

| Layer | Technology |
|---|---|
| Backend | Python (Flask) |
| AI Analysis | Groq LLM — `llama-3.3-70b` |
| IP Geolocation | ip-api.com |
| Database | SQLite |
| Map | Folium + Leaflet.js |
| Hardware | Arduino Uno · 16×2 LCD (I2C) · Red/Green LEDs · Buzzer |
| Serial | PySerial |
| Frontend | HTML / CSS / JS |
| QR Scanning | html5-qrcode |
| Encryption | AES-256-GCM |

---

## 🔌 Hardware Wiring

| Component | Arduino Pin |
|---|---|
| LCD SDA | A4 |
| LCD SCL | A5 |
| Red LED | D8 |
| Green LED | D9 |
| Buzzer | D10 |

---

> Built with ❤️ to make India's internet safer — **ShieldAI / PhishGuard v2.0**
