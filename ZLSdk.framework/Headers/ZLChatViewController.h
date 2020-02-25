//
//  ZLChatViewController.h
//  ZLSdk
//
//  Created by hua on 2019/5/30.
//  Copyright © 2019 zhilian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZLIMBaseViewController.h"


@interface ZLChatViewController : ZLIMBaseViewController
@property(nonatomic,copy)NSString *groupId;///<回话id

/// 聊天背景图片
@property(nonatomic,strong)UIImage *chatBgImage;
@end

