//
//  ZLActionSheet.h
//  YXJ
//
//  Created by 张锋 on 16/4/26.
//  Copyright © 2016年 成都寸芒网络科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ZLActionSheet;

typedef enum {
    ZLActionSheetStyleDefault, // 正常字体样式
    ZLActionSheetStyleCancel,  // 粗体字样式
    ZLActionSheetStyleDestructive, // 红色字体样式
    ZLActionSheetStyleInkBlue //字体为墨蓝色
} ZLActionSheetStyle;

@protocol ZLActionSheetDelegate <NSObject>
/**
 *  代理方法
 *
 *  @param actionSheet actionSheet
 *  @param index       被点击按钮是哪个
 */
@optional
- (void)clickAction:(ZLActionSheet *)actionSheet atIndex:(NSUInteger)index;
@end

@interface ZLActionSheet : UIView
/**
 *  设置代理
 */
//@property (nonatomic, copy) void(^didLongPressLinkBlock)(MLLink *link,NSString *linkText,MLLinkLabel *label);
@property (nonatomic, weak) id<ZLActionSheetDelegate> delegate;
@property(nonatomic,copy)void (^clickAction)(ZLActionSheet *actionSheet,NSUInteger index,id value);
@property(nonatomic,strong)id value;///<传参


-(void)setClickAction:(void (^)(ZLActionSheet *actionSheet, NSUInteger index,id value))clickAction;
/**
 *  初始化方法
 *
 *  @param title    提示内容
 *  @param confirms 选项标题数组
 *  @param cancel   取消按钮标题
 *  @param style    显示样式
 *
 *  @return         actionSheet
 */
+ (ZLActionSheet *)actionSheetWithDelegate:(id<ZLActionSheetDelegate>)delegate Title:(NSString *)title confirms:(NSArray *)confirms cancel:(NSString *)cancel style:(ZLActionSheetStyle)style;


+(void)showActionSheetWithDelegate:(id<ZLActionSheetDelegate>)delegate Title:(NSString *)title confirms:(NSArray *)confirms cancel:(NSString *)cancel style:(ZLActionSheetStyle)style value:(id)value clickAction:(void (^)(ZLActionSheet *actionSheet,NSUInteger index,id value))clickActionCompletion;


/// block 方式显示 ZLActionSheet
/// @param title 标题
/// @param confirms 选项
/// @param cancel 取消按钮标题
/// @param style 样式
/// @param value 带入的值
/// @param clickActionCompletion 点击回调
+(void)showActionSheetWithTitle:(NSString *)title confirms:(NSArray *)confirms cancel:(NSString *)cancel style:(ZLActionSheetStyle)style value:(id)value clickAction:(void (^)(ZLActionSheet *actionSheet,NSUInteger index,id value))clickActionCompletion;
/**
 *  返回按钮所在的标题
 *
 *  @return 标题
 */
- (NSString *)buttonTitleAtIndex :(NSInteger)index;
/**
 *  显示方法
 *
 */
- (void)show;
@end
