//
//  VSChannelListViewController.h
//  VideoStream
//
//  Created by Murat Sudan on 11/16/12.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VSPlayerViewControllerWithAd.h"

@interface VSChannelListViewController : UIViewController <VSPlayerViewControllerDelegate>

@property (retain, nonatomic) IBOutlet UITableView *tableView;
@end
