#ifndef __SKF_LIB_H__
#define __SKF_LIB_H__

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <dlfcn.h>
#include <pthread.h>

#define HMODULE                 void*

#define LoadLibrary(x)          dlopen(x, RTLD_LAZY)
#define GetProcAddress(x, y)    dlsym(x, y)
#define FreeLibrary(x)          dlclose(x)
#endif

#include "skfapi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef ULONG (*P_SKF_WaitForDevEvent)(LPSTR szDevName, ULONG *pulDevNameLen, ULONG *pulEvent);
typedef ULONG (*P_SKF_CancelWaitForDevEvent)();
typedef ULONG (*P_SKF_EnumDev)(BOOL bPresent, LPSTR szNameList, ULONG *pulSize);
typedef ULONG (*P_SKF_ConnectDev)(LPSTR szName, DEVHANDLE *phDev);
typedef ULONG (*P_SKF_DisConnectDev)(DEVHANDLE hDev);

typedef ULONG (*P_SKF_EnumApplication)(DEVHANDLE hDev, LPSTR szAppName,ULONG *pulSize);
typedef ULONG (*P_SKF_OpenApplication)(DEVHANDLE hDev, LPSTR szAppName, HAPPLICATION *phApplication);
typedef ULONG (*P_SKF_CloseApplication)(HAPPLICATION hApplication);

typedef ULONG (*P_SKF_ChangePIN)(HAPPLICATION hApplication, ULONG ulPINType, LPSTR szOldPin, LPSTR szNewPin, ULONG *pulRetryCount);
typedef ULONG (*P_SKF_VerifyPIN)(HAPPLICATION hApplication, ULONG  ulPINType, LPSTR szPIN, ULONG *pulRetryCount);
typedef ULONG (*P_SKF_UnblockPIN)(HAPPLICATION hApplication, LPSTR szAdminPIN, LPSTR szNewUserPIN,  ULONG *pulRetryCount);

typedef ULONG (*P_SKF_EnumContainer)(HAPPLICATION hApplication, LPSTR szContainerName, ULONG *pulSize);
typedef ULONG (*P_SKF_OpenContainer)(HAPPLICATION hApplication, LPSTR szContainerName, HCONTAINER *phContainer);
typedef ULONG (*P_SKF_CloseContainer)(HCONTAINER hContainer);
typedef ULONG (*P_SKF_CreateContainer)(HAPPLICATION hApplication, LPSTR szContainerName, HCONTAINER *phContainer);
typedef ULONG (*P_SKF_DeleteContainer)(HAPPLICATION hApplication, LPSTR szContainerName);

typedef ULONG (*P_SKF_ECCSignData)(HCONTAINER hContainer, BYTE *pbData, ULONG ulDataLen, PECCSIGNATUREBLOB pSignature);
typedef ULONG (*P_SKF_RSASignData)(HCONTAINER hContainer, BYTE *pbData, ULONG ulDataLen, BYTE *pbSignature, ULONG *pulSignLen);

typedef ULONG (*P_SKF_GenECCKeyPair)(HCONTAINER hContainer, ULONG ulAlgId, ECCPUBLICKEYBLOB *pBlob);
typedef ULONG (*P_SKF_ImportECCKeyPair)(HCONTAINER hContainer, PENVELOPEDKEYBLOB pEnvelopedKeyBlob);

typedef ULONG (*P_SKF_GenRSAKeyPair)(HCONTAINER hContainer, ULONG ulBitsLen, RSAPUBLICKEYBLOB *pBlob);
typedef ULONG (*P_SKF_ImportRSAKeyPair)(HCONTAINER hContainer, ULONG ulSymAlgId, BYTE *pbWrappedKey, ULONG ulWrappedKeyLen, BYTE *pbEncryptedData, ULONG ulEncryptedDataLen);

typedef ULONG (*P_SKF_ImportCertificate)(HCONTAINER hContainer, BOOL bSignFlag,  BYTE* pbCert, ULONG ulCertLen);
typedef ULONG (*P_SKF_ExportCertificate)(HCONTAINER hContainer, BOOL bSignFlag,  BYTE* pbCert, ULONG *pulCertLen);
typedef ULONG (*P_SKF_ExportPublicKey)(HCONTAINER hContainer, BOOL bSignFlag, BYTE* pbBlob, ULONG* pulBlobLen);

typedef struct {
    HMODULE                     hSKF;       // SKF动态库句柄

    P_SKF_WaitForDevEvent       SKF_WaitForDevEvent;
    P_SKF_CancelWaitForDevEvent SKF_CancelWaitForDevEvent;
    P_SKF_EnumDev               SKF_EnumDev;
    P_SKF_ConnectDev            SKF_ConnectDev;
    P_SKF_DisConnectDev         SKF_DisConnectDev;

    P_SKF_EnumApplication       SKF_EnumApplication;
    P_SKF_OpenApplication       SKF_OpenApplication;
    P_SKF_CloseApplication      SKF_CloseApplication;

    P_SKF_ChangePIN             SKF_ChangePIN;
    P_SKF_VerifyPIN             SKF_VerifyPIN;
    P_SKF_UnblockPIN            SKF_UnblockPIN;

    P_SKF_EnumContainer         SKF_EnumContainer;
    P_SKF_OpenContainer         SKF_OpenContainer;
    P_SKF_CloseContainer        SKF_CloseContainer;
    P_SKF_CreateContainer       SKF_CreateContainer;
    P_SKF_DeleteContainer       SKF_DeleteContainer;

    P_SKF_ECCSignData           SKF_ECCSignData;
    P_SKF_RSASignData           SKF_RSASignData;

    P_SKF_GenECCKeyPair         SKF_GenECCKeyPair;
    P_SKF_ImportECCKeyPair      SKF_ImportECCKeyPair;

    P_SKF_GenRSAKeyPair         SKF_GenRSAKeyPair;
    P_SKF_ImportRSAKeyPair      SKF_ImportRSAKeyPair;

    P_SKF_ImportCertificate     SKF_ImportCertificate;
    P_SKF_ExportCertificate     SKF_ExportCertificate;
    P_SKF_ExportPublicKey       SKF_ExportPublicKey;
} SKF_API_st;

SKF_API_st* SKF_LoadLibrary(const char *libname);

void SKF_FreeLibrary(SKF_API_st *handle);

#ifdef __cplusplus
}
#endif

#endif
