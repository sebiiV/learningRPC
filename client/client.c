#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "../learningRPC/learningRPC.h"


void main()
{
    RPC_STATUS status;
    /*
    Best practice: Use ncacn_ip_tcp when making a remote call.
    Use ncalrpc for local calls. Do not use ncacn_np, ncacn_spx,
    or any of the ncadg_* protocol sequences; they are less efficient 
    and have inferior capabilities.
    */
    unsigned char* pszUuid = NULL;
    RPC_CSTR pszProtocolSequence = "ncalrpc";
    RPC_CSTR pszNetworkAddress = NULL;
    RPC_CSTR pszEndpoint = "8765";
    RPC_CSTR pszOptions = NULL;
    RPC_CSTR pszStringBinding = NULL;
    RPC_CSTR pszString = "hello, world";
    unsigned long ulCode;

    status = RpcStringBindingComposeA(pszUuid,
        pszProtocolSequence,
        pszNetworkAddress,
        pszEndpoint,
        pszOptions,
        &pszStringBinding);

    if (status) exit(status);

    status = RpcBindingFromStringBindingA(pszStringBinding, &hLearningRPCbinding);

    if (status) exit(status);

    RpcTryExcept
    {
        Echo(hLearningRPCbinding,pszString);
        unsigned int response = Square(hLearningRPCbinding, 4);
        printf_s("response from squared: %i\n", response);
    }
        RpcExcept(1)
    {
        ulCode = RpcExceptionCode();
        printf("Runtime reported exception 0x%lx = %ld\n", ulCode, ulCode);
    }
    RpcEndExcept

        Shutdown(hLearningRPCbinding);
        status = RpcStringFree(&pszStringBinding);

    if (status) exit(status);

    status = RpcBindingFree(&hLearningRPCbinding);

    if (status) exit(status);

    exit(0);
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