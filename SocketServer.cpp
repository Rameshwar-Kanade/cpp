 #include<iostream>
#include<winsock.h>

#pragma comment(lib, "ws2_32.lib")
#define PORT 9909
using namespace std;
struct sockaddr_in srv;
fd_set fr,fw,fe;
 int nMaxFD;


int main()
{
    //Initialize the WSA Variables
    int nRet=0;
    WSADATA ws;
    if(WSAStartup (MAKEWORD(2,2),&ws)<0)
    {
         cout << endl <<"WSA Failed to initialize";
    }
    else
    {
        cout << endl <<"WSA initialized";
    }  

    //Initialize the Socket
    int nSocket= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (nSocket<0)
    {
         cout << endl <<"The Socket not opened";
    }
    else
    {
        cout << endl <<"The Socket opened Successufully" << nSocket;
    } 

    // Initialize  the enviorment for sockaddr structure
    srv.sin_family=AF_INET;
    srv.sin_port=htons(PORT);
    srv.sin_addr.s_addr=INADDR_ANY;

    // Bind the socket to the local port
    nRet=bind(nSocket,(sockaddr*)&srv,sizeof(sockaddr));
    if (nRet<0)
    {
        cout << endl <<"Fail to bind to local port";  
    }
    else
    {
         cout << endl <<"Successfully bind to local port";
    }

    // listen the request from client queues the request

    nRet=listen(nSocket,5);
    if (nRet < 0)
    {
         cout << endl <<"Fail to start listen  to local port";
    }
    else
    {
        cout << endl <<" started listen  to local port";
    }
    
    nMaxFD=nSocket;
    struct timeval tv;
    tv.tv_sec=1;
    tv.tv_usec=0;

    FD_ZERO(&fr);
    FD_ZERO(&fe);
    FD_ZERO(&fw);

    FD_SET (nSocket,&fr);
    FD_SET (nSocket,&fe);

    cout << endl << "Before  the select  call : " << fr.fd_count;

    // keep waiting for new request and processed as per the request
    nRet=select(nMaxFD +1 , &fr, &fw, &fe, &tv);
    if ( nRet > 0)
    {
        // when someone connects or communicates with a message over a dedicated connection 
    }
    else if (nRet==0)
    {
        //No connection or any comminication request made or you can say that none of the socket descriptors are ready
        cout << endl << "Nohthing on port: "<< PORT;
    }
    else
    {
       cout << endl << "I failed...";
    }
    cout << endl << "After  the select  call : " << fr.fd_count;
}
  
    



