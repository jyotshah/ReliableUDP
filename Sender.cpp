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
}