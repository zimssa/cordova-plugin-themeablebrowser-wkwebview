/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <Cordova/CDVPlugin.h>
#import <Cordova/CDVInvokedUrlCommand.h>
#import <Cordova/CDVScreenOrientationDelegate.h>
#import <WebKit/WebKit.h>
#import <UIKit/UIKit.h>
#import "CDVWKWebViewUIDelegate.h"

//#ifdef __CORDOVA_4_0_0
//    #import <Cordova/CDVUIWebViewDelegate.h>
//#else
//    #import <CDVWKWebViewUIDelegate.h>
//    //#import <Cordova/CDVWebViewDelegate.h>
//#endif

// ************** add[start] 2019/05/20
// Fixed the message event to work.
@class CDVWKInAppBrowserViewController;
// ************** add[end]

@interface CDVThemeableBrowserOptions : NSObject {}

@property (nonatomic) BOOL location;
@property (nonatomic) NSString* closebuttoncaption;
@property (nonatomic) NSString* toolbarposition;
@property (nonatomic) BOOL clearcache;
@property (nonatomic) BOOL clearsessioncache;

@property (nonatomic) NSString* presentationstyle;
@property (nonatomic) NSString* transitionstyle;

@property (nonatomic) BOOL zoom;
// ************** add[start] 2019/05/20
// Fix enableviewportscale to work.
@property (nonatomic) BOOL enableviewportscale;
// ************** add[end]
@property (nonatomic) BOOL mediaplaybackrequiresuseraction;
@property (nonatomic) BOOL allowinlinemediaplayback;
@property (nonatomic) BOOL keyboarddisplayrequiresuseraction;
@property (nonatomic) BOOL suppressesincrementalrendering;
@property (nonatomic) BOOL hidden;
@property (nonatomic) BOOL disallowoverscroll;

@property (nonatomic) NSDictionary* statusbar;
@property (nonatomic) NSDictionary* toolbar;
@property (nonatomic) NSDictionary* title;
// ************** add[start] 2019/05/20
// Implementation of progress bar
@property (nonatomic) NSDictionary* browserProgress;
// ************** add[end]
@property (nonatomic) NSDictionary* backButton;
// ************** add[start] 2019/05/20
// add reload button
@property (nonatomic) NSDictionary* reloadButton;
// ************** add[end]
@property (nonatomic) NSDictionary* forwardButton;
@property (nonatomic) NSDictionary* closeButton;
@property (nonatomic) NSDictionary* menu;
@property (nonatomic) NSArray* customButtons;
@property (nonatomic) BOOL backButtonCanClose;
@property (nonatomic) BOOL disableAnimation;
@property (nonatomic) BOOL fullscreen;
// ************** add[start] 2019/05/20
// Enable flip back / forward.
@property (nonatomic) BOOL allowsBackForwardNavigationGestures;
// ************** add[end]

@end

@class CDVThemeableBrowserViewController;

@interface CDVThemeableBrowser : CDVPlugin <WKNavigationDelegate> {
// ************** del[start] 2019/05/20
// Fixed the message event to work.
//     BOOL _injectedIframeBridge;
// ************** del[end]
}


@property (nonatomic, retain) CDVThemeableBrowserViewController* themeableBrowserViewController;
@property (nonatomic, copy) NSString* callbackId;
@property (nonatomic, copy) NSRegularExpression *callbackIdPattern;

- (CDVThemeableBrowserOptions*)parseOptions:(NSString*)options;
- (void)open:(CDVInvokedUrlCommand*)command;
- (void)close:(CDVInvokedUrlCommand*)command;
- (void)injectScriptCode:(CDVInvokedUrlCommand*)command;
- (void)show:(CDVInvokedUrlCommand*)command;
- (void)show:(CDVInvokedUrlCommand*)command withAnimation:(BOOL)animated;
// ************** add[start] 2019/05/20
// Implement hide method
- (void)hide:(CDVInvokedUrlCommand*)command;
// ************** add[end]
- (void)reload:(CDVInvokedUrlCommand*)command;
// ************** add[start] 2019/05/20
// add changeButtonImage for custom buttons, and fixed event for custom button
- (void)changeButtonImage:(CDVInvokedUrlCommand*)command;
// ************** add[end]

