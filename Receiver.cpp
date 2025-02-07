/*
Students Name : Ashwini Gunaga and Jyot Shah
Students Number : 8888180 and 8871717
Assignment : Assignment-01
Date : 02/05/2025
File : Receiver.cpp
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include<string>
#include <openssl/md5.h>

using namespace std;
using namespace net;

const int ServerPort = 30000;
const int ProtocolId = 0x11223344;


        char buffer[BUFFER_SIZE];
        int bytesReceived = 0;
        while (bytesReceived <= fileSize){
            int chunkSize = recvfrom(socket, buffer, BUFFER_SIZE, 0, (sockaddr*)&senderAddr, &senderAddrCount);
            if (chunkSize == SOCKET_ERROR) 
            break;
            outputFile.write(buffer, chunkSize);
            bytesReceived += chunkSize;

            float progress = (float)bytesReceived / fileSize * 100;
            std::cout << "TRANSFER PROGRESS: " << progress << "%\r";
            std::cout.flush();
        }

int main(){
    ReliableConnection connection(0x11223344, 10.0f);
    if (!connection.Start(ServerPort)) {
        cout << "FAILED TO START SERVER " << ServerPort << "\n";
        return 1;
    }
    cout << "WAITING FOR FILE TRANSFER...\n";
    vector<unsigned char> receivedData;
    
    bool receiving = true;
    string expectedMD5;

    while (receiving){
        unsigned char packet[PacketSize];
        int bytesRead = connection.ReceivePacket(packet, sizeof(packet));
        if (bytesRead > 0){

        } else{

        }
    }

}