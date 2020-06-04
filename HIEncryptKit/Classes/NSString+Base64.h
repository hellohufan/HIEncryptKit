//
//  NSString+Base64.h
//   HIEncryptKit <https://github.com/hellohufan/HIEncryptKit>
//
//  Created by IVAN on 15/2/8.
//  Copyright (c) 2015年 IVAN. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Base64)
+ (NSString *)stringWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
- (NSString *)base64EncodedString;
- (NSString *)base64DecodedString;
- (NSData *)base64DecodedData;
@end
