#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "HIFileHash.h"
#import "HIKeychain.h"
#import "NSData+Base64.h"
#import "NSData+Encrypt.h"
#import "NSData+Hash.h"
#import "NSString+Base64.h"
#import "NSString+Encrypt.h"
#import "NSString+Hash.h"

FOUNDATION_EXPORT double HIEncryptKitVersionNumber;
FOUNDATION_EXPORT const unsigned char HIEncryptKitVersionString[];

