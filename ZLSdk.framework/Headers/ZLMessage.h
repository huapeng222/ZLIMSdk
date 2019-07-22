//
//  ZLMessage.h
//  ZLSdk
//
//  Created by hua on 2019/6/1.
//  Copyright © 2019 zhilian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZLMessage : NSObject


@property(nonatomic,copy)NSString *msgId;///<消息id
@property(nonatomic,copy)NSString *content;///<消息内容
@property(nonatomic,copy)NSString *toId;///<发送给谁
@property(nonatomic,copy)NSString *fromId;///<谁发送的
@property(nonatomic,copy)NSString *groupId;///<会话id
@property(nonatomic,copy)NSString *fileUrl;///<文件地址(包括图片语音视频)
@property(nonatomic,copy)NSString *filePath;///<文件本地地址(包括图片语音视频)

@property(nonatomic,copy)NSString *capacity;///<容量,语音时长,文件大小,视频长度等

@property(nonatomic,assign)NSInteger msgType;///<消息类型,1-文本 2-图片 3-语音 4-位置   5-视频 6 -文件  7-名片,-1,时间

@property(nonatomic,assign)BOOL isSendOut;///<是否是自己发出去的


@property(nonatomic,copy)NSString *avatarUrl;///<头像地址
@property(nonatomic,copy)NSString *sendName;///<发送人名字


@property(nonatomic,assign)NSInteger sendState;///<发送状态,0成功,1发送中,2发送失败

@property(nonatomic,assign)NSTimeInterval time;///<消息时间戳

@property(nonatomic,copy)NSString *maybeHits;///<可能命中的问题

@property(nonatomic,copy)NSString *relatedKnowledge;///<可能命中的问题

@property(nonatomic,copy)NSString *replay;

+ (NSString *)createBotId:(NSString *)botId;


/**
 是否是可能问题
 */
- (BOOL)isMaybeMsg;

/**
 是否是相关问题
 */
- (BOOL)isRelatedKnowledgeMsg;
@end
