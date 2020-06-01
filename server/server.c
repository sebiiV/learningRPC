#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "../learningRPC/learningRPC.h"

#include "../learningRPC/spn.c"


/******************************************************/
/*         Naive Security callback                    */
/******************************************************/
RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE hInterface, void* pBindinghandle)
{
    printf_s("Client connected\n");

    RPC_STATUS status;
    unsigned long ulAuthnLevel;
    unsigned long ulAuthnSvc;

    status = RpcBindingInqAuthClient(pBindinghandle,
        NULL,
        NULL,
        &ulAuthnLevel,
        &ulAuthnSvc,
        NULL);

    if (status) {
        printf_s("Client Inq failed");
        return RPC_S_ACCESS_DENIED;
    };

    if (ulAuthnLevel != RPC_C_AUTHN_LEVEL_PKT_PRIVACY || ulAuthnSvc != RPC_C_AUTHN_WINNT) {

        return RPC_S_ACCESS_DENIED;
    }

    printf_s("Client authneticated successfully");
    return RPC_S_OK;
}

void main()
{
    RPC_STATUS status;
    /*
    Best practice: Use ncacn_ip_tcp when making a remote call.
    Use ncalrpc for local calls. Do not use ncacn_np, ncacn_spx,
    or any of the ncadg_* protocol sequences; they are less efficient 
    and have inferior capabilities.
    */
    unsigned char* pszProtocolSequence = "ncalrpc";
    unsigned char* pszSecurity = NULL;
    unsigned char* pszEndpoint = "8765";
    unsigned int    cMinCalls = RPC_C_LISTEN_MAX_CALLS_DEFAULT;
    unsigned int    fDontWait = FALSE;

    //create a Service principal name
    LPSTR lpzSpn = makespn();

    //register it
    status = RpcServerRegisterAuthInfo(
        lpzSpn,                                // Server principal name
        RPC_C_AUTHN_GSS_NEGOTIATE,             // Authentication service
        NULL,                                  // Use default key function
        NULL);                                 // No arg for key function
    if (status) exit(status);

    status = RpcServerUseProtseqEpA(pszProtocolSequence,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        pszEndpoint,
        pszSecurity);


    if (status) exit(status);

    status = RpcServerRegisterIf2(
        learningRPC_v1_0_s_ifspec, // Interface to register.
        NULL, // Use the MIDL generated entry-point vector.
        NULL, // Use the MIDL generated entry-point vector.
        RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, // Forces use of security callback.
        RPC_C_LISTEN_MAX_CALLS_DEFAULT, // Use default number of concurrent calls.
        (unsigned)-1, // Infinite max size of incoming data blocks.
        SecurityCallback); // Naive security callback.

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