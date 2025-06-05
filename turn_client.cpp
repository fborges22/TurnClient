#include "turn_client.hpp"
#include "TurnMsgLib.h"
#include <iostream>
#include <cstring>

bool establish_turn_relay(const std::string& turn_server, uint16_t port,
                          const std::string& username, const std::string& password,
                          const std::string& peer_ip, uint16_t peer_port) {
    turn_client_ctx_t* ctx = turn_client_ctx_create();
    if (!ctx) {
        std::cerr << "Failed to create TURN client context.\n";
        return false;
    }

    if (turn_client_set_server(ctx, turn_server.c_str(), port) != 0) {
        std::cerr << "Failed to set TURN server address.\n";
        turn_client_ctx_destroy(ctx);
        return false;
    }

    if (turn_client_set_credentials(ctx, username.c_str(), password.c_str()) != 0) {
        std::cerr << "Failed to set TURN credentials.\n";
        turn_client_ctx_destroy(ctx);
        return false;
    }

    if (turn_client_allocate(ctx) != 0) {
        std::cerr << "TURN allocation failed.\n";
        turn_client_ctx_destroy(ctx);
        return false;
    }

    if (turn_client_create_permission(ctx, peer_ip.c_str(), peer_port) != 0) {
        std::cerr << "Failed to create permission for peer.\n";
        turn_client_ctx_destroy(ctx);
        return false;
    }

    const char* message = "Hello from TURN client!";
    if (turn_client_send_data(ctx, peer_ip.c_str(), peer_port, message, std::strlen(message)) != 0) {
        std::cerr << "Failed to send data to peer.\n";
        turn_client_ctx_destroy(ctx);
        return false;
    }

    char buffer[1024];
    int received = turn_client_receive_data(ctx, buffer, sizeof(buffer));
    if (received > 0) {
        std::cout << "Received data from peer: " << std::string(buffer, received) << std::endl;
    } else {
        std::cerr << "Failed to receive data from peer.\n";
    }

    turn_client_ctx_destroy(ctx);
    return true;
}
