//
//  ZLIMBaseViewController.h
//  NavigationPresent
//
//  Created by huazhaopeng on 2019/8/3.
//  Copyright © 2017年 kamous. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZLIMBaseViewController : UIViewController

- (void)presentViewController:(UIViewController *)viewControllerToPresent
                     animated:(BOOL)animated
                   completion:(void (^)(void))completion
                    pushStyle:(BOOL)isPushStyle;

@end
