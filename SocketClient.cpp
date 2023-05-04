 #include<iostream>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define PORT 9909

using namespace std;

int main()
{
    int nRet = 0;
    WSADATA ws;
    SOCKET nClientSocket;
    struct sockaddr_in srv;

    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0)
    {
        cout << endl << "WSA Failed to initialize";
        return (EXIT_FAILURE);
    }
    else
    {
        cout << endl << "WSA initialized";
    }

    nClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (nClientSocket == INVALID_SOCKET)
    {
        cout << endl << " Socket call failed";
        WSACleanup();
        return (EXIT_FAILURE);
    }

    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    srv.sin_addr.s_addr = inet_addr("10.9.9.115");
    memset(&srv.sin_zero, 0, sizeof(srv.sin_zero));

    nRet = connect(nClientSocket, (struct sockaddr*)&srv, sizeof(srv));
    if (nRet < 0)
    {
        cout << endl << "connect failed";
        WSACleanup();
        return (EXIT_FAILURE);
    }
    
    else
    {
        cout << endl << "Connected to the server";
        char buff[255] = { 0 };
        int nRecv = recv(nClientSocket, buff, 255, 0);
        if (nRecv == SOCKET_ERROR)
        {
            cout << endl << "Error receiving data: " << WSAGetLastError();
        }
        else
        {
            cout << endl << "Just press any key to see the message received from the server";
            getchar();
            cout << endl << buff;
        }
    }

    closesocket(nClientSocket);
    WSACleanup();
    return 0;
}
