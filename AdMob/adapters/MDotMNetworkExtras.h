//
//  NetworkExtras.h
//  MdotMAdapter
//
//  Created by MdotM on 8/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GADAdNetworkExtras.h"

@interface MdotMNetworkExtras : NSObject<GADAdNetworkExtras> {

	NSString *extraParameter;
	NSString *email;
	NSString *password;
	NSString *partnerkey;
	NSString *secretkey;
}
@property (nonatomic,copy) NSString *extraParameter;
@property (nonatomic,copy) NSString *email;
@property (nonatomic,copy) NSString *password;
@property (nonatomic,copy) NSString *partnerkey;
@property (nonatomic,copy) NSString *secretkey;

@end
