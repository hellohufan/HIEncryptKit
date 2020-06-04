//
//  HIKeychain.h
//  HIEncryptKit <https://github.com/hellohufan/HIEncryptKit>
//
//  Created by IVAN on 14/10/15.
//  Copyright (c) 2015 IVAN.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>


@class HIKeychainItem;


NS_ASSUME_NONNULL_BEGIN

/**
 A wrapper for system keychain API.
 
 Inspired by [SSKeychain]
 */
@interface HIKeychain : NSObject

#pragma mark - Convenience method for keychain
///=============================================================================
/// @name Convenience method for keychain
///=============================================================================

/**
 Returns the password for a given account and service, or `nil` if not found or
 an error occurs.
 
 @param serviceName The service for which to return the corresponding password.
 This value must not be nil.
 
 @param account The account for which to return the corresponding password.
 This value must not be nil.
 
 @param error   On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information. 
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return Password string, or nil when not found or error occurs.
 */
+ (nullable NSString *)getPasswordForService:(NSString *)serviceName
                                     account:(NSString *)account
                                       error:(NSError **)error;
+ (nullable NSString *)getPasswordForService:(NSString *)serviceName
                                     account:(NSString *)account;

/**
 Deletes a password from the Keychain.
 
 @param serviceName The service for which to return the corresponding password.
 This value must not be nil.
 
 @param account The account for which to return the corresponding password.
 This value must not be nil.
 
 @param error   On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return Whether succeed.
 */
+ (BOOL)deletePasswordForService:(NSString *)serviceName account:(NSString *)account error:(NSError **)error;
+ (BOOL)deletePasswordForService:(NSString *)serviceName account:(NSString *)account;

/**
 Insert or update the password for a given account and service.
 
 @param password    The new password.
 
 @param serviceName The service for which to return the corresponding password.
 This value must not be nil.
 
 @param account The account for which to return the corresponding password.
 This value must not be nil.
 
 @param error   On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return Whether succeed.
 */
+ (BOOL)setPassword:(NSString *)password
         forService:(NSString *)serviceName
            account:(NSString *)account
              error:(NSError **)error;
+ (BOOL)setPassword:(NSString *)password
         forService:(NSString *)serviceName
            account:(NSString *)account;


#pragma mark - Full query for keychain (SQL-like)
///=============================================================================
/// @name Full query for keychain (SQL-like)
///=============================================================================

/**
 Insert an item into keychain.
 
 @discussion The service,account,password is required. If there's item exist
 already, an error occurs and insert fail.
 
 @param item  The item to insert.
 
 @param error On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return Whether succeed.
 */
+ (BOOL)insertItem:(HIKeychainItem *)item error:(NSError **)error;
+ (BOOL)insertItem:(HIKeychainItem *)item;

/**
 Update item in keychain.
 
 @discussion The service,account,password is required. If there's no item exist
 already, an error occurs and insert fail.
 
 @param item  The item to insert.
 
 @param error On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return Whether succeed.
 */
+ (BOOL)updateItem:(HIKeychainItem *)item error:(NSError **)error;
+ (BOOL)updateItem:(HIKeychainItem *)item;

/**
 Delete items from keychain.
 
 @discussion The service,account,password is required. If there's item exist
 already, an error occurs and insert fail.
 
 @param item  The item to update.
 
 @param error On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return Whether succeed.
 */
+ (BOOL)deleteItem:(HIKeychainItem *)item error:(NSError **)error;
+ (BOOL)deleteItem:(HIKeychainItem *)item;

/**
 Find an item from keychain.
 
 @discussion The service,account is optinal. It returns only one item if there
 exist multi.
 
 @param item  The item for query.
 
 @param error On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return An item or nil.
 */
+ (nullable HIKeychainItem *)selectOneItem:(HIKeychainItem *)item error:(NSError **)error;
+ (nullable HIKeychainItem *)selectOneItem:(HIKeychainItem *)item;

/**
 Find all items matches the query.
 
 @discussion The service,account is optinal. It returns all item matches by the
 query.
 
 @param item  The item for query.
 
 @param error On input, a pointer to an error object. If an error occurs,
 this pointer is set to an actual error object containing the error information.
 You may specify nil for this parameter if you do not want the error information.
 See `HIKeychainErrorCode`.
 
 @return An array of HIKeychainItem.
 */
+ (nullable NSArray<HIKeychainItem *> *)selectItems:(HIKeychainItem *)item error:(NSError **)error;
+ (nullable NSArray<HIKeychainItem *> *)selectItems:(HIKeychainItem *)item;

@end




#pragma mark - Const

/**
 Error code in HIKeychain API.
 */
typedef NS_ENUM (NSUInteger, HIKeychainErrorCode) {
    HIKeychainErrorUnimplemented = 1, ///< Function or operation not implemented.
    HIKeychainErrorIO, ///< I/O error (bummers)
    HIKeychainErrorOpWr, ///< File already open with with write permission.
    HIKeychainErrorParam, ///< One or more parameters passed to a function where not valid.
    HIKeychainErrorAllocate, ///< Failed to allocate memory.
    HIKeychainErrorUserCancelled, ///< User cancelled the operation.
    HIKeychainErrorBadReq, ///< Bad parameter or invalid state for operation.
    HIKeychainErrorInternalComponent, ///< Internal...
    HIKeychainErrorNotAvailable, ///< No keychain is available. You may need to restart your computer.
    HIKeychainErrorDuplicateItem, ///< The specified item already exists in the keychain.
    HIKeychainErrorItemNotFound, ///< The specified item could not be found in the keychain.
    HIKeychainErrorInteractionNotAllowed, ///< User interaction is not allowed.
    HIKeychainErrorDecode, ///< Unable to decode the provided data.
    HIKeychainErrorAuthFailed, ///< The user name or passphrase you entered is not.
};


