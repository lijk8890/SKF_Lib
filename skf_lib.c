#ifdef UNICODE
#undef UNICODE
#endif
#include "skf_lib.h"

SKF_API_st* SKF_LoadLibrary(const char *libname)
{
    SKF_API_st *handle = (SKF_API_st*)calloc(1, sizeof(SKF_API_st));
    if(handle == NULL)
    {
        fprintf(stderr, "%s %s:%u - calloc failed\n", __FUNCTION__, __FILE__, __LINE__);
        return NULL;
    }

    handle->hSKF = (HMODULE)LoadLibrary(libname);
    if(handle->hSKF == NULL)
    {
        fprintf(stderr, "%s %s:%u - LoadLibrary \"%s\" failed\n", __FUNCTION__, __FILE__, __LINE__, libname);
        goto ErrP;
    }

    do {
        handle->SKF_WaitForDevEvent = (P_SKF_WaitForDevEvent)GetProcAddress(handle->hSKF, "SKF_WaitForDevEvent");
        if(handle->SKF_WaitForDevEvent == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_WaitForDevEvent\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_CancelWaitForDevEvent = (P_SKF_CancelWaitForDevEvent)GetProcAddress(handle->hSKF, "SKF_CancelWaitForDevEvent");
        if (handle->SKF_CancelWaitForDevEvent == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_CancelWaitForDevEvent\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_EnumDev = (P_SKF_EnumDev)GetProcAddress(handle->hSKF, "SKF_EnumDev");
        if(handle->SKF_EnumDev == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_EnumDev\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_ConnectDev = (P_SKF_ConnectDev)GetProcAddress(handle->hSKF, "SKF_ConnectDev");
        if(handle->SKF_ConnectDev == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ConnectDev\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_DisConnectDev = (P_SKF_DisConnectDev)GetProcAddress(handle->hSKF, "SKF_DisConnectDev");
        if(handle->SKF_DisConnectDev == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_DisConnectDev\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_EnumApplication = (P_SKF_EnumApplication)GetProcAddress(handle->hSKF, "SKF_EnumApplication");
        if(handle->SKF_EnumApplication == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_EnumApplication\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_OpenApplication = (P_SKF_OpenApplication)GetProcAddress(handle->hSKF, "SKF_OpenApplication");
        if(handle->SKF_OpenApplication == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_OpenApplication\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_CloseApplication = (P_SKF_CloseApplication)GetProcAddress(handle->hSKF, "SKF_CloseApplication");
        if(handle->SKF_CloseApplication == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_CloseApplication\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_CreateContainer = (P_SKF_CreateContainer)GetProcAddress(handle->hSKF, "SKF_CreateContainer");
        if(handle->SKF_CreateContainer == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_CreateContainer\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_DeleteContainer = (P_SKF_DeleteContainer)GetProcAddress(handle->hSKF, "SKF_DeleteContainer");
        if(handle->SKF_DeleteContainer == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_DeleteContainer\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_ChangePIN = (P_SKF_ChangePIN)GetProcAddress(handle->hSKF, "SKF_ChangePIN");
        if(handle->SKF_ChangePIN == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ChangePIN\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_VerifyPIN = (P_SKF_VerifyPIN)GetProcAddress(handle->hSKF, "SKF_VerifyPIN");
        if(handle->SKF_VerifyPIN == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_VerifyPIN\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_UnblockPIN = (P_SKF_UnblockPIN)GetProcAddress(handle->hSKF, "SKF_UnblockPIN");
        if(handle->SKF_UnblockPIN == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_UnblockPIN\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_EnumContainer = (P_SKF_EnumContainer)GetProcAddress(handle->hSKF, "SKF_EnumContainer");
        if(handle->SKF_EnumContainer == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_EnumContainer\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_OpenContainer = (P_SKF_OpenContainer)GetProcAddress(handle->hSKF, "SKF_OpenContainer");
        if(handle->SKF_OpenContainer == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_OpenContainer\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_CloseContainer = (P_SKF_CloseContainer)GetProcAddress(handle->hSKF, "SKF_CloseContainer");
        if(handle->SKF_CloseContainer == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_CloseContainer\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_ECCSignData = (P_SKF_ECCSignData)GetProcAddress(handle->hSKF, "SKF_ECCSignData");
        if(handle->SKF_ECCSignData == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ECCSignData\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_RSASignData = (P_SKF_RSASignData)GetProcAddress(handle->hSKF, "SKF_RSASignData");
        if(handle->SKF_RSASignData == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_RSASignData\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_GenECCKeyPair = (P_SKF_GenECCKeyPair)GetProcAddress(handle->hSKF, "SKF_GenECCKeyPair");
        if(handle->SKF_GenECCKeyPair == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_GenECCKeyPair\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_ImportECCKeyPair = (P_SKF_ImportECCKeyPair)GetProcAddress(handle->hSKF, "SKF_ImportECCKeyPair");
        if(handle->SKF_ImportECCKeyPair == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ImportECCKeyPair\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_GenRSAKeyPair = (P_SKF_GenRSAKeyPair)GetProcAddress(handle->hSKF, "SKF_GenRSAKeyPair");
        if(handle->SKF_GenRSAKeyPair == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_GenRSAKeyPair\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_ImportRSAKeyPair = (P_SKF_ImportRSAKeyPair)GetProcAddress(handle->hSKF, "SKF_ImportRSAKeyPair");
        if(handle->SKF_ImportRSAKeyPair == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ImportRSAKeyPair\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }

        handle->SKF_ImportCertificate = (P_SKF_ImportCertificate)GetProcAddress(handle->hSKF, "SKF_ImportCertificate");
        if(handle->SKF_ImportCertificate == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ImportCertificate\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_ExportCertificate = (P_SKF_ExportCertificate)GetProcAddress(handle->hSKF, "SKF_ExportCertificate");
        if(handle->SKF_ExportCertificate == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ExportCertificate\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
        handle->SKF_ExportPublicKey = (P_SKF_ExportPublicKey)GetProcAddress(handle->hSKF, "SKF_ExportPublicKey");
        if(handle->SKF_ExportPublicKey == NULL)
        {
            fprintf(stderr, "%s %s:%u - GetProcAddress \"SKF_ExportPublicKey\" failed\n", __FUNCTION__, __FILE__, __LINE__);
            goto ErrP;
        }
    } while(0);

    return handle;
ErrP:
    SKF_FreeLibrary(handle);
    return NULL;
}

void SKF_FreeLibrary(SKF_API_st *handle)
{
    if(handle)
    {
        if(handle->hSKF) FreeLibrary(handle->hSKF);
        free(handle);
    }
}
