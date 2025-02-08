/*
Students Name : Ashwini Gunaga and Jyot Shah
Students Number : 8888180 and 8871717
Assignment : Assignment-01
Date : 02/05/2025
File : Sender.cpp
*/
#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include "Net.h"

const int ServerPort = 30000;
const int ProtocolId = 0x11223344;
const int PacketSize = 1024;


void transferFile(connection) {
    std::ifstream f(file, std::ios::binary | std::ios::ate);
    if (!f) {
        std::cerr << "Error opening file: " << file << std::endl;
        return;
    }

    int fs = f.tellg();
    f.seekg(0, std::ios::beg);

    char fn[256] = { 0 };
    strncpy(fn, file, sizeof(fn) - 1);

    char buf[SIZE];

    while (!f.eof())
    {
        f.read(buf, SIZE);
        connection.SendPacket((const unsigned char*)buf, sizeof(buf));
    }

    f.close();
    std::cout << "\nFile sent: " << file << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <IP> <File1> <File2> ..." << std::endl;
        return 1;
    }
    if (!InitializeSockets())
    {
        printf("failed to initialize sockets\n");
        return 1;
    }
    ReliableConnection connection(ProtocolId, TimeOut);

    for (int i = 2; i < argc; i++) {
        transferFile(connection);
    }
}