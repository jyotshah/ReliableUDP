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
#include <openssl/md5.h>

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
    string expectedMD5;

    while (receiving){
        unsigned char packet[PacketSize];
        int bytesRead = connection.ReceivePacket(packet, sizeof(packet));
        if (bytesRead > 0){

        } else{

        }
    }

}