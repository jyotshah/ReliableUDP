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
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void recieveFile(SOCKET socket,sockaddr_in senderAddr){
    int senderAddrCount = sizeof(senderAddr);

    while(true){
        char fileName[256] = {0};
        int recievedbytes = recvfrom(socket, fileName, sizeof(fileName), 0, (sockaddr*)&senderAddr, &senderAddrCount);

        if(recievedBytes == SOCKET_ERROR){
            std::cerr << "ERROR RECEIVING FILE NAME.\n";
            break;
        }

        if(strcmp(fileName, "END")==0){
            std::cout << "ALL THE FILES HAVE BEN RECIEVED. \n";
            break;
        }

        std::cout << "RECEIVING FILE: " <<fileName << std::endl;

        int fileSize;
        recvfrom(socket, (char*)&fileSize, sizeof(fileSize),0 ,&senderAddr, &senderAddrCount);
        
        fileSize = abs(fileSize); 

        std::ofstream outputFile(fileName, std::ios::binary);
        if (!outputFile) {
            std::cerr << "ERROR CREATING FILE: " << fileName << std::endl;
            break;
        }

        char buffer[BUFFER_SIZE];
        int bytesReceived = 0;
        while (bytesReceived <= fileSize){

        }
    }
}

        int main(){
            WSADATA wsaData;
            if (WSAStartup(MAKEWORD(2,2), &wsaData)!= 0){
                std::cerr << "FAILED TO INITIALIZE SOCK. \n";
                WSACleanup();
                return 1;
            }

            SOCKET socketInfo = socket(AF_INET, SOCK_DGRAM, 0);
            if(!socketInfo){
                std::cerr <<"ERROR CREATING SOCKET."
                return 1;
            }

            std::cout << "WAITING FOR INCOMING FILES...\n";
            sockaddr_in senderAddress;
            receiveFile(socketInfo, senderAddress);

            closesocket(socketInfo);
            return 0;
        }
    }
}