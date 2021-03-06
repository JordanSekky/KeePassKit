//
//  KPKFormat.h
//  KeePassKit
//
//  Created by Michael Starke on 12.07.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>
#import "KPKVersion.h"

FOUNDATION_EXTERN NSString *const kKPKTitleKey;
FOUNDATION_EXTERN NSString *const kKPKNameKey;
FOUNDATION_EXTERN NSString *const kKPKUsernameKey;
FOUNDATION_EXTERN NSString *const kKPKPasswordKey;
FOUNDATION_EXTERN NSString *const kKPKURLKey;
FOUNDATION_EXTERN NSString *const kKPKNotesKey;

/**
 Format class.
 Holds all allowed keys for an element.
 */
@interface KPKFormat : NSObject
/**
 @returns The shared format instance
 */
+ (instancetype)sharedFormat;

/**
 @param data The input data to read
 @returns the Version for this file type
 */
- (KPKVersion)databaseVersionForData:(NSData *)data;
/**
 @param data The input data of a kdb file
 @returns the interla veriosn number, NOT if it's a Version1 or Version2 file. Use databaseVersionForData to dertmine the Version
 */
- (uint32_t)fileVersionForData:(NSData *)data;
/**
 @returns A set containing the strings that are default keys
 */
- (NSSet *)defaultKeys;
/**
 @param key The key to test for defaultness
 @returns YES, if the key is a default key, NO otherwise
 */
- (BOOL)isDefaultKey:(NSString *)key;

/**
 @param key The key to determine the minimum version for
 @returns The minimum version for a database to store this key
 */
- (KPKVersion)minimumVersionForKey:(NSString *)key;

@end
