#include <boost/asio.hpp>
#include <iostream>
#include "turn_client.hpp"

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " <STUN host> <TURN host> <TURN username> <TURN password> <peer IP:port>\n";
        return 1;
    }

    std::string stun_host = argv[1];
    std::string turn_host = argv[2];
    std::string turn_username = argv[3];
    std::string turn_password = argv[4];
    std::string peer = argv[5];

    auto colon_pos = peer.find(':');
    if (colon_pos == std::string::npos) {
        std::cerr << "Invalid peer address format. Use IP:port\n";
        return 1;
    }
    std::string peer_ip = peer.substr(0, colon_pos);
    uint16_t peer_port = static_cast<uint16_t>(std::stoi(peer.substr(colon_pos + 1)));

    boost::asio::io_context io_context;

    try {
        bool p2p_success = false;

        if (!p2p_success) {
            std::cout << "P2P connection failed. Falling back to TURN relay.\n";
            if (!establish_turn_relay(turn_host, 3478, turn_username, turn_password, peer_ip, peer_port)) {
                std::cerr << "TURN relay failed.\n";
                return 1;
            }
        } else {
            std::cout << "P2P connection established successfully.\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
