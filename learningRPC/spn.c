#pragma once
#include <windows.h>
#include <ntdsapi.h>

LPTSTR makespn() {
    DWORD dwStatus = ERROR_SUCCESS;
    DWORD dwLength = 0;
    LPTSTR lpzSpn = NULL;

    // call once, to get size of buffer
    dwStatus = DsMakeSpnA(
        "ldap",
        "ServerName.domain.com",
        NULL,
        0,
        NULL,
        &dwLength,
        NULL);

    lpzSpn = (LPTSTR)malloc(dwLength * sizeof(TCHAR));

    dwStatus = DsMakeSpnA(
        "ldap",
        "ServerName.domain.com",
        NULL,
        0,
        NULL,
        &dwLength,
        lpzSpn);

    if (dwStatus != ERROR_SUCCESS)
    {
        free(lpzSpn);
        exit(dwStatus);
    }

    return lpzSpn;

}

