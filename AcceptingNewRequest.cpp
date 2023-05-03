 #include<iostream>
#include<winsock.h>

#pragma comment(lib, "ws2_32.lib")
#define PORT 9909
using namespace std;
struct sockaddr_in srv;
fd_set fr,fw,fe;

int nSocket;
int nMaxFD;

int nArrClient[5]; // hardcoded values

void ProcessTheNewRequest()
{
    //New connection request
    if(FD_ISSET(nSocket,&fr))
    {
        int nLen=sizeof(struct sockaddr);
        int nClientSocket=  accept(nSocket,NULL,& nLen);

        if(nClientSocket > 0)
        {
            //put it into the client FD_SET
            int nIndex;
            for ( nIndex = 0; nIndex < 5  ; nIndex++)
            {
                if ( nArrClient[nIndex]==0)
                {
                    nArrClient[nIndex]=nClientSocket;
                    send(nClientSocket,"Get the connection done successfully",37,0);
                    break;
                }

            }
            
            if ( nIndex==5)
            {
                cout << endl << "No space for new connection";
            }


        }
    }
}


int main()
{
    //Initialize the WSA Variables
    int nRet=0;
    WSADATA ws;
    if(WSAStartup (MAKEWORD(2,2),&ws)<0)
    {
        cout << endl <<"WSA Failed to initialize";
        return 1;
    }
    else
    {
        cout << endl <<"WSA initialized";
    }

    //Initialize the Socket
    nSocket= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (nSocket<0)
    {
        cout << endl <<"The Socket not opened";
        return 1;
    }
    else
    {
        cout << endl <<"The Socket opened Successfully";
    }

    // Initialize  the environment for sockaddr structure
    srv.sin_family=AF_INET;
    srv.sin_port=htons(PORT);
    srv.sin_addr.s_addr=INADDR_ANY;

    // Bind the socket to the local port
    nRet=bind(nSocket,(sockaddr*)&srv,sizeof(srv));
    if (nRet<0)
    {
        cout << endl <<"Fail to bind to local port";
        return 1;
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
        return 1;
    }
    else
    {
        cout << endl <<"Started listen  to local port";
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

   

    // keep waiting for new request and processed as per the request
    while (1) {
        nRet=select(nMaxFD +1 , &fr, &fw, &fe, &tv);
        if ( nRet > 0)
        {
            // when someone connects or communicates with a message over a dedicated connection
            cout << endl << "Data on port .....  Processing  now...";
            break;

            ProcessTheNewRequest();
        }
    else if (nRet==0)
    {
        //No connection or any comminication request made or you can say that none of the socket descriptors are ready
         
    }
    else
    {
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    


    
}
  
}



