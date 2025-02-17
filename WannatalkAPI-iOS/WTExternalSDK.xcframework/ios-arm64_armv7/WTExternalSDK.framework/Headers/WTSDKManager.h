//
//  WTSDKManager.h
//  Wannatalk
//
//  Created by Srikanth Ganji on 09/03/17.
//  Copyright © 2017 Wannatalk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@protocol WTSDKManagerDelegate;
//@protocol WTChatLoaderDelegate;

@interface WTSDKManager : NSObject

@property (nonatomic, weak) id<WTSDKManagerDelegate> delegate;

+ (WTSDKManager *) sharedInstance;

+ (void) ClearTempDirectory;

// To show or hide guide button
+ (void) ShowGuideButton:(BOOL) show;               // default = YES

// To enable or disable sending audio message
+ (void) ShouldAllowSendAudioMessage:(BOOL) allow;  // default = YES

// To show or hide add participants option in new ticket page and chat item profile page
+ (void) ShouldAllowAddParticipant:(BOOL) allow;    // default = YES

// To show or hide remove participants option in chat item profile
+ (void) ShouldAllowRemoveParticipant:(BOOL) allow; // default = NO

// To show or hide welcome message
+ (void) ShowWelcomeMessage:(BOOL) show;            // default = NO

// To show or hide Profile Info page
+ (void) ShowProfileInfoPage:(BOOL) show;           // default = YES

// To create auto tickets:
//Chat ticket will create automatically when auto tickets is enabled, otherwise default ticket creation page will popup
+ (void) EnableAutoTickets:(BOOL) enable;           // default = NO

// To show or hide close chat button in chat page
+ (void) ShowExitButton:(BOOL) show;                // default = NO

// To show or hide participants in chat profile page
+ (void) ShowChatParticipants:(BOOL) show;          // default = YES

// To enable or disbale chat profile page
+ (void) EnableChatProfile:(BOOL) enable;           // default = YES

// To allow modify  in chat profile page
+ (void) AllowModifyChatProfile:(BOOL) allow;       // default = YES

// To set Inactive chat timeout:
//Chat session will end if user is inactive for timeout interval duration. If timeout interval is 0, chat session will not end automatically. The default timout interval is 1800 seconds (30 minutes).
+ (void) SetInactiveChatTimeoutInterval:(NSTimeInterval) timeoutInterval;   // default = 1800 seconds (30 minutes).


// To set timeinterval for checking the available agent // default 20 seconds
+ (void) SetAgentQueueTimeInterval:(NSTimeInterval) timeInterval;

+ (void) ShowDebugLogs:(BOOL) show;

//@property (nonatomic, weak) id<WTChatLoaderDelegate> chatLoaderDelegate;
//
//- (void) loadUserChatPageWithIdentifier:(NSString *) identifier message: (NSString *) message;

+ (void) ShowHomeButton:(BOOL) value;
+ (void) SetChatHeaderColor:(NSString *) value;
+ (void) SetChatTitleColor:(NSString *) value;
+ (void) SetChatBGColor:(NSString *) value;
+ (void) SetFontNames:(NSDictionary *) value;

@end
