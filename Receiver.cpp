/*
Students Name : Ashwini Gunaga and Jyot Shah
Students Number : 8888180 and 8871717
Assignment : Assignment-01
Date : 02/05/2025
File : Receiver.cpp
*/
#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include "Net.h"

using namespace std;
using namespace net;

const int ServerPort = 30000;
const int ProtocolId = 0x11223344;
const int PacketSize = 1024;


int main(){
    ReliableConnection connection(0x11223344, 10.0f);
    if (!connection.Start(ServerPort)) {
        cout << "FAILED TO START SERVER " << ServerPort << "\n";
        return 1;
    }
    cout << "WAITING FOR FILE TRANSFER...\n";
    vector<unsigned char> receivedData;

    bool receiving = true;

    while (receiving){
        unsigned char packet[PacketSize];
        int bytesRead = connection.ReceivePacket(packet, sizeof(packet));
        if (bytesRead > 0){
            string packetStr(reinterpret_cast<char*>(packet), bytesRead);
            if (packetStr.rfind("EOF:",0) == 0) { 
                receiving == false; 
            }
            else{
                receivedData.insert(receivedData.end(), packet, packet + bytesRead);
            }
        } 
    }
            ofstream outFile("received_file", ios::binary);
            outFile.write(reinterpret_cast<const char*>(&receivedData[0]), receivedData.size());
            printf("File received successfully! Saved as 'received_file'.\n");


}