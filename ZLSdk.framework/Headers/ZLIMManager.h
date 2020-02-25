//
//  ZLIMManager.h
//  Mars
//
//  Created by hua on 2019/5/21.
//  Copyright © 2019 hzp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZLIMHeader.h"
#import "ZLMessage.h"

typedef void (^ReceivedMessage)(id value,CmIdHeader header);///<接收到系统推送



@interface ZLIMManager : NSObject

@property(copy,nonatomic)ReceivedMessage receivedMessage;///<接收到系统推送
/**
 *  初始化
 */
+ (instancetype)sharedInstance;

- (void)connectAndLoginIMWithCorpId:(NSString *)corpId robots:(NSArray *)robots userId:(NSString *)userId completion:(void(^)(id value,NSError *error))completion;

- (void)sendBotMessage:(ZLMessage *)msg completion:(void(^)(id value,NSError *error))completion;

- (void)sendImMessage:(NSDictionary *)parame completion:(void(^)(id value,NSError *error))completion;

#pragma mark - 程序生命周期
// 进入后台
- (void)applicationDidEnterBackground:(UIApplication *)application;
// 将要进入前台
- (void)applicationWillEnterForeground:(UIApplication *)application;
// 程序将要终止
- (void)applicationWillTerminate:(UIApplication *)application;

#pragma mark - ui


/// 打开聊天界面
/// @param vc 打开页面的当前页面
/// @param groupId 聊天id
- (UIViewController *)openChatVC:(UIViewController *)vc groupId:(NSString *)groupId;


/**
 获取欢迎语

 @param botId 机器人id
 @param userId 用户id
 */
- (void)getWelcomeMessage:(NSString *)botId userId:(NSString *)userId;


/**
 清空本地存储的消息
 */
- (void)deleteAllMsg;
#pragma mark - 断开连接
- (void)disconnect;
@end