@end

// ************** mod[start] 2019/05/20
// Enable flip back / forward.
// Fixed the message event to work.
// Supports links that open in new windows or tabs.
// @interface CDVThemeableBrowserViewController : UIViewController <WKNavigationDelegate,CDVScreenOrientationDelegate, UIActionSheetDelegate>{
@interface CDVThemeableBrowserViewController : UIViewController <WKNavigationDelegate,CDVScreenOrientationDelegate, UIActionSheetDelegate, UIGestureRecognizerDelegate, WKScriptMessageHandler, WKUIDelegate>{
// ************** mod[end]
    @private
    NSString* _userAgent;
    NSString* _prevUserAgent;
    NSInteger _userAgentLockToken;
    UIStatusBarStyle _statusBarStyle;
    CDVThemeableBrowserOptions *_browserOptions;

//#ifdef __CORDOVA_4_0_0
////    kCDVWebViewEngineWKUIDelegate* _webViewDelegate;
////    kCDVWebViewEngineWKNavigationDelegate * _webNavigationDelegate;
////    CDVUIWebViewDelegate* _webViewDelegate;
////#else
////    kCDVWebViewEngineWKUIDelegate* _webViewDelegate;
////    kCDVWebViewEngineWKNavigationDelegate * _webNavigationDelegate;
////    //CDVWebViewDelegate* _webViewDelegate;
//#endif
    
}

@property (nonatomic, strong) IBOutlet WKWebView* webView;
@property (nonatomic, strong) IBOutlet UIButton* closeButton;
@property (nonatomic, strong) IBOutlet UILabel* addressLabel;
@property (nonatomic, strong) IBOutlet UILabel* titleLabel;
@property (nonatomic, strong) IBOutlet UIButton* backButton;
// ************** add[start] 2019/05/20
// add reload button
@property (nonatomic, strong) IBOutlet UIButton* reloadButton;
// ************** add[end]
@property (nonatomic, strong) IBOutlet UIButton* forwardButton;
@property (nonatomic, strong) IBOutlet UIButton* menuButton;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView* spinner;
@property (nonatomic, strong) IBOutlet UIView* toolbar;
// ************** add[start] 2019/05/20
// Implementation of progress bar
@property (nonatomic, strong) IBOutlet UIProgressView* progressView;
// ************** add[end]

@property (nonatomic, strong) NSArray* leftButtons;
@property (nonatomic, strong) NSArray* rightButtons;

@property (nonatomic, weak) id <CDVScreenOrientationDelegate> orientationDelegate;
@property (nonatomic, weak) CDVThemeableBrowser* navigationDelegate;
@property (nonatomic) NSURL* currentURL;
@property (nonatomic) CGFloat titleOffset;
// ************** add[start] 2019/05/20
// Implementation of progress bar
@property (nonatomic , readonly , getter=loadProgress) CGFloat currentProgress;
// ************** add[end]
// ************** add[start] 2019/05/20
// add changeButtonImage for custom buttons, and fixed event for custom button
- (void)changeButtonImage:(int)buttonIndex buttonProps:(NSDictionary*)buttonProps;
// ************** add[end]

- (void)close;
- (void)reload;
- (void)navigateTo:(NSURL*)url;
- (void)showLocationBar:(BOOL)show;
- (void)showToolBar:(BOOL)show : (NSString*) toolbarPosition;
- (void)setCloseButtonTitle:(NSString*)title;

- (id)initWithUserAgent:(NSString*)userAgent prevUserAgent:(NSString*)prevUserAgent browserOptions: (CDVThemeableBrowserOptions*) browserOptions navigationDelete:(CDVThemeableBrowser*) navigationDelegate statusBarStyle:(UIStatusBarStyle) statusBarStyle;

+ (UIColor *)colorFromRGBA:(NSString *)rgba;

@end

@interface CDVThemeableBrowserNavigationController : UINavigationController

@property (nonatomic, weak) id <CDVScreenOrientationDelegate> orientationDelegate;

@end