/**
 When query to return the item's data, the error
 errSecInteractionNotAllowed will be returned if the item's data is not
 available until a device unlock occurs.
 */
typedef NS_ENUM (NSUInteger, HIKeychainAccessible) {
    HIKeychainAccessibleNone = 0, ///< no value
    
    /** Item data can only be accessed
     while the device is unlocked. This is recommended for items that only
     need be accesible while the application is in the foreground.  Items
     with this attribute will migrate to a new device when using encrypted
     backups. */
    HIKeychainAccessibleWhenUnlocked,
    
    /** Item data can only be
     accessed once the device has been unlocked after a restart.  This is
     recommended for items that need to be accesible by background
     applications. Items with this attribute will migrate to a new device
     when using encrypted backups.*/
    HIKeychainAccessibleAfterFirstUnlock,
    
    /** Item data can always be accessed
     regardless of the lock state of the device.  This is not recommended
     for anything except system use. Items with this attribute will migrate
     to a new device when using encrypted backups.*/
    HIKeychainAccessibleAlways,
    
    /** Item data can
     only be accessed while the device is unlocked. This class is only
     available if a passcode is set on the device. This is recommended for
     items that only need to be accessible while the application is in the
     foreground. Items with this attribute will never migrate to a new
     device, so after a backup is restored to a new device, these items
     will be missing. No items can be stored in this class on devices
     without a passcode. Disabling the device passcode will cause all
     items in this class to be deleted.*/
    HIKeychainAccessibleWhenPasscodeSetThisDeviceOnly,
    
    /** Item data can only
     be accessed while the device is unlocked. This is recommended for items
     that only need be accesible while the application is in the foreground.
     Items with this attribute will never migrate to a new device, so after
     a backup is restored to a new device, these items will be missing. */
    HIKeychainAccessibleWhenUnlockedThisDeviceOnly,
    
    /** Item data can
     only be accessed once the device has been unlocked after a restart.
     This is recommended for items that need to be accessible by background
     applications. Items with this attribute will never migrate to a new
     device, so after a backup is restored to a new device these items will
     be missing.*/
    HIKeychainAccessibleAfterFirstUnlockThisDeviceOnly,
    
    /** Item data can always
     be accessed regardless of the lock state of the device.  This option
     is not recommended for anything except system use. Items with this
     attribute will never migrate to a new device, so after a backup is
     restored to a new device, these items will be missing.*/
    HIKeychainAccessibleAlwaysThisDeviceOnly,
};

/**
 Whether the item in question can be synchronized.
 */
typedef NS_ENUM (NSUInteger, HIKeychainQuerySynchronizationMode) {
    
    /** Default, Don't care for synchronization  */
    HIKeychainQuerySynchronizationModeAny = 0,
    
    /** Is not synchronized */
    HIKeychainQuerySynchronizationModeNo,
    
    /** To add a new item which can be synced to other devices, or to obtain 
     synchronized results from a query*/
    HIKeychainQuerySynchronizationModeYes,
} NS_AVAILABLE_IOS (7_0);


#pragma mark - Item

/**
 Wrapper for keychain item/query.
 */
@interface HIKeychainItem : NSObject <NSCopying>

@property (nullable, nonatomic, copy) NSString *service; ///< kSecAttrService
@property (nullable, nonatomic, copy) NSString *account; ///< kSecAttrAccount
@property (nullable, nonatomic, copy) NSData *passwordData; ///< kSecValueData
@property (nullable, nonatomic, copy) NSString *password; ///< shortcut for `passwordData`
@property (nullable, nonatomic, copy) id <NSCoding> passwordObject; ///< shortcut for `passwordData`

@property (nullable, nonatomic, copy) NSString *label; ///< kSecAttrLabel
@property (nullable, nonatomic, copy) NSNumber *type; ///< kSecAttrType (FourCC)
@property (nullable, nonatomic, copy) NSNumber *creater; ///< kSecAttrCreator (FourCC)
@property (nullable, nonatomic, copy) NSString *comment; ///< kSecAttrComment
@property (nullable, nonatomic, copy) NSString *descr; ///< kSecAttrDescription
@property (nullable, nonatomic, readonly, strong) NSDate *modificationDate; ///< kSecAttrModificationDate
@property (nullable, nonatomic, readonly, strong) NSDate *creationDate; ///< kSecAttrCreationDate
@property (nullable, nonatomic, copy) NSString *accessGroup; ///< kSecAttrAccessGroup

@property (nonatomic) HIKeychainAccessible accessible; ///< kSecAttrAccessible
@property (nonatomic) HIKeychainQuerySynchronizationMode synchronizable NS_AVAILABLE_IOS(7_0); ///< kSecAttrSynchronizable

@end

NS_ASSUME_NONNULL_END

