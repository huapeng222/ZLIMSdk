//
//  ZLChatView.h
//  ZLSdk
//
//  Created by hua on 2019/6/8.
//  Copyright © 2019 zhilian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZLMessage.h"

typedef void (^SendMessageText)(NSString * text);///<发送消息
typedef void (^SendMessageAudio)(NSString * audioPath,NSString *audioDuration,NSString *audioName);///<发送语音消息
typedef void (^ZLChatHeaderClick)(ZLMessage * msg);///<头像点击
typedef void (^ZLChatHeaderLongPress)(ZLMessage * msg);///<头像长按
typedef void (^ZLBubbleViewLongPress)(ZLMessage *msg,UIView *contentView);///<气泡长按
typedef void (^ZLDidClickLinkWithMoreQuestion)(NSString *question,NSString*replay);///<更多问题点击
@protocol ZLChatViewDataSource <NSObject>

@optional
/// 如果需要自定义cell,使用该方法,如果调用该方法,并且返回不为空,就是用sdk内部的方法绘制
/// @param indexPath 行数
/// @param tableView 聊天列表
/// @param msg 数据
- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath tableView:(UITableView *)tableView msg:(ZLMessage *)msg;

/// 由于自定义cell,行高如果能够满足autoLayout规则,不需要实现高度回调,如果不行,需要返回实际行高,建议尽量满足autoLayout,不适用此方法
/// @param tableView 列表
/// @param indexPath 行数
-(CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath;


/// 下拉
/// @param refreshControl 上层需要提供需要插入到上方的新数据数组
- (NSArray *)downRefreshChatList:(UIRefreshControl *)refreshControl;

@end

@interface ZLChatView : UIView

@property(nonatomic,weak)id<ZLChatViewDataSource> datasource;

@property(nonatomic,copy)SendMessageText sendMessageText;///<输入框发送消息
@property(nonatomic,copy)SendMessageAudio sendMessageAudio;///<语音消息录制完成
@property(nonatomic,copy)ZLChatHeaderClick chatHeaderClick;///<头像点击
@property(nonatomic,copy)ZLChatHeaderLongPress chatHeaderLongPress;///<头像长按
@property(nonatomic,copy)ZLBubbleViewLongPress chatBubbleViewLongPress;///<气泡长按
@property(nonatomic,copy)ZLDidClickLinkWithMoreQuestion didClickLinkWithMoreQuestion;///<更多问题回复
#pragma mark - 列表
/// 时间显示间隔(分钟数),为0 不显示,默认为5分钟
@property(nonatomic,assign)NSInteger showTime_minutes;

#pragma mark - 输入框
/// 是否显示更多按钮,默认为NO
@property(nonatomic,assign)BOOL isShowMoreButt;

/// 是否显示表情按钮,默认为NO
@property(nonatomic,assign)BOOL isShowFaceButt;
/**
 是否显示语音按钮
 */
@property(nonatomic,assign)BOOL isShowAudioButt;
/// 是否自定义inputBar,内部使用Masory布局,默认设置customView 完全覆盖当前的view,如需自定义高度,请重新设置约束
@property(nonatomic,strong)UIView *customView;

#pragma mark - 列表

/// 右边气泡的图片名字
@property(nonatomic,strong)UIImage *rightBubbleImage;

/// 右边气泡按下的图片名字
@property(nonatomic,strong)UIImage *rightBubbleHighImage;

/// 右边气泡的拉伸值,两个属性必须设置,缺一不可
@property(nonatomic)UIEdgeInsets rightBubbleCapInsets;

/// 右边文本内容的padding
@property(nonatomic)UIEdgeInsets rightTextContentCapInsets;

/// 左边气泡的图片名字
@property(nonatomic,strong)UIImage *leftBubbleImage;

/// 左边气泡按下的图片名字,
@property(nonatomic,strong)UIImage *leftBubbleHighImage;

/// 左边气泡的拉伸值,两个属性必须设置,缺一不可
@property(nonatomic)UIEdgeInsets leftBubbleCapInsets;
/// 左边文本内容的padding
@property(nonatomic)UIEdgeInsets leftTextContentCapInsets;
#pragma mark 头像
//TODO 不支持设置头像大小
/// 头像大小(默认40*40),
//@property(nonatomic)CGSize headerSize;

/// 头像默认图片(加载网络图片前的占位图)(传入图片名字,如果是bundle中的图片,请传入对应的路径)
@property(nonatomic,strong)UIImage *left_defaultHeaderImage;
@property(nonatomic,strong)UIImage *right_defaultHeaderImage;
/// 当前发送人的头像(如果需要使用本地图片,请使用defaultHeaderImageName)
@property(nonatomic,copy)NSString *sendOutHeaderImageUrl;

/// 头像圆角度,默认为默认大小40的一半20
@property(nonatomic,assign)CGFloat headerCornerRadius;

#pragma mark - 背景图片
/// 聊天背景图片
@property(nonatomic,strong)UIImage *chatBgImage;

#pragma mark - 数据更新
- (void)updateMessageList:(ZLMessage *)msg;

- (void)appendMessageList:(NSArray *)msgs;

- (void)removeChatData;

- (void)registerClass:(Class)cellClass forCellReuseIdentifier:(NSString *)identifier;

@end

