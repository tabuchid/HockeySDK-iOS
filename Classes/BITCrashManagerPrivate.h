/*
 * Author: Andreas Linde <mail@andreaslinde.de>
 *
 * Copyright (c) 2013-2014 HockeyApp, Bit Stadium GmbH.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#import "HockeySDK.h"

#if HOCKEYSDK_FEATURE_CRASH_REPORTER

#import <CrashReporter/CrashReporter.h>

@class BITHockeyAppClient;

@interface BITCrashManager () {
}

/**
 * must be set
 */
@property (nonatomic, strong) BITHockeyAppClient *hockeyAppClient;

@property (nonatomic) NSUncaughtExceptionHandler *exceptionHandler;

@property (nonatomic, strong) NSFileManager *fileManager;

@property (nonatomic, strong) BITPLCrashReporter *plCrashReporter;

@property (nonatomic) NSString *lastCrashFilename;

@property (nonatomic, copy, setter = setAlertViewHandler:) BITCustomAlertViewHandler alertViewHandler;

#if HOCKEYSDK_FEATURE_AUTHENTICATOR

// Only set via BITAuthenticator
@property (nonatomic, strong) NSString *installationIdentification;

// Only set via BITAuthenticator
@property (nonatomic) BITAuthenticatorIdentificationType installationIdentificationType;

// Only set via BITAuthenticator
@property (nonatomic) BOOL installationIdentified;

#endif /* HOCKEYSDK_FEATURE_AUTHENTICATOR */

- (void)cleanCrashReports;

- (NSString *)userIDForCrashReport;
- (NSString *)userEmailForCrashReport;
- (NSString *)userNameForCrashReport;

- (void)handleCrashReport;
- (BOOL)hasPendingCrashReport;
- (BOOL)hasNonApprovedCrashReports;

- (void)persistUserProvidedCrashDescription:(NSString *)userProvidedCrashDescription;
- (void)persistAttachment:(BITCrashAttachment *)attachment withFilename:(NSString *)filename;

- (BITCrashAttachment *)attachmentForCrashReport:(NSString *)filename;

- (void)invokeDelayedProcessing;
- (void)sendCrashReports;

- (NSString *)getCrashesDir;
- (void)setLastCrashFilename:(NSString *)lastCrashFilename;

@end


#endif /* HOCKEYSDK_FEATURE_CRASH_REPORTER */
