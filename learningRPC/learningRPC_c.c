

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for learningRPC.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "learningRPC_h.h"

#define TYPE_FORMAT_STRING_SIZE   7                                 
#define PROC_FORMAT_STRING_SIZE   63                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _learningRPC_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } learningRPC_MIDL_TYPE_FORMAT_STRING;

typedef struct _learningRPC_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } learningRPC_MIDL_PROC_FORMAT_STRING;

typedef struct _learningRPC_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } learningRPC_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const learningRPC_MIDL_TYPE_FORMAT_STRING learningRPC__MIDL_TypeFormatString;
extern const learningRPC_MIDL_PROC_FORMAT_STRING learningRPC__MIDL_ProcFormatString;
extern const learningRPC_MIDL_EXPR_FORMAT_STRING learningRPC__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: learningRPC, ver. 1.0,
   GUID={0xd4866451,0xc006,0x4680,{0xa2,0xa7,0xa2,0x6e,0x69,0xc6,0xd0,0xaa}} */

handle_t hLearningRPCbinding;


static const RPC_CLIENT_INTERFACE learningRPC___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xd4866451,0xc006,0x4680,{0xa2,0xa7,0xa2,0x6e,0x69,0xc6,0xd0,0xaa}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE learningRPC_v1_0_c_ifspec = (RPC_IF_HANDLE)& learningRPC___RpcClientInterface;

extern const MIDL_STUB_DESC learningRPC_StubDesc;

static RPC_BINDING_HANDLE learningRPC__MIDL_AutoBindHandle;


void Echo( 
    /* [in] */ handle_t h1,
    /* [string][in] */ unsigned char *pszString)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&learningRPC_StubDesc,
                  (PFORMAT_STRING) &learningRPC__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&h1);
    
}


void Shutdown( 
    /* [in] */ handle_t h1)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&learningRPC_StubDesc,
                  (PFORMAT_STRING) &learningRPC__MIDL_ProcFormatString.Format[34],
                  ( unsigned char * )&h1);
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const learningRPC_MIDL_PROC_FORMAT_STRING learningRPC__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Echo */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	NdrFcShort( 0x0 ),	/* 0 */
/* 18 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x1,		/* 1 */
/* 20 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszString */

/* 28 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 30 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 32 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Procedure Shutdown */

/* 34 */	0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/* 36 */	NdrFcLong( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x1 ),	/* 1 */
/* 42 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 44 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 46 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 54 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const learningRPC_MIDL_TYPE_FORMAT_STRING learningRPC__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const unsigned short learningRPC_FormatStringOffsetTable[] =
    {
    0,
    34
    };


static const MIDL_STUB_DESC learningRPC_StubDesc = 
    {
    (void *)& learningRPC___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &hLearningRPCbinding,
    0,
    0,
    0,
    0,
    learningRPC__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

