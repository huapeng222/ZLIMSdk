//
//  ZLIMUtils.h
//  ZLSdk
//
//  Created by hua on 2019/6/24.
//  Copyright © 2019 zhilian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZLIMUtils : NSObject
+ (void)getIMServerWithCorpId:(NSString *)corpId robots:(NSArray *)robots userId:(NSString *)userId completion:(void (^) (NSDictionary *rspDict,NSError *error))completion;

+ (void)getWelcomeMessage:(NSString *)botId userId:(NSString *)userId completion:(void (^) (NSDictionary *rspDict,NSError *error))completion;
@end

