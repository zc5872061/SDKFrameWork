//
//  HTWrapper.m
//  MyTest
//
//  Created by Chukie on 14-10-9.
//
//

#import "HTWrapper.h"
#import "cocos2d.h"
#import "HTGameProxy.h"
#import "HTKeys.h"
#import "SDKAdapter.h"

using namespace cocos2d;

#pragma mark -----------------FOR EXTERNAL ALL--------------

void _showLoginView()
{
    [[HTWrapper shareHTWrapper] showLoginView];
}

void _initPlatForm()
{
    [[HTWrapper shareHTWrapper] initHTWrapper];
}

#pragma mark -------------FOR EXTERNAL INTERFACE-------
@interface HTWrapper ()<HTLoginProtocol, HTLogoutProtocol, HTPayProtocol>

- (void)onHTLoginCompleted:(HTUser *)user custom:(NSDictionary *)customDictionary;
- (void)onHTLoginFailed:(HTError *)error;
- (void)onHTLogoutCompleted:(HTUser *)user custom:(NSDictionary *)customDictionary;
- (void)onHTLogoutFailed:(HTError *)error;
- (void)onHTPayCompleted:(NSDictionary *)customDictionary;
- (void)onHTPayFailed:(HTError *)error;

@end

#pragma mark -------------FOR EXTERNAL IMPLEMENTATION-------
@implementation HTWrapper

static HTWrapper* _instance = NULL;

+(id) shareHTWrapper
{
    if(_instance == nil)
    {
        _instance = [HTWrapper alloc];
    }
    return _instance;
}

-(id) init
{
    if(self = [super init])
    {
        
    }
    return self;
}

-(void) initHTWrapper
{
    HTGameInfo* gameInfo = [[HTGameInfo alloc] init];
    gameInfo.direction = Portrait;
    gameInfo.shortName = @"tmsj";
    gameInfo.name = @"唐门世界";
    
    [HTGameProxy setLogEnable:YES];
    [HTGameProxy setDebugEnable:YES];
    [HTGameProxy setShowFunctionMenu:YES];
    [HTGameProxy initWithGameInfo:gameInfo];
}

-(void) showLoginView
{
    
    [HTGameProxy doLogin:nil delegate:self];
}

#pragma mark -------------FOR DELEGATE CALLBACK-------
- (void)onHTLoginCompleted:(HTUser *)user custom:(NSDictionary *)customDictionary
{
    CCLog("onHTLoginCompleted");
    CCNotificationCenter::sharedNotificationCenter()->postNotification(NOTIFICATION_LOGIN_OK);
}

- (void)onHTLoginFailed:(HTError *)error
{
    CCLog("onHTLoginFailed");
}

- (void)onHTLogoutCompleted:(HTUser *)user custom:(NSDictionary *)customDictionary
{
    CCLog("onHTLogoutCompleted");
}

- (void)onHTLogoutFailed:(HTError *)error
{
    CCLog("onHTLogoutFailed");
}

- (void)onHTPayCompleted:(NSDictionary *)customDictionary
{
    CCLog("onHTPayCompleted");
}

- (void)onHTPayFailed:(HTError *)error
{
    CCLog("onHTPayFailed");
}


@end
