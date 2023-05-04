 #include<iostream>
#include<winsock.h>

#pragma comment(lib, "ws2_32.lib")
#define PORT 9909
using namespace std;
struct sockaddr_in srv;

int main()
{
    int nRet=0;

    WSADATA ws;
     if (WSAStartup(MAKEWORD(2, 2), &ws) != 0)
    {
        cout << endl << "WSA Failed to initialize";
        return (EXIT_FAILURE);
    }
    else
    {
        cout << endl << "WSA initialized";
        
    }

    int nSocket= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    srv.sin_family=AF_INET;
    srv.sin_port=htons(PORT);
    srv.sin_addr.s_addr=INADDR_ANY;



    int nOptVal=0;
    int nOptLen=sizeof(nOptVal);
    nRet=setsockopt(nSocket,SOL_SOCKET,SO_REUSEADDR,(const char*) &nOptVal,nOptLen);
    if (!nRet)
    {
         cout << endl << "The setsockopt call successfull";
    }
    else
    {
        cout << endl << "The setsockopt call failed";
    }


      nRet=bind(nSocket,(sockaddr*)&srv,sizeof(sockaddr));
    if (nRet<0)
    {
        cout << endl <<"Fail to bind to local port";  
    }
    else
    {
         cout << endl <<"Successfully bind to local port";
    }

     

     nRet=listen(nSocket,5);
    if (nRet < 0)
    {
         cout << endl <<"Fail to start listen  to local port";
    }
    else
    {
        cout << endl <<" started listen  to local port";
    }



    char strHostName[32]={0,};
    nRet =gethostname(strHostName,32);
    if (nRet < 0)
    {
        cout << endl << "Call failed";
    }
    else
    {
        cout << endl << "The name of they Host   " << strHostName;
    }
}