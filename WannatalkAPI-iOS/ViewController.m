//
//  ViewController.m
//  WannatalkAPI-iOS
//
//  Created by Srikanth Ganji on 11/03/18.
//  Copyright © 2018 Wannatalk. All rights reserved.
//

#import "ViewController.h"
#import <WTExternalSDK/WTExternalSDK.h>

@interface ViewController () <WTLoginManagerDelegate, WTSDKManagerDelegate>
@property (weak, nonatomic) IBOutlet UIButton *btnLogin;
@property (weak, nonatomic) IBOutlet UIButton *btnOrgProfile;
@property (weak, nonatomic) IBOutlet UIButton *btnSilentLogin;
@property (weak, nonatomic) IBOutlet UIButton *btnLogout;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [WTLoginManager sharedInstance].delegate = self;
    [self updateButtons];
}

- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark -
- (void) updateButtons {
    
    BOOL userLoggedIn = [WTLoginManager sharedInstance].isUserLoggedIn;
    self.btnLogin.hidden = userLoggedIn;
    self.btnSilentLogin.hidden = userLoggedIn;
    self.btnOrgProfile.hidden = !userLoggedIn;
    self.btnLogout.hidden = !userLoggedIn;
}
#pragma mark -

- (IBAction)silentLoginBtnClicked:(id)sender {
    [[WTLoginManager sharedInstance] silentLoginWithIdentifier:@"<your_phone_number>" fromVC:self];

}

- (IBAction)loginBtnClicked:(id)sender {
    
    [[WTLoginManager sharedInstance] loginFromVC:self];
    
}

- (IBAction)orgProfileClicked:(id)sender {
    [self.navigationController pushOrgProfileVCWithDelegate:self animated:YES];
}

- (void) loadChatList {
    [self.navigationController pushChatListVCWithDelegate:self animated:YES];
}

- (void) loadUsers {
    [self.navigationController pushUsersVCWithDelegate:self animated:YES];
}

- (IBAction)logoutClicked:(id)sender {
    [[WTLoginManager sharedInstance] logout];
}

#pragma mark - Delegate Methods
#pragma mark -
- (void) wtAccountDidLoginSuccessfully {
    [self updateButtons];
}

- (void) wtAccountDidLogOutSuccessfully {
    [self updateButtons];
}

#pragma mark -
- (void) wtsdkOrgProfileDidLoadFailWithError:(NSString *)error {
    
}

- (void) wtsdkOrgProfileDidLoadSuccesfully {
    
}

@end
