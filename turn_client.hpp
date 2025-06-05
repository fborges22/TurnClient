#pragma once
#include <string>

bool establish_turn_relay(const std::string& turn_server, uint16_t port,
                          const std::string& username, const std::string& password,
                          const std::string& peer_ip, uint16_t peer_port);
