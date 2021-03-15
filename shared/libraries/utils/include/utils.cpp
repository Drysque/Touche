#include <Arduino.h>
#include "utils.hpp"
#include "DebugLog.hpp"

void utils::print_bin(const char *name, uint8_t n)
{
    char buff[9] = "00000000";

    for (int i = 0; i < 8; i++) {
        if (n & 1) {
            buff[7 - i] = '1';
        }
        n >>= 1;
    }
    Serial.print(name);
    Serial.print(" : ");
    Serial.println(buff);
}

void utils::print_packet(packet_t packet)
{
    static int index = 0;

    DEBUG_LOG_LN("===================================");
    DEBUG_LOG_VAL("Packet: ", index);

    DEBUG_LOG_VAL("Received: ", packet);
    utils::print_bin("As binary", packet);

    wsff_role_e player_role = (wsff_role_e)GET_ROLE(packet);
    payload_type_e payload = (payload_type_e)packet;

    DEBUG_LOG_VAL("Role: ", player_role == PLAYER_1 ? "PLAYER_1" : "PLAYER_2");
    utils::print_bin("Payload", payload);
    DEBUG_LOG_LN("===================================");

    index += 1;
}