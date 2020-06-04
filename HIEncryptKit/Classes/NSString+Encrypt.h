//
//  NSString+Encrypt.h
//  HIEncryptKit <https://github.com/hellohufan/HIEncryptKit>
//
//  Created by IVAN on 15/1/26.
//  Copyright (c) 2015年 IVAN. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Encrypt)
- (NSString*)encryptedWithAESUsingKey:(NSString*)key andIV:(NSData*)iv;
- (NSString*)decryptedWithAESUsingKey:(NSString*)key andIV:(NSData*)iv;

- (NSString*)encryptedWith3DESUsingKey:(NSString*)key andIV:(NSData*)iv;
- (NSString*)decryptedWith3DESUsingKey:(NSString*)key andIV:(NSData*)iv;

@end
