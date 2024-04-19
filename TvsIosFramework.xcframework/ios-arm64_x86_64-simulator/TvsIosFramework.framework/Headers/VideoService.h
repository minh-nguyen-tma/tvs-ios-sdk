//
//  CallManager.h
//  residentapp
//
//  Created by Minh Nguyen on 5/17/21.
//

#import <Foundation/Foundation.h>

#import <PushKit/PKPushPayload.h>

NS_ASSUME_NONNULL_BEGIN


#define kOnIncomingCall @"onIncomingCall"
#define kOnCallAnswered @"onCallAnswered"
#define kOnEndCallActionPerformed @"onEndCallActionPerformed"
#define kOnCallMuted @"onCallMuted"
#define kOnUserOpenNotification @"onUserOpenNotification"


#define eOnCallCreated @"onCallCreated"
#define eOnCallStarted @"onCallStarted"
#define eOnCallFailed @"onCallFailed"
#define eOnCallEnded @"onCallEnded"
#define eOnCallNegotiationNeeded @"onCallNegotiationNeeded"
#define eOnRemoveCanidate @"onRemoteCandidateReceived"
#define eOnTextMessage @"onTextMessageReceived"

//
//#define kMessageTypeRegister @"REGISTER"
//#define kMessageTypeInvite @"video-invite"
//#define kMessageTypeAnswer @"video-answer"
//#define kMessageTypeEnd @"video-end"
//#define kMessageTypeCancel @"video-cancel"
//#define kMessageTypeReject @"video-reject"
//#define kMessageTypeOffer @"video-offer"
//#define kMessageTypeText @"text-message"

#define kCallPeerConnectionConfig @"peerConnectionConfig"
#define kCallOfferSdp @"sdp"
#define kCallRemoteCandidates @"candidates"	
#define kCallRemoteCandidate @"candidate"
#define kMessageStatusCode @"statusCode"
#define kCallMessage @"message"
#define kCallId @"callId"

#define webSocketUrl @"ws://video.t-building.vn:3001/ws" //@"ws://11.11.7.10:3001/ws"

#define LOCAL_ENDED 4000
#define LOCAL_REJECTED 4002
#define REMOTE_ENDED 4003
#define REMOTE_REJECTED 4004

@interface VideoService : NSObject

//@property (nonatomic, strong) NSString *accessToken;

+ (instancetype)getClassInstance;


- (void)handleIncomingPush:(PKPushPayload *)payload;
- (void)sendTextMessage:(NSString*)callId to:(NSString*)targetType message:(NSString*)message;
- (void)toggleAudioRoute:(BOOL)toSpeaker;
- (void)offerMediaForCall:(NSString*)callId;
- (void)requestUpdateMedia:(NSString*)offerSdp candidates:(NSString*)candidates;

- (void)createCall:(NSString*)callId to:(NSString*)target isGroup:(BOOL)isGroup;
- (void)startCall:(NSString*)offerSdp candidates:(NSString*)candidates agent:(NSString*)agent;
- (void)endCall:(NSString*)callId;
- (void)acceptCall:(NSString*)callId localSdp:(NSString*)sdp candidates:(NSString*)candidates;
- (void)acceptUpdateMediaRequest:(NSString*)callId localSdp:(NSString*)localSdp;

@end

NS_ASSUME_NONNULL_END
