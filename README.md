# TURN P2P Client

This project demonstrates a peer-to-peer UDP communication system that uses STUN for NAT traversal and falls back to TURN relaying if direct peer-to-peer (P2P) communication is not possible.

## Features

- 🔍 STUN support for public IP/port discovery
- 🔁 TURN relay fallback using CoTURN's `libturnclient`
- ⚙️ CMake-based build system
- 🧱 Integrates with system-installed `libturnclient` via a custom CMake module

## Requirements

- C++17 compatible compiler
- Boost.Asio (Boost system component)
- CoTURN with `libturnclient` installed on your system
- CMake ≥ 3.10

## Building

```bash
mkdir build
cd build
cmake ..
make
```

If your system cannot find `libturnclient`, ensure headers and libraries are accessible and try:

```bash
cmake -DTURNCLIENT_INCLUDE_DIR=/path/to/headers -DTURNCLIENT_LIBRARY=/path/to/libturnclient.so ..
```

## Usage

```bash
./turn_p2p_client <STUN host> <TURN host> <TURN username> <TURN password> <peer IP:port>
```

Example:

```bash
./turn_p2p_client stun.l.google.com turn.example.com user pass 203.0.113.5:9000
```

## Project Structure

```
turn_p2p_client/
├── CMakeLists.txt
├── main.cpp
├── turn_client.cpp
├── turn_client.hpp
└── cmake/
    └── FindTURNClient.cmake
```

## License

This project is provided for educational and prototype purposes. Integrate responsibly and refer to [RFC 5766](https://datatracker.ietf.org/doc/html/rfc5766) for TURN protocol compliance.
