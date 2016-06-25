/*

 GADMAdapterMdotM.h

 Copyright 2011 Google, Inc.

*/

#import "GADMAdNetworkAdapterProtocol.h"
#import "GADMAdNetworkConnectorProtocol.h"

@interface GADMAdapterMdotM : NSObject  <GADMAdNetworkAdapter>{
  id<GADMAdNetworkConnector> connector;
  UIView *adView;
}

@property (nonatomic, retain) UIView *adView;

@end
