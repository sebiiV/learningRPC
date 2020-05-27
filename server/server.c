#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "../learningRPC/learningRPC.h"



void main()
{
    RPC_STATUS status;
    unsigned char* pszProtocolSequence = "ncacn_np";
    unsigned char* pszSecurity = NULL;
    unsigned char* pszEndpoint = "\\pipe\\learningRPC";
    unsigned int    cMinCalls = 1;
    unsigned int    fDontWait = FALSE;


    status = RpcServerUseProtseqEpA(pszProtocolSequence,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        pszEndpoint,
        pszSecurity);

    // this is scuffed, was return 1703 with the above. So this is bruteforce solution...
    //status = RpcServerUseAllProtseqs(RPC_C_LISTEN_MAX_CALLS_DEFAULT, pszSecurity);

    if (status) exit(status);

    status = RpcServerRegisterIf(learningRPC_v1_0_s_ifspec,
        NULL,
        NULL);

    if (status) exit(status);

    status = RpcServerListen(cMinCalls,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        fDontWait);

    if (status) exit(status);
}


/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}