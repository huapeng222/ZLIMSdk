//
//  ZLIMHeader.h
//  aichat
//
//  Created by hua on 2019/5/24.
//  Copyright © 2019 Facebook. All rights reserved.
//

#ifndef ZLIMHeader_h
#define ZLIMHeader_h

typedef NS_ENUM(NSInteger, CmIdHeader) {
    CmIdHeaderLogin 			= 1,			///< 登录
    CmIdHeaderImMessage 		= 2,          	///< 消息
    CmIdHeaderBotMessage 		= 3,          	///< 机器人消息
    CmIdHeaderBotHeart 			= 5,         	///< 心跳
};

#endif /* ZLIMHeader_h */
