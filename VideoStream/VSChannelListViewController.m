//
//  VSChannelListViewController.m
//  VideoStream
//
//  Created by Murat Sudan on 11/16/12.
//  Copyright (c) 2013-2016 Murat Sudan. All rights reserved.
//

#import "VSChannelListViewController.h"
#include "ChannelsManager.h"

@interface VSChannelListViewController () {
    NSMutableArray *_channelList;
}
@end

@implementation VSChannelListViewController

@synthesize tableView = _tableView;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
        self.title = @"Channel List";
        _channelList = [[ChannelsManager sharedManager] streamList];
        
    }
    return self;
}

#pragma mark View life cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    if ([[[UIDevice currentDevice] systemVersion] compare:@"7.0" options:NSNumericSearch] != NSOrderedAscending) {
        //running on iOS 7.0 or higher
        self.edgesForExtendedLayout = UIRectEdgeNone;
        self.navigationItem.rightBarButtonItem.tintColor = [UIColor colorWithRed:0.0 green:122.0/255.0 blue:1.0 alpha:1.0];
    }
    self.navigationController.navigationBar.tintColor = [UIColor lightGrayColor];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeInfoLight];
    self.navigationItem.rightBarButtonItem = [[[UIBarButtonItem alloc] initWithImage:button.currentImage style:UIBarButtonItemStylePlain target:self action:@selector(onBarButtonInfoTapped:)] autorelease];
}

#pragma mark - Subview actions 

- (void)onBarButtonInfoTapped:(id) sender {
    NSString *version = [[[NSBundle mainBundle] infoDictionary] valueForKey:@"SDK-Build"];
    UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:TR(@"Build date") message:version delegate:nil cancelButtonTitle:TR(@"OK") otherButtonTitles:nil] autorelease];
    [alert show];
}

#pragma mark TableView delegate methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [_channelList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellId = @"CellIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellId];
    if (!cell) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:cellId] autorelease];

        UIView *topLine = [[[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, [UIScreen mainScreen].bounds.size.height, 1.0f)] autorelease];
		topLine.backgroundColor = [UIColor colorWithRed:1.1 green:1.1 blue:1.11 alpha:0.5];
        [cell.contentView addSubview:topLine];

        UIView *bottomLine = [[[UIView alloc] initWithFrame:CGRectMake(0.0f, 63.0f, [UIScreen mainScreen].bounds.size.height, 1.0f)] autorelease];
		bottomLine.backgroundColor =[UIColor colorWithRed:0.78 green:0.78 blue:0.79 alpha:0.5];
		[cell.contentView addSubview:bottomLine];

        cell.selectionStyle = UITableViewCellSelectionStyleGray;
        cell.textLabel.font = [UIFont fontWithName:@"HelveticaNeue" size:18];
        cell.detailTextLabel.font = [UIFont fontWithName:@"HelveticaNeue-Light" size:16];
    }

    Channel *channel = [_channelList objectAtIndex:indexPath.row];
    cell.textLabel.text = [channel name];
    cell.detailTextLabel.text = [channel description];

    return cell;
}

- (void)tableView:(UITableView*)tableView willDisplayCell:(UITableViewCell*)cell forRowAtIndexPath:(NSIndexPath*)indexPath {
    cell.backgroundColor = [UIColor colorWithRed:0.94 green:0.94 blue:0.95 alpha:1.0];
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    Channel *channel = [_channelList objectAtIndex:indexPath.row];
    NSString *urlString = [[channel urlAddress] retain];
    NSDictionary *options = [channel options];
    
    VSPlayerViewControllerWithAd *playerVc = [[[VSPlayerViewControllerWithAd alloc] initWithURLString:urlString decoderOptions:options] autorelease];
    playerVc.barTitle = [channel name];
    playerVc.statusBarHidden = YES;
    playerVc.delegate = self;
    
    playerVc.clientAdUnitIdBanner = @"enter-your-ad-unit-id-here";
    playerVc.clientAdUnitIdInterstitial = @"enter-your-ad-unit-id-here";
    playerVc.interstitialAdFrequencyPerPlay = 2;
    
    [self.navigationController presentViewController:playerVc animated:YES completion:NULL];
    [urlString release];
}

#pragma mark - VSPlayerViewController callback

- (void)onPlayerViewControllerStateChanged:(VSDecoderState)state errorCode:(VSError)errCode {
    if (state == kVSDecoderStateConnecting) {
    } else if (state == kVSDecoderStateConnected) {
    } else if (state == kVSDecoderStateInitialLoading) {
    } else if (state == kVSDecoderStateReadyToPlay) {
    } else if (state == kVSDecoderStateBuffering) {
    } else if (state == kVSDecoderStatePlaying) {
    } else if (state == kVSDecoderStatePaused) {
    } else if (state == kVSDecoderStateStoppedByUser) {
    } else if (state == kVSDecoderStateConnectionFailed) {
    } else if (state == kVSDecoderStateStoppedWithError) {
        if (errCode == kVSErrorStreamReadError) {
        }
    }
}

#pragma mark Memory events

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {

    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
    [_channelList release];
    [_tableView release];
    [super dealloc];
}
- (void)viewDidUnload {
    [self setTableView:nil];
    [super viewDidUnload];
}
@end
