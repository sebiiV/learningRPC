#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "../learningRPC/learningRPC.h"


void main()
{
    RPC_STATUS status;
    unsigned char* pszUuid = NULL;
    RPC_CSTR pszProtocolSequence = "ncacn_np";
    RPC_CSTR pszNetworkAddress = NULL;
    RPC_CSTR pszEndpoint = "\\pipe\\learningRPC";
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
        Shutdown(hLearningRPCbinding);
    }
        RpcExcept(1)
    {
        ulCode = RpcExceptionCode();
        printf("Runtime reported exception 0x%lx = %ld\n", ulCode, ulCode);
    }
    RpcEndExcept

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