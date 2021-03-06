#ifndef SB_H
#define SB_H 1

struct _WIN_CERTIFICATE {
	UINT32	dwLength;
	UINT16	wRevision;
	UINT16	wCertificateType;
	//UINT8	bCertficate[];
} __attribute__((aligned (1)));

typedef struct _WIN_CERTIFICATE WIN_CERTIFICATE;

#define EFI_CERT_TYPE_RSA2048_SHA256_GUID \
  { 0xa7717414, 0xc616, 0x4977, {0x94,0x20,0x84,0x47,0x12,0xa7,0x35,0xbf }}

typedef struct {
	EFI_GUID	HashType;
	UINT8		PublicKey[256];
	UINT8		Signature[256];
} EFI_CERT_BLOCK_RSA_2048_SHA256;

struct _WIN_CERTIFICATE_UEFI_GUID {
	WIN_CERTIFICATE	Hdr;
	EFI_GUID	CertType;
	//UINT8		CertData[];
} __attribute__((aligned (1)));

typedef struct _WIN_CERTIFICATE_UEFI_GUID WIN_CERTIFICATE_UEFI_GUID;

struct _EFI_VARIABLE_AUTHENTICATION {
	UINT64				MonotonicCount;
	WIN_CERTIFICATE_UEFI_GUID	AuthInfo;
} __attribute__((aligned (1)));

typedef struct _EFI_VARIABLE_AUTHENTICATION EFI_VARIABLE_AUTHENTICATION;

struct _EFI_VARIABLE_AUTHENTICATION_2 {
	EFI_TIME			TimeStamp;
	WIN_CERTIFICATE_UEFI_GUID	AuthInfo;
} __attribute__((aligned (1)));

typedef struct _EFI_VARIABLE_AUTHENTICATION_2 EFI_VARIABLE_AUTHENTICATION_2;

struct _EFI_SIGNATURE_DATA {
	EFI_GUID	SignatureOwner; /* 16 */
//	UINT8		SignatureData[];
} __attribute__((aligned (1)));

typedef struct _EFI_SIGNATURE_DATA EFI_SIGNATURE_DATA;

struct _EFI_SIGNATURE_LIST {
	EFI_GUID	SignatureType;		/* 16 */
	UINT32		SignatureListSize;	/* 4 */
	UINT32		SignatureHeaderSize;	/* 4 */
	UINT32		SignatureSize;		/* 4 */
} __attribute__((aligned (1)));

typedef struct _EFI_SIGNATURE_LIST EFI_SIGNATURE_LIST;

#define EFI_IMAGE_SECURITY_DATABASE_GUID \
  { 0xd719b2cb, 0x3d3a, 0x4596, {0xa3,0xbc,0xda,0xd0,0x0e,0x67,0x65,0x6f }}
EFI_GUID gEfiImageSecurityDatabaseGuid = EFI_IMAGE_SECURITY_DATABASE_GUID;

#define EFI_CERT_SHA256_GUID \
  { 0xc1c41626, 0x504c, 0x4092, {0xac,0xa9,0x41,0xf9,0x36,0x93,0x43,0x28 }}
EFI_GUID gEfiCertSha256Guid = EFI_CERT_SHA256_GUID;

#define EFI_CERT_RSA2048_GUID \
  { 0x3c5766e8, 0x269c, 0x4e34, {0xaa,0x14,0xed,0x77,0x6e,0x85,0xb3,0xb6 }}
EFI_GUID gEfiCertRsa2048Guid = EFI_CERT_RSA2048_GUID;

#define EFI_CERT_RSA2048_SHA256_GUID \
  { 0xe2b36190, 0x879b, 0x4a3d, {0xad,0x8d,0xf2,0xe7,0xbb,0xa3,0x27,0x84 }}
EFI_GUID gEfiCertRsa2048Sha256Guid = EFI_CERT_RSA2048_SHA256_GUID;

#define EFI_CERT_SHA1_GUID \
  { 0x826ca512, 0xcf10, 0x4ac9, {0xb1,0x87,0xbe,0x01,0x49,0x66,0x31,0xbd }}
EFI_GUID gEfiCertSha1Guid = EFI_CERT_SHA1_GUID;

#define EFI_CERT_RSA2048_SHA1_GUID \
  { 0x67f8444f, 0x8743, 0x48f1, {0xa3,0x28,0x1e,0xaa,0xb8,0x73,0x60,0x80 }}
EFI_GUID gEfiCertRsa2048Sha1Guid = EFI_CERT_RSA2048_SHA1_GUID;

#define EFI_CERT_X509_GUID \
  { 0xa5c059a1, 0x94e4, 0x4aa7, {0x87,0xb5,0xab,0x15,0x5c,0x2b,0xf0,0x72 }}
EFI_GUID gEfiCertX509Guid = EFI_CERT_X509_GUID;

#define EFI_CERT_TYPE_PKCS7_GUID \
  { 0x4aafd29d, 0x68df, 0x49ee, {0x8a,0xa9,0x34,0x7d,0x37,0x56,0x65,0xa7 }}
EFI_GUID gEfiCertPkcs7Guid = EFI_CERT_TYPE_PKCS7_GUID;

#define EFI_IMAGE_SECURITY_DATABASE L"db"
#define EFI_IMAGE_SECURITY_DATABASE1 L"dbx"
#define EFI_SETUP_MODE_NAME L"SetupMode"
#define EFI_PLATFORM_KEY_NAME L"PK"
#define EFI_KEY_EXCHANGE_KEY_NAME L"KEK"
#define EFI_SIGNATURE_SUPPORT_NAME L"SignatureSupport"
#define EFI_SECURE_BOOT_MODE_NAME L"SecureBoot"

#define SECURE_BOOT_MODE_ENABLE 1
#define SECURE_BOOT_MODE_DISABLE 0

#define SETUP_MODE 1
#define USER_MODE 0

#endif /* SB_H */
