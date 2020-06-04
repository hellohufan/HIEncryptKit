//
//  NSString+Hash.h
//   HIEncryptKit <https://github.com/hellohufan/HIEncryptKit>
//
//  Created by IVAN on 14/12/15.
//  Copyright (c) 2014年 IVAN. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSString (Hash)
@property (readonly) NSString *md5String;
@property (readonly) NSString *sha1String;
@property (readonly) NSString *sha256String;
@property (readonly) NSString *sha512String;

- (NSString *)hmacMD5StringWithKey:(NSString *)key;
- (NSString *)hmacSHA1StringWithKey:(NSString *)key;
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;
@end
